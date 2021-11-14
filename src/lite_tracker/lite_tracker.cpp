#define VERSION "1.0.2.0"

/* includes //{ */

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <ros/ros.h>

#include <mrs_uav_managers/tracker.h>

#include <nav_msgs/Odometry.h>

#include <mrs_lib/param_loader.h>
#include <mrs_lib/profiler.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/subscribe_handler.h>

#include <mrs_msgs/VelocityReferenceSrv.h>
//}

/* defines //{ */

#define STOP_THR 1e-3

//}

namespace mrs_uav_trackers
{

namespace lite_tracker
{

/* //{ class LiteTracker */

class LiteTracker : public mrs_uav_managers::Tracker {
public:
  ~LiteTracker(){};

  void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_);
  std::tuple<bool, std::string> activate(const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &uav_state, const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  const std_srvs::TriggerResponse::ConstPtr switchOdometrySource(const mrs_msgs::UavState::ConstPtr &new_uav_state);

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
  bool callbacks_enabled_ = true;

  std::string _version_;

  bool is_initialized_ = false;
  bool is_active_      = false;

  // | ------------------------ the goal ------------------------ |

  mrs_lib::SubscribeHandler<nav_msgs::Odometry> sh_goal_;

  mrs_msgs::ReferenceStamped current_reference_;
  mrs_msgs::PositionCommand  current_pos_cmd_;

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler;
  bool              _profiler_enabled_ = false;

  // | ------------------- the tracker's ouput ------------------ |

  bool _position_mode_ = false;
  bool _tilt_mode_     = false;

  mrs_msgs::PositionCommand position_output_;

  ros::Publisher publisher_visualization_vectors_;

  struct vec3d
  {
    double x;
    double y;
    double z;

    vec3d() {
      x = 0.0;
      y = 0.0;
      z = 0.0;
    }

    vec3d(double x_in, double y_in, double z_in) {
      x = x_in;
      y = y_in;
      z = z_in;
    }

    vec3d operator+(vec3d a) {
      return {x + a.x, y + a.y, z + a.z};
    }
    vec3d operator-(vec3d a) {
      return {x - a.x, y - a.y, z - a.z};
    }
    vec3d operator*(double a) {
      return {x * a, y * a, z * a};
    }
    vec3d operator*(vec3d a) {
      return {x * a.x, y * a.y, z * a.z};
    }
    vec3d operator/(double a) {
      return {x / a, y / a, z / a};
    };
  };

  /* typedef enum */
  /* { */
  /*   STANDARD, */
  /*   REMOTE, */
  /*   MAIN_MENU, */
  /*   GOTO_MENU, */
  /* } tracker_state; */

  double             magnitude(LiteTracker::vec3d &vec_in);
  LiteTracker::vec3d normalize(LiteTracker::vec3d &vec_in);
  LiteTracker::vec3d getMaximumValue(LiteTracker::vec3d &direction, LiteTracker::vec3d &constraints);
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void LiteTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                             [[maybe_unused]] std::shared_ptr<mrs_uav_managers::CommonHandlers_t> common_handlers_) {

  ros::NodeHandle nh_(parent_nh, "lite_tracker");

  ros::Time::waitForValid();

  // --------------------------------------------------------------
  // |                       load parameters                      |
  // --------------------------------------------------------------

  mrs_lib::ParamLoader param_loader(nh_, "LiteTracker");

  param_loader.loadParam("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[LiteTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.loadParam("enable_profiler", _profiler_enabled_);
  param_loader.loadParam("position_mode", _position_mode_);
  param_loader.loadParam("tilt_mode", _tilt_mode_);

  if (!param_loader.loadedSuccessfully()) {
    ROS_ERROR("[LiteTracker]: could not load all parameters!");
    ros::shutdown();
  }

  // | ------------------------ profiler ------------------------ |

  profiler = mrs_lib::Profiler(nh_, "litetracker", _profiler_enabled_);

  // | ----------------------- subscribers ---------------------- |

  /* subscriber_lite_ = nh_.subscribe("goal_in", 1, &LiteTracker::callbackLite, this, ros::TransportHints().tcpNoDelay()); */

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh              = nh_;
  shopts.node_name       = "LiteTracker";
  shopts.threadsafe      = true;
  shopts.autostart       = true;
  shopts.transport_hints = ros::TransportHints().tcpNoDelay();

  sh_goal_ = mrs_lib::SubscribeHandler<nav_msgs::Odometry>(shopts, "goal_in");

  // | ----------------------- publishers ---------------------- |

  publisher_visualization_vectors_ = nh_.advertise<visualization_msgs::MarkerArray>("disturbances_markers_out", 1);

  // | --------------------- finish the init -------------------- |

  is_initialized_ = true;

  ROS_INFO("[LiteTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

std::tuple<bool, std::string> LiteTracker::activate([[maybe_unused]] const mrs_msgs::PositionCommand::ConstPtr &last_position_cmd) {

  std::stringstream ss;

  /* if (!sh_goal_.hasMsg()) { */
  /*   ss << "missing Lite command"; */
  /*   return std::tuple(false, ss.str()); */
  /* } */

  is_active_ = true;

  current_reference_.reference.position = last_position_cmd->position;
  current_reference_.reference.heading  = last_position_cmd->heading;
  current_pos_cmd_                      = *last_position_cmd;

  ss << "activated";
  ROS_INFO_STREAM("[LiteTracker]: " << ss.str());

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void LiteTracker::deactivate(void) {

  is_active_ = false;

  ROS_INFO("[LiteTracker]: deactivated");
}

//}

/* //{ resetStatic() */

bool LiteTracker::resetStatic(void) {

  return false;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr LiteTracker::update(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                              [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  // ehmmm, fuj fuj fuj TODO repair this POS
  double dt = 0.01;

  double max_vel_xy = 4;
  double max_vel_z  = 2;

  double max_acc_xy = 2;
  double max_acc_z  = 1.0;

  double max_jerk_xy = 2;
  double max_jerk_z  = 1.0;

  vec3d max_vel_vec(max_vel_xy, max_vel_xy, max_vel_z);
  vec3d max_acc_vec(max_acc_xy, max_acc_xy, max_acc_z);
  vec3d max_jerk_vec(max_jerk_xy, max_jerk_xy, max_jerk_z);

  vec3d pos_difference;
  vec3d reference_direction;
  vec3d current_velocity;
  vec3d current_acceleration;

  double stopping_time         = 0.0;
  double stopping_distance     = 0.0;
  double stopping_deceleration = 0.0;

  double distance_to_reference = 0.0;
  double velocity_to_reference = 0.0;

  vec3d  desired_velocity;
  vec3d  velocity_error;
  vec3d  velocity_error_direction;
  double required_velocity_change = 0.0;

  vec3d  desired_acceleration;
  vec3d  acceleration_error;
  vec3d  acceleration_error_direction;
  double required_acceleration_change = 0.0;

  vec3d required_jerk;

  pos_difference.x = current_reference_.reference.position.x - current_pos_cmd_.position.x;
  pos_difference.y = current_reference_.reference.position.y - current_pos_cmd_.position.y;
  pos_difference.z = current_reference_.reference.position.z - current_pos_cmd_.position.z;

  ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: pos_difference" << pos_difference.x << " " << pos_difference.y << " " << pos_difference.z << " ");

  reference_direction = normalize(pos_difference);

  ROS_INFO_STREAM_THROTTLE(
      0.5, "[LiteTracker]: reference_direction " << reference_direction.x << " " << reference_direction.y << " " << reference_direction.z << " ");


  current_velocity.x = current_pos_cmd_.velocity.x;
  current_velocity.y = current_pos_cmd_.velocity.y;
  current_velocity.z = current_pos_cmd_.velocity.z;

  current_acceleration.x = current_pos_cmd_.acceleration.x;
  current_acceleration.y = current_pos_cmd_.acceleration.y;
  current_acceleration.z = current_pos_cmd_.acceleration.z;

  distance_to_reference = magnitude(pos_difference);


  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: distance to reference: " << distance_to_reference); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: velocity to reference: " << velocity_to_reference); */
  /* vec3d tmp2            = (reference_direction * max_acc_vec); */
  /* stopping_deceleration = magnitude(tmp2); */
  /* /1* stopping_deceleration = magnitude(reference_direction * max_acc_vec); *1/ */
  /* stopping_time = velocity_to_reference / stopping_deceleration; */

  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: stopping_time: " << stopping_time); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: stopping_deceleration: " << stopping_deceleration); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: calc: " << 0.5 * stopping_deceleration * pow(stopping_time, 2)); */
  /* stopping_distance = 0.5 * stopping_deceleration * pow(stopping_time, 2); */

  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: max_acc_vec" << max_acc_vec.x << " " << max_acc_vec.y << " " << max_acc_vec.z << " "); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: tmp" << tmp.x << " " << tmp.y << " " << tmp.z << " "); */


  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: stopping_distance: " << stopping_distance); */

  /* double max_safe_vel_xy = max_vel_xy; */

  /* if (stopping_distance > distance_to_reference) { */
  /*   double tmp_stopping_time = sqrt((2 * distance_to_reference) / stopping_deceleration); */
  /*   max_safe_vel_xy          = tmp_stopping_time * stopping_deceleration; */
  /*   desired_velocity         = reference_direction * max_safe_vel_xy; */
  /* } */

  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: max_safe_vel_xy: " << max_safe_vel_xy); */

  /* desired_velocity = reference_direction * max_safe_vel_xy; */

  /* desired_velocity = reference_direction * max_vel_xy; */

  /* if (desired_velocity.z > max_vel_z) { */
  /*   double velocity_scale_factor = desired_velocity.z / max_vel_z; */
  /*   desired_velocity             = desired_velocity / velocity_scale_factor; */
  /* } */

  vec3d velocity_to_reference_vec       = reference_direction * current_velocity;
  vec3d velocity_to_reference_direction = normalize(velocity_to_reference_vec);
  velocity_to_reference                 = magnitude(velocity_to_reference_vec);
  vec3d tmp                             = getMaximumValue(velocity_to_reference_direction, max_vel_vec);
  stopping_deceleration                 = magnitude(tmp);

  stopping_time = velocity_to_reference / stopping_deceleration;

  /* stopping_distance = (velocity_to_reference * stopping_time) - (0.5 * stopping_deceleration * pow(stopping_time, 2)); */

  /* vec3d  max_safe_vel_vec = max_vel_vec; */
  /* double safe_vel         = 0.0; */

  /* if (stopping_distance > distance_to_reference) { */
  /*   double safe_velocity  = (distance_to_reference / stopping_time) - (stopping_deceleration * stopping_time * 0.5); */
  /*   vec3d max_velocity_to_reference = reference_direction * max_vel_vec; */

  /*   double scaling_factor = magnitude(max_velocity_to_reference) / safe_velocity; */
  /*   max_safe_vel_vec      = max_vel_vec / scaling_factor; */
  /*   safe_vel              = magnitude(max_vel_vec) / scaling_factor; */
  /* } */


  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: safe velocity: " << safe_vel); */

  vec3d  max_safe_vel_vec = max_vel_vec;
  if (distance_to_reference < 8) {
    max_safe_vel_vec = max_safe_vel_vec*(distance_to_reference/8);
  }

  desired_velocity = getMaximumValue(reference_direction, max_safe_vel_vec);

  velocity_error           = desired_velocity - current_velocity;
  velocity_error_direction = normalize(velocity_error);
  required_velocity_change = magnitude(velocity_error);

  desired_acceleration = getMaximumValue(velocity_error_direction, max_acc_vec);

  double acc_scale_factor = (magnitude(desired_acceleration)*dt)/magnitude(desired_velocity);
  if (acc_scale_factor > 1) {
   desired_acceleration =  desired_acceleration/acc_scale_factor;
  }

  acceleration_error           = desired_acceleration - current_acceleration;
  acceleration_error_direction = normalize(acceleration_error);
  required_acceleration_change = magnitude(acceleration_error);

  required_jerk = getMaximumValue(acceleration_error_direction, max_jerk_vec);

  double jerk_scale_factor = (magnitude(required_jerk)*dt)/magnitude(desired_acceleration);
  if (jerk_scale_factor > 1) {
   required_jerk =  required_jerk/jerk_scale_factor;
  }

  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: needed velocity change: " << required_velocity_change); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: velocity_error" << velocity_error.x << " " << velocity_error.y << " " << velocity_error.z << " "); */
  /* ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: xacc:: " << max_acc_xy); */

  /* vis //{ */
  {

    visualization_msgs::MarkerArray msg_out;
    visualization_msgs::Marker      marker;
    geometry_msgs::Point            point;

    marker.header.frame_id = uav_state->header.frame_id;
    marker.header.stamp    = ros::Time::now();
    marker.ns              = "lite_tracker";
    marker.id              = 0;
    marker.type            = visualization_msgs::Marker::ARROW;
    marker.action          = visualization_msgs::Marker::ADD;

    /* pose //{ */

    marker.pose.position.x  = 0.0;
    marker.pose.position.y  = 0.0;
    marker.pose.position.z  = 0.0;
    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    //}

    /* origin //{ */

    point.x = uav_state->pose.position.x;
    point.y = uav_state->pose.position.y;
    point.z = uav_state->pose.position.z;

    marker.points.push_back(point);

    //}

    /* tip //{ */

    point.x = uav_state->pose.position.x + pos_difference.x;
    point.y = uav_state->pose.position.y + pos_difference.y;
    point.z = uav_state->pose.position.z + pos_difference.z;

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
    publisher_visualization_vectors_.publish(msg_out);
  }

  //}


  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state->header.frame_id;

  /* nav_msgs::OdometryConstPtr goal = sh_goal_.getMsg(); */

  // apply calculated acc command:

  /* position_output_ = current_pos_cmd_; */

  position_output_.jerk.x = required_jerk.x;
  position_output_.jerk.y = required_jerk.y;
  position_output_.jerk.z = required_jerk.z;

  position_output_.acceleration.x = current_pos_cmd_.acceleration.x + required_jerk.x * dt;
  position_output_.acceleration.y = current_pos_cmd_.acceleration.y + required_jerk.y * dt;
  position_output_.acceleration.z = current_pos_cmd_.acceleration.z + required_jerk.z * dt;

  position_output_.velocity.x = current_pos_cmd_.velocity.x + desired_acceleration.x * dt;
  position_output_.velocity.y = current_pos_cmd_.velocity.y + desired_acceleration.y * dt;
  position_output_.velocity.z = current_pos_cmd_.velocity.z + desired_acceleration.z * dt;

  position_output_.position.x = current_pos_cmd_.position.x + current_pos_cmd_.velocity.x * dt;
  position_output_.position.y = current_pos_cmd_.position.y + current_pos_cmd_.velocity.y * dt;
  position_output_.position.z = current_pos_cmd_.position.z + current_pos_cmd_.velocity.z * dt;


  /* position_output_.acceleration.x = current_pos_cmd_.acceleration.x + required_jerk.x; */
  /* position_output_.acceleration.y = current_pos_cmd_.acceleration.y + required_jerk.y; */
  /* position_output_.acceleration.z = current_pos_cmd_.acceleration.z + required_jerk.z; */

  /* position_output_.velocity.x = current_pos_cmd_.velocity.x + desired_acceleration.x * dt; */
  /* position_output_.velocity.y = current_pos_cmd_.velocity.y + desired_acceleration.y * dt; */
  /* position_output_.velocity.z = current_pos_cmd_.velocity.z + desired_acceleration.z * dt; */

  /* position_output_.position.x = current_pos_cmd_.position.x + current_pos_cmd_.velocity.x * dt; */
  /* position_output_.position.y = current_pos_cmd_.position.y + current_pos_cmd_.velocity.y * dt; */
  /* position_output_.position.z = current_pos_cmd_.position.z + current_pos_cmd_.velocity.z * dt; */

  position_output_.heading      = current_pos_cmd_.heading;
  position_output_.heading_rate = 0.0;

  position_output_.use_heading             = 1;
  position_output_.use_heading_rate        = 1;
  position_output_.use_position_vertical   = 1;
  position_output_.use_position_horizontal = 1;
  position_output_.use_velocity_vertical   = 1;
  position_output_.use_velocity_horizontal = 1;
  position_output_.use_acceleration        = 1;
  position_output_.use_jerk                = 1;

  current_pos_cmd_ = position_output_;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output_));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus LiteTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = callbacks_enabled_;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr LiteTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  std_srvs::SetBoolResponse res;
  std::stringstream         ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_INFO_STREAM_THROTTLE(1.0, "[LiteTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    ROS_WARN_STREAM_THROTTLE(1.0, "[LiteTracker]: " << ss.str());
  }

  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::UavState::ConstPtr &new_uav_state) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr LiteTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() */

const mrs_msgs::DynamicsConstraintsSrvResponse::ConstPtr LiteTracker::setConstraints([
    [maybe_unused]] const mrs_msgs::DynamicsConstraintsSrvRequest::ConstPtr &cmd) {

  return mrs_msgs::DynamicsConstraintsSrvResponse::Ptr();
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr LiteTracker::setReference([[maybe_unused]] const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  /* return mrs_msgs::ReferenceSrvResponse::Ptr(); */
  current_reference_.reference = cmd->reference;

  mrs_msgs::ReferenceSrvResponse res;
  res.success = true;
  res.message = "reference set";
  ROS_INFO_STREAM("[LiteTracker]: Reference set: x: " << current_reference_.reference.position.x << " y: " << current_reference_.reference.position.y
                                                      << " z: " << current_reference_.reference.position.z << " hdg: " << current_reference_.reference.heading);
  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ setVelocityReference() */

const mrs_msgs::VelocityReferenceSrvResponse::ConstPtr LiteTracker::setVelocityReference([
    [maybe_unused]] const mrs_msgs::VelocityReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::VelocityReferenceSrvResponse::Ptr();
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr LiteTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr &cmd) {
  return mrs_msgs::TrajectoryReferenceSrvResponse::Ptr();
}

//}

/* //{ magnitude() */

double LiteTracker::magnitude(LiteTracker::vec3d &vec_in) {

  double magnitude = 0.0;

  magnitude = sqrt(pow(vec_in.x, 2) + pow(vec_in.y, 2) + pow(vec_in.z, 2));

  return magnitude;
}

//}

/* //{ normalize() */

LiteTracker::vec3d LiteTracker::normalize(LiteTracker::vec3d &vec_in) {

  LiteTracker::vec3d normalized_vec;

  double vec_magnitude = magnitude(vec_in);

  if (vec_magnitude == 0.0) {
    normalized_vec.x = 0.0;
    normalized_vec.y = 0.0;
    normalized_vec.z = 0.0;

  } else {

    normalized_vec.x = vec_in.x / vec_magnitude;
    normalized_vec.y = vec_in.y / vec_magnitude;
    normalized_vec.z = vec_in.z / vec_magnitude;
  }

  return normalized_vec;
}

//}

/* //{ getMaximumValue() */

LiteTracker::vec3d LiteTracker::getMaximumValue(LiteTracker::vec3d &direction, LiteTracker::vec3d &constraints) {


  LiteTracker::vec3d maximum_value;

  // assume that X and Y values are the same, therefore Y is not checked
  if (constraints.x > constraints.z) {

    maximum_value = direction * constraints;

    if (maximum_value.z > constraints.z) {
      double scale_factor = maximum_value.z / constraints.z;
      maximum_value       = maximum_value / scale_factor;
    }
  } else {
    // value in Z is higher
    maximum_value = direction * constraints;

    if (maximum_value.x > constraints.x) {
      double scale_factor = maximum_value.x / constraints.x;
      maximum_value       = maximum_value / scale_factor;
    }
  }

  return maximum_value;
}

//}

}  // namespace lite_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::lite_tracker::LiteTracker, mrs_uav_managers::Tracker)
