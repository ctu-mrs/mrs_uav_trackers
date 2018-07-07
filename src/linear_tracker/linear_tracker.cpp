#include <geometry_msgs/PoseStamped.h>
#include <math.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_uav_manager/Tracker.h>
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
  class LinearTracker : public mrs_uav_manager::Tracker {
    public:
      LinearTracker(void);

      void Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh);

      bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);

      void Deactivate(void);

      const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);

      const mrs_msgs::TrackerStatus::Ptr status();

    private:
      bool                      active, firstime;
      double                    speed, time, dtime;
      double                    x, y, z;
      double                    xc, yc, zc;
      nav_msgs::Odometry        outPose;
      double                    desX = 0, desY = 20, desZ = 5, desYaw = 0;
      bool                      useYaw;
      mrs_msgs::PositionCommand position_output;
      ros::Subscriber           desPosition;

      ros::Publisher cmd_publisher;
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

  void LinearTracker::Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh) {

    ros::NodeHandle priv_nh(nh, "linear_tracker");
    desPosition   = priv_nh.subscribe("desired_position", 1, &LinearTracker::desPositionHandle, this, ros::TransportHints().tcpNoDelay());
    cmd_publisher = priv_nh.advertise<nav_msgs::Odometry>("cmd_pose", 1);

    nh.param("speed", speed, 1.0);
    nh.param("useyaw", useYaw, true);
    firstime = false;

    ROS_INFO("LinearTracker initialized");
  }

  bool LinearTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

    if (mrs_msgs::PositionCommand::Ptr() != cmd) {

      // the last command is usable
      active = true;
      desX   = cmd->position.x;
      desY   = cmd->position.y;
      desZ   = cmd->position.z;
      desYaw = cmd->yaw;

    } else {
    
      // TODO: take the setpoint from odom
    }

    ROS_INFO("LinearTracker was activated.");
    return true;
  }

  void LinearTracker::Deactivate(void) {

    ROS_INFO("LinearTracker was deactivated.");
    active = false;
  }

  const mrs_msgs::PositionCommand::ConstPtr LinearTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

    x                               = msg->pose.pose.position.x;
    y                               = msg->pose.pose.position.y;
    z                               = msg->pose.pose.position.z;
    dtime                           = ros::Time::now().toSec() - time;
    position_output.header.stamp    = ros::Time::now();
    position_output.header.frame_id = "local_origin";

    if (!active) {
      return mrs_msgs::PositionCommand::Ptr();
    }

    ROS_INFO("LinearTracker's update() is called");

    // set positions from odom
    double vectorLength = sqrt((desX - x) * (desX - x) + (desY - y) * (desY - y) + (desZ - z) * (desZ - z));
    if (vectorLength > 1) {
      if (newCommand) {
        xc         = x + ((desX - x) / vectorLength) * speed * dtime;
        yc         = y + ((desY - y) / vectorLength) * speed * dtime;
        zc         = z + ((desZ - z) / vectorLength) * speed * dtime;
        newCommand = false;
      }
      if (!firstime) {
        position_output.position.x = xc + ((desX - xc) / vectorLength) * speed * dtime;
        position_output.position.y = yc + ((desY - yc) / vectorLength) * speed * dtime;
        position_output.position.z = zc + ((desZ - zc) / vectorLength) * speed * dtime;
        xc                         = position_output.position.x;
        yc                         = position_output.position.y;
        zc                         = position_output.position.z;
      } else {
        position_output.position.x = xc + ((desX - xc) / vectorLength) * speed;
        position_output.position.y = yc + ((desY - yc) / vectorLength) * speed;
        position_output.position.z = zc + ((desZ - zc) / vectorLength) * speed;
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
    if (useYaw) {
      position_output.yaw     = desYaw;
      position_output.yaw_dot = 0;
    }
    time = ros::Time::now().toSec();

    outPose.header.stamp    = ros::Time::now();
    outPose.header.frame_id = "local_origin";

    outPose.pose.pose.position = position_output.position;
    tf::Quaternion orientation;
    orientation.setEuler(0, 0, desYaw);
    outPose.pose.pose.orientation.x = msg->pose.pose.orientation.x;
    outPose.pose.pose.orientation.y = msg->pose.pose.orientation.y;
    outPose.pose.pose.orientation.z = msg->pose.pose.orientation.z;
    outPose.pose.pose.orientation.w = msg->pose.pose.orientation.w;

    outPose.twist.twist.linear.x = 0;
    outPose.twist.twist.linear.y = 0;
    outPose.twist.twist.linear.z = 0;

    cmd_publisher.publish(outPose);
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

PLUGINLIB_EXPORT_CLASS(mrs_trackers::LinearTracker, mrs_uav_manager::Tracker)
