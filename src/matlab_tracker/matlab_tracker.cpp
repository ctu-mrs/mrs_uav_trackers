#define VERSION "1.0.4.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <nav_msgs/Odometry.h>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/attitude_converter.h>

#include <mrs_msgs/VelocityReferenceSrv.h>
//}

/* defines //{ */

#define STOP_THR 1e-3

//}

namespace mrs_uav_trackers
{

namespace matlab_tracker
{

/* //{ class MatlabTracker */

class MatlabTracker : public mrs_uav_managers::Tracker {
public:
  ~MatlabTracker(){};

  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers);
  std::tuple<bool, std::string> activate(const mrs_msgs::TrackerCommand::ConstPtr &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  const mrs_msgs::TrackerCommand::ConstPtr  update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr   setVelocityReference(const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd);

  const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  ros::NodeHandle nh_;

  bool callbacks_enabled_ = true;

  std::string _version_;

  bool is_initialized_ = false;
  bool is_active_      = false;

  std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_;

  // | ------------------------ the goal ------------------------ |

  mrs_lib::SubscribeHandler<nav_msgs::Odometry> sh_goal_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler;
  bool              _profiler_enabled_ = false;

  // | ------------------- the tracker's ouput ------------------ |

  bool _position_mode_ = false;
  bool _tilt_mode_     = false;

  mrs_msgs::TrackerCommand position_output_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void MatlabTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                               std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers) {

  this->common_handlers_ = common_handlers;

  nh_ = ros::NodeHandle(parent_nh, "matlab_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "MatlabTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[MatlabTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("enable_profiler", _profiler_enabled_);
  param_loader.loadParam("position_mode", _position_mode_);
  param_loader.loadParam("tilt_mode", _tilt_mode_);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[MatlabTracker]: could not load all parameters!");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler = mrs_lib::Profiler(nh_, "matlabtracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  /* subscriber_matlab_ = nh_.subscribe("goal_in", 1, &MatlabTracker::callbackMatlab, this, ros::TransportHints().tcpNoDelay()); */

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "MatlabTracker";
  shopts.threadsafe      = true;
  shopts.autostart       = true;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_goal_ = mrs_lib::SubscribeHandler<nav_msgs::Odometry>(shopts, "goal_in");

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[MatlabTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> MatlabTracker::activate([[maybe_unused]] const mrs_msgs::TrackerCommand::ConstPtr &last_tracker_cmd) {

  std::stringstream ss;

  if (!sh_goal_.hasMsg()) {
    ss << "missing Matlab command";
    return std::tuple(false, ss.str());
  }

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[MatlabTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void MatlabTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[MatlabTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool MatlabTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::TrackerCommand::ConstPtr MatlabTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                               [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("MatlabTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::TrackerCommand::Ptr();
  }

  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state->header.frame_id;

  nav_msgs::OdometryConstPtr goal = sh_goal_.getMsg();

  if (_position_mode_) {

    position_output_.position.x = goal->pose.pose.position.x;
    position_output_.position.y = goal->pose.pose.position.y;
    position_output_.position.z = goal->pose.pose.position.z;

    position_output_.velocity.x = goal->twist.twist.linear.x;
    position_output_.velocity.y = goal->twist.twist.linear.y;
    position_output_.velocity.z = goal->twist.twist.linear.z;

    position_output_.acceleration.x = goal->twist.twist.angular.x;
    position_output_.acceleration.y = goal->twist.twist.angular.y;
    position_output_.acceleration.z = goal->twist.twist.angular.z;

    position_output_.heading      = goal->pose.pose.orientation.x;
    position_output_.heading_rate = goal->pose.pose.orientation.y;

    position_output_.use_heading             = 1;
    position_output_.use_heading_rate        = 1;
    position_output_.use_position_vertical   = 1;
    position_output_.use_position_horizontal = 1;
    position_output_.use_velocity_vertical   = 1;
    position_output_.use_velocity_horizontal = 1;
    position_output_.use_acceleration        = 1;
  }

  if (_tilt_mode_) {

    position_output_.position.z            = goal->pose.pose.position.z;
    position_output_.use_position_vertical = 1;

    position_output_.orientation     = mrs_lib::AttitudeConverter(goal->pose.pose.orientation);
    position_output_.use_orientation = 1;
  }

  return mrs_msgs::TrackerCommand::ConstPtr(new mrs_msgs::TrackerCommand(position_output_));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus MatlabTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr MatlabTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[MatlabTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[MatlabTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr MatlabTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr MatlabTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::DynamicsConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr MatlabTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr MatlabTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr MatlabTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

}  // namespace matlab_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::matlab_tracker::MatlabTracker, mrs_uav_managers::Tracker)
