#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_mav_manager/Tracker.h>
#include <nav_msgs/Odometry.h>
#include <mrs_lib/Profiler.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#define STOP_THR 1e-3

namespace mrs_trackers
{

//{ class LandoffTracker

// state machine
typedef enum {

  IDLE_STATE,
  LANDED_STATE,
  STOP_MOTION_STATE,
  HOVER_STATE,
  ACCELERATING_STATE,
  DECELERATING_STATE,
  STOPPING_STATE,

} States_t;

const char *state_names[7] = {

    "IDLING", "LANDED", "STOPPING_MOTION", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

class LandoffTracker : public mrs_mav_manager::Tracker {
public:
  LandoffTracker(void);

  void initialize(const ros::NodeHandle &parent_nh);
  bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  void deactivate(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const mrs_msgs::TrackerStatus::Ptr status();

  virtual const mrs_msgs::Vec4Response::ConstPtr goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec4Response::ConstPtr goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd);
  virtual const mrs_msgs::Vec1Response::ConstPtr goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

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
  double takeoff_height_;
  double landing_height_;
  double landing_fast_height_;
  double tracker_dt_;
  bool   is_initialized;
  bool   is_active;
  bool   first_iter;

private:
  void mainTimer(const ros::TimerEvent &event);
  ros::Timer main_timer;

private:
  ros::ServiceServer service_takeoff;
  ros::ServiceServer service_land;

private:
  States_t current_state_vertical;
  States_t previous_state_vertical;
  States_t current_state_horizontal;
  States_t previous_state_horizontal;

  void changeStateHorizontal(States_t new_state);
  void changeStateVertical(States_t new_state);
  void changeState(States_t new_state);

  bool taking_off = false;
  bool landing    = false;

private:
  void stopHorizontalMotion(void);
  void stopVerticalMotion(void);
  void accelerateHorizontal(void);
  void accelerateVertical(void);
  void decelerateHorizontal(void);
  void decelerateVertical(void);
  void stopHorizontal(void);
  void stopVertical(void);
  bool callbackTakeoff(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool callbackLand(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

private:
  double horizontal_speed_;
  double vertical_speed_;
  double takeoff_speed_;
  double landing_speed_;

  double horizontal_acceleration_;
  double vertical_acceleration_;
  double takeoff_acceleration_;
  double landing_acceleration_;

  double yaw_rate_;
  double yaw_gain_;

  double max_position_difference_;
  double landing_cutoff_height_;

private:
  // desired goal
  double goal_x, goal_y, goal_z, goal_yaw;
  double have_goal = false;

  // my current state
  double state_x, state_y, state_z, state_yaw;
  double speed_x, speed_y, speed_yaw;
  double current_heading, current_vertical_direction, current_vertical_speed, current_horizontal_speed;

  mrs_msgs::PositionCommand position_output;

private:
  mrs_lib::Profiler *profiler;
  mrs_lib::Routine * routine_main_timer;
};

LandoffTracker::LandoffTracker(void) : is_initialized(false), is_active(false) {
}

//}

//{ initialize()

void LandoffTracker::initialize(const ros::NodeHandle &parent_nh) {

  ros::NodeHandle nh_(parent_nh, "landoff_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  nh_.param("horizontal_tracker/horizontal_speed", horizontal_speed_, -1.0);
  nh_.param("horizontal_tracker/horizontal_acceleration", horizontal_acceleration_, -1.0);

  nh_.param("vertical_tracker/vertical_speed", vertical_speed_, -1.0);
  nh_.param("vertical_tracker/vertical_acceleration", vertical_acceleration_, -1.0);

  nh_.param("vertical_tracker/takeoff_speed", takeoff_speed_, -1.0);
  nh_.param("vertical_tracker/takeoff_acceleration", takeoff_acceleration_, -1.0);

  nh_.param("vertical_tracker/landing_speed", landing_speed_, -1.0);
  nh_.param("vertical_tracker/landing_acceleration", landing_acceleration_, -1.0);

  nh_.param("yaw_tracker/yaw_rate", yaw_rate_, -1.0);
  nh_.param("yaw_tracker/yaw_gain", yaw_gain_, -1.0);

  nh_.param("tracker_loop_rate", tracker_loop_rate_, -1);

  nh_.param("takeoff_height", takeoff_height_, -1.0);
  nh_.param("landing_height", landing_height_, -1000.0);
  nh_.param("landing_fast_height", landing_fast_height_, -1.0);

  nh_.param("max_position_difference", max_position_difference_, -1.0);

  nh_.param("landing_cutoff_height", landing_cutoff_height_, -1.0);
  nh_.param("landing_cutoff_height", landing_cutoff_height_, -1.0);

  if (horizontal_speed_ < 0) {
    ROS_ERROR("[LandoffTracker]: horizontal_speed was not specified!");
    ros::shutdown();
  }

  if (vertical_speed_ < 0) {
    ROS_ERROR("[LandoffTracker]: vertical_speed was not specified!");
    ros::shutdown();
  }

  if (horizontal_acceleration_ < 0) {
    ROS_ERROR("[LandoffTracker]: horizontal_acceleration was not specified!");
    ros::shutdown();
  }

  if (vertical_acceleration_ < 0) {
    ROS_ERROR("[LandoffTracker]: vertical_acceleration was not specified!");
    ros::shutdown();
  }

  if (yaw_rate_ < 0) {
    ROS_ERROR("[LandoffTracker]: yaw_rate was not specified!");
    ros::shutdown();
  }

  if (yaw_gain_ < 0) {
    ROS_ERROR("[LandoffTracker]: yaw_gain was not specified!");
    ros::shutdown();
  }

  if (tracker_loop_rate_ < 0) {
    ROS_ERROR("[LandoffTracker]: tracker_loop_rate was not specified!");
    ros::shutdown();
  }

  if (takeoff_speed_ < 0) {
    ROS_ERROR("[LandoffTracker]: takeoff_speed was not specified!");
    ros::shutdown();
  }

  if (takeoff_acceleration_ < 0) {
    ROS_ERROR("[LandoffTracker]: takeoff_acceleration was not specified!");
    ros::shutdown();
  }

  if (landing_speed_ < 0) {
    ROS_ERROR("[LandoffTracker]: landing_speed was not specified!");
    ros::shutdown();
  }

  if (landing_acceleration_ < 0) {
    ROS_ERROR("[LandoffTracker]: landing_acceleration was not specified!");
    ros::shutdown();
  }

  if (takeoff_height_ < 0) {
    ROS_ERROR("[LandoffTracker]: takeoff_height was not specified!");
    ros::shutdown();
  }

  if (landing_height_ < -999) {
    ROS_ERROR("[LandoffTracker]: landing_height was not specified!");
    ros::shutdown();
  }

  if (landing_fast_height_ < -999) {
    ROS_ERROR("[LandoffTracker]: landing_fast_height was not specified!");
    ros::shutdown();
  }

  if (max_position_difference_ < 0) {
    ROS_ERROR("[LandoffTracker]: max_position_difference was not specified!");
    ros::shutdown();
  }

  if (landing_cutoff_height_ < 0) {
    ROS_ERROR("[LandoffTracker]: landing_cutoff_height was not specified!");
    ros::shutdown();
  }

  tracker_dt_ = 1.0 / double(tracker_loop_rate_);

  ROS_INFO("[LandoffTracker]: tracker_dt: %f", tracker_dt_);

  state_x   = 0;
  state_y   = 0;
  state_z   = 0;
  state_yaw = 0;

  speed_x   = 0;
  speed_y   = 0;
  speed_yaw = 0;

  current_horizontal_speed = 0;
  current_vertical_speed   = 0;

  current_vertical_direction = 0;

  is_initialized = true;

  current_state_vertical  = LANDED_STATE;
  previous_state_vertical = LANDED_STATE;

  current_state_horizontal  = LANDED_STATE;
  previous_state_horizontal = LANDED_STATE;

  // --------------------------------------------------------------
  // |                          services                          |
  // --------------------------------------------------------------

  service_takeoff = nh_.advertiseService("takeoff", &LandoffTracker::callbackTakeoff, this);
  service_land    = nh_.advertiseService("land", &LandoffTracker::callbackLand, this);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  main_timer = nh_.createTimer(ros::Rate(tracker_loop_rate_), &LandoffTracker::mainTimer, this);

  profiler           = new mrs_lib::Profiler(nh_, "LandoffTracker");
  routine_main_timer = profiler->registerRoutine("main", tracker_loop_rate_, 0.002);

  ROS_INFO("[LandoffTracker]: initialized");
}

//}

// --------------------------------------------------------------
// |                tracker's interface routines                |
// --------------------------------------------------------------

//{ activate()

bool LandoffTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_odometry) {
    ROS_ERROR("[LandoffTracker]: can't activate(), odometry not set");
    return false;
  }

  mutex_odometry.lock();
  {
    if (cmd == mrs_msgs::PositionCommand::Ptr() || (odometry_z < landing_cutoff_height_)) {

      state_x   = odometry.pose.pose.position.x;
      state_y   = odometry.pose.pose.position.y;
      state_z   = odometry.pose.pose.position.z;
      state_yaw = odometry_yaw;

      speed_x                  = 0;
      speed_y                  = 0;
      current_heading          = 0;
      current_horizontal_speed = 0;

      current_vertical_speed = odometry.twist.twist.linear.z;

      goal_yaw = odometry_yaw;

      ROS_WARN("[LandoffTracker]: activated, the previous command is not usable for activation, using Odometry instead.");

    } else {

      // the last command is usable
      state_x   = cmd->position.x;
      state_y   = cmd->position.y;
      state_z   = cmd->position.z;
      state_yaw = cmd->yaw;

      speed_x         = cmd->velocity.x;
      speed_y         = cmd->velocity.y;
      current_heading = atan2(speed_y, speed_x);

      current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));
      current_vertical_speed   = cmd->velocity.z;

      goal_yaw = cmd->yaw;

      ROS_INFO("[LandoffTracker]: activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z,
               cmd->yaw);
    }
  }
  mutex_odometry.unlock();

  // --------------------------------------------------------------
  // |          horizontal initial conditions prediction          |
  // --------------------------------------------------------------

  double horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  double horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  double stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  double stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  // --------------------------------------------------------------
  // |           vertical initial conditions prediction           |
  // --------------------------------------------------------------

  double vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;

  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  goal_x = state_x + stop_dist_x;
  goal_y = state_y + stop_dist_y;
  goal_z = state_z + vertical_stop_dist;

  landing    = false;
  taking_off = false;
  is_active  = true;

  ROS_INFO("[LandoffTracker]: activated with goal x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", goal_x, goal_y, goal_z, goal_yaw);

  changeState(STOP_MOTION_STATE);

  return true;
}

//}

//{ deactivate()

void LandoffTracker::deactivate(void) {

  is_active                = false;
  landing                  = false;
  taking_off               = false;
  current_state_vertical   = IDLE_STATE;
  current_state_horizontal = IDLE_STATE;

  ROS_INFO("[LandoffTracker]: deactivated");
}

//}

// --------------------------------------------------------------
// |                   state machine routines                   |
// --------------------------------------------------------------

//{ changeStateHorizontal()

void LandoffTracker::changeStateHorizontal(States_t new_state) {

  previous_state_horizontal = current_state_horizontal;
  current_state_horizontal  = new_state;

  // just for ROS_INFO
  ROS_DEBUG("[LandoffTracker]: Switching horizontal state %s -> %s", state_names[previous_state_horizontal], state_names[current_state_horizontal]);
}

//}

//{ changeStateVertical()

void LandoffTracker::changeStateVertical(States_t new_state) {

  previous_state_vertical = current_state_vertical;
  current_state_vertical  = new_state;

  switch (current_state_vertical) {

    case IDLE_STATE:
      break;
    case LANDED_STATE:
      break;
    case HOVER_STATE:
      landing    = false;
      taking_off = false;
      break;
    case STOP_MOTION_STATE:
      break;
    case ACCELERATING_STATE:
      break;
    case DECELERATING_STATE:
      break;
    case STOPPING_STATE:
      break;
  }

  // just for ROS_INFO
  ROS_DEBUG("[LandoffTracker]: Switching vertical state %s -> %s", state_names[previous_state_vertical], state_names[current_state_vertical]);
}

//}

//{ changeState()

void LandoffTracker::changeState(States_t new_state) {

  changeStateVertical(new_state);
  changeStateHorizontal(new_state);
}

//}

//{ update()

const mrs_msgs::PositionCommand::ConstPtr LandoffTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  mutex_odometry.lock();
  {
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
  mutex_odometry.unlock();

  if (!is_active) {

    return mrs_msgs::PositionCommand::Ptr();
  }

  position_output.header.stamp    = ros::Time::now();
  position_output.header.frame_id = "local_origin";

  position_output.position.x = state_x;
  position_output.position.y = state_y;
  position_output.position.z = state_z;
  position_output.yaw        = state_yaw;

  position_output.velocity.x = cos(current_heading) * current_horizontal_speed;
  position_output.velocity.y = sin(current_heading) * current_horizontal_speed;
  position_output.velocity.z = current_vertical_direction * current_vertical_speed;
  position_output.yaw_dot    = speed_yaw;

  position_output.acceleration.x = 0;
  position_output.acceleration.y = 0;
  position_output.acceleration.z = 0;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
}

//}

//{ status()

const mrs_msgs::TrackerStatus::Ptr LandoffTracker::status() {

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

//{ goTo()

const mrs_msgs::Vec4Response::ConstPtr LandoffTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {
  return mrs_msgs::Vec4Response::Ptr();
}

//}

//{ goToRelative()

const mrs_msgs::Vec4Response::ConstPtr LandoffTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {
  return mrs_msgs::Vec4Response::Ptr();
}

//}

//{ goToAltitude()

const mrs_msgs::Vec1Response::ConstPtr LandoffTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

//{ hover()

const std_srvs::TriggerResponse::ConstPtr LandoffTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

// --------------------------------------------------------------
// |                       motion routines                      |
// --------------------------------------------------------------

//{ stopHorizontalMotion()

void LandoffTracker::stopHorizontalMotion(void) {

  current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed < 0) {
    current_horizontal_speed = 0;
  }
}

//}

//{ stopVerticalMotion()

void LandoffTracker::stopVerticalMotion(void) {

  current_vertical_speed -= vertical_acceleration_ * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed = 0;
  }
}

//}

//{ accelerateHorizontal()

void LandoffTracker::accelerateHorizontal(void) {

  current_heading = atan2(goal_y - state_y, goal_x - state_x);

  // decelerationg condition
  // calculate the time to stop and the distance it will take to stop [horizontal]
  double horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
  double horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
  double stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
  double stop_dist_y          = sin(current_heading) * horizontal_stop_dist;

  current_horizontal_speed += horizontal_acceleration_ * tracker_dt_;

  if (current_horizontal_speed >= horizontal_speed_) {
    current_horizontal_speed = horizontal_speed_;
  }

  if (sqrt(pow(state_x + stop_dist_x - goal_x, 2) + pow(state_y + stop_dist_y - goal_y, 2)) < (2 * (horizontal_speed_ * tracker_dt_))) {
    changeStateHorizontal(DECELERATING_STATE);
  }
}

//}

//{ accelerateVertical()

void LandoffTracker::accelerateVertical(void) {

  double used_acceleration;
  double used_speed;

  if (taking_off) {
    used_speed        = takeoff_speed_;
    used_acceleration = takeoff_acceleration_;
  } else if (landing) {

    if (odometry_z > 2 * landing_fast_height_) {
      used_speed        = vertical_speed_;
      used_acceleration = vertical_acceleration_;
    } else if (odometry_z > landing_fast_height_) {
      used_speed        = vertical_speed_ / 2.0;
      used_acceleration = vertical_acceleration_ / 2.0;
    } else {
      used_speed        = landing_speed_;
      used_acceleration = landing_acceleration_;
    }

  } else {
    used_speed        = vertical_speed_;
    used_acceleration = vertical_acceleration_;
  }

  // set the right heading
  double tar_z = goal_z - state_z;

  // set the right vertical direction
  current_vertical_direction = mrs_trackers_commons::sign(tar_z);

  // calculate the time to stop and the distance it will take to stop [vertical]
  double vertical_t_stop    = current_vertical_speed / used_acceleration;
  double vertical_stop_dist = (vertical_t_stop * current_vertical_speed) / 2;
  double stop_dist_z        = current_vertical_direction * vertical_stop_dist;

  current_vertical_speed += used_acceleration * tracker_dt_;

  if (current_vertical_speed >= used_speed) {
    current_vertical_speed -= vertical_acceleration_ * tracker_dt_;
  }

  if (fabs(state_z + stop_dist_z - goal_z) < (2 * (used_speed * tracker_dt_))) {
    changeStateVertical(DECELERATING_STATE);
  }
}

//}

//{ decelerateHorizontal()

void LandoffTracker::decelerateHorizontal(void) {

  double used_acceleration;

  if (taking_off) {
    used_acceleration = takeoff_acceleration_;
  } else if (landing) {

    if (odometry_z > 2 * landing_fast_height_) {
      used_acceleration = vertical_acceleration_;
    } else if (odometry_z > landing_fast_height_) {
      used_acceleration = vertical_acceleration_ / 2.0;
    } else {
      used_acceleration = landing_acceleration_;
    }

  } else {
    used_acceleration = vertical_acceleration_;
  }

  current_horizontal_speed -= used_acceleration * tracker_dt_;

  if (current_horizontal_speed < 0) {
    current_horizontal_speed = 0;
  }

  if (current_horizontal_speed == 0) {
    changeStateHorizontal(STOPPING_STATE);
  }
}

//}

//{ decelerateVertical()

void LandoffTracker::decelerateVertical(void) {

  double used_acceleration;

  if (taking_off) {
    used_acceleration = takeoff_acceleration_;
  } else if (landing) {
    used_acceleration = landing_acceleration_;
  } else {
    used_acceleration = vertical_acceleration_;
  }

  current_vertical_speed -= used_acceleration * tracker_dt_;

  if (current_vertical_speed < 0) {
    current_vertical_speed = 0;
  }

  if (current_vertical_speed == 0) {
    changeStateVertical(STOPPING_STATE);
  }
}

//}

//{ stopHorizontal()

void LandoffTracker::stopHorizontal(void) {

  state_x = 0.95 * state_x + 0.05 * goal_x;
  state_y = 0.95 * state_y + 0.05 * goal_y;
}

//}

//{ stopVertical()

void LandoffTracker::stopVertical(void) {

  state_z = 0.95 * state_z + 0.05 * goal_z;
}

//}

// --------------------------------------------------------------
// |                       timer routines                       |
// --------------------------------------------------------------

//{ mainTimer()

void LandoffTracker::mainTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  routine_main_timer->start(event);

  switch (current_state_horizontal) {

    case IDLE_STATE:
      break;

    case LANDED_STATE:
      break;

    case HOVER_STATE:
      break;

    case STOP_MOTION_STATE:

      stopHorizontalMotion();
      break;

    case ACCELERATING_STATE:

      accelerateHorizontal();
      break;

    case DECELERATING_STATE:

      decelerateHorizontal();
      break;

    case STOPPING_STATE:

      stopHorizontal();
      break;
  }

  switch (current_state_vertical) {

    case IDLE_STATE:
      break;

    case LANDED_STATE:
      break;

    case HOVER_STATE:
      break;

    case STOP_MOTION_STATE:

      stopVerticalMotion();
      break;

    case ACCELERATING_STATE:

      accelerateVertical();
      break;

    case DECELERATING_STATE:

      decelerateVertical();
      break;

    case STOPPING_STATE:

      stopVertical();
      break;
  }

  if (current_state_horizontal == STOP_MOTION_STATE && current_state_vertical == STOP_MOTION_STATE) {

    if (current_vertical_speed == 0 && current_horizontal_speed == 0) {
      if (have_goal) {
        changeState(ACCELERATING_STATE);
      } else {
        changeState(STOPPING_STATE);
      }
    }
  }

  if (current_state_horizontal == STOPPING_STATE && current_state_vertical == STOPPING_STATE) {

    if (fabs(state_x - goal_x) < 1e-3 && fabs(state_y - goal_y) < 1e-3 && fabs(state_z - goal_z) < 1e-3) {

      state_x = goal_x;
      state_y = goal_y;
      state_z = goal_z;

      changeState(HOVER_STATE);
    }
  }

  if (current_state_horizontal == LANDED_STATE && current_state_vertical == LANDED_STATE) {
    mutex_odometry.lock();
    {
      state_x = goal_x = odometry_x;
      state_y = goal_y = odometry_y;
      state_z = goal_z = odometry_z;
    }
    mutex_odometry.unlock();
  }

  // --------------------------------------------------------------
  // |              motion saturation during takeoff              |
  // --------------------------------------------------------------

  mutex_odometry.lock();
  {
    if (taking_off) {

      // calculate the vector
      double err_x      = odometry_x - state_x;
      double err_y      = odometry_y - state_y;
      double err_z      = odometry_z - state_z;
      double error_size = mrs_trackers_commons::size3(err_x, err_y, err_z);

      if (error_size > max_position_difference_) {

        // calculate the potential next step
        double future_state_x = state_x + cos(current_heading) * current_horizontal_speed * tracker_dt_;
        double future_state_y = state_y + sin(current_heading) * current_horizontal_speed * tracker_dt_;
        double future_state_z = state_z + current_vertical_direction * current_vertical_speed * tracker_dt_;

        if (mrs_trackers_commons::dist3(future_state_x, odometry_x, future_state_y, odometry_y, future_state_z, odometry_z) > error_size) {

          current_horizontal_speed = 0;
          current_vertical_speed   = 0;

          ROS_WARN_THROTTLE(1.0, "[LandoffTracker]: position difference > %1.3f, saturating the motion", error_size);
        }
      }
    }
  }
  mutex_odometry.unlock();

  // update the inner states
  state_x += cos(current_heading) * current_horizontal_speed * tracker_dt_;
  state_y += sin(current_heading) * current_horizontal_speed * tracker_dt_;
  state_z += current_vertical_direction * current_vertical_speed * tracker_dt_;

  // --------------------------------------------------------------
  // |                        yaw tracking                        |
  // --------------------------------------------------------------

  // compute the desired yaw rate
  double current_yaw_rate;
  if (fabs(goal_yaw - state_yaw) > PI)
    current_yaw_rate = -yaw_gain_ * (goal_yaw - state_yaw);
  else
    current_yaw_rate = yaw_gain_ * (goal_yaw - state_yaw);

  if (current_yaw_rate > yaw_rate_) {
    current_yaw_rate = yaw_rate_;
  } else if (current_yaw_rate < -yaw_rate_) {
    current_yaw_rate = -yaw_rate_;
  }

  // flap the resulted state_yaw aroud PI
  state_yaw += current_yaw_rate * tracker_dt_;

  if (state_yaw > PI) {
    state_yaw -= 2 * PI;
  } else if (state_yaw < -PI) {
    state_yaw += 2 * PI;
  }

  if (fabs(state_yaw - goal_yaw) < (2 * (yaw_rate_ * tracker_dt_))) {
    state_yaw = goal_yaw;
  }

  routine_main_timer->end();
}

//}

// --------------------------------------------------------------
// |                          callbacks                         |
// --------------------------------------------------------------

//{ callbackTakeoff()

bool LandoffTracker::callbackTakeoff(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[100];

  if (!is_active) {

    sprintf((char *)&message, "Can't take off, the tracker is not active.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (odometry_z > landing_cutoff_height_) {

    sprintf((char *)&message, "Can't take off, already in the air!");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  mutex_odometry.lock();
  {
    state_x = odometry_x;
    goal_x  = odometry_x;

    state_y = odometry_y;
    goal_y  = odometry_y;

    state_z = odometry_z;
    goal_z  = takeoff_height_;

    state_yaw = odometry_yaw;
    goal_yaw  = odometry_yaw;
  }
  mutex_odometry.unlock();

  speed_x                = 0;
  speed_y                = 0;
  current_vertical_speed = 0;

  ROS_INFO("[LandoffTracker]: taking off");

  taking_off = true;
  landing    = false;
  have_goal  = true;

  res.success = true;
  res.message = "taking off";

  changeState(ACCELERATING_STATE);

  return true;
}

//}

//{ callbackLand()

bool LandoffTracker::callbackLand(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[100];

  if (!is_active) {

    sprintf((char *)&message, "Can't land, the tracker is not active.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    taking_off  = false;
    landing     = false;
    changeState(LANDED_STATE);
    return true;
  }

  if (odometry_z < landing_cutoff_height_) {

    sprintf((char *)&message, "Can't land, already on the ground.");
    ROS_ERROR("[LandoffTracker]: %s", message);
    res.success = false;
    res.message = message;
    changeState(LANDED_STATE);
    taking_off = false;
    landing    = false;
    return true;
  }

  goal_z = landing_height_;

  ROS_INFO("[LandoffTracker]: landing");

  landing    = true;
  taking_off = false;
  have_goal  = true;

  res.success = true;
  res.message = "landing";

  changeState(STOP_MOTION_STATE);

  return true;
}

//}
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::LandoffTracker, mrs_mav_manager::Tracker)
