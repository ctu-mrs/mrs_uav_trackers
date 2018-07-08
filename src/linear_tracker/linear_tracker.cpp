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
#include <mutex>

#include <mrs_msgs/PositionCommand.h>
#include <mrs_msgs/TrackerStatus.h>
#include <mrs_msgs/Vec4.h>

#define PI 3.141592653
/* #define SAFE 1 */

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

private:
  nav_msgs::Odometry odometry;
  bool               got_odometry = false;
  double             odom_x;
  double             odom_y;
  double             odom_z;
  double             odom_yaw;
  double             odom_roll;
  double             odom_pitch;

private:
  bool   is_initialized, is_active, first_iter;
  double horizontal_speed_, vertical_speed_, yaw_rate_, max_acceleration_;

  ros::Time last_update;
  double    time_difference;

  // desired goal
  double des_x, des_y, des_z, des_yaw;

  // last position
  double last_x, last_y, last_z, last_yaw;

  mrs_msgs::PositionCommand position_output;

private:
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

  res.success = true;
  res.message = "setpoint set";

  return true;
}

bool LinearTracker::callbackGotoRelative(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

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
  priv_nh.param("yaw_rate", yaw_rate_, -1.0);
  priv_nh.param("max_acceleration", max_acceleration_, -1.0);

  if (horizontal_speed_ < 0) {
    ROS_ERROR("LinearTracker: horizontal_speed is not specified!");
    ros::shutdown();
  }

  if (vertical_speed_ < 0) {
    ROS_ERROR("LinearTracker: vertical_speed is not specified!");
    ros::shutdown();
  }

  if (yaw_rate_ < 0) {
    ROS_ERROR("LinearTracker: yaw_rate is not specified!");
    ros::shutdown();
  }

  if (max_acceleration_ < 0) {
    ROS_ERROR("LinearTracker: max_acceleration is not specified!");
    ros::shutdown();
  }

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
    des_x   = cmd->position.x;
    des_y   = cmd->position.y;
    des_z   = cmd->position.z;
    des_yaw = cmd->yaw;

  } else {

    ROS_WARN("LinearTracker: the previous command is not usable for activation, using Odometry instead.");
    des_x   = odometry.pose.pose.position.x;
    des_y   = odometry.pose.pose.position.y;
    des_z   = odometry.pose.pose.position.z;
    des_yaw = odom_yaw;
  }

  last_x   = odometry.pose.pose.position.x;
  last_y   = odometry.pose.pose.position.y;
  last_z   = odometry.pose.pose.position.z;
  last_yaw = odom_yaw;

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

  // calculate the yaw from odometry
  tf::Quaternion quaternion_odometry;
  quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
  tf::Matrix3x3 m(quaternion_odometry);
  m.getRPY(odom_roll, odom_pitch, odom_yaw);

  time_difference = (ros::Time::now() - last_update).toSec();
  last_update     = ros::Time::now();

  /* #ifdef SAFE */
  /*   last_x   = odometry.pose.pose.position.x; */
  /*   last_y   = odometry.pose.pose.position.y; */
  /*   last_z   = odometry.pose.pose.position.z; */
  /*   last_yaw = odom_yaw; */
  /*   time_difference = 0.2; */
  /* #endif */

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  // determine the vector to the target
  double tar_x, tar_y, tar_z;
  tar_x = des_x - last_x;
  tar_y = des_y - last_y;
  tar_z = des_z - last_z;

  // determine the heading to the target
  double desired_heading    = atan2(tar_y, tar_x);
  double vertical_direction = (tar_z > 0 ? 1.0 : -1.0);

  double horizontal_distance = sqrt(pow(tar_x, 2) + pow(tar_y, 2));
  double vertical_distance   = fabs(tar_z);

  // --------------------------------------------------------------
  // |                         horizontal                         |
  // --------------------------------------------------------------

  // if the goasl is far away, calculate the next step
  if (horizontal_distance > (horizontal_speed_ * time_difference)) {

    double step_x = cos(desired_heading) * horizontal_speed_ * time_difference;
    double step_y = sin(desired_heading) * horizontal_speed_ * time_difference;

    /* if (step_x > odometry.twist.twist.linear.x * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting + x"); */
    /*   step_x = odometry.twist.twist.linear.x * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } else if (step_x < odometry.twist.twist.linear.x * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting - x"); */
    /*   step_x = odometry.twist.twist.linear.x * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } */

    /* if (step_y > odometry.twist.twist.linear.y * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting + y"); */
    /*   step_y = odometry.twist.twist.linear.y * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } else if (step_y < odometry.twist.twist.linear.y * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting - y"); */
    /*   step_y = odometry.twist.twist.linear.y * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } */

    last_x += step_x;
    last_y += step_y;

    position_output.velocity.x = cos(desired_heading) * horizontal_speed_;
    position_output.velocity.y = sin(desired_heading) * horizontal_speed_;

    // if the goal is closer than one step at nominal horizontal_speed_, set it as the output
  } else {

    last_x = des_x;
    last_y = des_y;

    position_output.velocity.x = 0;
    position_output.velocity.y = 0;
  }

  // --------------------------------------------------------------
  // |                          vertical                          |
  // --------------------------------------------------------------

  if (vertical_distance > (vertical_speed_ * time_difference)) {

    double step_z = vertical_direction * vertical_speed_ * time_difference;

    /* if (step_z > odometry.twist.twist.linear.z * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting + z"); */
    /*   step_z = odometry.twist.twist.linear.z * time_difference + 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } else if (step_z < odometry.twist.twist.linear.z * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2)) { */
    /*   ROS_INFO_THROTTLE(1.0, "Limiting - z"); */
    /*   step_z = odometry.twist.twist.linear.z * time_difference - 0.5 * max_acceleration_ * pow(time_difference, 2); */
    /* } */

    last_z += step_z;

    position_output.velocity.z = vertical_direction * vertical_speed_;

  } else {

    last_z = des_z;

    position_output.velocity.z = 0;
  }

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
