/* includes //{ */

#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/Reference.h>
#include <mrs_uav_manager/Tracker.h>
#include <mrs_msgs/UavState.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>

//}

#define STOP_THR 1e-3

namespace mrs_trackers
{

namespace line_tracker
{

/* //{ class LineTracker */

// state machine
typedef enum
{

  IDLE_STATE,
  STOP_MOTION_STATE,
  HOVER_STATE,
  ACCELERATING_STATE,
  DECELERATING_STATE,
  STOPPING_STATE,

} States_t;

const char *state_names[6] = {

    "IDLING", "STOPPING_MOTION", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

class LineTracker : public mrs_uav_manager::Tracker {
public:
  virtual void initialize(const ros::NodeHandle &parent_nh, mrs_uav_manager::SafetyArea_t const *safety_area,
                          mrs_uav_manager::Transformer_t const *transformer);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &msg);
  virtual const mrs_msgs::TrackerStatus             getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  virtual void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr &msg);

  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goTo(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goToRelative(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   goToAltitude(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYaw(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYawRelative(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::ReferenceConstPtr &msg);

  virtual const mrs_msgs::TrackerConstraintsResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled = true;

  std::string uav_name_;

private:
  mrs_msgs::UavState uav_state;
  bool               got_uav_state = false;
  std::mutex         mutex_uav_state;

  double uav_x;
  double uav_y;
  double uav_z;
  double uav_yaw;
  double uav_roll;
  double uav_pitch;

private:
  // tracker's inner states
  int    tracker_loop_rate_;
  double tracker_dt_;
  bool   is_initialized = false;
  bool   is_active      = false;
  bool   first_iter     = false;

private:
  void       mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer;

private:
  States_t current_state_vertical    = IDLE_STATE;
  States_t previous_state_vertical   = IDLE_STATE;
  States_t current_state_horizontal  = IDLE_STATE;
  States_t previous_state_horizontal = IDLE_STATE;

  void changeStateHorizontal(States_t new_state);
  void changeStateVertical(States_t new_state);
  void changeState(States_t new_state);

private:
  void stopHorizontalMotion(void);
  void stopVerticalMotion(void);
  void accelerateHorizontal(void);
  void accelerateVertical(void);
  void decelerateHorizontal(void);
  void decelerateVertical(void);
  void stopHorizontal(void);
  void stopVertical(void);

private:
  // dynamical constraints
  double     horizontal_speed_;
  double     vertical_speed_;
  double     horizontal_acceleration_;
  double     vertical_acceleration_;
  double     yaw_rate_;
  double     yaw_gain_;
  std::mutex mutex_constraints;

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
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void LineTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] mrs_uav_manager::SafetyArea_t const *safety_area,
                             [[maybe_unused]] mrs_uav_manager::Transformer_t const *transformer) {

  ros::NodeHandle nh_(parent_nh, "line_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------


  mrs_lib::ParamLoader param_loader(nh_, "LineTracker");

  param_loader.load_param("enable_profiler", profiler_enabled_);

  param_loader.load_param("uav_name", uav_name_);

  param_loader.load_param("horizontal_tracker/horizontal_speed", horizontal_speed_);
  param_loader.load_param("horizontal_tracker/horizontal_acceleration", horizontal_acceleration_);

  param_loader.load_param("vertical_tracker/vertical_speed", vertical_speed_);
  param_loader.load_param("vertical_tracker/vertical_acceleration", vertical_acceleration_);

  param_loader.load_param("yaw_tracker/yaw_rate", yaw_rate_);
  param_loader.load_param("yaw_tracker/yaw_gain", yaw_gain_);

  param_loader.load_param("tracker_loop_rate", tracker_loop_rate_);

  tracker_dt_ = 1.0 / double(tracker_loop_rate_);

  ROS_INFO("[LineTracker]: tracker_dt: %f", tracker_dt_);

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

  current_state_vertical  = IDLE_STATE;
  previous_state_vertical = IDLE_STATE;

  current_state_horizontal  = IDLE_STATE;
  previous_state_horizontal = IDLE_STATE;

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = new mrs_lib::Profiler(nh_, "LineTracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer = nh_.createTimer(ros::Rate(tracker_loop_rate_), &LineTracker::mainTimer, this);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[LineTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[LineTracker]: initialized");
}

//}

/* //{ activate() */

bool LineTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_uav_state) {
    ROS_ERROR("[LineTracker]: can't activate(), odometry not set");
    return false;
  }

  {
    std::scoped_lock lock(mutex_goal, mutex_state, mutex_uav_state);

    if (mrs_msgs::PositionCommand::Ptr() != cmd) {

      // the last command is usable
      state_x   = cmd->position.x;
      state_y   = cmd->position.y;
      state_z   = cmd->position.z;
      state_yaw = cmd->yaw;

      speed_x                  = cmd->velocity.x;
      speed_y                  = cmd->velocity.y;
      current_heading          = atan2(speed_y, speed_x);
      current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

      current_vertical_speed     = fabs(cmd->velocity.z);
      current_vertical_direction = cmd->velocity.z > 0 ? +1 : -1;

      current_horizontal_acceleration = 0;
      current_vertical_acceleration   = 0;

      goal_yaw = cmd->yaw;

      ROS_INFO("[LineTracker]: initial condition: x=%2.2f, y=%2.2f, z=%2.2f, yaw=%2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);
      ROS_INFO("[LineTracker]: initial condition: x_dot=%2.2f, y_dot=%2.2f, z_dot=%2.2f", speed_x, speed_y, current_vertical_speed);

    } else {

      state_x   = uav_state.pose.position.x;
      state_y   = uav_state.pose.position.y;
      state_z   = uav_state.pose.position.z;
      state_yaw = uav_yaw;

      speed_x                  = uav_state.velocity.linear.x;
      speed_y                  = uav_state.velocity.linear.y;
      current_heading          = atan2(speed_y, speed_x);
      current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

      current_vertical_speed     = fabs(uav_state.velocity.linear.z);
      current_vertical_direction = uav_state.velocity.linear.z > 0 ? +1 : -1;

      current_horizontal_acceleration = 0;
      current_vertical_acceleration   = 0;

      goal_yaw = uav_yaw;

      ROS_WARN("[LineTracker]: the previous command is not usable for activation, using Odometry instead.");
    }
  }

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------

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
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  {
    std::scoped_lock lock(mutex_goal, mutex_state);

    goal_x = state_x + stop_dist_x;
    goal_y = state_y + stop_dist_y;
    goal_z = state_z + vertical_stop_dist;
    ROS_INFO("[LineTracker]: setting z goal to %f", goal_z);
  }

  is_active = true;

  ROS_INFO("[LineTracker]: activated");

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

/* //{ deactivate() */

void LineTracker::deactivate(void) {

  is_active = false;

  ROS_INFO("[LineTracker]: deactivated");
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr LineTracker::update(const mrs_msgs::UavState::ConstPtr &msg) {

  mrs_lib::Routine profiler_routine = profiler->createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state);

    uav_state = *msg;
    uav_x     = uav_state.pose.position.x;
    uav_y     = uav_state.pose.position.y;
    uav_z     = uav_state.pose.position.z;

    // calculate the euler angles
    tf::Quaternion uav_attitude;
    quaternionMsgToTF(uav_state.pose.orientation, uav_attitude);
    tf::Matrix3x3 m(uav_attitude);
    m.getRPY(uav_roll, uav_pitch, uav_yaw);

    got_uav_state = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = uav_state.header.frame_id;

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

    position_output.use_position_vertical   = 1;
    position_output.use_position_horizontal = 1;
    position_output.use_yaw                 = 1;
    position_output.use_yaw_dot             = 1;
    position_output.use_velocity_vertical   = 1;
    position_output.use_velocity_horizontal = 1;
    position_output.use_acceleration        = 1;
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus LineTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = callbacks_enabled;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr LineTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[100];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[LineTracker]: %s", message);

  } else {

    sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
  }

  res.message = message;
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

void LineTracker::switchOdometrySource(const mrs_msgs::UavState::ConstPtr &msg) {

  std::scoped_lock lock(mutex_uav_state, mutex_goal, mutex_state);

  double odom_roll, odom_pitch, odom_yaw;
  double msg_roll, msg_pitch, msg_yaw;

  // calculate the euler angles
  tf::Quaternion quaternion_odometry;
  quaternionMsgToTF(uav_state.pose.orientation, quaternion_odometry);
  tf::Matrix3x3 m(quaternion_odometry);
  m.getRPY(odom_roll, odom_pitch, odom_yaw);

  tf::Quaternion quaternion_msg;
  quaternionMsgToTF(msg->pose.orientation, quaternion_msg);
  tf::Matrix3x3 m2(quaternion_msg);
  m2.getRPY(msg_roll, msg_pitch, msg_yaw);

  // | --------- recalculate the goal to new coordinates -------- |
  double dx, dy, dz;

  dx          = msg->pose.position.x - uav_state.pose.position.x;
  dy          = msg->pose.position.y - uav_state.pose.position.y;
  dz          = msg->pose.position.z - uav_state.pose.position.z;
  double dyaw = msg_yaw - odom_yaw;

  goal_x += dx;
  goal_y += dy;
  goal_z += dz;
  goal_yaw += dyaw;
  have_goal = true;

  // | -------------------- update the state -------------------- |

  state_x   = msg->pose.position.x;
  state_y   = msg->pose.position.y;
  state_z   = msg->pose.position.z;
  state_yaw = msg_yaw;

  // | ------- copy the new odometry as the current state ------- |

  current_horizontal_speed = sqrt(pow(msg->velocity.linear.x, 2) + pow(msg->velocity.linear.y, 2));
  current_vertical_speed   = msg->velocity.linear.z;
  current_heading          = atan2(goal_y - state_y, goal_x - state_x);

  // | ---------- switch to stop motion, which should  ---------- |

  changeState(STOP_MOTION_STATE);
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr LineTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  std_srvs::TriggerResponse res;

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  {
    std::scoped_lock lock(mutex_state, mutex_uav_state);

    current_horizontal_speed = sqrt(pow(uav_state.velocity.linear.x, 2) + pow(uav_state.velocity.linear.y, 2));
    current_vertical_speed   = uav_state.velocity.linear.z;
    current_heading          = atan2(uav_state.velocity.linear.y, uav_state.velocity.linear.x);
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
    std::scoped_lock lock(mutex_goal, mutex_state);

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

const mrs_msgs::TrackerConstraintsResponse::ConstPtr LineTracker::setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  mrs_msgs::TrackerConstraintsResponse res;

  // this is the place to copy the constraints
  {
    std::scoped_lock lock(mutex_constraints);

    horizontal_speed_        = cmd->horizontal_speed;
    horizontal_acceleration_ = cmd->horizontal_acceleration;

    vertical_speed_        = cmd->vertical_ascending_speed;
    vertical_acceleration_ = cmd->vertical_ascending_acceleration;

    yaw_rate_ = cmd->yaw_speed;
  }

  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::TrackerConstraintsResponse::ConstPtr(new mrs_msgs::TrackerConstraintsResponse(res));
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr LineTracker::goTo(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  mrs_msgs::ReferenceSrvResponse res;

  {
    std::scoped_lock lock(mutex_goal);

    goal_x   = cmd->reference.position.x;
    goal_y   = cmd->reference.position.y;
    goal_z   = cmd->reference.position.z;
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(cmd->reference.yaw);
  }

  ROS_INFO("[LineTracker]: received new setpoint %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ goTo() topic */

bool LineTracker::goTo(const mrs_msgs::ReferenceConstPtr &msg) {

  {
    std::scoped_lock lock(mutex_goal);

    goal_x   = msg->position.x;
    goal_y   = msg->position.y;
    goal_z   = msg->position.z;
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(msg->yaw);
  }

  ROS_INFO("[LineTracker]: received new setpoint %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr LineTracker::goToRelative(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  mrs_msgs::ReferenceSrvResponse res;

  {
    std::scoped_lock lock(mutex_goal, mutex_state);

    goal_x   = state_x + cmd->reference.position.x;
    goal_y   = state_y + cmd->reference.position.y;
    goal_z   = state_z + cmd->reference.position.z;
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + cmd->reference.yaw);
  }

  ROS_INFO("[LineTracker]: received new relative setpoint, flying to %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Float64SrvResponse::ConstPtr LineTracker::goToAltitude(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  {
    std::scoped_lock lock(mutex_goal, mutex_state);

    goal_x   = state_x;
    goal_y   = state_y;
    goal_z   = cmd->value;
    goal_yaw = state_yaw;

    have_goal = true;
  }

  ROS_INFO("[LineTracker]: received new altituded setpoint %3.2f", goal_z);

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

/* //{ setYaw() service */

const mrs_msgs::Float64SrvResponse::ConstPtr LineTracker::setYaw(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  {
    std::scoped_lock lock(mutex_goal);

    goal_yaw = mrs_trackers_commons::validateYawSetpoint(cmd->value);
  }

  ROS_INFO("[LineTracker]: setting yaw %3.2f", goal_yaw);

  res.success = true;
  res.message = "yaw set";

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Float64SrvResponse::ConstPtr LineTracker::setYawRelative(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  {
    std::scoped_lock lock(mutex_state, mutex_goal);

    goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + cmd->value);
  }

  ROS_INFO("[LineTracker]: setting relative yaw by %3.2f", goal_yaw);

  res.success = true;
  res.message = "yaw set";

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

// | ----------------- state machine routines ----------------- |

/* //{ changeStateHorizontal() */

void LineTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal = current_state_horizontal;
  current_state_horizontal  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching horizontal state %s -> %s", state_names[previous_state_horizontal], state_names[current_state_horizontal]);
}

//}

/* //{ changeStateVertical() */

void LineTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical = current_state_vertical;
  current_state_vertical  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching vertical state %s -> %s", state_names[previous_state_vertical], state_names[current_state_vertical]);
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

void LineTracker::stopVerticalMotion(void) {

  current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed        = 0;
    current_vertical_acceleration = 0;
  } else {
    current_vertical_acceleration = -vertical_acceleration_;
  }
}

//}

/* //{ accelerateHorizontal() */

void LineTracker::accelerateHorizontal(void) {

  current_heading = atan2(goal_y - state_y, goal_x - state_x);

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  current_horizontal_speed += horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed >= horizontal_speed_) {
    current_horizontal_speed        = horizontal_speed_;
    current_horizontal_acceleration = 0;
  } else {
    current_horizontal_acceleration = horizontal_acceleration_;
  }

  if (sqrt(pow(state_x + stop_dist_x - goal_x, 2) + pow(state_y + stop_dist_y - goal_y, 2)) < (2 * (horizontal_speed_ * tracker_dt_))) {
    current_horizontal_acceleration = 0;
    changeStateHorizontal(DECELERATING_STATE);
  }
}

//}

/* //{ accelerateVertical() */

void LineTracker::accelerateVertical(void) {

  // set the right heading
  double tar_z = goal_z - state_z;

  // set the right vertical direction
  current_vertical_direction = mrs_trackers_commons::sign(tar_z);

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  current_vertical_speed += vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed >= vertical_speed_) {
    current_vertical_speed        = vertical_speed_;
    current_vertical_acceleration = 0;
  } else {
    current_vertical_acceleration = vertical_acceleration_;
  }

  if (fabs(state_z + stop_dist_z - goal_z) < (2 * (vertical_speed_ * tracker_dt_))) {
    current_vertical_acceleration = 0;
    changeStateVertical(DECELERATING_STATE);
  }
}

//}

/* //{ decelerateHorizontal() */

void LineTracker::decelerateHorizontal(void) {

  current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed < 0) {
    current_horizontal_speed = 0;
  } else {
    current_horizontal_acceleration = -horizontal_acceleration_;
  }

  if (current_horizontal_speed == 0) {
    current_horizontal_acceleration = 0;
    changeStateHorizontal(STOPPING_STATE);
  }
}

//}

/* //{ decelerateVertical() */

void LineTracker::decelerateVertical(void) {

  current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed = 0;
  } else {
    current_vertical_acceleration = -vertical_acceleration_;
  }

  if (current_vertical_speed == 0) {
    current_vertical_acceleration = 0;
    changeStateVertical(STOPPING_STATE);
  }
}

//}

/* //{ stopHorizontal() */

void LineTracker::stopHorizontal(void) {

  state_x                         = 0.95 * state_x + 0.05 * goal_x;
  state_y                         = 0.95 * state_y + 0.05 * goal_y;
  current_horizontal_acceleration = 0;
}

//}

/* //{ stopVertical() */

void LineTracker::stopVertical(void) {

  state_z                       = 0.95 * state_z + 0.05 * goal_z;
  current_vertical_acceleration = 0;
}

//}

// | ------------------------- timers ------------------------- |

/* //{ mainTimer() */

void LineTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler->createRoutine("main", tracker_loop_rate_, 0.002, event);

  {
    std::scoped_lock lock(mutex_constraints, mutex_uav_state, mutex_goal, mutex_state);

    switch (current_state_horizontal) {

      case IDLE_STATE:

        break;

      case HOVER_STATE:

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

    switch (current_state_vertical) {

      case IDLE_STATE:

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

      if (current_vertical_speed == 0 && current_horizontal_speed == 0) {
        if (have_goal) {
          changeState(ACCELERATING_STATE);
        } else {
          changeState(STOPPING_STATE);
        }
      }
    }

    if (current_state_horizontal == STOPPING_STATE && current_state_vertical == STOPPING_STATE) {

      if (fabs(state_x - goal_x) < 1e-3 && fabs(state_y - goal_y) < 1e-3 && fabs(state_z - goal_z) < 1e-3) {

        state_x = goal_x;
        state_y = goal_y;
        state_z = goal_z;

        changeState(HOVER_STATE);
      }
    }

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
}

//}

}  // namespace line_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::line_tracker::LineTracker, mrs_uav_manager::Tracker)
