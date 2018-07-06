#include <ros/ros.h>

#include <tf/transform_datatypes.h>
#include "tf/LinearMath/Transform.h"

#include <mrs_msgs/TrackerPoint.h>
#include <mrs_msgs/TrackerStatus.h>
#include <mrs_msgs/TrackerTrajectory.h>
#include <mrs_msgs/Transition.h>
#include <mrs_msgs/Vec1.h>

#include <mav_manager/Vec4.h>
#include <mrs_uav_manager/Tracker.h>

#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
#include <std_srvs/SetBool.h>
#include <std_srvs/Trigger.h>

#include <math.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

using namespace Eigen;

namespace mrs_trackers
{

class CsvTracker : public mrs_uav_manager::Tracker {
public:
  CsvTracker(void);

  void Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh);
  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  void Deactivate(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const mrs_msgs::TrackerStatus::Ptr status();

  bool start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

  void odometryCallback(const nav_msgs::OdometryConstPtr &msg);

  bool setXScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setYScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setZScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setScales(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);

  void setInitPoint(void);

private:
  ros::NodeHandle nh_;

  nav_msgs::Odometry odom;
  ros::Time          odomLastTime;

  std::thread main_thread;

  mrs_msgs::PositionCommand position_cmd;
  mrs_msgs::PositionCommand last_position_cmd;

  std::mutex mutex_position_cmd, mutex_odom;

  // subscriber
  ros::Subscriber subscriber_odom;

  // service servers
  ros::ServiceServer service_start;

  // service clients
  ros::ServiceClient service_switch_tracker;
  ros::ServiceClient service_goto;

  // publishers
  ros::Publisher publisher_odom_pitch_;
  ros::Publisher publisher_desired_pitch_;
  ros::Publisher publisher_desired_zd_;
  ros::Publisher publisher_desired_xd_;
  ros::Publisher publisher_action;
  ros::Publisher publisher_trajectory_;

  ros::Publisher pub_weight;

  ros::Publisher publisher_desired_thrust_;

  ros::ServiceServer ser_x_scale_;
  ros::ServiceServer ser_y_scale_;
  ros::ServiceServer ser_z_scale_;
  ros::ServiceServer ser_scales_;

  std::thread mpc_thread;

  bool odom_set = false;
  bool active   = false;
  bool got_odom = false;

  // for tracking
  bool     tracking     = false;
  int      tracking_idx = 0;
  MatrixXd trajectory;
  int      trajectory_len = 0;

  // for debugging
  double last_odom_pitch = 0;

  // methods
  void mainThread(void);

  // params
  std::string filename_;

  double x_offset_ = 0;
  double y_offset_ = 0;
  double z_offset_ = 0;

  double x_scale_ = 1;
  double y_scale_ = 1;
  double z_scale_ = 1;

  double yaw_ = 0;
};

CsvTracker::CsvTracker(void) : odom_set(false), active(false) {
}

void CsvTracker::setInitPoint(void) {

  // publish the first point as a trajectory
  mrs_msgs::TrackerTrajectory init_trajectory;

  init_trajectory.header.stamp    = ros::Time::now();
  init_trajectory.header.frame_id = "local_origin";
  init_trajectory.fly_now         = false;
  init_trajectory.use_yaw         = true;  // TODO

  mrs_msgs::TrackerPoint point;
  point.x   = x_scale_ * trajectory(0, 0) + x_offset_;
  point.y   = y_offset_;
  point.z   = z_scale_ * trajectory(0, 1) + z_offset_;
  point.yaw = yaw_;

  init_trajectory.points.push_back(point);

  publisher_trajectory_.publish(init_trajectory);

  ROS_INFO("Publishing the first point to the MPC tracker");
}

bool CsvTracker::setXScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  if (req.goal >= 0 && req.goal <= 1.0) {

    x_scale_ = req.goal;

    res.success = true;
    res.message = "OK";

    setInitPoint();

  } else {

    res.success = false;
    res.message = "Scale out of bound!";
  }

  return true;
}

bool CsvTracker::setYScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  if (req.goal >= 0 && req.goal <= 1.0) {

    y_scale_ = req.goal;

    res.success = true;
    res.message = "OK";

    CsvTracker::setInitPoint();

  } else {

    res.success = false;
    res.message = "Scale out of bound!";
  }

  return true;
}

bool CsvTracker::setZScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  if (req.goal >= 0 && req.goal <= 1.0) {

    z_scale_ = req.goal;

    res.success = true;
    res.message = "OK";

    CsvTracker::setInitPoint();

  } else {

    res.success = false;
    res.message = "Scale out of bound!";
  }

  return true;
}

bool CsvTracker::setScales(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  if (req.goal >= 0 && req.goal <= 1.0) {

    x_scale_ = req.goal;
    y_scale_ = req.goal;
    z_scale_ = req.goal;

    res.success = true;
    res.message = "OK";

    CsvTracker::setInitPoint();

  } else {

    res.success = false;
    res.message = "Scale out of bound!";
  }

  return true;
}

bool CsvTracker::start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  return true;
}

double dist(double ax, double ay, double az, double bx, double by, double bz) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2) + pow(az - bz, 2));
}

// called once at the very beginning
void CsvTracker::Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh) {
  ros::NodeHandle priv_nh(nh, "csv_tracker");

  nh.param("filename", filename_, std::string());

  if (filename_.empty()) {
    ROS_ERROR("The file name has not been filled!");
    ros::shutdown();
    return;
  }

  // posX posY vx vy ax ay theta thrust release
  trajectory = MatrixXd::Zero(5000, 9);

  std::ifstream in(filename_.c_str(), std::ifstream::in);

  if (!in) {

    ROS_ERROR("Cannot open %s", filename_.c_str());
    ros::shutdown();
    return;

  } else {

    ROS_INFO("Loading from file: %s", filename_.c_str());
    std::string line;

    while (getline(in, line)) {

      std::istringstream s(line);

      s >> trajectory(trajectory_len, 0);
      s >> trajectory(trajectory_len, 1);
      s >> trajectory(trajectory_len, 2);
      s >> trajectory(trajectory_len, 3);
      s >> trajectory(trajectory_len, 4);
      s >> trajectory(trajectory_len, 5);
      s >> trajectory(trajectory_len, 6);
      s >> trajectory(trajectory_len, 7);
      s >> trajectory(trajectory_len, 8);

      ROS_INFO("%2.2f %2.2f", trajectory(trajectory_len, 0), trajectory(trajectory_len, 1));

      trajectory_len++;
    }

    in.close();

    ROS_INFO("Trajectory loaded, len = %d", trajectory_len);
  }

  service_goto           = priv_nh.serviceClient<mav_manager::Vec4>("goto_out");
  service_switch_tracker = priv_nh.serviceClient<mrs_msgs::Transition>("transition_out");

  publisher_action      = priv_nh.advertise<std_msgs::Int32>("action", 1, false);
  pub_weight            = priv_nh.advertise<std_msgs::Float32>("set_mass", 1);
  publisher_trajectory_ = priv_nh.advertise<mrs_msgs::TrackerTrajectory>("desired_trajectory", 1);

  subscriber_odom = priv_nh.subscribe("odom_in", 1, &CsvTracker::odometryCallback, this, ros::TransportHints().tcpNoDelay());

  publisher_odom_pitch_    = priv_nh.advertise<std_msgs::Float64>("odom_pitch", 1, false);
  publisher_desired_pitch_ = priv_nh.advertise<std_msgs::Float64>("desired_pitch", 1, false);
  publisher_desired_zd_    = priv_nh.advertise<std_msgs::Float64>("desired_zd", 1, false);
  publisher_desired_xd_    = priv_nh.advertise<std_msgs::Float64>("desired_xd", 1, false);

  publisher_desired_thrust_ = priv_nh.advertise<std_msgs::Float64>("desired_thrust", 1, false);

  ser_x_scale_ = priv_nh.advertiseService("set_x_scale", &CsvTracker::setXScale, this);
  ser_y_scale_ = priv_nh.advertiseService("set_y_scale", &CsvTracker::setYScale, this);
  ser_z_scale_ = priv_nh.advertiseService("set_z_scale", &CsvTracker::setZScale, this);
  ser_scales_  = priv_nh.advertiseService("set_scales", &CsvTracker::setScales, this);

  // load params
  nh.param("offset/x", x_offset_, 10000.0);
  nh.param("offset/y", y_offset_, 10000.0);
  nh.param("offset/z", z_offset_, 10000.0);

  nh.param("scale/x", x_scale_, -1.0);
  nh.param("scale/y", y_scale_, -1.0);
  nh.param("scale/z", z_scale_, -1.0);

  nh.param("yaw", yaw_, -1.0);

  ROS_WARN("offset/x: %2.2f", x_offset_);
  ROS_WARN("offset/y: %2.2f", y_offset_);
  ROS_WARN("offset/z: %2.2f", z_offset_);
  ROS_WARN("scale/x: %2.2f", x_scale_);
  ROS_WARN("scale/y: %2.2f", y_scale_);
  ROS_WARN("scale/z: %2.2f", z_scale_);
  ROS_WARN("yaw: %2.2f", yaw_);

  if (x_offset_ > 1000 || y_offset_ > 1000 || z_offset_ > 1000) {
    ROS_ERROR("Offsets were not loaded from the config file!");
    ros::shutdown();
  }

  if (x_scale_ < 0 || y_scale_ < 0 || z_scale_ < 0) {
    ROS_ERROR("Scales were not loaded from the config file!");
    ros::shutdown();
  }

  if (x_scale_ > 1 || y_scale_ > 1 || z_scale_ > 1) {
    ROS_ERROR("Scales are greater than 1");
    ros::shutdown();
  }

  if (yaw_ < 0) {
    ROS_ERROR("Yaw was not set in the config file!");
    ros::shutdown();
  }

  CsvTracker::setInitPoint();

  main_thread = std::thread(&CsvTracker::mainThread, this);
}

void CsvTracker::odometryCallback(const nav_msgs::OdometryConstPtr &msg) {

  got_odom = true;

  // tady tim to neni
  mutex_odom.lock();
  { odom = *msg; }
  mutex_odom.unlock();
}

bool CsvTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odom) {

    ROS_ERROR("Cannot activate CSV tracker, dont have odometry");
    return false;
  }

  last_position_cmd = *cmd;

  tracking_idx = 0;

  position_cmd = *cmd;

  // if we are too far from the initial point
  double distance = sqrt(pow(odom.pose.pose.position.x - (x_scale_ * trajectory(0, 0) + x_offset_), 2) + pow(odom.pose.pose.position.y - y_offset_, 2) +
                         pow(odom.pose.pose.position.z - (z_scale_ * trajectory(0, 1) + z_offset_), 2));

  ROS_INFO("Distance: %2.2f", distance);
  ROS_INFO("Z_start: %2.2f", z_scale_ * trajectory(0, 1) + z_offset_);
  ROS_INFO("Z_scale: %2.2f", z_scale_);

  if (distance > 1.0) {

    ROS_ERROR("Cannon activate, to far from the initial point!");

    active = false;

  } else {

    ROS_INFO("CSV tracker activated");
    active   = true;
    tracking = true;
  }

  return active;
}

void CsvTracker::Deactivate(void) {

  active   = false;
  odom_set = false;

  ROS_INFO("CSV tracker deactivated");
}

// if the tracker is active, this mehod is called on every odometry update, even if the tracker is not active
const mrs_msgs::PositionCommand::ConstPtr CsvTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // very important, return null pointer when the tracker is not active, but we can still do some stuff
  if (!active)
    return mrs_msgs::PositionCommand::Ptr();

  // calculate the current angle
  double                    odom_roll, odom_pitch, odom_yaw;
  geometry_msgs::Quaternion odom_quat = msg->pose.pose.orientation;
  tf::Quaternion            qt(odom_quat.x, odom_quat.y, odom_quat.z, odom_quat.w);
  tf::Matrix3x3(qt).getRPY(odom_roll, odom_pitch, odom_yaw);

  last_odom_pitch = odom_pitch;

  mrs_msgs::PositionCommand::ConstPtr out;

  mutex_position_cmd.lock();
  { out = mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd)); }
  mutex_position_cmd.unlock();

  return out;
}

void CsvTracker::mainThread(void) {

  ROS_INFO("Main thread has started");

  ros::Rate r(100);

  while (ros::ok()) {

    while (!got_odom && ros::ok()) {

      ROS_WARN_THROTTLE(1.0, "Waiting for odometry");
      r.sleep();
    }

    while (!active && ros::ok()) {
      r.sleep();
    }

    ROS_INFO_THROTTLE(1, "Thread is spinning, idx=%d", tracking_idx);

    mutex_position_cmd.lock();
    {
      // set the message according to the file
      position_cmd.header.stamp    = ros::Time::now();
      position_cmd.header.frame_id = "local_origin";

      position_cmd.position.x = x_scale_ * trajectory(tracking_idx, 0) + x_offset_;
      position_cmd.position.z = z_scale_ * trajectory(tracking_idx, 1) + z_offset_;

      position_cmd.velocity.x = x_scale_ * trajectory(tracking_idx, 2);
      position_cmd.velocity.z = z_scale_ * trajectory(tracking_idx, 3);

      position_cmd.acceleration.x = x_scale_ * trajectory(tracking_idx, 4);
      position_cmd.acceleration.z = z_scale_ * trajectory(tracking_idx, 5);

      position_cmd.position.y     = y_offset_;
      position_cmd.velocity.y     = 0;
      position_cmd.acceleration.y = 0;

      position_cmd.yaw     = yaw_;
      position_cmd.yaw_dot = 0;
    }
    mutex_position_cmd.unlock();

    // debugging current pitch
    std_msgs::Float64 odom_pitch_msg;
    odom_pitch_msg.data = last_odom_pitch;

    // debugging desired pitch
    std_msgs::Float64 desired_pitch_msg;
    desired_pitch_msg.data = -trajectory(tracking_idx, 6);

    // debugging desired zd
    std_msgs::Float64 desired_zd_msg;
    desired_zd_msg.data = trajectory(tracking_idx, 3);

    // debugging desired xd
    std_msgs::Float64 desired_xd_msg;
    desired_xd_msg.data = trajectory(tracking_idx, 2);

    publisher_odom_pitch_.publish(odom_pitch_msg);
    publisher_desired_pitch_.publish(desired_pitch_msg);
    publisher_desired_zd_.publish(desired_zd_msg);
    publisher_desired_xd_.publish(desired_xd_msg);

    if (trajectory(tracking_idx, 8) == 1) {

      ROS_ERROR("RELEASING MASS");

      std_msgs::Int32 action;

      action.data = 1;

      publisher_action.publish(action);
    }

    // debugging desired thrust
    std_msgs::Float64 desired_thrust_msg;
    desired_thrust_msg.data = trajectory(tracking_idx, 7) / 34.3233;

    publisher_desired_thrust_.publish(desired_thrust_msg);

    if (tracking_idx < (trajectory_len - 1)) {

      tracking_idx = tracking_idx + 1;

    } else {

      ROS_INFO_THROTTLE(1, "Trajectory has finished, replaying the last poing...");

      mrs_msgs::Transition transition;
      transition.request.tracker = "mrs_trackers/MpcTracker";
      service_switch_tracker.call(transition);
    }

    r.sleep();
  }
}

const mrs_msgs::TrackerStatus::Ptr CsvTracker::status() {

  if (!active)
    return mrs_msgs::TrackerStatus::Ptr();

  mrs_msgs::TrackerStatus::Ptr msg(new mrs_msgs::TrackerStatus);
  msg->status = mrs_msgs::TrackerStatus::SUCCEEDED;
  return msg;
}

}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::CsvTracker, mrs_uav_manager::Tracker)
