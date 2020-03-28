#define VERSION "0.0.5.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_manager/Tracker.h>

#include <nav_msgs/Odometry.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>
#include <mrs_lib/mutex.h>

//}

#define STOP_THR 1e-3

namespace mrs_trackers
{

namespace matlab_tracker
{

/* //{ class MatlabTracker */

class MatlabTracker : public mrs_uav_manager::Tracker {
public:
  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers_);
  bool activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd);
  void deactivate(void);
  bool resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd);

  const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled_ = true;

  std::string _version_;

  bool is_initialized_ = false;
  bool is_active_      = false;
  bool first_iter_     = false;


  // | ------------------------ the goal ------------------------ |

  double             have_goal_ = false;
  std::mutex         mutex_goal_;
  nav_msgs::Odometry matlab_goal_;

  ros::Subscriber subscriber_matlab_;
  void            callbackMatlab(const nav_msgs::Odometry &msg);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler;
  bool              _profiler_enabled_ = false;

  // | ------------------- the tracker's ouput ------------------ |

  bool _position_mode_ = false;
  bool _tilt_mode_     = false;

  mrs_msgs::PositionCommand position_output_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void MatlabTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                               [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers_) {

  ros::NodeHandle nh_(parent_nh, "matlab_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "MatlabTracker");

  param_loader.load_param("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[MatlabTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.load_param("enable_profiler", _profiler_enabled_);
  param_loader.load_param("position_mode", _position_mode_);
  param_loader.load_param("tilt_mode", _tilt_mode_);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[MatlabTracker]: could not load all parameters!");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler = mrs_lib::Profiler(nh_, "matlabtracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  subscriber_matlab_ = nh_.subscribe("goal_in", 1, &MatlabTracker::callbackMatlab, this, ros::TransportHints().tcpNoDelay());

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[MatlabTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

bool MatlabTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  if (!have_goal_) {

    ROS_ERROR("[MatlabTracker]: can not activate, missing Matlab command");
    return false;
  }

  is_active_ = true;

  ROS_INFO("[MatlabTracker]: activated");

  return true;
}

//}

/* //{ deactivate() */

void MatlabTracker::deactivate(void) {

  is_active_ = false;
  have_goal_ = false;

  ROS_INFO("[MatlabTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool MatlabTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr MatlabTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                                [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state->header.frame_id;

  {
    std::scoped_lock lock(mutex_goal_);

    if (_position_mode_) {

      position_output_.position.x = matlab_goal_.pose.pose.position.x;
      position_output_.position.y = matlab_goal_.pose.pose.position.y;
      position_output_.position.z = matlab_goal_.pose.pose.position.z;

      position_output_.velocity.x = matlab_goal_.twist.twist.linear.x;
      position_output_.velocity.y = matlab_goal_.twist.twist.linear.y;
      position_output_.velocity.z = matlab_goal_.twist.twist.linear.z;

      position_output_.acceleration.x = matlab_goal_.twist.twist.angular.x;
      position_output_.acceleration.y = matlab_goal_.twist.twist.angular.y;
      position_output_.acceleration.z = matlab_goal_.twist.twist.angular.z;

      position_output_.yaw     = matlab_goal_.pose.pose.orientation.x;
      position_output_.yaw_dot = matlab_goal_.pose.pose.orientation.y;

      position_output_.use_yaw                 = 1;
      position_output_.use_yaw_dot             = 1;
      position_output_.use_position_vertical   = 1;
      position_output_.use_position_horizontal = 1;
      position_output_.use_velocity_vertical   = 1;
      position_output_.use_velocity_horizontal = 1;
      position_output_.use_acceleration        = 1;
    }

    if (_tilt_mode_) {

      position_output_.position.x = uav_state->pose.position.x;
      position_output_.position.y = uav_state->pose.position.x;
      position_output_.position.z = matlab_goal_.pose.pose.position.z;

      position_output_.velocity.x = uav_state->velocity.linear.x;
      position_output_.velocity.y = uav_state->velocity.linear.y;
      position_output_.velocity.z = uav_state->velocity.linear.z;

      position_output_.acceleration.x = 0;
      position_output_.acceleration.y = 0;
      position_output_.acceleration.z = 0;

      position_output_.use_quat_attitude       = 1;
      position_output_.use_position_vertical   = 1;
      position_output_.use_position_horizontal = 1;
    }
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output_));
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

void MatlabTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {
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

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr MatlabTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr MatlabTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr MatlabTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | --------------------- custom methods --------------------- |

/* callbackMatlab() //{ */

void MatlabTracker::callbackMatlab(const nav_msgs::Odometry &msg) {

  if (!is_initialized_)
    return;

  std::scoped_lock lock(mutex_goal_);

  mrs_lib::Routine profiler_routine = profiler.createRoutine("callbackMatlab");

  matlab_goal_ = msg;

  have_goal_ = true;
}

//}

}  // namespace matlab_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::matlab_tracker::MatlabTracker, mrs_uav_manager::Tracker)
