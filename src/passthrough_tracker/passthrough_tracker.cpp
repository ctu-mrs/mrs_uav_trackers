/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_msgs/PassthroughTrackerCommand.h>
#include <mrs_msgs/VelocityReferenceSrv.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>
#include <mrs_lib/publisher_handler.h>
#include <mrs_lib/service_client_handler.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <mrs_msgs/String.h>

//}

/* defines //{ */

#define STOP_THR 1e-3

//}

/* using //{ */

using vec2_t = mrs_lib::geometry::vec_t<2>;
using vec3_t = mrs_lib::geometry::vec_t<3>;

using radians  = mrs_lib::geometry::radians;
using sradians = mrs_lib::geometry::sradians;

//}

namespace mrs_uav_trackers
{

namespace passthrough_tracker
{

/* //{ class PassthroughTracker */

class PassthroughTracker : public mrs_uav_managers::Tracker {
public:
  bool initialize(const ros::NodeHandle &nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers);

  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::TrackerCommand>   update(const mrs_msgs::UavState &uav_state, const mrs_uav_managers::Controller::ControlOutput &last_control_output);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr   setVelocityReference(const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd);

  const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  ros::NodeHandle nh_;

  bool callbacks_enabled_ = true;

  std::string _uav_name_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  mrs_lib::PublisherHandler<visualization_msgs::MarkerArray> ph_rviz_marker_;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ------------------- tracker constraints ------------------ |

  mrs_msgs::DynamicsConstraints constraints_;
  std::mutex                    mutex_constraints_;

  // | ---------------- the tracker's inner state --------------- |

  std::atomic<bool> is_initialized_  = false;
  std::atomic<bool> is_active_       = false;
  std::atomic<bool> first_iteration_ = true;

  double _external_command_timeout_;

  mrs_lib::SubscribeHandler<mrs_msgs::PassthroughTrackerCommand> sh_command_;

  void callbackCommand(const mrs_msgs::PassthroughTrackerCommand::ConstPtr msg);

  // stores the post-processed and transformed command
  mrs_msgs::PassthroughTrackerCommand command_;
  std::mutex                    mutex_command_;
  ros::Time                     last_command_time_;
  std::atomic<bool>             getting_cmd_ = false;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;

  // | --------------------- service clients -------------------- |

  mrs_lib::ServiceClientHandler<mrs_msgs::String> sch_switch_tracker_;

  std::string _backup_tracker_;

  std::future<mrs_msgs::String> switch_tracker_future_;

  std::atomic<bool> switch_tracker_called_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool PassthroughTracker::initialize(const ros::NodeHandle &nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                              std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  nh_ = nh;

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  // | ---------------- load parent's parameters ---------------- |

  mrs_lib::ParamLoader param_loader_parent(common_handlers->parent_nh, "ControlManager");

  param_loader_parent.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader_parent.loadedSuccessfully()) {
    ROS_ERROR("[PassthroughTracker]: Could not load all parameters!");
    return false;
  }

  // | ---------------- load plugin's parameters ---------------- |

  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/private/passthrough_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/public/passthrough_tracker.yaml");

  const std::string yaml_prefix = "mrs_uav_trackers/passthrough_tracker/";

  private_handlers->param_loader->loadParam(yaml_prefix + "command_timeout", _external_command_timeout_);

  private_handlers->param_loader->loadParam(yaml_prefix + "backup_tracker", _backup_tracker_);

  if (!private_handlers->param_loader->loadedSuccessfully()) {
    ROS_ERROR("[PassthroughTracker]: could not load all parameters!");
    return false;
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_nh, "PassthroughTracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "PassthroughTracker";
  shopts.threadsafe      = true;
  shopts.autostart       = true;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_command_ = mrs_lib::SubscribeHandler<mrs_msgs::PassthroughTrackerCommand>(shopts, "command", &PassthroughTracker::callbackCommand, this);

  // | ----------------------- publishers ----------------------- |

  ph_rviz_marker_ = mrs_lib::PublisherHandler<visualization_msgs::MarkerArray>(nh_, "rviz_marker", 1);

  // | --------------------- service clients -------------------- |

  sch_switch_tracker_ = mrs_lib::ServiceClientHandler<mrs_msgs::String>(common_handlers->parent_nh, "switch_tracker");

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[PassthroughTracker]: initialized");

  return true;
}

//}

/* //{ activate() */

std::tuple<bool, std::string> PassthroughTracker::activate([[maybe_unused]] const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {
    ss << "odometry not set";
    ROS_ERROR_STREAM("[PassthroughTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  if (!getting_cmd_) {

    std::scoped_lock lock(mutex_command_);

    command_.header.stamp    = ros::Time(0);
    command_.header.frame_id = last_tracker_cmd->header.frame_id;

    // stay at the current position
    command_.use_position = true;
    command_.position     = last_tracker_cmd->position;

    if (last_tracker_cmd->use_heading) {
      command_.heading     = last_tracker_cmd->heading;
      command_.use_heading = true;
    } else {
      command_.use_heading = false;
    }
  }

  is_active_       = true;
  first_iteration_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[PassthroughTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void PassthroughTracker::deactivate(void) {

  is_active_   = false;
  getting_cmd_ = false;

  ROS_INFO("[PassthroughTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool PassthroughTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::TrackerCommand> PassthroughTracker::update(const mrs_msgs::UavState &                                          uav_state,
                                                             [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("PassthroughTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;

    got_uav_state_ = true;
  }

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state_.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[PassthroughTracker]: could not calculate UAV heading");

    return {};
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  const auto now = ros::Time::now();
  const ros::Time external_command_time = sh_command_.lastMsgTime();

  // timeout the external command
  if (getting_cmd_ && (now - external_command_time).toSec() > _external_command_timeout_) {

    ROS_WARN("[PassthroughTracker]: command timeouted");
    getting_cmd_ = false;

    mrs_msgs::String srv;
    srv.request.value = _backup_tracker_;

    switch_tracker_future_ = sch_switch_tracker_.callAsync(srv);

    switch_tracker_called_ = true;
  }

  if (switch_tracker_called_ && switch_tracker_future_.wait_for(std::chrono::milliseconds(1)) == std::future_status::ready) {

    switch_tracker_called_ = false;

    if (!switch_tracker_future_.get().response.success) {
      ROS_ERROR("[PassthroughTracker]: failed to switch to backup tracker");
      return {};
    }

    switch_tracker_future_ = std::future<mrs_msgs::String>();
  }

  const auto command = mrs_lib::get_mutexed(mutex_command_, command_);

  mrs_msgs::TrackerCommand tracker_cmd;

  tracker_cmd.header.stamp    = ros::Time::now();
  tracker_cmd.header.frame_id = uav_state.header.frame_id;

  tracker_cmd.position.x = uav_state.pose.position.x;
  tracker_cmd.position.y = uav_state.pose.position.y;

  if (command.use_position) {
    tracker_cmd.position                = command.position;
    tracker_cmd.use_position_horizontal = true;
    tracker_cmd.use_position_vertical   = true;
  } else {
    tracker_cmd.position                = uav_state.position;
    tracker_cmd.use_velocity_horizontal = false;
    tracker_cmd.use_velocity_vertical   = false;
  }

  if (command.use_velocity) {
    tracker_cmd.velocity.x              = command.velocity.x;
    tracker_cmd.velocity.y              = command.velocity.y;
    tracker_cmd.velocity.z              = command.velocity.z;
    tracker_cmd.use_velocity_horizontal = true;
    tracker_cmd.use_velocity_vertical   = true;
  } else {
    tracker_cmd.velocity.x              = uav_state.velocity.linear.x;
    tracker_cmd.velocity.y              = uav_state.velocity.linear.y;
    tracker_cmd.velocity.z              = uav_state.velocity.linear.z;
    tracker_cmd.use_velocity_horizontal = false;
    tracker_cmd.use_velocity_vertical   = false;
  }

  if (command.use_z) {
    tracker_cmd.position.z            = command.z;
    tracker_cmd.use_position_vertical = true;
  } else {
    tracker_cmd.position.z            = uav_state.pose.position.z;
    tracker_cmd.use_position_vertical = false;
  }

  if (command.use_acceleration) {
    tracker_cmd.acceleration.x   = command.acceleration.x;
    tracker_cmd.acceleration.y   = command.acceleration.y;
    tracker_cmd.acceleration.z   = command.acceleration.z;
    tracker_cmd.use_acceleration = true;
  } else if (command.use_force) {
    tracker_cmd.acceleration.x   = command.force.x / last_control_output.diagnostics.total_mass;
    tracker_cmd.acceleration.y   = command.force.y / last_control_output.diagnostics.total_mass;
    tracker_cmd.acceleration.z   = command.force.z / last_control_output.diagnostics.total_mass;
    tracker_cmd.use_acceleration = true;
  } else {
    tracker_cmd.acceleration.x   = 0;
    tracker_cmd.acceleration.y   = 0;
    tracker_cmd.acceleration.z   = 0;
    tracker_cmd.use_acceleration = false;
  }

  if (command.use_heading) {
    tracker_cmd.heading     = command.heading;
    tracker_cmd.use_heading = true;
  } else {
    tracker_cmd.heading     = uav_heading;
    tracker_cmd.use_heading = false;
  }

  if (command.use_heading_rate) {
    tracker_cmd.heading_rate     = command.heading_rate;
    tracker_cmd.use_heading_rate = true;
  } else {
    tracker_cmd.heading_rate     = uav_state.velocity.angular.z;
    tracker_cmd.use_heading_rate = false;
  }

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus PassthroughTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  if (!tracker_status.active || first_iteration_)
    tracker_status.state = mrs_msgs::TrackerStatus::STATE_IDLE;
  else
    tracker_status.state = mrs_msgs::TrackerStatus::STATE_REFERENCE;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr PassthroughTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[PassthroughTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[PassthroughTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState &new_uav_state) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  ROS_WARN("[PassthroughTracker]: initiating hover");

  getting_cmd_ = false;

  mrs_msgs::String srv;
  srv.request.value = _backup_tracker_;

  switch_tracker_future_ = sch_switch_tracker_.callAsync(srv);

  switch_tracker_called_ = true;

  std::stringstream ss;
  ss << "initiating hover";

  std_srvs::TriggerResponse res;
  res.success = true;
  res.message = ss.str();

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr PassthroughTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr PassthroughTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  {
    std::scoped_lock lock(mutex_constraints_);

    constraints_ = cmd->constraints;
  }

  mrs_msgs::DynamicsConstraintsSrvResponse res;

  res.success = true;
  res.message = "constraints updated";

  return boost::make_shared<const mrs_msgs::DynamicsConstraintsSrvResponse>(res);
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr PassthroughTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr PassthroughTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr PassthroughTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | ----------- helper functions for constraining  ----------- |

/*  //{ */

template <int Dims>
bool constrainnNorm(mrs_lib::geometry::vec_t<Dims>& vec, const double max_norm)
{
  const double cur_norm = vec.norm();
  if (cur_norm > max_norm)
  {
    vec = vec / cur_norm * max_norm;
    return true;
  }
  else
  {
    return false;
  }
}

template <typename MsgT>
bool constrainnNorm(MsgT& vec, const double max_norm)
{
  vec3_t constrained(vec.x, vec.y, vec.z);
  const bool changed = constrainnNorm(constrained, max_norm);
  vec.x = constrained.x();
  vec.y = constrained.y();
  vec.z = constrained.z();
  return changed;
}

template <typename MsgT>
bool constrainHorizontalNorm(MsgT& vec, const double max_norm)
{
  vec2_t constrained(vec.x, vec.y);
  const bool changed = constrainnNorm(constrained, max_norm);
  vec.x = constrained.x();
  vec.y = constrained.y();
  return changed;
}

bool constrain(double& value, const double& minimum, const double& maximum)
{
  const auto orig = value;
  value = std::clamp(value, minimum, maximum);
  return value != orig;
}

template <typename MsgT>
bool constrainVertical(MsgT& vec, const double minimum, const double maximum)
{
  return constrain(vec.z, minimum, maximum);
}

bool constrainAngle(mrs_lib::geometry::sradians& angle, const mrs_lib::geometry::sradians& minimum, const mrs_lib::geometry::sradians& maximum)
{
  if (angle < minimum)
  {
    angle = minimum;
    return true;
  }
  if (angle > maximum)
  {
    angle = maximum;
    return true;
  }
  return false;
}

bool constrainAngleDerivative(mrs_lib::geometry::sradians& angle, const double dt, const mrs_lib::geometry::sradians& prev_angle, const double& minimum, const double& maximum)
{
  const double der = sradians::diff(angle, prev_angle) / dt;
  if (der < minimum)
  {
    angle = minimum;
    return true;
  }
  if (der > maximum)
  {
    angle = maximum;
    return true;
  }
  return false;
}

template <typename MsgT>
bool constrainHorizontalDerivative(MsgT& vec, const double dt, const MsgT& prev_vec, const double max_norm)
{
  vec2_t constrained = (vec2_t(vec.x, vec.y) - vec2_t(prev_vec.x, prev_vec.y)) / dt;
  const bool changed = constrainnNorm(constrained, max_norm);
  vec.x = prev_vec.x + dt*constrained.x();
  vec.y = prev_vec.y + dt*constrained.y();
  return changed;
}

template <typename MsgT>
bool constrainVerticalDerivative(MsgT& vec, const double dt, const MsgT& prev_vec, const double minimum, const double maximum)
{
  const double der = (vec.z - prev_vec.z) / dt;
  if (der > maximum)
  {
    vec.z = prev_vec.z + dt*maximum;
    return true;
  }
  if (der < minimum)
  {
    vec.z = prev_vec.z + dt*minimum;
    return true;
  }
  return true;
}

//}

// | --------------------- custom methods --------------------- |

/* callbackCommand() //{ */

void PassthroughTracker::callbackCommand(const mrs_msgs::PassthroughTrackerCommand::ConstPtr external_command) {

  if (!is_initialized_)
    return;

  if (!is_active_)
    return;

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("callbackCommand");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("PassthroughTracker::callbackCommand", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  if (first_iteration_) {

    last_command_time_ = ros::Time::now();
    first_iteration_   = false;

    {
      std::scoped_lock lock(mutex_command_);

      command_ = *external_command;
    }

    return;

  }

  const auto now = ros::Time::now();
  const double dt    = (now - last_command_time_).toSec();
  last_command_time_ = now;

  if (dt <= 1e-4) {
    ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: the command dt is %.5f, returning", dt);
    return;
    }

  getting_cmd_ = true;

  mrs_msgs::PassthroughTrackerCommand transformed_command = *external_command;

  const auto old_command = mrs_lib::get_mutexed(mutex_command_, command_);
  const auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);
  const auto uav_state   = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state_.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[PassthroughTracker]: could not calculate UAV heading");
    return;
  }

  // transform the command

  /* transform and constrain position //{ */
  
  if (transformed_command.use_position) {
  
    geometry_msgs::PointStamped point3;
    point3.header = transformed_command.header;
  
    point3.point.x = transformed_command.position.x;
    point3.point.y = transformed_command.position.y;
    point3.point.z = transformed_command.position.z;
  
    const auto ret = common_handlers_->transformer->transformSingle(point3, "");
  
    if (ret) {
      transformed_command.position.x = ret.value().point.x;
      transformed_command.position.y = ret.value().point.y;
      transformed_command.position.z = ret.value().point.z;
    } else {
      return;
    }
  
    // horizontal position change rate limit
    if (constrainHorizontalDerivative(transformed_command.position, dt, old_command.position, constraints.horizontal_speed))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting horizontal position change rate");
  
    // vertical position change rate
    if (constrainVerticalDerivative(transformed_command.position, dt, old_command.position, -constraints.vertical_descending_speed, constraints.vertical_ascending_speed))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting vertical position change rate");
  }
  
  //}

  // transform and constrain velocity
  
  if (transformed_command.use_velocity) {
  
    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;
  
    vector3.vector.x = transformed_command.velocity.x;
    vector3.vector.y = transformed_command.velocity.y;
    vector3.vector.z = transformed_command.velocity.z;
  
    const auto ret = common_handlers_->transformer->transformSingle(vector3, "");
  
    if (ret) {
      transformed_command.velocity.x = ret.value().vector.x;
      transformed_command.velocity.y = ret.value().vector.y;
      transformed_command.velocity.z = ret.value().vector.z;
    } else {
      return;
    }
  
    // horizontal speed limit
    if (constrainHorizontalNorm(transformed_command.velocity, constraints.horizontal_speed))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting horizontal speed");
  
    // vertical speed limit
    if (constrainVertical(transformed_command.velocity, -constraints.vertical_descending_speed, constraints.vertical_ascending_speed))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting vertical speed");
  
    // horizontal speed change rate limit
    if (constrainHorizontalDerivative(transformed_command.velocity, dt, old_command.velocity, constraints.horizontal_acceleration))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting horizontal speed change rate");
  
    // vertical speed change rate limit
    if (constrainVerticalDerivative(transformed_command.velocity, dt, old_command.velocity, -constraints.vertical_descending_acceleration, constraints.vertical_ascending_acceleration))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting vertical speed change rate");
  }
  
  //}

  /* transform and constrain heading //{ */

  if (transformed_command.use_heading) {

    mrs_msgs::ReferenceStamped temp_ref;
    temp_ref.header = transformed_command.header;

    temp_ref.reference.heading = transformed_command.heading;

    const auto ret = common_handlers_->transformer->transformSingle(temp_ref, "");

    if (ret) {

      mrs_lib::geometry::sradians hdg(ret.value().reference.heading);

      // yaw change limit
      if (constrainAngleDerivative(hdg, dt, old_command.heading, -constraints.heading_speed, constraints.heading_speed))
        ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting heading change");

      transformed_command.heading = hdg.value();

    } else {
      return;
    }
  } else {
    transformed_command.use_heading = false;
    transformed_command.heading     = uav_heading;
  }

  //}

  /* constrain heading rate //{ */
  
  if (transformed_command.use_heading_rate) {

    if (constrain(transformed_command.heading_rate, -constraints.heading_speed, constraints.heading_speed))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting heading rate");
  
  }
  
  //}

  /* transform acceleration //{ */
  
  if (transformed_command.use_acceleration) {
  
    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;
  
    vector3.vector.x = transformed_command.acceleration.x;
    vector3.vector.y = transformed_command.acceleration.y;
    vector3.vector.z = transformed_command.acceleration.z;
  
    const auto ret = common_handlers_->transformer->transformSingle(vector3, "");
  
    if (ret) {
      transformed_command.acceleration.x = ret.value().vector.x;
      transformed_command.acceleration.y = ret.value().vector.y;
      transformed_command.acceleration.z = ret.value().vector.z;
    } else {
      return;
    }
  
    // horizontal acceleration limit
    if (constrainHorizontalNorm(transformed_command.acceleration, constraints.horizontal_acceleration))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting horizontal acceleration");
  
    // vertical acceleration limit
    if (constrainVertical(transformed_command.acceleration, -constraints.vertical_descending_acceleration, constraints.vertical_ascending_acceleration))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting vertical acceleration");
  
    // horizontal acceleration change rate limit
    if (constrainHorizontalDerivative(transformed_command.acceleration, dt, old_command.acceleration, constraints.horizontal_jerk))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting horizontal acceleration change rate");
  
    // vertical acceleration change rate limit
    if (constrainVerticalDerivative(transformed_command.acceleration, dt, old_command.acceleration, -constraints.vertical_descending_jerk, constraints.vertical_ascending_jerk))
      ROS_WARN_THROTTLE(1.0, "[PassthroughTracker]: limitting vertical acceleration change rate");
  
  }

  //}

  // transform force

  if (transformed_command.use_force) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;

    vector3.vector.x = transformed_command.force.x;
    vector3.vector.y = transformed_command.force.y;
    vector3.vector.z = transformed_command.force.z;

    auto ret = common_handlers_->transformer->transformSingle(vector3, "");

    if (ret) {
      transformed_command.force.x = vector3.vector.x;
      transformed_command.force.y = vector3.vector.y;
      transformed_command.force.z = vector3.vector.z;
    } else {
      return;
    }
  }

  // if not active, nullify the desired speeds and accelerations
  // this will produce a rumpum (using the constraints) after the activation
  if (!is_active_) {

    auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

    transformed_command.position = uav_state_.pose.position;
    transformed_command.use_position = true;

    try {
      transformed_command.heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
      transformed_command.use_heading = true;
    }
    catch (...) {
      return;
    }
  }

  {
    std::scoped_lock lock(mutex_command_);

    command_ = transformed_command;
  }

  if (!is_active_) {
    ROS_INFO_ONCE("[PassthroughTracker]: getting command");
  } else {
    ROS_INFO_THROTTLE(5.0, "[PassthroughTracker]: getting command");
  }

  // --------------------------------------------------------------
  // |                     publish rviz markers                   |
  // --------------------------------------------------------------

  visualization_msgs::MarkerArray msg_out;

  double id = 0;

  geometry_msgs::Point point;

  /* desired position //{ */

  if (transformed_command.use_position) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "passthrough_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::LINE_LIST;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = transformed_command.position.x;
    point.y = transformed_command.position.y;
    point.z = transformed_command.position.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 1.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  /* desired speed //{ */

  if (transformed_command.use_velocity) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "passthrough_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.velocity.x;
    point.y = uav_state_.pose.position.y + transformed_command.velocity.y;
    point.z = uav_state_.pose.position.z + transformed_command.velocity.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  /* desired acceleration //{ */
  if (transformed_command.use_acceleration) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "passthrough_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.acceleration.x;
    point.y = uav_state_.pose.position.y + transformed_command.acceleration.y;
    point.z = uav_state_.pose.position.z + transformed_command.acceleration.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  /* desired force //{ */
  if (transformed_command.use_force) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "passthrough_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.force.x;
    point.y = uav_state_.pose.position.y + transformed_command.force.y;
    point.z = uav_state_.pose.position.z + transformed_command.force.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 0.0;
    marker.color.g = 0.0;
    marker.color.b = 1.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  ph_rviz_marker_.publish(msg_out);
}

//}

}  // namespace passthrough_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::passthrough_tracker::PassthroughTracker, mrs_uav_managers::Tracker)
