#define VERSION "1.0.4.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/utils.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>

#include <mrs_msgs/VelocityReferenceSrv.h>

//}

/* defines //{ */

#define STOP_THR 1e-3

//}

/* using //{ */

using namespace Eigen;

using vec2_t = mrs_lib::geometry::vec_t<2>;
using vec3_t = mrs_lib::geometry::vec_t<3>;

using radians  = mrs_lib::geometry::radians;
using sradians = mrs_lib::geometry::sradians;

//}

namespace mrs_uav_trackers
{

namespace line_tracker
{

/* //{ class LineTracker */

// state machine
typedef enum
{

  IDLE_STATE,
  STOP_MOTION_STATE,
  ACCELERATING_STATE,
  DECELERATING_STATE,
  STOPPING_STATE,

} States_t;

const char *state_names[5] = {

    "IDLING", "STOPPING_MOTION", "ACCELERATING", "DECELERATING", "STOPPING"};

class LineTracker : public mrs_uav_managers::Tracker {
public:
  ~LineTracker(){};

  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers);
  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::TrackerCommand>   update(const mrs_msgs::UavState &uav_state, const mrs_uav_managers::Controller::ControlOutput &last_control_output);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

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

  std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_;

  bool callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

  void       mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer_;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  double uav_x_;
  double uav_y_;
  double uav_z_;

  // tracker's inner states
  double _tracker_loop_rate_;
  double _tracker_dt_;
  bool   is_initialized_ = false;
  bool   is_active_      = false;

  // | ----------------- internal state mmachine ---------------- |

  States_t current_state_vertical_    = IDLE_STATE;
  States_t previous_state_vertical_   = IDLE_STATE;
  States_t current_state_horizontal_  = IDLE_STATE;
  States_t previous_state_horizontal_ = IDLE_STATE;

  void changeStateHorizontal(States_t new_state);
  void changeStateVertical(States_t new_state);
  void changeState(States_t new_state);

  void stopHorizontalMotion(void);
  void stopVerticalMotion(void);
  void accelerateHorizontal(void);
  void accelerateVertical(void);
  void decelerateHorizontal(void);
  void decelerateVertical(void);
  void stopHorizontal(void);
  void stopVertical(void);

  // | ------------------ dynamics constraints ------------------ |

  double     _horizontal_speed_;
  double     _vertical_speed_;
  double     _horizontal_acceleration_;
  double     _vertical_acceleration_;
  double     _heading_rate_;
  double     _heading_gain_;
  std::mutex mutex_constraints_;

  // | ---------------------- desired goal ---------------------- |

  double     goal_x_;
  double     goal_y_;
  double     goal_z_;
  double     goal_heading_;
  bool       have_goal_ = false;
  std::mutex mutex_goal_;

  // | ------------------- the state variables ------------------ |
  double state_x_;
  double state_y_;
  double state_z_;
  double state_heading_;

  double speed_x_;
  double speed_y_;
  double speed_heading_;

  double current_heading_;
  double current_vertical_direction_;

  double current_vertical_speed_;
  double current_horizontal_speed_;

  double current_horizontal_acceleration_;
  double current_vertical_acceleration_;

  std::mutex mutex_state_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void LineTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                             [[maybe_unused]] std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  nh_ = ros::NodeHandle(parent_nh, "line_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------


  mrs_lib::ParamLoader param_loader(nh_, "LineTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[LineTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("enable_profiler", _profiler_enabled_);

  param_loader.loadParam("horizontal_tracker/horizontal_speed", _horizontal_speed_);
  param_loader.loadParam("horizontal_tracker/horizontal_acceleration", _horizontal_acceleration_);

  param_loader.loadParam("vertical_tracker/vertical_speed", _vertical_speed_);
  param_loader.loadParam("vertical_tracker/vertical_acceleration", _vertical_acceleration_);

  param_loader.loadParam("heading_tracker/heading_rate", _heading_rate_);
  param_loader.loadParam("heading_tracker/heading_gain", _heading_gain_);

  param_loader.loadParam("tracker_loop_rate", _tracker_loop_rate_);

  _tracker_dt_ = 1.0 / double(_tracker_loop_rate_);

  ROS_INFO("[LineTracker]: tracker_dt: %.2f", _tracker_dt_);

  state_x_       = 0;
  state_y_       = 0;
  state_z_       = 0;
  state_heading_ = 0;

  speed_x_       = 0;
  speed_y_       = 0;
  speed_heading_ = 0;

  current_horizontal_speed_ = 0;
  current_vertical_speed_   = 0;

  current_horizontal_acceleration_ = 0;
  current_vertical_acceleration_   = 0;

  current_vertical_direction_ = 0;

  current_state_vertical_  = IDLE_STATE;
  previous_state_vertical_ = IDLE_STATE;

  current_state_horizontal_  = IDLE_STATE;
  previous_state_horizontal_ = IDLE_STATE;

  // --------------------------------------------------------------
  // |                          profiler_                          |
  // --------------------------------------------------------------

  profiler_ = mrs_lib::Profiler(nh_, "LineTracker", _profiler_enabled_);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer_ = nh_.createTimer(ros::Rate(_tracker_loop_rate_), &LineTracker::mainTimer, this);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[LineTracker]: could not load all parameters!");
    ros::shutdown();
  }

  is_initialized_ = true;

  ROS_INFO("[LineTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> LineTracker::activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {

    ss << "odometry not set";
    ROS_ERROR_STREAM("[LineTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ss << "could not calculate the UAV heading";
    return std::tuple(false, ss.str());
  }

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_);

    if (last_tracker_cmd) {

      // the last command is usable
      if (last_tracker_cmd->use_position_horizontal) {
        state_x_ = last_tracker_cmd->position.x;
        state_y_ = last_tracker_cmd->position.y;
      } else {
        state_x_ = uav_state.pose.position.x;
        state_y_ = uav_state.pose.position.y;
      }

      if (last_tracker_cmd->use_position_vertical) {
        state_z_ = last_tracker_cmd->position.z;
      } else {
        state_z_ = uav_state.pose.position.z;
      }

      if (last_tracker_cmd->use_heading) {
        state_heading_ = last_tracker_cmd->heading;
      } else if (last_tracker_cmd->use_orientation) {
        try {
          state_heading_ = mrs_lib::AttitudeConverter(last_tracker_cmd->orientation).getHeading();
        }
        catch (...) {
          state_heading_ = uav_heading;
        }
      } else {
        state_heading_ = uav_heading;
      }

      if (last_tracker_cmd->use_velocity_horizontal) {
        speed_x_ = last_tracker_cmd->velocity.x;
        speed_y_ = last_tracker_cmd->velocity.y;
      } else {
        speed_x_ = uav_state.velocity.linear.x;
        speed_y_ = uav_state.velocity.linear.y;
      }

      current_heading_          = atan2(speed_y_, speed_x_);
      current_horizontal_speed_ = sqrt(pow(speed_x_, 2) + pow(speed_y_, 2));

      current_vertical_speed_     = fabs(last_tracker_cmd->velocity.z);
      current_vertical_direction_ = last_tracker_cmd->velocity.z > 0 ? +1 : -1;

      current_horizontal_acceleration_ = 0;
      current_vertical_acceleration_   = 0;

      goal_heading_ = last_tracker_cmd->heading;

      ROS_INFO("[LineTracker]: initial condition: x=%.2f, y=%.2f, z=%.2f, heading=%.2f", last_tracker_cmd->position.x, last_tracker_cmd->position.y,
               last_tracker_cmd->position.z, last_tracker_cmd->heading);
      ROS_INFO("[LineTracker]: initial condition: x_rate=%.2f, y_rate=%.2f, z_rate=%.2f", speed_x_, speed_y_, current_vertical_speed_);

    } else {

      state_x_       = uav_state.pose.position.x;
      state_y_       = uav_state.pose.position.y;
      state_z_       = uav_state.pose.position.z;
      state_heading_ = uav_heading;

      speed_x_                  = uav_state.velocity.linear.x;
      speed_y_                  = uav_state.velocity.linear.y;
      current_heading_          = atan2(speed_y_, speed_x_);
      current_horizontal_speed_ = sqrt(pow(speed_x_, 2) + pow(speed_y_, 2));

      current_vertical_speed_     = fabs(uav_state.velocity.linear.z);
      current_vertical_direction_ = uav_state.velocity.linear.z > 0 ? +1 : -1;

      current_horizontal_acceleration_ = 0;
      current_vertical_acceleration_   = 0;

      goal_heading_ = uav_heading;

      ROS_WARN("[LineTracker]: the previous command is not usable for activation, using Odometry instead");
    }
  }

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  {
    std::scoped_lock lock(mutex_state_);

    horizontal_t_stop    = current_horizontal_speed_ / _horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed_) / 2.0;
    stop_dist_x          = cos(current_heading_) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading_) * horizontal_stop_dist;
  }

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state_);

    vertical_t_stop    = current_vertical_speed_ / _vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction_ * (vertical_t_stop * current_vertical_speed_) / 2.0;
  }

  // --------------------------------------------------------------
  // |              heading initial condition  prediction             |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_);

    goal_x_ = state_x_ + stop_dist_x;
    goal_y_ = state_y_ + stop_dist_y;
    goal_z_ = state_z_ + vertical_stop_dist;

    ROS_INFO("[LineTracker]: setting z goal to %.2f", goal_z_);
  }

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[LineTracker]: " << ss.str());

  changeState(STOP_MOTION_STATE);

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void LineTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[LineTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool LineTracker::resetStatic(void) {

  if (!is_initialized_) {
    ROS_ERROR("[LineTracker]: can not reset, not initialized");
    return false;
  }

  if (!is_active_) {
    ROS_ERROR("[LineTracker]: can not reset, not active");
    return false;
  }

  ROS_INFO("[LineTracker]: reseting with no dynamics");

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;
  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[LineTracker]: could not calculate the UAV heading");
    return false;
  }

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_, mutex_uav_state_);

    state_x_       = uav_state_.pose.position.x;
    state_y_       = uav_state_.pose.position.y;
    state_z_       = uav_state_.pose.position.z;
    state_heading_ = uav_heading;

    speed_x_                  = 0;
    speed_y_                  = 0;
    current_heading_          = 0;
    current_horizontal_speed_ = 0;

    current_vertical_speed_     = 0;
    current_vertical_direction_ = 0;

    current_horizontal_acceleration_ = 0;
    current_vertical_acceleration_   = 0;

    goal_heading_ = uav_heading;
  }

  changeState(IDLE_STATE);

  return true;
}

//}

/* //{ update() */

std::optional<mrs_msgs::TrackerCommand> LineTracker::update(const mrs_msgs::UavState &                                          uav_state,
                                                            [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("LineTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;
    uav_x_     = uav_state_.pose.position.x;
    uav_y_     = uav_state_.pose.position.y;
    uav_z_     = uav_state_.pose.position.z;

    got_uav_state_ = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  mrs_msgs::TrackerCommand tracker_cmd;

  tracker_cmd.header.stamp    = ros::Time::now();
  tracker_cmd.header.frame_id = uav_state.header.frame_id;

  {
    std::scoped_lock lock(mutex_state_);

    tracker_cmd.position.x = state_x_;
    tracker_cmd.position.y = state_y_;
    tracker_cmd.position.z = state_z_;
    tracker_cmd.heading    = radians::wrap(state_heading_);

    tracker_cmd.velocity.x   = cos(current_heading_) * current_horizontal_speed_;
    tracker_cmd.velocity.y   = sin(current_heading_) * current_horizontal_speed_;
    tracker_cmd.velocity.z   = current_vertical_direction_ * current_vertical_speed_;
    tracker_cmd.heading_rate = speed_heading_;

    tracker_cmd.acceleration.x = 0;
    tracker_cmd.acceleration.y = 0;
    tracker_cmd.acceleration.z = current_vertical_direction_ * current_vertical_acceleration_;

    tracker_cmd.use_position_vertical   = 1;
    tracker_cmd.use_position_horizontal = 1;
    tracker_cmd.use_heading             = 1;
    tracker_cmd.use_heading_rate        = 1;
    tracker_cmd.use_velocity_vertical   = 1;
    tracker_cmd.use_velocity_horizontal = 1;
    tracker_cmd.use_acceleration        = 1;
  }

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus LineTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  bool idling = current_state_vertical_ == IDLE_STATE && current_state_horizontal_ == IDLE_STATE;

  tracker_status.have_goal = !idling;

  tracker_status.tracking_trajectory = false;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr LineTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[LineTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[LineTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr LineTracker::switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state) {

  std::scoped_lock lock(mutex_goal_, mutex_state_);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double old_heading, new_heading;
  bool   got_headings = true;

  try {
    old_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[LineTracker]: could not calculate the old UAV heading");
    got_headings = false;
  }

  try {
    new_heading = mrs_lib::AttitudeConverter(new_uav_state->pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[LineTracker]: could not calculate the new UAV heading");
    got_headings = false;
  }

  std_srvs::TriggerResponse res;

  if (!got_headings) {
    res.message = "could not calculate the heading difference";
    res.success = false;

    return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
  }

  // | --------- recalculate the goal to new coordinates -------- |

  double dx       = new_uav_state->pose.position.x - uav_state.pose.position.x;
  double dy       = new_uav_state->pose.position.y - uav_state.pose.position.y;
  double dz       = new_uav_state->pose.position.z - uav_state.pose.position.z;
  double dheading = new_heading - old_heading;

  goal_x_ += dx;
  goal_y_ += dy;
  goal_z_ += dz;
  goal_heading_ += dheading;

  // | -------------------- update the state -------------------- |

  state_x_ += dx;
  state_y_ += dy;
  state_z_ += dz;
  state_heading_ += dheading;

  current_heading_ = atan2(goal_y_ - state_y_, goal_x_ - state_x_);

  res.message = "odometry source switched";
  res.success = true;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr LineTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  std_srvs::TriggerResponse res;

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  {
    std::scoped_lock lock(mutex_state_, mutex_uav_state_);

    current_horizontal_speed_ = sqrt(pow(uav_state_.velocity.linear.x, 2) + pow(uav_state_.velocity.linear.y, 2));
    current_vertical_speed_   = uav_state_.velocity.linear.z;
    current_heading_          = atan2(uav_state_.velocity.linear.y, uav_state_.velocity.linear.x);
  }

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  {
    std::scoped_lock lock(mutex_state_);

    horizontal_t_stop    = current_horizontal_speed_ / _horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed_) / 2.0;
    stop_dist_x          = cos(current_heading_) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading_) * horizontal_stop_dist;
  }

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state_);

    vertical_t_stop    = current_vertical_speed_ / _vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction_ * (vertical_t_stop * current_vertical_speed_) / 2.0;
  }

  // --------------------------------------------------------------
  // |                        set the goal                        |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_);

    goal_x_ = state_x_ + stop_dist_x;
    goal_y_ = state_y_ + stop_dist_y;
    goal_z_ = state_z_ + vertical_stop_dist;
  }

  res.message = "hover initiated";
  res.success = true;

  changeState(STOP_MOTION_STATE);

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LineTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LineTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LineTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr LineTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr LineTracker::setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  mrs_msgs::DynamicsConstraintsSrvResponse res;

  // this is the place to copy the constraints
  {
    std::scoped_lock lock(mutex_constraints_);

    _horizontal_speed_        = cmd->constraints.horizontal_speed;
    _horizontal_acceleration_ = cmd->constraints.horizontal_acceleration;

    _vertical_speed_        = cmd->constraints.vertical_ascending_speed;
    _vertical_acceleration_ = cmd->constraints.vertical_ascending_acceleration;

    _heading_rate_ = cmd->constraints.heading_speed;
  }

  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr(new mrs_msgs::DynamicsConstraintsSrvResponse(res));
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr LineTracker::setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  mrs_msgs::ReferenceSrvResponse res;

  auto state_heading = mrs_lib::get_mutexed(mutex_state_, state_heading_);

  {
    std::scoped_lock lock(mutex_goal_);

    goal_x_       = cmd->reference.position.x;
    goal_y_       = cmd->reference.position.y;
    goal_z_       = cmd->reference.position.z;
    goal_heading_ = radians::unwrap(cmd->reference.heading, state_heading);

    ROS_INFO("[LineTracker]: received new setpoint %.2f, %.2f, %.2f, %.2f", goal_x_, goal_y_, goal_z_, goal_heading_);

    have_goal_ = true;
  }

  changeState(STOP_MOTION_STATE);

  res.success = true;
  res.message = "reference set";

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr LineTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr LineTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | ----------------- state machine routines ----------------- |

/* //{ changeStateHorizontal() */

void LineTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal_ = current_state_horizontal_;
  current_state_horizontal_  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching horizontal state %s -> %s", state_names[previous_state_horizontal_], state_names[current_state_horizontal_]);
}

//}

/* //{ changeStateVertical() */

void LineTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical_ = current_state_vertical_;
  current_state_vertical_  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching vertical state %s -> %s", state_names[previous_state_vertical_], state_names[current_state_vertical_]);
}

//}

/* //{ changeState() */

void LineTracker::changeState(States_t new_state) {

  changeStateVertical(new_state);
  changeStateHorizontal(new_state);
}

//}

// | --------------------- motion routines -------------------- |

/* //{ stopHorizontalMotion() */

void LineTracker::stopHorizontalMotion(void) {

  {
    std::scoped_lock lock(mutex_state_);

    current_horizontal_speed_ -= _horizontal_acceleration_ * _tracker_dt_;

    if (current_horizontal_speed_ < 0) {
      current_horizontal_speed_        = 0;
      current_horizontal_acceleration_ = 0;
    } else {
      current_horizontal_acceleration_ = -_horizontal_acceleration_;
    }
  }
}

//}

/* //{ stopVerticalMotion() */

void LineTracker::stopVerticalMotion(void) {

  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_speed_ -= _vertical_acceleration_ * _tracker_dt_;

    if (current_vertical_speed_ < 0) {
      current_vertical_speed_        = 0;
      current_vertical_acceleration_ = 0;
    } else {
      current_vertical_acceleration_ = -_vertical_acceleration_;
    }
  }
}

//}

/* //{ accelerateHorizontal() */

void LineTracker::accelerateHorizontal(void) {

  // copy member variables
  auto [goal_x, goal_y]                             = mrs_lib::get_mutexed(mutex_goal_, goal_x_, goal_y_);
  auto [state_x, state_y, current_horizontal_speed] = mrs_lib::get_mutexed(mutex_state_, state_x_, state_y_, current_horizontal_speed_);

  {
    std::scoped_lock lock(mutex_state_);

    current_heading_ = atan2(goal_y - state_y, goal_x - state_x);
  }

  auto current_heading = mrs_lib::get_mutexed(mutex_state_, current_heading_);

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  horizontal_t_stop    = current_horizontal_speed / _horizontal_acceleration_;
  horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2.0;
  stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  {
    std::scoped_lock lock(mutex_state_);

    current_horizontal_speed_ += _horizontal_acceleration_ * _tracker_dt_;

    if (current_horizontal_speed_ >= _horizontal_speed_) {
      current_horizontal_speed_        = _horizontal_speed_;
      current_horizontal_acceleration_ = 0;
    } else {
      current_horizontal_acceleration_ = _horizontal_acceleration_;
    }
  }

  if (sqrt(pow(state_x + stop_dist_x - goal_x, 2) + pow(state_y + stop_dist_y - goal_y, 2)) < (2 * (_horizontal_speed_ * _tracker_dt_))) {

    {
      std::scoped_lock lock(mutex_state_);

      current_horizontal_acceleration_ = 0;
    }

    changeStateHorizontal(DECELERATING_STATE);
  }
}

//}

/* //{ accelerateVertical() */

void LineTracker::accelerateVertical(void) {

  auto goal_z                            = mrs_lib::get_mutexed(mutex_goal_, goal_z_);
  auto [state_z, current_vertical_speed] = mrs_lib::get_mutexed(mutex_state_, state_z_, current_vertical_speed_);

  // set the right heading
  double tar_z = goal_z - state_z;

  // set the right vertical direction
  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_direction_ = mrs_lib::signum(tar_z);
  }

  auto current_vertical_direction = mrs_lib::get_mutexed(mutex_state_, current_vertical_direction_);

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / _vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2.0;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_speed_ += _vertical_acceleration_ * _tracker_dt_;

    if (current_vertical_speed_ >= _vertical_speed_) {
      current_vertical_speed_        = _vertical_speed_;
      current_vertical_acceleration_ = 0;
    } else {
      current_vertical_acceleration_ = _vertical_acceleration_;
    }
  }

  if (fabs(state_z + stop_dist_z - goal_z) < (2 * (_vertical_speed_ * _tracker_dt_))) {

    {
      std::scoped_lock lock(mutex_state_);

      current_vertical_acceleration_ = 0;
    }

    changeStateVertical(DECELERATING_STATE);
  }
}

//}

/* //{ decelerateHorizontal() */

void LineTracker::decelerateHorizontal(void) {

  {
    std::scoped_lock lock(mutex_state_);

    current_horizontal_speed_ -= _horizontal_acceleration_ * _tracker_dt_;

    if (current_horizontal_speed_ < 0) {
      current_horizontal_speed_ = 0;
    } else {
      current_horizontal_acceleration_ = -_horizontal_acceleration_;
    }
  }

  auto current_horizontal_speed = mrs_lib::get_mutexed(mutex_state_, current_horizontal_speed_);

  if (current_horizontal_speed == 0) {

    {
      std::scoped_lock lock(mutex_state_);

      current_horizontal_acceleration_ = 0;
    }

    changeStateHorizontal(STOPPING_STATE);
  }
}

//}

/* //{ decelerateVertical() */

void LineTracker::decelerateVertical(void) {

  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_speed_ -= _vertical_acceleration_ * _tracker_dt_;

    if (current_vertical_speed_ < 0) {
      current_vertical_speed_ = 0;
    } else {
      current_vertical_acceleration_ = -_vertical_acceleration_;
    }
  }

  auto current_vertical_speed = mrs_lib::get_mutexed(mutex_state_, current_vertical_speed_);

  if (current_vertical_speed == 0) {
    current_vertical_acceleration_ = 0;
    changeStateVertical(STOPPING_STATE);
  }
}

//}

/* //{ stopHorizontal() */

void LineTracker::stopHorizontal(void) {

  {
    std::scoped_lock lock(mutex_state_);

    state_x_                         = 0.95 * state_x_ + 0.05 * goal_x_;
    state_y_                         = 0.95 * state_y_ + 0.05 * goal_y_;
    current_horizontal_acceleration_ = 0;
  }
}

//}

/* //{ stopVertical() */

void LineTracker::stopVertical(void) {

  {
    std::scoped_lock lock(mutex_state_);

    state_z_                       = 0.95 * state_z_ + 0.05 * goal_z_;
    current_vertical_acceleration_ = 0;
  }
}

//}

// | ------------------------- timers ------------------------- |

/* //{ mainTimer() */

void LineTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active_) {
    return;
  }

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("main", _tracker_loop_rate_, 0.01, event);
  mrs_lib::ScopeTimer timer            = mrs_lib::ScopeTimer("LineTracker::main", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  auto [goal_x, goal_y, goal_z]    = mrs_lib::get_mutexed(mutex_goal_, goal_x_, goal_y_, goal_z_);
  auto [state_x, state_y, state_z] = mrs_lib::get_mutexed(mutex_state_, state_x_, state_y_, state_z_);

  switch (current_state_horizontal_) {

    case IDLE_STATE:

      break;

    case STOP_MOTION_STATE:

      stopHorizontalMotion();

      break;

    case ACCELERATING_STATE:

      accelerateHorizontal();

      break;

    case DECELERATING_STATE:

      decelerateHorizontal();

      break;

    case STOPPING_STATE:

      stopHorizontal();

      break;
  }

  switch (current_state_vertical_) {

    case IDLE_STATE:

      break;

    case STOP_MOTION_STATE:

      stopVerticalMotion();

      break;

    case ACCELERATING_STATE:

      accelerateVertical();

      break;

    case DECELERATING_STATE:

      decelerateVertical();

      break;

    case STOPPING_STATE:

      stopVertical();

      break;
  }

  if (current_state_horizontal_ == STOP_MOTION_STATE && current_state_vertical_ == STOP_MOTION_STATE) {
    if (current_vertical_speed_ == 0 && current_horizontal_speed_ == 0) {
      if (have_goal_) {
        changeState(ACCELERATING_STATE);
      } else {
        changeState(STOPPING_STATE);
      }
    }
  }

  if (current_state_horizontal_ == STOPPING_STATE && current_state_vertical_ == STOPPING_STATE) {
    if (fabs(state_x - goal_x) < 1e-3 && fabs(state_y - goal_y) < 1e-3 && fabs(state_z - goal_z) < 1e-3) {

      {
        std::scoped_lock lock(mutex_state_);

        state_x_ = goal_x;
        state_y_ = goal_y;
        state_z_ = goal_z;
      }

      changeState(IDLE_STATE);

      have_goal_ = false;
    }
  }

  {
    std::scoped_lock lock(mutex_state_);

    state_x_ += cos(current_heading_) * current_horizontal_speed_ * _tracker_dt_;
    state_y_ += sin(current_heading_) * current_horizontal_speed_ * _tracker_dt_;
    state_z_ += current_vertical_direction_ * current_vertical_speed_ * _tracker_dt_;
  }

  // --------------------------------------------------------------
  // |                        heading tracking                        |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_state_);

    // compute the desired heading rate
    double current_heading_rate;
    if (fabs(goal_heading_ - state_heading_) > M_PI)
      current_heading_rate = -_heading_gain_ * (goal_heading_ - state_heading_);
    else
      current_heading_rate = _heading_gain_ * (goal_heading_ - state_heading_);

    if (current_heading_rate > _heading_rate_) {
      current_heading_rate = _heading_rate_;
    } else if (current_heading_rate < -_heading_rate_) {
      current_heading_rate = -_heading_rate_;
    }

    // flap the resulted state_heading_ aroud PI
    state_heading_ += current_heading_rate * _tracker_dt_;

    if (fabs(state_heading_ - goal_heading_) < (2 * (_heading_rate_ * _tracker_dt_))) {
      state_heading_ = goal_heading_;
    }
  }
}

//}

}  // namespace line_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::line_tracker::LineTracker, mrs_uav_managers::Tracker)
