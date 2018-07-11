#include <geometry_msgs/PoseStamped.h>
#include <math.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_mav_manager/Tracker.h>
#include <nav_msgs/Odometry.h>
#include <ros/package.h>
#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <tf/transform_datatypes.h>

#include <mrs_msgs/PositionCommand.h>
#include <mrs_msgs/TrackerStatus.h>
#include <mrs_msgs/Vec4.h>

#include <thread>

#define PI 3.141592653

namespace mrs_trackers
{

// state machine
typedef enum {

  IDLE_STATE,
  STOP_MOTION_STATE,
  HOVER_STATE,
  ACCELERATING_STATE,
  DECELERATING_STATE,
  STOPPING_STATE,

} States_t;

const char *state_names[6] = {

    "IDLING", "STOP_MOTION_STATE", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

class LinearTracker : public mrs_mav_manager::Tracker {
public:
  LinearTracker(void);

  void Initialize(const ros::NodeHandle &parent_nh);
  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  void                                      Deactivate(void);
  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const mrs_msgs::TrackerStatus::Ptr status();

private:
  nav_msgs::Odometry odometry;
  bool               got_odometry = false;

  double odometry_x;
  double odometry_y;
  double odometry_z;
  double odometry_yaw;
  double odometry_roll;
  double odometry_pitch;

private:
  // tracker's inner states
  int tracker_loop_rate_;
  double tracker_dt_;
  bool   is_initialized;
  bool   is_active;
  bool   first_iter;

private:
  void        mainThread(void);
  std::thread main_thread;

private:
  States_t current_state;
  States_t previous_state;
  void changeState(States_t new_state);

private:
  void stopMotion(void);
  void accelerate(void);
  void decelerate(void);
  void stop(void);

private:
  // dynamical constraints
  double horizontal_speed_;
  double vertical_speed_;
  double horizontal_acceleration_;
  double vertical_acceleration_;
  double yaw_rate_;

private:
  // desired goal
  double goal_x, goal_y, goal_z, goal_yaw;
  double have_goal = false;

  // my current state
  double state_x, state_y, state_z, state_yaw;
  double speed_x, speed_y, speed_yaw;
  double current_heading, current_vertical_direction, current_vertical_speed, current_horizontal_speed;

  mrs_msgs::PositionCommand position_output;

private:
  ros::Subscriber    subscriberDesiredPosition;
  ros::ServiceServer service_goto;
  ros::ServiceServer service_goto_relative;

  void callbackDesiredPosition(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  bool callbackGoto(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool callbackGotoRelative(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
};

void LinearTracker::changeState(States_t new_state) {

  previous_state = current_state;
  current_state  = new_state;

  // just for ROS_INFO
  ROS_WARN("[LinearTracker]: Switching states %s -> %s", state_names[previous_state], state_names[current_state]);

  switch (new_state) {

    case IDLE_STATE:
      break;

    case HOVER_STATE:
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
}

LinearTracker::LinearTracker(void) : is_initialized(false), is_active(false) {
}

void LinearTracker::callbackDesiredPosition(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {

  goal_x   = msg->position.x;
  goal_y   = msg->position.y;
  goal_z   = msg->position.z;
  goal_yaw = msg->position.yaw;

  have_goal = true;

  ROS_INFO("[LinearTracker]: received new setpoint %f, %f, %f, %f", goal_x, goal_y, goal_z, goal_yaw);

  changeState(STOP_MOTION_STATE);
}

bool LinearTracker::callbackGoto(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  goal_x   = req.goal[0];
  goal_y   = req.goal[1];
  goal_z   = req.goal[2];
  goal_yaw = req.goal[3];

  ROS_INFO("[LinearTracker]: received new setpoint %f, %f, %f, %f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return true;
}

bool LinearTracker::callbackGotoRelative(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  goal_x   = odometry_x + req.goal[0];
  goal_y   = odometry_y + req.goal[1];
  goal_z   = odometry_z + req.goal[2];
  goal_yaw = odometry_yaw + req.goal[3];

  ROS_INFO("[LinearTracker]: received new relative setpoint, flying to %f, %f, %f, %f", goal_x, goal_y, goal_z, goal_yaw);

  have_goal = true;

  res.success = true;
  res.message = "setpoint set";

  changeState(STOP_MOTION_STATE);

  return true;
}

void LinearTracker::Initialize(const ros::NodeHandle &parent_nh) {

  ros::NodeHandle priv_nh(parent_nh, "linear_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  subscriberDesiredPosition = priv_nh.subscribe("desired_position", 1, &LinearTracker::callbackDesiredPosition, this, ros::TransportHints().tcpNoDelay());

  // --------------------------------------------------------------
  // |                          services                          |
  // --------------------------------------------------------------

  service_goto          = priv_nh.advertiseService("goTo", &LinearTracker::callbackGoto, this);
  service_goto_relative = priv_nh.advertiseService("goToRelative", &LinearTracker::callbackGotoRelative, this);

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  priv_nh.param("horizontal_speed", horizontal_speed_, -1.0);
  priv_nh.param("vertical_speed", vertical_speed_, -1.0);
  priv_nh.param("horizontal_acceleration", horizontal_acceleration_, -1.0);
  priv_nh.param("vertical_acceleration", vertical_acceleration_, -1.0);
  priv_nh.param("yaw_rate", yaw_rate_, -1.0);
  priv_nh.param("tracker_loop_rate", tracker_loop_rate_, -1);

  if (horizontal_speed_ < 0) {
    ROS_ERROR("[LinearTracker]: horizontal_speed was not specified!");
    ros::shutdown();
  }

  if (vertical_speed_ < 0) {
    ROS_ERROR("[LinearTracker]: vertical_speed was not specified!");
    ros::shutdown();
  }

  if (horizontal_acceleration_ < 0) {
    ROS_ERROR("[LinearTracker]: horizontal_acceleration was not specified!");
    ros::shutdown();
  }

  if (vertical_acceleration_ < 0) {
    ROS_ERROR("[LinearTracker]: vertical_acceleration was not specified!");
    ros::shutdown();
  }

  if (yaw_rate_ < 0) {
    ROS_ERROR("[LinearTracker]: yaw_rate was not specified!");
    ros::shutdown();
  }

  if (tracker_loop_rate_ < 0) {
    ROS_ERROR("[LinearTracker]: tracker_loop_rate was not specified!");
    ros::shutdown();
  }

  tracker_dt_ = 1.0 / double(tracker_loop_rate_);

  ROS_INFO("[LinearTracker]: tracker_dt: %f", tracker_dt_);

  state_x   = 0;
  state_y   = 0;
  state_z   = 0;
  state_yaw = 0;

  speed_x   = 0;
  speed_y   = 0;
  speed_yaw = 0;

  current_horizontal_speed = 0;
  current_vertical_speed   = 0;

  is_initialized = true;

  current_state  = IDLE_STATE;
  previous_state = IDLE_STATE;

  main_thread = std::thread(&LinearTracker::mainThread, this);

  ROS_INFO("[LinearTracker]: initialized");
}

void LinearTracker::stopMotion(void) {

  // slow down horizontally
  if (current_horizontal_speed > 0) {

    current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed = 0;
    }
  }

  // slow down vertically
  if (current_vertical_speed > 0) {

    current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

    if (current_vertical_speed < 0) {
      current_vertical_speed = 0;
    }
  }

  // if we are stationary, switch to hover
  if (current_horizontal_speed == 0 && current_vertical_speed == 0) {

    if (have_goal) {
      changeState(ACCELERATING_STATE);
    } else {
      changeState(HOVER_STATE);
    }
  }
}

void LinearTracker::accelerate(void) {

  // set the right heading
  double tar_x          = goal_x - state_x;
  double tar_y          = goal_y - state_y;
  double tar_z          = goal_z - state_z;
  double target_heading = atan2(tar_y, tar_x);

  current_heading = target_heading;

  // set the right vertical direction
  current_vertical_direction = (tar_z > 0) ? 1.0 : -1.0;

  current_horizontal_speed += horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed >= horizontal_speed_) {
    current_horizontal_speed = horizontal_speed_;
  }

  current_vertical_speed += vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed >= vertical_speed_) {
    current_vertical_speed = vertical_speed_;
  }

  // decelerationg condition
  // calculate the time to stop and the distance it will take to stop [horizontal]
  double horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  double horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  double stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  double stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  if (sqrt(pow(state_x + stop_dist_x - goal_x, 2) + pow(state_y + stop_dist_y - goal_y, 2) + pow(state_z + stop_dist_z - goal_z, 3) < 0.1)) {
    changeState(DECELERATING_STATE);
  }
}

void LinearTracker::decelerate(void) {

  current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed < 0) {
    current_horizontal_speed = 0;
  }

  current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed = 0;
  }

  if (current_vertical_speed == 0 && current_horizontal_speed == 0) {
    changeState(STOPPING_STATE);
  }
}

void LinearTracker::stop(void) {

  state_x = 0.99 * state_x + 0.01 * goal_x;
  state_y = 0.99 * state_y + 0.01 * goal_y;
  state_z = 0.99 * state_z + 0.01 * goal_z;

  if (fabs(state_x - goal_x) < 1e-5 && fabs(state_y - goal_y) < 1e-5 && fabs(state_z - goal_z) < 1e-5) {
    state_x = goal_x;
    state_y = goal_y;
    state_z = goal_z;

    changeState(HOVER_STATE);
  }
}

void LinearTracker::mainThread(void) {

  ROS_INFO("[LinearTracker]: mainThread has started");
  ros::Rate r(tracker_loop_rate_);

  while (ros::ok()) {

    switch (current_state) {

      case IDLE_STATE:

        break;

      case HOVER_STATE:

        break;

      case STOP_MOTION_STATE:

        stopMotion();

        break;

      case ACCELERATING_STATE:

        accelerate();

        break;

      case DECELERATING_STATE:

        decelerate();

        break;

      case STOPPING_STATE:

        stop();

        break;
    }

    state_x += cos(current_heading) * current_horizontal_speed * tracker_dt_;
    state_y += sin(current_heading) * current_horizontal_speed * tracker_dt_;
    state_z += current_vertical_direction * current_vertical_speed * tracker_dt_;

    ROS_INFO_THROTTLE(0.1, "[LinearTracker]: x: %f, y: %f, z: %f", state_x, state_y, state_z);

    r.sleep();
  }
}

bool LinearTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {
    ROS_WARN("[LinearTracker]: can't activate(), odometry not set");
    return false;
  }

  if (mrs_msgs::PositionCommand::Ptr() != cmd) {

    // the last command is usable
    state_x   = odometry.pose.pose.position.x;
    state_y   = odometry.pose.pose.position.y;
    state_z   = odometry.pose.pose.position.z;
    state_yaw = cmd->yaw;

    speed_x         = cmd->velocity.x;
    speed_y         = cmd->velocity.y;
    current_heading = atan2(speed_y, speed_x);

    current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));
    current_vertical_speed   = cmd->velocity.z;

    ROS_INFO("[LinearTracker]: activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);

  } else {

    ROS_WARN("[LinearTracker]: activated, the previous command is not usable for activation, using Odometry instead.");

    state_x   = odometry.pose.pose.position.x;
    state_y   = odometry.pose.pose.position.y;
    state_z   = odometry.pose.pose.position.z;
    state_yaw = odometry_yaw;

    speed_x                  = odometry.twist.twist.linear.x;
    speed_y                  = odometry.twist.twist.linear.y;
    current_heading          = atan2(speed_y, speed_x);
    current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

    current_vertical_speed = odometry.twist.twist.linear.z;
  }

  double horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  double horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  double stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  double stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  double vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;

  goal_x = state_x + stop_dist_x;
  goal_y = state_y + stop_dist_y;
  goal_z = state_z + vertical_stop_dist;

  is_active = true;

  ROS_INFO("[LinearTracker]: activated");

  changeState(STOP_MOTION_STATE);

  return true;
}

void LinearTracker::Deactivate(void) {

  is_active = false;

  ROS_INFO("[LinearTracker]: deactivated");
}

const mrs_msgs::PositionCommand::ConstPtr LinearTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

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

  if (!is_active) {

    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

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
  position_output.acceleration.z = 0;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

const mrs_msgs::TrackerStatus::Ptr LinearTracker::status() {

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
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::LinearTracker, mrs_mav_manager::Tracker)
