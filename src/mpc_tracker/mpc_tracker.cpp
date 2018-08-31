#include <ros/ros.h>

#include <math.h>
#include <cmath>
#include <mutex>
#include <tf/transform_datatypes.h>
#include <Eigen/Eigen>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <mavros_msgs/RCIn.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/FuturePoint.h>
#include <mrs_msgs/FutureTrajectory.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerTrajectory.h>
#include <mrs_msgs/TrackerTrajectorySrv.h>
#include <mrs_msgs/TrackerStatus.h>

#include <mrs_mav_manager/Tracker.h>

#include <mrs_lib/ConvexPolygon.h>
#include <mrs_lib/Profiler.h>

#include "cvx_wrapper.h"

#include <commons.h>

#include <mrs_lib/ParamLoader.h>

using namespace Eigen;

namespace mrs_trackers
{

/* //{ class MpcTracker */

class MpcTracker : public mrs_mav_manager::Tracker {
public:
  MpcTracker(void);

  virtual void initialize(const ros::NodeHandle &parent_nh, mrs_mav_manager::SafetyArea_t const *safety_area);
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

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

  virtual const mrs_msgs::TrackerConstraintsResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled = true;

private:
  ros::NodeHandle nh_;
  // nodelet variables
  ros::Subscriber    sub_trajectory_;                   // desired trajectory
  ros::Subscriber    sub_rc_;                           // rc transmitter
  ros::ServiceServer ser_start_trajectory_following_;   // start trajectory following
  ros::ServiceServer ser_stop_trajectory_following_;    // stop trajectory following
  ros::ServiceServer ser_resume_trajectory_following_;  // resume trajectory following
  ros::ServiceServer ser_fly_to_trajectory_start_;      // fly to the first point of the trajectory
  ros::ServiceServer ser_set_trajectory_;               // service for setting desired trajectory
  ros::ServiceServer set_yaw_service_cmd_cb;
  ros::ServiceServer failsafe_trigger_service_cmd_;  // this service makes the uav stop and go 5m above
  ros::ServiceServer collision_avoidance_service;

  // debugging publishers
  ros::Publisher pub_cmd_odom;
  ros::Publisher pub_cmd_acceleration_;
  ros::Publisher pub_setpoint_pose_;
  ros::Publisher pub_diagnostics_;

  nav_msgs::Odometry odometry;
  std::mutex         mutex_odometry;

  mrs_msgs::FutureTrajectory future_trajectory_out;
  mrs_msgs::PositionCommand  position_cmd_;  // message being returned

  bool      odom_set_, is_active, is_initialized;
  double    kx_[3], kv_[3];
  double    new_kx_[3], new_kv_[3];
  double    cur_yaw_;
  ros::Time odomLastTime;

  // variables for yaw tracker
  double max_yaw_rate_old;
  double yaw_gain;

  // safety area
  mrs_mav_manager::SafetyArea_t const *safety_area;

  // variables regarding the MPC controller
  int       n;            // number of states
  int       m;            // number of inputs
  int       n_yaw;        // number of states - yaw
  int       m_yaw;        // number of inputs - yaw
  int       horizon_len;  // lenght of the prediction horizon
  double    minimum_collison_free_altitude = 0;
  int       active_collision_index         = INT_MAX;
  double    coef_scaler                    = 0;
  ros::Time coef_time;

  // constraints
  std::mutex mutex_constraints;
  ros::Time  priority_time;
  double     max_horizontal_speed;
  double     max_horizontal_acceleration;
  double     max_vertical_ascending_acceleration;
  double     max_vertical_ascending_speed;
  double     max_vertical_ascending_jerk;
  double     max_vertical_descending_speed;
  double     max_vertical_descending_acceleration;
  double     max_vertical_descending_jerk;
  double     max_yaw_rate;
  double     max_yaw_acceleration;
  double     max_yaw_jerk;
  bool       publish_debug_trajectory;

  int      max_iters_XY, max_iters_Z, max_iters_YAW;
  int      iters_X             = 0;
  int      iters_Y             = 0;
  int      iters_Z             = 0;
  int      iters_YAW           = 0;
  double   max_speed_x         = 0;
  double   max_speed_y         = 0;
  double   max_acc_x           = 0;
  double   max_acc_y           = 0;
  double   max_jerk_x          = 0;
  double   max_jerk_y          = 0;
  double   max_speed_z         = 0;
  double   max_acc_z           = 0;
  double   max_jerk_z          = 0;
  double   min_speed_z         = 0;
  double   min_acc_z           = 0;
  double   min_jerk_z          = 0;
  double   max_horizontal_jerk = 0;
  MatrixXd initial_x           = MatrixXd::Zero(3, 1);  // initial x state to be used by cvxgen
  MatrixXd initial_y           = MatrixXd::Zero(3, 1);  // initial y state to be used by cvxgen
  MatrixXd initial_z           = MatrixXd::Zero(3, 1);  // initial z state to be used by cvxgen
  MatrixXd initial_yaw         = MatrixXd::Zero(3, 1);  // initial yaw state to be used by cvxgen

  double diagnostic_tracking_threshold;

  CvxWrapper *cvx_x;
  CvxWrapper *cvx_y;
  CvxWrapper *cvx_z;
  CvxWrapper *cvx_yaw;

  double   dt, dt2;  // time difference of the dynamical system
  bool     no_overshoots;
  MatrixXd A;  // system matrix for virtual UAV
  MatrixXd B;  // input matrix for virtual UAV

  MatrixXd A_yaw;  // system matrix for yaw
  MatrixXd B_yaw;  // input matrix for yaw

  // trajectories
  MatrixXd des_x_trajectory;    // trajectory reference over the prediction horizon
  MatrixXd des_y_trajectory;    // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory;    // trajectory reference over the prediction horizon
  MatrixXd des_yaw_trajectory;  // trajectory reference over the prediction horizon

  MatrixXd des_z_filtered_offset;  // trajectory reference over the prediction horizon
  MatrixXd des_x_filtered;         // filtered trajectory reference over the horizon
  MatrixXd des_y_filtered;         // filtered trajectory reference over the horizon
  MatrixXd des_z_filtered;         // filtered trajectory reference over the horizon

  VectorXd cvxgen_horizontal_vel_constraint;  // velocity constraint for the XY cvxgen solver
  VectorXd cvxgen_horizontal_acc_constraint;  // acceleration constraint for the XY cvxgen solver

  VectorXd   des_x_whole_trajectory;    // long trajectory reference
  VectorXd   des_y_whole_trajectory;    // long trajectory reference
  VectorXd   des_z_whole_trajectory;    // long trajectory reference
  VectorXd   des_yaw_whole_trajectory;  // long trajectory reference
  std::mutex mutex_des_whole_trajectory;

  bool use_yaw_in_trajectory;

  bool tracking_trajectory_;  // are we currently tracking a trajectory
  int  trajectory_tracking_timer = 0;
  int  trajectory_idx;       // index in the currently tracked trajectory
  int  trajectory_size;      // size of the tracked trajectory
  int  max_trajectory_size;  // maximum length of the trajectory
  bool trajectory_set_;      // true if trajectory was set
  int  trajectory_count;     // counting number of trajectories uploaded to the tracker
  bool loop;                 // whether we are looping the trajectory

  MatrixXd reference;      // XYZ reference for the controller
  MatrixXd reference_yaw;  // yaw reference for the controlle
  MatrixXd x;              // current state of the uav
  MatrixXd x_yaw;          // current yaw of the uav

  // yaw tracker
  double yaw_rate;
  double yaw;
  double desired_yaw;

  // predicting the future
  MatrixXd   predicted_future_yaw_trajectory;
  MatrixXd   predicted_future_trajectory;
  std::mutex mutex_predicted_trajectory;

  std::string                                       uav_name_;
  std::vector<std::string>                          other_drone_names_;
  std::map<std::string, mrs_msgs::FutureTrajectory> other_drones_trajectories;
  std::vector<ros::Subscriber>                      other_drones_subscribers;
  ros::Publisher                                    predicted_trajectory_publisher;
  ros::Publisher                                    debug_predicted_trajectory_publisher;
  bool                                              mrs_collision_avoidance;
  bool                                              use_priority_swap;
  double                                            predicted_trajectory_publish_rate;
  double                                            mrs_collision_avoidance_radius;
  double                                            mrs_collision_avoidance_correction;
  std::string                                       predicted_trajectory_topic;
  void                                              callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg);
  bool                                              future_was_predicted;
  double                                            mrs_collision_avoidance_altitude_threshold;
  double    checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  double    checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  int       my_uav_number;
  int       my_uav_priority;
  double    collision_free_altitude;
  ros::Time avoiding_collision_time;
  ros::Time being_avoided_time;
  bool      callbackToggleCollisionAvoidance(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  double    collision_horizontal_speed_coef;
  int       collision_slow_down_fully;
  int       collision_slow_down_start;
  int       collision_start_climbing;
  int       earliest_collision_idx;
  double    collision_trajectory_timeout;
  int       vel_qx;
  int       vel_qy;

private:
  ros::Timer future_trajectory_timer;
  void       futureTrajectoryTimer(const ros::TimerEvent &event);

private:
  ros::Timer diagnostics_timer;
  double     diagnostics_rate;
  void       diagnosticsTimer(const ros::TimerEvent &event);

private:
  MatrixXd   outputTrajectory;
  std::mutex x_mutex, mutex_des_trajectory, des_yaw_mutex;

  ros::Timer mpc_timer;

  bool mpc_computed_;

  // failsafe
  bool      failsafe_triggered    = false;
  bool      use_rc_failsafe       = false;
  int       rc_failsafe_threshold = 2000;
  int       rc_failsafe_channel;
  ros::Time rc_failsafe_time;  // remembers the time when failsafe was triggered by the rc

  // for integrating the delay caused by long mpc calculations
  ros::Time mpc_start_time;
  double    mpc_total_delay = 0;

  // methods
  void     mpcTimer(const ros::TimerEvent &event);
  void     pos_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void     callbackDesiredPositionRelative(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void     callbackDesiredTrajectory(const mrs_msgs::TrackerTrajectory::ConstPtr &msg);
  bool     callbackSetTrajectory(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res);
  bool     callbackStartTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackStopTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackResumeTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackFlyToTrajectoryStart(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void     odom_cb(const nav_msgs::OdometryConstPtr &msg);
  void     calculateMPC();
  void     setTrajectory(float x, float y, float z, float yaw);
  bool     loadTrajectory(const mrs_msgs::TrackerTrajectory &msg, std::string &message);
  double   checkTrajectoryForCollisions(double lowest_z, int &first_collision_index);
  void     filterReferenceXY(double max_speed_x, double max_speed_y);
  void     filterReferenceZ(double max_speed_z);
  void     filterYawReference(void);
  VectorXd integrate(VectorXd &in, double dt, double integrational_const);
  bool     setRelativeGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool     setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool     goTo_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool     callbackTriggerFailsafe(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void     callbackRadioControl(const mavros_msgs::RCInConstPtr &msg);
  bool     triggerFailsafe();
  void     publishDiagnostics();
  double   triangleArea(Eigen::VectorXd a, Eigen::VectorXd b, Eigen::VectorXd c);
  bool     pointInBoundary(Eigen::MatrixXd boundary, double px, double py);

  bool callbackSetYaw(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  void desired_yaw_cmd_cb(const mrs_msgs::TrackerPoint::ConstPtr &msg);

private:
  mrs_lib::Profiler *profiler;
  bool               profiler_enabled_ = false;
  mrs_lib::Routine * routine_mpc_timer;
  mrs_lib::Routine * routine_diagnostics_timer;
  mrs_lib::Routine * routine_future_trajectory_timer;
};

MpcTracker::MpcTracker(void) : odom_set_(false), is_active(false), is_initialized(false), mpc_computed_(false) {
}

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void MpcTracker::initialize(const ros::NodeHandle &parent_nh, mrs_mav_manager::SafetyArea_t const *safety_area) {

  this->safety_area = safety_area;

  ros::NodeHandle nh_(parent_nh, "mpc_tracker");

  ros::Time::waitForValid();

  failsafe_triggered = false;

  std::vector<double> tempList, tempList2, UvaluesList;

  // load parameters for yaw_tracker

  mrs_lib::ParamLoader param_loader(nh_, "MpcTracker");

  param_loader.load_param("enable_profiler", profiler_enabled_);

  param_loader.load_param("yawTracker/maxYawRate", max_yaw_rate_old);
  param_loader.load_param("yawTracker/yawGain", yaw_gain);
  desired_yaw = 0;

  // load the dynamicall model parameters
  param_loader.load_param("dynamicalModel/numberOfStates", n);
  param_loader.load_param("dynamicalModel/numberOfInputs", m);

  // load the dynamicall model parameters
  param_loader.load_param("yawModel/numberOfStates", n_yaw);
  param_loader.load_param("yawModel/numberOfInputs", m_yaw);

  // failsafe
  param_loader.load_param("use_rc_failsafe", use_rc_failsafe);
  param_loader.load_param("rc_failsafe_threshold", rc_failsafe_threshold);
  param_loader.load_param("rc_failsafe_channel", rc_failsafe_channel);
  rc_failsafe_time = ros::Time::now();

  if (use_rc_failsafe) {
    ROS_INFO("[MpcTracker]: RC Failsafe ON, channel = %d, threshold = %d", rc_failsafe_channel, rc_failsafe_threshold);
  }

  // load the main system matrix
  param_loader.load_matrix_static("dynamicalModel/A", A, n, n);

  // load the input matrix
  param_loader.load_matrix_static("dynamicalModel/B", B, n, m);

  // load the yaw system matrix
  param_loader.load_matrix_static("yawModel/A", A_yaw, n_yaw, n_yaw);

  // load the yaw input matrix
  param_loader.load_matrix_static("yawModel/B", B_yaw, n_yaw, m_yaw);

  // load the MPC parameters
  param_loader.load_param("cvxgenMpc/horizon_len", horizon_len);
  param_loader.load_param("cvxgenMpc/maxTrajectorySize", max_trajectory_size);

  param_loader.load_param("cvxgenMpc/dt", dt);
  param_loader.load_param("cvxgenMpc/dt2", dt2);

  param_loader.load_param("cvxgenMpc/maxHorizontalSpeed", max_horizontal_speed);
  param_loader.load_param("cvxgenMpc/maxHorizontalAcceleration", max_horizontal_acceleration);
  param_loader.load_param("cvxgenMpc/maxHorizontalJerk", max_horizontal_jerk);

  param_loader.load_param("cvxgenMpc/maxVerticalAscendingSpeed", max_vertical_ascending_speed);
  param_loader.load_param("cvxgenMpc/maxVerticalAscendingAcceleration", max_vertical_ascending_acceleration);
  param_loader.load_param("cvxgenMpc/maxVerticalAscendingJerk", max_vertical_ascending_jerk);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingSpeed", max_vertical_descending_speed);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingAcceleration", max_vertical_descending_acceleration);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingJerk", max_vertical_descending_jerk);

  param_loader.load_param("cvxgenMpc/maxYawRate", max_yaw_rate);
  param_loader.load_param("cvxgenMpc/maxYawAcceleration", max_yaw_acceleration);
  param_loader.load_param("cvxgenMpc/maxYawJerk", max_yaw_jerk);

  param_loader.load_param("cvxgenMpc/no_overshoots", no_overshoots);

  nh_.param("cvxgenMpc/no_overshoots", no_overshoots, true);

  nh_.param("publish_debug_trajectory", publish_debug_trajectory, false);

  nh_.param("diagnostics_rate", diagnostics_rate, 1.0);
  nh_.param("diagnostic_tracking_threshold", diagnostic_tracking_threshold, 1.0);

  ROS_INFO(
      "MPC parameters: horizon_len: %d, max_vertical_ascending_speed: %2.1f, max_horizontal_speed: %2.1f, max_horizontal_acceleration: "
      "%2.1f, max_vertical_ascending_acceleration: %2.1f, max_vertical_descending_speed: %2.1f, max_vertical_descending_acceleration: %2.1f, ",
      horizon_len, max_vertical_ascending_speed, max_horizontal_speed, max_horizontal_acceleration, max_vertical_ascending_acceleration,
      max_vertical_descending_speed, max_vertical_descending_acceleration);

  // CVXGEN wrappers
  bool verbose;

  param_loader.load_param("cvxWrapper/verbose", verbose);
  param_loader.load_param("cvxWrapper/maxNumOfIterations", max_iters_XY);
  param_loader.load_param("cvxWrapper/Q", tempList);
  param_loader.load_param("cvxWrapper/R", tempList2);

  cvx_x = new CvxWrapper(verbose, max_iters_XY, tempList, tempList2, dt, dt2, 0);
  cvx_y = new CvxWrapper(verbose, max_iters_XY, tempList, tempList2, dt, dt2, 1);

  param_loader.load_param("cvxWrapperZ/verbose", verbose);
  param_loader.load_param("cvxWrapperZ/maxNumOfIterations", max_iters_Z);
  param_loader.load_param("cvxWrapperZ/Q", tempList);
  param_loader.load_param("cvxWrapperZ/R", tempList2);

  cvx_z = new CvxWrapper(verbose, max_iters_Z, tempList, tempList2, dt, dt2, 2);

  param_loader.load_param("cvxWrapperYaw/verbose", verbose);
  param_loader.load_param("cvxWrapperYaw/maxNumOfIterations", max_iters_YAW);
  param_loader.load_param("cvxWrapperYaw/Q", tempList);
  param_loader.load_param("cvxWrapperYaw/R", tempList2);

  cvx_yaw = new CvxWrapper(verbose, max_iters_YAW, tempList, tempList2, dt, dt2, 0);

  ROS_INFO("[MpcTracker]: MPC Tracker initiated with system parameters: n: %d, m: %d, dt: %0.3f, dt2: %0.3f", n, m, dt, dt2);
  ROS_INFO_STREAM("\nA:\n" << A << "\nB:\n" << B);

  // initialize other matrices
  x                = MatrixXd::Zero(n, 1);
  x_yaw            = MatrixXd::Zero(3, 1);
  outputTrajectory = MatrixXd::Zero(horizon_len * n, 1);

  // trajectory tracking
  coef_time                = ros::Time(0);
  priority_time            = ros::Time(0);
  des_x_whole_trajectory   = VectorXd::Zero(max_trajectory_size);
  des_y_whole_trajectory   = VectorXd::Zero(max_trajectory_size);
  des_z_whole_trajectory   = VectorXd::Zero(max_trajectory_size);
  des_yaw_whole_trajectory = VectorXd::Zero(max_trajectory_size);
  trajectory_set_          = false;
  trajectory_count         = 0;
  use_yaw_in_trajectory    = false;
  loop                     = false;

  tracking_trajectory_ = false;
  trajectory_idx       = 0;
  trajectory_size      = 0;

  // initialize the trajectory variables
  reference     = MatrixXd::Zero(n * horizon_len, 1);
  reference_yaw = MatrixXd::Zero(3 * horizon_len, 1);

  cvxgen_horizontal_vel_constraint = VectorXd::Zero(horizon_len);
  cvxgen_horizontal_acc_constraint = VectorXd::Zero(horizon_len);

  des_x_trajectory      = MatrixXd::Zero(horizon_len, 1);
  des_y_trajectory      = MatrixXd::Zero(horizon_len, 1);
  des_z_trajectory      = MatrixXd::Zero(horizon_len, 1);
  des_z_filtered_offset = MatrixXd::Zero(horizon_len, 1);
  des_yaw_trajectory    = MatrixXd::Zero(horizon_len, 1);

  des_x_filtered = MatrixXd::Zero(horizon_len, 1);
  des_y_filtered = MatrixXd::Zero(horizon_len, 1);
  des_z_filtered = MatrixXd::Zero(horizon_len, 1);

  // fill last trajectory with initial data
  future_trajectory_out.stamp               = ros::Time::now();
  future_trajectory_out.uav_name            = uav_name_;
  future_trajectory_out.priority            = my_uav_priority;
  future_trajectory_out.collision_avoidance = mrs_collision_avoidance;

  mrs_msgs::FuturePoint newPoint;
  newPoint.x = std::numeric_limits<float>::max();
  newPoint.y = std::numeric_limits<float>::max();
  newPoint.z = std::numeric_limits<float>::min();

  for (int i = 0; i < horizon_len; i++) {
    future_trajectory_out.points.push_back(newPoint);
  }

  // subscriber for desired trajectory
  sub_trajectory_ = nh_.subscribe("set_trajectory_in", 1, &MpcTracker::callbackDesiredTrajectory, this, ros::TransportHints().tcpNoDelay());

  // service for desired trajectory
  ser_set_trajectory_ = nh_.advertiseService("set_trajectory_in", &MpcTracker::callbackSetTrajectory, this);

  // subscriber for rc transmitter
  sub_rc_ = nh_.subscribe("rc_in", 1, &MpcTracker::callbackRadioControl, this, ros::TransportHints().tcpNoDelay());

  // service for starting trajectory following
  ser_start_trajectory_following_ = nh_.advertiseService("start_trajectory_following_in", &MpcTracker::callbackStartTrajectoryFollowing, this);

  // service for stopping trajectory following
  ser_stop_trajectory_following_ = nh_.advertiseService("stop_trajectory_following_in", &MpcTracker::callbackStopTrajectoryFollowing, this);

  // service for resuming trajectory following
  ser_resume_trajectory_following_ = nh_.advertiseService("resume_trajectory_following_in", &MpcTracker::callbackResumeTrajectoryFollowing, this);

  // service for flying to the trajectory start point
  ser_fly_to_trajectory_start_ = nh_.advertiseService("fly_to_trajectory_start_in", &MpcTracker::callbackFlyToTrajectoryStart, this);

  // service for triggering failsafe
  failsafe_trigger_service_cmd_ = nh_.advertiseService("failsafe_in", &MpcTracker::callbackTriggerFailsafe, this);

  // publishers for debugging
  pub_cmd_odom          = nh_.advertise<nav_msgs::Odometry>("cmd_pose_out", 1);
  pub_cmd_acceleration_ = nh_.advertise<geometry_msgs::Vector3>("cmd_acceleration_out", 1);
  pub_diagnostics_      = nh_.advertise<mrs_msgs::TrackerDiagnostics>("diagnostics_out", 1);

  // publisher for the current setpoint
  pub_setpoint_pose_ = nh_.advertise<nav_msgs::Odometry>("setpoint_pose_out", 1);

  // collision avoidance
  param_loader.load_param("uav_name", uav_name_);

  // extract the numerical name
  sscanf(uav_name_.c_str(), "uav%d", &my_uav_number);
  ROS_INFO("[MpcTracker]: Numerical ID of this UAV is %d", my_uav_number);
  my_uav_priority = my_uav_number;

  param_loader.load_param("mrs_collision_avoidance/drone_names", other_drone_names_);

  // exclude this drone from the list
  std::vector<std::string>::iterator it = other_drone_names_.begin();
  while (it != other_drone_names_.end()) {

    std::string temp_str = *it;

    int other_uav_priority;
    sscanf(temp_str.c_str(), "uav%d", &other_uav_priority);

    if (other_uav_priority == my_uav_number) {

      other_drone_names_.erase(it);
      continue;
    }

    it++;
  }

  param_loader.load_param("mrs_collision_avoidance/enable", mrs_collision_avoidance);

  // create publisher for predicted trajectory
  predicted_trajectory_publisher       = nh_.advertise<mrs_msgs::FutureTrajectory>("predicted_trajectory", 1);
  debug_predicted_trajectory_publisher = nh_.advertise<geometry_msgs::PoseArray>("predicted_trajectory_debugging", 1);

  // preallocate future trajectory
  predicted_future_trajectory     = MatrixXd::Zero(horizon_len * n, 1);
  predicted_future_yaw_trajectory = MatrixXd::Zero(horizon_len * n, 1);

  collision_free_altitude = 0;
  avoiding_collision_time = ros::Time::now();
  being_avoided_time      = ros::Time::now();
  future_was_predicted    = false;
  earliest_collision_idx  = INT_MAX;
  vel_qx                  = 0;
  vel_qy                  = 0;

  param_loader.load_param("predicted_trajectory_topic", predicted_trajectory_topic);

  param_loader.load_param("mrs_collision_avoidance/predicted_trajectory_publish_rate", predicted_trajectory_publish_rate);
  param_loader.load_param("mrs_collision_avoidance/use_priority_swap", use_priority_swap);
  param_loader.load_param("mrs_collision_avoidance/correction", mrs_collision_avoidance_correction);
  param_loader.load_param("mrs_collision_avoidance/radius", mrs_collision_avoidance_radius);
  param_loader.load_param("mrs_collision_avoidance/altitude_threshold", mrs_collision_avoidance_altitude_threshold);
  param_loader.load_param("mrs_collision_avoidance/collision_horizontal_speed_coef", collision_horizontal_speed_coef);
  param_loader.load_param("mrs_collision_avoidance/collision_slow_down_fully", collision_slow_down_fully);
  param_loader.load_param("mrs_collision_avoidance/collision_slow_down_start", collision_slow_down_start);
  param_loader.load_param("mrs_collision_avoidance/collision_start_climbing", collision_start_climbing);
  param_loader.load_param("mrs_collision_avoidance/trajectory_timeout", collision_trajectory_timeout);

  // collision avoidance toggle service
  collision_avoidance_service = nh_.advertiseService("collision_avoidance", &MpcTracker::callbackToggleCollisionAvoidance, this);

  // create subscribers on other drones diagnostics
  for (unsigned long i = 0; i < other_drone_names_.size(); i++) {

    std::string topic_name = std::string("/") + other_drone_names_[i] + std::string("/") + predicted_trajectory_topic;

    ROS_INFO("[MpcTracker]: subscribing to %s", topic_name.c_str());

    other_drones_subscribers.push_back(nh_.subscribe(topic_name, 1, &MpcTracker::callbackOtherMavTrajectory, this, ros::TransportHints().tcpNoDelay()));
  }

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler                        = new mrs_lib::Profiler(nh_, "MpcTracker", profiler_enabled_);
  routine_mpc_timer               = profiler->registerRoutine("mpcIteration", int(1.0 / dt), 0.004);
  routine_diagnostics_timer       = profiler->registerRoutine("diagnosticsTimer");
  routine_future_trajectory_timer = profiler->registerRoutine("futureTrajectoryTimer");

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  future_trajectory_timer = nh_.createTimer(ros::Rate(predicted_trajectory_publish_rate), &MpcTracker::futureTrajectoryTimer, this);
  diagnostics_timer       = nh_.createTimer(ros::Rate(diagnostics_rate), &MpcTracker::diagnosticsTimer, this);
  mpc_timer               = nh_.createTimer(ros::Rate(1.0 / dt), &MpcTracker::mpcTimer, this);

  // | ----------------------- finish init ---------------------- |

  if (!param_loader.loaded_successfully()) {
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[MpcTracker]: MpcTracker initialized");
}

//}

/* //{ activate() */

bool MpcTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (mrs_msgs::PositionCommand::Ptr() != cmd) {

    // set the initial condition from the odometry
    x_mutex.lock();
    x(0, 0) = cmd->position.x;
    x(1, 0) = cmd->velocity.x;
    x(2, 0) = 0;

    x(3, 0) = cmd->position.y;
    x(4, 0) = cmd->velocity.y;
    x(5, 0) = 0;

    x(6, 0) = cmd->position.z;
    x(7, 0) = cmd->velocity.z;
    x(8, 0) = 0;

    x_yaw(0, 0) = cmd->yaw;
    x_yaw(1, 0) = cmd->yaw_dot;
    x_yaw(2, 0) = 0;

    yaw = cur_yaw_;
    x_mutex.unlock();

  } else {

    // set the initial condition from the odometry
    x_mutex.lock();
    x(0, 0) = odometry.pose.pose.position.x;
    x(1, 0) = odometry.twist.twist.linear.x;
    x(2, 0) = 0;

    x(3, 0) = odometry.pose.pose.position.y;
    x(4, 0) = odometry.twist.twist.linear.y;
    x(5, 0) = 0;

    x(6, 0) = odometry.pose.pose.position.z;
    x(7, 0) = odometry.twist.twist.linear.z;
    x(8, 0) = 0;

    x_yaw(0, 0) = cur_yaw_;
    x_yaw(1, 0) = 0;
    x_yaw(2, 0) = 0;

    yaw = cur_yaw_;
    x_mutex.unlock();
  }

  failsafe_triggered   = false;
  tracking_trajectory_ = false;

  /* // if we got a setpoint with the activation command */
  /* if (cmd && odom_set_) { */

  /*   des_yaw_mutex.lock(); */
  /*   desired_yaw = cmd->yaw; */
  /*   des_yaw_mutex.unlock(); */

  /*   setTrajectory(cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw); */

  /*   ROS_INFO("[MpcTracker]: MPC tracker activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z,
   */
  /*            cmd->yaw); */
  /*   is_active = true; */
  /* } */

  /* // if we dont, stay where you are */
  /* else if (odom_set_) { */

  /*   setTrajectory(odometry.pose.pose.position.x, odometry.pose.pose.position.y, odometry.pose.pose.position.z, tf::getYaw(odometry.pose.pose.orientation));
   */
  /*   position_cmd_.yaw = tf::getYaw(odometry.pose.pose.orientation); */

  /*   ROS_INFO("[MpcTracker]: MPC tracker activated with no setpoint, staying where we are."); */
  /*   is_active = true; */
  /* } */

  // calculate time needed to stop
  double time_x;
  double time_y;
  double time_z;
  mutex_constraints.lock();
  {
    time_x = 1.5 * x(1, 0) / max_horizontal_acceleration;
    time_y = 1.5 * x(4, 0) / max_horizontal_acceleration;
    time_z = 1.5 * x(7, 0) / max_vertical_ascending_acceleration;
  }
  mutex_constraints.unlock();

  // calculate how far will it move before it stops
  double move_x = (x(1, 0) >= 0 ? 1 : -1) * 0.5 * time_x * x(1, 0);
  double move_y = (x(4, 0) >= 0 ? 1 : -1) * 0.5 * time_y * x(4, 0);
  double move_z = (x(7, 0) >= 0 ? 1 : -1) * 0.5 * time_z * x(7, 0);

  // stop
  setRelativeGoal(move_x, move_y, move_z, 0, false);

  mpc_start_time  = ros::Time::now();
  mpc_total_delay = 0;
  is_active       = true;

  ROS_INFO("[MpcTracker]: activated");

  publishDiagnostics();

  // can return false
  return is_active;
}

//}

/* //{ deactivate() */

void MpcTracker::deactivate(void) {

  is_active = false;
  odom_set_ = false;

  // turn off trajectory tracking
  mutex_des_trajectory.lock();
  tracking_trajectory_ = false;
  trajectory_idx       = 0;
  mutex_des_trajectory.unlock();

  ROS_INFO("[MpcTracker]: MPC tracker deactivated");

  publishDiagnostics();
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr MpcTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // copy the odometry from the message
  mutex_odometry.lock();
  { odometry = *msg; }
  mutex_odometry.unlock();

  cur_yaw_ = tf::getYaw(msg->pose.pose.orientation);

  odom_set_ = true;

  // very important, return null pointer when the tracker is not active, but we can still do some stuff
  if (!is_active)
    return mrs_msgs::PositionCommand::Ptr();

  if (!mpc_computed_) {

    // if the tracker is not computed yet

    // set the header
    position_cmd_.header.stamp    = msg->header.stamp;
    position_cmd_.header.frame_id = msg->header.frame_id;

    // set positions from odom
    position_cmd_.position.x = msg->pose.pose.position.x;
    position_cmd_.position.y = msg->pose.pose.position.y;
    position_cmd_.position.z = msg->pose.pose.position.z;

    // set velocities from odom
    position_cmd_.velocity.x = msg->twist.twist.linear.x;
    position_cmd_.velocity.y = msg->twist.twist.linear.y;
    position_cmd_.velocity.z = msg->twist.twist.linear.z;

    // set zero accelerations
    position_cmd_.acceleration.x = 0;
    position_cmd_.acceleration.y = 0;
    position_cmd_.acceleration.z = 0;

    // set yaw based on current odom
    position_cmd_.yaw     = cur_yaw_;
    position_cmd_.yaw_dot = msg->twist.twist.angular.z;

    ROS_WARN("[MpcTracker]: MPC not ready, reaturning current odom as the command.");

    return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
  }

  // chech wheather all outputs are finite
  bool arefinite = true;
  for (int i = 0; i < 9; i++) {
    if (!std::isfinite(x(i, 0))) {
      arefinite = false;
    }
  }

  if (arefinite) {

    x_mutex.lock();
    {
      // set the desired states base on the result of the mpc
      position_cmd_.position.x     = x(0, 0);
      position_cmd_.velocity.x     = x(1, 0);
      position_cmd_.acceleration.x = x(2, 0);

      position_cmd_.position.y     = x(3, 0);
      position_cmd_.velocity.y     = x(4, 0);
      position_cmd_.acceleration.y = x(5, 0);

      position_cmd_.position.z     = x(6, 0);
      position_cmd_.velocity.z     = x(7, 0);
      position_cmd_.acceleration.z = x(8, 0);
    }
    x_mutex.unlock();

  } else {

    ROS_ERROR("[MpcTracker]: MPC outputs are not finite!");

    position_cmd_.velocity.x     = 0;
    position_cmd_.acceleration.x = 0;

    position_cmd_.velocity.y     = 0;
    position_cmd_.acceleration.y = 0;

    position_cmd_.velocity.z     = 0;
    position_cmd_.acceleration.z = 0;
  }

  des_yaw_mutex.lock();
  { desired_yaw = mrs_trackers_commons::validateYawSetpoint(desired_yaw); }
  des_yaw_mutex.unlock();

  // compute the desired yaw rate
  des_yaw_mutex.lock();
  if (fabs(desired_yaw - yaw) > PI) {
    yaw_rate = -yaw_gain * (desired_yaw - yaw);
  } else {
    yaw_rate = yaw_gain * (desired_yaw - yaw);
  }
  des_yaw_mutex.unlock();

  if (yaw_rate > max_yaw_rate_old) {
    yaw_rate = max_yaw_rate_old;
  } else if (yaw_rate < -max_yaw_rate_old) {
    yaw_rate = -max_yaw_rate_old;
  }

  // flap the resulted yaw aroud PI
  yaw = yaw + dt * yaw_rate;
  if (yaw > PI) {
    yaw -= 2 * PI;
  } else if (yaw < -PI) {
    yaw += 2 * PI;
  }

  if (std::isfinite(x_yaw(0, 0)) && std::isfinite(x_yaw(1, 0))) {

    // set the yaw output - cvxgen MPC controller
    position_cmd_.yaw     = x_yaw(0, 0);
    position_cmd_.yaw_dot = x_yaw(1, 0);

  } else {

    ROS_INFO("[MpcTracker]: Output YAW is not finite!");
  }

  // set the header
  position_cmd_.header.stamp    = msg->header.stamp;
  position_cmd_.header.frame_id = msg->header.frame_id;

  // publish position for debugging purposes
  nav_msgs::Odometry cmd_odom_out;

  cmd_odom_out.header.stamp    = ros::Time::now();
  cmd_odom_out.header.frame_id = "local_origin";

  cmd_odom_out.pose.pose.position = position_cmd_.position;
  tf::Quaternion orientation;
  orientation.setEuler(0, 0, yaw);
  cmd_odom_out.pose.pose.orientation.x = orientation.x();
  cmd_odom_out.pose.pose.orientation.y = orientation.y();
  cmd_odom_out.pose.pose.orientation.z = orientation.z();
  cmd_odom_out.pose.pose.orientation.w = orientation.w();

  cmd_odom_out.twist.twist.linear.x = position_cmd_.velocity.x;
  cmd_odom_out.twist.twist.linear.y = position_cmd_.velocity.y;
  cmd_odom_out.twist.twist.linear.z = position_cmd_.velocity.z;

  try {
    pub_cmd_odom.publish(nav_msgs::OdometryConstPtr(new nav_msgs::Odometry(cmd_odom_out)));
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_cmd_odom.getTopic().c_str());
  }

  // publish velocity for debugging purposes
  geometry_msgs::Vector3 outVelocity;

  outVelocity.x = position_cmd_.velocity.x;
  outVelocity.y = position_cmd_.velocity.y;
  outVelocity.z = position_cmd_.velocity.z;

  // publish acceleration for debugging purposes
  geometry_msgs::Vector3 outAcceleration;

  outAcceleration.x = position_cmd_.acceleration.x;
  outAcceleration.y = position_cmd_.acceleration.y;
  outAcceleration.z = position_cmd_.acceleration.z;

  try {
    pub_cmd_acceleration_.publish(geometry_msgs::Vector3ConstPtr(new geometry_msgs::Vector3(outAcceleration)));
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_cmd_acceleration_.getTopic().c_str());
  }

  // publish position setpoint for debugging purposes
  nav_msgs::Odometry setpoint_odom_out;

  setpoint_odom_out.header.stamp    = ros::Time::now();
  setpoint_odom_out.header.frame_id = "local_origin";

  mutex_des_trajectory.lock();
  {
    setpoint_odom_out.pose.pose.position.x = des_x_trajectory(0, 0);
    setpoint_odom_out.pose.pose.position.y = des_y_trajectory(0, 0);
    setpoint_odom_out.pose.pose.position.z = des_z_trajectory(0, 0);

    orientation.setEuler(0, 0, desired_yaw);
    setpoint_odom_out.pose.pose.orientation.x = orientation.x();
    setpoint_odom_out.pose.pose.orientation.y = orientation.y();
    setpoint_odom_out.pose.pose.orientation.z = orientation.z();
    setpoint_odom_out.pose.pose.orientation.w = orientation.w();
  }
  mutex_des_trajectory.unlock();

  try {
    pub_setpoint_pose_.publish(nav_msgs::OdometryConstPtr(new nav_msgs::Odometry(setpoint_odom_out)));
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_setpoint_pose_.getTopic().c_str());
  }

  // u have to return a position command
  // can set the jerk to 0
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus::Ptr MpcTracker::getStatus() {

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

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr MpcTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd) {

  char                      message[100];
  std_srvs::SetBoolResponse res;

  if (cmd->data != callbacks_enabled) {

    callbacks_enabled = cmd->data;

    sprintf((char *)&message, "Callbacks %s", callbacks_enabled ? "enabled" : "disabled");

    ROS_INFO("[MpcTracker]: %s", message);

  } else {

    sprintf((char *)&message, "Callbacks were already %s", callbacks_enabled ? "enabled" : "disabled");
  }

  res.message = message;
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

void MpcTracker::switchOdometrySource(const nav_msgs::Odometry::ConstPtr &msg) {

  // | --------- recalculate the goal to new coordinates -------- |
  double dx, dy, dz;

  mutex_odometry.lock();
  {
    dx = msg->pose.pose.position.x - odometry.pose.pose.position.x;
    dy = msg->pose.pose.position.y - odometry.pose.pose.position.y;
    dz = msg->pose.pose.position.z - odometry.pose.pose.position.z;
    // TODO yaw?
  }
  mutex_odometry.unlock();

  mutex_des_whole_trajectory.lock();
  mutex_des_trajectory.lock();
  x_mutex.lock();
  {
    if (tracking_trajectory_) {

      for (int i = 0; i < trajectory_size; i++) {
        des_x_whole_trajectory(i) += dx;
        des_y_whole_trajectory(i) += dy;
        des_z_whole_trajectory(i) += dz;
      }

    } else {

      // TODO: should set goal when flying to a setpoint
      for (int i = 0; i < horizon_len; i++) {
        des_x_trajectory(i, 0) += dx;
        des_y_trajectory(i, 0) += dy;
        des_z_trajectory(i, 0) += dz;
      }
    }

    x(0, 0) = msg->pose.pose.position.x;
    x(1, 0) = msg->twist.twist.linear.x;

    x(3, 0) = msg->pose.pose.position.y;
    x(4, 0) = msg->twist.twist.linear.y;

    x(6, 0) = msg->pose.pose.position.z;
    x(7, 0) = msg->twist.twist.linear.z;
  }
  x_mutex.unlock();
  mutex_des_trajectory.unlock();
  mutex_des_whole_trajectory.unlock();
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::Vec4Response::ConstPtr MpcTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  setGoal(cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3], true);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3]);
  res.message = tempStr;

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

/* //{ goTo() topic */

bool MpcTracker::goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  if (!failsafe_triggered) {

    setGoal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
  }

  return true;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::Vec4Response::ConstPtr MpcTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  setRelativeGoal(cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3], true);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to relative x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3]);
  res.message = tempStr;

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

/* //{ goToRelative() topic */

bool MpcTracker::goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  if (!failsafe_triggered) {

    setRelativeGoal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
  }

  return true;
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  setGoal(x(0, 0), x(3, 0), cmd->goal, x_yaw(0, 0), false);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to altitude %3.2f", cmd->goal);
  res.message = tempStr;

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

/* //{ goToAltitude() topic */

bool MpcTracker::goToAltitude(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    setGoal(x(0, 0), x(3, 0), msg->data, x_yaw(0, 0), false);
  }

  return true;
}

//}

/* //{ setYaw() service */

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  if (tracking_trajectory_) {

    // TODO implement
    ROS_ERROR("[MpcTracker]: TODO, implement");

  } else {

    // TODO: should set goal when flying to a setpoint
    setGoal(x(0, 0), x(3, 0), x(6, 0), mrs_trackers_commons::validateYawSetpoint(cmd->goal), true);
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->goal);
  res.message = tempStr;

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

/* //{ setYaw() topic */

bool MpcTracker::setYaw(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    if (tracking_trajectory_) {

      mutex_des_trajectory.lock();
      {
        for (int i = 0; i < horizon_len; i++) {
          des_yaw_trajectory(i, 0) = mrs_trackers_commons::validateYawSetpoint(msg->data);
        }
      }
      mutex_des_trajectory.unlock();

    } else {

      // TODO: should set goal when flying to a setpoint
      setGoal(x(0, 0), x(3, 0), x(6, 0), mrs_trackers_commons::validateYawSetpoint(msg->data), true);
    }
  }

  return true;
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  if (tracking_trajectory_) {

    mutex_des_trajectory.lock();
    {
      for (int i = 0; i < horizon_len; i++) {
        des_yaw_trajectory(i, 0) += mrs_trackers_commons::validateYawSetpoint(cmd->goal);
      }
    }
    mutex_des_trajectory.unlock();

  } else {

    setGoal(des_x_trajectory(0, 0), des_y_trajectory(0, 0), des_z_trajectory(0, 0),
            mrs_trackers_commons::validateYawSetpoint(des_yaw_trajectory(0, 0) + cmd->goal), true);
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->goal);
  res.message = tempStr;

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

/* //{ setYawRelative() topic */

bool MpcTracker::setYawRelative(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    if (tracking_trajectory_) {

      mutex_des_trajectory.lock();
      {
        for (int i = 0; i < horizon_len; i++) {
          des_yaw_trajectory(i, 0) += mrs_trackers_commons::validateYawSetpoint(msg->data);
        }
      }
      mutex_des_trajectory.unlock();

    } else {

      setGoal(des_x_trajectory(0, 0), des_y_trajectory(0, 0), des_z_trajectory(0, 0),
              mrs_trackers_commons::validateYawSetpoint(des_yaw_trajectory(0, 0) + msg->data), true);
    }
  }

  return true;
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsResponse::ConstPtr MpcTracker::setConstraints(const mrs_msgs::TrackerConstraintsRequest::ConstPtr &cmd) {

  mrs_msgs::TrackerConstraintsResponse res;

  // this is the place to copy the constraints
  mutex_constraints.lock();
  {
    max_horizontal_speed        = cmd->horizontal_speed;
    max_horizontal_acceleration = cmd->horizontal_acceleration;
    max_horizontal_jerk         = cmd->horizontal_jerk;

    max_vertical_ascending_speed        = cmd->vertical_ascending_speed;
    max_vertical_ascending_acceleration = cmd->vertical_ascending_acceleration;
    max_vertical_ascending_jerk         = cmd->vertical_ascending_jerk;

    max_vertical_descending_speed        = cmd->vertical_descending_speed;
    max_vertical_descending_acceleration = cmd->vertical_descending_acceleration;
    max_vertical_descending_jerk         = cmd->vertical_descending_jerk;

    max_yaw_rate         = cmd->yaw_speed;
    max_yaw_acceleration = cmd->yaw_acceleration;
    max_yaw_jerk         = cmd->yaw_jerk;
  }
  mutex_constraints.unlock();

  ROS_INFO("[LineTracker]: updating constraints");

  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::TrackerConstraintsResponse::ConstPtr(new mrs_msgs::TrackerConstraintsResponse(res));
}

//}

// --------------------------------------------------------------
// |                  tracker's custom routines                 |
// --------------------------------------------------------------

// | ------------------------ callbacks ----------------------- |

/* //{ callbackOtherMavTrajectory() */

void MpcTracker::callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg) {

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // update the diagnostics
  other_drones_trajectories[msg->uav_name] = temp_trajectory;
}

//}

/* //{ callbackToggleCollisionAvoidance() */

bool MpcTracker::callbackToggleCollisionAvoidance(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  mrs_collision_avoidance = req.data;

  if (!mrs_collision_avoidance) {

    collision_free_altitude = 0;
  }

  ROS_INFO("[MpcTracker]: Collision avoidance was switched %s", mrs_collision_avoidance ? "TRUE" : "FALSE");

  res.message = "Collision avoidance set.";
  res.success = true;

  return true;
}

//}

/* //{ callbackRadioControl() */

void MpcTracker::callbackRadioControl(const mavros_msgs::RCInConstPtr &msg) {

  if (use_rc_failsafe) {

    // dont trigger failsafe if it was trigger within last 5 seconds
    if ((ros::Time::now() - rc_failsafe_time).toSec() < 5)
      return;

    if (int(msg->channels.size()) < rc_failsafe_channel) {

      ROS_WARN_THROTTLE(1, "rc_failsafe_channel is larger than the field of RC Channels");
      return;
    }

    // check for the failsave channel
    if (msg->channels[rc_failsafe_channel - 1] > rc_failsafe_threshold) {

      ROS_WARN("[MpcTracker]: Toggling Failsafe by RC");
      rc_failsafe_time = ros::Time::now();
      triggerFailsafe();
    }
  }
}

//}

/* //{ callbackStartTrajectoryFollowing() */

bool MpcTracker::callbackStartTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!callbacks_enabled) {

    res.success = false;
    res.message = "Callbacks are disabled!";
    return true;
  }

  if (trajectory_set_) {

    mutex_des_trajectory.lock();
    tracking_trajectory_ = true;
    trajectory_idx       = 0;
    mutex_des_trajectory.unlock();

    ROS_INFO("[MpcTracker]: Starting trajectory following.");

    res.success = true;
    res.message = "Starting trajectory following.";

    publishDiagnostics();

  } else {

    ROS_WARN("[MpcTracker]: Cannot start trajectory following, trajectory not set.");
    res.success = false;
    res.message = "Trajectory not set.";
  }

  return true;
}

//}

/* //{ callbackStopTrajectoryFollowing() */

bool MpcTracker::callbackStopTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (tracking_trajectory_) {

    mutex_des_trajectory.lock();
    tracking_trajectory_ = false;

    x_mutex.lock();
    setTrajectory(x(0, 0), x(3, 0), x(6, 0), x_yaw(0, 0));
    x_mutex.unlock();

    mutex_des_trajectory.unlock();

    ROS_INFO("[MpcTracker]: Stopping trajectory following, staying at x: %2.2f, y: %2.2f, z: %2.2f.", x(0, 0), x(3, 0), x(6, 0));

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Staying at x: %3.2f, y: %2.2f, z: %2.2f", x(0, 0), x(3, 0), x(6, 0));

    publishDiagnostics();

  } else {

    ROS_WARN("[MpcTracker]: Cannot stop trajectory trakcing, it is already stopped.");
    res.success = false;
    res.message = "Already at stop.";
  }

  return true;
}

//}

/* //{ callbackFlyToTrajectoryStart() */

bool MpcTracker::callbackFlyToTrajectoryStart(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!callbacks_enabled) {

    res.success = false;
    res.message = "Callbacks are disabled!";
    return true;
  }

  if (trajectory_set_) {

    mutex_des_whole_trajectory.lock();
    { setGoal(des_x_whole_trajectory[0], des_y_whole_trajectory[0], des_z_whole_trajectory[0], des_yaw_whole_trajectory[0], true); }
    mutex_des_whole_trajectory.unlock();

    if (use_yaw_in_trajectory)
      desired_yaw = des_yaw_whole_trajectory[0];

    mutex_des_trajectory.lock();
    tracking_trajectory_ = false;
    mutex_des_trajectory.unlock();

    char tempStr[100];
    if (use_yaw_in_trajectory) {

      ROS_INFO("[MpcTracker]: Flying to trajectory start pooint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
               des_z_whole_trajectory[0], des_yaw_whole_trajectory[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
              des_z_whole_trajectory[0], des_yaw_whole_trajectory[0]);
    } else {
      ROS_INFO("[MpcTracker]: Flying to trajectory start pooint x: %2.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
               des_z_whole_trajectory[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0], des_z_whole_trajectory[0]);
    }
    res.success = true;
    res.message = tempStr;

    publishDiagnostics();

  } else {
    ROS_WARN("[MpcTracker]: Cannot fly to trajectory start point, trajectory not set!");

    res.success = false;
    res.message = "Trajectory not set!";
  }

  return true;
}

//}

/* //{ callbackResumeTrajectoryFollowing() */

bool MpcTracker::callbackResumeTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!callbacks_enabled) {

    res.success = false;
    res.message = "Callbacks are disabled!";
    return true;
  }

  if (trajectory_set_) {

    if (trajectory_idx < (trajectory_size - 1)) {

      mutex_des_trajectory.lock();
      tracking_trajectory_ = true;
      mutex_des_trajectory.unlock();

      ROS_INFO("[MpcTracker]: Resuming trajectory following.");
      res.success = true;
      res.message = "Resuming trajectory following.";

      publishDiagnostics();

    } else {
      ROS_WARN("[MpcTracker]: Cannot resume trajectory tracking, trajectory is already finished.");
      res.success = false;
      res.message = "Trajectory already finished.";
    }

  } else {
    ROS_WARN("[MpcTracker]: Cannot resume trajectory following, trajectory not set");
    res.success = false;
    res.message = "Trajectory not set!";
  }

  return true;
}

//}

/* //{ callbackTriggerFailsafe() */

bool MpcTracker::callbackTriggerFailsafe(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (triggerFailsafe()) {

    res.success = true;
    res.message = "Failsafe activated";
  } else {

    res.success = true;
    res.message = "Failsafe deactivated!";
  }

  publishDiagnostics();

  return true;
}

//}

/* //{ callbackSetTrajectory() */

// service for setting desired trajectory
bool MpcTracker::callbackSetTrajectory(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res) {

  if (!callbacks_enabled) {

    res.success = false;
    res.message = "Callbacks are disabled!";
    return true;
  }

  std::string message;
  res.success = loadTrajectory(req.trajectory_msg, message);
  res.message = message;
  return true;
}

//}

/* //{ callbackDesiredTrajectory() */

// callback for loading desired trajectory
void MpcTracker::callbackDesiredTrajectory(const mrs_msgs::TrackerTrajectory::ConstPtr &msg) {

  if (failsafe_triggered) {

    return;
  }

  if (!callbacks_enabled) {

    ROS_WARN("[MpcTracker]: Can't set trajectory, callbacks are disabled!");
    return;
  }

  std::string message;
  loadTrajectory(*msg, message);
}

//}

// | -------------------- setpoint handlign ------------------- |

/* //{ triggerFailsafe() */

bool MpcTracker::triggerFailsafe() {

  // turn it off
  if (failsafe_triggered) {

    failsafe_triggered = false;
    ROS_WARN("[MpcTracker]: Failsafe OFF");
    return false;

    // turn it on
  } else {

    // turn off potential trajectory tracking
    mutex_des_trajectory.lock();
    tracking_trajectory_ = false;
    trajectory_idx       = 0;
    mutex_des_trajectory.unlock();

    // calculate time needed to stop
    double time_x;
    double time_y;
    mutex_constraints.lock();
    {
      time_x = 1.5 * x(1, 0) / max_horizontal_acceleration;
      time_y = 1.5 * x(4, 0) / max_horizontal_acceleration;
    }
    mutex_constraints.unlock();

    // calculate how far will it move before it stops
    double move_x = (x(1, 0) >= 0 ? 1 : -1) * 0.5 * time_x * x(1, 0);
    double move_y = (x(4, 0) >= 0 ? 1 : -1) * 0.5 * time_y * x(4, 0);

    // stop
    setRelativeGoal(move_x, move_y, 5, 0, false);

    ROS_WARN("[MpcTracker]: Failsafe ON");

    failsafe_triggered = true;

    publishDiagnostics();

    return true;
  }
}

//}

/* //{ dist() */

double dist(const double ax, const double ay, const double bx, const double by) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

//}

/* //{ checkCollision() */

double MpcTracker::checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (dist(ax, ay, bx, by) < mrs_collision_avoidance_radius && fabs(az - bz) < mrs_collision_avoidance_altitude_threshold) {
    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkCollisionInflated() */

double MpcTracker::checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (dist(ax, ay, bx, by) < mrs_collision_avoidance_radius + 1.0 && fabs(az - bz) < mrs_collision_avoidance_altitude_threshold + 1.0) {
    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkTrajectoryForCollisions() */

// Check for potential collisions and return the needed altitude offset to avoid other drones
double MpcTracker::checkTrajectoryForCollisions(double lowest_z, int &first_collision_index) {

  mutex_des_trajectory.lock();
  first_collision_index = INT_MAX;
  bool avoiding         = false;

  // This variable is used for collision avoidance priority swapping,only the first detected collision is considered for priority swap, subsequent collisons are
  // irrelevant
  bool                                                        first_collision = true;
  std::map<std::string, mrs_msgs::FutureTrajectory>::iterator u               = other_drones_trajectories.begin();

  mutex_predicted_trajectory.lock();
  {
    while (u != other_drones_trajectories.end()) {

      first_collision = true;

      // is the other's trajectory fresh enought?
      if ((ros::Time::now() - u->second.stamp).toSec() < collision_trajectory_timeout) {

        for (int v = 0; v < horizon_len; v++) {

          // check all points of the trajectory for possible collisions
          if (checkCollision(predicted_future_trajectory(v * 9, 0), predicted_future_trajectory(v * 9 + 3, 0), predicted_future_trajectory(v * 9 + 6, 0),
                             u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {

            // collision is detected
            int other_uav_priority = INT_MAX;
            // get the priority of the other uav
            /* sscanf(u->first.c_str(), "uav%d", &other_uav_priority); */
            other_uav_priority = u->second.priority;
            // check if we should be avoiding (out priority is higher, or the other uav has collision avoidance turned off)
            if ((u->second.collision_avoidance == false) || (other_uav_priority < my_uav_priority)) {
              // we should be avoiding
              avoiding                 = true;
              double tmp_safe_altitude = u->second.points[v].z + mrs_collision_avoidance_correction;
              if (tmp_safe_altitude > collision_free_altitude && v <= collision_start_climbing) {
                collision_free_altitude = tmp_safe_altitude;
              }
              ROS_ERROR_STREAM_THROTTLE(1, "[MpcTracker]: Avoiding collision with uav" << other_uav_priority);
            } else {
              // the other drone should be avoiding, except for priority swap
              if (use_priority_swap && first_collision) {
                if (u->second.points[v].z + 0.5 < future_trajectory_out.points[v].z) {
                  priority_time = ros::Time::now();
                  ROS_ERROR_STREAM("[MpcTracker]: LOWERING MY PRIORITY TO AVOID COLLISION " << u->second.points[0].z
                                                                                            << "  my: " << future_trajectory_out.points[0].z);
                  if (my_uav_priority < 1050) {
                    // To prevent priority swapping runaway scenario
                    my_uav_priority += 100;
                  } else {
                    ROS_ERROR("[MpcTracker]: Saturating UAV priority");
                  }
                  continue;
                }
              }
              // the other uav should avoid us
              ROS_WARN_STREAM_THROTTLE(1, "[MpcTracker]: Detected collision with uav" << other_uav_priority << ", not avoiding (My priority is higher)");
              first_collision = false;
            }
          }
          if (checkCollisionInflated(predicted_future_trajectory(v * 9, 0), predicted_future_trajectory(v * 9 + 3, 0),
                                     predicted_future_trajectory(v * 9 + 6, 0), u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {
            // collision is detected
            if (first_collision_index > v) {
              first_collision_index = v;
            }
          }
        }
      }
      u++;
    }
  }
  mutex_predicted_trajectory.unlock();

  mutex_des_trajectory.unlock();
  if (!avoiding) {
    // we are not avoiding any collisions, so we slowly reduce the collision avoidance offset to return to normal flight
    collision_free_altitude -= 0.02;
    if (collision_free_altitude < 0) {
      collision_free_altitude = 0;
    }
  }
  if (collision_free_altitude < lowest_z && my_uav_priority != my_uav_number && (ros::Time::now() - priority_time).toSec() > 5.0) {
    // priority swapping ends when the collision free altitude is lower than the lowest point in our trajectory
    my_uav_priority = my_uav_number;
    ROS_WARN("[MpcTracker]: RETURNING TO ORIGINAL PRIORITY");
  }
  return collision_free_altitude;
}

//}

/* //{ filterReferenceXY() */

void MpcTracker::filterReferenceXY(double max_speed_x, double max_speed_y) {

  double difference_x;
  double difference_y;
  double max_sample_x;
  double max_sample_y;

  for (int i = 0; i < horizon_len; i++) {

    if (i == 0) {
      max_sample_x = max_speed_x * dt;
      max_sample_y = max_speed_y * dt;
      difference_x = des_x_trajectory(i, 0) - x(0, 0);
      difference_y = des_y_trajectory(i, 0) - x(3, 0);
    } else {
      max_sample_x = max_speed_x * dt2;
      max_sample_y = max_speed_y * dt2;
      difference_x = des_x_trajectory(i, 0) - des_x_filtered(i - 1, 0);
      difference_y = des_y_trajectory(i, 0) - des_y_filtered(i - 1, 0);
    }

    // saturate the difference
    if (difference_x > max_sample_x)
      difference_x = max_sample_x;
    else if (difference_x < -max_sample_x)
      difference_x = -max_sample_x;

    if (difference_y > max_sample_y)
      difference_y = max_sample_y;
    else if (difference_y < -max_sample_y)
      difference_y = -max_sample_y;

    if (i == 0) {
      des_x_filtered(i, 0) = x(0, 0) + difference_x;
      des_y_filtered(i, 0) = x(3, 0) + difference_y;
    } else {
      des_x_filtered(i, 0) = des_x_filtered(i - 1, 0) + difference_x;
      des_y_filtered(i, 0) = des_y_filtered(i - 1, 0) + difference_y;
    }
  }
}

//}

/* //{ filterReferenceZ() */

void MpcTracker::filterReferenceZ(double max_speed_z) {
  double difference_z;
  double max_sample_z;
  for (int i = 0; i < horizon_len; i++) {
    if (i == 0) {
      max_sample_z = max_speed_z * dt;
      difference_z = des_z_trajectory(i, 0) - x(6, 0);
    } else {
      max_sample_z = max_speed_z * dt2;
      difference_z = des_z_trajectory(i, 0) - des_z_filtered(i - 1, 0);
    }

    // saturate the difference
    if (difference_z > max_sample_z)
      difference_z = max_sample_z;
    else if (difference_z < -max_sample_z)
      difference_z = -max_sample_z;

    if (i == 0) {
      des_z_filtered(i, 0) = x(6, 0) + difference_z;
    } else {
      des_z_filtered(i, 0) = des_z_filtered(i - 1, 0) + difference_z;
    }
  }
}

//}

/* //{ filterYawReference() */

void MpcTracker::filterYawReference(void) {

  for (int i = 0; i < horizon_len; i++) {
    if (fabs(des_yaw_trajectory(0, 0)) > 1000) {
      ROS_WARN_THROTTLE(0.1, "Desired yaw is greater than 1000 rad!");
    }
  }

  // check the first trajectory member for yaw overflow
  while (des_yaw_trajectory(0, 0) - x_yaw(0) < -PI) {
    for (int i = 0; i < horizon_len; i++) {
      des_yaw_trajectory(i, 0) += 2 * PI;
    }
  }
  while (des_yaw_trajectory(0, 0) - x_yaw(0) > PI) {
    for (int i = 0; i < horizon_len; i++) {
      des_yaw_trajectory(i, 0) -= 2 * PI;
    }
  }

  // check the rest of the trajectory for yaw overflow
  for (int i = 1; i < horizon_len; i++) {
    while (des_yaw_trajectory(i, 0) - des_yaw_trajectory(i - 1, 0) < -PI) {
      for (int j = i; j < horizon_len; j++) {
        des_yaw_trajectory(j, 0) += 2 * PI;
      }
    }
    while (des_yaw_trajectory(i, 0) - des_yaw_trajectory(i - 1, 0) > PI) {
      for (int j = i; j < horizon_len; j++) {
        des_yaw_trajectory(j, 0) -= 2 * PI;
      }
    }
  }
}

//}

/* //{ setTrajectory() */

// sets the desired trajectory based on a single setpoint
void MpcTracker::setTrajectory(float x, float y, float z, float yaw) {

  mutex_des_trajectory.lock();
  {
    des_x_trajectory.fill(x);
    des_y_trajectory.fill(y);
    des_z_trajectory.fill(z);
    des_yaw_trajectory.fill(yaw);
  }
  mutex_des_trajectory.unlock();
  vel_qx = 0;
  vel_qy = 0;
}

//}

/* //{ integrate() */

VectorXd MpcTracker::integrate(VectorXd &in, double dt, double integrational_const) {

  VectorXd out;
  out    = VectorXd::Zero(in.size());
  out(0) = integrational_const;

  for (int i = 1; i < in.size(); i++) {

    out(i) = out(i - 1) + in(i - 1) * dt;
  }

  return out;
}

//}

/* //{ calculateMPC() */

void MpcTracker::calculateMPC() {

  int    first_collision_index = INT_MAX;
  double lowest_z              = std::numeric_limits<double>::max();

  if (mrs_collision_avoidance) {
    // determine the lowest point in our trajectory
    for (int i = 0; i < horizon_len; i++) {
      if (des_z_trajectory(i, 0) < lowest_z) {
        lowest_z = des_z_trajectory(i, 0);
      }
    }
    // Check other drone trajectories for collisions
    minimum_collison_free_altitude = checkTrajectoryForCollisions(lowest_z, first_collision_index);
  }

  mutex_constraints.lock();
  {
    max_jerk_x = max_horizontal_jerk;
    max_jerk_y = max_horizontal_jerk;

    // State and input constraints
    max_speed_x = max_horizontal_speed;
    max_speed_y = max_horizontal_speed;
    max_acc_x   = max_horizontal_acceleration;
    max_acc_y   = max_horizontal_acceleration;

    max_speed_z = max_vertical_ascending_speed;
    max_acc_z   = max_vertical_ascending_acceleration;
    max_jerk_z  = max_vertical_ascending_jerk;
    min_speed_z = max_vertical_descending_speed;
    min_acc_z   = max_vertical_descending_acceleration;
    min_jerk_z  = max_vertical_descending_jerk;
  }
  mutex_constraints.unlock();

  if (first_collision_index < horizon_len) {
    // the tmp variable is used to scale the speed of our drone in collision avoidance, depending on how far away the collision is
    double tmp = 0;
    if (first_collision_index <= collision_slow_down_fully) {
      tmp = 1;
    } else if (first_collision_index <= collision_slow_down_start) {
      tmp = 1.0 - ((double)(first_collision_index - collision_slow_down_fully)) / (double)(collision_slow_down_start - collision_slow_down_fully);
      tmp = tmp * tmp;
    }
    if (!std::isfinite(tmp)) {
      tmp = 1.0;
      ROS_ERROR("[MpcTracker]: NaN detected in variable \"tmp\", setting it to 1.0 and returning!!!");
      return;
    } else if (tmp > 1.0) {
      tmp = 1.0;
    } else if (tmp < 0.0) {
      tmp = 0.0;
    }
    if (tmp > coef_scaler) {
      coef_scaler = tmp;
      coef_time   = ros::Time::now();
    }
    if ((ros::Time::now() - coef_time).toSec() > 2.0) {
      coef_scaler = tmp;
    }

    // We are close to a possible collision, better slow down a bit to give everyone more time
    mutex_constraints.lock();
    {
      max_speed_x = max_horizontal_speed * ((collision_horizontal_speed_coef * coef_scaler) + (1.0 - coef_scaler));
      max_speed_y = max_horizontal_speed * ((collision_horizontal_speed_coef * coef_scaler) + (1.0 - coef_scaler));
    }
    mutex_constraints.unlock();
  }

  if (collision_free_altitude > lowest_z) {
    // we are avoiding someone, increase Z dynamics limit for faster evasion
    max_speed_z = 2.0;
    max_acc_z   = 2.0;
    max_jerk_z  = 2.0;
    min_speed_z = 2.0;
    min_acc_z   = 2.0;
    min_jerk_z  = 4.0;
    mutex_constraints.lock();
    {
      max_speed_x = max_horizontal_speed * (collision_horizontal_speed_coef);
      max_speed_y = max_horizontal_speed * (collision_horizontal_speed_coef);
    }
    mutex_constraints.unlock();
  }

  // First control input generated by cvxgen
  VectorXd cvx_u     = VectorXd::Zero(m);
  double   cvx_u_yaw = 0;

  iters_Z      = 0;
  iters_X      = 0;
  iters_Y      = 0;
  iters_YAW    = 0;
  double vel_q = 0;

  ros::Time time_begin = ros::Time::now();

  filterReferenceZ(max_speed_z);
  // filter desired yaw reference to be feasible and remove PI rollovers
  for (int i = 0; i < horizon_len; i++) {
    if (des_z_filtered(i, 0) < minimum_collison_free_altitude) {
      des_z_filtered_offset(i, 0) = minimum_collison_free_altitude;
    } else {
      des_z_filtered_offset(i, 0) = des_z_filtered(i, 0);
    }
  }

  // | ---------------------- cvxgen Z axis --------------------- |
  initial_z(0, 0) = x(6, 0);
  initial_z(1, 0) = x(7, 0);
  initial_z(2, 0) = x(8, 0);

  if (no_overshoots) {
    vel_q = 8000;
  } else {
    vel_q = 0;
  }

  cvx_z->setInitialState(initial_z);
  cvx_z->loadReference(des_z_filtered_offset);
  cvx_z->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_vertical_ascending_jerk, max_vertical_descending_jerk, vel_q);
  iters_Z += cvx_z->solveCvx();

  mutex_predicted_trajectory.lock();
  { cvx_z->getStates(predicted_future_trajectory); }
  mutex_predicted_trajectory.unlock();

  cvx_u(2) = cvx_z->getFirstControlInput();

  // If we are climbing to avoid a collision, reduce or arrest our horizontal velocity
  double ascend;
  mutex_predicted_trajectory.lock();
  { ascend = (predicted_future_trajectory(7, 0) / max_speed_z); }
  mutex_predicted_trajectory.unlock();

  if (ascend > 0 && collision_free_altitude > lowest_z) {
    max_speed_y = max_speed_y * (1.0 - ascend);
    max_speed_x = max_speed_x * (1.0 - ascend);
  }

  if (!tracking_trajectory_ && (dist(x(0, 0), x(3, 0), des_x_trajectory(0, 0), des_y_trajectory(0, 0)) > 1.0)) {
    // yaw angle at which my drone "sees" the goto reference point
    double goto_yaw = atan2(des_y_trajectory(0, 0) - x(3, 0), des_x_trajectory(0, 0) - x(0, 0));

    // Circle saturation of maximum velocity
    max_speed_x = fabs(max_speed_x * cos(goto_yaw));
    max_speed_y = fabs(max_speed_y * sin(goto_yaw));
  }

  filterYawReference();
  filterReferenceXY(max_speed_x, max_speed_y);

  // | ---------------------- cvxgen X axis --------------------- |
  initial_x(0, 0) = x(0, 0);
  initial_x(1, 0) = x(1, 0);
  initial_x(2, 0) = x(2, 0);

  if (no_overshoots) {
    mutex_predicted_trajectory.lock();
    {
      if (tracking_trajectory_) {
        vel_qx = 8000;
      } else if (fabs(predicted_future_trajectory((horizon_len - 1) * 9, 0) - des_x_trajectory(0, 0)) < 2.0) {
        vel_qx = 8000;
      }
    }
    mutex_predicted_trajectory.unlock();
  }

  cvx_x->setInitialState(initial_x);
  cvx_x->loadReference(des_x_filtered);
  cvx_x->setLimits(max_speed_x, max_speed_x, max_acc_x, max_acc_x, max_jerk_x, max_jerk_x, vel_qx);
  iters_X += cvx_x->solveCvx();
  mutex_predicted_trajectory.lock();
  { cvx_x->getStates(predicted_future_trajectory); }
  mutex_predicted_trajectory.unlock();
  cvx_u(0) = cvx_x->getFirstControlInput();

  // | ---------------------- cvxgen Y axis --------------------- |
  initial_y(0, 0) = x(3, 0);
  initial_y(1, 0) = x(4, 0);
  initial_y(2, 0) = x(5, 0);

  if (no_overshoots) {
    mutex_predicted_trajectory.lock();
    {
      if (tracking_trajectory_) {
        vel_qy = 8000;
      } else if (fabs(predicted_future_trajectory((horizon_len - 1) * 9 + 3, 0) - des_y_trajectory(0, 0)) < 2.0) {
        vel_qy = 8000;
      }
    }
    mutex_predicted_trajectory.unlock();
  }

  cvx_y->setInitialState(initial_y);
  cvx_y->loadReference(des_y_filtered);
  cvx_y->setLimits(max_speed_y, max_speed_y, max_acc_y, max_acc_y, max_jerk_y, max_jerk_y, vel_qy);
  iters_Y += cvx_y->solveCvx();
  mutex_predicted_trajectory.lock();
  { cvx_y->getStates(predicted_future_trajectory); }
  mutex_predicted_trajectory.unlock();
  cvx_u(1) = cvx_y->getFirstControlInput();

  // | ---------------------- cvxgen Z axis --------------------- |
  initial_z(0, 0) = x(6, 0);
  initial_z(1, 0) = x(7, 0);
  initial_z(2, 0) = x(8, 0);

  mutex_predicted_trajectory.lock();
  {
    if (fabs(predicted_future_trajectory((horizon_len - 1) * 9 + 6, 0) - des_z_trajectory(0, 0)) < 2.0 && no_overshoots) {
      vel_q = 8000;
    } else {
      vel_q = 0;
    }
  }
  mutex_predicted_trajectory.unlock();

  cvx_z->setInitialState(initial_z);
  cvx_z->loadReference(des_z_filtered_offset);
  mutex_constraints.lock();
  { cvx_z->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_vertical_ascending_jerk, max_vertical_descending_jerk, vel_q); }
  mutex_constraints.unlock();
  iters_Z += cvx_z->solveCvx();
  mutex_predicted_trajectory.lock();
  { cvx_z->getStates(predicted_future_trajectory); }
  mutex_predicted_trajectory.unlock();
  cvx_u(2) = cvx_z->getFirstControlInput();

  // | ---------------------- cvxgen YAW axis --------------------- |
  cvx_yaw->setInitialState(x_yaw);
  cvx_yaw->loadReference(des_yaw_trajectory);
  mutex_constraints.lock();
  { cvx_yaw->setLimits(max_yaw_rate, max_yaw_rate, max_yaw_acceleration, max_yaw_acceleration, max_yaw_jerk, max_yaw_jerk, 0); }
  mutex_constraints.unlock();
  iters_YAW += cvx_yaw->solveCvx();
  mutex_predicted_trajectory.lock();
  { cvx_yaw->getStates(predicted_future_yaw_trajectory); }
  mutex_predicted_trajectory.unlock();
  cvx_u_yaw = cvx_yaw->getFirstControlInput();

  mutex_constraints.lock();
  {
    if (cvx_u(0) > max_horizontal_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jerk X: " << cvx_u(0));
      cvx_u(0) = max_horizontal_jerk;
    }
    if (cvx_u(0) < -max_horizontal_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jert X: " << cvx_u(0));
      cvx_u(0) = -max_horizontal_jerk;
    }
    if (cvx_u(1) > max_horizontal_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jerk Y: " << cvx_u(1));
      cvx_u(1) = max_horizontal_jerk;
    }
    if (cvx_u(1) < -max_horizontal_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jerk Y: " << cvx_u(1));
      cvx_u(1) = -max_horizontal_jerk;
    }
    if (cvx_u(2) > max_vertical_ascending_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jerk Z: " << cvx_u(2));
      cvx_u(2) = max_vertical_ascending_jerk;
    }
    if (cvx_u(2) < -max_vertical_descending_jerk * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating jerk Z: " << cvx_u(2));
      cvx_u(2) = -max_vertical_descending_jerk;
    }
  }
  mutex_constraints.unlock();

  double cvx_time = (ros::Time::now() - time_begin).toSec();
  if (cvx_time > 0.01 || iters_X > max_iters_XY || iters_Y > max_iters_XY || iters_Z > max_iters_Z || iters_YAW > max_iters_YAW) {
    ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Total CVXtime: " << cvx_time << " iters X: " << iters_X << "/" << max_iters_XY << " iters Y:  " << iters_Y
                                                                  << "/" << max_iters_XY << " iters Z: " << iters_Z << "/" << max_iters_Z
                                                                  << " iters yaw: " << iters_YAW << "/" << max_iters_YAW);
  }

  x_mutex.lock();
  {
    x     = A * x + B * cvx_u;
    x_yaw = A_yaw * x_yaw + B_yaw * cvx_u_yaw;

    // fix possible PI overflows
    if (x_yaw(0) > PI) {
      x_yaw(0) -= 2 * PI;
    } else if (x_yaw(0) < -PI) {
      x_yaw(0) += 2 * PI;
    }
  }
  x_mutex.unlock();

  future_was_predicted = true;
}

//}

/* //{ publishDiagnostics() */

void MpcTracker::publishDiagnostics(void) {

  mrs_msgs::TrackerDiagnostics diagnostics;

  diagnostics.header.stamp    = ros::Time::now();
  diagnostics.header.frame_id = "local_origin";

  diagnostics.tracker_active = is_active;

  // true if tracking_trajectory of if flying to a setpoint
  diagnostics.tracking_trajectory = false;

  if (tracking_trajectory_) {
    diagnostics.tracking_trajectory = true;
  } else {
    if (sqrt(pow(x(0, 0) - des_x_trajectory(0), 2) + pow(x(3, 0) - des_y_trajectory(0), 2) + pow(x(6, 0) - des_z_trajectory(0), 2)) >
        diagnostic_tracking_threshold) {
      diagnostics.tracking_trajectory = true;
    }
  }

  diagnostics.trajectory_length = trajectory_size;
  diagnostics.trajectory_idx    = trajectory_idx;
  diagnostics.trajectory_count  = trajectory_count;
  diagnostics.failsafe_active   = failsafe_triggered;

  diagnostics.setpoint.position.x = des_x_trajectory(0, 0);
  diagnostics.setpoint.position.y = des_y_trajectory(0, 0);
  diagnostics.setpoint.position.z = des_z_trajectory(0, 0);

  tf::Quaternion orientation;
  orientation.setEuler(0, 0, desired_yaw);
  diagnostics.setpoint.orientation.x = orientation.x();
  diagnostics.setpoint.orientation.y = orientation.y();
  diagnostics.setpoint.orientation.z = orientation.z();
  diagnostics.setpoint.orientation.w = orientation.w();

  try {
    pub_diagnostics_.publish(mrs_msgs::TrackerDiagnosticsConstPtr(new mrs_msgs::TrackerDiagnostics(diagnostics)));
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_diagnostics_.getTopic().c_str());
  }
}

//}

/* //{ setRelativeGoal() */

bool MpcTracker::setRelativeGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

  double abs_x   = x(0, 0) + set_x;
  double abs_y   = x(3, 0) + set_y;
  double abs_z   = x(6, 0) + set_z;
  double abs_yaw = x_yaw(0, 0) + set_yaw;

  if (set_use_yaw) {
    des_yaw_mutex.lock();
    desired_yaw = abs_yaw;
    des_yaw_mutex.unlock();
  }

  mutex_des_trajectory.lock();
  tracking_trajectory_ = false;
  mutex_des_trajectory.unlock();

  setTrajectory(abs_x, abs_y, abs_z, abs_yaw);

  if (set_use_yaw) {
    ROS_INFO("[MpcTracker]: Setting Relative Goal to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f which moves it to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f.", set_x,
             set_y, set_z, set_yaw, abs_x, abs_y, abs_z, abs_yaw);
  } else {
    ROS_INFO("[MpcTracker]: Setting Relative Goal to x: %2.2f y: %2.2f z: %2.2f which moves it to x: %2.2f y: %2.2f z: %2.2f.", set_x, set_y, set_z, abs_x,
             abs_y, abs_z);
  }

  publishDiagnostics();

  return true;
}

//}

/* //{ loadTrajectory() */

// method for setting desired trajectory
bool MpcTracker::loadTrajectory(const mrs_msgs::TrackerTrajectory &msg, std::string &message) {

  if (failsafe_triggered) {

    message = "Failsafe is active!";
    ROS_WARN("[MpcTracker]: %s", message.c_str());
    return false;
  }

  if (int(msg.points.size()) > (max_trajectory_size - horizon_len - 1)) {

    ROS_WARN("[MpcTracker]: Cannot load trajectory, its too large (%d).", (int)msg.points.size());

    char buffer[60];
    sprintf(buffer, "Cannot load trajectory, its too large (%d).", (int)msg.points.size());
    message = buffer;
    return false;

  } else if (msg.points.size() == 0) {

    message = "Cannot load trajectory with size 0.";
    ROS_WARN("[MpcTracker]: %s", message.c_str());
    return false;

  } else {

    mutex_des_trajectory.lock();
    mutex_des_whole_trajectory.lock();
    {

      trajectory_size = msg.points.size();

      // copy the trajectories
      for (int i = 0; i < trajectory_size; i++) {

        des_x_whole_trajectory(i) = msg.points[i].x;
        des_y_whole_trajectory(i) = msg.points[i].y;
        des_z_whole_trajectory(i) = msg.points[i].z;
      }

      // set looping
      if (msg.loop) {

        // check whether the trajectory iss loopable
        if (dist(des_x_whole_trajectory(0), des_y_whole_trajectory(0), des_x_whole_trajectory(trajectory_size - 1),
                 des_y_whole_trajectory(trajectory_size - 1)) < 4) {

          loop = true;

        } else {

          loop = false;
        }
      } else {
        loop = false;
      }

      bool   trajectory_is_ok = true;
      double min_height       = safety_area->getMinHeight();
      double max_height       = safety_area->getMaxHeight();

      // check the safety area
      if (safety_area->use_safety_area) {

        int last_valid_idx    = 0;
        int first_invalid_idx = -1;
        for (int i = 0; i < trajectory_size; i++) {

          // saturate the trajectory to min and max height
          if (des_z_whole_trajectory(i) < min_height) {
            des_z_whole_trajectory(i) = min_height;
          }
          if (des_z_whole_trajectory(i) > max_height) {
            des_z_whole_trajectory(i) = max_height;
          }

          // the point is not feasible
          if (!safety_area->isPointInSafetyArea2d(des_x_whole_trajectory(i), des_y_whole_trajectory(i))) {

            ROS_WARN_THROTTLE(1.0, "The trajectory contains points outside of the safety area!");
            trajectory_is_ok = false;

            // we found the left point
            if (first_invalid_idx == -1) {

              first_invalid_idx = i;

              last_valid_idx = i - 1;
            }

            // the point is ok
          } else {

            // we found the right point
            if (first_invalid_idx != -1) {

              // interpolate
              // TODO dont do this when fly_now == true and just start the trajectory in the first valid point
              if (last_valid_idx == -1) {  // special case, we had no valid point so far

                // interpolate between the current position and the valid point
                double angle           = atan2((des_y_whole_trajectory(i) - x(3, 0)), (des_x_whole_trajectory(i) - x(0, 0)));
                double dist_two_points = dist(des_x_whole_trajectory(i), des_y_whole_trajectory(i), x(0, 0), x(3, 0));
                double step            = dist_two_points / i;

                for (int j = 0; j < i; j++) {

                  des_x_whole_trajectory(j) = x(0, 0) + j * cos(angle) * step;
                  des_y_whole_trajectory(j) = x(3, 0) + j * sin(angle) * step;
                }

                // we have a valid point in the past
              } else {

                // iterpolate between the valid point and this point
                double angle = atan2((des_y_whole_trajectory(i) - des_y_whole_trajectory(last_valid_idx)),
                                     (des_x_whole_trajectory(i) - des_x_whole_trajectory(last_valid_idx)));
                double dist_two_points =
                    dist(des_x_whole_trajectory(i), des_y_whole_trajectory(i), des_x_whole_trajectory(last_valid_idx), des_y_whole_trajectory(last_valid_idx));
                double step = dist_two_points / (i - last_valid_idx);

                for (int j = last_valid_idx + 1; j < i; j++) {

                  des_x_whole_trajectory(j) = des_x_whole_trajectory(last_valid_idx) + (j - last_valid_idx) * cos(angle) * step;
                  des_y_whole_trajectory(j) = des_y_whole_trajectory(last_valid_idx) + (j - last_valid_idx) * sin(angle) * step;
                }
              }

              first_invalid_idx = -1;
            }
          }
        }

        // special case, the trajectory does not end with a valid point
        if (first_invalid_idx != -1) {

          // super special case, the whole trajectory is invalid
          if (first_invalid_idx == 0) {

            // stay where we are
            for (int i = 0; i < trajectory_size; i++) {

              des_x_whole_trajectory(i) = x(0, 0);
              des_y_whole_trajectory(i) = x(3, 0);
            }

          } else {

            // delete the end of the trajectory beginning with the last invalid point
            for (int i = last_valid_idx + 1; i < trajectory_size; i++) {

              des_x_whole_trajectory(i) = des_x_whole_trajectory(last_valid_idx);
              des_y_whole_trajectory(i) = des_y_whole_trajectory(last_valid_idx);
            }
          }
        }
      }

      // extend it so it has smooth ending
      for (int i = 0; i < horizon_len; i++) {

        des_x_whole_trajectory(i + trajectory_size) = des_x_whole_trajectory(i + trajectory_size - 1);
        des_y_whole_trajectory(i + trajectory_size) = des_y_whole_trajectory(i + trajectory_size - 1);
        des_z_whole_trajectory(i + trajectory_size) = des_z_whole_trajectory(i + trajectory_size - 1);
      }

      if (msg.use_yaw) {

        use_yaw_in_trajectory = true;

        for (int i = 0; i < trajectory_size; i++) {

          des_yaw_whole_trajectory(i) = msg.points[i].yaw;
        }

        for (int i = 0; i < horizon_len; i++) {

          des_yaw_whole_trajectory(i + trajectory_size) = des_yaw_whole_trajectory(i + trajectory_size - 1);
        }
      } else {

        des_yaw_whole_trajectory.fill(desired_yaw);
        use_yaw_in_trajectory = false;
      }

      if (msg.fly_now) {

        tracking_trajectory_ = true;
      } else {

        tracking_trajectory_ = false;
      }

      // set the starting index accoarding to the message
      if (msg.start_index >= 0 && msg.start_index < trajectory_size)
        trajectory_idx = msg.start_index;
      else
        trajectory_idx = 0;

      trajectory_set_ = true;
      trajectory_count++;

      // if we are tracking trajectory, copy the setpoint
      if (tracking_trajectory_) {

        for (int i = 0; i < horizon_len; i++) {

          des_x_trajectory(i)   = des_x_whole_trajectory(i);
          des_y_trajectory(i)   = des_y_whole_trajectory(i);
          des_z_trajectory(i)   = des_z_whole_trajectory(i);
          des_yaw_trajectory(i) = des_yaw_whole_trajectory(i);
        }

        if (use_yaw_in_trajectory) {
          desired_yaw = des_yaw_whole_trajectory(trajectory_idx);
        }
      }

      ROS_INFO_THROTTLE(1, "Setting trajectory with length %d", trajectory_size);

      publishDiagnostics();

      if (trajectory_is_ok) {
        message = "The trajectory successfully loaded.";
      } else {
        message = "The trajectory was modified because it contains points outside of the safety area!";
      }
    }
    mutex_des_trajectory.unlock();
    mutex_des_whole_trajectory.unlock();

    return true;
  }
}

//}

/* //{ setGoal() */

// set absolute goal
bool MpcTracker::setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

  if (set_use_yaw) {

    des_yaw_mutex.lock();
    desired_yaw = set_yaw;
    des_yaw_mutex.unlock();
  }

  setTrajectory(set_x, set_y, set_z, set_yaw);

  tracking_trajectory_ = false;

  if (set_use_yaw) {
    ROS_INFO("[MpcTracker]: Setting Goal to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f", set_x, set_y, set_z, set_yaw);
  } else {
    ROS_INFO("[MpcTracker]: Setting Goal to x: %2.2f y: %2.2f z: %2.2f", set_x, set_y, set_z);
  }

  publishDiagnostics();

  return true;
}

//}

// --------------------------------------------------------------
// |                           timers                           |
// --------------------------------------------------------------

/* //{ diagnosticsTimer() */

// published diagnostics in reguar intervals
void MpcTracker::diagnosticsTimer(const ros::TimerEvent &event) {

  if (!is_initialized)
    return;

  routine_diagnostics_timer->start();

  publishDiagnostics();

  routine_diagnostics_timer->end();
}

//}

/* //{ mpcTimer() */

void MpcTracker::mpcTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  if (!is_initialized)
    return;

  routine_mpc_timer->start(event);

  ros::Time     begin = ros::Time::now();
  ros::Time     end;
  ros::Duration interval;

  mutex_des_trajectory.lock();
  {
    // if we are tracking trajectory, copy the setpoint
    if (tracking_trajectory_ && trajectory_tracking_timer++ == 20 && trajectory_idx < (trajectory_size)) {

      trajectory_tracking_timer = 0;

      // fill the prediction horizon with the desired trajectory
      for (int i = 0; i < horizon_len; i++) {

        int tempIdx = i + trajectory_idx;
        if (loop) {

          if (tempIdx >= trajectory_size) {

            tempIdx = tempIdx % trajectory_size;
          }
        }

        mutex_des_whole_trajectory.lock();
        {
          des_x_trajectory(i)   = des_x_whole_trajectory(tempIdx);
          des_y_trajectory(i)   = des_y_whole_trajectory(tempIdx);
          des_z_trajectory(i)   = des_z_whole_trajectory(tempIdx);
          des_yaw_trajectory(i) = des_yaw_whole_trajectory(tempIdx);
        }
        mutex_des_whole_trajectory.unlock();
      }

      if (use_yaw_in_trajectory)
        desired_yaw = des_yaw_whole_trajectory(trajectory_idx);

      if (loop) {  // if we are looping, the loop it
        if (++trajectory_idx == trajectory_size) {
          trajectory_idx = 0;
        }
      } else {
        // if we are at the end, select the last point as a constant setpoint
        if (++trajectory_idx == (trajectory_size)) {

          tracking_trajectory_ = false;
          ROS_INFO("[MpcTracker]: Done tracking trajectory.");
          publishDiagnostics();
        }
      }
    }
  }
  mutex_des_trajectory.unlock();

  // run the mpc
  calculateMPC();

  end      = ros::Time::now();
  interval = end - begin;
  if (interval.toSec() > dt) {

    mpc_total_delay += interval.toSec() - dt;
    ROS_WARN_THROTTLE(10.0, "[MpcTracker] MPC is Running %2.2f%% slower than it should.", 100 * mpc_total_delay / (ros::Time::now() - mpc_start_time).toSec());
  }

  mpc_computed_ = true;
  if (publish_debug_trajectory) {

    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = ros::Time::now();
    debug_trajectory_out.header.frame_id = "local_origin";

    mutex_predicted_trajectory.lock();
    {
      for (int i = 0; i < horizon_len; i++) {

        geometry_msgs::Pose newPose;

        newPose.position.x = predicted_future_trajectory(i * n);
        newPose.position.y = predicted_future_trajectory(i * n + 3);
        newPose.position.z = predicted_future_trajectory(i * n + 6);

        tf::Quaternion orientation;
        orientation.setEuler(0, 0, predicted_future_yaw_trajectory(i * n));
        newPose.orientation.x = orientation.x();
        newPose.orientation.y = orientation.y();
        newPose.orientation.z = orientation.z();
        newPose.orientation.w = orientation.w();

        debug_trajectory_out.poses.push_back(newPose);
      }
    }
    mutex_predicted_trajectory.unlock();

    try {
      debug_predicted_trajectory_publisher.publish(geometry_msgs::PoseArrayConstPtr(new geometry_msgs::PoseArray(debug_trajectory_out)));
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", debug_predicted_trajectory_publisher.getTopic().c_str());
    }
  }

  routine_mpc_timer->end();
}

//}

/* //{ futureTrajectoryTimer() */

void MpcTracker::futureTrajectoryTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  if (!is_initialized)
    return;

  routine_future_trajectory_timer->start();

  if (future_was_predicted) {

    future_trajectory_out.points.clear();
    future_trajectory_out.stamp               = ros::Time::now();
    future_trajectory_out.uav_name            = uav_name_;
    future_trajectory_out.priority            = my_uav_priority;
    future_trajectory_out.collision_avoidance = mrs_collision_avoidance;

    // fill the trajectory
    mutex_predicted_trajectory.lock();
    {
      for (int i = 0; i < horizon_len; i++) {

        mrs_msgs::FuturePoint newPoint;

        newPoint.x = predicted_future_trajectory(i * n);
        newPoint.y = predicted_future_trajectory(i * n + 3);
        newPoint.z = predicted_future_trajectory(i * n + 6);

        future_trajectory_out.points.push_back(newPoint);
      }
    }
    mutex_predicted_trajectory.unlock();

    try {
      predicted_trajectory_publisher.publish(mrs_msgs::FutureTrajectoryConstPtr(new mrs_msgs::FutureTrajectory(future_trajectory_out)));
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", predicted_trajectory_publisher.getTopic().c_str());
    }
  }

  routine_future_trajectory_timer->end();
}

//}
}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::MpcTracker, mrs_mav_manager::Tracker)
