#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_uav_manager/Tracker.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>

#define STOP_THR 1e-3

namespace mrs_trackers
{

  /* //{ class WallTracker */

  // state machine
  typedef enum
  {

    IDLE_STATE,
    STOP_MOTION_STATE,
    HOVER_STATE,
    ACCELERATING_STATE,
    DECELERATING_STATE,
    STOPPING_STATE,

  } States_t;

  const char *state_names[6] = {

      "IDLING", "STOPPING_MOTION", "HOVERING", "ACCELERATING", "DECELERATING", "STOPPING"};

  class WallTracker : public mrs_uav_manager::Tracker {
  public:
    WallTracker(void);

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
    States_t current_state_vertical    = IDLE_STATE;
    States_t previous_state_vertical   = IDLE_STATE;
    States_t current_state_horizontal  = IDLE_STATE;
    States_t previous_state_horizontal = IDLE_STATE;

    void changeStateHorizontal(States_t new_state);
    void changeStateVertical(States_t new_state);
    void changeState(States_t new_state);

  private:
    void approachWall(void);
    void yawControl(void);
    void coordinateChange(void);
    void detachWall(void);
    
  private:
    // dynamical constraints
    double     horizontal_speed_;
    double     vertical_speed_;
    double     horizontal_acceleration_;
    double     vertical_acceleration_;
    double     yaw_rate_;
    double     yaw_gain_;
    std::mutex mutex_constraints;

  private:
    // desired goal
    double     goal_x, goal_y, goal_z, goal_yaw;
    double     have_goal = false;
    std::mutex mutex_goal;

    // my current state
    double     state_x, state_y, state_z, state_yaw;
    double     speed_x, speed_y, speed_yaw;
    double     current_heading, current_vertical_direction, current_vertical_speed, current_horizontal_speed;
    double     current_horizontal_acceleration, current_vertical_acceleration;
    std::mutex mutex_state;

    mrs_msgs::PositionCommand position_output;

  private:
    mrs_lib::Profiler *profiler;
    bool               profiler_enabled_ = false;
  };

  WallTracker::WallTracker(void) : is_initialized(false), is_active(false) {
  }

  //}

  // | -------------- tracker's interface routines -------------- |

  /* //{ initialize() - Inicializace konstant, profiler a timer*/
   

  void WallTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] mrs_uav_manager::SafetyArea_t const *safety_area) {

    ros::NodeHandle nh_(parent_nh, "wall_tracker");

    ros::Time::waitForValid();

    // --------------------------------------------------------------
    // |                       load parameters                      |
    // --------------------------------------------------------------


    mrs_lib::ParamLoader param_loader(nh_, "WallTracker");

    param_loader.load_param("enable_profiler", profiler_enabled_);

    param_loader.load_param("horizontal_tracker/horizontal_speed", horizontal_speed_);
    param_loader.load_param("horizontal_tracker/horizontal_acceleration", horizontal_acceleration_);

    param_loader.load_param("vertical_tracker/vertical_speed", vertical_speed_);
    param_loader.load_param("vertical_tracker/vertical_acceleration", vertical_acceleration_);

    param_loader.load_param("yaw_tracker/yaw_rate", yaw_rate_);
    param_loader.load_param("yaw_tracker/yaw_gain", yaw_gain_);

    param_loader.load_param("tracker_loop_rate", tracker_loop_rate_);

    tracker_dt_ = 1.0 / double(tracker_loop_rate_);

    ROS_INFO("[WallTracker]: tracker_dt: %f", tracker_dt_);

    state_x   = 0;
    state_y   = 0;
    state_z   = 0;
    state_yaw = 0;

    speed_x   = 0;
    speed_y   = 0;
    speed_yaw = 0;

    current_horizontal_speed = 0;
    current_vertical_speed   = 0;

    current_horizontal_acceleration = 0;
    current_vertical_acceleration   = 0;

    current_vertical_direction = 0;

    current_state_vertical  = IDLE_STATE;
    previous_state_vertical = IDLE_STATE;

    current_state_horizontal  = IDLE_STATE;
    previous_state_horizontal = IDLE_STATE;

    // --------------------------------------------------------------
    // |                          profiler                          |
    // --------------------------------------------------------------

    profiler = new mrs_lib::Profiler(nh_, "WallTracker", profiler_enabled_);

    // --------------------------------------------------------------
    // |                           timers                           |
    // --------------------------------------------------------------

    main_timer = nh_.createTimer(ros::Rate(tracker_loop_rate_), &WallTracker::mainTimer, this);

    if (!param_loader.loaded_successfully()) {
      ROS_ERROR("[WallTracker]: Could not load all parameters!");
      ros::shutdown();
    }

    is_initialized = true;

    ROS_INFO("[WallTracker]: initialized");
  }

  //}

  /* //{ activate() - Aktivace, rozdeleni podle predchozi stavu, vypocet a nacteni zakladnich hodnot */

  bool WallTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

    if (!got_odometry) {
      ROS_ERROR("[WallTracker]: can't activate(), odometry not set");
      return false;
    }

    {
      std::scoped_lock lock(mutex_goal, mutex_state, mutex_odometry);

      if (mrs_msgs::PositionCommand::Ptr() != cmd) {

        // the last command is usable
        state_x   = cmd->position.x;
        state_y   = cmd->position.y;
        state_z   = cmd->position.z;
        state_yaw = cmd->yaw;

        speed_x                  = cmd->velocity.x;
        speed_y                  = cmd->velocity.y;
        current_heading          = atan2(speed_y, speed_x);
        current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

        current_vertical_speed     = fabs(cmd->velocity.z);
        current_vertical_direction = cmd->velocity.z > 0 ? +1 : -1;

        current_horizontal_acceleration = 0;
        current_vertical_acceleration   = 0;

        goal_yaw = cmd->yaw;

        ROS_INFO("[WallTracker]: initial condition: x=%2.2f, y=%2.2f, z=%2.2f, yaw=%2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);
        ROS_INFO("[WallTracker]: initial condition: x_dot=%2.2f, y_dot=%2.2f, z_dot=%2.2f", speed_x, speed_y, current_vertical_speed);

      } else {

        state_x   = odometry.pose.pose.position.x;
        state_y   = odometry.pose.pose.position.y;
        state_z   = odometry.pose.pose.position.z;
        state_yaw = odometry_yaw;

        speed_x                  = odometry.twist.twist.linear.x;
        speed_y                  = odometry.twist.twist.linear.y;
        current_heading          = atan2(speed_y, speed_x);
        current_horizontal_speed = sqrt(pow(speed_x, 2) + pow(speed_y, 2));

        current_vertical_speed     = fabs(odometry.twist.twist.linear.z);
        current_vertical_direction = odometry.twist.twist.linear.z > 0 ? +1 : -1;

        current_horizontal_acceleration = 0;
        current_vertical_acceleration   = 0;

        goal_yaw = odometry_yaw;

        ROS_WARN("[WallTracker]: the previous command is not usable for activation, using Odometry instead.");
      }
    }

    // --------------------------------------------------------------
    // |          horizontal initial conditions prediction          |
    // --------------------------------------------------------------

    double horizontal_t_stop, horizontal_stop_dist, stop_dist_x, stop_dist_y;

    {
      std::scoped_lock lock(mutex_state);

      horizontal_t_stop    = current_horizontal_speed / horizontal_acceleration_;
      horizontal_stop_dist = (horizontal_t_stop * current_horizontal_speed) / 2;
      stop_dist_x          = cos(current_heading) * horizontal_stop_dist;
      stop_dist_y          = sin(current_heading) * horizontal_stop_dist;
    }

    // --------------------------------------------------------------
    // |           vertical initial conditions prediction           |
    // --------------------------------------------------------------

    double vertical_t_stop, vertical_stop_dist;

    {
      std::scoped_lock lock(mutex_state);

      vertical_t_stop    = current_vertical_speed / vertical_acceleration_;
      vertical_stop_dist = current_vertical_direction * (vertical_t_stop * current_vertical_speed) / 2;
    }

    // --------------------------------------------------------------
    // |              yaw initial condition  prediction             |
    // --------------------------------------------------------------

    {
      std::scoped_lock lock(mutex_goal, mutex_state);

      goal_x = state_x + stop_dist_x;
      goal_y = state_y + stop_dist_y;
      goal_z = state_z + vertical_stop_dist;
      ROS_INFO("[WallTracker]: setting z goal to %f", goal_z);
    }

    is_active = true;

    ROS_INFO("[WallTracker]: activated");

    changeState(STOP_MOTION_STATE);

    return true;
  }

  //}

  /* //{ deactivate() - prepnuti is_active */

  void WallTracker::deactivate(void) {

    is_active = false;

    ROS_INFO("[WallTracker]: deactivated");
  }

  //}

  /* //{ update() - core - cteni odometrie, uprava prikazu, update */

  const mrs_msgs::PositionCommand::ConstPtr WallTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

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
      std::scoped_lock lock(mutex_state);

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
      position_output.acceleration.z = current_vertical_direction * current_vertical_acceleration;

      position_output.use_position       = 1;
      position_output.use_euler_attitude = 1;
      position_output.use_velocity       = 1;
      position_output.use_acceleration   = 1;
    }

    return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output));
  }

  //}

  /* //{ getStatus() - poslani status msgs */

  const mrs_msgs::TrackerStatus::Ptr WallTracker::getStatus() {

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

  /* //{ enableCallbacks() - v pripade ze nechces poslouchat a venovat se jinymu */

  const std_srvs::SetBoolResponse::ConstPtr WallTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

    char                      message[100];
    std_srvs::SetBoolResponse res;

    if (cmd->data != callbacks_enabled) {

      callbacks_enabled = cmd->data;

      sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

      ROS_INFO("[WallTracker]: %s", message);

    } else {

      sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
    }

    res.message = message;
    res.success = true;

    return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
  }

  //}

  /* switchOdometrySource() - prepocet pro nove souradnice //{ */

  void WallTracker::switchOdometrySource(const nav_msgs::Odometry::ConstPtr &msg) {

    std::scoped_lock lock(mutex_odometry, mutex_goal, mutex_state);

    double odom_roll, odom_pitch, odom_yaw;
    double msg_roll, msg_pitch, msg_yaw;

    // calculate the euler angles
    tf::Quaternion quaternion_odometry;
    quaternionMsgToTF(odometry.pose.pose.orientation, quaternion_odometry);
    tf::Matrix3x3 m(quaternion_odometry);
    m.getRPY(odom_roll, odom_pitch, odom_yaw);

    tf::Quaternion quaternion_msg;
    quaternionMsgToTF(msg->pose.pose.orientation, quaternion_msg);
    tf::Matrix3x3 m2(quaternion_msg);
    m2.getRPY(msg_roll, msg_pitch, msg_yaw);

    // | --------- recalculate the goal to new coordinates -------- |
    double dx, dy, dz;

    dx = msg->pose.pose.position.x - odometry.pose.pose.position.x;
    dy = msg->pose.pose.position.y - odometry.pose.pose.position.y;
    dz = msg->pose.pose.position.z - odometry.pose.pose.position.z;
    double dyaw = msg_yaw - odom_yaw;

    goal_x += dx;
    goal_y += dy;
    goal_z += dz;
    goal_yaw += dyaw;
    have_goal = true;

    // | -------------------- update the state -------------------- |

    state_x = msg->pose.pose.position.x;
    state_y = msg->pose.pose.position.y;
    state_z = msg->pose.pose.position.z;
    state_yaw = msg_yaw;

    // | ------- copy the new odometry as the current state ------- |

    current_horizontal_speed = sqrt(pow(msg->twist.twist.linear.x, 2) + pow(msg->twist.twist.linear.y, 2));
    current_vertical_speed   = msg->twist.twist.linear.z;
    current_heading          = atan2(goal_y - state_y, goal_x - state_x);

    // | ---------- switch to stop motion, which should  ---------- |

    changeState(STOP_MOTION_STATE);
  }

  //}

  // | -------------- setpoint topics and services -------------- |


/* //{ goTo() service */

const mrs_msgs::Vec4Response::ConstPtr WallTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {
  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goTo() topic */

bool WallTracker::goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg) {
  return false;
}

//}

/* //{ goToRelative() topic */

const mrs_msgs::Vec4Response::ConstPtr WallTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {
  return mrs_msgs::Vec4Response::Ptr();
}

//}

/* //{ goToRelative() topic */

bool WallTracker::goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg) {
  return false;
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Vec1Response::ConstPtr WallTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ goToAltitude() topic */

bool WallTracker::goToAltitude(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

/* //{ setYaw() service */

const mrs_msgs::Vec1Response::ConstPtr WallTracker::setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYaw() topic */

bool WallTracker::setYaw(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Vec1Response::ConstPtr WallTracker::setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd) {
  return mrs_msgs::Vec1Response::Ptr();
}

//}

/* //{ setYawRelative() topic */

bool WallTracker::setYawRelative(const std_msgs::Float64ConstPtr &msg) {
  return false;
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr WallTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsResponse::ConstPtr WallTracker::setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsResponse::Ptr();
}

//}

  // | --------------------- motion routines -------------------- |

  /* //{ approachWall() */

  void WallTracker::approachWall(void) {

    current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed        = 0;
      current_horizontal_acceleration = 0;
    } else {
      current_horizontal_acceleration = -horizontal_acceleration_;
    }
  }

  //}
  
  /* //{ yawControl() */

  void WallTracker::yawControl(void) {

    current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed        = 0;
      current_horizontal_acceleration = 0;
    } else {
      current_horizontal_acceleration = -horizontal_acceleration_;
    }
  }

  //}
 
  /* //{ coordinatesChange() */

  void WallTracker::coordinateChange(void) {

    current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed        = 0;
      current_horizontal_acceleration = 0;
    } else {
      current_horizontal_acceleration = -horizontal_acceleration_;
    }
  }

  //}
  
  /* //{ detachWall() */

  void WallTracker::detachWall(void) {

    current_horizontal_speed -= horizontal_acceleration_ * tracker_dt_;

    if (current_horizontal_speed < 0) {
      current_horizontal_speed        = 0;
      current_horizontal_acceleration = 0;
    } else {
      current_horizontal_acceleration = -horizontal_acceleration_;
    }
  }

  //}

  // | ------------------------- timers ------------------------- |

  /* //{ mainTimer() */

  void WallTracker::mainTimer(const ros::TimerEvent &event) {

    if (!is_active) {
      return;
    }

    mrs_lib::Routine profiler_routine = profiler->createRoutine("main", tracker_loop_rate_, 0.002, event);

    {
      std::scoped_lock lock(mutex_constraints, mutex_odometry, mutex_goal, mutex_state);

      switch (current_state_horizontal) {

        case IDLE_STATE:

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
    }
  }

  //}
}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::WallTracker, mrs_uav_manager::Tracker)
