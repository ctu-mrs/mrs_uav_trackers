#include <ros/ros.h>

#include <tf/transform_datatypes.h>
#include <tf/LinearMath/Transform.h>

#include <mrs_msgs/TrackerTrajectory.h>
#include <mrs_msgs/String.h>

#include <mrs_mav_manager/Tracker.h>

#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>

#include <math.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <fstream>
#include <iostream>
#include <mutex>

#include <mrs_lib/ParamLoader.h>

using namespace Eigen;

namespace mrs_trackers
{

//{ class CsvTracker

class CsvTracker : public mrs_mav_manager::Tracker {
public:
  CsvTracker(void);

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

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToAltitude(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYaw(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYawRelative(const std_msgs::Float64ConstPtr &msg);

  bool start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

  void odometryCallback(const nav_msgs::OdometryConstPtr &msg);

  bool setXScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setYScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setZScale(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool setScales(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);

  void setInitPoint(void);

private:
  bool callbacks_enabled = true;

private:
  ros::NodeHandle nh_;

  nav_msgs::Odometry odom;
  ros::Time          odomLastTime;

  ros::Timer main_timer;

  mrs_msgs::PositionCommand position_cmd;
  mrs_msgs::PositionCommand last_position_cmd;

  std::mutex mutex_position_cmd, mutex_odom;

  // subscriber
  ros::Subscriber subscriber_odom;

  // service servers
  ros::ServiceServer service_start;

  // service clients
  ros::ServiceClient service_switch_tracker;
  ros::ServiceClient service_goTo;

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

  bool odom_set       = false;
  bool is_active      = false;
  bool is_initialized = false;
  bool got_odom       = false;

  // for tracking
  bool     tracking     = false;
  int      tracking_idx = 0;
  MatrixXd trajectory;
  int      trajectory_len = 0;

  // for debugging
  double last_odom_pitch = 0;

  // methods
  void mainTimer(const ros::TimerEvent &event);

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

CsvTracker::CsvTracker(void) : odom_set(false), is_active(false) {
}

//}

// | ------------------- tracker's interface ------------------ |

//{ initialize()

void CsvTracker::initialize(const ros::NodeHandle &parent_nh, mrs_mav_manager::SafetyArea const *safety_area) {

  ros::NodeHandle priv_nh(parent_nh, "csv_tracker");

  mrs_lib::ParamLoader param_loader(nh_, "CsvTracker");

  param_loader.load_param("filename", filename_);

  // posX posY vx vy ax ay theta thrust release
  trajectory = MatrixXd::Zero(5000, 9);

  std::ifstream in(filename_.c_str(), std::ifstream::in);

  if (!in) {

    ROS_ERROR("[CsvTracker]: Cannot open %s", filename_.c_str());
    ros::shutdown();
    return;

  } else {

    ROS_INFO("[CsvTracker]: Loading from file: %s", filename_.c_str());
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

      ROS_INFO("[CsvTracker]: %2.2f %2.2f", trajectory(trajectory_len, 0), trajectory(trajectory_len, 1));

      trajectory_len++;
    }

    in.close();

    ROS_INFO("[CsvTracker]: Trajectory loaded, len = %d", trajectory_len);
  }

  service_goTo           = priv_nh.serviceClient<mrs_msgs::Vec4>("goTo_out");
  service_switch_tracker = priv_nh.serviceClient<mrs_msgs::String>("SwitchTracker_out");

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
  param_loader.load_param("offset/x", x_offset_);
  param_loader.load_param("offset/y", y_offset_);
  param_loader.load_param("offset/z", z_offset_);

  param_loader.load_param("scale/x", x_scale_);
  param_loader.load_param("scale/y", y_scale_);
  param_loader.load_param("scale/z", z_scale_);

  param_loader.load_param("yaw", yaw_);

  ROS_WARN("[CsvTracker]: offset/x: %2.2f", x_offset_);
  ROS_WARN("[CsvTracker]: offset/y: %2.2f", y_offset_);
  ROS_WARN("[CsvTracker]: offset/z: %2.2f", z_offset_);
  ROS_WARN("[CsvTracker]: scale/x: %2.2f", x_scale_);
  ROS_WARN("[CsvTracker]: scale/y: %2.2f", y_scale_);
  ROS_WARN("[CsvTracker]: scale/z: %2.2f", z_scale_);
  ROS_WARN("[CsvTracker]: yaw: %2.2f", yaw_);

  if (x_scale_ > 1 || y_scale_ > 1 || z_scale_ > 1) {
    ROS_ERROR("[CsvTracker]: Scales are greater than 1");
    ros::shutdown();
  }

  CsvTracker::setInitPoint();

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer = nh_.createTimer(ros::Rate(100), &CsvTracker::mainTimer, this);

  if (!param_loader.loaded_successfully()) {
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[CsvTracker]: initialized");
}

//}

//{ activate()

bool CsvTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odom) {

    ROS_ERROR("[CsvTracker]: Cannot activate CSV tracker, dont have odometry");
    return false;
  }

  last_position_cmd = *cmd;

  tracking_idx = 0;

  position_cmd = *cmd;

  // if we are too far from the initial point
  double distance = sqrt(pow(odom.pose.pose.position.x - (x_scale_ * trajectory(0, 0) + x_offset_), 2) + pow(odom.pose.pose.position.y - y_offset_, 2) +
                         pow(odom.pose.pose.position.z - (z_scale_ * trajectory(0, 1) + z_offset_), 2));

  ROS_INFO("[CsvTracker]: Distance: %2.2f", distance);
  ROS_INFO("[CsvTracker]: Z_start: %2.2f", z_scale_ * trajectory(0, 1) + z_offset_);
  ROS_INFO("[CsvTracker]: Z_scale: %2.2f", z_scale_);

  if (distance > 1.0) {

    ROS_ERROR("[CsvTracker]: Cannon activate, to far from the initial point!");

    is_active = false;

  } else {

    ROS_INFO("[CsvTracker]: CSV tracker activated");
    is_active = true;
    tracking  = true;
  }

  return is_active;
}

//}

//{ deactivate()

void CsvTracker::deactivate(void) {

  is_active = false;
  odom_set  = false;

  ROS_INFO("[CsvTracker]: CSV tracker deactivated");
}

//}

//{ update()

const mrs_msgs::PositionCommand::ConstPtr CsvTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // very important, return null pointer when the tracker is not active, but we can still do some stuff
  if (!is_active)
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

//}

//{ getStatus()

const mrs_msgs::TrackerStatus::Ptr CsvTracker::getStatus() {

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

const std_srvs::SetBoolResponse::ConstPtr CsvTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[100];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[CsvTracker]: %s", message);

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

const mrs_msgs::Vec4Response::ConstPtr CsvTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

//{ goTo() topic

bool CsvTracker::goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg) {
  return false;
}

//}

//{ goToRelative() service

const mrs_msgs::Vec4Response::ConstPtr CsvTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

//{ goToRelative() topic

bool CsvTracker::goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg) {
  return false;
}

//}

//{ goToAltitude() service

const mrs_msgs::Vec1Response::ConstPtr CsvTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

//{ goToAltitude() topic

bool CsvTracker::goToAltitude(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

//{ setYaw() service

const mrs_msgs::Vec1Response::ConstPtr CsvTracker::setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

//{ setYaw() topic

bool CsvTracker::setYaw(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

//{ setYawRelative() service

const mrs_msgs::Vec1Response::ConstPtr CsvTracker::setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

//{ setYawRelative() topic

bool CsvTracker::setYawRelative(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

//{ hover()

const std_srvs::TriggerResponse::ConstPtr CsvTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

// | ------------------------ callbacks ----------------------- |

//{ odometryCallbacks()

void CsvTracker::odometryCallback(const nav_msgs::OdometryConstPtr &msg) {

  got_odom = true;

  // tady tim to neni
  mutex_odom.lock();
  { odom = *msg; }
  mutex_odom.unlock();
}

//}

//{ start_callback()

bool CsvTracker::start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  return true;
}

//}

//{ setInitPoint()

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

  ROS_INFO("[CsvTracker]: Publishing the first point to the MPC tracker");
}

//}

//{ setXYScale()

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

//}

//{ setYScale()

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

//}

//{ setZScale()

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

//}

//{ setScales()

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

//}

// | ------------------------- timers ------------------------- |

//{ mainTimer()

void CsvTracker::mainTimer(const ros::TimerEvent &event) {

  if (!got_odom) {

    ROS_WARN_THROTTLE(1.0, "[CsvTracker]: Waiting for odometry");
    return;
  }

  if (!is_active) {
    return;
  }

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

    ROS_ERROR("[CsvTracker]: RELEASING MASS");

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

    ROS_INFO_THROTTLE(1, "[CsvTracker]: Trajectory has finished, replaying the last poing...");

    mrs_msgs::String SwitchTracker;
    SwitchTracker.request.value = "mrs_trackers/MpcTracker";
    service_switch_tracker.call(SwitchTracker);
  }
}

//}
}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::CsvTracker, mrs_mav_manager::Tracker)
