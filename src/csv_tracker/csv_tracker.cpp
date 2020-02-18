#define VERSION "0.0.4.0"

/* includes //{ */

#include <ros/ros.h>

#include <tf/transform_datatypes.h>
#include <tf/LinearMath/Transform.h>

#include <mrs_msgs/TrackerTrajectorySrv.h>
#include <mrs_msgs/String.h>
#include <mrs_msgs/UavState.h>

#include <mrs_uav_manager/Tracker.h>

#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>

#include <mrs_msgs/Float64Stamped.h>

#include <math.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <fstream>
#include <iostream>
#include <mutex>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>

//}

using namespace Eigen;

namespace mrs_trackers
{

namespace csv_tracker
{

/* //{ class CsvTracker */

class CsvTracker : public mrs_uav_manager::Tracker {
public:
  virtual void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);
  virtual bool resetStatic(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &msg, const mrs_msgs::AttitudeCommand::ConstPtr &cmd);
  virtual const mrs_msgs::TrackerStatus             getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  virtual void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr &msg);

  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goTo(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goToRelative(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   goToAltitude(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYaw(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYawRelative(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

  virtual const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::ReferenceConstPtr &msg);

  bool start_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

  bool setXScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setYScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setZScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setScales(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);

  void setInitPoint(void);

private:
  bool callbacks_enabled = true;

private:
  ros::NodeHandle                                    nh_;
  std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers;

  mrs_msgs::UavState uav_state;
  ros::Time          odomLastTime;

  ros::Timer main_timer;
  ros::Timer set_traj_timer;

  mrs_msgs::PositionCommand position_cmd;
  mrs_msgs::PositionCommand last_position_cmd;

  std::mutex mutex_position_cmd, mutex_uav_state;

  // subscriber
  ros::Subscriber subscriber_odom;

  // service servers
  ros::ServiceServer service_start;

  // service clients
  ros::ServiceClient service_switch_tracker;

  // publishers
  ros::Publisher publisher_odom_pitch_;
  ros::Publisher publisher_desired_pitch_;
  ros::Publisher publisher_desired_zd_;
  ros::Publisher publisher_desired_xd_;
  ros::Publisher publisher_action;

  ros::ServiceClient service_client_set_trajectory;
  ros::ServiceServer service_server_set_trajectory;

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
  void setTrajTimer(const ros::TimerEvent &event);

  // params
  std::string filename_;
  std::string _version_;
  std::string uav_name_;

  double x_offset_ = 0;
  double y_offset_ = 0;
  double z_offset_ = 0;

  double x_scale_ = 1;
  double y_scale_ = 1;
  double z_scale_ = 1;

  double yaw_ = 0;

private:
  mrs_lib::Profiler profiler;
  bool              profiler_enabled_ = false;
};

//}

// | ------------------- tracker's interface ------------------ |

/* //{ initialize() */

void CsvTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers) {

  uav_name_             = uav_name;
  this->common_handlers = common_handlers;

  ros::NodeHandle nh_(parent_nh, "csv_tracker");

  ros::Time::waitForValid();

  mrs_lib::ParamLoader param_loader(nh_, "CsvTracker");

  param_loader.load_param("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[CsvTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.load_param("filename", filename_);
  param_loader.load_param("enable_profiler", profiler_enabled_);

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

  service_switch_tracker = nh_.serviceClient<mrs_msgs::String>("switch_tracker_out");

  publisher_action = nh_.advertise<std_msgs::Int32>("action_in", 1, false);
  pub_weight       = nh_.advertise<std_msgs::Float32>("set_mass_out", 1);

  service_client_set_trajectory = nh_.serviceClient<mrs_msgs::TrackerTrajectorySrv>("set_trajectory_out");

  publisher_odom_pitch_     = nh_.advertise<mrs_msgs::Float64>("odom_pitch_out", 1, false);
  publisher_desired_pitch_  = nh_.advertise<mrs_msgs::Float64>("desired_pitch_out", 1, false);
  publisher_desired_zd_     = nh_.advertise<mrs_msgs::Float64>("desired_zd_out", 1, false);
  publisher_desired_xd_     = nh_.advertise<mrs_msgs::Float64>("desired_xd_out", 1, false);
  publisher_desired_thrust_ = nh_.advertise<mrs_msgs::Float64>("desired_thrust_out", 1, false);

  ser_x_scale_ = nh_.advertiseService("set_x_scale_in", &CsvTracker::setXScale, this);
  ser_y_scale_ = nh_.advertiseService("set_y_scale_in", &CsvTracker::setYScale, this);
  ser_z_scale_ = nh_.advertiseService("set_z_scale_in", &CsvTracker::setZScale, this);
  ser_scales_  = nh_.advertiseService("set_scales_in", &CsvTracker::setScales, this);

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

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = mrs_lib::Profiler(nh_, "CsvTracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer     = nh_.createTimer(ros::Rate(100), &CsvTracker::mainTimer, this, false, false);
  set_traj_timer = nh_.createTimer(ros::Rate(1), &CsvTracker::setTrajTimer, this);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[CsvTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[CsvTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

bool CsvTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odom) {

    ROS_ERROR("[CsvTracker]: Cannot activate CSV tracker, dont have odometry");
    return false;
  }

  last_position_cmd = *cmd;

  tracking_idx = 0;

  position_cmd = *cmd;

  // if we are too far from the initial point
  double distance = sqrt(pow(uav_state.pose.position.x - (x_scale_ * trajectory(0, 0) + x_offset_), 2) + pow(uav_state.pose.position.y - y_offset_, 2) +
                         pow(uav_state.pose.position.z - (z_scale_ * trajectory(0, 1) + z_offset_), 2));

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
    main_timer.start();
  }

  return is_active;
}

//}

/* //{ deactivate() */

void CsvTracker::deactivate(void) {

  ROS_INFO("[CsvTracker]: being deactivated");

  is_active = false;
  odom_set  = false;
  tracking  = false;
}

//}

/* //{ resetStatic() */

bool CsvTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr CsvTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state);

    uav_state = *msg;
  }

  got_odom = true;

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  // calculate the current angle
  double                    odom_roll, odom_pitch, odom_yaw;
  geometry_msgs::Quaternion odom_quat = msg->pose.orientation;
  tf::Quaternion            qt(odom_quat.x, odom_quat.y, odom_quat.z, odom_quat.w);
  tf::Matrix3x3(qt).getRPY(odom_roll, odom_pitch, odom_yaw);

  last_odom_pitch = odom_pitch;

  mrs_msgs::PositionCommand::ConstPtr out;

  {
    std::scoped_lock lock(mutex_position_cmd);

    out = mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd));
  }

  return out;
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus CsvTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = callbacks_enabled;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

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

/* switchOdometrySource() //{ */

void CsvTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &msg) {
  // TODO
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr CsvTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsSrvResponse::Ptr();
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr CsvTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goTo() topic */

bool CsvTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceConstPtr &msg) {
  return false;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr CsvTracker::goToRelative([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Float64SrvResponse::ConstPtr CsvTracker::goToAltitude([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYaw() service */

const mrs_msgs::Float64SrvResponse::ConstPtr CsvTracker::setYaw([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {
  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Float64SrvResponse::ConstPtr CsvTracker::setYawRelative([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {
  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ start_callback() */

bool CsvTracker::start_callback([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  res.success = true;
  res.message = "started";

  return true;
}

//}

/* //{ setInitPoint() */

void CsvTracker::setInitPoint(void) {

  mrs_msgs::TrackerTrajectorySrv trajectory_service;

  // publish the first point as a trajectory
  mrs_msgs::TrackerTrajectory init_trajectory;

  init_trajectory.header.stamp    = ros::Time::now();
  init_trajectory.header.frame_id = uav_state.header.frame_id;
  init_trajectory.fly_now         = false;
  init_trajectory.use_yaw         = true;  // TODO

  mrs_msgs::TrackerPoint point;
  point.x   = x_scale_ * trajectory(0, 0) + x_offset_;
  point.y   = y_offset_;
  point.z   = z_scale_ * trajectory(0, 1) + z_offset_;
  point.yaw = yaw_;

  init_trajectory.points.push_back(point);

  trajectory_service.request.trajectory_msg = init_trajectory;

  /* publisher_trajectory_.publish(init_trajectory); */

  service_client_set_trajectory.call(trajectory_service);

  if (!trajectory_service.response.success) {

    ROS_ERROR("[CsvTracker]: service for setting trajectory failed");
    ROS_ERROR("[CsvTracker]: %.s", trajectory_service.response.message.c_str());
  }

  ROS_INFO("[CsvTracker]: Publishing the first point to the MPC tracker");
}

//}

/* //{ setXYScale() */

bool CsvTracker::setXScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res) {

  if (req.value >= 0 && req.value <= 1.0) {

    x_scale_ = req.value;

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

/* //{ setYScale() */

bool CsvTracker::setYScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res) {

  if (req.value >= 0 && req.value <= 1.0) {

    y_scale_ = req.value;

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

/* //{ setZScale() */

bool CsvTracker::setZScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res) {

  if (req.value >= 0 && req.value <= 1.0) {

    z_scale_ = req.value;

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

/* //{ setScales() */

bool CsvTracker::setScales(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res) {

  if (req.value >= 0 && req.value <= 1.0) {

    x_scale_ = req.value;
    y_scale_ = req.value;
    z_scale_ = req.value;

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

// | ------------------------- timers ------------------------- |

/* //{ mainTimer() */

void CsvTracker::mainTimer(const ros::TimerEvent &event) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("mainTimer", 100, 0.005, event);

  if (!got_odom) {

    ROS_WARN_THROTTLE(1.0, "[CsvTracker]: Waiting for odometry");
    return;
  }

  if (!tracking) {
    ROS_INFO_THROTTLE(1.0, "[CsvTracker]: waiting for activation");
    return;
  }

  {
    std::scoped_lock lock(mutex_position_cmd);

    // set the message according to the file
    position_cmd.header.stamp    = ros::Time::now();
    position_cmd.header.frame_id = uav_state.header.frame_id;

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

    position_cmd.use_position_vertical   = 1;
    position_cmd.use_position_horizontal = 1;
    position_cmd.use_yaw                 = 1;
    position_cmd.use_velocity_vertical   = 1;
    position_cmd.use_velocity_horizontal = 1;
    position_cmd.use_acceleration        = 1;
  }

  // debugging current pitch
  mrs_msgs::Float64 odom_pitch_msg;
  odom_pitch_msg.value = last_odom_pitch;

  // debugging desired pitch
  mrs_msgs::Float64 desired_pitch_msg;
  desired_pitch_msg.value = -trajectory(tracking_idx, 6);

  // debugging desired zd
  mrs_msgs::Float64 desired_zd_msg;
  desired_zd_msg.value = trajectory(tracking_idx, 3);

  // debugging desired xd
  mrs_msgs::Float64 desired_xd_msg;
  desired_xd_msg.value = trajectory(tracking_idx, 2);

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
  mrs_msgs::Float64 desired_thrust_msg;
  desired_thrust_msg.value = trajectory(tracking_idx, 7) / 34.3233;

  publisher_desired_thrust_.publish(desired_thrust_msg);

  if (tracking_idx < (trajectory_len - 1)) {

    tracking_idx = tracking_idx + 1;

  } else {

    ROS_INFO_THROTTLE(1, "[CsvTracker]: Trajectory has finished, switching to Mpctracker");

    mrs_msgs::String SwitchTracker;
    SwitchTracker.request.value = "MpcTracker";
    service_switch_tracker.call(SwitchTracker);

    tracking = false;

    main_timer.stop();
  }
}

//}

/* //{ setTrajTimer() */

void CsvTracker::setTrajTimer(const ros::TimerEvent &event) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("setTrajTimer", 100, 0.005, event);

  ros::Duration(5.0).sleep();

  ROS_INFO("[CsvTracker]: Setting trajectory in the Timer");

  setInitPoint();

  set_traj_timer.stop();
}

//}

}  // namespace csv_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::csv_tracker::CsvTracker, mrs_uav_manager::Tracker)
