#define VERSION "0.0.5.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_manager/Tracker.h>

#include <commons.h>

#include <mrs_msgs/SpeedTrackerCommand.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>
#include <mrs_lib/mutex.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

//}

#define STOP_THR 1e-3

namespace mrs_trackers
{

namespace speed_tracker
{

/* //{ class SpeedTracker */

class SpeedTracker : public mrs_uav_manager::Tracker {
public:
  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers);
  bool activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd);
  void deactivate(void);
  bool resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);

  const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

  std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers_;

  ros::Publisher publisher_rviz_marker_;

  // | ------------------------ uav state ----------------------- |

  mrs_msgs::UavState uav_state_;
  bool               got_uav_state_ = false;
  std::mutex         mutex_uav_state_;

  double uav_x_;
  double uav_y_;
  double uav_z_;
  double uav_yaw_;
  double uav_roll_;
  double uav_pitch_;

  // | ---------------- the tracker's inner staet --------------- |

  double _tracker_loop_rate_;
  double _tracker_dt_;
  bool   is_initialized_ = false;
  bool   is_active_      = false;

  // | -------------------------- goal -------------------------- |

  double                        got_command_ = false;
  std::mutex                    mutex_command_;
  mrs_msgs::SpeedTrackerCommand external_command_;
  ros::Time                     external_command_time_;

  double _external_command_timeout_;

  ros::Subscriber subscriber_command_;
  void            callbackCommand(const mrs_msgs::SpeedTrackerCommand &msg);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler_;
  bool              _profiler_enabled_ = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void SpeedTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                              [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers) {

  _uav_name_             = uav_name;
  this->common_handlers_ = common_handlers;

  ros::NodeHandle nh_(parent_nh, "speed_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "SpeedTracker");

  param_loader.load_param("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[SpeedTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.load_param("command_timeout", _external_command_timeout_);

  param_loader.load_param("enable_profiler", _profiler_enabled_);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[SpeedTracker]: could not load all parameters!");
    ros::shutdown();
  }

  external_command_time_ = ros::Time(0);

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler_ = mrs_lib::Profiler(nh_, "SpeedTracker", _profiler_enabled_);

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  subscriber_command_ = nh_.subscribe("command_in", 1, &SpeedTracker::callbackCommand, this, ros::TransportHints().tcpNoDelay());

  // --------------------------------------------------------------
  // |                         publishers                         |
  // --------------------------------------------------------------

  publisher_rviz_marker_ = nh_.advertise<visualization_msgs::MarkerArray>("rviz_marker_out", 1);

  is_initialized_ = true;

  ROS_INFO("[SpeedTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

bool SpeedTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  if (!got_uav_state_) {
    ROS_ERROR("[SpeedTracker]: can not activate, odometry not set");
    return false;
  }

  std::scoped_lock lock(mutex_command_);

  if (!got_command_) {

    ROS_ERROR("[SpeedTracker]: can not activate, missing command");
    return false;
  }

  auto external_command_time = mrs_lib::get_mutexed(mutex_command_, external_command_time_);

  // timeout the external command
  if ((ros::Time::now() - external_command_time).toSec() > _external_command_timeout_) {
    ROS_ERROR("[SpeedTracker]: can not activate, the command is too old");
    return false;
  }

  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  is_active_ = true;

  ROS_INFO("[SpeedTracker]: activated");

  return true;
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

const mrs_msgs::PositionCommand::ConstPtr SpeedTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
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

  {
    auto external_command_time = mrs_lib::get_mutexed(mutex_command_, external_command_time_);

    // timeout the external command
    if (got_command_ && (ros::Time::now() - external_command_time).toSec() > _external_command_timeout_) {
      ROS_ERROR("[SpeedTracker]: command timeouted, returning nil");
      return mrs_msgs::PositionCommand::Ptr();
    }
  }

  mrs_msgs::PositionCommand position_cmd;

  auto [uav_state, uav_yaw] = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_, uav_yaw_);
  auto external_command     = mrs_lib::get_mutexed(mutex_command_, external_command_);

  position_cmd.header.stamp    = ros::Time::now();
  position_cmd.header.frame_id = uav_state.header.frame_id;

  position_cmd.position.x = uav_state.pose.position.x;
  position_cmd.position.y = uav_state.pose.position.y;

  if (external_command.use_velocity) {
    position_cmd.velocity.x              = external_command.velocity.x;
    position_cmd.velocity.y              = external_command.velocity.y;
    position_cmd.velocity.z              = external_command.velocity.z;
    position_cmd.use_velocity_horizontal = true;
    position_cmd.use_velocity_vertical   = true;
  } else {
    position_cmd.velocity.x              = uav_state.velocity.linear.x;
    position_cmd.velocity.y              = uav_state.velocity.linear.y;
    position_cmd.velocity.z              = uav_state.velocity.linear.z;
    position_cmd.use_velocity_horizontal = false;
    position_cmd.use_velocity_vertical   = false;
  }

  if (external_command.use_height) {
    position_cmd.position.z            = external_command.height;
    position_cmd.use_position_vertical = true;
  } else {
    position_cmd.position.z            = uav_state.pose.position.z;
    position_cmd.use_position_vertical = false;
  }

  if (external_command.use_acceleration) {
    position_cmd.acceleration.x   = external_command.acceleration.x;
    position_cmd.acceleration.y   = external_command.acceleration.y;
    position_cmd.acceleration.z   = external_command.acceleration.z;
    position_cmd.use_acceleration = true;
  } else if (external_command.use_force) {
    position_cmd.acceleration.x   = external_command.force.x / cmd->total_mass;
    position_cmd.acceleration.y   = external_command.force.y / cmd->total_mass;
    position_cmd.acceleration.z   = external_command.force.z / cmd->total_mass;
    position_cmd.use_acceleration = true;
  } else {
    position_cmd.acceleration.x   = uav_state.acceleration.linear.x;
    position_cmd.acceleration.y   = uav_state.acceleration.linear.y;
    position_cmd.acceleration.z   = uav_state.acceleration.linear.z;
    position_cmd.use_acceleration = false;
  }

  if (external_command.use_yaw) {
    position_cmd.yaw     = external_command.yaw;
    position_cmd.use_yaw = true;
  } else {
    position_cmd.yaw     = uav_yaw;
    position_cmd.use_yaw = false;
  }

  if (external_command.use_yaw_dot) {
    position_cmd.yaw_dot     = external_command.yaw_dot;
    position_cmd.use_yaw_dot = true;
  } else {
    position_cmd.yaw_dot     = uav_state.velocity.angular.z;
    position_cmd.use_yaw_dot = false;
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

void SpeedTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr SpeedTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr SpeedTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

// | --------------------- custom methods --------------------- |

/* callbackCommand() //{ */

void SpeedTracker::callbackCommand(const mrs_msgs::SpeedTrackerCommand &msg) {

  if (!is_initialized_)
    return;

  mrs_lib::Routine profiler_routine = profiler_.createRoutine("callbackCommand");

  mrs_msgs::SpeedTrackerCommand external_command = msg;

  // transform the command

  // transform velocity

  if (msg.use_velocity) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = external_command.velocity.x;
    vector3.vector.y = external_command.velocity.y;
    vector3.vector.z = external_command.velocity.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      external_command.velocity.x = ret.value().vector.x;
      external_command.velocity.y = ret.value().vector.y;
      external_command.velocity.z = ret.value().vector.z;
    }
  }

  // transform yaw

  if (msg.use_yaw) {

    mrs_msgs::ReferenceStamped temp_ref;
    temp_ref.header = msg.header;

    temp_ref.reference.yaw = external_command.yaw;

    auto ret = common_handlers_->transformer->transformSingle("", temp_ref);

    if (ret) {
      external_command.yaw = ret.value().reference.yaw;
    }
  }

  // transform acceleration

  if (msg.use_acceleration) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = external_command.acceleration.x;
    vector3.vector.y = external_command.acceleration.y;
    vector3.vector.z = external_command.acceleration.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      external_command.acceleration.x = ret.value().vector.x;
      external_command.acceleration.y = ret.value().vector.y;
      external_command.acceleration.z = ret.value().vector.z;
    }
  }

  // transform force

  if (msg.use_force) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = external_command.force.x;
    vector3.vector.y = external_command.force.y;
    vector3.vector.z = external_command.force.z;

    auto ret = common_handlers_->transformer->transformSingle("", vector3);

    if (ret) {
      external_command.force.x = vector3.vector.x;
      external_command.force.y = vector3.vector.y;
      external_command.force.z = vector3.vector.z;
    }
  }

  {
    std::scoped_lock lock(mutex_command_);

    external_command_      = external_command;
    external_command_time_ = ros::Time::now();
    got_command_           = true;
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

  if (external_command.use_velocity) {

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

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + external_command.velocity.x;
    point.y = uav_state_.pose.position.y + external_command.velocity.y;
    point.z = uav_state_.pose.position.z + external_command.velocity.z;

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
  if (external_command.use_acceleration) {

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

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + external_command.acceleration.x;
    point.y = uav_state_.pose.position.y + external_command.acceleration.y;
    point.z = uav_state_.pose.position.z + external_command.acceleration.z;

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
  if (external_command.use_force) {

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

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    //}

    /* origin //{ */
    point.x = uav_state_.pose.position.x;
    point.y = uav_state_.pose.position.y;
    point.z = uav_state_.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state_.pose.position.x + external_command.force.x;
    point.y = uav_state_.pose.position.y + external_command.force.y;
    point.z = uav_state_.pose.position.z + external_command.force.z;

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

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::speed_tracker::SpeedTracker, mrs_uav_manager::Tracker)
