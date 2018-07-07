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

namespace mrs_trackers
{
class LinearTracker : public mrs_mav_manager::Tracker {
public:
  LinearTracker(void);

  void Initialize(const ros::NodeHandle &parent_nh);

  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);

  void Deactivate(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);

  const mrs_msgs::TrackerStatus::Ptr status();

private:
  bool                      got_odometry = false;
  nav_msgs::Odometry        odometry;
  bool                      active, firstime;
  double                    speed_, time, dtime;
  double                    x, y, z;
  double                    xc, yc, zc;
  double                    desX = 0, desY = 20, desZ = 5, desYaw = 0;
  bool                      use_yaw_;
  mrs_msgs::PositionCommand position_output;
  ros::Subscriber           desPosition;

  ros::Publisher publisher_cmd_pose;
  void desPositionHandle(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
};

LinearTracker::LinearTracker(void) : active(false) {
}

bool newCommand = false;

void LinearTracker::desPositionHandle(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {
  desX       = msg->position.x;
  desY       = msg->position.y;
  desZ       = msg->position.z;
  desYaw     = msg->position.yaw;
  newCommand = true;
}

void LinearTracker::Initialize(const ros::NodeHandle &parent_nh) {

  ros::NodeHandle priv_nh(parent_nh, "linear_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  desPosition = priv_nh.subscribe("desired_position", 1, &LinearTracker::desPositionHandle, this, ros::TransportHints().tcpNoDelay());

  publisher_cmd_pose = priv_nh.advertise<nav_msgs::Odometry>("cmd_pose", 1);

  priv_nh.param("speed", speed_, 1.0);
  priv_nh.param("use_yaw", use_yaw_, true);
  firstime = false;

  ROS_INFO("LinearTracker initialized");
}

bool LinearTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {
    ROS_WARN("LinearTracker: can't Activate, odometry not set yet");
    return false;
  }

  if (mrs_msgs::PositionCommand::Ptr() != cmd) {

    // the last command is usable
    desX   = cmd->position.x;
    desY   = cmd->position.y;
    desZ   = cmd->position.z;
    desYaw = cmd->yaw;

  } else {

    ROS_WARN("LinearTracker: the previous command is not usable for activation, using Odometry instead.");
    desX = odometry.pose.pose.position.x;
    desY = odometry.pose.pose.position.y;
    desZ = odometry.pose.pose.position.z;

    double         yaw, pitch, roll;
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(roll, pitch, yaw);
    desYaw = yaw;
  }

  active = true;
  ROS_INFO("LinearTracker was activated.");
  return true;
}

void LinearTracker::Deactivate(void) {

  ROS_INFO("LinearTracker was deactivated.");
  active = false;
}

const mrs_msgs::PositionCommand::ConstPtr LinearTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  odometry                        = *msg;
  x                               = msg->pose.pose.position.x;
  y                               = msg->pose.pose.position.y;
  z                               = msg->pose.pose.position.z;
  dtime                           = ros::Time::now().toSec() - time;
  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  got_odometry = true;

  if (!active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  ROS_INFO_THROTTLE(1.0, "LinearTracker's update() is called");

  // set positions from odom
  double vectorLength = sqrt((desX - x) * (desX - x) + (desY - y) * (desY - y) + (desZ - z) * (desZ - z));

  if (vectorLength > 1) {

    if (newCommand) {
      xc         = x + ((desX - x) / vectorLength) * speed_ * dtime;
      yc         = y + ((desY - y) / vectorLength) * speed_ * dtime;
      zc         = z + ((desZ - z) / vectorLength) * speed_ * dtime;
      newCommand = false;
    }

    if (!firstime) {

      position_output.position.x = xc + ((desX - xc) / vectorLength) * speed_ * dtime;
      position_output.position.y = yc + ((desY - yc) / vectorLength) * speed_ * dtime;
      position_output.position.z = zc + ((desZ - zc) / vectorLength) * speed_ * dtime;
      xc                         = position_output.position.x;
      yc                         = position_output.position.y;
      zc                         = position_output.position.z;

    } else {

      position_output.position.x = xc + ((desX - xc) / vectorLength) * speed_;
      position_output.position.y = yc + ((desY - yc) / vectorLength) * speed_;
      position_output.position.z = zc + ((desZ - zc) / vectorLength) * speed_;
      xc                         = position_output.position.x;
      yc                         = position_output.position.y;
      zc                         = position_output.position.z;
    }

  } else {
    position_output.position.x = desX;
    position_output.position.y = desY;
    position_output.position.z = desZ;
  }

  /* ROS_INFO_THROTTLE(2, "LI our: %f %f %f %f", vectorLength, position_output.position.x, position_output.position.y, position_output.position.z); */

  // set velocities from odom
  position_output.velocity.x = msg->twist.twist.linear.x;
  position_output.velocity.y = msg->twist.twist.linear.y;
  position_output.velocity.z = msg->twist.twist.linear.z;

  // set zero accelerations
  position_output.acceleration.x = 0;
  position_output.acceleration.y = 0;
  position_output.acceleration.z = 0;

  // set yaw based on current odom
  if (use_yaw_) {

    position_output.yaw     = desYaw;
    position_output.yaw_dot = 0;
  }
  time = ros::Time::now().toSec();

  // --------------------------------------------------------------
  // |                 publish odom for debugging                 |
  // --------------------------------------------------------------
  //
  nav_msgs::Odometry outPose;
  outPose.header.stamp    = ros::Time::now();
  outPose.header.frame_id = "local_origin";

  outPose.pose.pose.position = position_output.position;
  tf::Quaternion orientation;
  orientation.setEuler(0, 0, desYaw);
  outPose.pose.pose.orientation.x = msg->pose.pose.orientation.x;
  outPose.pose.pose.orientation.y = msg->pose.pose.orientation.y;
  outPose.pose.pose.orientation.z = msg->pose.pose.orientation.z;
  outPose.pose.pose.orientation.w = msg->pose.pose.orientation.w;
  publisher_cmd_pose.publish(outPose);

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

const mrs_msgs::TrackerStatus::Ptr LinearTracker::status() {

  if (!active)
    return mrs_msgs::TrackerStatus::Ptr();

  mrs_msgs::TrackerStatus::Ptr msg(new mrs_msgs::TrackerStatus);
  msg->status = mrs_msgs::TrackerStatus::SUCCEEDED;
  return msg;
}
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::LinearTracker, mrs_mav_manager::Tracker)
