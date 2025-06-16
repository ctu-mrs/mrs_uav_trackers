/* includes //{ */

#include <ros/ros.h>
#include <ros/package.h>

#include <mrs_uav_managers/tracker.h>

#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/geometry/cyclic.h>

#include <mrs_msgs/VelocityReferenceSrv.h>

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

namespace joy_tracker
{

/* //{ class JoyTracker */

class JoyTracker : public mrs_uav_managers::Tracker {
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

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  bool callbacks_enabled_ = true;

  std::string _uav_name_;

  bool is_initialized_ = false;
  bool is_active_      = false;

  ros::Time last_update;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ------------------ dynamics constraints ------------------ |

  double     _heading_rate_;
  std::mutex mutex_constraints_;

  // | ------------------ tracker's inner state ----------------- |

  double     state_z_;
  double     state_heading_;
  std::mutex mutex_state_;

  // | ------------------- joystick subscriber ------------------ |

  mrs_lib::SubscribeHandler<sensor_msgs::Joy> sh_joystick_;

  double _max_tilt_;
  double _vertical_speed_;

  // channel numbers and channel multipliers
  int    _channel_pitch_;
  int    _channel_roll_;
  int    _channel_heading_;
  int    _channel_throttle_;
  double _channel_mult_pitch_;
  double _channel_mult_roll_;
  double _channel_mult_heading_;
  double _channel_mult_throttle_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool JoyTracker::initialize(const ros::NodeHandle &nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                            std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  nh_ = nh;

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  // | ---------- loading params using the parent's nh ---------- |

  mrs_lib::ParamLoader param_loader_parent(common_handlers->parent_nh, "ControlManager");

  param_loader_parent.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader_parent.loadedSuccessfully()) {
    ROS_ERROR("[JoyTracker]: Could not load all parameters!");
    return false;
  }

  // | ---------------- load plugin's parameters ---------------- |

  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/private/joy_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/public/joy_tracker.yaml");

  /* const std::string yaml_prefix = "mrs_uav_trackers/joy_tracker/"; */
  const std::string yaml_prefix = "";

  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/vertical_speed", _vertical_speed_);

  private_handlers->param_loader->loadParam(yaml_prefix + "max_tilt", _max_tilt_);

  private_handlers->param_loader->loadParam(yaml_prefix + "heading_tracker/heading_rate", _heading_rate_);

  // load channels
  private_handlers->param_loader->loadParam(yaml_prefix + "channels/pitch", _channel_pitch_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channels/roll", _channel_roll_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channels/heading", _channel_heading_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channels/throttle", _channel_throttle_);

  // load channel multipliers
  private_handlers->param_loader->loadParam(yaml_prefix + "channel_multipliers/pitch", _channel_mult_pitch_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channel_multipliers/roll", _channel_mult_roll_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channel_multipliers/heading", _channel_mult_heading_);
  private_handlers->param_loader->loadParam(yaml_prefix + "channel_multipliers/throttle", _channel_mult_throttle_);

  if (!private_handlers->param_loader->loadedSuccessfully()) {
    ROS_ERROR("[JoyTracker]: could not load all parameters!");
    return false;
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_nh, "JoyTracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "JoyTracker";
  shopts.queue_size      = 1;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_joystick_ = mrs_lib::SubscribeHandler<sensor_msgs::Joy>(shopts, "joystick");

  // | --------------------- finish the init -------------------- |

  last_update = ros::Time(0);

  is_initialized_ = true;

  ROS_INFO("[JoyTracker]: initialized");

  return true;
}

//}

/* //{ activate() */

std::tuple<bool, std::string> JoyTracker::activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {

    ss << "odometry not set";
    return std::tuple(false, ss.str());
  }

  if (!sh_joystick_.hasMsg()) {

    ss << "missing joystick goal";
    return std::tuple(false, ss.str());
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading = 0;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[JoyTracker]: could not calculate UAV heading");
  }

  // initialized the heading and z from the last tracker command / odometry
  {
    std::scoped_lock lock(mutex_state_);

    if (last_tracker_cmd) {

      // the last command is usable
      state_z_       = last_tracker_cmd->position.z;
      state_heading_ = last_tracker_cmd->heading;

    } else {

      state_z_       = uav_state.pose.position.z;
      state_heading_ = uav_heading;

      ROS_WARN("[JoyTracker]: the previous command is not usable for activation, using Odometry instead");
    }
  }

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[JoyTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void JoyTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[JoyTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool JoyTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::TrackerCommand> JoyTracker::update(const mrs_msgs::UavState &                                          uav_state,
                                                           [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer            = mrs_lib::ScopeTimer("JoyTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;

    got_uav_state_ = true;
  }

  double dt = (ros::Time::now() - last_update).toSec();

  last_update = ros::Time::now();

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  if (!sh_joystick_.hasMsg()) {
    return {};
  }

  // | ------------------ get the joystick data ----------------- |

  sensor_msgs::JoyConstPtr joy_data = sh_joystick_.getMsg();

  double desired_vertical_speed = _channel_mult_throttle_ * joy_data->axes[_channel_throttle_] * _vertical_speed_;
  double desired_heading_rate   = _channel_mult_heading_ * joy_data->axes[_channel_heading_] * _heading_rate_;
  double desired_pitch          = _channel_mult_pitch_ * joy_data->axes[_channel_pitch_] * _max_tilt_;
  double desired_roll           = _channel_mult_roll_ * joy_data->axes[_channel_roll_] * _max_tilt_;

  // | ----------------------- z tracking ----------------------- |

  state_z_ += desired_vertical_speed * dt;

  // | -------------------- heading tracking -------------------- |

  state_heading_ += desired_heading_rate * dt;
  state_heading_ = radians::wrap(state_heading_);

  ROS_INFO_THROTTLE(1.0, "[JoyTracker]: desired vert_speed: %.2f, heading_speed: %.2f, pitch: %.2f, roll: %.2f", desired_vertical_speed, desired_heading_rate,
                    desired_pitch, desired_roll);

  mrs_msgs::TrackerCommand tracker_cmd;

  tracker_cmd.header.stamp    = ros::Time::now();
  tracker_cmd.header.frame_id = uav_state.header.frame_id;

  tracker_cmd.use_position_vertical = true;
  tracker_cmd.position.z            = state_z_;

  // filling these anyway to allow visualization of the reference
  tracker_cmd.position.x = uav_state.pose.position.x;
  tracker_cmd.position.y = uav_state.pose.position.y;

  tracker_cmd.use_velocity_vertical = true;
  tracker_cmd.velocity.z            = desired_vertical_speed;

  tracker_cmd.use_heading_rate = 1;
  tracker_cmd.heading_rate     = desired_heading_rate;

  /* tracker_cmd.orientation     = mrs_lib::AttitudeConverter(desired_roll, desired_pitch, 0).setHeadingByYaw(state_heading_); */
  tracker_cmd.orientation     = mrs_lib::AttitudeConverter(desired_roll, desired_pitch, state_heading_);
  tracker_cmd.use_orientation = true;

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus JoyTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr JoyTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[JoyTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[JoyTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState &new_uav_state) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr JoyTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::DynamicsConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr JoyTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr JoyTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr JoyTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

}  // namespace joy_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::joy_tracker::JoyTracker, mrs_uav_managers::Tracker)
