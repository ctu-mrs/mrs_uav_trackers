/* includes //{ */

#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Joy.h>

#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_msgs/ObstacleSectors.h>
#include <mrs_uav_manager/Tracker.h>

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
  JoyTracker(void);

  virtual void initialize(const ros::NodeHandle &parent_nh, mrs_uav_manager::SafetyArea_t const *safety_area);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  virtual const mrs_msgs::TrackerStatus::Ptr        getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  virtual void                                      switchOdometrySource(const nav_msgs::Odometry::ConstPtr &msg);

  virtual const mrs_msgs::Vec4Response::ConstPtr goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec4Response::ConstPtr goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg);
  virtual bool goToAltitude(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYaw(const std_msgs::Float64ConstPtr &msg);
  virtual bool setYawRelative(const std_msgs::Float64ConstPtr &msg);

  virtual const mrs_msgs::TrackerConstraintsResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled = true;

private:
  nav_msgs::Odometry odometry;
  bool               got_odometry = false;
  std::mutex         mutex_odometry;

  double odometry_x;
  double odometry_y;
  double odometry_z;
  double odometry_yaw;
  double odometry_roll;
  double odometry_pitch;

private:
  // tracker's inner states
  int    tracker_loop_rate_;
  double tracker_dt_;
  bool   is_initialized;
  bool   is_active;
  bool   first_iter;

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
  ros::Subscriber subscriber_bumper;
  void            callbackJoystic(const sensor_msgs::Joy &msg);
  void            callbackBumper(const mrs_msgs::ObstacleSectorsConstPtr &msg);
  double          max_tilt_;
  double          vertical_speed_;
  bool            got_bumper = false;

  mrs_msgs::ObstacleSectors bumper_data;
  mrs_msgs::ObstacleSectors bumper_previous_data;
  std::mutex                mutex_bumper;

  bool bumper_enabled_ = false;
  /* bool bumper_hugging_enabled_   = false; */
  /* bool bumper_repulsion_enabled_ = false; */
  /* bool repulsing                 = false; */
  /* uint repulsing_from; */

  double bumper_horizontal_distance_;
  double bumper_vertical_distance_;

  double bumper_repulsion_horizontal_distance_;
  double bumper_critical_horizontal_distance_;
  double bumper_repulsion_horizontal_offset_;
  double bumper_critical_vertical_distance_;
  double bumper_repulsion_vertical_distance_;
  double bumper_repulsion_vertical_offset_;

  bool bumperPushFromObstacle();
  int  bumperGetSectorId(const double x, const double y, const double z);

private:
  mrs_lib::Profiler *profiler;
  bool               profiler_enabled_ = false;

  // indices of joystick buttons
  int start_button_idx_;
  int thrust_idx_;
  int yaw_idx_;
  int pitch_idx_;
  int roll_idx_;
};

JoyTracker::JoyTracker(void) : is_initialized(false), is_active(false) {
}

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void JoyTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] mrs_uav_manager::SafetyArea_t const *safety_area) {

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

  param_loader.load_param("buttons_indices/thrust", thrust_idx_);
  param_loader.load_param("buttons_indices/yaw", yaw_idx_);
  param_loader.load_param("buttons_indices/pitch", pitch_idx_);
  param_loader.load_param("buttons_indices/roll", roll_idx_);
  param_loader.load_param("buttons_indices/start", start_button_idx_);

  /* //{ check loaded indices */
  if (start_button_idx_ < 0 || start_button_idx_ > 10) {
    ROS_ERROR("[JoyTracker]: Invalid index of start button. Setting default value.");
    start_button_idx_ = 7;
  }
  if (thrust_idx_ < 0 || thrust_idx_ > 7) {
    ROS_ERROR("[JoyTracker]: Invalid index of thrust button. Setting default value.");
    thrust_idx_ = 4;
  }
  if (yaw_idx_ < 0 || yaw_idx_ > 7) {
    ROS_ERROR("[JoyTracker]: Invalid index of yaw button. Setting default value.");
    yaw_idx_ = 0;
  }
  if (pitch_idx_ < 0 || pitch_idx_ > 7) {
    ROS_ERROR("[JoyTracker]: Invalid index of pitch button. Setting default value.");
    pitch_idx_ = 1;
  }
  if (roll_idx_ < 0 || roll_idx_ > 7) {
    ROS_ERROR("[JoyTracker]: Invalid index of roll button. Setting default value.");
    roll_idx_ = 3;
  }
  /*//}*/

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
  subscriber_bumper   = nh_.subscribe("bumper_in", 1, &JoyTracker::callbackBumper, this, ros::TransportHints().tcpNoDelay());

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

  if (!got_odometry) {

    ROS_ERROR("[JoyTracker]: can't activate(), odometry not set");
    return false;
  }

  if (!got_goal) {

    ROS_ERROR("[JoyTracker]: can't activate(), missing joystic goal");
    return false;
  }

  {
    std::scoped_lock lock(mutex_goal, mutex_state, mutex_odometry);

    if (mrs_msgs::PositionCommand::Ptr() != cmd) {

      // the last command is usable
      state_z   = cmd->position.z;
      state_yaw = cmd->yaw;

    } else {

      state_z   = odometry.pose.pose.position.z;
      state_yaw = odometry_yaw;

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

const mrs_msgs::PositionCommand::ConstPtr JoyTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  mrs_lib::Routine profiler_routine = profiler->createRoutine("update");

  {
    std::scoped_lock lock(mutex_odometry);

    odometry   = *msg;
    odometry_x = odometry.pose.pose.position.x;
    odometry_y = odometry.pose.pose.position.y;
    odometry_z = odometry.pose.pose.position.z;

    // calculate the euler angles
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(odometry_roll, odometry_pitch, odometry_yaw);

    got_odometry = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  {
    std::scoped_lock lock(mutex_state, mutex_odometry);

    position_output.position.x = odometry.pose.pose.position.x;
    position_output.position.y = odometry.pose.pose.position.y;
    position_output.position.z = state_z;
    position_output.yaw        = state_yaw;

    position_output.velocity.x = odometry.twist.twist.linear.x;
    position_output.velocity.y = odometry.twist.twist.linear.y;
    position_output.velocity.z = current_vertical_speed;
    position_output.yaw_dot    = current_yaw_rate;

    position_output.acceleration.x = 0;
    position_output.acceleration.y = 0;
    position_output.acceleration.z = 0;

    position_output.use_quat_attitude = 1;

    tf::Quaternion desired_orientation;

    double affine_coef = 0.99;
    if (fabs(odometry.twist.twist.linear.x) > 5 || fabs(odometry.twist.twist.linear.y) > 5) {
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

const mrs_msgs::TrackerStatus::Ptr JoyTracker::getStatus() {

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

void JoyTracker::switchOdometrySource([[maybe_unused]] const nav_msgs::Odometry::ConstPtr &msg) {
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::Vec4Response::ConstPtr JoyTracker::goTo([[maybe_unused]] const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goTo() topic */

bool JoyTracker::goTo([[maybe_unused]] const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  return false;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::Vec4Response::ConstPtr JoyTracker::goToRelative([[maybe_unused]] const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goToRelative() topic */

bool JoyTracker::goToRelative([[maybe_unused]] const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  return false;
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Vec1Response::ConstPtr JoyTracker::goToAltitude([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ goToAltitude() topic */

bool JoyTracker::goToAltitude([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
}

//}

/* //{ setYaw() service */

const mrs_msgs::Vec1Response::ConstPtr JoyTracker::setYaw([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYaw() topic */

bool JoyTracker::setYaw([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Vec1Response::ConstPtr JoyTracker::setYawRelative([[maybe_unused]] const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYawRelative() topic */

bool JoyTracker::setYawRelative([[maybe_unused]] const std_msgs::Float64ConstPtr &msg) {

  return false;
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

  current_vertical_speed = msg.axes[thrust_idx_] * vertical_speed_;
  current_yaw_rate       = msg.axes[yaw_idx_] * yaw_rate_;
  desired_pitch          = msg.axes[pitch_idx_] * max_tilt_;
  desired_roll           = msg.axes[roll_idx_] * max_tilt_;

  got_goal = true;

  ROS_INFO_THROTTLE(1.0, "[JoyTracker]: th: %f, yaw: %f, pitch: %f, roll: %f", current_vertical_speed, current_yaw_rate, desired_pitch, desired_roll);
}

//}

/* callbackBumper() //{ */

void JoyTracker::callbackBumper(const mrs_msgs::ObstacleSectorsConstPtr &msg) {
  ROS_ERROR("[JoyTracker]: start bumper callback");
  if (!is_initialized)
    return;

  ROS_INFO_ONCE("[JoyTracker]: getting bumper data");
  ROS_INFO_THROTTLE(0.5, "[JoyTracker]: getting bumper data");

  std::scoped_lock lock(mutex_bumper);

  got_bumper = true;

  bumper_data = *msg;
}

//}

/* bumperGetSectorId() //{ */

int JoyTracker::bumperGetSectorId(const double x, const double y, [[maybe_unused]] const double z) {

  // heading of the point in drone frame
  double point_heading_horizontal = atan2(y, x);

  point_heading_horizontal += 2 * M_PI;

  // if point_heading_horizontal is greater then 2*M_PI mod it
  if (fabs(point_heading_horizontal) >= 2 * M_PI) {
    point_heading_horizontal = fmod(point_heading_horizontal, 2 * M_PI);
  }

  // heading of the right edge of the first sector
  double sector_size = 2 * M_PI / double(bumper_data.n_horizontal_sectors);

  // calculate the idx
  int idx = floor((point_heading_horizontal + (sector_size / 2.0)) / sector_size);

  if (uint(idx) > bumper_data.n_horizontal_sectors - 1) {
    idx -= bumper_data.n_horizontal_sectors;
  }

  return idx;
}

//}
//
/* bumperPushFromObstacle() //{ */

bool JoyTracker::bumperPushFromObstacle(void) {

  if (!bumper_enabled_) {
    return true;
  }

  if (!got_bumper) {
    return true;
  }

  std::scoped_lock lock(mutex_bumper);

  double sector_size = 2 * M_PI / double(bumper_data.n_horizontal_sectors);

  double min_distance                  = 10e9;
  double repulsion_distance            = 10e9;
  double obst_dist_below               = 10e9;
  double obst_dist_above               = 10e9;
  double horizontal_collision_detected = false;
  double ver_speed_correction_below    = 0;
  double ver_speed_correction_above    = 0;


  double vertical_collision_detected = false;

  for (uint i = 0; i < bumper_data.n_horizontal_sectors; i++) {

    if (bumper_data.sectors[i] < 0) {
      continue;
    }

    // if the sector is under critical distance
    if (bumper_data.sectors[i] <= bumper_repulsion_horizontal_distance_) {

      // get the desired direction of motion
      double oposite_direction  = double(i) * sector_size + M_PI;
      int    oposite_sector_idx = bumperGetSectorId(cos(oposite_direction), sin(oposite_direction), 0);

      horizontal_collision_detected = true;
    }
  }

  bool   collision_above             = false;
  bool   collision_below             = false;

  // check for vertical collision down
  if (bumper_data.sectors[bumper_data.n_horizontal_sectors] > 0 &&
      bumper_data.sectors[bumper_data.n_horizontal_sectors] <= bumper_repulsion_vertical_distance_) {

    ROS_INFO_THROTTLE(1.0, "[JoyTracker]: bumper: potential collision below");
    collision_below             = true;
    vertical_collision_detected = true;
    obst_dist_below             = bumper_data.sectors[bumper_data.n_horizontal_sectors];
    if (bumper_data.sectors[bumper_data.n_horizontal_sectors] <= bumper_critical_vertical_distance_) {  // below critical distance
      if (bumper_data.sectors[bumper_data.n_horizontal_sectors] >
          bumper_previous_data.sectors[bumper_data.n_horizontal_sectors]) {  // further than in previous step
        ver_speed_correction_below = 0;
      } else {                             // closer than previous step
        ver_speed_correction_below = 0.1;  // TODO add adpation based on the distance
      }
    } else {  // inside detection radius
      ver_speed_correction_below = -1.0 * (bumper_data.sectors[bumper_data.n_horizontal_sectors] - bumper_critical_vertical_distance_) /
                                   (bumper_repulsion_vertical_distance_ - bumper_critical_vertical_distance_);  // normalized
    }
  }

  // check for vertical collision up
  if (bumper_data.sectors[bumper_data.n_horizontal_sectors + 1] > 0 &&
      bumper_data.sectors[bumper_data.n_horizontal_sectors + 1] <= bumper_repulsion_vertical_distance_) {

    ROS_INFO_THROTTLE(1.0, "[JoyTracker]: bumper: potential collision above");
    collision_above             = true;
    vertical_collision_detected = true;
    obst_dist_above             = bumper_data.sectors[bumper_data.n_horizontal_sectors + 1];
    if (bumper_data.sectors[bumper_data.n_horizontal_sectors + 1] <= bumper_critical_vertical_distance_) {  // below critical distance
      if (bumper_data.sectors[bumper_data.n_horizontal_sectors + 1] >
          bumper_previous_data.sectors[bumper_data.n_horizontal_sectors + 1]) {  // further than in previous step
        ver_speed_correction_above = 0;
      } else {                              // closer than previous step
        ver_speed_correction_above = -0.1;  // TODO add adpation based on the distance
      }
    } else {  // inside detection radius
      ver_speed_correction_above = 1.0 * (bumper_data.sectors[bumper_data.n_horizontal_sectors] - bumper_critical_vertical_distance_) /
                                   (bumper_repulsion_vertical_distance_ - bumper_critical_vertical_distance_);  // normalized
    }
  }

  if (obst_dist_above < bumper_critical_vertical_distance_ && obst_dist_below < bumper_critical_vertical_distance_) { // in critical distance below and above concurrently
    vertical_speed_ = 0.05 * (obst_dist_above - obst_dist_below) / bumper_critical_vertical_distance_;  // replace by coefficient
  } else {
    ROS_INFO("[JoyTracker]: vertical_speed = %.2f, limits = [%.2f, %.2f]", vertical_speed_, ver_speed_correction_below, ver_speed_correction_above);
    vertical_speed_ = fmax(fmin(vertical_speed_, ver_speed_correction_above), ver_speed_correction_below);
    ROS_INFO("[JoyTracker]: Resulting vertical_speed = %.2f", vertical_speed_);
  }
  
  bumper_previous_data = bumper_data;  // TODO: check correctness of assignment
  return false;
}

//}


}  // namespace joy_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::joy_tracker::JoyTracker, mrs_uav_manager::Tracker)
