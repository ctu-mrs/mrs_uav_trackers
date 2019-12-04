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

//}

#define STOP_THR 1e-3

namespace mrs_trackers
{

namespace joy_tracker
{

/* //{ class JoyTracker */

class JoyTracker : public mrs_uav_manager::Tracker {
public:
  virtual void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, mrs_uav_manager::CommonHandlers_t const *common_handlers);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

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

  virtual const mrs_msgs::TrackerConstraintsResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  mrs_uav_manager::CommonHandlers_t const *common_handlers;
  bool                                     callbacks_enabled = true;

  std::string uav_name_;

private:
  mrs_msgs::UavState uav_state;
  bool               got_uav_state = false;
  std::mutex         mutex_uav_state;

  double uav_x;
  double uav_y;
  double uav_z;
  double uav_yaw;
  double uav_roll;
  double uav_pitch;

private:
  // tracker's inner states
  int    tracker_loop_rate_;
  double tracker_dt_;
  bool   is_initialized = false;
  bool   is_active      = false;
  bool   first_iter     = false;

private:
  void       mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer;

private:
  // dynamical constraints
  double     yaw_rate_;
  std::mutex mutex_constraints;

private:
  // desired goal
  double     got_goal = false;
  std::mutex mutex_goal;

  // my current state
  double     state_z, state_yaw;
  double     speed_yaw;
  double     current_heading;
  double     current_vertical_speed = 0;
  double     current_yaw_rate       = 0;
  double     desired_pitch          = 0;
  double     desired_roll           = 0;
  double     attitude_coeff         = 1;
  double     current_horizontal_acceleration, current_vertical_acceleration;
  std::mutex mutex_state;

  mrs_msgs::PositionCommand position_output;

private:
  ros::Subscriber subscriber_joystick;
  void            callbackJoystic(const sensor_msgs::Joy &msg);
  double          max_tilt_;
  double          vertical_speed_;

  // channel numbers and channel multipliers
  int _channel_pitch_, _channel_roll_, _channel_yaw_, _channel_thrust_;
  int _channel_mult_pitch_, _channel_mult_roll_, _channel_mult_yaw_, _channel_mult_thrust_;

private:
  mrs_lib::Profiler *profiler;
  bool               profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void JoyTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] mrs_uav_manager::CommonHandlers_t const *common_handlers) {

  uav_name_             = uav_name;
  this->common_handlers = common_handlers;

  ros::NodeHandle nh_(parent_nh, "joy_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "JoyTracker");

  param_loader.load_param("enable_profiler", profiler_enabled_);

  param_loader.load_param("vertical_tracker/vertical_speed", vertical_speed_);

  param_loader.load_param("tracker_loop_rate", tracker_loop_rate_);
  param_loader.load_param("max_tilt", max_tilt_);

  param_loader.load_param("yaw_tracker/yaw_rate", yaw_rate_);

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

  tracker_dt_ = 1.0 / double(tracker_loop_rate_);

  ROS_INFO("[JoyTracker]: tracker_dt: %f", tracker_dt_);

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = new mrs_lib::Profiler(nh_, "joytracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  subscriber_joystick = nh_.subscribe("joystick_in", 1, &JoyTracker::callbackJoystic, this, ros::TransportHints().tcpNoDelay());

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer = nh_.createTimer(ros::Rate(tracker_loop_rate_), &JoyTracker::mainTimer, this);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[JoyTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[JoyTracker]: initialized");
}

//}

/* //{ activate() */

bool JoyTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_uav_state) {

    ROS_ERROR("[JoyTracker]: can't activate(), odometry not set");
    return false;
  }

  if (!got_goal) {

    ROS_ERROR("[JoyTracker]: can't activate(), missing joystic goal");
    return false;
  }

  {
    std::scoped_lock lock(mutex_goal, mutex_state, mutex_uav_state);

    if (mrs_msgs::PositionCommand::Ptr() != cmd) {

      // the last command is usable
      state_z   = cmd->position.z;
      state_yaw = cmd->yaw;

    } else {

      state_z   = uav_state.pose.position.z;
      state_yaw = uav_yaw;

      ROS_WARN("[JoyTracker]: the previous command is not usable for activation, using Odometry instead.");
    }
  }


  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  is_active = true;

  ROS_INFO("[JoyTracker]: activated");

  return true;
}

//}

/* //{ deactivate() */

void JoyTracker::deactivate(void) {

  is_active = false;

  ROS_INFO("[JoyTracker]: deactivated");
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr JoyTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &cmd) {

  mrs_lib::Routine profiler_routine = profiler->createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state);

    uav_state = *msg;
    uav_x     = uav_state.pose.position.x;
    uav_y     = uav_state.pose.position.y;
    uav_z     = uav_state.pose.position.z;

    // calculate the euler angles
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(uav_state.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(uav_roll, uav_pitch, uav_yaw);

    got_uav_state = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = uav_state.header.frame_id;

  {
    std::scoped_lock lock(mutex_state, mutex_uav_state);

    position_output.position.x = uav_state.pose.position.x;
    position_output.position.y = uav_state.pose.position.y;
    position_output.position.z = state_z;
    position_output.yaw        = state_yaw;

    position_output.velocity.x = uav_state.velocity.linear.x;
    position_output.velocity.y = uav_state.velocity.linear.y;
    position_output.velocity.z = current_vertical_speed;
    position_output.yaw_dot    = current_yaw_rate;

    position_output.acceleration.x = 0;
    position_output.acceleration.y = 0;
    position_output.acceleration.z = 0;

    position_output.use_quat_attitude = 1;
    position_output.use_yaw           = 1;
    position_output.use_yaw_dot       = 1;

    tf::Quaternion desired_orientation;

    double affine_coef = 0.99;
    if (fabs(uav_state.velocity.linear.x) > 5 || fabs(uav_state.velocity.linear.y) > 5) {
      attitude_coeff = affine_coef * attitude_coeff;
    } else {
      attitude_coeff = affine_coef * attitude_coeff + (1 - affine_coef);
    }

    desired_orientation = tf::createQuaternionFromRPY(-desired_roll * attitude_coeff, desired_pitch * attitude_coeff, state_yaw);

    position_output.attitude.w = desired_orientation.getW();
    position_output.attitude.x = desired_orientation.getX();
    position_output.attitude.y = desired_orientation.getY();
    position_output.attitude.z = desired_orientation.getZ();
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus JoyTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = callbacks_enabled;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr JoyTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[100];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[JoyTracker]: %s", message);

  } else {

    sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
  }

  res.message = message;
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

const mrs_msgs::TrackerConstraintsResponse::ConstPtr JoyTracker::setConstraints([[maybe_unused]] const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsResponse::Ptr();
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

  if (!is_active) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler->createRoutine("main", tracker_loop_rate_, 0.002, event);

  // --------------------------------------------------------------
  // |                       height tracking                      |
  // --------------------------------------------------------------

  state_z += current_vertical_speed * tracker_dt_;

  // --------------------------------------------------------------
  // |                        yaw tracking                        |
  // --------------------------------------------------------------

  // flap the resulted state_yaw aroud PI
  state_yaw += current_yaw_rate * tracker_dt_;

  if (state_yaw > PI) {
    state_yaw -= 2 * PI;
  } else if (state_yaw < -PI) {
    state_yaw += 2 * PI;
  }
}

//}

// | --------------------- custom methods --------------------- |

/* callbackJoystick() //{ */

void JoyTracker::callbackJoystic(const sensor_msgs::Joy &msg) {

  if (!is_initialized)
    return;

  mrs_lib::Routine profiler_routine = profiler->createRoutine("callbackJoy");

  // TODO check the size of the array

  current_vertical_speed = _channel_mult_thrust_ * msg.axes[_channel_thrust_] * vertical_speed_;
  current_yaw_rate       = _channel_mult_yaw_ * msg.axes[_channel_yaw_] * yaw_rate_;
  desired_pitch          = _channel_mult_pitch_ * msg.axes[_channel_pitch_] * max_tilt_;
  desired_roll           = _channel_mult_roll_ * msg.axes[_channel_roll_] * max_tilt_;

  got_goal = true;

  ROS_INFO_THROTTLE(1.0, "[JoyTracker]: th: %f, yaw: %f, pitch: %f, roll: %f", current_vertical_speed, current_yaw_rate, desired_pitch, desired_roll);
}

//}

}  // namespace joy_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::joy_tracker::JoyTracker, mrs_uav_manager::Tracker)
