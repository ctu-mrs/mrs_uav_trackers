/* includes //{ */

#include <ros/ros.h>

#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/Reference.h>
#include <mrs_uav_manager/Tracker.h>

#include <tf/transform_datatypes.h>
#include <mutex>

#include <commons.h>

#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/Profiler.h>

#include <mrs_msgs/SpeedTrackerCommand.h>

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
  bool callbacks_enabled = true;

  std::string uav_name_;

  mrs_uav_manager::CommonHandlers_t const *common_handlers;

  double external_command_timeout_;

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
  // dynamical constraints
  double     yaw_rate_;
  std::mutex mutex_constraints;

private:
  // desired goal
  double                        got_command = false;
  std::mutex                    mutex_command;
  mrs_msgs::SpeedTrackerCommand external_command;
  ros::Time                     external_command_time;

  mrs_msgs::PositionCommand output;

private:
  ros::Subscriber subscriber_command;
  void            callbackCommand(const mrs_msgs::SpeedTrackerCommand &msg);

private:
  ros::Publisher publisher_rviz_marker;

private:
  mrs_lib::Profiler *profiler;
  bool               profiler_enabled_ = false;
  bool               position_mode_    = false;
  bool               tilt_mode_        = false;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void SpeedTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                              [[maybe_unused]] mrs_uav_manager::CommonHandlers_t const *common_handlers) {

  uav_name_             = uav_name;
  this->common_handlers = common_handlers;

  ros::NodeHandle nh_(parent_nh, "speed_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "SpeedTracker");

  param_loader.load_param("command_timeout", external_command_timeout_);

  param_loader.load_param("enable_profiler", profiler_enabled_);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[SpeedTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = new mrs_lib::Profiler(nh_, "SpeedTracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                         subscribers                        |
  // --------------------------------------------------------------

  subscriber_command = nh_.subscribe("command_in", 1, &SpeedTracker::callbackCommand, this, ros::TransportHints().tcpNoDelay());

  // --------------------------------------------------------------
  // |                         publishers                         |
  // --------------------------------------------------------------

  publisher_rviz_marker = nh_.advertise<visualization_msgs::MarkerArray>("rviz_marker_out", 1);

  is_initialized = true;

  ROS_INFO("[SpeedTracker]: initialized");
}

//}

/* //{ activate() */

bool SpeedTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (!got_uav_state) {
    ROS_ERROR("[SpeedTracker]: can't activate(), odometry not set");
    return false;
  }

  std::scoped_lock lock(mutex_command);

  if (!got_command) {

    ROS_ERROR("[SpeedTracker]: cannot activate, missing command");
    return false;
  }

  // timeout the external command
  if ((ros::Time::now() - external_command_time).toSec() > external_command_timeout_) {
    ROS_ERROR("[SpeedTracker]: cannot activate, the command is too old");
    return false;
  }

  // --------------------------------------------------------------
  // |              yaw initial condition  prediction             |
  // --------------------------------------------------------------

  is_active = true;

  ROS_INFO("[SpeedTracker]: activated");

  return true;
}

//}

/* //{ deactivate() */

void SpeedTracker::deactivate(void) {

  is_active = false;

  ROS_INFO("[SpeedTracker]: deactivated");
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr SpeedTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
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

  // timeout the external command
  if (got_command && (ros::Time::now() - external_command_time).toSec() > external_command_timeout_) {
    ROS_ERROR("[SpeedTracker]: command timeouted, returning nil");
    return mrs_msgs::PositionCommand::Ptr();
  }

  output.header.stamp    = ros::Time::now();
  output.header.frame_id = uav_state.header.frame_id;

  {
    std::scoped_lock lock(mutex_uav_state, mutex_command);

    output.position.x = uav_state.pose.position.x;
    output.position.y = uav_state.pose.position.y;

    if (external_command.use_velocity) {
      output.velocity.x              = external_command.velocity.x;
      output.velocity.y              = external_command.velocity.y;
      output.velocity.z              = external_command.velocity.z;
      output.use_velocity_horizontal = true;
      output.use_velocity_vertical   = true;
    } else {
      output.velocity.x              = uav_state.velocity.linear.x;
      output.velocity.y              = uav_state.velocity.linear.y;
      output.velocity.z              = uav_state.velocity.linear.z;
      output.use_velocity_horizontal = false;
      output.use_velocity_vertical   = false;
    }

    if (external_command.use_height) {
      output.position.z            = external_command.height;
      output.use_position_vertical = true;
    } else {
      output.position.z            = uav_state.pose.position.z;
      output.use_position_vertical = false;
    }

    if (external_command.use_acceleration) {
      output.acceleration.x   = external_command.acceleration.x;
      output.acceleration.y   = external_command.acceleration.y;
      output.acceleration.z   = external_command.acceleration.z;
      output.use_acceleration = true;
    } else if (external_command.use_force) {
      output.acceleration.x   = external_command.force.x / cmd->total_mass;
      output.acceleration.y   = external_command.force.y / cmd->total_mass;
      output.acceleration.z   = external_command.force.z / cmd->total_mass;
      output.use_acceleration = true;
    } else {
      output.acceleration.x   = uav_state.acceleration.linear.x;
      output.acceleration.y   = uav_state.acceleration.linear.y;
      output.acceleration.z   = uav_state.acceleration.linear.z;
      output.use_acceleration = false;
    }

    if (external_command.use_yaw) {
      output.yaw     = external_command.yaw;
      output.use_yaw = true;
    } else {
      output.yaw     = uav_yaw;
      output.use_yaw = false;
    }

    if (external_command.use_yaw_dot) {
      output.yaw_dot     = external_command.yaw_dot;
      output.use_yaw_dot = true;
    } else {
      output.yaw_dot     = uav_state.velocity.angular.z;
      output.use_yaw_dot = false;
    }
  }

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(output));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus SpeedTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = callbacks_enabled;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr SpeedTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[100];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[SpeedTracker]: %s", message);

  } else {

    sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
  }

  res.message = message;
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

void SpeedTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &msg) {
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr SpeedTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsResponse::ConstPtr SpeedTracker::setConstraints([[maybe_unused]] const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  return mrs_msgs::TrackerConstraintsResponse::Ptr();
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr SpeedTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goTo() topic */

bool SpeedTracker::goTo([[maybe_unused]] const mrs_msgs::ReferenceConstPtr &msg) {

  return false;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr SpeedTracker::goToRelative([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::ReferenceSrvResponse::Ptr();
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Float64SrvResponse::ConstPtr SpeedTracker::goToAltitude([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYaw() service */

const mrs_msgs::Float64SrvResponse::ConstPtr SpeedTracker::setYaw([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Float64SrvResponse::ConstPtr SpeedTracker::setYawRelative([[maybe_unused]] const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  return mrs_msgs::Float64SrvResponse::Ptr();
}

//}

// | --------------------- custom methods --------------------- |

/* callbackCommand() //{ */

void SpeedTracker::callbackCommand(const mrs_msgs::SpeedTrackerCommand &msg) {

  if (!is_initialized)
    return;

  std::scoped_lock lock(mutex_command);

  mrs_lib::Routine profiler_routine = profiler->createRoutine("callbackCommand");

  mrs_msgs::SpeedTrackerCommand temp_command = msg;

  // transform the command

  // transform velocity

  if (msg.use_velocity) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = temp_command.velocity.x;
    vector3.vector.y = temp_command.velocity.y;
    vector3.vector.z = temp_command.velocity.z;

    common_handlers->transformer.transformVector3Single("", vector3);

    temp_command.velocity.x = vector3.vector.x;
    temp_command.velocity.y = vector3.vector.y;
    temp_command.velocity.z = vector3.vector.z;
  }

  // transform yaw

  if (msg.use_yaw) {

    mrs_msgs::ReferenceStamped temp_ref;
    temp_ref.header = msg.header;

    temp_ref.reference.yaw = temp_command.yaw;

    common_handlers->transformer.transformReferenceSingle("", temp_ref);

    temp_command.yaw = temp_ref.reference.yaw;
  }

  // transform acceleration

  if (msg.use_acceleration) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = temp_command.acceleration.x;
    vector3.vector.y = temp_command.acceleration.y;
    vector3.vector.z = temp_command.acceleration.z;

    common_handlers->transformer.transformVector3Single("", vector3);

    temp_command.acceleration.x = vector3.vector.x;
    temp_command.acceleration.y = vector3.vector.y;
    temp_command.acceleration.z = vector3.vector.z;
  }


  // transform force

  if (msg.use_force) {

    geometry_msgs::Vector3Stamped vector3;
    vector3.header = msg.header;

    vector3.vector.x = temp_command.force.x;
    vector3.vector.y = temp_command.force.y;
    vector3.vector.z = temp_command.force.z;

    common_handlers->transformer.transformVector3Single("", vector3);

    temp_command.force.x = vector3.vector.x;
    temp_command.force.y = vector3.vector.y;
    temp_command.force.z = vector3.vector.z;
  }

  external_command = temp_command;

  got_command = true;

  external_command_time = ros::Time::now();

  if (!is_active) {
    ROS_INFO_ONCE("[SpeedTracker]: getting command");
  } else {
    ROS_INFO_THROTTLE(5.0, "[SpeedTracker]: getting command");
  }

  // --------------------------------------------------------------
  // |                    publishe rviz markers                   |
  // --------------------------------------------------------------

  visualization_msgs::MarkerArray msg_out;

  double id = 0;

  geometry_msgs::Point point;

  /* desired speed //{ */
  if (external_command.use_velocity) {

    std::scoped_lock lock(mutex_uav_state);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state.header.frame_id;
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
    point.x = uav_state.pose.position.x;
    point.y = uav_state.pose.position.y;
    point.z = uav_state.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state.pose.position.x + external_command.velocity.x;
    point.y = uav_state.pose.position.y + external_command.velocity.y;
    point.z = uav_state.pose.position.z + external_command.velocity.z;

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

    std::scoped_lock lock(mutex_uav_state);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state.header.frame_id;
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
    point.x = uav_state.pose.position.x;
    point.y = uav_state.pose.position.y;
    point.z = uav_state.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state.pose.position.x + external_command.acceleration.x;
    point.y = uav_state.pose.position.y + external_command.acceleration.y;
    point.z = uav_state.pose.position.z + external_command.acceleration.z;

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

    std::scoped_lock lock(mutex_uav_state);

    visualization_msgs::Marker marker;

    marker.header.frame_id = uav_state.header.frame_id;
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
    point.x = uav_state.pose.position.x;
    point.y = uav_state.pose.position.y;
    point.z = uav_state.pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state.pose.position.x + external_command.force.x;
    point.y = uav_state.pose.position.y + external_command.force.y;
    point.z = uav_state.pose.position.z + external_command.force.z;

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
    publisher_rviz_marker.publish(msg_out);
  }
  catch (...) {
    ROS_ERROR("[SpeedTracker]: Exception caught during publishing topic %s.", publisher_rviz_marker.getTopic().c_str());
  }
}

//}

}  // namespace speed_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::speed_tracker::SpeedTracker, mrs_uav_manager::Tracker)
