/* includes //{ */

#include <ros/ros.h>
#include <ros/package.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_msgs/Vec1.h>
#include <mrs_msgs/UavState.h>
#include <mrs_msgs/VelocityReferenceSrv.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/utils.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>

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

namespace landoff_tracker
{

/* //{ class LandoffTracker */

// state machine
typedef enum
{

  IDLE_STATE,
  LANDED_STATE,
  STOP_MOTION_STATE,
  HOVER_STATE,
  ACCELERATING_STATE,
  DECELERATING_STATE,
  STOPPING_STATE,

} States_t;

const std::array<const char*, 7> state_names = {

    "IDLING", "LANDED", "STOPPING_MOTION", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

class LandoffTracker : public mrs_uav_managers::Tracker {
public:
  bool initialize(const ros::NodeHandle& nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers);

  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::TrackerCommand>& last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::TrackerCommand>   update(const mrs_msgs::UavState& uav_state, const mrs_uav_managers::Controller::ControlOutput& last_control_output);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState& new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr& cmd);
  const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr   setVelocityReference(const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr& cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr& cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr& cmd);

  const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr& cmd);

private:
  bool callbacks_enabled_ = true;

  mrs_uav_managers::Controller::ControlOutput last_control_output_;
  std::mutex                                  mutex_last_control_output_;

  ros::NodeHandle nh_;
  std::string     _uav_name_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  // main timer
  void       timerMain(const ros::TimerEvent& event);
  ros::Timer timer_main_;
  std::mutex mutex_main_timer_;

  std::atomic<bool> activate_as_the_first_tracker = false;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ---------------- the tracker's inner state --------------- |

  int    _main_timer_rate_;
  double _landing_reference_;
  double _tracker_dt_;
  bool   is_initialized_ = false;
  bool   is_active_      = false;

  bool   _takeoff_disable_lateral_gains_ = false;
  double _takeoff_disable_lateral_gains_z_;

  // | --------------- the tracker's state machine -------------- |

  States_t current_state_vertical_    = IDLE_STATE;
  States_t previous_state_vertical_   = IDLE_STATE;
  States_t current_state_horizontal_  = IDLE_STATE;
  States_t previous_state_horizontal_ = IDLE_STATE;

  void changeStateHorizontal(States_t new_state);
  void changeStateVertical(States_t new_state);
  void changeState(States_t new_state);

  std::atomic<bool> taking_off_ = false;
  std::atomic<bool> landing_    = false;
  std::atomic<bool> elanding_   = false;

  std::atomic<bool> cause_failsafe_ = false;

  void stopHorizontalMotion(void);
  void stopVerticalMotion(void);
  void accelerateVertical(void);
  void decelerateVertical(void);
  void stopHorizontal(void);
  void stopVertical(void);

  // | --------------- takeoff / landing services --------------- |

  ros::ServiceServer service_takeoff_;
  ros::ServiceServer service_land_;
  ros::ServiceServer service_eland_;

  bool callbackTakeoff(mrs_msgs::Vec1::Request& req, mrs_msgs::Vec1::Response& res);
  bool callbackLand(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res);
  bool callbackELand(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res);

  // | ------------------ dynamics constraints ------------------ |

  double _horizontal_speed_;
  double _vertical_speed_;
  double _takeoff_speed_;
  double _landing_speed_;
  double _elanding_speed_;

  double _horizontal_acceleration_;
  double _vertical_acceleration_;
  double _takeoff_acceleration_;
  double _landing_acceleration_;
  double _elanding_acceleration_;

  double _heading_rate_;
  double _heading_gain_;

  double _max_position_difference_;

  // | -------------------------- goal -------------------------- |

  double            goal_x_, goal_y_, goal_z_, goal_heading_;
  std::atomic<bool> have_goal_ = false;
  std::mutex        mutex_goal_;

  // | ---------------- tracker's internal state ---------------- |

  double     state_x_, state_y_, state_z_, state_heading_;
  double     speed_x_, speed_y_, speed_heading_;
  double     current_heading_, current_vertical_direction_, current_vertical_speed_, current_horizontal_speed_;
  double     current_horizontal_acceleration_, current_vertical_acceleration_;
  std::mutex mutex_state_;

  // | -------------------- tracker's output -------------------- |

  mrs_msgs::TrackerCommand position_output_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;

  // | ----------------------- constraints ---------------------- |

  mrs_msgs::DynamicsConstraints constraints_;
  std::mutex                    mutex_constraints_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool LandoffTracker::initialize(const ros::NodeHandle& nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
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
    ROS_ERROR("[LandoffTracker]: Could not load all parameters!");
    return false;
  }

  // | --------------- loading plugin's parameters -------------- |

  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/private/landoff_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/public/landoff_tracker.yaml");

  const std::string yaml_prefix = "mrs_uav_trackers/landoff_tracker/";

  private_handlers->param_loader->loadParam(yaml_prefix + "horizontal_tracker/horizontal_speed", _horizontal_speed_);
  private_handlers->param_loader->loadParam(yaml_prefix + "horizontal_tracker/horizontal_acceleration", _horizontal_acceleration_);

  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/vertical_speed", _vertical_speed_);
  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/vertical_acceleration", _vertical_acceleration_);

  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/takeoff_speed", _takeoff_speed_);
  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/takeoff_acceleration", _takeoff_acceleration_);

  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/landing_speed", _landing_speed_);
  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/landing_acceleration", _landing_acceleration_);

  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/elanding_speed", _elanding_speed_);
  private_handlers->param_loader->loadParam(yaml_prefix + "vertical_tracker/elanding_acceleration", _elanding_acceleration_);

  private_handlers->param_loader->loadParam(yaml_prefix + "heading_tracker/heading_rate", _heading_rate_);
  private_handlers->param_loader->loadParam(yaml_prefix + "heading_tracker/heading_gain", _heading_gain_);

  private_handlers->param_loader->loadParam(yaml_prefix + "main_timer_rate", _main_timer_rate_);

  private_handlers->param_loader->loadParam(yaml_prefix + "landing_reference", _landing_reference_);

  private_handlers->param_loader->loadParam(yaml_prefix + "max_position_difference", _max_position_difference_);

  private_handlers->param_loader->loadParam(yaml_prefix + "takeoff_disable_lateral_gains", _takeoff_disable_lateral_gains_);
  private_handlers->param_loader->loadParam(yaml_prefix + "takeoff_disable_lateral_gains_z", _takeoff_disable_lateral_gains_z_);

  if (!private_handlers->param_loader->loadedSuccessfully()) {
    ROS_ERROR("[LandoffTracker]: Could not load all parameters!");
    return false;
  }

  _tracker_dt_ = 1.0 / double(_main_timer_rate_);

  ROS_INFO("[LandoffTracker]: tracker_dt: %f", _tracker_dt_);

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

  current_state_vertical_  = LANDED_STATE;
  previous_state_vertical_ = LANDED_STATE;

  current_state_horizontal_  = LANDED_STATE;
  previous_state_horizontal_ = LANDED_STATE;

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_nh, "LandoffTracker", _profiler_enabled_);

  // | ------------------------ services ------------------------ |

  service_takeoff_ = nh_.advertiseService("takeoff", &LandoffTracker::callbackTakeoff, this);
  service_land_    = nh_.advertiseService("land", &LandoffTracker::callbackLand, this);
  service_eland_   = nh_.advertiseService("eland", &LandoffTracker::callbackELand, this);

  // | ------------------------- timers ------------------------- |

  timer_main_ = nh_.createTimer(ros::Rate(_main_timer_rate_), &LandoffTracker::timerMain, this, false, false);

  // | ----------------------- finish init ---------------------- |

  is_initialized_ = true;

  ROS_INFO("[LandoffTracker]: initialized");

  return true;
}

//}

/* //{ activate() */

std::tuple<bool, std::string> LandoffTracker::activate([[maybe_unused]] const std::optional<mrs_msgs::TrackerCommand>& last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {

    ss << "odometry not set";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  activate_as_the_first_tracker = !last_tracker_cmd.has_value();

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {

    ss << "could not initialize the UAV heading";
    ROS_ERROR_STREAM("[LandoffTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  // --------------------------------------------------------------
  // |                      initial condition                     |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal_);

    // the last command is usable
    state_x_       = uav_state.pose.position.x;
    state_y_       = uav_state.pose.position.y;
    state_z_       = uav_state.pose.position.z;
    state_heading_ = uav_heading;

    speed_x_         = uav_state.velocity.linear.x;
    speed_y_         = uav_state.velocity.linear.y;
    current_heading_ = atan2(speed_y_, speed_x_);

    current_horizontal_speed_ = sqrt(pow(speed_x_, 2) + pow(speed_y_, 2));

    current_vertical_speed_     = fabs(uav_state.velocity.linear.z);
    current_vertical_direction_ = uav_state.velocity.linear.z > 0 ? +1 : -1;

    current_horizontal_acceleration_ = 0;
    current_vertical_acceleration_   = 0;

    goal_heading_ = uav_heading;

    ROS_INFO("[LandoffTracker]: initial condition: x: %.2f, y: %.2f, z: %.2f, heading: %.2f", state_x_, state_y_, state_z_, state_heading_);
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
  // |               heading initial condition prediction             |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_);

    goal_x_ = state_x_ + stop_dist_x;
    goal_y_ = state_y_ + stop_dist_y;
    goal_z_ = state_z_ + vertical_stop_dist;
  }

  landing_        = false;
  taking_off_     = false;
  is_active_      = true;
  have_goal_      = false;
  cause_failsafe_ = false;

  timer_main_.start();

  {
    std::scoped_lock lock(mutex_goal_);

    ROS_INFO("[LandoffTracker]: stopping goal: x: %.2f, y: %.2f, z: %.2f, heading: %.2f", goal_x_, goal_y_, goal_z_, goal_heading_);
  }

  changeState(STOP_MOTION_STATE);

  ss << "activated";
  ROS_INFO_STREAM("[LandoffTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void LandoffTracker::deactivate(void) {

  is_active_                = false;
  landing_                  = false;
  taking_off_               = false;
  current_state_vertical_   = IDLE_STATE;
  current_state_horizontal_ = IDLE_STATE;

  timer_main_.stop();

  ROS_INFO("[LandoffTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool LandoffTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::TrackerCommand> LandoffTracker::update(const mrs_msgs::UavState&                                           uav_state,
                                                               [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput& last_control_output) {

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("LandoffTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;

    got_uav_state_ = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_ || cause_failsafe_) {
    return {};
  }

  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state_.header.frame_id;

  {
    std::scoped_lock lock(mutex_state_);

    position_output_.position.x = state_x_;
    position_output_.position.y = state_y_;
    position_output_.position.z = state_z_;
    position_output_.heading    = state_heading_;

    position_output_.velocity.x   = cos(current_heading_) * current_horizontal_speed_;
    position_output_.velocity.y   = sin(current_heading_) * current_horizontal_speed_;
    position_output_.velocity.z   = current_vertical_direction_ * current_vertical_speed_;
    position_output_.heading_rate = speed_heading_;

    position_output_.use_position_vertical   = 1;
    position_output_.use_position_horizontal = 1;
    position_output_.use_heading             = 1;
    position_output_.use_heading_rate        = 1;
    position_output_.use_velocity_vertical   = 1;
    position_output_.use_velocity_horizontal = 1;
  }

  {
    std::scoped_lock lock(mutex_last_control_output_);

    last_control_output_ = last_control_output;
  }

  if (_takeoff_disable_lateral_gains_ && taking_off_ && uav_state_.pose.position.z < _takeoff_disable_lateral_gains_z_) {
    position_output_.disable_position_gains = true;
  } else {
    position_output_.disable_position_gains = false;
  }

  if (taking_off_) {
    position_output_.disable_antiwindups = true;
  } else {
    position_output_.disable_antiwindups = false;
  }

  return {position_output_};
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus LandoffTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  const bool hovering = current_state_vertical_ == HOVER_STATE && current_state_horizontal_ == HOVER_STATE;
  const bool idling   = current_state_vertical_ == IDLE_STATE && current_state_horizontal_ == IDLE_STATE;

  // the (hovering && activate_as_the_first_tracker) part of the condition makes sure that the IDLE will be
  // reported even when hovering on the ground, just before the takeoff service is called
  if (idling || (hovering && activate_as_the_first_tracker)) {

    tracker_status.state = mrs_msgs::TrackerStatus::STATE_IDLE;

  } else if (taking_off_) {

    tracker_status.state = mrs_msgs::TrackerStatus::STATE_TAKEOFF;

  } else if (hovering) {

    tracker_status.state = mrs_msgs::TrackerStatus::STATE_HOVER;

  } else if (landing_) {

    tracker_status.state = mrs_msgs::TrackerStatus::STATE_LAND;
  }

  tracker_status.have_goal = landing_ || taking_off_ || !(hovering || idling);

  tracker_status.tracking_trajectory = false;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr LandoffTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr& cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[LandoffTrakcer]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[LandoffTrakcer]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState& new_uav_state) {

  std::scoped_lock lock(mutex_goal_, mutex_state_);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double old_heading  = 0;
  double new_heading  = 0;
  bool   got_headings = true;

  try {
    old_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[LandoffTracker]: could not calculate the old UAV heading");
    got_headings = false;
  }

  try {
    new_heading = mrs_lib::AttitudeConverter(new_uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[LandoffTracker]: could not calculate the new UAV heading");
    got_headings = false;
  }

  std_srvs::TriggerResponse res;

  if (!got_headings) {
    res.message = "could not calculate the heading difference";
    res.success = false;

    return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
  }

  // | --------- recalculate the goal to new coordinates -------- |

  double dx       = new_uav_state.pose.position.x - uav_state.pose.position.x;
  double dy       = new_uav_state.pose.position.y - uav_state.pose.position.y;
  double dz       = new_uav_state.pose.position.z - uav_state.pose.position.z;
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
const std_srvs::TriggerResponse::ConstPtr LandoffTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {

  std::scoped_lock lock(mutex_main_timer_);

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  auto [current_horizontal_speed, current_vertical_speed, current_heading, current_vertical_direction] =
      mrs_lib::get_mutexed(mutex_state_, current_horizontal_speed_, current_vertical_speed_, current_heading_, current_vertical_direction_);

  std_srvs::TriggerResponse res;

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  {
    std::scoped_lock lock(mutex_state_);

    current_horizontal_speed_ = sqrt(pow(uav_state.velocity.linear.x, 2) + pow(uav_state.velocity.linear.y, 2));
    current_vertical_speed_   = uav_state.velocity.linear.z;
    current_heading_          = atan2(uav_state.velocity.linear.y, uav_state.velocity.linear.x);
  }

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  horizontal_t_stop    = current_horizontal_speed / _horizontal_acceleration_;
  horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2.0;
  stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop    = current_vertical_speed / _vertical_acceleration_;
  double vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2.0;

  // --------------------------------------------------------------
  // |                        set the goal                        |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_state_, mutex_goal_);

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

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr LandoffTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr& cmd) {


  mrs_lib::set_mutexed(mutex_constraints_, cmd->constraints, constraints_);

  ROS_INFO("[LandoffTracker]: updating constraints");

  mrs_msgs::DynamicsConstraintsSrvResponse res;
  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr(new mrs_msgs::DynamicsConstraintsSrvResponse(res));
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr LandoffTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr& cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr LandoffTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr& cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr LandoffTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr& cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | ----------------- state machine routines ----------------- |

/* //{ changeStateHorizontal() */

void LandoffTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal_ = current_state_horizontal_;
  current_state_horizontal_  = new_state;

  switch (current_state_horizontal_) {

    case STOPPING_STATE: {

      std::scoped_lock lock(mutex_state_);
      current_horizontal_speed_ = 0;

      break;
    };

    default: {

      break;
    }
  }

  ROS_INFO("[LandoffTracker]: Switching horizontal state %s -> %s", state_names.at(previous_state_horizontal_), state_names.at(current_state_horizontal_));
}

//}

/* //{ changeStateVertical() */

void LandoffTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical_ = current_state_vertical_;
  current_state_vertical_  = new_state;

  switch (current_state_vertical_) {

    case HOVER_STATE: {
      taking_off_ = false;
      break;
    }

    default: {
      break;
    }
  }

  ROS_INFO("[LandoffTracker]: Switching vertical state %s -> %s", state_names.at(previous_state_vertical_), state_names.at(current_state_vertical_));
}

//}

/* //{ changeState() */

void LandoffTracker::changeState(States_t new_state) {

  changeStateVertical(new_state);
  changeStateHorizontal(new_state);
}

//}

// | --------------------- motion routines -------------------- |

/* //{ stopHorizontalMotion() */

void LandoffTracker::stopHorizontalMotion(void) {

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

void LandoffTracker::stopVerticalMotion(void) {

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

/* //{ accelerateVertical() */

void LandoffTracker::accelerateVertical(void) {

  // copy member variables
  auto [current_vertical_speed, state_z] = mrs_lib::get_mutexed(mutex_state_, current_vertical_speed_, state_z_);
  auto goal_z                            = mrs_lib::get_mutexed(mutex_goal_, goal_z_);
  auto constraints                       = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

  double used_acceleration;
  double used_speed;

  if (taking_off_) {

    used_speed        = _takeoff_speed_;
    used_acceleration = _takeoff_acceleration_;

    if (used_speed > constraints.vertical_ascending_speed) {
      used_speed = constraints.vertical_ascending_speed;
      ROS_WARN_THROTTLE(1.0, "[LandoffTracker]: saturating takeoff speed");
    }

    if (used_acceleration > constraints.vertical_ascending_acceleration) {
      used_acceleration = constraints.vertical_ascending_acceleration;
      ROS_WARN_THROTTLE(1.0, "[LandoffTracker]: saturating takeoff acceleration");
    }

  } else if (landing_) {

    if (elanding_) {

      used_speed        = _elanding_speed_;
      used_acceleration = _elanding_acceleration_;

    } else {

      used_speed        = _landing_speed_;
      used_acceleration = _landing_acceleration_;

      if (used_speed > constraints.vertical_descending_speed) {
        used_speed = constraints.vertical_descending_speed;
        ROS_WARN_THROTTLE(1.0, "[LandoffTracker]: saturating landing speed");
      }

      if (used_acceleration > constraints.vertical_descending_acceleration) {
        used_acceleration = constraints.vertical_descending_acceleration;
        ROS_WARN_THROTTLE(1.0, "[LandoffTracker]: saturating landing acceleration");
      }
    }

  } else {

    // TODO take this from constraints
    used_speed        = _vertical_speed_;
    used_acceleration = _vertical_acceleration_;
  }

  // set the right heading
  double tar_z = goal_z - state_z;

  // set the right vertical direction
  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_direction_ = mrs_lib::signum(tar_z);
  }

  auto current_vertical_direction = mrs_lib::get_mutexed(mutex_state_, current_vertical_direction_);

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / used_acceleration;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2.0;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_speed_ += used_acceleration * _tracker_dt_;

    if (current_vertical_speed_ >= used_speed) {
      current_vertical_speed_ -= _vertical_acceleration_ * _tracker_dt_;
      current_vertical_acceleration_ = 0;
    } else {
      current_vertical_acceleration_ = used_acceleration;
    }
  }

  // stopping condition to change to decelerate state
  //
  // It does not apply if landing or elanding, cause,
  // it could potentially stop in mid air if odometry jumps (this happened),
  // Instead, landing and elanding is stopped by sensing the throttle.
  if (!elanding_ && !landing_) {
    if (fabs(state_z + stop_dist_z - goal_z) < (2 * (used_speed * _tracker_dt_))) {

      {
        std::scoped_lock lock(mutex_state_);

        current_vertical_acceleration_ = 0;
      }

      changeStateVertical(DECELERATING_STATE);
    }
  }
}

//}

/* //{ decelerateVertical() */

void LandoffTracker::decelerateVertical(void) {

  double used_acceleration;

  if (taking_off_) {

    used_acceleration = _takeoff_acceleration_;

  } else if (landing_) {

    if (elanding_) {

      used_acceleration = _elanding_acceleration_;

    } else {

      used_acceleration = _landing_acceleration_;
    }

  } else {
    used_acceleration = _vertical_acceleration_;
  }

  {
    std::scoped_lock lock(mutex_state_);

    current_vertical_speed_ -= used_acceleration * _tracker_dt_;

    if (current_vertical_speed_ < 0) {
      current_vertical_speed_ = 0;
    } else {
      current_vertical_acceleration_ = -used_acceleration;
    }
  }

  auto current_vertical_speed = mrs_lib::get_mutexed(mutex_state_, current_vertical_speed_);

  if (current_vertical_speed == 0) {

    {
      std::scoped_lock lock(mutex_state_);

      current_vertical_acceleration_ = 0;
    }

    changeStateVertical(STOPPING_STATE);
  }
}

//}

/* //{ stopHorizontal() */

void LandoffTracker::stopHorizontal(void) {

  {
    std::scoped_lock lock(mutex_state_, mutex_goal_);

    double new_state_x = 0.95 * state_x_ + 0.05 * goal_x_;
    double new_state_y = 0.95 * state_y_ + 0.05 * goal_y_;

    double dist_x = new_state_x - state_x_;
    double dist_y = new_state_y - state_y_;

    double dt = 1.0 / _main_timer_rate_;

    if (std::abs(dist_x / dt) > 1.0) {
      dist_x = mrs_lib::signum(dist_x) * (1.0 * dt);
    }

    if (std::abs(dist_y / dt) > 1.0) {
      dist_y = mrs_lib::signum(dist_y) * (1.0 * dt);
    }

    state_x_ += dist_x;
    state_y_ += dist_y;

    current_horizontal_acceleration_ = 0;
  }
}

//}

/* //{ stopVertical() */

void LandoffTracker::stopVertical(void) {

  {
    std::scoped_lock lock(mutex_state_, mutex_goal_);

    double new_state_z = 0.95 * state_z_ + 0.05 * goal_z_;

    double dist_z = new_state_z - state_z_;

    double dt = 1.0 / _main_timer_rate_;

    if (std::abs(dist_z / dt) > 1.0) {
      dist_z = mrs_lib::signum(dist_z) * (1.0 * dt);
    }

    state_z_ += dist_z;

    current_vertical_acceleration_ = 0;
  }
}

//}

// | --------------------- timer routines --------------------- |

/* //{ timerMain() */

void LandoffTracker::timerMain(const ros::TimerEvent& event) {

  std::scoped_lock lock(mutex_main_timer_);

  if (!is_active_) {
    return;
  }

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto [state_x, state_y, state_z, current_horizontal_speed, current_vertical_speed, current_heading, current_vertical_direction] = mrs_lib::get_mutexed(
      mutex_state_, state_x_, state_y_, state_z_, current_horizontal_speed_, current_vertical_speed_, current_heading_, current_vertical_direction_);
  auto [goal_x, goal_y, goal_z] = mrs_lib::get_mutexed(mutex_goal_, goal_x_, goal_y_, goal_z_);
  auto last_control_output      = mrs_lib::get_mutexed(mutex_last_control_output_, last_control_output_);

  double uav_x, uav_y, uav_z;
  uav_x = uav_state.pose.position.x;
  uav_y = uav_state.pose.position.y;
  uav_z = uav_state.pose.position.z;

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("main", _main_timer_rate_, 0.002, event);
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("LandoffTracker::main", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  bool takeoff_saturated = false;

  if (taking_off_) {

    // calculate the vector
    double err_x      = uav_x - state_x;
    double err_y      = uav_y - state_y;
    double err_z      = uav_z - state_z;
    double error_size = sqrt(pow(err_x, 2) + pow(err_y, 2) + pow(err_z, 2));

    if (error_size > _max_position_difference_) {

      // calculate the potential next step
      double future_state_x = state_x + cos(current_heading) * current_horizontal_speed * _tracker_dt_;
      double future_state_y = state_y + sin(current_heading) * current_horizontal_speed * _tracker_dt_;
      double future_state_z = state_z + current_vertical_direction * current_vertical_speed * _tracker_dt_;

      // if the step would lead to a greater control error than the threshold
      if (mrs_lib::geometry::dist(vec3_t(future_state_x, future_state_y, future_state_z), vec3_t(uav_x, uav_y, uav_z)) > error_size) {

        // set this to true... later, we will not update the model if this is true, thus the tracker's motion will stop
        // => the tracker will wait for the controller
        takeoff_saturated = true;

        ROS_WARN_THROTTLE(
            0.1, "[LandoffTracker]: position difference %.3f > %.3f, saturating the motion. Reference: x=%.2f, y=%.2f, z=%.2f, Odometry: %.2f, %.2f, %.2f",
            error_size, _max_position_difference_, future_state_x, future_state_y, future_state_z, uav_x, uav_y, uav_z);
      }
    }

    // saturate while ramping up during takeoff
    if (last_control_output.diagnostics.ramping_up) {

      ROS_INFO_THROTTLE(1.0, "[LandoffTracker]: waiting for the controller to rampup");
      takeoff_saturated = true;
    }
  }

  if (!takeoff_saturated) {

    switch (current_state_horizontal_) {

      case STOP_MOTION_STATE: {

        stopHorizontalMotion();
        break;
      }

      case STOPPING_STATE: {

        stopHorizontal();
        break;
      }

      default: {

        break;
      }
    }

    switch (current_state_vertical_) {

      case STOP_MOTION_STATE: {

        stopVerticalMotion();
        break;
      }

      case ACCELERATING_STATE: {

        accelerateVertical();
        break;
      }

      case DECELERATING_STATE: {

        decelerateVertical();
        break;
      }

      case STOPPING_STATE: {

        stopVertical();
        break;
      }

      default: {

        break;
      }
    }
  }

  if (current_state_horizontal_ == STOP_MOTION_STATE && current_state_vertical_ == STOP_MOTION_STATE) {
    if (fabs(current_vertical_speed) <= 0.1 && fabs(current_horizontal_speed) <= 0.1) {

      // if the current motion was stopped (the conditions above) but we still have a goal (landing or taking off)
      // -> we should start accelerating towards the goal in the vertical direction
      // This is important, do not modify without testing, otherwise your landing routine may crash into the ground
      // while having large lateral speed
      if (have_goal_) {

        changeStateVertical(ACCELERATING_STATE);
        changeStateHorizontal(STOPPING_STATE);

      } else {

        changeState(STOPPING_STATE);

        {
          std::scoped_lock lock(mutex_state_);

          current_horizontal_speed_ = 0;
          current_vertical_speed_   = 0;
        }
      }
    }
  }

  if (current_state_vertical_ == STOPPING_STATE && current_state_horizontal_ == STOPPING_STATE) {

    if (fabs(state_x - goal_x) > 1.0 || fabs(state_y - goal_y) > 1.0 || fabs(state_z - goal_z) > 1.0) {

      ROS_ERROR("[LandoffTracker]: distance to the goal is too large when STOPPING, this could have been caused by a race condition!");
      ROS_ERROR("[LandoffTracker]: call for Tomas!!");

      cause_failsafe_ = true;

      changeState(HOVER_STATE);

    } else if (fabs(state_x - goal_x) < 0.1 && fabs(state_y - goal_y) < 0.1 && fabs(state_z - goal_z) < 0.1) {

      {
        std::scoped_lock lock(mutex_state_);

        if (!taking_off_) {
          state_x_ = goal_x;
          state_y_ = goal_y;
          state_z_ = goal_z;
        }

        current_horizontal_speed_ = 0;
        current_vertical_speed_   = 0;
      }

      changeState(HOVER_STATE);

      have_goal_ = false;
    }
  }

  if (current_state_horizontal_ == LANDED_STATE && current_state_vertical_ == LANDED_STATE) {
    {
      std::scoped_lock lock(mutex_state_);

      state_x_ = goal_x = uav_x;
      state_y_ = goal_y = uav_y;
      state_z_ = goal_z = uav_z;

      have_goal_ = false;
    }
  }

  // --------------------------------------------------------------
  // |              motion saturation during takeoff              |
  // --------------------------------------------------------------

  // update the inner states
  if (!takeoff_saturated) {
    {
      std::scoped_lock lock(mutex_state_);

      state_x_ += cos(current_heading) * current_horizontal_speed * _tracker_dt_;
      state_y_ += sin(current_heading) * current_horizontal_speed * _tracker_dt_;
      state_z_ += current_vertical_direction * current_vertical_speed * _tracker_dt_;
    }
  }

  // --------------------------------------------------------------
  // |                        heading tracking                        |
  // --------------------------------------------------------------

  // compute the desired heading rate
  {
    std::scoped_lock lock(mutex_state_);

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

    if (state_heading_ > M_PI) {
      state_heading_ -= 2 * M_PI;
    } else if (state_heading_ < -M_PI) {
      state_heading_ += 2 * M_PI;
    }

    if (fabs(state_heading_ - goal_heading_) < (2 * (_heading_rate_ * _tracker_dt_))) {
      state_heading_ = goal_heading_;
    }
  }

  // --------------------------------------------------------------
  // |                      landing setpoint                      |
  // --------------------------------------------------------------

  if (landing_) {
    {
      std::scoped_lock lock(mutex_goal_);

      goal_z_ = uav_z + _landing_reference_;
    }
  }
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ callbackTakeoff() */

bool LandoffTracker::callbackTakeoff(mrs_msgs::Vec1::Request& req, mrs_msgs::Vec1::Response& res) {

  std::stringstream ss;

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();

  double uav_x, uav_y, uav_z;
  uav_x = uav_state.pose.position.x;
  uav_y = uav_state.pose.position.y;
  uav_z = uav_state.pose.position.z;

  if (!is_active_) {
    ss << "can not takeoff, the tracker is not active";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    res.success = false;
    res.message = ss.str();
    return true;
  }

  if (!callbacks_enabled_) {
    ss << "can not takeoff, the callbacks are disabled";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    res.success = false;
    res.message = ss.str();
    return true;
  }

  if (req.goal < 0.5 || req.goal > 10.0) {

    ss << "can not takeoff, the goal should be within [0.5, 10.0] m!";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    res.success = false;
    res.message = ss.str();
    return true;
  }

  {
    std::scoped_lock lock(mutex_goal_, mutex_state_);

    state_x_ = uav_x;
    goal_x_  = uav_x;

    state_y_ = uav_y;
    goal_y_  = uav_y;

    state_z_ = uav_z;
    goal_z_  = uav_z + req.goal;

    state_heading_ = uav_heading;
    goal_heading_  = uav_heading;

    speed_x_                = 0;
    speed_y_                = 0;
    current_vertical_speed_ = 0;

    have_goal_ = true;
  }

  ROS_INFO("[LandoffTracker]: taking off");

  taking_off_ = true;
  landing_    = false;
  elanding_   = false;

  res.success = true;
  res.message = "taking off";

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

/* //{ callbackLand() */

bool LandoffTracker::callbackLand([[maybe_unused]] std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res) {

  std::scoped_lock lock(mutex_main_timer_);

  std::stringstream ss;

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  if (!is_active_) {
    ss << "can not land, the tracker is not active";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    res.success = false;
    res.message = ss.str();
    return true;
  }

  {
    std::scoped_lock lock(mutex_goal_);

    goal_z_ = uav_state.pose.position.z + _landing_reference_;
  }

  ROS_INFO("[LandoffTracker]: landing");

  landing_    = true;
  elanding_   = false;
  taking_off_ = false;
  have_goal_  = true;

  res.success = true;
  res.message = "landing";

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

/* //{ callbackELand() */

bool LandoffTracker::callbackELand([[maybe_unused]] std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res) {

  std::scoped_lock lock(mutex_main_timer_);

  std::stringstream ss;

  // copy member variables
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  if (!is_active_) {

    ss << "can not eland, the tracker is not active";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[LandoffTracker]: " << ss.str());
    res.success = false;
    res.message = ss.str();
    taking_off_ = false;
    landing_    = false;
    elanding_   = false;
    changeState(LANDED_STATE);
    return true;
  }

  {
    std::scoped_lock lock(mutex_goal_);

    goal_z_ = uav_state.pose.position.z + _landing_reference_;
  }

  ROS_WARN("[LandoffTracker]: emergency landing");

  landing_    = true;
  elanding_   = true;
  taking_off_ = false;
  have_goal_  = true;

  res.success = true;
  res.message = "elanding";

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

}  // namespace landoff_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::landoff_tracker::LandoffTracker, mrs_uav_managers::Tracker)
