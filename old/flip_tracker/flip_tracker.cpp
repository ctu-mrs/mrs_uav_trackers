/* includes //{ */

#include <ros/ros.h>
#include <ros/package.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>

#include <dynamic_reconfigure/server.h>
#include <mrs_uav_trackers/flip_trackerConfig.h>

#include <mrs_msgs/String.h>
#include <mrs_msgs/VelocityReferenceSrv.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

//}

/* using //{ */

using vec2_t = mrs_lib::geometry::vec_t<2>;
using vec3_t = mrs_lib::geometry::vec_t<3>;

using radians  = mrs_lib::geometry::radians;
using sradians = mrs_lib::geometry::sradians;

//}

/* defines //{ */

#define FLIPPING_PULSE_STOP_TILT ((2.0 / 3.0) * M_PI)
#define INNERTIA_PULSE_STOP_TILT ((2.0 / 3.0) * M_PI)

typedef enum
{

  STATE_IDLE,
  STATE_ACCELERATION,
  STATE_FLIPPING_PULSE,
  STATE_FLIPPING_INTERTIA,
  STATE_RECOVERY,

} States_t;

//}

namespace mrs_uav_trackers
{

namespace flip_tracker
{

/* //{ class FlipTracker */

class FlipTracker : public mrs_uav_managers::Tracker {
public:
  bool initialize(const ros::NodeHandle &nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers);

  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::TrackerCommand>   update(const mrs_msgs::UavState &uav_state, const mrs_uav_managers::Controller::ControlOutput &last_control_output);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState &new_uav_state);

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

  std::string _uav_name_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  // | --------------------- service server --------------------- |

  ros::ServiceServer service_server_flip_;

  bool callbackFlip(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ------------------- tracker constraints ------------------ |

  mrs_msgs::DynamicsConstraints constraints_;
  std::mutex                    mutex_constraints_;

  // | ---------------- the tracker's inner state --------------- |

  bool is_initialized_ = false;
  bool is_active_      = false;

  // | ----------------------- parameters ----------------------- |

  double _activation_max_velocity_;
  double _activation_max_acceleration_;
  double _activation_max_heading_rate_;

  double z_acceleration_acc_;
  /* double z_pos_lost_by_flipping_; */
  double z_vel_gained_by_flipping_;
  double z_acceleration_duration_;

  double _recovery_duration_;

  double _innertia_timeout_factor_;
  double _innertia_timeout_;

  double _pulse_timeout_factor_;
  double _pulse_timeout_;

  // | ------------------------ flipping ------------------------ |

  mrs_msgs::TrackerCommand activation_cmd_;
  ros::Time                state_change_time_;

  States_t   current_state_ = STATE_IDLE;
  std::mutex mutex_current_state_;

  double initial_heading_;

  ros::Time inertia_time_started_;

  // | ------------------------ routines ------------------------ |

  bool checkState(void);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;

  // | --------------- dynamic reconfigure server --------------- |

  void dynamicReconfigureCallback(mrs_uav_trackers::flip_trackerConfig &config, uint32_t level);

  boost::recursive_mutex                       config_mutex_;
  typedef mrs_uav_trackers::flip_trackerConfig Config;
  typedef dynamic_reconfigure::Server<Config>  ReconfigureServer;
  boost::shared_ptr<ReconfigureServer>         reconfigure_server_;
  mrs_uav_trackers::flip_trackerConfig         drs_params_;
  std::mutex                                   mutex_drs_params_;

  // | ------------------------- rampup ------------------------- |

  double _rampup_speed_;

  bool      rampup_active_ = false;
  double    rampup_acc_;
  double    rampup_duration_;
  ros::Time rampup_start_time_;
  ros::Time rampup_last_time_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool FlipTracker::initialize(const ros::NodeHandle &nh, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                             std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  nh_ = nh;

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  // | ---------- loading params using the parent's nh ---------- |

  mrs_lib::ParamLoader param_loader_parent(common_handlers->parent_nh, "ControlManager");

  param_loader_parent.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader_parent.loadedSuccessfully()) {
    ROS_ERROR("[FlipTracker]: Could not load all parameters!");
    return false;
  }

  // | --------------- loading plugin's parameters -------------- |

  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/private/flip_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ros::package::getPath("mrs_uav_trackers") + "/config/public/flip_tracker.yaml");

  /* const std::string yaml_prefix = "mrs_uav_trackers/flip_tracker/"; */
  const std::string yaml_prefix = "";

  private_handlers->param_loader->loadParam(yaml_prefix + "activation_limits/max_velocity", _activation_max_velocity_);
  private_handlers->param_loader->loadParam(yaml_prefix + "activation_limits/max_acceleration", _activation_max_acceleration_);
  private_handlers->param_loader->loadParam(yaml_prefix + "activation_limits/max_heading_rate", _activation_max_heading_rate_);

  private_handlers->param_loader->loadParam(yaml_prefix + "phases/z_acceleration/mode", drs_params_.z_mode);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/z_acceleration/acceleration", drs_params_.z_acceleration);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/z_acceleration/throttle", drs_params_.z_throttle);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/z_acceleration/velocity_gain_from_rot", drs_params_.velocity_gain_from_rot);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/flipping_pulse/attitude_rate", drs_params_.attitude_rate);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/flipping_pulse/axis", drs_params_.axis);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/flipping_pulse/direction", drs_params_.direction);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/flipping_pulse/timeout_factor", _pulse_timeout_factor_);

  private_handlers->param_loader->loadParam(yaml_prefix + "rampup/speed", _rampup_speed_);

  private_handlers->param_loader->loadParam(yaml_prefix + "phases/recovery/duration", _recovery_duration_);
  private_handlers->param_loader->loadParam(yaml_prefix + "phases/innertia/timeout_factor", _innertia_timeout_factor_);

  _pulse_timeout_ = _pulse_timeout_factor_ * (FLIPPING_PULSE_STOP_TILT / drs_params_.attitude_rate);
  ROS_INFO("[FlipTracker]: initializing pulse timeout: %.4f s", _pulse_timeout_);
  _innertia_timeout_ = _innertia_timeout_factor_ * (((M_PI - FLIPPING_PULSE_STOP_TILT) + (M_PI - INNERTIA_PULSE_STOP_TILT)) / drs_params_.attitude_rate);
  ROS_INFO("[FlipTracker]: initializing inertia timeout: %.4f s", _innertia_timeout_);

  if (!private_handlers->param_loader->loadedSuccessfully()) {
    ROS_ERROR("[FlipTracker]: could not load all parameters!");
    return false;
  }

  // | --------------- dynamic reconfigure server --------------- |

  reconfigure_server_.reset(new ReconfigureServer(config_mutex_, nh_));
  reconfigure_server_->updateConfig(drs_params_);
  ReconfigureServer::CallbackType f = boost::bind(&FlipTracker::dynamicReconfigureCallback, this, _1, _2);
  reconfigure_server_->setCallback(f);

  // | --------------------- service servers -------------------- |

  service_server_flip_ = nh_.advertiseService("flip", &FlipTracker::callbackFlip, this);

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_nh, "FlipTracker", _profiler_enabled_);

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[FlipTracker]: initialized");

  return true;
}

//}

/* //{ activate() */

std::tuple<bool, std::string> FlipTracker::activate(const std::optional<mrs_msgs::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {
    ss << "odometry not set";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  if (!last_tracker_cmd) {
    ss << "last position cmd not valid";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  // check for the states during activation
  if (!checkState()) {
    ss << "current states violates the activation limits";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  // save the activation cmd
  {
    activation_cmd_ = *last_tracker_cmd;

    activation_cmd_.velocity.x = 0;
    activation_cmd_.velocity.y = 0;
    activation_cmd_.velocity.z = 0;

    activation_cmd_.acceleration.x = 0;
    activation_cmd_.acceleration.y = 0;
    activation_cmd_.acceleration.z = 0;

    activation_cmd_.jerk.x = 0;
    activation_cmd_.jerk.y = 0;
    activation_cmd_.jerk.z = 0;

    activation_cmd_.heading_rate = 0;
  }

  mrs_lib::set_mutexed(mutex_current_state_, STATE_IDLE, current_state_);

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[FlipTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void FlipTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[FlipTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool FlipTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::TrackerCommand> FlipTracker::update(const mrs_msgs::UavState &                                          uav_state,
                                                            [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  auto current_state = mrs_lib::get_mutexed(mutex_current_state_, current_state_);
  auto drs_params    = mrs_lib::get_mutexed(mutex_drs_params_, drs_params_);

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer("FlipTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;

    got_uav_state_ = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  mrs_msgs::TrackerCommand tracker_cmd = activation_cmd_;

  tracker_cmd.header.stamp = ros::Time::now();

  // rotate the drone's z axis
  tf2::Transform uav_state_transform = mrs_lib::AttitudeConverter(uav_state.pose.orientation);
  tf2::Vector3   uav_z_in_world      = uav_state_transform * tf2::Vector3(0, 0, 1);

  // calculate the angle between the drone's z axis and the world's z axis
  double tilt_angle = acos(uav_z_in_world.dot(tf2::Vector3(0, 0, 1)));

  double mass = common_handlers_->getMass();
  double g    = common_handlers_->g;

  // calculate the z acceleration
  double hover_throttle = mrs_lib::quadratic_throttle_model::forceToThrottle(common_handlers_->throttle_model, mass * g);

  switch (current_state) {

    case STATE_IDLE: {

      tracker_cmd.use_position_vertical   = true;
      tracker_cmd.use_position_horizontal = true;

      tracker_cmd.use_velocity_vertical   = true;
      tracker_cmd.use_velocity_horizontal = true;

      tracker_cmd.use_acceleration = false;
      tracker_cmd.use_jerk         = false;
      tracker_cmd.use_snap         = false;

      tracker_cmd.use_heading              = true;
      tracker_cmd.use_heading_rate         = false;
      tracker_cmd.use_heading_acceleration = false;
      tracker_cmd.use_heading_jerk         = false;

      tracker_cmd.use_orientation = false;

      tracker_cmd.use_attitude_rate = false;

      break;
    }

    case STATE_ACCELERATION: {

      tracker_cmd.use_position_vertical   = false;
      tracker_cmd.use_position_horizontal = true;

      tracker_cmd.use_velocity_vertical   = true;
      tracker_cmd.use_velocity_horizontal = true;

      tracker_cmd.use_acceleration = true;

      tracker_cmd.use_jerk = false;

      tracker_cmd.use_snap = false;

      tracker_cmd.use_heading              = true;
      tracker_cmd.use_heading_rate         = false;
      tracker_cmd.use_heading_acceleration = false;
      tracker_cmd.use_heading_jerk         = false;

      tracker_cmd.use_orientation = false;

      tracker_cmd.use_attitude_rate = false;

      if (rampup_active_) {

        // deactivate the rampup when the times up
        if (fabs((ros::Time::now() - rampup_start_time_).toSec()) >= rampup_duration_) {

          rampup_active_             = false;
          tracker_cmd.acceleration.z = z_acceleration_acc_;

          ROS_INFO("[FlipTracker]: rampup finished");

        } else {

          double rampup_dt = (ros::Time::now() - rampup_last_time_).toSec();

          rampup_acc_ += _rampup_speed_ * rampup_dt;

          rampup_last_time_ = ros::Time::now();

          tracker_cmd.acceleration.z = rampup_acc_;

          ROS_INFO_THROTTLE(0.1, "[FlipTracker]: ramping up acceleration, %.4f", rampup_acc_);
        }

      } else {
        tracker_cmd.acceleration.z = z_acceleration_acc_;
      }

      tracker_cmd.acceleration.z = z_acceleration_acc_;

      tracker_cmd.velocity.z = z_vel_gained_by_flipping_;

      if ((ros::Time::now() - state_change_time_).toSec() >= 2 * z_acceleration_duration_) {
        ROS_INFO("[FlipTracker]: acceleration timeouted, recovering");
        mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);
        state_change_time_ = ros::Time::now();
      }

      if (uav_state.velocity.linear.z > 0.95 * z_vel_gained_by_flipping_) {
        ROS_INFO("[FlipTracker]: z vel exceeded %.2f, flipping", z_vel_gained_by_flipping_);
        mrs_lib::set_mutexed(mutex_current_state_, STATE_FLIPPING_PULSE, current_state_);
        state_change_time_ = ros::Time::now();
      }

      break;
    }

    case STATE_FLIPPING_PULSE: {

      tracker_cmd.use_position_vertical   = false;
      tracker_cmd.use_position_horizontal = false;

      tracker_cmd.use_velocity_vertical   = false;
      tracker_cmd.use_velocity_horizontal = false;

      tracker_cmd.use_acceleration = false;

      tracker_cmd.use_jerk = false;

      tracker_cmd.use_snap = false;

      tracker_cmd.use_heading              = false;
      tracker_cmd.use_heading_rate         = false;
      tracker_cmd.use_heading_acceleration = false;
      tracker_cmd.use_heading_jerk         = false;

      tracker_cmd.use_orientation = false;

      double direction = drs_params.direction == 0 ? 1.0 : -1.0;

      if (drs_params.axis == 0) {
        tracker_cmd.attitude_rate.x = direction * drs_params.attitude_rate;
      } else if (drs_params.axis == 1) {
        tracker_cmd.attitude_rate.y = direction * drs_params.attitude_rate;
      }

      tracker_cmd.use_attitude_rate = true;

      if (tilt_angle <= M_PI / 2.0) {
        tracker_cmd.throttle = hover_throttle * cos(tilt_angle);
      } else {
        tracker_cmd.throttle = 0;
      }
      tracker_cmd.use_throttle = true;

      if ((ros::Time::now() - state_change_time_).toSec() >= _pulse_timeout_) {

        mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

        ROS_ERROR("[FlipTracker]: pulse phase took too long (%.4f s, timeout %.4f s), startin recovery", (ros::Time::now() - state_change_time_).toSec(),
                  _pulse_timeout_);

        state_change_time_ = ros::Time::now();

      } else if (tilt_angle > FLIPPING_PULSE_STOP_TILT) {

        mrs_lib::set_mutexed(mutex_current_state_, STATE_FLIPPING_INTERTIA, current_state_);

        ROS_INFO("[FlipTracker]: pulse phase took %.4f s, (timeout %.4f s)", (ros::Time::now() - state_change_time_).toSec(), _pulse_timeout_);

        state_change_time_ = ros::Time::now();
      }

      break;
    }

    case STATE_FLIPPING_INTERTIA: {

      tracker_cmd.use_position_vertical   = false;
      tracker_cmd.use_position_horizontal = false;

      tracker_cmd.use_velocity_vertical   = false;
      tracker_cmd.use_velocity_horizontal = false;

      tracker_cmd.use_acceleration = false;

      tracker_cmd.use_jerk = false;

      tracker_cmd.use_snap = false;

      tracker_cmd.use_heading              = false;
      tracker_cmd.use_heading_rate         = false;
      tracker_cmd.use_heading_acceleration = false;
      tracker_cmd.use_heading_jerk         = false;

      tracker_cmd.use_orientation = false;

      tracker_cmd.use_attitude_rate = true;

      double direction = drs_params.direction == 0 ? 1.0 : -1.0;

      if (drs_params.axis == 0) {
        tracker_cmd.attitude_rate.x = direction * drs_params.attitude_rate;
      } else if (drs_params.axis == 1) {
        tracker_cmd.attitude_rate.y = direction * drs_params.attitude_rate;
      }

      tracker_cmd.throttle     = hover_throttle;
      tracker_cmd.use_throttle = true;

      if ((ros::Time::now() - state_change_time_).toSec() >= _innertia_timeout_) {

        mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

        ROS_ERROR("[FlipTracker]: inertia phase took too long (%.4f s, timeout %.4f s), startin recovery", (ros::Time::now() - state_change_time_).toSec(),
                  _innertia_timeout_);

        state_change_time_ = ros::Time::now();

      } else if (tilt_angle <= INNERTIA_PULSE_STOP_TILT) {

        mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

        ROS_INFO("[FlipTracker]: inertia phase took %.4f s, (timeout %.4f s)", (ros::Time::now() - state_change_time_).toSec(), _innertia_timeout_);

        state_change_time_ = ros::Time::now();
      }

      break;
    }

    case STATE_RECOVERY: {

      activation_cmd_.position.z = uav_state.pose.position.z;

      tracker_cmd.use_position_vertical   = false;
      tracker_cmd.use_position_horizontal = true;

      tracker_cmd.use_velocity_vertical   = true;
      tracker_cmd.use_velocity_horizontal = true;

      tracker_cmd.use_acceleration = false;
      tracker_cmd.use_jerk         = false;
      tracker_cmd.use_snap         = false;

      tracker_cmd.use_heading              = true;
      tracker_cmd.use_heading_rate         = false;
      tracker_cmd.use_heading_acceleration = false;
      tracker_cmd.use_heading_jerk         = false;

      tracker_cmd.use_orientation = false;

      tracker_cmd.use_attitude_rate = false;

      if ((ros::Time::now() - state_change_time_).toSec() >= _recovery_duration_) {

        mrs_lib::set_mutexed(mutex_current_state_, STATE_IDLE, current_state_);
        state_change_time_ = ros::Time::now();
      }

      break;
    }
  }

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus FlipTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr FlipTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[FlipTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[FlipTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState &new_uav_state) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr FlipTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr FlipTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  {
    std::scoped_lock lock(mutex_constraints_);

    constraints_ = cmd->constraints;
  }

  mrs_msgs::DynamicsConstraintsSrvResponse res;

  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr(new mrs_msgs::DynamicsConstraintsSrvResponse(res));
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr FlipTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr FlipTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr FlipTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | ------------------------ callbacks ----------------------- |

/* callbackFlip() //{ */

bool FlipTracker::callbackFlip([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (!is_initialized_)
    return false;

  if (!is_active_) {

    std::stringstream ss;
    ss << "can not flip, not activated";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  if (!callbacks_enabled_) {

    std::stringstream ss;
    ss << "can not flip, callbacks disabled";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  auto current_state = mrs_lib::get_mutexed(mutex_current_state_, current_state_);

  if (current_state != STATE_IDLE) {

    std::stringstream ss;
    ss << "can not flip, not idling";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  if (!checkState()) {

    std::stringstream ss;
    ss << "can not flip, current state violates the activation limits";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  double mass = common_handlers_->getMass();
  double g    = common_handlers_->g;

  auto drs_params = mrs_lib::get_mutexed(mutex_drs_params_, drs_params_);

  // calculate the z acceleration
  if (drs_params.z_mode == 0) {
    z_acceleration_acc_ = drs_params.z_acceleration;
    ROS_INFO("[FlipTracker]: accelerating with %.2f m/s^2", z_acceleration_acc_);
  } else if (drs_params.z_mode == 1) {
    z_acceleration_acc_ = (mrs_lib::quadratic_throttle_model::throttleToForce(common_handlers_->throttle_model, drs_params.z_throttle) / mass) - g;
    ROS_INFO("[FlipTracker]: accelerating with throttle %.2f => %.2f m/s^2", drs_params.z_throttle, z_acceleration_acc_);
  } else {
    std::stringstream ss;
    ss << "invalid acceleration mode";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

  if (z_acceleration_acc_ > constraints.vertical_ascending_acceleration) {

    std::stringstream ss;
    ss << "can not flip, the required acceleration is outside of constraints";

    res.message = ss.str();
    res.success = false;

    ROS_WARN_STREAM("[FlipTracker]: " << ss.str());

    return true;
  }

  // calculate what velocity will the UAV gain while perfoming the flipping maneuvre
  /* z_pos_lost_by_flipping_ = 0.5 * g * pow(((drs_params.velocity_gain_from_rot * M_PI) / drs_params.attitude_rate), 2.0); */

  z_vel_gained_by_flipping_ = g * ((drs_params.velocity_gain_from_rot * M_PI) / drs_params.attitude_rate);

  // calculate how long do we have to accelerate to create a positive velocity for the maneuvre
  /* z_acceleration_duration_ = sqrt((2 * z_pos_lost_by_flipping_) / z_acceleration_acc_); */

  z_acceleration_duration_ = z_vel_gained_by_flipping_ / z_acceleration_acc_;

  ROS_INFO("[FlipTracker]: z manouvre: acceleration: %.2f, duration: %.2f", z_acceleration_acc_, z_acceleration_duration_);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  try {
    initial_heading_ = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[FlipTracker]: could not calculate UAV heading");
  }

  std::stringstream ss;
  ss << "flipping";

  res.message = ss.str();
  res.success = true;

  ROS_INFO_STREAM("[FlipTracker]: " << ss.str());

  rampup_active_     = true;
  rampup_start_time_ = ros::Time::now();
  rampup_last_time_  = ros::Time::now();
  rampup_duration_   = fabs(z_acceleration_acc_) / _rampup_speed_;
  rampup_acc_        = 0;

  mrs_lib::set_mutexed(mutex_current_state_, STATE_ACCELERATION, current_state_);

  state_change_time_ = ros::Time::now();

  return true;
}

//}

/* dynamicReconfigureCallback() //{ */

void FlipTracker::dynamicReconfigureCallback(mrs_uav_trackers::flip_trackerConfig &config, [[maybe_unused]] uint32_t level) {

  std::scoped_lock lock(mutex_drs_params_);

  drs_params_ = config;

  ROS_INFO("[FlipTracker]: DRS updated");
}

//}

// | ------------------------ routines ------------------------ |

/* checkState() //{ */

bool FlipTracker::checkState(void) {

  auto   uav_state    = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  double heading_rate = 0;

  std::stringstream ss;

  try {
    heading_rate = mrs_lib::AttitudeConverter(uav_state_.pose.orientation).getHeadingRate(uav_state_.velocity.angular);
  }
  catch (...) {
    ss << "could not get current heading rate";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return false;
  }

  if (fabs(uav_state.velocity.linear.x) > _activation_max_velocity_ || fabs(uav_state.velocity.linear.y) > _activation_max_velocity_ ||
      fabs(uav_state.velocity.linear.z) > _activation_max_velocity_) {
    ss << "the current velocity exceeds the limits";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return false;
  }

  if (fabs(uav_state.acceleration.linear.x) > _activation_max_acceleration_ || fabs(uav_state.acceleration.linear.y) > _activation_max_acceleration_ ||
      fabs(uav_state.acceleration.linear.z) > _activation_max_acceleration_) {
    ss << "the current acceleration exceeds the limits";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return false;
  }

  if (fabs(heading_rate) > _activation_max_heading_rate_) {
    ss << "the current heading reate exceeds the limits";
    ROS_ERROR_STREAM("[FlipTracker]: " << ss.str());
    return false;
  }

  return true;
}

//}

}  // namespace flip_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::flip_tracker::FlipTracker, mrs_uav_managers::Tracker)
