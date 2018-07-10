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

#define PI 3.141592653

namespace mrs_trackers
{
class LinearTracker : public mrs_mav_manager::Tracker {
public:
  LinearTracker(void);

  void Initialize(const ros::NodeHandle &parent_nh);
  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  void                                      Deactivate(void);
  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const mrs_msgs::TrackerStatus::Ptr status();

private:  // Odometry stuff
  nav_msgs::Odometry odometry;
  bool               got_odometry = false;

  double odom_x;
  double odom_y;
  double odom_z;
  double odom_yaw;
  double odom_roll;
  double odom_pitch;

private:
  // tracker's inner states
  bool is_initialized;
  bool is_active;
  bool first_iter;

  ros::Time last_update;
  double    time_difference;

private:
  // dynamical constraints
  double horizontal_speed_;
  double vertical_speed_;
  double horizontal_acceleration_;
  double vertical_acceleration_;
  double yaw_rate_;

private:
  // desired goal
  double des_x, des_y, des_z, des_yaw;

  // last output position
  double last_x, last_y, last_z, last_yaw;

  // internal speed
  double speed_x, speed_y;
  double current_horizontal_speed;
  double current_heading;
  double current_vertical_speed;

  mrs_msgs::PositionCommand position_output;

private:
  // subscribers+publishers+services
  ros::Subscriber    subscriberDesiredPosition;
  ros::ServiceServer service_goto;
  ros::ServiceServer service_goto_relative;

  void callbackDesiredPosition(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  bool callbackGoto(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool callbackGotoRelative(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
};

LinearTracker::LinearTracker(void) : is_initialized(false), is_active(false) {
}

void LinearTracker::callbackDesiredPosition(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {

  des_x   = msg->position.x;
  des_y   = msg->position.y;
  des_z   = msg->position.z;
  des_yaw = msg->position.yaw;
}

bool LinearTracker::callbackGoto(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  des_x   = req.goal[0];
  des_y   = req.goal[1];
  des_z   = req.goal[2];
  des_yaw = req.goal[3];

  ROS_INFO("LinearTracker: received new setpoint %f, %f, %f, %f", des_x, des_y, des_z, des_yaw);

  res.success = true;
  res.message = "setpoint set";

  return true;
}

bool LinearTracker::callbackGotoRelative(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  ROS_INFO("LinearTracker: received new relative setpoint");

  des_x   = odom_x + req.goal[0];
  des_y   = odom_y + req.goal[1];
  des_z   = odom_z + req.goal[2];
  des_yaw = odom_yaw + req.goal[3];

  res.success = true;
  res.message = "setpoint set";

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

  if (horizontal_speed_ < 0) {
    ROS_ERROR("LinearTracker: horizontal_speed is not specified!");
    ros::shutdown();
  }

  if (vertical_speed_ < 0) {
    ROS_ERROR("LinearTracker: vertical_speed is not specified!");
    ros::shutdown();
  }

  if (horizontal_acceleration_ < 0) {
    ROS_ERROR("LinearTracker: horizontal_acceleration is not specified!");
    ros::shutdown();
  }

  if (vertical_acceleration_ < 0) {
    ROS_ERROR("LinearTracker: vertical_acceleration is not specified!");
    ros::shutdown();
  }

  if (yaw_rate_ < 0) {
    ROS_ERROR("LinearTracker: yaw_rate is not specified!");
    ros::shutdown();
  }

  speed_x = 0;
  speed_y = 0;

  current_horizontal_speed = 0;
  current_vertical_speed   = 0;

  is_initialized = true;

  ROS_INFO("LinearTracker initialized");
}

bool LinearTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {
    ROS_WARN("LinearTracker: can't Activate, odometry not set yet");
    return false;
  }

  if (mrs_msgs::PositionCommand::Ptr() != cmd) {

    // the last command is usable
    des_yaw = cmd->yaw;

    last_x   = odometry.pose.pose.position.x;
    last_y   = odometry.pose.pose.position.y;
    last_z   = odometry.pose.pose.position.z;
    last_yaw = cmd->yaw;

    speed_x                  = cmd->velocity.x;
    speed_y                  = cmd->velocity.y;
    current_heading          = atan2(speed_y, speed_x);
    current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

    current_vertical_speed = cmd->velocity.z;
    ROS_INFO("Activated with horizontal speed %f, heading %f", current_horizontal_speed, atan2(speed_y, speed_x));

  } else {

    ROS_WARN("LinearTracker: the previous command is not usable for activation, using Odometry instead.");
    des_yaw = odom_yaw;

    speed_x                  = odometry.twist.twist.linear.x;
    speed_y                  = odometry.twist.twist.linear.y;
    current_heading          = atan2(speed_y, speed_x);
    current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

    current_vertical_speed = odometry.twist.twist.linear.z;

    last_x   = odometry.pose.pose.position.x;
    last_y   = odometry.pose.pose.position.y;
    last_z   = odometry.pose.pose.position.z;
    last_yaw = odom_yaw;
  }

  double horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  double horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  double stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  double stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  double vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;

  des_x = last_x + stop_dist_x;
  des_y = last_y + stop_dist_y;
  des_z = last_z + vertical_stop_dist;

  /* last_update = ros::Time::now(); */

  is_active = true;

  ROS_INFO("LinearTracker was activated.");

  return true;
}

void LinearTracker::Deactivate(void) {

  is_active = false;

  ROS_INFO("LinearTracker was deactivated.");
}

const mrs_msgs::PositionCommand::ConstPtr LinearTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  odometry = *msg;
  odom_x   = odometry.pose.pose.position.x;
  odom_y   = odometry.pose.pose.position.y;
  odom_z   = odometry.pose.pose.position.z;

  got_odometry = true;

  if (!is_active) {

    last_update = ros::Time::now();
    return mrs_msgs::PositionCommand::Ptr();
  }

  time_difference = (ros::Time::now() - last_update).toSec();
  last_update     = ros::Time::now();

  // calculate the yaw from odometry
  tf::Quaternion quaternion_odometry;
  quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
  tf::Matrix3x3 m(quaternion_odometry);
  m.getRPY(odom_roll, odom_pitch, odom_yaw);

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  // determine the vector to the target
  double tar_x, tar_y, tar_z;
  tar_x = des_x - last_x;
  tar_y = des_y - last_y;
  tar_z = des_z - last_z;

  // determine the heading to the target
  double target_heading = atan2(tar_y, tar_x);

  double vertical_direction = (tar_z > 0 ? 1.0 : -1.0);

  double horizontal_distance = sqrt(pow(tar_x, 2) + pow(tar_y, 2));
  double vertical_distance   = fabs(tar_z);

  // --------------------------------------------------------------
  // |                         horizontal                         |
  // --------------------------------------------------------------

  // if the goal is far away, calculate the next step

  double t_stop      = current_horizontal_speed / horizontal_acceleration_;
  double stop_dist   = (t_stop * current_horizontal_speed) / 2;
  double stop_dist_x = cos(current_heading) * stop_dist;
  double stop_dist_y = sin(current_heading) * stop_dist;

  double scalar_tar_speed = tar_x * speed_x + tar_x * speed_y;

  ROS_INFO_THROTTLE(0.2, "des_x %f", des_x);
  ROS_INFO_THROTTLE(0.2, "last_x %f", last_x);
  ROS_INFO_THROTTLE(0.2, "tar_x %f", tar_x);
  ROS_INFO_THROTTLE(0.2, "stop_dist_x %f", stop_dist_x);
  ROS_INFO_THROTTLE(0.2, "scalar %f", scalar_tar_speed);
  ROS_INFO_THROTTLE(0.2, "current heading %f", current_heading);
  ROS_INFO_THROTTLE(0.2, "target heading %f", target_heading);

  double horizontal_distance_thr = 0.2;

  double desired_heading = current_heading;

  if ((horizontal_distance > horizontal_distance_thr) && (scalar_tar_speed >= -10e-3) && fabs(horizontal_distance - stop_dist) > 0.1) {

    if (current_horizontal_speed < horizontal_speed_) {

      ROS_WARN("accelerating");

      current_horizontal_speed += horizontal_acceleration_ * time_difference;

      desired_heading = target_heading;

      if (current_horizontal_speed > horizontal_speed_) {
        current_horizontal_speed = horizontal_speed_;
      }
    }
  } else if ((current_horizontal_speed <= 0.2) && (horizontal_distance <= horizontal_distance_thr)) {

    ROS_WARN("stopped");

    current_horizontal_speed = 0;
    last_x                   = 0.99 * last_x + 0.01 * des_x;
    last_y                   = 0.99 * last_y + 0.01 * des_y;

  } else if (current_horizontal_speed > 0.1 && fabs(horizontal_distance - stop_dist) < 0.1) {

    ROS_WARN("slowing down");

    if (scalar_tar_speed < -1e-3) {

      desired_heading = current_heading;
      ROS_WARN_THROTTLE(0.2, "using original heading");
    } else {

      desired_heading = target_heading;
    }

    current_horizontal_speed -= horizontal_acceleration_ * time_difference;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed = 0;
    }
  }

  ROS_INFO_THROTTLE(0.2, "desired heading %f", desired_heading);

  speed_x = cos(desired_heading) * current_horizontal_speed;
  speed_y = sin(desired_heading) * current_horizontal_speed;

  double step_x = speed_x * time_difference;
  double step_y = speed_y * time_difference;

  last_x += step_x;
  last_y += step_y;

  /* position_output.velocity.x = cos(desired_heading) * current_horizontal_speed; */
  /* position_output.velocity.y = sin(desired_heading) * current_horizontal_speed; */

  // --------------------------------------------------------------
  // |                          vertical                          |
  // --------------------------------------------------------------

  t_stop             = current_vertical_speed / vertical_acceleration_;
  double stop_dist_z = (t_stop * vertical_direction * current_vertical_speed) / 2;

  if (fabs(vertical_distance) < 0.1) {

    current_vertical_speed = 0;
    last_z                 = 0.95 * last_z + 0.05 * des_z;

  } else if (fabs(last_z + stop_dist_z - des_z) < 0.05) {

    current_vertical_speed -= vertical_acceleration_ * time_difference;

    if (current_vertical_speed < 0) {

      current_vertical_speed = 0;
    }

  } else if (current_vertical_speed < vertical_speed_) {

    current_vertical_speed += vertical_acceleration_ * time_difference;

    if (current_vertical_speed > vertical_speed_) {
      current_vertical_speed = vertical_speed_;
    } else if (current_vertical_speed < -vertical_speed_) {
      current_vertical_speed = -vertical_speed_;
    }
  }

  double step_z = vertical_direction * current_vertical_speed * time_difference;

  last_z += step_z;

  position_output.velocity.z = vertical_direction * current_vertical_speed;

  // set the positions
  position_output.position.x = last_x;
  position_output.position.y = last_y;
  position_output.position.z = last_z;
  position_output.yaw        = odom_yaw;
  position_output.yaw_dot    = 0;

  // set zero accelerations
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
