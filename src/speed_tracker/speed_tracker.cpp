#define VERSION "0.0.6.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <mrs_msgs/SpeedTrackerCommand.h>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

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

namespace speed_tracker
{

/* //{ class SpeedTracker */

class SpeedTracker : public mrs_uav_managers::Tracker {
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
  bool callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

  std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_;

  ros::Publisher publisher_rviz_marker_;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  // | ------------------- tracker constraints ------------------ |

  mrs_msgs::DynamicsConstraints constraints_;
  std::mutex                    mutex_constraints_;

  // | ---------------- the tracker's inner state --------------- |

  bool is_initialized_  = false;
  bool is_active_       = false;
  bool first_iteration_ = true;

  double _external_command_timeout_;

  mrs_lib::SubscribeHandler<mrs_msgs::SpeedTrackerCommand> sh_command_;

  void callbackCommand(mrs_lib::SubscribeHandler<mrs_msgs::SpeedTrackerCommand> &sh_ptr);

  // stores the post-processed and transformed command
  mrs_msgs::SpeedTrackerCommand command_;
  std::mutex                    mutex_command_;
  ros::Time                     last_command_time_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void SpeedTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                              [[maybe_unused]] std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  ros::NodeHandle nh_(parent_nh, "speed_tracker");

  ros::Time::waitForValid();

  // | --------------------- load the params -------------------- |

  mrs_lib::ParamLoader param_loader(nh_, "SpeedTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[SpeedTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("command_timeout", _external_command_timeout_);

  param_loader.loadParam("enable_profiler", _profiler_enabled_);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[SpeedTracker]: could not load all parameters!");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler_ = mrs_lib::Profiler(nh_, "SpeedTracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "SpeedTracker";
  shopts.threadsafe      = true;
  shopts.autostart       = true;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_command_ = mrs_lib::SubscribeHandler<mrs_msgs::SpeedTrackerCommand>(shopts, "command_in", &SpeedTracker::callbackCommand, this);

  // | ----------------------- publishers ----------------------- |

  publisher_rviz_marker_ = nh_.advertise<visualization_msgs::MarkerArray>("rviz_marker_out", 1);

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[SpeedTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> SpeedTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  std::stringstream ss;

  if (!got_uav_state_) {
    ss << "odometry not set";
    ROS_ERROR_STREAM("[SpeedTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  if (!sh_command_.hasMsg()) {
    ss << "missing command";
    ROS_ERROR_STREAM("[SpeedTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  ros::Time external_command_time = sh_command_.lastMsgTime();

  // timeout the external command
  if ((ros::Time::now() - external_command_time).toSec() > _external_command_timeout_) {
    ss << "the command is too old";
    ROS_ERROR_STREAM("[SpeedTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  is_active_ = true;

  ss << "activated";
  ROS_INFO_STREAM("[SpeedTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void SpeedTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[SpeedTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool SpeedTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr SpeedTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                               [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("update");

  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = *uav_state;

    got_uav_state_ = true;
  }

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state_.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[SpeedTracker]: could not calculate UAV heading");

    return mrs_msgs::PositionCommand::Ptr();
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  ros::Time external_command_time = sh_command_.lastMsgTime();

  // timeout the external command
  if (sh_command_.hasMsg() && (ros::Time::now() - external_command_time).toSec() > _external_command_timeout_) {
    ROS_ERROR("[SpeedTracker]: command timeouted, returning nil");
    first_iteration_ = true;
    return mrs_msgs::PositionCommand::Ptr();
  }

  auto command = mrs_lib::get_mutexed(mutex_command_, command_);

  mrs_msgs::PositionCommand position_cmd;

  position_cmd.header.stamp    = ros::Time::now();
  position_cmd.header.frame_id = uav_state->header.frame_id;

  position_cmd.position.x = uav_state->pose.position.x;
  position_cmd.position.y = uav_state->pose.position.y;

  if (command.use_velocity) {
    position_cmd.velocity.x              = command.velocity.x;
    position_cmd.velocity.y              = command.velocity.y;
    position_cmd.velocity.z              = command.velocity.z;
    position_cmd.use_velocity_horizontal = true;
    position_cmd.use_velocity_vertical   = true;
  } else {
    position_cmd.velocity.x              = uav_state->velocity.linear.x;
    position_cmd.velocity.y              = uav_state->velocity.linear.y;
    position_cmd.velocity.z              = uav_state->velocity.linear.z;
    position_cmd.use_velocity_horizontal = false;
    position_cmd.use_velocity_vertical   = false;
  }

  if (command.use_height) {
    position_cmd.position.z            = command.height;
    position_cmd.use_position_vertical = true;
  } else {
    position_cmd.position.z            = uav_state->pose.position.z;
    position_cmd.use_position_vertical = false;
  }

  if (command.use_acceleration) {
    position_cmd.acceleration.x   = command.acceleration.x;
    position_cmd.acceleration.y   = command.acceleration.y;
    position_cmd.acceleration.z   = command.acceleration.z;
    position_cmd.use_acceleration = true;
  } else if (command.use_force) {
    position_cmd.acceleration.x   = command.force.x / last_attitude_cmd->total_mass;
    position_cmd.acceleration.y   = command.force.y / last_attitude_cmd->total_mass;
    position_cmd.acceleration.z   = command.force.z / last_attitude_cmd->total_mass;
    position_cmd.use_acceleration = true;
  } else {
    position_cmd.acceleration.x   = 0;
    position_cmd.acceleration.y   = 0;
    position_cmd.acceleration.z   = 0;
    position_cmd.use_acceleration = false;
  }

  if (command.use_heading) {
    position_cmd.heading     = command.heading;
    position_cmd.use_heading = true;
  } else {
    position_cmd.heading     = uav_heading;
    position_cmd.use_heading = false;
  }

  if (command.use_heading_rate) {
    position_cmd.heading_rate     = command.heading_rate;
    position_cmd.use_heading_rate = true;
  } else {
    position_cmd.heading_rate     = uav_state->velocity.angular.z;
    position_cmd.use_heading_rate = false;
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus SpeedTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr SpeedTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[SpeedTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[SpeedTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr SpeedTracker::setConstraints([
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

const mrs_msgs::ReferenceSrvResponse::ConstPtr SpeedTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr SpeedTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

// | --------------------- custom methods --------------------- |

/* callbackCommand() //{ */

void SpeedTracker::callbackCommand(mrs_lib::SubscribeHandler<mrs_msgs::SpeedTrackerCommand> &sh_ptr) {

  if (!is_initialized_)
    return;

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("callbackCommand");

  mrs_msgs::SpeedTrackerCommandConstPtr external_command = sh_ptr.getMsg();

  double dt;
  if (first_iteration_) {

    last_command_time_ = ros::Time::now();
    first_iteration_   = false;

    {
      std::scoped_lock lock(mutex_command_);

      command_ = *external_command;
    }

    return;
  } else {
    dt                 = (ros::Time::now() - last_command_time_).toSec();
    last_command_time_ = ros::Time::now();

    if (dt <= 1e-4) {
      ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: the command dt is %.5f, returning", dt);
      return;
    }
  }

  mrs_msgs::SpeedTrackerCommand transformed_command = *external_command;

  auto old_command = mrs_lib::get_mutexed(mutex_command_, command_);
  auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);
  auto uav_state   = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_heading;

  try {
    uav_heading = mrs_lib::AttitudeConverter(uav_state_.pose.orientation).getHeading();
  }
  catch (...) {
    ROS_ERROR_THROTTLE(1.0, "[SpeedTracker]: could not calculate UAV heading");
    return;
  }

  // transform the command

  // transform velocity

  if (transformed_command.use_velocity) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;

    vector3.vector.x = transformed_command.velocity.x;
    vector3.vector.y = transformed_command.velocity.y;
    vector3.vector.z = transformed_command.velocity.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      transformed_command.velocity.x = ret.value().vector.x;
      transformed_command.velocity.y = ret.value().vector.y;
      transformed_command.velocity.z = ret.value().vector.z;
    } else {
      return;
    }

    /* horizontal speed limit //{ */

    {
      double des_horizontal_speed = sqrt(pow(transformed_command.velocity.x, 2) + pow(transformed_command.velocity.y, 2));

      if (des_horizontal_speed > constraints.horizontal_speed) {

        double des_speed_heading = atan2(transformed_command.velocity.y, transformed_command.velocity.x);

        transformed_command.velocity.x = cos(des_speed_heading) * constraints.horizontal_speed;
        transformed_command.velocity.y = sin(des_speed_heading) * constraints.horizontal_speed;
      }
    }

    //}

    /* horizontal speed change rate limit //{ */

    {
      Eigen::Vector2d hor_speed_derivative =
          Eigen::Vector2d(transformed_command.velocity.x - old_command.velocity.x, transformed_command.velocity.y - old_command.velocity.y) / dt;

      // exceeding the maximum acceleration
      if (hor_speed_derivative.norm() > constraints.horizontal_acceleration) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting speed change rate");
        double direction = atan2(hor_speed_derivative[1], hor_speed_derivative[0]);

        transformed_command.velocity.x = old_command.velocity.x + cos(direction) * constraints.horizontal_acceleration * dt;
        transformed_command.velocity.y = old_command.velocity.y + sin(direction) * constraints.horizontal_acceleration * dt;
      }
    }

    //}

    /* vertical speed limit //{ */

    {
      // if ascending
      if (transformed_command.velocity.z > constraints.vertical_ascending_speed) {

        transformed_command.velocity.z = constraints.vertical_ascending_speed;
      }

      // if descending
      if (transformed_command.velocity.z < -constraints.vertical_descending_speed) {

        transformed_command.velocity.z = -constraints.vertical_descending_speed;
      }
    }

    //}

    /* vertical speed change rate //{ */

    {

      double vert_speed_derivative = (transformed_command.velocity.z - old_command.velocity.z) / dt;

      if (vert_speed_derivative > constraints.vertical_ascending_acceleration) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting vertical ascending speed change rate");
        transformed_command.velocity.z = old_command.velocity.z + constraints.vertical_ascending_acceleration * dt;

      } else if (vert_speed_derivative < -constraints.vertical_descending_acceleration) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting vertical descending speed change rate");
        transformed_command.velocity.z = old_command.velocity.z - constraints.vertical_descending_acceleration * dt;
      }
    }

    //}
  }

  /* transform and constrain heading //{ */

  if (transformed_command.use_heading) {

    mrs_msgs::ReferenceStamped temp_ref;
    temp_ref.header = transformed_command.header;

    temp_ref.reference.heading = transformed_command.heading;

    auto ret = common_handlers_->transformer->transformSingle("", temp_ref);

    if (ret) {

      // calculate the produced heading rate
      double des_hdg_rate = sradians::diff(ret.value().reference.heading, old_command.heading) / dt;

      // saturate the change in the desired heading
      if (des_hdg_rate > constraints.heading_speed) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting change of the desired heading using constraints");
        transformed_command.heading = old_command.heading + constraints.heading_speed * dt;

      } else if (des_hdg_rate < -constraints.heading_speed) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting change of the desired heading using constraints");
        transformed_command.heading = old_command.heading - constraints.heading_speed * dt;

      } else {

        transformed_command.heading = ret.value().reference.heading;
      }

    } else {
      return;
    }
  } else {
    transformed_command.use_heading = false;
    transformed_command.heading     = uav_heading;
  }

  //}

  if (transformed_command.use_heading_rate) {

    if (transformed_command.heading_rate > constraints.heading_speed) {
      transformed_command.heading_rate = constraints.heading_speed;
    } else if (transformed_command.heading_rate < -constraints.heading_speed) {
      transformed_command.heading_rate = -constraints.heading_speed;
    }
  }

  if (transformed_command.use_acceleration) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;

    vector3.vector.x = transformed_command.acceleration.x;
    vector3.vector.y = transformed_command.acceleration.y;
    vector3.vector.z = transformed_command.acceleration.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      transformed_command.acceleration.x = ret.value().vector.x;
      transformed_command.acceleration.y = ret.value().vector.y;
      transformed_command.acceleration.z = ret.value().vector.z;
    } else {
      return;
    }

    /* horizontal acceleration limit //{ */

    {
      double des_horizontal_acceleration = sqrt(pow(transformed_command.acceleration.x, 2) + pow(transformed_command.acceleration.y, 2));

      if (des_horizontal_acceleration > constraints.horizontal_acceleration) {

        double des_acc_heading = atan2(transformed_command.acceleration.y, transformed_command.acceleration.x);

        transformed_command.acceleration.x = cos(des_acc_heading) * constraints.horizontal_acceleration;
        transformed_command.acceleration.y = sin(des_acc_heading) * constraints.horizontal_acceleration;
      }
    }

    //}

    /* horizontal acceleration change rate limit //{ */

    {
      Eigen::Vector2d hor_acc_derivative =
          Eigen::Vector2d(transformed_command.acceleration.x - old_command.acceleration.x, transformed_command.acceleration.y - old_command.acceleration.y) /
          (dt);

      // exceeding the maximum acceleration
      if (hor_acc_derivative.norm() > constraints.horizontal_jerk) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting acceleration change rate");
        double direction = atan2(hor_acc_derivative[1], hor_acc_derivative[0]);

        transformed_command.acceleration.x = old_command.acceleration.x + cos(direction) * constraints.horizontal_jerk * dt;
        transformed_command.acceleration.y = old_command.acceleration.y + sin(direction) * constraints.horizontal_jerk * dt;
      }
    }

    //}

    /* vertical acceleration limit //{ */

    {
      // if ascending
      if (transformed_command.acceleration.z > constraints.vertical_ascending_acceleration) {

        transformed_command.acceleration.z = constraints.vertical_ascending_acceleration;
      }

      // if descending
      if (transformed_command.acceleration.z < -constraints.vertical_descending_acceleration) {

        transformed_command.acceleration.z = -constraints.vertical_descending_acceleration;
      }
    }

    //}

    /* vertical acceleration change rate //{ */

    {

      double vert_acc_derivative = (transformed_command.acceleration.z - old_command.acceleration.z) / dt;

      if (vert_acc_derivative > constraints.vertical_ascending_jerk) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting vertical ascending acceleration change rate");
        transformed_command.acceleration.z = old_command.acceleration.z + constraints.vertical_ascending_jerk * dt;

      } else if (vert_acc_derivative < -constraints.vertical_descending_jerk) {

        ROS_WARN_THROTTLE(1.0, "[SpeedTracker]: limitting vertical descending acceleration change rate");
        transformed_command.acceleration.z = old_command.acceleration.z - constraints.vertical_descending_jerk * dt;
      }
    }

    //}
  }

  // transform force

  if (transformed_command.use_force) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = transformed_command.header;

    vector3.vector.x = transformed_command.force.x;
    vector3.vector.y = transformed_command.force.y;
    vector3.vector.z = transformed_command.force.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      transformed_command.force.x = vector3.vector.x;
      transformed_command.force.y = vector3.vector.y;
      transformed_command.force.z = vector3.vector.z;
    } else {
      return;
    }
  }

  // check the feasibility of the height
  {
    double height_derivative = (transformed_command.height - old_command.height) / dt;

    if (height_derivative > constraints.vertical_ascending_speed) {

      transformed_command.height = old_command.height + constraints.vertical_ascending_speed * dt;

    } else if (height_derivative < -constraints.vertical_ascending_speed) {

      transformed_command.height = old_command.height - constraints.vertical_descending_speed * dt;
    }

    // saturate the desired height using the safety area
    if (common_handlers_->safety_area.use_safety_area) {

      if (transformed_command.height > common_handlers_->safety_area.getMaxHeight()) {

        transformed_command.height = common_handlers_->safety_area.getMaxHeight();

      } else if (transformed_command.height < common_handlers_->safety_area.getMinHeight()) {

        transformed_command.height = common_handlers_->safety_area.getMinHeight();
      }
    }
  }

  // if not active, nullify the desired speeds and accelerations
  // this will produce a rumpum (using the constraints) after the activation
  if (!is_active_) {

    auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

    transformed_command.velocity.x = 0;
    transformed_command.velocity.y = 0;
    transformed_command.velocity.z = 0;

    transformed_command.acceleration.x = 0;
    transformed_command.acceleration.y = 0;
    transformed_command.acceleration.z = 0;

    try {
      transformed_command.heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
    }
    catch (...) {
      return;
    }

    transformed_command.height = uav_state_.pose.position.z;
  }

  {
    std::scoped_lock lock(mutex_command_);

    command_ = transformed_command;
  }

  if (!is_active_) {
    ROS_INFO_ONCE("[SpeedTracker]: getting command");
  } else {
    ROS_INFO_THROTTLE(5.0, "[SpeedTracker]: getting command");
  }

  // --------------------------------------------------------------
  // |                     publish rviz markers                   |
  // --------------------------------------------------------------

  visualization_msgs::MarkerArray msg_out;

  double id = 0;

  geometry_msgs::Point point;

  /* desired speed //{ */

  if (transformed_command.use_velocity) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "speed_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.velocity.x;
    point.y = uav_state_.pose.position.y + transformed_command.velocity.y;
    point.z = uav_state_.pose.position.z + transformed_command.velocity.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  /* desired acceleration //{ */
  if (transformed_command.use_acceleration) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "speed_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.acceleration.x;
    point.y = uav_state_.pose.position.y + transformed_command.acceleration.y;
    point.z = uav_state_.pose.position.z + transformed_command.acceleration.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  /* desired force //{ */
  if (transformed_command.use_force) {

    std::scoped_lock lock(mutex_uav_state_);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state_.header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "speed_tracker";
    marker.id              = id++;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* position //{ */

    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    //}

    /* orientation //{ */

    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + transformed_command.force.x;
    point.y = uav_state_.pose.position.y + transformed_command.force.y;
    point.z = uav_state_.pose.position.z + transformed_command.force.z;

    marker.points.push_back(point);

    //}

    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;

    marker.color.a = 0.5;
    marker.color.r = 0.0;
    marker.color.g = 0.0;
    marker.color.b = 1.0;

    marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";

    msg_out.markers.push_back(marker);
  }

  //}

  try {
    publisher_rviz_marker_.publish(msg_out);
  }
  catch (...) {
    ROS_ERROR("[SpeedTracker]: exception caught during publishing topic %s", publisher_rviz_marker_.getTopic().c_str());
  }
}

//}

}  // namespace speed_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::speed_tracker::SpeedTracker, mrs_uav_managers::Tracker)
