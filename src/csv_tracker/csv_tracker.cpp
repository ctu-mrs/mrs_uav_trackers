#define VERSION "0.0.5.1"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_msgs/TrajectoryReferenceSrv.h>
#include <mrs_msgs/String.h>

#include <mrs_msgs/Float64Stamped.h>

#include <fstream>
#include <iostream>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>

//}

/* using //{ */

using namespace Eigen;

//}

namespace mrs_uav_trackers
{

namespace csv_tracker
{

/* //{ class CsvTracker */

class CsvTracker : public mrs_uav_managers::Tracker {
public:
  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_);
  std::tuple<bool, std::string> activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr &cmd);

  const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd);

private:
  bool callbackStart(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

  bool setXScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setYScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setZScale(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  bool setScales(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);

  void setInitPoint(void);

  bool callbacks_enabled_ = true;

  ros::NodeHandle                                     nh_;
  std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_;

  mrs_msgs::UavState uav_state_;
  std::mutex         mutex_uav_state_;

  ros::Time odometry_last_time_;

  ros::Timer timer_main_;
  ros::Timer timer_set_trajectory_;

  mrs_msgs::PositionCommand position_cmd_;
  mrs_msgs::PositionCommand last_position_cmd_;
  std::mutex                mutex_position_cmd_;

  // service servers
  ros::ServiceServer service_server_start_;

  // service clients
  ros::ServiceClient service_client_switch_tracker_;

  ros::ServiceClient service_client_set_trajectory_;
  ros::ServiceServer service_server_set_trajectory_;

  ros::ServiceServer ser_x_scale_;
  ros::ServiceServer ser_y_scale_;
  ros::ServiceServer ser_z_scale_;
  ros::ServiceServer ser_scales_;

  bool is_active_     = false;
  bool is_initialized = false;

  // for tracking
  bool     tracking_     = false;
  int      tracking_idx_ = 0;
  MatrixXd trajectory_;
  int      trajectory_len_ = 0;

  // methods
  void timerMain(const ros::TimerEvent &event);
  void timerSetTrajectory(const ros::TimerEvent &event);

  // params
  std::string _filename_;
  std::string _version_;
  std::string _uav_name_;

  double _x_offset_ = 0;
  double _y_offset_ = 0;
  double _z_offset_ = 0;

  double x_scale_ = 1;
  double y_scale_ = 1;
  double z_scale_ = 1;

  double _heading_ = 0;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | ------------------- tracker's interface ------------------ |

/* //{ initialize() */

void CsvTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  ros::NodeHandle nh_(parent_nh, "csv_tracker");

  ros::Time::waitForValid();

  mrs_lib::ParamLoader param_loader(nh_, "CsvTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[CsvTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("filename", _filename_);
  param_loader.loadParam("enable_profiler", _profiler_enabled_);

  // posX posY vx vy ax ay theta thrust release
  trajectory_ = MatrixXd::Zero(5000, 9);

  std::ifstream in(_filename_.c_str(), std::ifstream::in);

  if (!in) {

    ROS_ERROR("[CsvTracker]: cannot open '%s'", _filename_.c_str());
    ros::shutdown();
    return;

  } else {

    ROS_INFO("[CsvTracker]: loading from file: %s", _filename_.c_str());
    std::string line;

    while (getline(in, line)) {

      std::istringstream s(line);

      s >> trajectory_(trajectory_len_, 0);
      s >> trajectory_(trajectory_len_, 1);
      s >> trajectory_(trajectory_len_, 2);
      s >> trajectory_(trajectory_len_, 3);
      s >> trajectory_(trajectory_len_, 4);
      s >> trajectory_(trajectory_len_, 5);
      s >> trajectory_(trajectory_len_, 6);
      s >> trajectory_(trajectory_len_, 7);
      s >> trajectory_(trajectory_len_, 8);

      ROS_INFO("[CsvTracker]: %.2f %.2f", trajectory_(trajectory_len_, 0), trajectory_(trajectory_len_, 1));

      trajectory_len_++;
    }

    in.close();

    ROS_INFO("[CsvTracker]: trajectory loaded, len = %d", trajectory_len_);
  }

  service_client_switch_tracker_ = nh_.serviceClient<mrs_msgs::String>("switch_tracker_out");
  service_client_set_trajectory_ = nh_.serviceClient<mrs_msgs::TrajectoryReferenceSrv>("trajectory_reference_out");

  ser_x_scale_ = nh_.advertiseService("set_x_scale_in", &CsvTracker::setXScale, this);
  ser_y_scale_ = nh_.advertiseService("set_y_scale_in", &CsvTracker::setYScale, this);
  ser_z_scale_ = nh_.advertiseService("set_z_scale_in", &CsvTracker::setZScale, this);
  ser_scales_  = nh_.advertiseService("set_scales_in", &CsvTracker::setScales, this);

  // load params
  param_loader.loadParam("offset/x", _x_offset_);
  param_loader.loadParam("offset/y", _y_offset_);
  param_loader.loadParam("offset/z", _z_offset_);

  param_loader.loadParam("scale/x", x_scale_);
  param_loader.loadParam("scale/y", y_scale_);
  param_loader.loadParam("scale/z", z_scale_);

  param_loader.loadParam("heading", _heading_);

  ROS_WARN("[CsvTracker]: offset/x: %.2f", _x_offset_);
  ROS_WARN("[CsvTracker]: offset/y: %.2f", _y_offset_);
  ROS_WARN("[CsvTracker]: offset/z: %.2f", _z_offset_);
  ROS_WARN("[CsvTracker]: scale/x: %.2f", x_scale_);
  ROS_WARN("[CsvTracker]: scale/y: %.2f", y_scale_);
  ROS_WARN("[CsvTracker]: scale/z: %.2f", z_scale_);
  ROS_WARN("[CsvTracker]: heading: %.2f", _heading_);

  if (x_scale_ > 1 || y_scale_ > 1 || z_scale_ > 1) {
    ROS_ERROR("[CsvTracker]: scales are greater than 1");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(nh_, "CsvTracker", _profiler_enabled_);

  // | ------------------------- timers ------------------------- |

  timer_main_           = nh_.createTimer(ros::Rate(100), &CsvTracker::timerMain, this, false, false);
  timer_set_trajectory_ = nh_.createTimer(ros::Rate(1), &CsvTracker::timerSetTrajectory, this);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[CsvTracker]: could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[CsvTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> CsvTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  last_position_cmd_ = *last_position_cmd;

  tracking_idx_ = 0;

  position_cmd_ = *last_position_cmd;

  // if we are too far from the initial point
  double distance = sqrt(pow(uav_state_.pose.position.x - (x_scale_ * trajectory_(0, 0) + _x_offset_), 2) + pow(uav_state_.pose.position.y - _y_offset_, 2) +
                         pow(uav_state_.pose.position.z - (z_scale_ * trajectory_(0, 1) + _z_offset_), 2));

  ROS_INFO("[CsvTracker]: distance: %.2f", distance);
  ROS_INFO("[CsvTracker]: z_start: %.2f", z_scale_ * trajectory_(0, 1) + _z_offset_);
  ROS_INFO("[CsvTracker]: z_scale: %.2f", z_scale_);

  std::stringstream ss;

  if (distance > 1.0) {

    ss << "cannon activate, too far from the initial point!";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[CsvTracker]: " << ss.str());

    is_active_ = false;

  } else {

    ss << "activated";
    ROS_INFO_STREAM("[CsvTracker]: " << ss.str());

    is_active_ = true;
    tracking_  = true;
    timer_main_.start();
  }

  return std::tuple(is_active_, ss.str());
}

//}

/* //{ deactivate() */

void CsvTracker::deactivate(void) {

  ROS_INFO("[CsvTracker]: deactivated");

  is_active_ = false;
  tracking_  = false;
}

//}

/* //{ resetStatic() */

bool CsvTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr CsvTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = *uav_state;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  mrs_msgs::PositionCommand::ConstPtr out;

  {
    std::scoped_lock lock(mutex_position_cmd_);

    out = mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
  }

  return out;
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus CsvTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  tracker_status.tracking_trajectory = tracking_;
  tracker_status.have_goal           = tracking_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr CsvTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[CsvTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[CsvTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr CsvTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr CsvTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::DynamicsConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr CsvTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr CsvTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ callbackStart() */

bool CsvTracker::callbackStart([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  res.success = true;
  res.message = "started";

  return true;
}

//}

/* //{ setInitPoint() */

void CsvTracker::setInitPoint(void) {

  mrs_msgs::TrajectoryReferenceSrv trajectory_service;

  // publish the first point as a trajectory
  mrs_msgs::TrajectoryReference init_trajectory;

  init_trajectory.header.stamp    = ros::Time::now();
  init_trajectory.header.frame_id = uav_state_.header.frame_id;
  init_trajectory.fly_now         = false;
  init_trajectory.dt              = 1.0;
  init_trajectory.use_heading     = true;  // TODO

  mrs_msgs::Reference point;
  point.position.x = x_scale_ * trajectory_(0, 0) + _x_offset_;
  point.position.y = _y_offset_;
  point.position.z = z_scale_ * trajectory_(0, 1) + _z_offset_;
  point.heading    = _heading_;

  init_trajectory.points.push_back(point);

  trajectory_service.request.trajectory = init_trajectory;

  service_client_set_trajectory_.call(trajectory_service);

  if (!trajectory_service.response.success) {

    ROS_ERROR("[CsvTracker]: service for setting trajectory failed");
    ROS_ERROR("[CsvTracker]: %s", trajectory_service.response.message.c_str());
  }

  ROS_INFO("[CsvTracker]: publishing the first point to the MPC tracker");
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

/* //{ timerMain() */

void CsvTracker::timerMain(const ros::TimerEvent &event) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("timerMain", 100, 0.005, event);

  if (!tracking_) {
    ROS_INFO_THROTTLE(1.0, "[CsvTracker]: waiting for activation");
    return;
  }

  {
    std::scoped_lock lock(mutex_position_cmd_);

    // set the message according to the file
    position_cmd_.header.stamp    = ros::Time::now();
    position_cmd_.header.frame_id = uav_state_.header.frame_id;

    position_cmd_.position.x = x_scale_ * trajectory_(tracking_idx_, 0) + _x_offset_;
    position_cmd_.position.z = z_scale_ * trajectory_(tracking_idx_, 1) + _z_offset_;

    position_cmd_.velocity.x = x_scale_ * trajectory_(tracking_idx_, 2);
    position_cmd_.velocity.z = z_scale_ * trajectory_(tracking_idx_, 3);

    position_cmd_.acceleration.x = x_scale_ * trajectory_(tracking_idx_, 4);
    position_cmd_.acceleration.z = z_scale_ * trajectory_(tracking_idx_, 5);

    position_cmd_.position.y     = _y_offset_;
    position_cmd_.velocity.y     = 0;
    position_cmd_.acceleration.y = 0;

    position_cmd_.heading      = _heading_;
    position_cmd_.heading_rate = 0;

    position_cmd_.use_position_vertical   = 1;
    position_cmd_.use_position_horizontal = 1;
    position_cmd_.use_heading             = 1;
    position_cmd_.use_velocity_vertical   = 1;
    position_cmd_.use_velocity_horizontal = 1;
    position_cmd_.use_acceleration        = 1;
  }

  if (tracking_idx_ < (trajectory_len_ - 1)) {

    tracking_idx_ = tracking_idx_ + 1;

  } else {

    ROS_INFO_THROTTLE(1, "[CsvTracker]: trajectory has finished, switching to Mpctracker");

    mrs_msgs::String SwitchTracker;
    SwitchTracker.request.value = "MpcTracker";
    service_client_switch_tracker_.call(SwitchTracker);

    tracking_ = false;

    timer_main_.stop();
  }
}

//}

/* //{ timerSetTrajectory() */

void CsvTracker::timerSetTrajectory(const ros::TimerEvent &event) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("timerSetTrajectory", 100, 0.01, event);

  ros::Duration(5.0).sleep();

  ROS_INFO("[CsvTracker]: setting trajectory in the timer");

  setInitPoint();

  timer_set_trajectory_.stop();
}

//}

}  // namespace csv_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::csv_tracker::CsvTracker, mrs_uav_managers::Tracker)
