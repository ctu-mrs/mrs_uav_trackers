/* includes //{ */

#include <rclcpp/rclcpp.hpp>

#include <mrs_uav_managers/tracker.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/service_server_handler.h>
#include <mrs_lib/geometry/misc.h>
#include <mrs_lib/dynparam_mgr.h>

#include <ament_index_cpp/get_package_share_directory.hpp>

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

/* drs params //{ */


//}

/* //{ class FlipTracker */

class FlipTracker : public mrs_uav_managers::Tracker {
public:
  bool initialize(const rclcpp::Node::SharedPtr &node, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers);

  void destroy(void);

  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::msg::TrackerCommand> &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::msg::TrackerCommand>            update(const mrs_msgs::msg::UavState                     &uav_state,
                                                                 const mrs_uav_managers::Controller::ControlOutput &last_control_output);
  const mrs_msgs::msg::TrackerStatus                      getStatus();
  const std::shared_ptr<std_srvs::srv::SetBool::Response> enableCallbacks(const std::shared_ptr<std_srvs::srv::SetBool::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> switchOdometrySource(const mrs_msgs::msg::UavState &new_uav_state);

  const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response> setReference(const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Request> &request);
  const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response>
  setVelocityReference(const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Request> &request);
  const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response>
  setTrajectoryReference(const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Request> &request);

  const std::shared_ptr<std_srvs::srv::Trigger::Response> hover(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> startTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> stopTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> resumeTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> gotoTrajectoryStart(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);

  const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response>
  setConstraints(const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Request> &request);

private:
  rclcpp::Node::SharedPtr  node_;
  rclcpp::Clock::SharedPtr clock_;

  rclcpp::CallbackGroup::SharedPtr cbkgrp_ss_;

  bool callbacks_enabled_ = true;

  std::string _uav_name_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  // | --------------------- service server --------------------- |

  mrs_lib::ServiceServerHandler<std_srvs::srv::Trigger> ss_flip_;

  bool callbackFlip([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
                    const std::shared_ptr<std_srvs::srv::Trigger::Response>                 response);

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::msg::UavState uav_state_;
  bool                    got_uav_state_ = false;
  std::mutex              mutex_uav_state_;

  // | ------------------- tracker constraints ------------------ |

  mrs_msgs::msg::DynamicsConstraints constraints_;
  std::mutex                         mutex_constraints_;

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

  mrs_msgs::msg::TrackerCommand activation_cmd_;
  rclcpp::Time                  state_change_time_;

  States_t   current_state_ = STATE_IDLE;
  std::mutex mutex_current_state_;

  double initial_heading_;

  rclcpp::Time inertia_time_started_;

  // | ------------------------ routines ------------------------ |

  bool checkState(void);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;

  // | ------------------- dynamic reconfigure ------------------ |

  std::shared_ptr<mrs_lib::DynparamMgr> dynparam_mgr_;

  struct DrsParams_t
  {
    double velocity_gain_from_rot;
    double z_throttle;
    double z_acceleration;
    double attitude_rate;
    int    axis;
    int    z_mode;
    int    direction;
  };

  DrsParams_t drs_params_;
  std::mutex  mutex_drs_params_;

  // | ------------------------- rampup ------------------------- |

  double _rampup_speed_;

  bool         rampup_active_ = false;
  double       rampup_acc_;
  double       rampup_duration_;
  rclcpp::Time rampup_start_time_;
  rclcpp::Time rampup_last_time_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool FlipTracker::initialize(const rclcpp::Node::SharedPtr &node, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                             std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  node_  = node;
  clock_ = node->get_clock();

  cbkgrp_ss_ = node_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  // | ---------- loading params using the parent's nh ---------- |

  mrs_lib::ParamLoader param_loader_parent(common_handlers->parent_node, "FlipTracker");

  param_loader_parent.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader_parent.loadedSuccessfully()) {
    RCLCPP_ERROR(node_->get_logger(), "could not load all parameters!");
    return false;
  }

  dynparam_mgr_ = std::make_shared<mrs_lib::DynparamMgr>(node_, mutex_drs_params_);

  // | ---------------- load plugin's parameters ---------------- |

  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") + "/config/private/flip_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") + "/config/public/flip_tracker.yaml");

  dynparam_mgr_->get_param_provider().copyYamls(private_handlers->param_loader->getParamProvider());

  private_handlers->param_loader->loadParam("activation_limits/max_velocity", _activation_max_velocity_);
  private_handlers->param_loader->loadParam("activation_limits/max_acceleration", _activation_max_acceleration_);
  private_handlers->param_loader->loadParam("activation_limits/max_heading_rate", _activation_max_heading_rate_);

  dynparam_mgr_->register_param("phases/z_acceleration/mode", &drs_params_.z_mode, mrs_lib::DynparamMgr::range_t<int>(0, 2));
  dynparam_mgr_->register_param("phases/z_acceleration/acceleration", &drs_params_.z_acceleration, mrs_lib::DynparamMgr::range_t<double>(0, 10.0));
  dynparam_mgr_->register_param("phases/z_acceleration/throttle", &drs_params_.z_throttle, mrs_lib::DynparamMgr::range_t<double>(0, 1.0));
  dynparam_mgr_->register_param("phases/z_acceleration/velocity_gain_from_rot", &drs_params_.velocity_gain_from_rot,
                                mrs_lib::DynparamMgr::range_t<double>(0, 2.0));
  dynparam_mgr_->register_param("phases/flipping_pulse/attitude_rate", &drs_params_.attitude_rate, mrs_lib::DynparamMgr::range_t<double>(0, 30.0));
  dynparam_mgr_->register_param("phases/flipping_pulse/axis", &drs_params_.axis, mrs_lib::DynparamMgr::range_t<int>(0, 1));
  dynparam_mgr_->register_param("phases/flipping_pulse/direction", &drs_params_.direction, mrs_lib::DynparamMgr::range_t<int>(0, 1));

  private_handlers->param_loader->loadParam("phases/flipping_pulse/timeout_factor", _pulse_timeout_factor_);

  private_handlers->param_loader->loadParam("rampup/speed", _rampup_speed_);

  private_handlers->param_loader->loadParam("phases/recovery/duration", _recovery_duration_);
  private_handlers->param_loader->loadParam("phases/innertia/timeout_factor", _innertia_timeout_factor_);

  _pulse_timeout_ = _pulse_timeout_factor_ * (FLIPPING_PULSE_STOP_TILT / drs_params_.attitude_rate);
  RCLCPP_INFO(node_->get_logger(), "initializing pulse timeout: %.4f s", _pulse_timeout_);
  _innertia_timeout_ = _innertia_timeout_factor_ * (((M_PI - FLIPPING_PULSE_STOP_TILT) + (M_PI - INNERTIA_PULSE_STOP_TILT)) / drs_params_.attitude_rate);
  RCLCPP_INFO(node_->get_logger(), "initializing inertia timeout: %.4f s", _innertia_timeout_);

  if (!private_handlers->param_loader->loadedSuccessfully() || !dynparam_mgr_->loaded_successfully()) {
    RCLCPP_ERROR(node_->get_logger(), "could not load all parameters!");
    return false;
  }

  // | --------------------- service servers -------------------- |

  ss_flip_ = mrs_lib::ServiceServerHandler<std_srvs::srv::Trigger>(node_, "~/" + private_handlers_->name_space + "/flip",
                                                                   std::bind(&FlipTracker::callbackFlip, this, std::placeholders::_1, std::placeholders::_2),
                                                                   cbkgrp_ss_);

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_node, "FlipTracker", _profiler_enabled_);

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  RCLCPP_INFO(node_->get_logger(), "initialized");

  return true;
}

//}

/* destroy() //{ */

void FlipTracker::destroy(void) {
}

//}

/* //{ activate() */

std::tuple<bool, std::string> FlipTracker::activate(const std::optional<mrs_msgs::msg::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {
    ss << "odometry not set";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return std::tuple(false, ss.str());
  }

  if (!last_tracker_cmd) {
    ss << "last position cmd not valid";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return std::tuple(false, ss.str());
  }

  // check for the states during activation
  if (!checkState()) {
    ss << "current states violates the activation limits";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
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
  RCLCPP_INFO_STREAM(node_->get_logger(), "" << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void FlipTracker::deactivate(void) {

  is_active_ = false;

  RCLCPP_INFO(node_->get_logger(), "deactivated");
}

//}

/* //{ resetStatic() */

bool FlipTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::msg::TrackerCommand> FlipTracker::update(const mrs_msgs::msg::UavState                                      &uav_state,
                                                                 [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  auto current_state = mrs_lib::get_mutexed(mutex_current_state_, current_state_);
  auto drs_params    = mrs_lib::get_mutexed(mutex_drs_params_, drs_params_);

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer(node_, "FlipTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = uav_state;

    got_uav_state_ = true;
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  mrs_msgs::msg::TrackerCommand tracker_cmd = activation_cmd_;

  tracker_cmd.header.stamp = clock_->now();

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
      if (std::abs((clock_->now() - rampup_start_time_).seconds()) >= rampup_duration_) {

        rampup_active_             = false;
        tracker_cmd.acceleration.z = z_acceleration_acc_;

        RCLCPP_INFO(node_->get_logger(), "rampup finished");

      } else {

        double rampup_dt = (clock_->now() - rampup_last_time_).seconds();

        rampup_acc_ += _rampup_speed_ * rampup_dt;

        rampup_last_time_ = clock_->now();

        tracker_cmd.acceleration.z = rampup_acc_;

        RCLCPP_INFO_THROTTLE(node_->get_logger(), *clock_, 100, "ramping up acceleration, %.4f", rampup_acc_);
      }

    } else {
      tracker_cmd.acceleration.z = z_acceleration_acc_;
    }

    tracker_cmd.acceleration.z = z_acceleration_acc_;

    tracker_cmd.velocity.z = z_vel_gained_by_flipping_;

    if ((clock_->now() - state_change_time_).seconds() >= 2 * z_acceleration_duration_) {
      RCLCPP_INFO(node_->get_logger(), "acceleration timeouted, recovering");
      mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);
      state_change_time_ = clock_->now();
    }

    if (uav_state.velocity.linear.z > 0.95 * z_vel_gained_by_flipping_) {
      RCLCPP_INFO(node_->get_logger(), "z vel exceeded %.2f, flipping", z_vel_gained_by_flipping_);
      mrs_lib::set_mutexed(mutex_current_state_, STATE_FLIPPING_PULSE, current_state_);
      state_change_time_ = clock_->now();
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

    if ((clock_->now() - state_change_time_).seconds() >= _pulse_timeout_) {

      mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

      RCLCPP_ERROR(node_->get_logger(), "pulse phase took too long (%.4f s, timeout %.4f s), startin recovery", (clock_->now() - state_change_time_).seconds(),
                   _pulse_timeout_);

      state_change_time_ = clock_->now();

    } else if (tilt_angle > FLIPPING_PULSE_STOP_TILT) {

      mrs_lib::set_mutexed(mutex_current_state_, STATE_FLIPPING_INTERTIA, current_state_);

      RCLCPP_INFO(node_->get_logger(), "pulse phase took %.4f s, (timeout %.4f s)", (clock_->now() - state_change_time_).seconds(), _pulse_timeout_);

      state_change_time_ = clock_->now();
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

    if ((clock_->now() - state_change_time_).seconds() >= _innertia_timeout_) {

      mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

      RCLCPP_ERROR(node_->get_logger(), "inertia phase took too long (%.4f s, timeout %.4f s), startin recovery",
                   (clock_->now() - state_change_time_).seconds(), _innertia_timeout_);

      state_change_time_ = clock_->now();

    } else if (tilt_angle <= INNERTIA_PULSE_STOP_TILT) {

      mrs_lib::set_mutexed(mutex_current_state_, STATE_RECOVERY, current_state_);

      RCLCPP_INFO(node_->get_logger(), "inertia phase took %.4f s, (timeout %.4f s)", (clock_->now() - state_change_time_).seconds(), _innertia_timeout_);

      state_change_time_ = clock_->now();
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

    if ((clock_->now() - state_change_time_).seconds() >= _recovery_duration_) {

      mrs_lib::set_mutexed(mutex_current_state_, STATE_IDLE, current_state_);
      state_change_time_ = clock_->now();
    }

    break;
  }
  }

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::msg::TrackerStatus FlipTracker::getStatus() {

  mrs_msgs::msg::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std::shared_ptr<std_srvs::srv::SetBool::Response> FlipTracker::enableCallbacks(const std::shared_ptr<std_srvs::srv::SetBool::Request> &request) {

  std::shared_ptr<std_srvs::srv::SetBool::Response> response = std::make_shared<std_srvs::srv::SetBool::Response>();

  std::stringstream ss;

  if (request->data != callbacks_enabled_) {

    callbacks_enabled_ = request->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "" << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "" << ss.str());
  }

  response->message = ss.str();
  response->success = true;

  return response;
}

//}

/* switchOdometrySource() //{ */

const std::shared_ptr<std_srvs::srv::Trigger::Response> FlipTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::msg::UavState &new_uav_state) {

  return nullptr;
}

//}

/* //{ hover() */

const std::shared_ptr<std_srvs::srv::Trigger::Response> FlipTracker::hover([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ startTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
FlipTracker::startTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {
  return nullptr;
}

//}

/* //{ stopTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
FlipTracker::stopTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {
  return nullptr;
}

//}

/* //{ resumeTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
FlipTracker::resumeTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {
  return nullptr;
}

//}

/* //{ gotoTrajectoryStart() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
FlipTracker::gotoTrajectoryStart([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {
  return nullptr;
}

//}

/* //{ setConstraints() */

const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response>
FlipTracker::setConstraints([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Request> &request) {

  {
    std::scoped_lock lock(mutex_constraints_);

    constraints_ = request->constraints;
  }

  std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response> response = std::make_shared<mrs_msgs::srv::DynamicsConstraintsSrv::Response>();

  response->success = true;
  response->message = "constraints updated";

  return response;
}

//}

/* //{ setReference() */

const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response>
FlipTracker::setReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Request> &request) {

  return nullptr;
}

//}

/* //{ setVelocityReference() */

const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response>
FlipTracker::setVelocityReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Request> &request) {

  return nullptr;
}

//}

/* //{ setTrajectoryReference() */

const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response>
FlipTracker::setTrajectoryReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Request> &request) {

  return nullptr;
}

//}

// | ------------------------ callbacks ----------------------- |

/* callbackFlip() //{ */

bool FlipTracker::callbackFlip([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
                               const std::shared_ptr<std_srvs::srv::Trigger::Response>                 response) {

  if (!is_initialized_)
    return false;

  if (!is_active_) {

    std::stringstream ss;
    ss << "can not flip, not activated";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  if (!callbacks_enabled_) {

    std::stringstream ss;
    ss << "can not flip, callbacks disabled";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  auto current_state = mrs_lib::get_mutexed(mutex_current_state_, current_state_);

  if (current_state != STATE_IDLE) {

    std::stringstream ss;
    ss << "can not flip, not idling";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  if (!checkState()) {

    std::stringstream ss;
    ss << "can not flip, current state violates the activation limits";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  double mass = common_handlers_->getMass();
  double g    = common_handlers_->g;

  auto drs_params = mrs_lib::get_mutexed(mutex_drs_params_, drs_params_);

  // calculate the z acceleration
  if (drs_params.z_mode == 0) {
    z_acceleration_acc_ = drs_params.z_acceleration;
    RCLCPP_INFO(node_->get_logger(), "accelerating with %.2f m/s^2", z_acceleration_acc_);
  } else if (drs_params.z_mode == 1) {
    z_acceleration_acc_ = (mrs_lib::quadratic_throttle_model::throttleToForce(common_handlers_->throttle_model, drs_params.z_throttle) / mass) - g;
    RCLCPP_INFO(node_->get_logger(), "accelerating with throttle %.2f => %.2f m/s^2", drs_params.z_throttle, z_acceleration_acc_);
  } else {
    std::stringstream ss;
    ss << "invalid acceleration mode";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

  if (z_acceleration_acc_ > constraints.vertical_ascending_acceleration) {

    std::stringstream ss;
    ss << "can not flip, the required acceleration is outside of constraints";

    response->message = ss.str();
    response->success = false;

    RCLCPP_WARN_STREAM(node_->get_logger(), "" << ss.str());

    return true;
  }

  // calculate what velocity will the UAV gain while perfoming the flipping maneuvre
  z_vel_gained_by_flipping_ = g * ((drs_params.velocity_gain_from_rot * M_PI) / drs_params.attitude_rate);

  // calculate how long do we have to accelerate to create a positive velocity for the maneuvre
  z_acceleration_duration_ = z_vel_gained_by_flipping_ / z_acceleration_acc_;

  RCLCPP_INFO(node_->get_logger(), "z manouvre: acceleration: %.2f, duration: %.2f", z_acceleration_acc_, z_acceleration_duration_);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  try {
    initial_heading_ = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "could not calculate UAV heading");
  }

  std::stringstream ss;
  ss << "flipping";

  response->message = ss.str();
  response->success = true;

  RCLCPP_INFO_STREAM(node_->get_logger(), "" << ss.str());

  rampup_active_     = true;
  rampup_start_time_ = clock_->now();
  rampup_last_time_  = clock_->now();
  rampup_duration_   = fabs(z_acceleration_acc_) / _rampup_speed_;
  rampup_acc_        = 0;

  mrs_lib::set_mutexed(mutex_current_state_, STATE_ACCELERATION, current_state_);

  state_change_time_ = clock_->now();

  return true;
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
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return false;
  }

  if (fabs(uav_state.velocity.linear.x) > _activation_max_velocity_ || fabs(uav_state.velocity.linear.y) > _activation_max_velocity_ ||
      fabs(uav_state.velocity.linear.z) > _activation_max_velocity_) {
    ss << "the current velocity exceeds the limits";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return false;
  }

  if (fabs(uav_state.acceleration.linear.x) > _activation_max_acceleration_ || fabs(uav_state.acceleration.linear.y) > _activation_max_acceleration_ ||
      fabs(uav_state.acceleration.linear.z) > _activation_max_acceleration_) {
    ss << "the current acceleration exceeds the limits";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return false;
  }

  if (fabs(heading_rate) > _activation_max_heading_rate_) {
    ss << "the current heading reate exceeds the limits";
    RCLCPP_ERROR_STREAM(node_->get_logger(), "" << ss.str());
    return false;
  }

  return true;
}

//}

} // namespace flip_tracker

} // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::flip_tracker::FlipTracker, mrs_uav_managers::Tracker)
