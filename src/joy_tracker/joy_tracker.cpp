#define VERSION "0.0.5.0"

/* includes //{ */

#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>

#include <mrs_msgs/Reference.h>
#include <mrs_uav_manager/Tracker.h>
#include <mrs_msgs/UavState.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>
#include <mrs_lib/mutex.h>

//}

#define STOP_THR 1e-3

namespace mrs_trackers
{

namespace joy_tracker
{

/* //{ class JoyTracker */

class JoyTracker : public mrs_uav_manager::Tracker {
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

  virtual bool goTo(const mrs_msgs::ReferenceConstPtr &msg);

  virtual const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers_;
  bool                                               callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

private:
  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  double uav_x_;
  double uav_y_;
  double uav_z_;
  double uav_yaw_;
  double uav_roll_;
  double uav_pitch_;

private:
  // tracker's inner states
  double _tracker_loop_rate_;
  double _tracker_dt_;
  bool   is_initialized_ = false;
  bool   is_active_      = false;
  bool   first_iter_     = false;

private:
  void       mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer_;

private:
  // dynamical constraints
  double     _yaw_rate_;
  std::mutex mutex_constraints_;

private:
  // desired goal
  double got_joystick_ = false;

  // my current state
  double     state_z_;
  double     state_yaw_;
  double     speed_yaw_;
  double     current_heading_;
  double     desired_vertical_speed_ = 0;
  double     desired_yaw_rate_       = 0;
  double     desired_pitch_          = 0;
  double     desired_roll_           = 0;
  double     current_horizontal_acceleration_;
  double     current_vertical_acceleration;
  std::mutex mutex_state_;

private:
  ros::Subscriber subscriber_joystick_;
  void            callbackJoystick(const sensor_msgs::Joy &msg);
  double          _max_tilt_;
  double          _vertical_speed_;

  // channel numbers and channel multipliers
  int _channel_pitch_;
  int _channel_roll_;
  int _channel_yaw_;
  int _channel_thrust_;
  int _channel_mult_pitch_;
  int _channel_mult_roll_;
  int _channel_mult_yaw_;
  int _channel_mult_thrust_;

private:
  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void JoyTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  ros::NodeHandle nh_(parent_nh, "joy_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "JoyTracker");

  param_loader.load_param("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[JoyTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.load_param("enable_profiler", _profiler_enabled_);

  param_loader.load_param("vertical_tracker/vertical_speed", _vertical_speed_);

  param_loader.load_param("tracker_loop_rate", _tracker_loop_rate_);
  param_loader.load_param("max_tilt", _max_tilt_);

  param_loader.load_param("yaw_tracker/yaw_rate", _yaw_rate_);

  // load channels
  param_loader.load_param("channels/pitch", _channel_pitch_);
  param_loader.load_param("channels/roll", _channel_roll_);
  param_loader.load_param("channels/yaw", _channel_yaw_);
  param_loader.load_param("channels/thrust", _channel_thrust_);

  // load channel multipliers
  param_loader.load_param("channel_multipliers/pitch", _channel_mult_pitch_);
  param_loader.load_param("channel_multipliers/roll", _channel_mult_roll_);
  param_loader.load_param("channel_multipliers/yaw", _channel_mult_yaw_);
  param_loader.load_param("channel_multipliers/thrust", _channel_mult_thrust_);

  _tracker_dt_ = 1.0 / double(_tracker_loop_rate_);

  ROS_INFO("[JoyTracker]: tracker_dt: %f", _tracker_dt_);

  // --------------------------------------------------------------
  // |                          profiler_                          |
  // --------------------------------------------------------------

  profiler_ = mrs_lib::Profiler(nh_, "joytracker", _profiler_enabled_);

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  subscriber_joystick_ = nh_.subscribe("joystick_in", 1, &JoyTracker::callbackJoystick, this, ros::TransportHints().tcpNoDelay());

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer_ = nh_.createTimer(ros::Rate(_tracker_loop_rate_), &JoyTracker::mainTimer, this);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[JoyTracker]: could not load all parameters!");
    ros::shutdown();
  }

  is_initialized_ = true;

  ROS_INFO("[JoyTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

bool JoyTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_uav_state_) {

    ROS_ERROR("[JoyTracker]: can not activate(), odometry not set");
    return false;
  }

  if (!got_joystick_) {

    ROS_ERROR("[JoyTracker]: can not activate(), missing joystick goal");
    return false;
  }

  auto [uav_state, uav_yaw] = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_, uav_yaw_);

  // initialized the yaw and z from the last tracker command / odometry
  {
    std::scoped_lock lock(mutex_state_);

    if (mrs_msgs::PositionCommand::Ptr() != cmd) {

      // the last command is usable
      state_z_   = cmd->position.z;
      state_yaw_ = cmd->yaw;

    } else {

      state_z_   = uav_state.pose.position.z;
      state_yaw_ = uav_yaw;

      ROS_WARN("[JoyTracker]: the previous command is not usable for activation, using Odometry instead");
    }
  }

  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  is_active_ = true;

  ROS_INFO("[JoyTracker]: activated");

  return true;
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

const mrs_msgs::PositionCommand::ConstPtr JoyTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &cmd) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = *msg;
    uav_x_     = uav_state_.pose.position.x;
    uav_y_     = uav_state_.pose.position.y;
    uav_z_     = uav_state_.pose.position.z;

    // calculate the euler angles
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(uav_state_.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(uav_roll_, uav_pitch_, uav_yaw_);

    got_uav_state_ = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto [state_z, desired_vertical_speed, desired_pitch, desired_roll, state_yaw, desired_yaw_rate] =
      mrs_lib::get_mutexed(mutex_state_, state_z_, desired_vertical_speed_, desired_pitch_, desired_roll_, state_yaw_, desired_yaw_rate_);

  mrs_msgs::PositionCommand position_cmd;

  position_cmd.header.stamp    = ros::Time::now();
  position_cmd.header.frame_id = uav_state.header.frame_id;

  position_cmd.use_position_horizontal = true;
  position_cmd.use_position_vertical   = true;
  position_cmd.position.x              = uav_state.pose.position.x;
  position_cmd.position.y              = uav_state.pose.position.y;
  position_cmd.position.z              = state_z;

  position_cmd.use_yaw = 1;
  position_cmd.yaw     = state_yaw;

  position_cmd.use_velocity_horizontal = true;
  position_cmd.use_velocity_vertical   = true;
  position_cmd.velocity.x              = uav_state.velocity.linear.x;
  position_cmd.velocity.y              = uav_state.velocity.linear.y;
  position_cmd.velocity.z              = desired_vertical_speed;

  position_cmd.use_yaw_dot = 1;
  position_cmd.yaw_dot     = desired_yaw_rate;

  position_cmd.acceleration.x = 0;
  position_cmd.acceleration.y = 0;
  position_cmd.acceleration.z = 0;

  tf::Quaternion desired_orientation;

  desired_orientation = tf::createQuaternionFromRPY(-desired_roll, desired_pitch, state_yaw);

  position_cmd.use_quat_attitude = 1;
  position_cmd.attitude.w        = desired_orientation.getW();
  position_cmd.attitude.x        = desired_orientation.getX();
  position_cmd.attitude.y        = desired_orientation.getY();
  position_cmd.attitude.z        = desired_orientation.getZ();

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

void JoyTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &msg) {
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr JoyTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr JoyTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsSrvResponse::Ptr();
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr JoyTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goTo() topic */

bool JoyTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceConstPtr &msg) {

  return false;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr JoyTracker::goToRelative([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Float64SrvResponse::ConstPtr JoyTracker::goToAltitude([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYaw() service */

const mrs_msgs::Float64SrvResponse::ConstPtr JoyTracker::setYaw([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Float64SrvResponse::ConstPtr JoyTracker::setYawRelative([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

// | ------------------------- timers ------------------------- |

/* //{ mainTimer() */

void JoyTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active_) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("main", _tracker_loop_rate_, 0.002, event);

  {
    std::scoped_lock lock(mutex_state_);

    // --------------------------------------------------------------
    // |                       height tracking                      |
    // --------------------------------------------------------------

    state_z_ += desired_vertical_speed_ * _tracker_dt_;

    // --------------------------------------------------------------
    // |                        yaw tracking                        |
    // --------------------------------------------------------------

    // flap the resulted state_yaw_ aroud PI
    state_yaw_ += desired_yaw_rate_ * _tracker_dt_;

    if (state_yaw_ > PI) {
      state_yaw_ -= 2 * PI;
    } else if (state_yaw_ < -PI) {
      state_yaw_ += 2 * PI;
    }
  }
}

//}

// | --------------------- custom methods --------------------- |

/* callbackJoystick() //{ */

void JoyTracker::callbackJoystick(const sensor_msgs::Joy &msg) {

  if (!is_initialized_)
    return;

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("callbackJoystick");

  // TODO check the size of the array

  {
    std::scoped_lock lock(mutex_state_);

    desired_vertical_speed_ = _channel_mult_thrust_ * msg.axes[_channel_thrust_] * _vertical_speed_;
    desired_yaw_rate_       = _channel_mult_yaw_ * msg.axes[_channel_yaw_] * _yaw_rate_;
    desired_pitch_          = _channel_mult_pitch_ * msg.axes[_channel_pitch_] * _max_tilt_;
    desired_roll_           = _channel_mult_roll_ * msg.axes[_channel_roll_] * _max_tilt_;

    got_joystick_ = true;

    ROS_INFO_THROTTLE(1.0, "[JoyTracker]: desired vert_speed: %.2f, yaw_rate: %.2f, pitch: %.2f, roll: %.2f", desired_vertical_speed_, desired_yaw_rate_,
                      desired_pitch_, desired_roll_);
  }
}

//}

}  // namespace joy_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::joy_tracker::JoyTracker, mrs_uav_manager::Tracker)
