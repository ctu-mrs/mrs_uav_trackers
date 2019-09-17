/* includes //{ */

#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>

#include <mrs_msgs/Vec1.h>
#include <mrs_msgs/LandoffDiagnostics.h>

#include <mrs_uav_manager/Tracker.h>
#include <nav_msgs/Odometry.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>

//}

#define STOP_THR 1e-3

namespace mrs_trackers
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

const char *state_names[7] = {

    "IDLING", "LANDED", "STOPPING_MOTION", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

class LandoffTracker : public mrs_uav_manager::Tracker {
public:
  virtual void initialize(const ros::NodeHandle &parent_nh, mrs_uav_manager::SafetyArea_t const *safety_area);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  virtual const mrs_msgs::TrackerStatus             getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  virtual void                                      switchOdometrySource(const nav_msgs::Odometry::ConstPtr &msg);

  virtual const mrs_msgs::Vec4Response::ConstPtr goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec4Response::ConstPtr goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToAltitude(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYaw(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYawRelative(const std_msgs::Float64ConstPtr &msg);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

  virtual const mrs_msgs::TrackerConstraintsResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd);

  void resetLateralOdometry(void);
  void replicateOdometry(void);

private:
  ros::ServiceClient service_client_reset_lateral_odometry;
  ros::Time          lateral_odometry_reset_time;
  bool               lateral_odometry_being_reset = false;

private:
  bool callbacks_enabled = true;

private:
  mrs_uav_manager::SafetyArea_t const *safety_area;

private:
  nav_msgs::Odometry odometry;
  bool               got_odometry = false;
  std::mutex         mutex_odometry;

  double odometry_x;
  double odometry_y;
  double odometry_z;
  double odometry_yaw;
  double odometry_roll;
  double odometry_pitch;

private:
  // tracker's inner states
  int    tracker_loop_rate_;
  double landing_reference_;
  double tracker_dt_;
  bool   is_initialized = false;
  bool   is_active      = false;
  bool   first_iter     = false;

  bool   takeoff_disable_lateral_gains_ = false;
  double takeoff_disable_lateral_gains_height_;
  double takeoff_reset_odometry_height_;
  bool   takeoff_odometry_was_reset    = false;
  bool   takeoff_from_moving_platform_ = false;

private:
  void       mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer;

private:
  void       diagnosticsTimer(const ros::TimerEvent &event);
  ros::Timer diagnostics_timer;
  std::mutex mutex_diagnostics;

private:
  ros::ServiceServer service_takeoff;
  ros::ServiceServer service_land;
  ros::ServiceServer service_eland;

private:
  States_t current_state_vertical    = IDLE_STATE;
  States_t previous_state_vertical   = IDLE_STATE;
  States_t current_state_horizontal  = IDLE_STATE;
  States_t previous_state_horizontal = IDLE_STATE;

  void changeStateHorizontal(States_t new_state);
  void changeStateVertical(States_t new_state);
  void changeState(States_t new_state);

  bool taking_off = false;
  bool landing    = false;
  bool elanding   = false;

  bool in_the_air = false;

private:
  void stopHorizontalMotion(void);
  void stopVerticalMotion(void);
  void accelerateVertical(void);
  void decelerateVertical(void);
  void stopHorizontal(void);
  void stopVertical(void);
  bool callbackTakeoff(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool callbackLand(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool callbackELand(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

private:
  double horizontal_speed_;
  double vertical_speed_;
  double takeoff_speed_;
  double landing_speed_;
  double elanding_speed_;

  double horizontal_acceleration_;
  double vertical_acceleration_;
  double takeoff_acceleration_;
  double landing_acceleration_;
  double elanding_acceleration_;

  double yaw_rate_;
  double yaw_gain_;

  double max_position_difference_;

private:
  // desired goal
  double     goal_x, goal_y, goal_z, goal_yaw;
  double     have_goal = false;
  std::mutex mutex_goal;

  // my current state
  double     state_x, state_y, state_z, state_yaw;
  double     speed_x, speed_y, speed_yaw;
  double     current_heading, current_vertical_direction, current_vertical_speed, current_horizontal_speed;
  double     current_horizontal_acceleration, current_vertical_acceleration;
  std::mutex mutex_state;

  mrs_msgs::PositionCommand position_output;

private:
  mrs_lib::Profiler *profiler;
  bool               profiler_enabled_ = false;

private:
  void           publishDiagnostics(void);
  ros::Publisher publisher_diagnostics;
  double         diagnostics_rate_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void LandoffTracker::initialize(const ros::NodeHandle &parent_nh, mrs_uav_manager::SafetyArea_t const *safety_area) {

  this->safety_area = safety_area;

  ros::NodeHandle nh_(parent_nh, "landoff_tracker");

  ros::Time::waitForValid();

  lateral_odometry_reset_time = ros::Time(0);

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "LandoffTracker");

  param_loader.load_param("enable_profiler", profiler_enabled_);

  param_loader.load_param("horizontal_tracker/horizontal_speed", horizontal_speed_);
  param_loader.load_param("horizontal_tracker/horizontal_acceleration", horizontal_acceleration_);

  param_loader.load_param("vertical_tracker/vertical_speed", vertical_speed_);
  param_loader.load_param("vertical_tracker/vertical_acceleration", vertical_acceleration_);

  param_loader.load_param("vertical_tracker/takeoff_speed", takeoff_speed_);
  param_loader.load_param("vertical_tracker/takeoff_acceleration", takeoff_acceleration_);

  param_loader.load_param("vertical_tracker/landing_speed", landing_speed_);
  param_loader.load_param("vertical_tracker/landing_acceleration", landing_acceleration_);

  param_loader.load_param("vertical_tracker/elanding_speed", elanding_speed_);
  param_loader.load_param("vertical_tracker/elanding_acceleration", elanding_acceleration_);

  param_loader.load_param("yaw_tracker/yaw_rate", yaw_rate_);
  param_loader.load_param("yaw_tracker/yaw_gain", yaw_gain_);

  param_loader.load_param("tracker_loop_rate", tracker_loop_rate_);
  param_loader.load_param("diagnostics_loop_rate", diagnostics_rate_);

  param_loader.load_param("landing_reference", landing_reference_);

  param_loader.load_param("max_position_difference", max_position_difference_);

  param_loader.load_param("takeoff_disable_lateral_gains", takeoff_disable_lateral_gains_);
  param_loader.load_param("takeoff_disable_lateral_gains_height", takeoff_disable_lateral_gains_height_);
  param_loader.load_param("takeoff_reset_odometry_height", takeoff_reset_odometry_height_);
  param_loader.load_param("takeoff_from_moving_platform", takeoff_from_moving_platform_);

  tracker_dt_ = 1.0 / double(tracker_loop_rate_);

  ROS_INFO("[LandoffTracker]: tracker_dt: %f", tracker_dt_);

  state_x   = 0;
  state_y   = 0;
  state_z   = 0;
  state_yaw = 0;

  speed_x   = 0;
  speed_y   = 0;
  speed_yaw = 0;

  current_horizontal_speed = 0;
  current_vertical_speed   = 0;

  current_horizontal_acceleration = 0;
  current_vertical_acceleration   = 0;

  current_vertical_direction = 0;

  current_state_vertical  = LANDED_STATE;
  previous_state_vertical = LANDED_STATE;

  current_state_horizontal  = LANDED_STATE;
  previous_state_horizontal = LANDED_STATE;

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = new mrs_lib::Profiler(nh_, "LandoffTracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                          services                          |
  // --------------------------------------------------------------

  service_takeoff = nh_.advertiseService("takeoff_in", &LandoffTracker::callbackTakeoff, this);
  service_land    = nh_.advertiseService("land_in", &LandoffTracker::callbackLand, this);
  service_eland   = nh_.advertiseService("eland_in", &LandoffTracker::callbackELand, this);

  service_client_reset_lateral_odometry = nh_.serviceClient<std_srvs::Trigger>("reset_lateral_odometry_out");

  // --------------------------------------------------------------
  // |                         publishers                         |
  // --------------------------------------------------------------

  publisher_diagnostics = nh_.advertise<mrs_msgs::LandoffDiagnostics>("diagnostics_out", 1);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer        = nh_.createTimer(ros::Rate(tracker_loop_rate_), &LandoffTracker::mainTimer, this, false, false);
  diagnostics_timer = nh_.createTimer(ros::Rate(diagnostics_rate_), &LandoffTracker::diagnosticsTimer, this);

  // | ----------------------- finish init ---------------------- |

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[LandoffTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[LandoffTracker]: initialized");
}

//}

/* //{ activate() */

bool LandoffTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {

    ROS_ERROR("[LandoffTracker]: can't activate(), odometry not set");
    return false;
  }

  {
    std::scoped_lock lock(mutex_goal, mutex_state, mutex_odometry);

    // the last command is usable
    state_x   = odometry.pose.pose.position.x;
    state_y   = odometry.pose.pose.position.y;
    state_z   = odometry.pose.pose.position.z;
    state_yaw = odometry_yaw;

    speed_x         = odometry.twist.twist.linear.x;
    speed_y         = odometry.twist.twist.linear.y;
    current_heading = atan2(speed_y, speed_x);

    current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

    current_vertical_speed     = fabs(odometry.twist.twist.linear.z);
    current_vertical_direction = odometry.twist.twist.linear.z > 0 ? +1 : -1;

    current_horizontal_acceleration = 0;
    current_vertical_acceleration   = 0;

    goal_yaw = odometry_yaw;

    ROS_INFO("[LandoffTracker]: activated with initial condition x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", state_x, state_y, state_z, state_yaw);
  }

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  {
    std::scoped_lock lock(mutex_state);

    horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2.0;
    stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading) * horizontal_stop_dist;
  }

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state);

    vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2.0;
  }

  // --------------------------------------------------------------
  // |               yaw initial condition prediction             |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal, mutex_state);

    goal_x = state_x + stop_dist_x;
    goal_y = state_y + stop_dist_y;
    goal_z = state_z + vertical_stop_dist;
  }

  landing    = false;
  taking_off = false;
  is_active  = true;

  main_timer.start();

  ROS_INFO("[LandoffTracker]: activated with goal x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", goal_x, goal_y, goal_z, goal_yaw);

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

/* //{ deactivate() */

void LandoffTracker::deactivate(void) {

  // when landing, deactivation means we landned
  if (landing || elanding) {
    in_the_air = false;
  }

  is_active                = false;
  landing                  = false;
  taking_off               = false;
  current_state_vertical   = IDLE_STATE;
  current_state_horizontal = IDLE_STATE;

  main_timer.stop();

  ROS_INFO("[LandoffTracker]: deactivated");
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr LandoffTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  mrs_lib::Routine profiler_routine = profiler->createRoutine("update");

  {
    std::scoped_lock lock(mutex_odometry);

    odometry   = *msg;
    odometry_x = odometry.pose.pose.position.x;
    odometry_y = odometry.pose.pose.position.y;
    odometry_z = odometry.pose.pose.position.z;

    // calculate the euler angles
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(odometry_roll, odometry_pitch, odometry_yaw);

    got_odometry = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  if (lateral_odometry_being_reset && (ros::Time::now() - lateral_odometry_reset_time).toSec() < 0.1) {

    {
      std::scoped_lock lock(mutex_state, mutex_odometry);

      goal_x = state_x = odometry.pose.pose.position.x;
      goal_y = state_y = odometry.pose.pose.position.y;

      speed_x         = odometry.twist.twist.linear.x;
      speed_y         = odometry.twist.twist.linear.y;
      current_heading = atan2(speed_y, speed_x);

      if (takeoff_from_moving_platform_) {
        current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));
      } else {
        current_horizontal_speed = 0;
      }
    }

    ROS_INFO("[LandoffTracker]: waiting for odometry to settle, height: %f", odometry_z);

  } else if (lateral_odometry_being_reset) {

    lateral_odometry_being_reset = false;

    /* replicateOdometry(); */
  }

  {
    std::scoped_lock lock(mutex_state);

    position_output.position.x = state_x;
    position_output.position.y = state_y;
    position_output.position.z = state_z;
    position_output.yaw        = state_yaw;

    position_output.velocity.x = cos(current_heading) * current_horizontal_speed;
    position_output.velocity.y = sin(current_heading) * current_horizontal_speed;
    position_output.velocity.z = current_vertical_direction * current_vertical_speed;
    position_output.yaw_dot    = speed_yaw;

    position_output.acceleration.x = 0;
    position_output.acceleration.y = 0;
    position_output.acceleration.z = current_vertical_direction * current_vertical_acceleration;

    position_output.use_position       = 1;
    position_output.use_euler_attitude = 1;
    position_output.use_velocity       = 1;
    position_output.use_acceleration   = 1;
  }

  if (takeoff_disable_lateral_gains_) {
    {
      std::scoped_lock lock(mutex_odometry);

      if (taking_off && !takeoff_odometry_was_reset) {
        position_output.disable_position_gains = true;
      } else {
        position_output.disable_position_gains = false;
      }
    }
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus LandoffTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = callbacks_enabled;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr LandoffTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[200];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[LandoffTracker]: %s", message);

  } else {

    sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
  }

  res.message = message;
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

void LandoffTracker::switchOdometrySource(const nav_msgs::Odometry::ConstPtr &msg) {

  std::scoped_lock lock(mutex_odometry, mutex_goal, mutex_state);

  double odom_roll, odom_pitch, odom_yaw;
  double msg_roll, msg_pitch, msg_yaw;

  // calculate the euler angles
  tf::Quaternion quaternion_odometry;
  quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
  tf::Matrix3x3 m(quaternion_odometry);
  m.getRPY(odom_roll, odom_pitch, odom_yaw);

  tf::Quaternion quaternion_msg;
  quaternionMsgToTF(msg->pose.pose.orientation, quaternion_msg);
  tf::Matrix3x3 m2(quaternion_msg);
  m2.getRPY(msg_roll, msg_pitch, msg_yaw);

  // | --------- recalculate the goal to new coordinates -------- |

  double dx   = msg->pose.pose.position.x - odometry.pose.pose.position.x;
  double dy   = msg->pose.pose.position.y - odometry.pose.pose.position.y;
  double dz   = msg->pose.pose.position.z - odometry.pose.pose.position.z;
  double dyaw = msg_yaw - odom_yaw;

  goal_x += dx;
  goal_y += dy;
  goal_z += dz;
  goal_yaw += dyaw;
  have_goal = true;

  // | -------------------- update the state -------------------- |

  state_x   = msg->pose.pose.position.x;
  state_y   = msg->pose.pose.position.y;
  state_z   = msg->pose.pose.position.z;
  state_yaw = msg_yaw;

  // | ------- copy the new odometry as the current state ------- |

  // TODO: this current state should be translated aswell
  current_horizontal_speed = sqrt(pow(msg->twist.twist.linear.x, 2) + pow(msg->twist.twist.linear.y, 2));
  current_vertical_speed   = msg->twist.twist.linear.z;
  current_heading          = atan2(goal_y - state_y, goal_x - state_x);

  // | ---------- switch to stop motion, which should  ---------- |

  changeState(STOP_MOTION_STATE);
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::Vec4Response::ConstPtr LandoffTracker::goTo([[maybe_unused]] const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goTo() topic */

bool LandoffTracker::goTo([[maybe_unused]] const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  return false;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::Vec4Response::ConstPtr LandoffTracker::goToRelative([[maybe_unused]] const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goToRelative() topic */

bool LandoffTracker::goToRelative([[maybe_unused]] const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  return false;
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Vec1Response::ConstPtr LandoffTracker::goToAltitude([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ goToAltitude() topic */

bool LandoffTracker::goToAltitude([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
}

//}

/* //{ setYaw() service */

const mrs_msgs::Vec1Response::ConstPtr LandoffTracker::setYaw([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYaw() topic */

bool LandoffTracker::setYaw([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Vec1Response::ConstPtr LandoffTracker::setYawRelative([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYawRelative() topic */

bool LandoffTracker::setYawRelative([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  std_srvs::TriggerResponse res;

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  {
    std::scoped_lock lock(mutex_state, mutex_odometry);

    current_horizontal_speed = sqrt(pow(odometry.twist.twist.linear.x, 2) + pow(odometry.twist.twist.linear.y, 2));
    current_vertical_speed   = odometry.twist.twist.linear.z;
    current_heading          = atan2(odometry.twist.twist.linear.y, odometry.twist.twist.linear.x);
  }

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  {
    std::scoped_lock lock(mutex_state);

    horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
    stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading) * horizontal_stop_dist;
  }

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  {
    std::scoped_lock lock(mutex_state);

    vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2;
  }

  // --------------------------------------------------------------
  // |                        set the goal                        |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_state, mutex_goal);

    goal_x = state_x + stop_dist_x;
    goal_y = state_y + stop_dist_y;
    goal_z = state_z + vertical_stop_dist;
  }

  res.message = "Hover initiated.";
  res.success = true;

  changeState(STOP_MOTION_STATE);

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsResponse::ConstPtr LandoffTracker::setConstraints([[maybe_unused]] const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsResponse::Ptr();
}

//}

// | ----------------- state machine routines ----------------- |

/* //{ changeStateHorizontal() */

void LandoffTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal = current_state_horizontal;
  current_state_horizontal  = new_state;

  switch (current_state_horizontal) {

    case IDLE_STATE:
      break;
    case LANDED_STATE:
      break;
    case HOVER_STATE:
      break;
    case STOP_MOTION_STATE:
      break;
    case ACCELERATING_STATE:
      current_state_horizontal = STOPPING_STATE;
      break;
    case DECELERATING_STATE:
      break;
    case STOPPING_STATE:
      break;
  }

  ROS_INFO("[LandoffTracker]: Switching horizontal state %s -> %s", state_names[previous_state_horizontal], state_names[current_state_horizontal]);
}

//}

/* //{ changeStateVertical() */

void LandoffTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical = current_state_vertical;
  current_state_vertical  = new_state;

  switch (current_state_vertical) {

    case IDLE_STATE:
      break;
    case LANDED_STATE:
      break;
    case HOVER_STATE:
      taking_off = false;
      publishDiagnostics();
      break;
    case STOP_MOTION_STATE:
      break;
    case ACCELERATING_STATE:
      break;
    case DECELERATING_STATE:
      break;
    case STOPPING_STATE:
      break;
  }

  ROS_INFO("[LandoffTracker]: Switching vertical state %s -> %s", state_names[previous_state_vertical], state_names[current_state_vertical]);
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

  current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed < 0) {
    current_horizontal_speed        = 0;
    current_horizontal_acceleration = 0;
  } else {
    current_horizontal_acceleration = -horizontal_acceleration_;
  }
}

//}

/* //{ stopVerticalMotion() */

void LandoffTracker::stopVerticalMotion(void) {

  current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed        = 0;
    current_vertical_acceleration = 0;
  } else {
    current_vertical_acceleration = -vertical_acceleration_;
  }
}

//}

/* //{ accelerateVertical() */

void LandoffTracker::accelerateVertical(void) {

  double used_acceleration;
  double used_speed;

  if (taking_off) {

    used_speed        = takeoff_speed_;
    used_acceleration = takeoff_acceleration_;

  } else if (landing) {

    if (elanding) {

      used_speed        = elanding_speed_;
      used_acceleration = elanding_acceleration_;

    } else {

      used_speed        = landing_speed_;
      used_acceleration = landing_acceleration_;
    }

  } else {
    used_speed        = vertical_speed_;
    used_acceleration = vertical_acceleration_;
  }

  // set the right heading
  double tar_z = goal_z - state_z;

  // set the right vertical direction
  current_vertical_direction = mrs_trackers_commons::sign(tar_z);

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / used_acceleration;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  current_vertical_speed += used_acceleration * tracker_dt_;

  if (current_vertical_speed >= used_speed) {
    current_vertical_speed -= vertical_acceleration_ * tracker_dt_;
    current_vertical_acceleration = 0;
  } else {
    current_vertical_acceleration = used_acceleration;
  }

  // stopping condition to change to decelerate state
  if (fabs(state_z + stop_dist_z - goal_z) < (2 * (used_speed * tracker_dt_))) {
    current_vertical_acceleration = 0;
    changeStateVertical(DECELERATING_STATE);
  }
}

//}

/* //{ decelerateVertical() */

void LandoffTracker::decelerateVertical(void) {

  double used_acceleration;

  if (taking_off) {

    used_acceleration = takeoff_acceleration_;

  } else if (landing) {

    if (elanding) {

      used_acceleration = elanding_acceleration_;

    } else {

      used_acceleration = landing_acceleration_;
    }

  } else {
    used_acceleration = vertical_acceleration_;
  }

  current_vertical_speed -= used_acceleration * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed = 0;
  } else {
    current_vertical_acceleration = -used_acceleration;
  }

  if (current_vertical_speed == 0) {
    current_vertical_acceleration = 0;
    changeStateVertical(STOPPING_STATE);
  }
}

//}

/* //{ stopHorizontal() */

void LandoffTracker::stopHorizontal(void) {

  state_x                         = 0.95 * state_x + 0.05 * goal_x;
  state_y                         = 0.95 * state_y + 0.05 * goal_y;
  current_horizontal_acceleration = 0;
}

//}

/* //{ stopVertical() */

void LandoffTracker::stopVertical(void) {

  state_z                       = 0.95 * state_z + 0.05 * goal_z;
  current_vertical_acceleration = 0;
}

//}

// | --------------------- timer routines --------------------- |

/* //{ mainTimer() */

void LandoffTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler->createRoutine("main", tracker_loop_rate_, 0.002, event);

  {
    std::scoped_lock lock(mutex_odometry, mutex_goal, mutex_state);

    switch (current_state_horizontal) {

      case IDLE_STATE:
        break;

      case LANDED_STATE:
        break;

      case HOVER_STATE:
        break;

      case STOP_MOTION_STATE:

        stopHorizontalMotion();
        break;

      case ACCELERATING_STATE:
        break;

      case DECELERATING_STATE:
        break;

      case STOPPING_STATE:

        stopHorizontal();
        break;
    }

    switch (current_state_vertical) {

      case IDLE_STATE:
        break;

      case LANDED_STATE:
        break;

      case HOVER_STATE:
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

    if (current_state_horizontal == STOP_MOTION_STATE && current_state_vertical == STOP_MOTION_STATE) {
      if (fabs(current_vertical_speed) <= 0.1 && fabs(current_horizontal_speed) <= 0.1) {
        if (have_goal) {
          changeState(ACCELERATING_STATE);
        } else {
          changeState(STOPPING_STATE);
        }
      }
    }

    if (current_state_vertical == STOPPING_STATE && current_state_horizontal == STOPPING_STATE) {
      if (fabs(state_x - goal_x) < 0.1 && fabs(state_y - goal_y) < 0.1 && fabs(state_z - goal_z) < 0.1) {
        state_x = goal_x;
        state_y = goal_y;
        state_z = goal_z;
        changeState(HOVER_STATE);
      }
    }

    if (current_state_horizontal == LANDED_STATE && current_state_vertical == LANDED_STATE) {
      state_x = goal_x = odometry_x;
      state_y = goal_y = odometry_y;
      state_z = goal_z = odometry_z;
    }

    // TODO: fix me
    /* if (taking_off && odometry_z > takeoff_reset_odometry_height_ && !takeoff_odometry_was_reset) { */

    /*   takeoff_odometry_was_reset = true; */
    /*   resetLateralOdometry(); */
    /* } */

    // --------------------------------------------------------------
    // |              motion saturation during takeoff              |
    // --------------------------------------------------------------

    if (taking_off) {

      // calculate the vector
      double err_x      = odometry_x - state_x;
      double err_y      = odometry_y - state_y;
      double err_z      = odometry_z - state_z;
      double error_size = mrs_trackers_commons::size3(err_x, err_y, err_z);

      if (error_size > max_position_difference_) {

        // calculate the potential next step
        double future_state_x = state_x + cos(current_heading) * current_horizontal_speed * tracker_dt_;
        double future_state_y = state_y + sin(current_heading) * current_horizontal_speed * tracker_dt_;
        double future_state_z = state_z + current_vertical_direction * current_vertical_speed * tracker_dt_;

        if (mrs_trackers_commons::dist3(future_state_x, odometry_x, future_state_y, odometry_y, future_state_z, odometry_z) > error_size) {

          current_horizontal_speed = 0;
          current_vertical_speed   = 0;

          ROS_WARN_THROTTLE(
              0.1, "[LandoffTracker]: position difference %.3f > %.3f, saturating the motion. Reference: x=%.2f, y=%.2f, z=%.2f, Odometry: %.2f, %.2f, %.2f",
              error_size, max_position_difference_, future_state_x, future_state_y, future_state_z, odometry_x, odometry_y, odometry_z);
        }
      }
    }

    // update the inner states
    state_x += cos(current_heading) * current_horizontal_speed * tracker_dt_;
    state_y += sin(current_heading) * current_horizontal_speed * tracker_dt_;
    state_z += current_vertical_direction * current_vertical_speed * tracker_dt_;

    // --------------------------------------------------------------
    // |                        yaw tracking                        |
    // --------------------------------------------------------------

    // compute the desired yaw rate
    double current_yaw_rate;
    if (fabs(goal_yaw - state_yaw) > PI)
      current_yaw_rate = -yaw_gain_ * (goal_yaw - state_yaw);
    else
      current_yaw_rate = yaw_gain_ * (goal_yaw - state_yaw);

    if (current_yaw_rate > yaw_rate_) {
      current_yaw_rate = yaw_rate_;
    } else if (current_yaw_rate < -yaw_rate_) {
      current_yaw_rate = -yaw_rate_;
    }

    // flap the resulted state_yaw aroud PI
    state_yaw += current_yaw_rate * tracker_dt_;

    if (state_yaw > PI) {
      state_yaw -= 2 * PI;
    } else if (state_yaw < -PI) {
      state_yaw += 2 * PI;
    }

    if (fabs(state_yaw - goal_yaw) < (2 * (yaw_rate_ * tracker_dt_))) {
      state_yaw = goal_yaw;
    }
  }

  // --------------------------------------------------------------
  // |                      landing setpoint                      |
  // --------------------------------------------------------------

  if (landing) {
    {
      std::scoped_lock lock(mutex_odometry);

      goal_z = odometry_z + landing_reference_;
    }
  }
}

//}

/* //{ diagnosticsTimer() */

void LandoffTracker::diagnosticsTimer(const ros::TimerEvent &event) {

  if (!is_initialized) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler->createRoutine("diagnostics", diagnostics_rate_, 0.002, event);

  publishDiagnostics();
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ callbackTakeoff() */

bool LandoffTracker::callbackTakeoff(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Can't take off, the tracker is not active.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Can't take off, the callbacks are disabled.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (in_the_air) {

    sprintf((char *)&message, "Can't take off, already in the air!");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (req.goal < 0.5 || req.goal > 3.0) {

    sprintf((char *)&message, "Can't take off, the goal should be within [0.5, 3.0] m!");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  {
    std::scoped_lock lock(mutex_goal, mutex_state, mutex_odometry);

    state_x = odometry_x;
    goal_x  = odometry_x;

    state_y = odometry_y;
    goal_y  = odometry_y;

    state_z = odometry_z;
    goal_z  = odometry_z + req.goal;

    state_yaw = odometry_yaw;
    goal_yaw  = odometry_yaw;

    speed_x                = 0;
    speed_y                = 0;
    current_vertical_speed = 0;

    have_goal = true;
  }

  ROS_INFO("[LandoffTracker]: taking off");

  taking_off                 = true;
  landing                    = false;
  elanding                   = false;
  takeoff_odometry_was_reset = false;

  in_the_air = true;

  res.success = true;
  res.message = "taking off";

  changeState(ACCELERATING_STATE);

  publishDiagnostics();

  return true;
}

//}

/* //{ callbackLand() */

bool LandoffTracker::callbackLand([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Can't land, the tracker is not active.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!in_the_air) {

    sprintf((char *)&message, "Can't land, we are already on the ground.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  {
    std::scoped_lock lock(mutex_odometry);

    goal_z = odometry_z + landing_reference_;
  }

  ROS_INFO("[LandoffTracker]: landing");

  landing    = true;
  elanding   = false;
  taking_off = false;
  have_goal  = true;

  res.success = true;
  res.message = "landing";

  changeState(STOP_MOTION_STATE);

  publishDiagnostics();

  return true;
}

//}

/* //{ callbackELand() */

bool LandoffTracker::callbackELand([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Can't eland, the tracker is not active.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    taking_off  = false;
    landing     = false;
    elanding    = false;
    changeState(LANDED_STATE);
    return true;
  }

  {
    std::scoped_lock lock(mutex_odometry);

    goal_z = odometry_z + landing_reference_;
  }

  ROS_WARN("[LandoffTracker]: emergency landing");

  landing    = true;
  elanding   = true;
  taking_off = false;
  have_goal  = true;

  res.success = true;
  res.message = "elanding";

  changeState(STOP_MOTION_STATE);

  publishDiagnostics();

  return true;
}

//}

// | --------------------- other routines --------------------- |

/* resetLateralOdometry() //{ */

void LandoffTracker::resetLateralOdometry(void) {

  std_srvs::Trigger reset_out;
  service_client_reset_lateral_odometry.call(reset_out);

  lateral_odometry_reset_time  = ros::Time::now();
  lateral_odometry_being_reset = true;
}

//}

/* replicateOdometry() //{ */

void LandoffTracker::replicateOdometry(void) {

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  current_horizontal_speed = sqrt(pow(odometry.twist.twist.linear.x, 2) + pow(odometry.twist.twist.linear.y, 2));
  current_heading          = atan2(odometry.twist.twist.linear.y, odometry.twist.twist.linear.x);

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  // --------------------------------------------------------------
  // |                        set the goal                        |
  // --------------------------------------------------------------

  state_x = odometry.pose.pose.position.x;
  state_y = odometry.pose.pose.position.y;

  speed_x = odometry.twist.twist.linear.x;
  speed_y = odometry.twist.twist.linear.y;

  goal_x = state_x + stop_dist_x;
  goal_y = state_y + stop_dist_y;

  ROS_INFO("[LandoffTracker]: replicating odometry and stopping: current: %f %f, goal: %f %f", state_x, state_y, goal_x, goal_y);

  changeStateHorizontal(STOP_MOTION_STATE);
}

//}

/* publishDiagnostics() //{ */

void LandoffTracker::publishDiagnostics(void) {

  if (!is_initialized) {
    return;
  }

  std::scoped_lock lock(mutex_diagnostics);

  mrs_msgs::LandoffDiagnostics diagnostics_msg;

  diagnostics_msg.stamp = ros::Time::now();

  diagnostics_msg.active     = is_active;
  diagnostics_msg.landing    = landing;
  diagnostics_msg.taking_off = taking_off;
  diagnostics_msg.elanding   = elanding;

  try {
    publisher_diagnostics.publish(diagnostics_msg);
  }
  catch (...) {
    ROS_ERROR("Exception caught during publishing topic %s.", publisher_diagnostics.getTopic().c_str());
  }
}

//}

}  // namespace landoff_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::landoff_tracker::LandoffTracker, mrs_uav_manager::Tracker)
