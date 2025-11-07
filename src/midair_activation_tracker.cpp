/* includes //{ */

#include <rclcpp/rclcpp.hpp>

#include <mrs_uav_managers/tracker.h>

#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>

#include <ament_index_cpp/get_package_share_directory.hpp>

//}

namespace mrs_uav_trackers
{

namespace midair_activation_tracker
{

/* //{ class MidairActivationTracker */

class MidairActivationTracker : public mrs_uav_managers::Tracker {
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

  bool callbacks_enabled_ = true;

  std::string _uav_name_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  // | ---------------- the tracker's inner state --------------- |

  bool is_initialized_ = false;
  bool is_active_      = false;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool MidairActivationTracker::initialize(const rclcpp::Node::SharedPtr                                        &node,
                                         std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers,
                                         std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  node_  = node;
  clock_ = node->get_clock();

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  // | ---------- loading params using the parent's nh ---------- |

  mrs_lib::ParamLoader param_loader_parent(common_handlers->parent_node, "ControlManager");

  param_loader_parent.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader_parent.loadedSuccessfully()) {
    RCLCPP_ERROR(node_->get_logger(), "[MidairActivationTracker]: Could not load all parameters!");
    return false;
  }

  // | ---------------- load plugin's parameters ---------------- |

  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") +
                                              "/config/private/midair_activation_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") +
                                              "/config/public/midair_activation_tracker.yaml");

  if (!private_handlers->param_loader->loadedSuccessfully()) {
    RCLCPP_ERROR(node_->get_logger(), "[MidairActivationTracker]: could not load all parameters!");
    return false;
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(common_handlers->parent_node, "MidairActivationTracker", _profiler_enabled_);

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  RCLCPP_INFO(node_->get_logger(), "[MidairActivationTracker]: initialized");

  return true;
}

//}

/* destroy() //{ */

void MidairActivationTracker::destroy(void) {
}

//}

/* //{ activate() */

std::tuple<bool, std::string> MidairActivationTracker::activate([[maybe_unused]] const std::optional<mrs_msgs::msg::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  is_active_ = true;

  ss << "activated";
  RCLCPP_INFO_STREAM(node_->get_logger(), "[MidairActivationTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void MidairActivationTracker::deactivate(void) {

  is_active_ = false;

  RCLCPP_INFO(node_->get_logger(), "[MidairActivationTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool MidairActivationTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

std::optional<mrs_msgs::msg::TrackerCommand>
MidairActivationTracker::update(const mrs_msgs::msg::UavState                                      &uav_state,
                                [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  mrs_lib::Routine    profiler_routine = profiler_.createRoutine("update");
  mrs_lib::ScopeTimer timer =
      mrs_lib::ScopeTimer(node_, "MidairActivationTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  mrs_msgs::msg::TrackerCommand tracker_cmd;

  tracker_cmd.header.frame_id = uav_state.header.frame_id;
  tracker_cmd.header.stamp    = clock_->now();

  tracker_cmd.position.x = uav_state.pose.position.x;
  tracker_cmd.position.y = uav_state.pose.position.y;
  tracker_cmd.position.z = uav_state.pose.position.z;

  tracker_cmd.velocity.x = uav_state.velocity.linear.x;
  tracker_cmd.velocity.y = uav_state.velocity.linear.y;
  tracker_cmd.velocity.z = uav_state.velocity.linear.z;

  try {
    tracker_cmd.heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    tracker_cmd.heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getYaw();
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MidairActivationTracker]: could not get heading");
  }

  tracker_cmd.use_position_vertical   = true;
  tracker_cmd.use_position_horizontal = true;

  tracker_cmd.use_velocity_vertical   = true;
  tracker_cmd.use_velocity_horizontal = true;

  tracker_cmd.use_heading = true;

  RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 100, "[MidairActivationTracker]: outputting cmd");

  return {tracker_cmd};
}

//}

/* //{ getStatus() */

const mrs_msgs::msg::TrackerStatus MidairActivationTracker::getStatus() {

  mrs_msgs::msg::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std::shared_ptr<std_srvs::srv::SetBool::Response>
MidairActivationTracker::enableCallbacks([[maybe_unused]] const std::shared_ptr<std_srvs::srv::SetBool::Request> &request) {

  std::shared_ptr<std_srvs::srv::SetBool::Response> response = std::make_shared<std_srvs::srv::SetBool::Response>();

  response->message = "callbacks are always disabled";
  response->success = true;

  return response;
}

//}

/* switchOdometrySource() //{ */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::msg::UavState &new_uav_state) {

  return nullptr;
}

//}

/* //{ hover() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::hover([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ startTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::startTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ stopTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::stopTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ resumeTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::resumeTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ gotoTrajectoryStart() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MidairActivationTracker::gotoTrajectoryStart([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  return nullptr;
}

//}

/* //{ setConstraints() */

const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response>
MidairActivationTracker::setConstraints([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Request> &request) {

  std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response> response = std::make_shared<mrs_msgs::srv::DynamicsConstraintsSrv::Response>();

  response->success = true;
  response->message = "constraints updated";

  return response;
}

//}

/* //{ setReference() */

const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response>
MidairActivationTracker::setReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Request> &request) {

  return nullptr;
}

//}

/* //{ setVelocityReference() */

const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response>
MidairActivationTracker::setVelocityReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Request> &request) {

  return nullptr;
}

//}

/* //{ setTrajectoryReference() */

const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response>
MidairActivationTracker::setTrajectoryReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Request> &request) {

  return nullptr;
}

//}

} // namespace midair_activation_tracker

} // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::midair_activation_tracker::MidairActivationTracker, mrs_uav_managers::Tracker)
