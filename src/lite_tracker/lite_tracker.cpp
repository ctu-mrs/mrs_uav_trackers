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
  const mrs_msgs::PositionCommand::ConstPtr update_deprec(const mrs_msgs::UavState::ConstPtr &       uav_state,
                                                          const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
  const mrs_msgs::PositionCommand::ConstPtr update_vel(const mrs_msgs::UavState::ConstPtr &       uav_state,
                                                       const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd);
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
    vec3d operator/(vec3d a) {
      return {x / a.x, y / a.y, z / a.z};
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
  LiteTracker::vec3d saturate(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in);
  LiteTracker::vec3d saturate(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in, double dt);
  LiteTracker::vec3d saturate_vector(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in);
  LiteTracker::vec3d saturate_acc(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in, double dt);
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

/* //{ update_deprec() */

const mrs_msgs::PositionCommand::ConstPtr LiteTracker::update_deprec(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                                     [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  // ehmmm, fuj fuj fuj TODO repair this POS
  double dt = 0.01;

  double max_vel_xy = 7.0;
  double max_vel_z  = 3.0;

  double max_acc_xy = 3.0;
  double max_acc_z  = 3.0;

  double max_jerk_xy = 3.0;
  double max_jerk_z  = 3.0;

  vec3d max_vel_vec(max_vel_xy, max_vel_xy, max_vel_z);
  vec3d max_acc_vec(max_acc_xy, max_acc_xy, max_acc_z);
  vec3d max_jerk_vec(max_jerk_xy, max_jerk_xy, max_jerk_z);

  vec3d position_error;
  vec3d reference_direction;
  vec3d current_velocity;
  vec3d current_acceleration;

  /* double stopping_time         = 0.0; */
  /* double stopping_distance     = 0.0; */
  /* double stopping_deceleration = 0.0; */

  /* double distance_to_reference = 0.0; */
  /* double velocity_to_reference = 0.0; */

  vec3d  desired_velocity;
  vec3d  velocity_error;
  vec3d  velocity_error_direction;
  double required_velocity_change = 0.0;

  vec3d  desired_acceleration;
  vec3d  acceleration_error;
  vec3d  acceleration_error_direction;
  double required_acceleration_change = 0.0;

  vec3d required_jerk;

  position_error.x = current_reference_.reference.position.x - current_pos_cmd_.position.x;
  position_error.y = current_reference_.reference.position.y - current_pos_cmd_.position.y;
  position_error.z = current_reference_.reference.position.z - current_pos_cmd_.position.z;

  ROS_INFO_STREAM_THROTTLE(0.5, "[LiteTracker]: position_error" << position_error.x << " " << position_error.y << " " << position_error.z << " ");

  reference_direction = normalize(position_error);

  ROS_INFO_STREAM_THROTTLE(
      0.5, "[LiteTracker]: reference_direction " << reference_direction.x << " " << reference_direction.y << " " << reference_direction.z << " ");


  current_velocity.x = current_pos_cmd_.velocity.x;
  current_velocity.y = current_pos_cmd_.velocity.y;
  current_velocity.z = current_pos_cmd_.velocity.z;

  current_acceleration.x = current_pos_cmd_.acceleration.x;
  current_acceleration.y = current_pos_cmd_.acceleration.y;
  current_acceleration.z = current_pos_cmd_.acceleration.z;

  /* vec3d velocity_to_reference = current_velocity * reference_direction; */

  /* ROS_INFO_STREAM("[LiteTracker]: velocity_to_reference" << velocity_to_reference.x << " " << velocity_to_reference.y << " " << velocity_to_reference.z << "
   * "); */

  /* vec3d stopping_time = velocity_to_reference / max_acc_vec; */

  /* ROS_INFO_STREAM("[LiteTracker]: stopping_time" << stopping_time.x << " " << stopping_time.y << " " << stopping_time.z << " "); */

  /* vec3d stopping_distance = (velocity_to_reference * stopping_time) - ((max_acc_vec * (stopping_time * stopping_time)) * 0.5); */

  /* ROS_INFO_STREAM("[LiteTracker]: stopping_distance" << stopping_distance.x << " " << stopping_distance.y << " " << stopping_distance.z << " "); */
  /* ROS_INFO_STREAM("[LiteTracker]: position_error" << position_error.x << " " << position_error.y << " " << position_error.z << " "); */

  /* vec3d tmp_max_safe_vel_vec = stopping_distance + ((max_acc_vec * stopping_time) * 0.5); */
  /* vec3d max_safe_vel_vec     = max_vel_vec; */

  /* ROS_INFO_STREAM("[LiteTracker]: max_safe_vel_vec" << max_safe_vel_vec.x << " " << max_safe_vel_vec.y << " " << max_safe_vel_vec.z << " "); */

  /* if (stopping_distance.x > fabs(position_error.x)) { */
  /*   ROS_INFO("[LiteTracker]: pesx"); */
  /*   max_safe_vel_vec.x = tmp_max_safe_vel_vec.x; */
  /* } */
  /* if (stopping_distance.y > fabs(position_error.y)) { */
  /*   ROS_INFO("[LiteTracker]: pesy"); */
  /*   max_safe_vel_vec.y = tmp_max_safe_vel_vec.y; */
  /* } */
  /* if (stopping_distance.z > fabs(position_error.z)) { */
  /*   ROS_INFO("[LiteTracker]: pesz"); */
  /*   max_safe_vel_vec.z = tmp_max_safe_vel_vec.z; */
  /* } */

  /* vec3d safe_vel_vec = saturate(max_vel_vec, max_safe_vel_vec); */

  /* ROS_INFO_STREAM("[LiteTracker]: safe_vel_vec" << safe_vel_vec.x << " " << safe_vel_vec.y << " " << safe_vel_vec.z << " "); */

  /* desired_velocity = getMaximumValue(reference_direction, max_safe_vel_vec); */

  /* double max_safe_vel = (stopping_distance/stopping_time) - (0.5*stopping_deceleration*stopping_time); */
  /* vec3d safe_vel_vec = reference_direction*max_safe_vel; */

  /* ROS_INFO_STREAM("[LiteTracker]: safe_vel_vec" << safe_vel_vec.x << " " << safe_vel_vec.y << " " << safe_vel_vec.z << " "); */

  double distance_to_reference = magnitude(position_error);
  double safe_vel              = max_vel_vec.x;

  double stopping_time = max_vel_vec.x / max_acc_vec.x;
  /* double stopping_distance = (max_vel_vec.x * stopping_time) - 0.5 * max_acc_vec.x * stopping_time * stopping_time; */
  double stopping_distance = std::pow(max_vel_vec.x, 2) / (2 * max_acc_vec.x);

  ROS_INFO_STREAM("[LiteTracker]: stopping_time " << stopping_time);
  ROS_INFO_STREAM("[LiteTracker]: stopping_distance " << stopping_distance);
  ROS_INFO_STREAM("[LiteTracker]: distance_to_reference " << distance_to_reference);

  if (stopping_distance > distance_to_reference) {
    /* safe_vel = (distance_to_reference / stopping_time) + 0.5 * max_acc_vec.x; */
    safe_vel = std::sqrt(2 * max_acc_vec.x * distance_to_reference);
    ROS_INFO_STREAM("[LiteTracker]: CLOSE safe_vel " << safe_vel);
  }

  double scaler       = safe_vel / max_vel_vec.x;
  vec3d  safe_vel_vec = max_vel_vec * scaler;
  ROS_INFO_STREAM("[LiteTracker]: safe_vel aft " << safe_vel_vec.x);
  /* vec3d safe_vel_vec = max_vel_vec; */
  /* if (scaler < 1) { */
  /*   if (scaler == 0) { */
  /*     safe_vel_vec = max_vel_vec * 0; */
  /*   } else { */
  /*     safe_vel_vec = max_vel_vec / scaler; */
  /*   } */
  /* } */

  /* desired_velocity = getMaximumValue(reference_direction, max_vel_vec); */
  desired_velocity = getMaximumValue(reference_direction, safe_vel_vec);
  /* ROS_INFO_STREAM("[LiteTracker]: position_error before " << position_error.x); */
  /* ROS_INFO_STREAM("[LiteTracker]: desired_velocity before sat" << desired_velocity.x); */
  desired_velocity = saturate(desired_velocity, position_error, dt);

  ROS_INFO_STREAM("[LiteTracker]: desired_velocity " << desired_velocity.x);

  velocity_error           = desired_velocity - current_velocity;
  velocity_error_direction = normalize(velocity_error);
  /* ROS_INFO_STREAM("[LiteTracker]: velocity_error" << velocity_error.x << " " << velocity_error.y << " " << velocity_error.z << " "); */

  ROS_INFO_STREAM("[LiteTracker]: velocity_error " << velocity_error.x);

  desired_acceleration = getMaximumValue(velocity_error_direction, max_acc_vec);

  ROS_INFO_STREAM("[LiteTracker]: desired_acceleration " << desired_acceleration.x);

  /* ROS_INFO_STREAM("[LiteTracker]: desired_acceleration" << desired_acceleration.x << " " << desired_acceleration.y << " " << desired_acceleration.z << " ");
   */

  /* desired_acceleration = saturate(desired_acceleration, velocity_error, dt); */
  desired_acceleration = saturate_acc(desired_acceleration, velocity_error, dt);

  ROS_INFO_STREAM("[LiteTracker]: desired_acceleration after sat " << desired_acceleration.x);

  /* ROS_INFO_STREAM("[LiteTracker]: desired_acceleration" << desired_acceleration.x << " " << desired_acceleration.y << " " << desired_acceleration.z << " ");
   */

  /* double acc_scale_factor = (magnitude(desired_acceleration)*dt)/magnitude(desired_velocity); */
  /* if (acc_scale_factor > 1) { */
  /*  desired_acceleration =  desired_acceleration/acc_scale_factor; */
  /* } */

  /* acceleration_error           = desired_acceleration - current_acceleration; */
  /* acceleration_error_direction = normalize(acceleration_error); */
  /* required_acceleration_change = magnitude(acceleration_error); */

  /* required_jerk = getMaximumValue(acceleration_error_direction, max_jerk_vec); */

  /* double jerk_scale_factor = (magnitude(required_jerk)*dt)/magnitude(desired_acceleration); */
  /* if (jerk_scale_factor > 1) { */
  /*  required_jerk =  required_jerk/jerk_scale_factor; */
  /* } */

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

    point.x = uav_state->pose.position.x + position_error.x;
    point.y = uav_state->pose.position.y + position_error.y;
    point.z = uav_state->pose.position.z + position_error.z;

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

  /* position_output_.jerk.x = required_jerk.x; */
  /* position_output_.jerk.y = required_jerk.y; */
  /* position_output_.jerk.z = required_jerk.z; */

  position_output_.acceleration.x = desired_acceleration.x;
  position_output_.acceleration.y = desired_acceleration.y;
  position_output_.acceleration.z = desired_acceleration.z;

  position_output_.velocity.x = current_pos_cmd_.velocity.x + desired_acceleration.x * dt;
  position_output_.velocity.y = current_pos_cmd_.velocity.y + desired_acceleration.y * dt;
  position_output_.velocity.z = current_pos_cmd_.velocity.z + desired_acceleration.z * dt;

  position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt;
  position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt;
  position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt;

  /* position_output_.velocity.x = desired_velocity.x; */
  /* position_output_.velocity.y = desired_velocity.y; */
  /* position_output_.velocity.z = desired_velocity.z; */

  /* position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt; */
  /* position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt; */
  /* position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt; */

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
  /* position_output_.use_acceleration = 0; */
  position_output_.use_jerk = 0;

  current_pos_cmd_ = position_output_;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output_));
}

//}

/* //{ update_vel() */

const mrs_msgs::PositionCommand::ConstPtr LiteTracker::update_vel(const mrs_msgs::UavState::ConstPtr &                        uav_state,
                                                                  [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  // ehmmm, fuj fuj fuj TODO repair this POS
  double dt = 0.01;

  double max_vel_xy = 2.0;
  double max_vel_z  = 1.0;

  double max_acc_xy = 1.0;
  double max_acc_z  = 1.0;

  double max_jerk_xy = 1.0;
  double max_jerk_z  = 1.0;

  vec3d max_vel_vec(max_vel_xy, max_vel_xy, max_vel_z);
  vec3d max_acc_vec(max_acc_xy, max_acc_xy, max_acc_z);
  vec3d max_jerk_vec(max_jerk_xy, max_jerk_xy, max_jerk_z);

  vec3d position_error;

  vec3d position_error_norm;

  vec3d required_velocity;

  /* vec3d reference_direction; */
  /* vec3d current_velocity; */
  /* vec3d current_acceleration; */

  /* double stopping_time         = 0.0; */
  /* double stopping_distance     = 0.0; */
  /* double stopping_deceleration = 0.0; */

  /* double distance_to_reference = 0.0; */
  /* double velocity_to_reference = 0.0; */

  /* vec3d  desired_velocity; */

  /* vec3d  desired_velocity; */
  /* vec3d  velocity_error; */
  /* vec3d  velocity_error_direction; */
  /* double required_velocity_change = 0.0; */

  /* vec3d  desired_acceleration; */
  /* vec3d  acceleration_error; */
  /* vec3d  acceleration_error_direction; */
  /* double required_acceleration_change = 0.0; */

  /* vec3d required_jerk; */

  position_error.x = current_reference_.reference.position.x - current_pos_cmd_.position.x;
  position_error.y = current_reference_.reference.position.y - current_pos_cmd_.position.y;
  position_error.z = current_reference_.reference.position.z - current_pos_cmd_.position.z;

  position_error_norm = normalize(position_error);

  required_velocity = position_error_norm / dt;

  /* ROS_INFO_STREAM_THROTTLE(0.001, "[LiteTracker]: position_error" << position_error.x << " " << position_error.y << " " << position_error.z << " "); */
  /* ROS_INFO_STREAM_THROTTLE(0.001, "[LiteTracker]: required_velocity" << required_velocity.x << " " << required_velocity.y << " " << required_velocity.z << "
   * "); */
  /* required_velocity = saturate(required_velocity, max_vel_vec); */

  /* ROS_INFO_STREAM_THROTTLE( */
  /*     0.001, "[LiteTracker]: required_velocity after sat" << required_velocity.x << " " << required_velocity.y << " " << required_velocity.z << " "); */


  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state->header.frame_id;

  /* nav_msgs::OdometryConstPtr goal = sh_goal_.getMsg(); */

  // apply calculated acc command:

  /* position_output_ = current_pos_cmd_; */

  position_output_.jerk.x = 0.0;
  position_output_.jerk.y = 0.0;
  position_output_.jerk.z = 0.0;

  position_output_.acceleration.x = 0.0;
  position_output_.acceleration.y = 0.0;
  position_output_.acceleration.z = 0.0;

  position_output_.velocity.x = required_velocity.x;
  position_output_.velocity.y = required_velocity.y;
  position_output_.velocity.z = required_velocity.z;

  position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt;
  position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt;
  position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt;

  /* position_output_.velocity.x = desired_velocity.x; */
  /* position_output_.velocity.y = desired_velocity.y; */
  /* position_output_.velocity.z = desired_velocity.z; */

  /* position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt; */
  /* position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt; */
  /* position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt; */

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
  position_output_.use_acceleration        = 0;
  position_output_.use_jerk                = 0;

  current_pos_cmd_ = position_output_;

  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_output_));
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

  double max_vel_xy = 7.0;
  double max_vel_z  = 3.0;

  double max_acc_xy = 3.0;
  double max_acc_z  = 3.0;

  double max_jerk_xy = 3.0;
  double max_jerk_z  = 3.0;

  vec3d max_vel_vec(max_vel_xy, max_vel_xy, max_vel_z);
  vec3d max_acc_vec(max_acc_xy, max_acc_xy, max_acc_z);
  vec3d max_jerk_vec(max_jerk_xy, max_jerk_xy, max_jerk_z);

  vec3d position_error;
  vec3d max_constrained_vel_vec;
  vec3d required_velocity;

  vec3d velocity_error;

  vec3d required_acc;

  vec3d stopping_time;
  vec3d current_abs_velocity;

  current_abs_velocity.x = fabs(current_pos_cmd_.velocity.x);
  current_abs_velocity.y = fabs(current_pos_cmd_.velocity.y);
  current_abs_velocity.z = fabs(current_pos_cmd_.velocity.z);

  /* vec3d reference_direction; */
  /* vec3d current_velocity; */
  /* vec3d current_acceleration; */

  /* double stopping_time         = 0.0; */
  /* double stopping_distance     = 0.0; */
  /* double stopping_deceleration = 0.0; */

  /* double distance_to_reference = 0.0; */
  /* double velocity_to_reference = 0.0; */

  /* vec3d  desired_velocity; */

  /* vec3d  desired_velocity; */
  /* vec3d  velocity_error; */
  /* vec3d  velocity_error_direction; */
  /* double required_velocity_change = 0.0; */

  /* vec3d  desired_acceleration; */
  /* vec3d  acceleration_error; */
  /* vec3d  acceleration_error_direction; */
  /* double required_acceleration_change = 0.0; */

  vec3d required_jerk;

  position_error.x = current_reference_.reference.position.x - current_pos_cmd_.position.x;
  position_error.y = current_reference_.reference.position.y - current_pos_cmd_.position.y;
  position_error.z = current_reference_.reference.position.z - current_pos_cmd_.position.z;

  required_velocity.x = position_error.x / dt;
  required_velocity.y = position_error.y / dt;
  required_velocity.z = position_error.z / dt;


  /* ROS_INFO_STREAM_THROTTLE(0.001, "[LiteTracker]: position_error " << position_error.x << " " << position_error.y << " " << position_error.z << " "); */
  /* ROS_INFO_STREAM_THROTTLE(0.001, */
  /*                          "[LiteTracker]: required_velocity " << required_velocity.x << " " << required_velocity.y << " " << required_velocity.z << " "); */


  required_velocity = saturate(required_velocity, max_vel_vec);

  /* ROS_INFO_STREAM_THROTTLE( */
  /*     0.001, "[LiteTracker]: required_velocity after sat " << required_velocity.x << " " << required_velocity.y << " " << required_velocity.z << " "); */

  if (position_error.x == 0) {
    max_constrained_vel_vec.x = 0.0;
  } else {
    max_constrained_vel_vec.x = (2 * fabs(position_error.x)) / (sqrt(2 * fabs(position_error.x) / max_acc_xy));
  }


  if (position_error.y == 0) {
    max_constrained_vel_vec.y = 0.0;
  } else {
    max_constrained_vel_vec.y = (2 * fabs(position_error.y)) / (sqrt(2 * fabs(position_error.y) / max_acc_xy));
  }


  if (position_error.z == 0) {
    max_constrained_vel_vec.z = 0.0;
  } else {
    max_constrained_vel_vec.z = (2 * fabs(position_error.z)) / (sqrt(2 * fabs(position_error.z) / max_acc_z));
  }

  required_velocity = saturate(required_velocity, max_constrained_vel_vec);

  ROS_INFO_STREAM_THROTTLE(
      0.001, "[LiteTracker]: required_velocity after dos " << required_velocity.x << " " << required_velocity.y << " " << velocity_error.z << " ");

  velocity_error.x = required_velocity.x - current_pos_cmd_.velocity.x;
  velocity_error.y = required_velocity.y - current_pos_cmd_.velocity.y;
  velocity_error.z = required_velocity.z - current_pos_cmd_.velocity.z;

  required_acc.x = velocity_error.x / dt;
  required_acc.y = velocity_error.y / dt;
  required_acc.z = velocity_error.z / dt;


  required_acc = saturate(required_acc, max_acc_vec);

  position_output_.header.stamp    = ros::Time::now();
  position_output_.header.frame_id = uav_state->header.frame_id;

  /* nav_msgs::OdometryConstPtr goal = sh_goal_.getMsg(); */

  // apply calculated acc command:

  /* position_output_ = current_pos_cmd_; */

  position_output_.jerk.x = 0.0;
  position_output_.jerk.y = 0.0;
  position_output_.jerk.z = 0.0;

  position_output_.acceleration.x = required_acc.x;
  position_output_.acceleration.y = required_acc.y;
  position_output_.acceleration.z = required_acc.z;

  position_output_.velocity.x = current_pos_cmd_.velocity.x + position_output_.acceleration.x * dt;
  position_output_.velocity.y = current_pos_cmd_.velocity.y + position_output_.acceleration.y * dt;
  position_output_.velocity.z = current_pos_cmd_.velocity.z + position_output_.acceleration.z * dt;

  position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt;
  position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt;
  position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt;

  /* position_output_.velocity.x = desired_velocity.x; */
  /* position_output_.velocity.y = desired_velocity.y; */
  /* position_output_.velocity.z = desired_velocity.z; */

  /* position_output_.position.x = current_pos_cmd_.position.x + position_output_.velocity.x * dt; */
  /* position_output_.position.y = current_pos_cmd_.position.y + position_output_.velocity.y * dt; */
  /* position_output_.position.z = current_pos_cmd_.position.z + position_output_.velocity.z * dt; */

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
  position_output_.use_acceleration        = 0;
  position_output_.use_jerk                = 0;

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

/* //{ saturate() */

LiteTracker::vec3d LiteTracker::saturate(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in) {

  LiteTracker::vec3d saturated_vec = vec_in;

  if (saturated_vec.x > maximum_vec_in.x) {
    saturated_vec.x = maximum_vec_in.x;
  } else if (saturated_vec.x < -maximum_vec_in.x) {
    saturated_vec.x = -maximum_vec_in.x;
  }

  if (saturated_vec.y > maximum_vec_in.y) {
    saturated_vec.y = maximum_vec_in.y;
  } else if (saturated_vec.y < -maximum_vec_in.y) {
    saturated_vec.y = -maximum_vec_in.y;
  }

  if (saturated_vec.z > maximum_vec_in.z) {
    saturated_vec.z = maximum_vec_in.z;
  } else if (saturated_vec.z < -maximum_vec_in.z) {
    saturated_vec.z = -maximum_vec_in.z;
  }

  return saturated_vec;
}

//}

/* //{ saturate() */

LiteTracker::vec3d LiteTracker::saturate(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in, double dt) {

  LiteTracker::vec3d saturated_vec = vec_in;
  ROS_INFO("[LiteTracker]: saturate called");
  ROS_INFO_STREAM("[LiteTracker]: vecin x " << vec_in.x << " max_vec_in x " << maximum_vec_in.x << "  dt_in " << dt << " dt*x " << saturated_vec.x * dt);

  if (fabs(saturated_vec.x * dt) > fabs(maximum_vec_in.x)) {
    ROS_INFO("[LiteTracker]: SATURATING");
    saturated_vec.x = maximum_vec_in.x;
  }
  if (fabs(saturated_vec.y * dt) > fabs(maximum_vec_in.y)) {
    saturated_vec.y = maximum_vec_in.y;
  }
  if (fabs(saturated_vec.z * dt) > fabs(maximum_vec_in.z)) {
    saturated_vec.z = maximum_vec_in.z;
  }

  return saturated_vec;
}

//}

/* //{ saturate() */

LiteTracker::vec3d LiteTracker::saturate_vector(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in) {

  ROS_INFO("[LiteTracker]: saturate called");

  double vec_mag = magnitude(vec_in);

  vec3d  in_norm              = normalize(vec_in);
  vec3d  max_vec_in_direction = in_norm * maximum_vec_in;
  double max_mag              = magnitude(max_vec_in_direction);

  double scaler = max_mag / vec_mag;

  if (scaler < 1.0) {
    LiteTracker::vec3d saturated_vec = vec_in;
    saturated_vec                    = saturated_vec * scaler;
    return saturated_vec;
  } else {
    return vec_in;
  }
}

//}

/* //{ saturate_acc() */

LiteTracker::vec3d LiteTracker::saturate_acc(LiteTracker::vec3d &vec_in, LiteTracker::vec3d &maximum_vec_in, double dt) {

  LiteTracker::vec3d saturated_vec = vec_in;
  ROS_INFO("[LiteTracker]: saturate called");
  ROS_INFO_STREAM("[LiteTracker]: vecin x " << vec_in.x << " max_vec_in x " << maximum_vec_in.x << "  dt_in " << dt << " dt*x " << saturated_vec.x * dt);

  if (fabs(saturated_vec.x * dt) > fabs(maximum_vec_in.x)) {
    ROS_INFO("[LiteTracker]: SATURATING");
    saturated_vec.x = maximum_vec_in.x / dt;
  }
  if (fabs(saturated_vec.y * dt) > fabs(maximum_vec_in.y)) {
    saturated_vec.y = maximum_vec_in.y / dt;
  }
  if (fabs(saturated_vec.z * dt) > fabs(maximum_vec_in.z)) {
    saturated_vec.z = maximum_vec_in.z / dt;
  }

  return saturated_vec;
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
