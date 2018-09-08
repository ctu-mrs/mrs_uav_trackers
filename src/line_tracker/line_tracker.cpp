#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_mav_manager/Tracker.h>
#include <nav_msgs/Odometry.h>
#include <mrs_lib/Profiler.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>

#define STOP_THR 1e-3

namespace mrs_trackers
{

//{ class LandoffTracker

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

class LineTracker : public mrs_mav_manager::Tracker {
public:
  LineTracker(void);

  virtual void initialize(const ros::NodeHandle &parent_nh, mrs_mav_manager::SafetyArea const *safety_area);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  virtual const mrs_msgs::TrackerStatus::Ptr        getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);

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

private:
  bool callbacks_enabled = true;

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
  double tracker_dt_;
  bool   is_initialized;
  bool   is_active;
  bool   first_iter;

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
  double horizontal_speed_;
  double vertical_speed_;
  double horizontal_acceleration_;
  double vertical_acceleration_;
  double yaw_rate_;
  double yaw_gain_;

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
  mrs_lib::Routine * routine_main_timer;
  mrs_lib::Routine * routine_update;
};

LineTracker::LineTracker(void) : is_initialized(false), is_active(false) {
}

//}

// | -------------- tracker's interface routines -------------- |

//{ initialize()

void LineTracker::initialize(const ros::NodeHandle &parent_nh, mrs_mav_manager::SafetyArea const *safety_area) {

  ros::NodeHandle nh_(parent_nh, "line_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------


  mrs_lib::ParamLoader param_loader(nh_, "LineTracker");

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

  profiler           = new mrs_lib::Profiler(nh_, "LineTracker");
  routine_main_timer = profiler->registerRoutine("main", tracker_loop_rate_, 0.002);
  routine_update     = profiler->registerRoutine("update");

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer = nh_.createTimer(ros::Rate(tracker_loop_rate_), &LineTracker::mainTimer, this);

  if (!param_loader.loaded_successfully()) {
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[LineTracker]: initialized");
}

//}

//{ activate()

bool LineTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {
    ROS_ERROR("[LineTracker]: can't activate(), odometry not set");
    return false;
  }

  mutex_odometry.lock();
  mutex_state.lock();
  mutex_goal.lock();
  {
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

      goal_yaw = cmd->yaw;

      ROS_INFO("[LineTracker]: initial condition: x=%2.2f, y=%2.2f, z=%2.2f, yaw=%2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);
      ROS_INFO("[LineTracker]: initial condition: x_dot=%2.2f, y_dot=%2.2f, z_dot=%2.2f", speed_x, speed_y, current_vertical_speed);

    } else {

      state_x   = odometry.pose.pose.position.x;
      state_y   = odometry.pose.pose.position.y;
      state_z   = odometry.pose.pose.position.z;
      state_yaw = odometry_yaw;

      speed_x                  = odometry.twist.twist.linear.x;
      speed_y                  = odometry.twist.twist.linear.y;
      current_heading          = atan2(speed_y, speed_x);
      current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

      current_vertical_speed     = fabs(odometry.twist.twist.linear.z);
      current_vertical_direction = odometry.twist.twist.linear.z > 0 ? +1 : -1;

      goal_yaw = odometry_yaw;

      ROS_WARN("[LineTracker]: the previous command is not usable for activation, using Odometry instead.");
    }
  }
  mutex_goal.unlock();
  mutex_state.unlock();
  mutex_odometry.unlock();

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  mutex_state.lock();
  {
    horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
    stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading) * horizontal_stop_dist;
  }
  mutex_state.unlock();

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  mutex_state.lock();
  {
    vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2;
  }
  mutex_state.unlock();

  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  mutex_state.lock();
  mutex_goal.lock();
  {
    goal_x = state_x + stop_dist_x;
    goal_y = state_y + stop_dist_y;
    goal_z = state_z + vertical_stop_dist;
    ROS_INFO("[LineTracker]: setting z goal to %f", goal_z);
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  is_active = true;

  ROS_INFO("[LineTracker]: activated");

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

//{ deactivate()

void LineTracker::deactivate(void) {

  is_active = false;

  ROS_INFO("[LineTracker]: deactivated");
}

//}

//{ update()

const mrs_msgs::PositionCommand::ConstPtr LineTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  routine_update->start();

  mutex_odometry.lock();
  {
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
  mutex_odometry.unlock();

  if (!is_active) {

    routine_update->end();
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  mutex_state.lock();
  {
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
  }
  mutex_state.unlock();

  routine_update->end();
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

//}

//{ getStatus()

const mrs_msgs::TrackerStatus::Ptr LineTracker::getStatus() {

  if (is_initialized) {

    mrs_msgs::TrackerStatus::Ptr tracker_status(new mrs_msgs::TrackerStatus);

    if (is_active) {
      tracker_status->active = mrs_msgs::TrackerStatus::ACTIVE;
    } else {
      tracker_status->active = mrs_msgs::TrackerStatus::NONACTIVE;
    }

    return tracker_status;
  } else {

    return mrs_msgs::TrackerStatus::Ptr();
  }
}

//}

//{ enableCallbacks()

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

// | -------------- setpoint topics and services -------------- |

//{ goTo() service

const mrs_msgs::Vec4Response::ConstPtr LineTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  mutex_goal.lock();
  {
    goal_x   = cmd->goal[0];
    goal_y   = cmd->goal[1];
    goal_z   = cmd->goal[2];
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(cmd->goal[3]);
  }
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: received new setpoint %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

//{ goTo() topic

bool LineTracker::goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  mutex_goal.lock();
  {
    goal_x   = msg->position.x;
    goal_y   = msg->position.y;
    goal_z   = msg->position.z;
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(msg->position.yaw);
  }
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: received new setpoint %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

//{ goToRelative() service

const mrs_msgs::Vec4Response::ConstPtr LineTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  mutex_state.lock();
  mutex_goal.lock();
  {
    mutex_odometry.lock();
    {
      goal_x   = state_x + cmd->goal[0];
      goal_y   = state_y + cmd->goal[1];
      goal_z   = state_z + cmd->goal[2];
      goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + cmd->goal[3]);
    }
    mutex_odometry.unlock();
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  ROS_INFO("[LineTracker]: received new relative setpoint, flying to %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

//{ goToRelative() topic

bool LineTracker::goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  mutex_state.lock();
  mutex_goal.lock();
  {
    goal_x   = state_x + msg->position.x;
    goal_y   = state_y + msg->position.y;
    goal_z   = state_z + msg->position.z;
    goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + msg->position.yaw);
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  ROS_INFO("[LineTracker]: received new relative setpoint, flying to %3.2f, %3.2f, %3.2f, %1.3f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

//{ goToAltitude() service

const mrs_msgs::Vec1Response::ConstPtr LineTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  mutex_state.lock();
  mutex_goal.lock();
  {
    goal_x   = state_x;
    goal_y   = state_y;
    goal_z   = cmd->goal;
    goal_yaw = state_yaw;

    have_goal = true;
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  ROS_INFO("[LineTracker]: received new altituded setpoint %3.2f", goal_z);

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ goToAltitude() topic

bool LineTracker::goToAltitude(const std_msgs::Float64ConstPtr &msg) {

  mutex_state.lock();
  mutex_goal.lock();
  {
    goal_x   = state_x;
    goal_y   = state_y;
    goal_z   = msg->data;
    goal_yaw = state_yaw;

    have_goal = true;
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  ROS_INFO("[LineTracker]: received new altituded setpoint %3.2f", goal_z);

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

//{ setYaw() service

const mrs_msgs::Vec1Response::ConstPtr LineTracker::setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  mutex_goal.lock();
  { goal_yaw = mrs_trackers_commons::validateYawSetpoint(cmd->goal); }
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: setting yaw %3.2f", goal_yaw);

  res.success = true;
  res.message = "yaw set";

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ setYaw() topic

bool LineTracker::setYaw(const std_msgs::Float64ConstPtr &msg) {

  mutex_goal.lock();
  { goal_yaw = mrs_trackers_commons::validateYawSetpoint(msg->data); }
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: setting absolute yaw to %3.2f", goal_yaw);

  return true;
}

//}

//{ setYawRelative() service

const mrs_msgs::Vec1Response::ConstPtr LineTracker::setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  mutex_goal.lock();
  mutex_state.lock();
  { goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + cmd->goal); }
  mutex_state.unlock();
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: setting relative yaw by %3.2f", goal_yaw);

  res.success = true;
  res.message = "yaw set";

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ setYawRelative() topic

bool LineTracker::setYawRelative(const std_msgs::Float64ConstPtr &msg) {

  mutex_goal.lock();
  mutex_state.lock();
  { goal_yaw = mrs_trackers_commons::validateYawSetpoint(state_yaw + msg->data); }
  mutex_state.unlock();
  mutex_goal.unlock();

  ROS_INFO("[LineTracker]: received relative yaw by %3.2f", goal_yaw);

  return true;
}

//}

//{ hover()

const std_srvs::TriggerResponse::ConstPtr LineTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {

  std_srvs::TriggerResponse res;

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------
  mutex_odometry.lock();
  mutex_state.lock();
  {
    current_horizontal_speed = sqrt(pow(odometry.twist.twist.linear.x, 2) + pow(odometry.twist.twist.linear.y, 2));
    current_vertical_speed   = odometry.twist.twist.linear.z;
  }
  mutex_state.unlock();
  mutex_odometry.unlock();

  double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

  mutex_state.lock();
  {
    horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
    horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
    stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
    stop_dist_y          = sin(current_heading) * horizontal_stop_dist;
  }
  mutex_state.unlock();

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop, vertical_stop_dist;

  mutex_state.lock();
  {
    vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
    vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2;
  }
  mutex_state.unlock();

  // --------------------------------------------------------------
  // |                        set the goal                        |
  // --------------------------------------------------------------

  mutex_state.lock();
  mutex_goal.lock();
  {
    goal_x = state_x + stop_dist_x;
    goal_y = state_y + stop_dist_y;
    goal_z = state_z + vertical_stop_dist;
  }
  mutex_goal.unlock();
  mutex_state.unlock();

  res.message = "Hover initiated.";
  res.success = true;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

// | ----------------- state machine routines ----------------- |

//{ changeStateHorizontal()

void LineTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal = current_state_horizontal;
  current_state_horizontal  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching horizontal state %s -> %s", state_names[previous_state_horizontal], state_names[current_state_horizontal]);
}

//}

//{ changeStateVertical()

void LineTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical = current_state_vertical;
  current_state_vertical  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LineTracker]: Switching vertical state %s -> %s", state_names[previous_state_vertical], state_names[current_state_vertical]);
}

//}

//{ changeState()

void LineTracker::changeState(States_t new_state) {

  changeStateVertical(new_state);
  changeStateHorizontal(new_state);
}

//}

// | --------------------- motion routines -------------------- |

//{ stopHorizontalMotion()

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

//{ stopVerticalMotion()

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

//{ accelerateHorizontal()

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

//{ accelerateVertical()

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

//{ decelerateHorizontal()

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

//{ decelerateVertical()

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

//{ stopHorizontal()

void LineTracker::stopHorizontal(void) {

  state_x                         = 0.95 * state_x + 0.05 * goal_x;
  state_y                         = 0.95 * state_y + 0.05 * goal_y;
  current_horizontal_acceleration = 0;
}

//}

//{ stopVertical()

void LineTracker::stopVertical(void) {

  state_z                       = 0.95 * state_z + 0.05 * goal_z;
  current_vertical_acceleration = 0;
}

//}

// | ------------------------- timers ------------------------- |

//{ mainTimer()

void LineTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  routine_main_timer->start(event);

  mutex_state.lock();
  mutex_goal.lock();
  mutex_odometry.lock();
  {
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
  mutex_odometry.unlock();
  mutex_goal.unlock();
  mutex_state.unlock();

  routine_main_timer->end();
}

//}
}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::LineTracker, mrs_mav_manager::Tracker)
