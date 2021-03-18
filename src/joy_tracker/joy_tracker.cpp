#define VERSION "1.0.0.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/geometry/cyclic.h>

//}

/* defines //{ */

#define STOP_THR 1e-3

//}

/* using //{ */

using vec2_t = mrs_lib::geometry::vec_t<2>;
using vec3_t = mrs_lib::geometry::vec_t<3>;

using radians  = mrs_lib::geometry::radians;
using sradians = mrs_lib::geometry::sradians;

//}

namespace mrs_uav_trackers
{

namespace joy_tracker
{

/* //{ class JoyTracker */

class JoyTracker : public mrs_uav_managers::Tracker {
public:
  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers);
  std::tuple<bool, std::string> activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd);

  const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_;
  bool                                                callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

  bool is_initialized_ = false;
  bool is_active_      = false;

  ros::Time last_update;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ------------------ dynamics constraints ------------------ |

  double     _heading_rate_;
  std::mutex mutex_constraints_;

  // | ------------------ tracker's inner state ----------------- |

  double     state_z_;
  double     state_heading_;
  double     speed_heading_;
  double     current_heading_;
  double     current_horizontal_acceleration_;
  double     current_vertical_acceleration;
  std::mutex mutex_state_;

  // | ------------------- joystick subscriber ------------------ |

  mrs_lib::SubscribeHandler<sensor_msgs::Joy> sh_joystick_;

  double _max_tilt_;
  double _vertical_speed_;

  // channel numbers and channel multipliers
  int _channel_pitch_;
  int _channel_roll_;
  int _channel_heading_;
  int _channel_thrust_;
  int _channel_mult_pitch_;
  int _channel_mult_roll_;
  int _channel_mult_heading_;
  int _channel_mult_thrust_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void JoyTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  ros::NodeHandle nh_(parent_nh, "joy_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "JoyTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[JoyTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("enable_profiler", _profiler_enabled_);

  param_loader.loadParam("vertical_tracker/vertical_speed", _vertical_speed_);

  param_loader.loadParam("max_tilt", _max_tilt_);

  param_loader.loadParam("heading_tracker/heading_rate", _heading_rate_);

  // load channels
  param_loader.loadParam("channels/pitch", _channel_pitch_);
  param_loader.loadParam("channels/roll", _channel_roll_);
  param_loader.loadParam("channels/heading", _channel_heading_);
  param_loader.loadParam("channels/thrust", _channel_thrust_);

  // load channel multipliers
  param_loader.loadParam("channel_multipliers/pitch", _channel_mult_pitch_);
  param_loader.loadParam("channel_multipliers/roll", _channel_mult_roll_);
  param_loader.loadParam("channel_multipliers/heading", _channel_mult_heading_);
  param_loader.loadParam("channel_multipliers/thrust", _channel_mult_thrust_);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[JoyTracker]: could not load all parameters!");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(nh_, "JoyTracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "JoyTracker";
  shopts.queue_size      = 1;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_joystick_ = mrs_lib::SubscribeHandler<sensor_msgs::Joy>(shopts, "joystick_in");

  // | --------------------- finish the init -------------------- |

  last_update = ros::Time(0);

  is_initialized_ = true;

  ROS_INFO("[JoyTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> JoyTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {

    ss << "odometry not set";
    return std::tuple(false, ss.str());
  }

  if (!sh_joystick_.hasMsg()) {

    ss << "missing joystick goal";
    return std::tuple(false, ss.str());
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[JoyTracker]: could not calculate UAV heading");
  }

  // initialized the heading and z from the last tracker command / odometry
  {
    std::scoped_lock lock(mutex_state_);

    if (mrs_msgs::PositionCommand::Ptr() != last_position_cmd) {

      // the last command is usable
      state_z_       = last_position_cmd->position.z;
      state_heading_ = last_position_cmd->heading;

    } else {

      state_z_       = uav_state.pose.position.z;
      state_heading_ = uav_heading;

      ROS_WARN("[JoyTracker]: the previous command is not usable for activation, using Odometry instead");
    }
  }

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[JoyTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void JoyTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[JoyTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool JoyTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr JoyTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = *uav_state;

    got_uav_state_ = true;
  }

  double dt = (ros::Time::now() - last_update).toSec();

  last_update = ros::Time::now();

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  if (!sh_joystick_.hasMsg()) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  // | ------------------ get the joystick data ----------------- |

  sensor_msgs::JoyConstPtr joy_data = sh_joystick_.getMsg();

  double desired_vertical_speed = _channel_mult_thrust_ * joy_data->axes[_channel_thrust_] * _vertical_speed_;
  double desired_heading_rate   = _channel_mult_heading_ * joy_data->axes[_channel_heading_] * _heading_rate_;
  double desired_pitch          = _channel_mult_pitch_ * joy_data->axes[_channel_pitch_] * _max_tilt_;
  double desired_roll           = _channel_mult_roll_ * joy_data->axes[_channel_roll_] * _max_tilt_;

  // | --------------------- height tracking -------------------- |

  state_z_ += desired_vertical_speed * dt;

  // | -------------------- heading tracking -------------------- |

  state_heading_ += desired_heading_rate * dt;
  state_heading_ = radians::wrap(state_heading_);

  ROS_INFO_THROTTLE(1.0, "[JoyTracker]: desired vert_speed: %.2f, heading_speed: %.2f, pitch: %.2f, roll: %.2f", desired_vertical_speed, desired_heading_rate,
                    desired_pitch, desired_roll);

  mrs_msgs::PositionCommand position_cmd;

  position_cmd.header.stamp    = ros::Time::now();
  position_cmd.header.frame_id = uav_state->header.frame_id;

  position_cmd.use_position_vertical = true;
  position_cmd.position.z            = state_z_;

  // filling these anyway to allow visualization of the reference
  position_cmd.position.x = uav_state->pose.position.x;
  position_cmd.position.y = uav_state->pose.position.y;

  position_cmd.use_velocity_vertical = true;
  position_cmd.velocity.z            = desired_vertical_speed;

  position_cmd.use_heading_rate = 1;
  position_cmd.heading_rate     = desired_heading_rate;

  /* position_cmd.orientation     = mrs_lib::AttitudeConverter(desired_roll, desired_pitch, 0).setHeadingByYaw(state_heading_); */
  position_cmd.orientation     = mrs_lib::AttitudeConverter(desired_roll, desired_pitch, state_heading_);
  position_cmd.use_orientation = true;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus JoyTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr JoyTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[JoyTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[JoyTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr JoyTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::DynamicsConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr JoyTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr JoyTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

}  // namespace joy_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::joy_tracker::JoyTracker, mrs_uav_managers::Tracker)
