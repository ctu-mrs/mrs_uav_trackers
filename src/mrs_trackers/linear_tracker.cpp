#include <ros/package.h>
#include <ros/ros.h>

#include <tf/transform_datatypes.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_uav_manager/Tracker.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mutex>

class LinearTracker : public mrs_uav_manager::Tracker {
public:

  LinearTracker(void);

  void Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh);

  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);

  void Deactivate(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);

  const mrs_msgs::TrackerStatus::Ptr status();

private:
  bool                      active;
  double                    speed;
  double                    x, y, z;
  double                    desX = 0, desY = 20, desZ = 5, desYaw = 0;
  bool                      useYaw;
  mrs_msgs::PositionCommand position_output;
  ros::Subscriber           desPosition;

  void desPositionHandle(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
};

LinearTracker::LinearTracker(void) : active(false) {
}

void LinearTracker::desPositionHandle(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {
  desX   = msg->position.x;
  desY   = msg->position.y;
  desZ   = msg->position.z;
  desYaw = msg->position.yaw;
}

void LinearTracker::Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh) {

  ros::NodeHandle priv_nh(nh, "linear_tracker");
  desPosition = priv_nh.subscribe("desired_position", 1, &LinearTracker::desPositionHandle, this, ros::TransportHints().tcpNoDelay());
  nh.param("speed", speed, 1.0);
  nh.param("useyaw", useYaw, true);
}

bool LinearTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {
  active = true;
  desX   = cmd->position.x;
  desY   = cmd->position.y;
  desZ   = cmd->position.z;
  return true;
}

void LinearTracker::Deactivate(void) {
  active = false;
}

const mrs_msgs::PositionCommand::ConstPtr LinearTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  x = msg->pose.pose.position.x;
  y = msg->pose.pose.position.y;
  z = msg->pose.pose.position.z;

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  double vectorLength = sqrt((desX - x) * (desX - x) + (desY - y) * (desY - y) + (desZ - z) * (desZ - z));
  // set positions from odom
  if (vectorLength > 5) {
    position_output.position.x = x + ((desX - x) / vectorLength) * speed;
    position_output.position.y = y + ((desY - y) / vectorLength) * speed;
    position_output.position.z = z + ((desZ - z) / vectorLength) * speed;
  } else {
    position_output.position.x = desX;
    position_output.position.y = desY;
    position_output.position.z = desZ;
  }

  ROS_INFO_THROTTLE(2, "LI our: %f %f %f %f", vectorLength, position_output.position.x, position_output.position.y, position_output.position.z);

  // set velocities from odom
  position_output.velocity.x = msg->twist.twist.linear.x;
  position_output.velocity.y = msg->twist.twist.linear.y;
  position_output.velocity.z = msg->twist.twist.linear.z;

  // set zero accelerations
  position_output.acceleration.x = 0;
  position_output.acceleration.y = 0;
  position_output.acceleration.z = 0;

  // set yaw based on current odom
  if (useYaw) {
    position_output.yaw     = desYaw;
    position_output.yaw_dot = 0;
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

const mrs_msgs::TrackerStatus::Ptr LinearTracker::status() {

  if (!active)
    return mrs_msgs::TrackerStatus::Ptr();

  mrs_msgs::TrackerStatus::Ptr msg(new mrs_msgs::TrackerStatus);
  msg->status = mrs_msgs::TrackerStatus::SUCCEEDED;
  return msg;
}

#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(LinearTracker, mrs_uav_manager::Tracker)
