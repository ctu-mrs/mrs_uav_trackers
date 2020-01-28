/* includes //{ */

#include <ros/ros.h>

#include <math.h>
#include <cmath>
#include <mutex>
#include <tf/transform_datatypes.h>
#include <Eigen/Eigen>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <nav_msgs/Odometry.h>

#include <mrs_msgs/FuturePoint.h>
#include <mrs_msgs/FutureTrajectory.h>
#include <mrs_msgs/FuturePointInt8.h>
#include <mrs_msgs/FutureTrajectoryInt8.h>
#include <mrs_msgs/MpcTrackerDiagnostics.h>
#include <mrs_msgs/TrackerTrajectory.h>
#include <mrs_msgs/TrackerTrajectorySrv.h>
#include <mrs_msgs/MpcMatrix.h>
#include <mrs_msgs/MpcMatrixRequest.h>
#include <mrs_msgs/MpcMatrixResponse.h>
#include <mrs_msgs/OdometryDiag.h>
#include <mrs_msgs/UavState.h>

#include <mrs_uav_manager/Tracker.h>

#include <mrs_lib/ConvexPolygon.h>
#include <mrs_lib/Profiler.h>
#include <mrs_lib/Utils.h>
#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/mutex.h>

#include <dynamic_reconfigure/server.h>
#include <mrs_trackers/cvx_wrapper.h>

#include <mrs_trackers/mpc_trackerConfig.h>

#include <commons.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

//}

/* defines //{ */

#define STRING_EQUAL 0

using quat_t = Eigen::Quaterniond;

//}

using namespace Eigen;

namespace mrs_trackers
{

namespace mpc_tracker
{

/* //{ class MpcTracker */

class MpcTracker : public mrs_uav_manager::Tracker {
public:
  virtual void initialize(const ros::NodeHandle &parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);
  virtual bool resetStatic(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr &msg, const mrs_msgs::AttitudeCommand::ConstPtr &cmd);
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);
  virtual const mrs_msgs::TrackerStatus             getStatus();
  virtual void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr &msg);

  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goTo(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::ReferenceSrvResponse::ConstPtr goToRelative(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   goToAltitude(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYaw(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);
  virtual const mrs_msgs::Float64SrvResponse::ConstPtr   setYawRelative(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd);

  virtual bool goTo(const mrs_msgs::ReferenceConstPtr &msg);

  virtual const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr &cmd);

  virtual const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd);

private:
  bool callbacks_enabled = true;

private:
  ros::NodeHandle                                    nh_;
  std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers;

  // nodelet variables
  ros::Subscriber    sub_trajectory_;                   // desired trajectory
  ros::Subscriber    sub_odometry_diagnostics_;         // odometry diagnostics
  ros::ServiceServer ser_start_trajectory_following_;   // start trajectory following
  ros::ServiceServer ser_stop_trajectory_following_;    // stop trajectory following
  ros::ServiceServer ser_resume_trajectory_following_;  // resume trajectory following
  ros::ServiceServer ser_fly_to_trajectory_start_;      // fly to the first point of the trajectory
  ros::ServiceServer ser_set_trajectory_;               // service for setting desired trajectory
  ros::ServiceServer set_yaw_service_cmd_cb;
  ros::ServiceServer set_set_mpc_matrix;  // set matrices in cvxgen
  ros::ServiceServer service_client_wiggle;
  ros::ServiceServer collision_avoidance_service;

  // debugging publishers
  ros::Publisher pub_cmd_acceleration_;
  ros::Publisher pub_setpoint_odom;
  ros::Publisher pub_diagnostics_;

  ros::Publisher pub_debug_original_trajectory_poses_;
  ros::Publisher pub_debug_original_trajectory_markers_;

  ros::Publisher pub_debug_processed_trajectory_poses_;
  ros::Publisher pub_debug_processed_trajectory_markers_;

  mrs_msgs::UavState uav_state_;
  std::mutex         mutex_uav_state_;

  mrs_msgs::FutureTrajectory     future_trajectory_out;
  mrs_msgs::FutureTrajectoryInt8 future_trajectory_esp_out;
  mrs_msgs::PositionCommand      position_cmd_;  // message being returned

  bool      odom_set_      = false;
  bool      is_active      = false;
  bool      is_initialized = false;
  double    kx_[3], kv_[3];
  double    new_kx_[3], new_kv_[3];
  double    cur_yaw_;
  ros::Time odomLastTime;

  // variables for yaw tracker
  double max_yaw_rate_old;
  double yaw_gain;

  // variables regarding the MPC controller
  int       n;             // number of states
  int       m;             // number of inputs
  int       n_yaw;         // number of states - yaw
  int       m_yaw;         // number of inputs - yaw
  int       horizon_len_;  // lenght of the prediction horizon
  double    minimum_collison_free_altitude = std::numeric_limits<float>::lowest();
  int       active_collision_index         = INT_MAX;
  double    coef_scaler                    = 0;
  ros::Time coef_time;

  // constraints
  std::mutex                             mutex_constraints;
  ros::Time                              priority_time;
  mrs_msgs::TrackerConstraintsSrvRequest desired_constraints;
  bool                                   all_constraints_set = false;
  double                                 max_horizontal_speed;
  double                                 max_horizontal_acceleration;
  double                                 max_horizontal_jerk;
  double                                 max_horizontal_snap;
  double                                 max_vertical_ascending_acceleration;
  double                                 max_vertical_ascending_speed;
  double                                 max_vertical_ascending_jerk;
  double                                 max_vertical_ascending_snap;
  double                                 max_vertical_descending_speed;
  double                                 max_vertical_descending_acceleration;
  double                                 max_vertical_descending_jerk;
  double                                 max_vertical_descending_snap;
  double                                 max_yaw_rate;
  double                                 max_yaw_acceleration;
  double                                 max_yaw_jerk;
  double                                 max_yaw_snap;

  bool publish_debug_trajectory = false;

  int      max_iters_XY, max_iters_Z, max_iters_YAW;
  int      iters_X     = 0;
  int      iters_Y     = 0;
  int      iters_Z     = 0;
  int      iters_YAW   = 0;
  double   max_speed_x = 0;
  double   max_speed_y = 0;
  double   max_acc_x   = 0;
  double   max_acc_y   = 0;
  double   max_jerk_x  = 0;
  double   max_jerk_y  = 0;
  double   max_snap_x  = 0;
  double   max_snap_y  = 0;
  double   max_speed_z = 0;
  double   max_acc_z   = 0;
  double   max_jerk_z  = 0;
  double   max_snap_z  = 0;
  double   min_speed_z = 0;
  double   min_acc_z   = 0;
  double   min_jerk_z  = 0;
  double   min_snap_z  = 0;
  MatrixXd initial_x   = MatrixXd::Zero(4, 1);  // initial x state to be used by cvxgen
  MatrixXd initial_y   = MatrixXd::Zero(4, 1);  // initial y state to be used by cvxgen
  MatrixXd initial_z   = MatrixXd::Zero(4, 1);  // initial z state to be used by cvxgen
  MatrixXd initial_yaw = MatrixXd::Zero(4, 1);  // initial yaw state to be used by cvxgen

  double diagnostic_position_tracking_threshold;
  double diagnostic_orientation_tracking_threshold;

  mrs_trackers::cvx_wrapper::CvxWrapper *cvx_x;
  mrs_trackers::cvx_wrapper::CvxWrapper *cvx_y;
  mrs_trackers::cvx_wrapper::CvxWrapper *cvx_z;
  mrs_trackers::cvx_wrapper::CvxWrapper *cvx_yaw;

  double   dt, dt2;  // time difference of the dynamical system
  MatrixXd A;        // system matrix for virtual UAV
  MatrixXd B;        // input matrix for virtual UAV

  MatrixXd A_yaw;  // system matrix for yaw
  MatrixXd B_yaw;  // input matrix for yaw

  // trajectories
  MatrixXd des_x_trajectory_;    // trajectory reference over the prediction horizon
  MatrixXd des_y_trajectory_;    // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory_;    // trajectory reference over the prediction horizon
  MatrixXd des_yaw_trajectory_;  // trajectory reference over the prediction horizon

  MatrixXd des_z_filtered_offset;  // trajectory reference over the prediction horizon
  MatrixXd des_x_filtered;         // filtered trajectory reference over the horizon
  MatrixXd des_y_filtered;         // filtered trajectory reference over the horizon
  MatrixXd des_z_filtered;         // filtered trajectory reference over the horizon

  VectorXd cvxgen_horizontal_vel_constraint;  // velocity constraint for the XY cvxgen solver
  VectorXd cvxgen_horizontal_acc_constraint;  // acceleration constraint for the XY cvxgen solver

  VectorXd   des_x_whole_trajectory_;    // long trajectory reference
  VectorXd   des_y_whole_trajectory_;    // long trajectory reference
  VectorXd   des_z_whole_trajectory_;    // long trajectory reference
  VectorXd   des_yaw_whole_trajectory_;  // long trajectory reference
  std::mutex mutex_des_whole_trajectory;

  bool use_yaw_in_trajectory_ = false;

  bool tracking_trajectory_       = false;  // are we currently tracking a trajectory
  int  trajectory_tracking_timer_ = 0;      // [0-20), increases with every iteration of the simulated model
  int  trajectory_idx_;                     // while tracking, this is the current index in the des_whole trjectory
  int  trajectory_size_;
  int  _max_trajectory_size_;
  bool trajectory_set_ = false;
  int  trajectory_count_;  // counts how many trajectories have we received
  bool loop_ = false;

  MatrixXd reference;      // XYZ reference for the controller
  MatrixXd reference_yaw;  // yaw reference for the controlle
  MatrixXd x_;             // current state of the uav
  MatrixXd x_yaw_;         // current yaw of the uav

  // yaw tracker
  double yaw_rate;
  double yaw;
  double desired_yaw;

  // odometry reset
  bool resetting_odometry = false;
  bool mpc_result_invalid = false;

  // predicting the future
  MatrixXd   predicted_future_yaw_trajectory;
  MatrixXd   predicted_future_trajectory;
  MatrixXd   predicted_future_trajectory_esp;
  std::mutex mutex_predicted_trajectory;

  std::string                                            uav_name_;
  std::vector<std::string>                               other_drone_names_;
  std::map<std::string, mrs_msgs::FutureTrajectory>      other_drones_trajectories;
  std::map<std::string, mrs_msgs::MpcTrackerDiagnostics> other_drones_diagnostics;
  std::vector<ros::Subscriber>                           other_uav_prediction_subscribers;
  std::vector<ros::Subscriber>                           other_uav_diag_subscribers;
  std::mutex                                             mutex_other_drone_trajecotries;
  std::mutex                                             mutex_other_drone_diagnostics;

  ros::Publisher predicted_trajectory_publisher;
  ros::Publisher predicted_trajectory_esp_publisher;
  ros::Publisher debug_predicted_trajectory_publisher;
  ros::Publisher debug_mpc_reference_publisher;
  bool           collision_avoidance_enabled_ = false;
  bool           use_priority_swap            = false;
  double         predicted_trajectory_publish_rate;
  double         mrs_collision_avoidance_radius;
  double         mrs_collision_avoidance_correction;
  std::string    predicted_trajectory_topic;
  std::string    diagnostics_topic;
  void           callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg);
  void           callbackOtherMavDiagnostics(const mrs_msgs::MpcTrackerDiagnosticsConstPtr &msg);
  bool           future_was_predicted = false;
  double         mrs_collision_avoidance_altitude_threshold;
  double         checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  double         checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  int            my_uav_number;
  int            my_uav_priority;
  double         collision_free_altitude;
  ros::Time      avoiding_collision_time;
  ros::Time      being_avoided_time;
  bool           callbackToggleCollisionAvoidance(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  double         collision_horizontal_speed_coef;
  int            collision_slow_down_fully;
  int            collision_slow_down_start;
  int            collision_start_climbing;
  int            earliest_collision_idx;
  double         collision_trajectory_timeout;
  bool           avoiding_collision = false;

  void                   callbackOdometryDiagnostics(const mrs_msgs::OdometryDiagConstPtr &msg);
  mrs_msgs::OdometryDiag odometry_diagnostics;
  bool                   got_odometry_diagnostics = false;
  std::mutex             mutex_odometry_diagnostics;

  // --------------------------------------------------------------
  // |                     dynamic reconfigure                    |
  // --------------------------------------------------------------
  void dynamicReconfigureCallback(mrs_trackers::mpc_trackerConfig &config, uint32_t level);

  boost::recursive_mutex                      config_mutex_;
  typedef mrs_trackers::mpc_trackerConfig     Config;
  typedef dynamic_reconfigure::Server<Config> ReconfigureServer;
  boost::shared_ptr<ReconfigureServer>        reconfigure_server_;
  void                                        drs_callback(mrs_trackers::mpc_trackerConfig &config, uint32_t level);
  mrs_trackers::mpc_trackerConfig             drs_params;

private:
  ros::Timer future_trajectory_timer;
  void       futureTrajectoryTimer(const ros::TimerEvent &event);

private:
  ros::Timer diagnostics_timer;
  double     diagnostics_rate;
  void       diagnosticsTimer(const ros::TimerEvent &event);

private:
  MatrixXd   outputTrajectory;
  std::mutex mutex_x, mutex_des_trajectory, des_yaw_mutex;

  ros::Timer mpc_timer;
  bool       running_mpc_timer = false;

private:
  ros::Timer hover_timer;
  void       hoverTimer(const ros::TimerEvent &event);
  bool       running_hover_timer  = false;
  bool       hovering_in_progress = false;
  void       toggleHover(bool in);

  bool mpc_computed_ = false;

  // for integrating the delay caused by long mpc calculations
  ros::Time mpc_start_time;
  double    mpc_total_delay = 0;

  // methods
  void     mpcTimer(const ros::TimerEvent &event);
  void     pos_cmd_cb(const mrs_msgs::Reference::ConstPtr &msg);
  void     callbackDesiredPositionRelative(const mrs_msgs::Reference::ConstPtr &msg);
  void     callbackDesiredTrajectory(const mrs_msgs::TrackerTrajectory::ConstPtr &msg);
  bool     callbackSetTrajectory(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res);
  bool     callbackStartTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackStopTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackResumeTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool     callbackFlyToTrajectoryStart(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void     odom_cb(const nav_msgs::OdometryConstPtr &msg);
  void     calculateMPC();
  void     manageConstraints();
  void     setTrajectory(float x, float y, float z, float yaw);
  bool     loadTrajectory(const mrs_msgs::TrackerTrajectory &msg, std::string &message, bool &modified);
  double   checkTrajectoryForCollisions(double lowest_z, int &first_collision_index);
  void     filterReferenceXY(double max_speed_x, double max_speed_y);
  void     filterReferenceZ(double max_speed_z);
  void     filterYawReference(void);
  VectorXd integrate(VectorXd &in, double dt, double integrational_const);
  bool     setRelativeGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool     setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool     callbackSetQ(mrs_msgs::MpcMatrixRequest &req, mrs_msgs::MpcMatrixResponse &res);
  void     publishDiagnostics();
  double   triangleArea(Eigen::VectorXd a, Eigen::VectorXd b, Eigen::VectorXd c);
  bool     pointInBoundary(Eigen::MatrixXd boundary, double px, double py);

  bool callbackSetYaw(mrs_msgs::Float64Srv::Request &req, mrs_msgs::Float64Srv::Response &res);
  void desired_yaw_cmd_cb(const mrs_msgs::TrackerPoint::ConstPtr &msg);

private:
  mrs_lib::Profiler profiler;
  bool              profiler_enabled_ = false;

private:
  bool               headless_mode      = false;
  bool               time_agnostic_mode = false;
  bool               callbackHeadlessMode(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  bool               callbackTimeAgnosticMode(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  ros::ServiceServer service_server_headless_mode;
  ros::ServiceServer service_server_time_agnostic_mode;

private:
  Eigen::Vector2d rotateVector(const Eigen::Vector2d vector_in, double angle);
  double          interpolateAngles(const double a1, const double a2, const double coeff);

private:
  bool       wiggle_enabled_ = false;
  double     wiggle_amplitude_;
  double     wiggle_frequency_;
  double     wiggle_phase = 0;
  std::mutex mutex_wiggle;
  bool       callbackWiggle(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void MpcTracker::initialize(const ros::NodeHandle &parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers) {

  uav_name_             = uav_name;
  this->common_handlers = common_handlers;

  ros::NodeHandle nh_(parent_nh, "mpc_tracker");

  ros::Time::waitForValid();

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

  // load the main system matrix
  param_loader.load_matrix_static("dynamicalModel/A", A, n, n);

  // load the input matrix
  param_loader.load_matrix_static("dynamicalModel/B", B, n, m);

  // load the yaw system matrix
  param_loader.load_matrix_static("yawModel/A", A_yaw, n_yaw, n_yaw);

  // load the yaw input matrix
  param_loader.load_matrix_static("yawModel/B", B_yaw, n_yaw, m_yaw);

  // load the MPC parameters
  param_loader.load_param("cvxgenMpc/horizon_len", horizon_len_);
  param_loader.load_param("cvxgenMpc/maxTrajectorySize", _max_trajectory_size_);

  param_loader.load_param("cvxgenMpc/dt", dt);
  param_loader.load_param("cvxgenMpc/dt2", dt2);

  param_loader.load_param("cvxgenMpc/maxHorizontalSpeed", max_horizontal_speed);
  param_loader.load_param("cvxgenMpc/maxHorizontalAcceleration", max_horizontal_acceleration);
  param_loader.load_param("cvxgenMpc/maxHorizontalJerk", max_horizontal_jerk);
  param_loader.load_param("cvxgenMpc/maxHorizontalSnap", max_horizontal_snap);

  param_loader.load_param("cvxgenMpc/maxVerticalAscendingSpeed", max_vertical_ascending_speed);
  param_loader.load_param("cvxgenMpc/maxVerticalAscendingAcceleration", max_vertical_ascending_acceleration);
  param_loader.load_param("cvxgenMpc/maxVerticalAscendingJerk", max_vertical_ascending_jerk);
  param_loader.load_param("cvxgenMpc/maxVerticalAscendingSnap", max_vertical_ascending_snap);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingSpeed", max_vertical_descending_speed);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingAcceleration", max_vertical_descending_acceleration);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingJerk", max_vertical_descending_jerk);
  param_loader.load_param("cvxgenMpc/maxVerticalDescendingSnap", max_vertical_descending_snap);

  param_loader.load_param("cvxgenMpc/maxYawRate", max_yaw_rate);
  param_loader.load_param("cvxgenMpc/maxYawAcceleration", max_yaw_acceleration);
  param_loader.load_param("cvxgenMpc/maxYawJerk", max_yaw_jerk);
  param_loader.load_param("cvxgenMpc/maxYawSnap", max_yaw_snap);

  nh_.param("publish_debug_trajectory", publish_debug_trajectory, false);

  nh_.param("diagnostics_rate", diagnostics_rate, 1.0);
  nh_.param("diagnostic_position_tracking_threshold", diagnostic_position_tracking_threshold, 1.0);
  nh_.param("diagnostic_orientation_tracking_threshold", diagnostic_orientation_tracking_threshold, 0.5);

  ROS_INFO(
      "MPC parameters: horizon_len_: %d, max_vertical_ascending_speed: %2.1f, max_horizontal_speed: %2.1f, max_horizontal_acceleration: "
      "%2.1f, max_vertical_ascending_acceleration: %2.1f, max_vertical_descending_speed: %2.1f, max_vertical_descending_acceleration: %2.1f, ",
      horizon_len_, max_vertical_ascending_speed, max_horizontal_speed, max_horizontal_acceleration, max_vertical_ascending_acceleration,
      max_vertical_descending_speed, max_vertical_descending_acceleration);

  // CVXGEN wrappers
  bool verbose = false;

  param_loader.load_param("cvxWrapper/verbose", verbose);
  param_loader.load_param("cvxWrapper/maxNumOfIterations", max_iters_XY);
  param_loader.load_param("cvxWrapper/Q", tempList);

  cvx_x = new mrs_trackers::cvx_wrapper::CvxWrapper(verbose, max_iters_XY, tempList, dt, dt2, 0);
  cvx_y = new mrs_trackers::cvx_wrapper::CvxWrapper(verbose, max_iters_XY, tempList, dt, dt2, 1);

  param_loader.load_param("cvxWrapperZ/verbose", verbose);
  param_loader.load_param("cvxWrapperZ/maxNumOfIterations", max_iters_Z);
  param_loader.load_param("cvxWrapperZ/Q", tempList);

  cvx_z = new mrs_trackers::cvx_wrapper::CvxWrapper(verbose, max_iters_Z, tempList, dt, dt2, 2);

  param_loader.load_param("cvxWrapperYaw/verbose", verbose);
  param_loader.load_param("cvxWrapperYaw/maxNumOfIterations", max_iters_YAW);
  param_loader.load_param("cvxWrapperYaw/Q", tempList);

  cvx_yaw = new mrs_trackers::cvx_wrapper::CvxWrapper(verbose, max_iters_YAW, tempList, dt, dt2, 0);

  ROS_INFO("[MpcTracker]: MPC Tracker initiated with system parameters: n: %d, m: %d, dt: %0.3f, dt2: %0.3f", n, m, dt, dt2);
  ROS_INFO_STREAM("[MpcTracker]: \nA:\n" << A << "\nB:\n" << B);

  param_loader.load_param("wiggle/enabled", wiggle_enabled_);
  param_loader.load_param("wiggle/amplitude", wiggle_amplitude_);
  param_loader.load_param("wiggle/frequency", wiggle_frequency_);

  // initialize other matrices
  x_               = MatrixXd::Zero(n, 1);
  x_yaw_           = MatrixXd::Zero(4, 1);
  outputTrajectory = MatrixXd::Zero(horizon_len_ * n, 1);

  // trajectory tracking
  coef_time                 = ros::Time(0);
  priority_time             = ros::Time(0);
  des_x_whole_trajectory_   = VectorXd::Zero(_max_trajectory_size_);
  des_y_whole_trajectory_   = VectorXd::Zero(_max_trajectory_size_);
  des_z_whole_trajectory_   = VectorXd::Zero(_max_trajectory_size_);
  des_yaw_whole_trajectory_ = VectorXd::Zero(_max_trajectory_size_);
  trajectory_set_           = false;
  trajectory_count_         = 0;
  use_yaw_in_trajectory_    = false;
  loop_                     = false;

  tracking_trajectory_ = false;
  trajectory_idx_      = 0;
  trajectory_size_     = 0;

  // initialize the trajectory variables
  reference     = MatrixXd::Zero(n * horizon_len_, 1);
  reference_yaw = MatrixXd::Zero(4 * horizon_len_, 1);

  cvxgen_horizontal_vel_constraint = VectorXd::Zero(horizon_len_);
  cvxgen_horizontal_acc_constraint = VectorXd::Zero(horizon_len_);

  des_x_trajectory_     = MatrixXd::Zero(horizon_len_, 1);
  des_y_trajectory_     = MatrixXd::Zero(horizon_len_, 1);
  des_z_trajectory_     = MatrixXd::Zero(horizon_len_, 1);
  des_z_filtered_offset = MatrixXd::Zero(horizon_len_, 1);
  des_yaw_trajectory_   = MatrixXd::Zero(horizon_len_, 1);

  des_x_filtered = MatrixXd::Zero(horizon_len_, 1);
  des_y_filtered = MatrixXd::Zero(horizon_len_, 1);
  des_z_filtered = MatrixXd::Zero(horizon_len_, 1);

  // fill last trajectory with initial data
  future_trajectory_out.stamp    = ros::Time::now();
  future_trajectory_out.uav_name = uav_name_;
  future_trajectory_out.priority = my_uav_priority;
  future_trajectory_out.collision_avoidance =
      collision_avoidance_enabled_ && ((odometry_diagnostics.estimator_type.name.compare(std::string("GPS")) == STRING_EQUAL) ||
                                       odometry_diagnostics.estimator_type.name.compare(std::string("RTK")) == STRING_EQUAL);

  mrs_msgs::FuturePoint newPoint;
  newPoint.x = std::numeric_limits<float>::max();
  newPoint.y = std::numeric_limits<float>::max();
  newPoint.z = std::numeric_limits<float>::lowest();

  mrs_msgs::FuturePointInt8 newPointInt8;
  newPointInt8.x = 0;
  newPointInt8.y = 0;
  newPointInt8.z = 0;

  for (int i = 0; i < horizon_len_; i++) {
    future_trajectory_out.points.push_back(newPoint);
  }

  for (int i = 0; i < horizon_len_; i++) {
    future_trajectory_esp_out.points.push_back(newPointInt8);
  }

  // subscriber for desired trajectory
  sub_trajectory_ = nh_.subscribe("set_trajectory_in", 1, &MpcTracker::callbackDesiredTrajectory, this, ros::TransportHints().tcpNoDelay());

  // subscriber for desired trajectory
  sub_odometry_diagnostics_ = nh_.subscribe("odometry_diagnostics_in", 1, &MpcTracker::callbackOdometryDiagnostics, this, ros::TransportHints().tcpNoDelay());

  // service for desired trajectory
  ser_set_trajectory_ = nh_.advertiseService("set_trajectory_in", &MpcTracker::callbackSetTrajectory, this);

  // service for starting trajectory following
  ser_start_trajectory_following_ = nh_.advertiseService("start_trajectory_following_in", &MpcTracker::callbackStartTrajectoryFollowing, this);

  // service for stopping trajectory following
  ser_stop_trajectory_following_ = nh_.advertiseService("stop_trajectory_following_in", &MpcTracker::callbackStopTrajectoryFollowing, this);

  // service for resuming trajectory following
  ser_resume_trajectory_following_ = nh_.advertiseService("resume_trajectory_following_in", &MpcTracker::callbackResumeTrajectoryFollowing, this);

  // service for flying to the trajectory start point
  ser_fly_to_trajectory_start_ = nh_.advertiseService("fly_to_trajectory_start_in", &MpcTracker::callbackFlyToTrajectoryStart, this);

  // service for triggering failsafe
  set_set_mpc_matrix = nh_.advertiseService("set_mpc_matrix_in", &MpcTracker::callbackSetQ, this);

  // service for enabling wiggle
  service_client_wiggle = nh_.advertiseService("wiggle_in", &MpcTracker::callbackWiggle, this);

  // publishers for debugging
  pub_cmd_acceleration_ = nh_.advertise<geometry_msgs::Vector3>("cmd_acceleration_out", 1);
  pub_diagnostics_      = nh_.advertise<mrs_msgs::MpcTrackerDiagnostics>("diagnostics_out", 1);

  // publisher for the current setpoint
  pub_setpoint_odom = nh_.advertise<nav_msgs::Odometry>("setpoint_odom_out", 1);

  // extract the numerical name
  sscanf(uav_name_.c_str(), "uav%d", &my_uav_number);
  ROS_INFO("[MpcTracker]: Numerical ID of this UAV is %d", my_uav_number);
  my_uav_priority = my_uav_number;

  param_loader.load_param("network/robot_names", other_drone_names_);

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

  param_loader.load_param("mrs_collision_avoidance/enable", collision_avoidance_enabled_);

  // create publisher for predicted trajectory
  predicted_trajectory_publisher       = nh_.advertise<mrs_msgs::FutureTrajectory>("predicted_trajectory", 1);
  predicted_trajectory_esp_publisher   = nh_.advertise<mrs_msgs::FutureTrajectoryInt8>("predicted_trajectory_esp", 1);
  debug_predicted_trajectory_publisher = nh_.advertise<geometry_msgs::PoseArray>("predicted_trajectory_debugging", 1);
  debug_mpc_reference_publisher        = nh_.advertise<geometry_msgs::PoseArray>("mpc_reference_debugging", 1, true);

  pub_debug_original_trajectory_poses_   = nh_.advertise<geometry_msgs::PoseArray>("trajectory_original/poses_out", 1, true);
  pub_debug_original_trajectory_markers_ = nh_.advertise<visualization_msgs::MarkerArray>("trajectory_original/markers_out", 1, true);

  pub_debug_processed_trajectory_poses_   = nh_.advertise<geometry_msgs::PoseArray>("trajectory_processed/poses_out", 1, true);
  pub_debug_processed_trajectory_markers_ = nh_.advertise<visualization_msgs::MarkerArray>("trajectory_processed/markers_out", 1, true);

  // preallocate future trajectory
  predicted_future_trajectory     = MatrixXd::Zero(horizon_len_ * n, 1);
  predicted_future_yaw_trajectory = MatrixXd::Zero(horizon_len_ * n, 1);

  collision_free_altitude = common_handlers->safety_area.getMinHeight();
  avoiding_collision_time = ros::Time::now();
  being_avoided_time      = ros::Time::now();
  future_was_predicted    = false;
  earliest_collision_idx  = INT_MAX;

  param_loader.load_param("predicted_trajectory_topic", predicted_trajectory_topic);
  param_loader.load_param("diagnostics_topic", diagnostics_topic);

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

    std::string prediction_topic_name = std::string("/") + other_drone_names_[i] + std::string("/") + predicted_trajectory_topic;
    std::string diag_topic_name       = std::string("/") + other_drone_names_[i] + std::string("/") + diagnostics_topic;

    ROS_INFO("[MpcTracker]: subscribing to %s", prediction_topic_name.c_str());

    other_uav_prediction_subscribers.push_back(
        nh_.subscribe(prediction_topic_name, 1, &MpcTracker::callbackOtherMavTrajectory, this, ros::TransportHints().tcpNoDelay()));


    ROS_INFO("[MpcTracker]: subscribing to %s", diag_topic_name.c_str());

    other_uav_diag_subscribers.push_back(nh_.subscribe(diag_topic_name, 1, &MpcTracker::callbackOtherMavDiagnostics, this, ros::TransportHints().tcpNoDelay()));
  }

  service_server_headless_mode      = nh_.advertiseService("headless_in", &MpcTracker::callbackHeadlessMode, this);
  service_server_time_agnostic_mode = nh_.advertiseService("time_agnostic_in", &MpcTracker::callbackTimeAgnosticMode, this);
  param_loader.load_param("headless_mode", headless_mode, false);
  param_loader.load_param("time_agnostic_mode", time_agnostic_mode, false);

  // --------------------------------------------------------------
  // |                     dynamic reconfigure                    |
  // --------------------------------------------------------------

  drs_params.wiggle_enabled   = wiggle_enabled_;
  drs_params.wiggle_frequency = wiggle_frequency_;
  drs_params.wiggle_amplitude = wiggle_amplitude_;

  reconfigure_server_.reset(new ReconfigureServer(config_mutex_, nh_));
  reconfigure_server_->updateConfig(drs_params);
  ReconfigureServer::CallbackType f = boost::bind(&MpcTracker::dynamicReconfigureCallback, this, _1, _2);
  reconfigure_server_->setCallback(f);

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler = mrs_lib::Profiler(nh_, "MpcTracker", profiler_enabled_);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  future_trajectory_timer = nh_.createTimer(ros::Rate(predicted_trajectory_publish_rate), &MpcTracker::futureTrajectoryTimer, this);
  diagnostics_timer       = nh_.createTimer(ros::Rate(diagnostics_rate), &MpcTracker::diagnosticsTimer, this);
  mpc_timer               = nh_.createTimer(ros::Rate(1.0 / dt), &MpcTracker::mpcTimer, this);
  hover_timer             = nh_.createTimer(ros::Rate(10), &MpcTracker::hoverTimer, this, false, false);

  // | ----------------------- finish init ---------------------- |

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[MpcTracker]: Could not load all parameters!");
    ros::shutdown();
  }

  is_initialized = true;

  ROS_INFO("[MpcTracker]: MpcTracker initialized");
}

//}

/* //{ activate() */

bool MpcTracker::activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  std::scoped_lock lock(mutex_x, mutex_constraints);

  if (!got_odometry_diagnostics) {

    ROS_ERROR("[MpcTracker]: cannot activate, missing odometry diagnostics");
    return false;
  }

  if (mrs_msgs::PositionCommand::Ptr() != cmd) {

    // set the initial condition from the last tracker's cmd

    x_(0, 0) = cmd->position.x;
    x_(1, 0) = cmd->velocity.x;
    x_(2, 0) = cmd->acceleration.x;
    x_(3, 0) = 0;

    x_(4, 0) = cmd->position.y;
    x_(5, 0) = cmd->velocity.y;
    x_(6, 0) = cmd->acceleration.y;
    x_(7, 0) = 0;

    x_(8, 0)  = cmd->position.z;
    x_(9, 0)  = cmd->velocity.z;
    x_(10, 0) = cmd->acceleration.z;
    x_(11, 0) = 0;

    x_yaw_(0, 0) = cmd->yaw;
    x_yaw_(1, 0) = cmd->yaw_dot;
    x_yaw_(2, 0) = 0;
    x_yaw_(3, 0) = 0;

    yaw = cur_yaw_;

    ROS_INFO("[MpcTracker]: activated with last tracker's command");

  } else {

    // set the initial condition from the odometry

    x_(0, 0) = uav_state_.pose.position.x;
    x_(1, 0) = uav_state_.velocity.linear.x;
    x_(2, 0) = 0;
    x_(3, 0) = 0;

    x_(4, 0) = uav_state_.pose.position.y;
    x_(5, 0) = uav_state_.velocity.linear.y;
    x_(6, 0) = 0;
    x_(7, 0) = 0;

    x_(8, 0)  = uav_state_.pose.position.z;
    x_(9, 0)  = uav_state_.velocity.linear.z;
    x_(10, 0) = 0;
    x_(11, 0) = 0;

    x_yaw_(0, 0) = cur_yaw_;
    x_yaw_(1, 0) = uav_state_.velocity.angular.z;
    x_yaw_(2, 0) = 0;
    x_yaw_(3, 0) = 0;

    yaw = cur_yaw_;

    ROS_INFO("[MpcTracker]: activated with uav state");
  }

  tracking_trajectory_ = false;

  mpc_start_time  = ros::Time::now();
  mpc_total_delay = 0;

  ROS_INFO("[MpcTracker]: activated");

  // this is here to initialize the desired_trajectory vector
  // if deleted (and I tried) the UAV will briefly fly to the
  // origin after activation
  setRelativeGoal(0, 0, 0, 0, false);  // do not delete

  toggleHover(true);

  is_active = true;

  // can return false
  return is_active;
}

//}

/* //{ deactivate() */

void MpcTracker::deactivate(void) {

  toggleHover(false);

  std::scoped_lock lock(mutex_des_trajectory);

  is_active = false;
  odom_set_ = false;

  // turn off trajectory tracking

  tracking_trajectory_ = false;
  trajectory_idx_      = 0;

  ROS_INFO("[MpcTracker]: deactivated");

  publishDiagnostics();
}

//}

/* //{ resetStatic() */

bool MpcTracker::resetStatic(void) {

  if (!is_initialized) {
    ROS_ERROR("[MpcTracker]: cannot reset, not initialized");
    return false;
  }

  if (!is_active) {
    ROS_ERROR("[MpcTracker]: cannot reset, not active");
    return false;
  }

  {
    std::scoped_lock lock(mutex_x);

    // set the initial condition from the odometry

    ROS_INFO("[MpcTracker]: reseting with uav state with no dynamics");

    x_(0, 0) = uav_state_.pose.position.x;
    x_(1, 0) = 0;
    x_(2, 0) = 0;
    x_(3, 0) = 0;

    x_(4, 0) = uav_state_.pose.position.y;
    x_(5, 0) = 0;
    x_(6, 0) = 0;
    x_(7, 0) = 0;

    x_(8, 0)  = uav_state_.pose.position.z;
    x_(9, 0)  = 0;
    x_(10, 0) = 0;
    x_(11, 0) = 0;

    x_yaw_(0, 0) = cur_yaw_;
    x_yaw_(1, 0) = 0;
    x_yaw_(2, 0) = 0;
    x_yaw_(3, 0) = 0;

    yaw = cur_yaw_;

    tracking_trajectory_ = false;

    mpc_start_time  = ros::Time::now();
    mpc_total_delay = 0;

    ROS_INFO("[MpcTracker]: reseted");
  }

  // this is here to initialize the desired_trajectory vector
  // if deleted (and I tried) the UAV will briefly fly to the
  // origin after activation
  setRelativeGoal(0, 0, 0, 0, false);  // do not delete

  return true;
}

//}

/* //{ update() */

const mrs_msgs::PositionCommand::ConstPtr MpcTracker::update(const mrs_msgs::UavState::ConstPtr &                        msg,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr &cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  // copy the odometry from the message
  {
    std::scoped_lock lock(mutex_uav_state_);

    uav_state_ = *msg;
  }

  cur_yaw_ = tf::getYaw(msg->pose.orientation);

  odom_set_ = true;

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  if (!mpc_computed_ && mpc_result_invalid) {

    // if the tracker is not computed yet

    // set the header
    position_cmd_.header.stamp    = msg->header.stamp;
    position_cmd_.header.frame_id = msg->header.frame_id;

    // set positions from odom
    position_cmd_.position.x = msg->pose.position.x;
    position_cmd_.position.y = msg->pose.position.y;
    position_cmd_.position.z = msg->pose.position.z;

    // set velocities from odom
    position_cmd_.velocity.x = msg->velocity.linear.x;
    position_cmd_.velocity.y = msg->velocity.linear.y;
    position_cmd_.velocity.z = msg->velocity.linear.z;

    // set zero accelerations
    position_cmd_.acceleration.x = 0;
    position_cmd_.acceleration.y = 0;
    position_cmd_.acceleration.z = 0;

    // set zero jerk
    position_cmd_.jerk.x = 0;
    position_cmd_.jerk.y = 0;
    position_cmd_.jerk.z = 0;


    // set yaw based on current odom
    position_cmd_.yaw       = cur_yaw_;
    position_cmd_.yaw_dot   = msg->velocity.angular.z;
    position_cmd_.yaw_ddot  = 0;
    position_cmd_.yaw_dddot = 0;

    ROS_WARN("[MpcTracker]: MPC not ready, reaturning current odom as the command.");

    return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
  }

  // chech wheather all outputs are finite
  bool arefinite = true;
  for (int i = 0; i < 12; i++) {
    if (!std::isfinite(x_(i, 0))) {
      arefinite = false;
    }
  }

  if (arefinite) {

    {
      std::scoped_lock lock(mutex_x);

      // set the desired states base on the result of the mpc
      position_cmd_.position.x     = x_(0, 0);
      position_cmd_.velocity.x     = x_(1, 0);
      position_cmd_.acceleration.x = x_(2, 0);
      position_cmd_.jerk.x         = x_(3, 0);

      position_cmd_.position.y     = x_(4, 0);
      position_cmd_.velocity.y     = x_(5, 0);
      position_cmd_.acceleration.y = x_(6, 0);
      position_cmd_.jerk.y         = x_(7, 0);

      position_cmd_.position.z     = x_(8, 0);
      position_cmd_.velocity.z     = x_(9, 0);
      position_cmd_.acceleration.z = x_(10, 0);
      position_cmd_.jerk.z         = x_(11, 0);

      position_cmd_.use_position_vertical   = 1;
      position_cmd_.use_position_horizontal = 1;
      position_cmd_.use_velocity_vertical   = 1;
      position_cmd_.use_velocity_horizontal = 1;
      position_cmd_.use_acceleration        = 1;
      position_cmd_.use_jerk                = 1;
      position_cmd_.use_yaw                 = 1;
      position_cmd_.use_yaw_dot             = 1;
    }

  } else {

    ROS_ERROR("[MpcTracker]: MPC outputs are not finite!");

    position_cmd_.velocity.x     = 0;
    position_cmd_.acceleration.x = 0;
    position_cmd_.jerk.x         = 0;

    position_cmd_.velocity.y     = 0;
    position_cmd_.acceleration.y = 0;
    position_cmd_.jerk.y         = 0;

    position_cmd_.velocity.z     = 0;
    position_cmd_.acceleration.z = 0;
    position_cmd_.jerk.z         = 0;
  }

  {
    std::scoped_lock lock(des_yaw_mutex);
    desired_yaw = mrs_trackers_commons::validateYawSetpoint(desired_yaw);
  }

  // compute the desired yaw rate
  {
    std::scoped_lock lock(des_yaw_mutex);

    if (fabs(desired_yaw - yaw) > PI) {
      yaw_rate = -yaw_gain * (desired_yaw - yaw);
    } else {
      yaw_rate = yaw_gain * (desired_yaw - yaw);
    }
  }

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

  bool yaw_finite = true;
  for (int i = 0; i < 4; i++) {
    if (!std::isfinite(x_yaw_(i, 0))) {
      yaw_finite = false;
    }
  }
  if (yaw_finite) {

    // set the yaw output - cvxgen MPC controller
    position_cmd_.yaw       = x_yaw_(0, 0);
    position_cmd_.yaw_dot   = x_yaw_(1, 0);
    position_cmd_.yaw_ddot  = x_yaw_(2, 0);
    position_cmd_.yaw_dddot = x_yaw_(3, 0);

  } else {

    ROS_INFO("[MpcTracker]: Output YAW is not finite!");

    position_cmd_.yaw_dot   = 0;
    position_cmd_.yaw_ddot  = 0;
    position_cmd_.yaw_dddot = 0;
  }

  // set the header
  position_cmd_.header.stamp    = msg->header.stamp;
  position_cmd_.header.frame_id = msg->header.frame_id;

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
    pub_cmd_acceleration_.publish(outAcceleration);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_cmd_acceleration_.getTopic().c_str());
  }

  // publish position setpoint for debugging purposes
  nav_msgs::Odometry setpoint_odom_out;

  setpoint_odom_out.header.stamp    = ros::Time::now();
  setpoint_odom_out.header.frame_id = uav_state_.header.frame_id;

  tf::Quaternion orientation;
  orientation.setEuler(0, 0, yaw);

  {
    std::scoped_lock lock(mutex_des_trajectory);

    setpoint_odom_out.pose.pose.position.x = des_x_trajectory_(0, 0);
    setpoint_odom_out.pose.pose.position.y = des_y_trajectory_(0, 0);
    setpoint_odom_out.pose.pose.position.z = des_z_trajectory_(0, 0);

    orientation.setEuler(0, 0, desired_yaw);
    setpoint_odom_out.pose.pose.orientation.x = orientation.x();
    setpoint_odom_out.pose.pose.orientation.y = orientation.y();
    setpoint_odom_out.pose.pose.orientation.z = orientation.z();
    setpoint_odom_out.pose.pose.orientation.w = orientation.w();
  }

  try {
    pub_setpoint_odom.publish(setpoint_odom_out);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_setpoint_odom.getTopic().c_str());
  }

  // u have to return a position command
  // can set the jerk to 0
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus MpcTracker::getStatus() {

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active;
  tracker_status.callbacks_enabled = is_active && callbacks_enabled && !hovering_in_progress;

  return tracker_status;
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

void MpcTracker::switchOdometrySource(const mrs_msgs::UavState::ConstPtr &msg) {

  resetting_odometry = true;
  mpc_result_invalid = true;

  ROS_INFO("[MpcTracker]: start of odmetry reset x %f y %f", msg->pose.position.x, msg->pose.position.y);

  mpc_timer.stop();
  ROS_INFO("[MpcTracker]: stopped mpc timer");

  while (running_mpc_timer) {

    ROS_DEBUG("[MpcTracker]: the MPC is in the middle of an iteration, waiting for it to finish");
    ros::Duration wait(0.01);
    wait.sleep();
  }

  // | --------- recalculate the goal to new coordinates -------- |
  double dx, dy, dz, dyaw;
  double dvz, dvyaw;
  double old_roll, old_pitch, old_yaw;
  double new_roll, new_pitch, new_yaw;

  {
    std::scoped_lock lock(mutex_uav_state_);

    // calculate the euler angles from the old uav state
    tf::Quaternion uav_state_attitude;
    quaternionMsgToTF(uav_state_.pose.orientation, uav_state_attitude);
    tf::Matrix3x3 m(uav_state_attitude);
    m.getRPY(old_roll, old_pitch, old_yaw);

    // calculate the euler angles from the new uav state
    tf::Quaternion new_attitude;
    quaternionMsgToTF(msg->pose.orientation, new_attitude);
    tf::Matrix3x3 m2(new_attitude);
    m2.getRPY(new_roll, new_pitch, new_yaw);

    // calculate the difference of position
    dx   = msg->pose.position.x - uav_state_.pose.position.x;
    dy   = msg->pose.position.y - uav_state_.pose.position.y;
    dz   = msg->pose.position.z - uav_state_.pose.position.z;
    dyaw = new_yaw - old_yaw;

    // calculate the difference in yaw
    dvyaw = msg->velocity.angular.z - uav_state_.velocity.angular.z;

    ROS_INFO("[MpcTracker]: dx %f dy %f dz %f dyaw %f", dx, dy, dz, dyaw);
  }

  {
    std::scoped_lock lock(mutex_x, mutex_des_trajectory, mutex_des_whole_trajectory, mutex_uav_state_);

    for (int i = 0; i < trajectory_size_ + horizon_len_; i++) {

      Eigen::Vector2d temp_vec(des_x_whole_trajectory_(i) - uav_state_.pose.position.x, des_y_whole_trajectory_(i) - uav_state_.pose.position.y);
      temp_vec = rotateVector(temp_vec, dyaw);

      des_x_whole_trajectory_(i) = msg->pose.position.x + temp_vec[0];
      des_y_whole_trajectory_(i) = msg->pose.position.y + temp_vec[1];
      des_z_whole_trajectory_(i) += dz;
      des_yaw_whole_trajectory_(i) += dyaw;
    }

    for (int i = 0; i < horizon_len_; i++) {

      Eigen::Vector2d temp_vec(des_x_trajectory_(i) - uav_state_.pose.position.x, des_y_trajectory_(i) - uav_state_.pose.position.y);
      temp_vec = rotateVector(temp_vec, dyaw);

      des_x_trajectory_(i, 0) = msg->pose.position.x + temp_vec[0];
      des_y_trajectory_(i, 0) = msg->pose.position.y + temp_vec[1];
      des_z_trajectory_(i, 0) += dz;
      des_yaw_trajectory_(i, 0) += dyaw;
    }

    dvz = msg->velocity.linear.z - uav_state_.velocity.linear.z;

    /* ROS_INFO("[MpcTracker]: dvx %f dvy %f dvz %f dvaw %f", dvx, dvy, dvz, dvyaw); */

    double velocity_scale = sqrt(pow(msg->velocity.linear.x, 2) + pow(msg->velocity.linear.y, 2)) /
                            sqrt(pow(uav_state_.velocity.linear.x, 2) + pow(uav_state_.velocity.linear.y, 2));

    double acceleration_scale = sqrt(pow(msg->acceleration.linear.x, 2) + pow(msg->acceleration.linear.y, 2)) /
                                sqrt(pow(uav_state_.acceleration.linear.x, 2) + pow(uav_state_.acceleration.linear.y, 2));

    // update the positon
    {
      Eigen::Vector2d temp_vec(x_(0, 0) - uav_state_.pose.position.x, x_(4, 0) - uav_state_.pose.position.y);
      temp_vec = rotateVector(temp_vec, dyaw);
      x_(0, 0) = msg->pose.position.x + temp_vec[0];
      x_(4, 0) = msg->pose.position.y + temp_vec[1];
      x_(8, 0) += dz;
    }

    // update the velocity
    {
      Eigen::Vector2d temp_vec(x_(1, 0), x_(5, 0));
      temp_vec = rotateVector(temp_vec, dyaw) * velocity_scale;
      x_(1, 0) = temp_vec[0];
      x_(5, 0) = temp_vec[1];
    }

    // update the acceleration
    {
      Eigen::Vector2d temp_vec(x_(2, 0), x_(6, 0));
      temp_vec = rotateVector(temp_vec, dyaw) * acceleration_scale;
      x_(2, 0) = temp_vec[0];
      x_(6, 0) = temp_vec[1];
    }

    // update the height
    x_(9, 0) += dvz;

    // update the heading and its derivative
    x_yaw_(0, 0) += dyaw;
    x_yaw_(1, 0) += dvyaw;
  }

  ROS_INFO("[MpcTracker]: end of odometry reset in mpc x %f y %f xvel %f yvel %f hor1x %f hor1y %f", x_(0, 0), x_(4, 0), x_(1, 0), x_(5, 0),
           des_x_trajectory_(0, 0), des_y_trajectory_(0, 0));

  mpc_timer.start();
  ROS_INFO("[MpcTracker]: started mpc timer");

  resetting_odometry = false;
}

//}

/* //{ hover() service */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr &cmd) {

  std::scoped_lock lock(mutex_x);

  std_srvs::TriggerResponse res;

  toggleHover(true);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Hovering");
  res.message = tempStr;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ setConstraints() service */

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr MpcTracker::setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr &cmd) {

  desired_constraints = *cmd;
  mrs_msgs::TrackerConstraintsSrvResponse res;
  all_constraints_set = false;

  {
    std::scoped_lock lock(mutex_constraints);
    // only speeds are set here, the rest is handled in manageConstraints()
    max_horizontal_speed          = cmd->constraints.horizontal_speed;
    max_vertical_ascending_speed  = cmd->constraints.vertical_ascending_speed;
    max_vertical_descending_speed = cmd->constraints.vertical_descending_speed;
    max_yaw_rate                  = cmd->constraints.yaw_speed;
  }

  ROS_INFO("[MpcTracker]: updating constraints");

  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr(new mrs_msgs::TrackerConstraintsSrvResponse(res));
}

//}

// | -------------- setpoint topics and services -------------- |

/* //{ goTo() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr MpcTracker::goTo(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  mrs_msgs::ReferenceSrvResponse res;

  toggleHover(false);

  setGoal(cmd->reference.position.x, cmd->reference.position.y, cmd->reference.position.z, cmd->reference.yaw, true);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->reference.position.x, cmd->reference.position.y,
          cmd->reference.position.z, cmd->reference.yaw);
  res.message = tempStr;

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ goTo() topic */

bool MpcTracker::goTo(const mrs_msgs::ReferenceConstPtr &msg) {

  toggleHover(false);

  setGoal(msg->position.x, msg->position.y, msg->position.z, msg->yaw, true);

  return true;
}

//}

/* //{ goToRelative() service */

const mrs_msgs::ReferenceSrvResponse::ConstPtr MpcTracker::goToRelative(const mrs_msgs::ReferenceSrvRequest::ConstPtr &cmd) {

  std::scoped_lock lock(mutex_x);

  mrs_msgs::ReferenceSrvResponse res;

  toggleHover(false);

  setRelativeGoal(cmd->reference.position.x, cmd->reference.position.y, cmd->reference.position.z, cmd->reference.yaw, true);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to relative x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->reference.position.x, cmd->reference.position.y,
          cmd->reference.position.z, cmd->reference.yaw);
  res.message = tempStr;

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ goToAltitude() service */

const mrs_msgs::Float64SrvResponse::ConstPtr MpcTracker::goToAltitude(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  toggleHover(false);

  setGoal(x_(0, 0), x_(4, 0), cmd->value, x_yaw_(0, 0), false);

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to altitude %3.2f", cmd->value);
  res.message = tempStr;

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

/* //{ setYaw() service */

const mrs_msgs::Float64SrvResponse::ConstPtr MpcTracker::setYaw(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  toggleHover(false);

  if (tracking_trajectory_) {

    // TODO implement
    ROS_ERROR("[MpcTracker]: TODO, implement");

  } else {

    // TODO: should set goal when flying to a setpoint
    setGoal(x_(0, 0), x_(4, 0), x_(8, 0), mrs_trackers_commons::validateYawSetpoint(cmd->value), true);
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->value);
  res.message = tempStr;

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

/* //{ setYawRelative() service */

const mrs_msgs::Float64SrvResponse::ConstPtr MpcTracker::setYawRelative(const mrs_msgs::Float64SrvRequest::ConstPtr &cmd) {

  mrs_msgs::Float64SrvResponse res;

  toggleHover(false);

  if (tracking_trajectory_) {

    {
      std::scoped_lock lock(mutex_des_trajectory);

      for (int i = 0; i < horizon_len_; i++) {
        des_yaw_trajectory_(i, 0) += mrs_trackers_commons::validateYawSetpoint(cmd->value);
      }
    }

  } else {

    setGoal(des_x_trajectory_(0, 0), des_y_trajectory_(0, 0), des_z_trajectory_(0, 0),
            mrs_trackers_commons::validateYawSetpoint(des_yaw_trajectory_(0, 0) + cmd->value), true);
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->value);
  res.message = tempStr;

  return mrs_msgs::Float64SrvResponse::ConstPtr(new mrs_msgs::Float64SrvResponse(res));
}

//}

// --------------------------------------------------------------
// |                  tracker's custom routines                 |
// --------------------------------------------------------------

// | ------------------------ callbacks ----------------------- |

/* //{ callbackOtherMavTrajectory() */

void MpcTracker::callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("callbackOtherMavTrajectory");

  std::scoped_lock lock(mutex_other_drone_trajecotries);

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // the times might not be synchronized, so just remember the time of receiving it
  temp_trajectory.stamp = ros::Time::now();

  // update the diagnostics
  other_drones_trajectories[msg->uav_name] = temp_trajectory;
}

//}

/* //{ callbackOtherMavDiagnostics() */

void MpcTracker::callbackOtherMavDiagnostics(const mrs_msgs::MpcTrackerDiagnosticsConstPtr &msg) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("callbackOtherMavDiagnostics");

  std::scoped_lock lock(mutex_other_drone_diagnostics);

  mrs_msgs::MpcTrackerDiagnostics temp_diagnostics = *msg;

  // the times might not be synchronized, so just remember the time of receiving it
  temp_diagnostics.header.stamp = ros::Time::now();

  // update the diagnostics
  other_drones_diagnostics[msg->uav_name] = temp_diagnostics;
}

//}

/* //{ callbackToggleCollisionAvoidance() */

bool MpcTracker::callbackToggleCollisionAvoidance(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  collision_avoidance_enabled_ = req.data;

  if (!collision_avoidance_enabled_) {

    collision_free_altitude = common_handlers->safety_area.getMinHeight();
  }

  ROS_INFO("[MpcTracker]: Collision avoidance was switched %s", collision_avoidance_enabled_ ? "TRUE" : "FALSE");

  res.message = "Collision avoidance set.";
  res.success = true;

  return true;
}

//}

/* //{ callbackStartTrajectoryFollowing() */

bool MpcTracker::callbackStartTrajectoryFollowing([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Tracker not active");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Callbacks are disabled");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (hovering_in_progress) {

    sprintf((char *)&message, "Hovering in progress");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (trajectory_set_) {

    {
      std::scoped_lock lock(mutex_des_trajectory);

      toggleHover(false);
      tracking_trajectory_ = true;
      trajectory_idx_      = 0;
    }

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

bool MpcTracker::callbackStopTrajectoryFollowing([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Tracker not active");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Callbacks are disabled");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (hovering_in_progress) {

    sprintf((char *)&message, "Hovering in progress");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (tracking_trajectory_) {

    tracking_trajectory_ = false;

    {
      std::scoped_lock lock(mutex_x);

      setTrajectory(x_(0, 0), x_(4, 0), x_(8, 0), x_yaw_(0, 0));
    }

    ROS_INFO("[MpcTracker]: Stopping trajectory following, staying at x: %2.2f, y: %2.2f, z: %2.2f.", x_(0, 0), x_(4, 0), x_(8, 0));

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Staying at x: %3.2f, y: %2.2f, z: %2.2f", x_(0, 0), x_(4, 0), x_(8, 0));

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

bool MpcTracker::callbackFlyToTrajectoryStart([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Tracker not active");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Callbacks are disabled");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (hovering_in_progress) {

    sprintf((char *)&message, "Hovering in progress");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (trajectory_set_) {

    toggleHover(false);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory);

      setGoal(des_x_whole_trajectory_[0], des_y_whole_trajectory_[0], des_z_whole_trajectory_[0], des_yaw_whole_trajectory_[0], use_yaw_in_trajectory_);
    }

    {
      std::scoped_lock lock(mutex_des_trajectory);

      tracking_trajectory_ = false;
    }

    char tempStr[100];
    if (use_yaw_in_trajectory_) {

      ROS_INFO("[MpcTracker]: Flying to trajectory start point x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory_[0],
               des_y_whole_trajectory_[0], des_z_whole_trajectory_[0], des_yaw_whole_trajectory_[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory_[0], des_y_whole_trajectory_[0],
              des_z_whole_trajectory_[0], des_yaw_whole_trajectory_[0]);
    } else {
      ROS_INFO("[MpcTracker]: Flying to trajectory start point x: %2.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory_[0], des_y_whole_trajectory_[0],
               des_z_whole_trajectory_[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory_[0], des_y_whole_trajectory_[0], des_z_whole_trajectory_[0]);
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

bool MpcTracker::callbackResumeTrajectoryFollowing([[maybe_unused]] std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  char message[200];

  if (!is_active) {

    sprintf((char *)&message, "Tracker not active");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Callbacks are disabled");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (hovering_in_progress) {

    sprintf((char *)&message, "Hovering in progress");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (trajectory_set_) {

    toggleHover(false);

    if (trajectory_idx_ < (trajectory_size_ - 1)) {

      {
        std::scoped_lock lock(mutex_des_trajectory);

        tracking_trajectory_ = true;
      }

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

/* //{ callbackSetQ() service */

bool MpcTracker::callbackSetQ(mrs_msgs::MpcMatrixRequest &req, mrs_msgs::MpcMatrixResponse &res) {

  std::vector<double> Qvec(4);
  bool                response = true;

  for (int i = 0; i < 4; i++) {
    if (req.Q[i] >= 0.0) {
      Qvec[i] = req.Q[i];
    } else {
      response = false;
      res.message += "Q has to be PSD! ";
    }
  }

  if (req.axis != "xy" && req.axis != "z" && req.axis != "yaw" && req.axis != "all") {
    response = false;
    res.message += "Enter axis description! [xy, z, yaw, all] ";
  }

  if (response) {
    if (req.axis == "xy" || req.axis == "all") {
      response &= cvx_x->setQ(Qvec);
      response &= cvx_y->setQ(Qvec);
    }
    if (req.axis == "z" || req.axis == "all") {
      response &= cvx_z->setQ(Qvec);
    }
    if (req.axis == "yaw" || req.axis == "all") {
      response &= cvx_yaw->setQ(Qvec);
    }

    char tempStr[100];
    sprintf((char *)&tempStr, "Setting matrix for %s axis, Q: %5.1f, %5.1f, %5.1f, %5.1f", req.axis.c_str(), req.Q[0], req.Q[1], req.Q[2], req.Q[3]);
    res.message = tempStr;
  } else {
    res.message += " Error setting matrices";
  }
  res.success = response;
  return true;
}

//}

/* //{ callbackSetTrajectory() */

// service for setting desired trajectory
bool MpcTracker::callbackSetTrajectory(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res) {

  char message[200];

  if (!is_initialized) {

    sprintf((char *)&message, "Tracker not initialized");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (!callbacks_enabled) {

    sprintf((char *)&message, "Callbacks are disabled");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  if (hovering_in_progress) {

    sprintf((char *)&message, "Hovering in progress");
    ROS_ERROR("[MpcTracker]: %s", message);
    res.success = false;
    res.message = message;
    return true;
  }

  bool modified;
  res.success  = loadTrajectory(req.trajectory_msg, res.message, modified);
  res.modified = modified;
  return true;
}

//}

/* //{ callbackOdometryDiagnostics() */

void MpcTracker::callbackOdometryDiagnostics(const mrs_msgs::OdometryDiagConstPtr &msg) {

  if (!is_initialized) {
    return;
  }

  ROS_INFO_ONCE("[MpcTracker]: getting odometry diagnostics");

  std::scoped_lock lock(mutex_odometry_diagnostics);

  odometry_diagnostics = *msg;

  got_odometry_diagnostics = true;
}

//}

/* //{ callbackDesiredTrajectory() */

// callback for loading desired trajectory
void MpcTracker::callbackDesiredTrajectory(const mrs_msgs::TrackerTrajectory::ConstPtr &msg) {

  if (!is_initialized) {
    ROS_WARN_THROTTLE(1.0, "[MpcTracker]: Can't set trajectory, the tracker is not initialized");
    return;
  }

  if (!callbacks_enabled) {

    ROS_WARN_THROTTLE(1.0, "[MpcTracker]: Can't set trajectory, callbacks are disabled!");
    return;
  }

  if (hovering_in_progress) {

    ROS_WARN_THROTTLE(1.0, "[MpcTracker]: Can't set trajectory, callbacks are disabled!");
    return;
  }

  std::string message;
  bool        modified;
  loadTrajectory(*msg, message, modified);
}

//}

/* callbackHeadlessMode() //{ */

bool MpcTracker::callbackHeadlessMode(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  headless_mode = req.data;
  char buffer[100];

  sprintf(buffer, "Headless mode %s", headless_mode ? "ON" : "OFF");
  res.message = buffer;
  ROS_INFO("[MpcTracker]: %s", buffer);

  res.success = true;

  return true;
}

//}

/* callbackTimeAgnosticMode() //{ */

bool MpcTracker::callbackTimeAgnosticMode(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  time_agnostic_mode = req.data;
  char buffer[100];

  sprintf(buffer, "Time Agnostic mode %s", time_agnostic_mode ? "ON" : "OFF");
  res.message = buffer;
  ROS_INFO("[MpcTracker]: %s", buffer);

  res.success = true;

  return true;
}

//}

/* callbackWiggle() //{ */

bool MpcTracker::callbackWiggle(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  std::scoped_lock lock(mutex_wiggle);

  if (!is_initialized) {

    res.success = false;
    res.message = "Tracker not active";
    return true;
  }

  wiggle_enabled_ = req.data;
  res.success     = true;
  res.message     = "Wiggle set";

  return true;
}

//}

/* //{ dynamicReconfigureCallback() */

void MpcTracker::dynamicReconfigureCallback(mrs_trackers::mpc_trackerConfig &config, [[maybe_unused]] uint32_t level) {

  std::scoped_lock lock(mutex_wiggle);

  drs_params = config;

  wiggle_enabled_   = config.wiggle_enabled;
  wiggle_amplitude_ = config.wiggle_amplitude;
  wiggle_frequency_ = config.wiggle_frequency;

  ROS_INFO("[So3Controller]: DRS updated gains");
}

//}

// | -------------------- setpoint handling ------------------- |

/* //{ dist() */

double dist(const double ax, const double ay, const double bx, const double by) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

//}

/* //{ dist3d() */

double dist3d(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2) + pow(az - bz, 2));
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

/* //{ checkCollision() */

void MpcTracker::manageConstraints() {

  if (all_constraints_set) {
    return;
  }

  bool can_change =
      (fabs(x_(1, 0)) < desired_constraints.constraints.horizontal_speed) && (fabs(x_(2, 0)) < desired_constraints.constraints.horizontal_acceleration) &&
      (fabs(x_(3, 0)) < desired_constraints.constraints.horizontal_jerk) && (fabs(x_(5, 0)) < desired_constraints.constraints.horizontal_speed) &&
      (fabs(x_(6, 0)) < desired_constraints.constraints.horizontal_acceleration) && (fabs(x_(7, 0)) < desired_constraints.constraints.horizontal_jerk) &&
      (x_(9, 0) < desired_constraints.constraints.vertical_ascending_speed) && (x_(9, 0) > -desired_constraints.constraints.vertical_descending_speed) &&
      (x_(10, 0) < desired_constraints.constraints.vertical_ascending_acceleration) &&
      (x_(10, 0) > -desired_constraints.constraints.vertical_descending_acceleration) &&
      (x_(11, 0) < desired_constraints.constraints.vertical_ascending_jerk) && (x_(11, 0) > -desired_constraints.constraints.vertical_descending_jerk) &&
      (fabs(x_yaw_(1, 0)) < desired_constraints.constraints.yaw_speed) && (fabs(x_yaw_(2, 0)) < desired_constraints.constraints.yaw_acceleration) &&
      (fabs(x_yaw_(3, 0)) < desired_constraints.constraints.yaw_jerk);

  if (can_change) {
    {
      std::scoped_lock lock(mutex_constraints);

      max_horizontal_acceleration = desired_constraints.constraints.horizontal_acceleration;
      max_horizontal_jerk         = desired_constraints.constraints.horizontal_jerk;
      max_horizontal_snap         = desired_constraints.constraints.horizontal_snap;

      max_vertical_ascending_acceleration = desired_constraints.constraints.vertical_ascending_acceleration;
      max_vertical_ascending_jerk         = desired_constraints.constraints.vertical_ascending_jerk;
      max_vertical_ascending_snap         = desired_constraints.constraints.vertical_ascending_snap;

      max_vertical_descending_acceleration = desired_constraints.constraints.vertical_descending_acceleration;
      max_vertical_descending_jerk         = desired_constraints.constraints.vertical_descending_jerk;
      max_vertical_descending_snap         = desired_constraints.constraints.vertical_descending_snap;

      max_yaw_acceleration = desired_constraints.constraints.yaw_acceleration;
      max_yaw_jerk         = desired_constraints.constraints.yaw_jerk;
      max_yaw_snap         = desired_constraints.constraints.yaw_snap;
    }
    ROS_WARN("[MpcTracker]: all constraints succesfully applied");
    all_constraints_set = true;
  } else {
    ROS_WARN_STREAM_THROTTLE(0.2, "[MpcTracker]: Slowing down to apply new constraints ");
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

  std::scoped_lock lock(mutex_predicted_trajectory, mutex_des_trajectory, mutex_other_drone_trajecotries);

  first_collision_index = INT_MAX;
  avoiding_collision    = false;

  // This variable is used for collision avoidance priority swapping, only the first detected collision is considered for priority swap, subsequent collisons
  // are irrelevant
  bool first_collision = true;

  std::map<std::string, mrs_msgs::FutureTrajectory>::iterator u = other_drones_trajectories.begin();

  while (u != other_drones_trajectories.end()) {

    first_collision = true;

    // is the other's trajectory fresh enought?
    if ((ros::Time::now() - u->second.stamp).toSec() < collision_trajectory_timeout) {

      for (int v = 0; v < horizon_len_; v++) {

        // check all points of the trajectory for possible collisions
        if (checkCollision(predicted_future_trajectory(v * n, 0), predicted_future_trajectory(v * n + 4, 0), predicted_future_trajectory(v * n + 8, 0),
                           u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {

          // collision is detected
          int other_uav_priority = INT_MAX;
          // get the priority of the other uav
          /* sscanf(u->first.c_str(), "uav%d", &other_uav_priority); */
          other_uav_priority = u->second.priority;
          // check if we should be avoiding (out priority is higher, or the other uav has collision avoidance turned off)
          if ((u->second.collision_avoidance == false) || (other_uav_priority < my_uav_priority)) {
            // we should be avoiding
            avoiding_collision       = true;
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
        if (checkCollisionInflated(predicted_future_trajectory(v * n, 0), predicted_future_trajectory(v * n + 4, 0), predicted_future_trajectory(v * n + 8, 0),
                                   u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {
          // collision is detected
          if (first_collision_index > v) {
            first_collision_index = v;
          }
        }
      }
    }
    u++;
  }

  if (!avoiding_collision) {

    // we are not avoiding any collisions, so we slowly reduce the collision avoidance offset to return to normal flight
    collision_free_altitude -= 0.02;

    if (collision_free_altitude < common_handlers->safety_area.getMinHeight()) {

      collision_free_altitude = common_handlers->safety_area.getMinHeight();
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

  for (int i = 0; i < horizon_len_; i++) {

    if (i == 0) {
      max_sample_x = max_speed_x * dt;
      max_sample_y = max_speed_y * dt;
      difference_x = des_x_trajectory_(i, 0) - x_(0, 0);
      difference_y = des_y_trajectory_(i, 0) - x_(4, 0);
    } else {
      max_sample_x = max_speed_x * dt2;
      max_sample_y = max_speed_y * dt2;
      difference_x = des_x_trajectory_(i, 0) - des_x_filtered(i - 1, 0);
      difference_y = des_y_trajectory_(i, 0) - des_y_filtered(i - 1, 0);
    }

    double direction_angle  = atan2(difference_y, difference_x);
    double max_dir_sample_x = abs(max_sample_x * cos(direction_angle));
    double max_dir_sample_y = abs(max_sample_y * sin(direction_angle));
    if (max_sample_x > max_dir_sample_x) {
      max_sample_x = max_dir_sample_x;
    }
    if (max_sample_y > max_dir_sample_y) {
      max_sample_y = max_dir_sample_y;
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
      des_x_filtered(i, 0) = x_(0, 0) + difference_x;
      des_y_filtered(i, 0) = x_(4, 0) + difference_y;
    } else {
      des_x_filtered(i, 0) = des_x_filtered(i - 1, 0) + difference_x;
      des_y_filtered(i, 0) = des_y_filtered(i - 1, 0) + difference_y;
    }
  }

  // | ----------------------- add wiggle ----------------------- |
  if (wiggle_enabled_) {

    for (int i = 0; i < horizon_len_; i++) {
      des_x_filtered(i, 0) += wiggle_amplitude_ * cos(wiggle_frequency_ * 2 * M_PI * i * 0.2 + wiggle_phase);
      des_y_filtered(i, 0) += wiggle_amplitude_ * sin(wiggle_frequency_ * 2 * M_PI * i * 0.2 + wiggle_phase);
    }

    wiggle_phase += wiggle_frequency_ * 0.01 * 2 * M_PI;
    if (wiggle_phase > M_PI) {
      wiggle_phase -= 2 * M_PI;
    }
  }
}

//}

/* //{ filterReferenceZ() */

void MpcTracker::filterReferenceZ(double max_speed_z) {
  double difference_z;
  double max_sample_z;
  for (int i = 0; i < horizon_len_; i++) {
    if (i == 0) {
      max_sample_z = max_speed_z * dt;
      difference_z = des_z_trajectory_(i, 0) - x_(8, 0);
    } else {
      max_sample_z = max_speed_z * dt2;
      difference_z = des_z_trajectory_(i, 0) - des_z_filtered(i - 1, 0);
    }

    // saturate the difference
    if (difference_z > max_sample_z)
      difference_z = max_sample_z;
    else if (difference_z < -max_sample_z)
      difference_z = -max_sample_z;

    if (i == 0) {
      des_z_filtered(i, 0) = x_(8, 0) + difference_z;
    } else {
      des_z_filtered(i, 0) = des_z_filtered(i - 1, 0) + difference_z;
    }
  }
}

//}

/* //{ filterYawReference() */

void MpcTracker::filterYawReference(void) {

  for (int i = 0; i < horizon_len_; i++) {
    if (fabs(des_yaw_trajectory_(0, 0)) > 1000) {
      ROS_WARN_THROTTLE(0.1, "Desired yaw is greater than 1000 rad!");
    }
  }

  // check the first trajectory member for yaw overflow
  while (des_yaw_trajectory_(0, 0) - x_yaw_(0) < -PI) {
    for (int i = 0; i < horizon_len_; i++) {
      des_yaw_trajectory_(i, 0) += 2 * PI;
    }
  }
  while (des_yaw_trajectory_(0, 0) - x_yaw_(0) > PI) {
    for (int i = 0; i < horizon_len_; i++) {
      des_yaw_trajectory_(i, 0) -= 2 * PI;
    }
  }

  // check the rest of the trajectory for yaw overflow
  for (int i = 1; i < horizon_len_; i++) {
    while (des_yaw_trajectory_(i, 0) - des_yaw_trajectory_(i - 1, 0) < -PI) {
      for (int j = i; j < horizon_len_; j++) {
        des_yaw_trajectory_(j, 0) += 2 * PI;
      }
    }
    while (des_yaw_trajectory_(i, 0) - des_yaw_trajectory_(i - 1, 0) > PI) {
      for (int j = i; j < horizon_len_; j++) {
        des_yaw_trajectory_(j, 0) -= 2 * PI;
      }
    }
  }
}

//}

/* //{ setTrajectory() */

// sets the desired trajectory based on a single setpoint
void MpcTracker::setTrajectory(float x, float y, float z, float yaw) {

  std::scoped_lock lock(mutex_des_trajectory);

  des_x_trajectory_.fill(x);
  des_y_trajectory_.fill(y);
  des_z_trajectory_.fill(z);
  des_yaw_trajectory_.fill(yaw);
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
  bool   brake;

  if (collision_avoidance_enabled_ && ((odometry_diagnostics.estimator_type.name.compare(std::string("GPS")) == STRING_EQUAL) ||
                                       odometry_diagnostics.estimator_type.name.compare(std::string("RTK")) == STRING_EQUAL)) {
    // determine the lowest point in our trajectory
    for (int i = 0; i < horizon_len_; i++) {
      if (des_z_trajectory_(i, 0) < lowest_z) {
        lowest_z = des_z_trajectory_(i, 0);
      }
    }
    // Check other drone trajectories for collisions
    minimum_collison_free_altitude = checkTrajectoryForCollisions(lowest_z, first_collision_index);
  }

  {
    std::scoped_lock lock(mutex_constraints);

    max_snap_x = max_horizontal_snap;
    max_snap_y = max_horizontal_snap;
    max_snap_z = max_vertical_ascending_snap;
    min_snap_z = max_vertical_descending_snap;

    // State and input constraints
    max_jerk_x  = max_horizontal_jerk;
    max_jerk_y  = max_horizontal_jerk;
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

  if (first_collision_index < horizon_len_) {

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
    {
      std::scoped_lock lock(mutex_constraints);

      max_speed_x = max_horizontal_speed * ((collision_horizontal_speed_coef * coef_scaler) + (1.0 - coef_scaler));
      max_speed_y = max_horizontal_speed * ((collision_horizontal_speed_coef * coef_scaler) + (1.0 - coef_scaler));
    }
  }

  if (collision_free_altitude > lowest_z) {

    // we are avoiding someone, increase Z dynamics limit for faster evasion
    max_speed_z = 2.0;
    max_acc_z   = 2.0;
    max_jerk_z  = 2.0;
    max_snap_z  = 4.0;
    min_speed_z = 2.0;
    min_acc_z   = 2.0;
    min_jerk_z  = 4.0;
    min_snap_z  = 4.0;

    {
      std::scoped_lock lock(mutex_constraints);

      max_speed_x = max_horizontal_speed * (collision_horizontal_speed_coef);
      max_speed_y = max_horizontal_speed * (collision_horizontal_speed_coef);
    }
  }

  // First control input generated by cvxgen
  VectorXd cvx_u     = VectorXd::Zero(m);
  double   cvx_u_yaw = 0;

  iters_Z   = 0;
  iters_X   = 0;
  iters_Y   = 0;
  iters_YAW = 0;

  ros::Time time_begin = ros::Time::now();

  filterReferenceZ(max_speed_z);
  for (int i = 0; i < horizon_len_; i++) {
    if (des_z_filtered(i, 0) < minimum_collison_free_altitude) {
      des_z_filtered_offset(i, 0) = minimum_collison_free_altitude;
    } else {
      des_z_filtered_offset(i, 0) = des_z_filtered(i, 0);
    }
  }

  // | ---------------------- cvxgen Z axis --------------------- |

  brake = true;
  if (des_z_filtered(10) != des_z_filtered(horizon_len_ - 1) || des_z_filtered(30) != des_z_filtered(horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_z->setVelQ(3000);
  } else {
    cvx_z->setVelQ(0);
  }

  initial_z(0, 0) = x_(8, 0);
  initial_z(1, 0) = x_(9, 0);
  initial_z(2, 0) = x_(10, 0);
  initial_z(3, 0) = x_(11, 0);

  cvx_z->setInitialState(initial_z);
  cvx_z->loadReference(des_z_filtered_offset);
  cvx_z->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_jerk_z, min_jerk_z, max_snap_z, min_snap_z);
  iters_Z += cvx_z->solveCvx();

  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    cvx_z->getStates(predicted_future_trajectory);
  }

  cvx_u(2) = cvx_z->getFirstControlInput();

  // If we are climbing to avoid a collision, reduce or arrest our horizontal velocity
  double ascend;
  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    ascend = (predicted_future_trajectory(10, 0) / max_speed_z);
  }

  if (ascend > 0 && collision_free_altitude > lowest_z) {
    max_speed_y = max_speed_y * (1.0 - ascend);
    max_speed_x = max_speed_x * (1.0 - ascend);
  }

  /* if (!tracking_trajectory_ && (dist(x_(0, 0), x_(4, 0), des_x_trajectory_(0, 0), des_y_trajectory_(0, 0)) > 1.0)) { */
  /*   // yaw angle at which my drone "sees" the goto reference point */
  /*   double goto_yaw = atan2(des_y_trajectory_(0, 0) - x_(4, 0), des_x_trajectory_(0, 0) - x_(0, 0)); */

  filterReferenceXY(max_speed_x, max_speed_y);

  filterYawReference();

  // | ---------------------- cvxgen X axis --------------------- |

  brake = true;
  if (des_x_filtered(10) != des_x_filtered(horizon_len_ - 1) || des_x_filtered(30) != des_x_filtered(horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_x->setVelQ(3000);
  } else {
    cvx_x->setVelQ(0);
  }

  initial_x(0, 0) = x_(0, 0);
  initial_x(1, 0) = x_(1, 0);
  initial_x(2, 0) = x_(2, 0);
  initial_x(3, 0) = x_(3, 0);

  cvx_x->setInitialState(initial_x);
  cvx_x->loadReference(des_x_filtered);
  cvx_x->setLimits(max_speed_x, max_speed_x, max_acc_x, max_acc_x, max_jerk_x, max_jerk_x, max_snap_x, max_snap_x);
  iters_X += cvx_x->solveCvx();

  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    cvx_x->getStates(predicted_future_trajectory);
  }

  cvx_u(0) = cvx_x->getFirstControlInput();

  // | ---------------------- cvxgen Y axis --------------------- |

  brake = true;
  if (des_y_filtered(10) != des_y_filtered(horizon_len_ - 1) || des_y_filtered(30) != des_y_filtered(horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_y->setVelQ(3000);
  } else {
    cvx_y->setVelQ(0);
  }

  initial_y(0, 0) = x_(4, 0);
  initial_y(1, 0) = x_(5, 0);
  initial_y(2, 0) = x_(6, 0);
  initial_y(3, 0) = x_(7, 0);

  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    /* if (tracking_trajectory_) { */
    /*   vel_qy = 8000; */
    /* } else if (fabs(predicted_future_trajectory((horizon_len_ - 1) * 12 + 4, 0) - des_y_trajectory_(0, 0)) < 2.0) { */
    /*   vel_qy = 8000; */
    /* } */
  }

  cvx_y->setInitialState(initial_y);
  cvx_y->loadReference(des_y_filtered);
  cvx_y->setLimits(max_speed_y, max_speed_y, max_acc_y, max_acc_y, max_jerk_y, max_jerk_y, max_snap_y, max_snap_y);
  iters_Y += cvx_y->solveCvx();
  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    cvx_y->getStates(predicted_future_trajectory);
  }
  cvx_u(1) = cvx_y->getFirstControlInput();


  // | ---------------------- cvxgen YAW axis --------------------- |

  brake = true;
  if (fabs(x_yaw_(0) - des_yaw_trajectory_(10)) > 1.0 || fabs(x_yaw_(0) - des_yaw_trajectory_(30)) > 1.0) {
    brake = false;
  }
  if (brake) {
    cvx_yaw->setVelQ(3000);
  } else {
    cvx_yaw->setVelQ(0);
  }

  cvx_yaw->setInitialState(x_yaw_);
  cvx_yaw->loadReference(des_yaw_trajectory_);
  {
    std::scoped_lock lock(mutex_constraints);

    cvx_yaw->setLimits(max_yaw_rate, max_yaw_rate, max_yaw_acceleration, max_yaw_acceleration, max_yaw_jerk, max_yaw_jerk, max_yaw_snap, max_yaw_snap);
  }
  iters_YAW += cvx_yaw->solveCvx();
  {
    std::scoped_lock lock(mutex_predicted_trajectory);

    cvx_yaw->getStates(predicted_future_yaw_trajectory);
  }
  cvx_u_yaw = cvx_yaw->getFirstControlInput();

  {
    std::scoped_lock lock(mutex_constraints);

    if (cvx_u(0) > max_horizontal_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap X: " << cvx_u(0));
      cvx_u(0) = max_horizontal_snap;
    }
    if (cvx_u(0) < -max_horizontal_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap X: " << cvx_u(0));
      cvx_u(0) = -max_horizontal_snap;
    }
    if (cvx_u(1) > max_horizontal_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap Y: " << cvx_u(1));
      cvx_u(1) = max_horizontal_snap;
    }
    if (cvx_u(1) < -max_horizontal_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap Y: " << cvx_u(1));
      cvx_u(1) = -max_horizontal_snap;
    }
    if (cvx_u(2) > max_vertical_ascending_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap Z: " << cvx_u(2));
      cvx_u(2) = max_vertical_ascending_snap;
    }
    if (cvx_u(2) < -max_vertical_descending_snap * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Saturating snap Z: " << cvx_u(2));
      cvx_u(2) = -max_vertical_descending_snap;
    }
  }

  double cvx_time = (ros::Time::now() - time_begin).toSec();
  if (cvx_time > 0.01 || iters_X > max_iters_XY || iters_Y > max_iters_XY || iters_Z > max_iters_Z || iters_YAW > max_iters_YAW) {
    ROS_DEBUG_STREAM_THROTTLE(1.0, "[MpcTracker]: Total CVXtime: " << cvx_time << " iters X: " << iters_X << "/" << max_iters_XY << " iters Y:  " << iters_Y
                                                                   << "/" << max_iters_XY << " iters Z: " << iters_Z << "/" << max_iters_Z
                                                                   << " iters yaw: " << iters_YAW << "/" << max_iters_YAW);
  }

  {
    std::scoped_lock lock(mutex_x);

    x_     = A * x_ + B * cvx_u;
    x_yaw_ = A_yaw * x_yaw_ + B_yaw * cvx_u_yaw;

    // fix possible PI overflows
    if (x_yaw_(0) > PI) {
      x_yaw_(0) -= 2 * PI;
    } else if (x_yaw_(0) < -PI) {
      x_yaw_(0) += 2 * PI;
    }
  }

  /* ROS_INFO("[MpcTracker]: end of mpc calculation x %f y %f xvel %f yvel %f xacc %f yacc %f", x_(0, 0), x_(4, 0), x_(1, 0), x_(5, 0), x_(2, 0), x_(6, 0)); */

  future_was_predicted = true;
}

//}

/* //{ publishDiagnostics() */

void MpcTracker::publishDiagnostics(void) {

  mrs_msgs::MpcTrackerDiagnostics diagnostics;

  diagnostics.header.stamp    = ros::Time::now();
  diagnostics.header.frame_id = uav_state_.header.frame_id;

  diagnostics.uav_name = uav_name_;

  diagnostics.tracker_active = is_active;

  diagnostics.collision_avoidance_active = collision_avoidance_enabled_;
  diagnostics.avoiding_collision         = avoiding_collision;

  // true if tracking_trajectory_ of if flying to a setpoint
  diagnostics.tracking_trajectory = false;

  if (tracking_trajectory_ || hovering_in_progress) {
    diagnostics.tracking_trajectory = true;
  } else {
    if (sqrt(pow(x_(0, 0) - des_x_trajectory_(0), 2) + pow(x_(4, 0) - des_y_trajectory_(0), 2) + pow(x_(8, 0) - des_z_trajectory_(0), 2)) >
            diagnostic_position_tracking_threshold ||
        fabs(des_yaw_trajectory_(0) - x_yaw_(0)) > diagnostic_orientation_tracking_threshold) {
      diagnostics.tracking_trajectory = true;
    }
  }

  diagnostics.trajectory_length = trajectory_size_;
  diagnostics.trajectory_idx    = trajectory_idx_;
  diagnostics.trajectory_count  = trajectory_count_;

  diagnostics.setpoint.position.x = des_x_trajectory_(0, 0);
  diagnostics.setpoint.position.y = des_y_trajectory_(0, 0);
  diagnostics.setpoint.position.z = des_z_trajectory_(0, 0);

  tf::Quaternion orientation;
  orientation.setEuler(0, 0, desired_yaw);
  diagnostics.setpoint.orientation.x = orientation.x();
  diagnostics.setpoint.orientation.y = orientation.y();
  diagnostics.setpoint.orientation.z = orientation.z();
  diagnostics.setpoint.orientation.w = orientation.w();

  char buffer[300];
  buffer[0] = 0;

  {
    std::scoped_lock lock(mutex_other_drone_diagnostics);

    // fill in if other UAVs are sending their trajectories
    std::map<std::string, mrs_msgs::MpcTrackerDiagnostics>::iterator u = other_drones_diagnostics.begin();

    while (u != other_drones_diagnostics.end()) {

      if (u->second.collision_avoidance_active) {

        // is the other's trajectory fresh enought?
        if ((ros::Time::now() - u->second.header.stamp).toSec() < collision_trajectory_timeout) {
          diagnostics.avoidance_active_uavs.push_back(u->first);
          sprintf(buffer + strlen(buffer), "%s ", u->first.c_str());
        }
      }

      u++;
    }
  }

  if (strlen(buffer) > 0) {
    ROS_DEBUG_THROTTLE(5.0, "[MpcTracker]: getting avoidance trajectories: %s", buffer);
  } else if (got_odometry_diagnostics && collision_avoidance_enabled_ &&
             ((odometry_diagnostics.estimator_type.name.compare(std::string("GPS")) == STRING_EQUAL) ||
              odometry_diagnostics.estimator_type.name.compare(std::string("RTK")) == STRING_EQUAL)) {
    ROS_WARN_THROTTLE(10.0, "[MpcTracker]: missing avoidance trajectories!");
  }

  try {
    pub_diagnostics_.publish(diagnostics);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_diagnostics_.getTopic().c_str());
  }
}

//}

/* //{ setRelativeGoal() */

bool MpcTracker::setRelativeGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

  double abs_x   = x_(0, 0) + set_x;
  double abs_y   = x_(4, 0) + set_y;
  double abs_z   = x_(8, 0) + set_z;
  double abs_yaw = x_yaw_(0, 0) + set_yaw;

  if (set_use_yaw) {
    {
      std::scoped_lock lock(des_yaw_mutex);

      desired_yaw = abs_yaw;
    }
  }

  {
    std::scoped_lock lock(mutex_des_trajectory);

    tracking_trajectory_ = false;
  }

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
bool MpcTracker::loadTrajectory(const mrs_msgs::TrackerTrajectory &msg, std::string &message, bool &modified) {

  // copy the member variables
  auto x         = mrs_lib::get_mutexed(mutex_x, x_);
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  /* validate size and NaNs //{ */

  // check if the trajectory does not exceed maximum size
  if (int(msg.points.size()) > (_max_trajectory_size_ - horizon_len_)) {

    ROS_WARN("[MpcTracker]: Cannot load trajectory, its too large (%d).", (int)msg.points.size());

    char buffer[200];
    sprintf(buffer, "Cannot load trajectory, its too large (%d).", (int)msg.points.size());
    message = buffer;
    return false;
  }

  // check for the size 0, which is also invalid
  if (msg.points.size() == 0) {

    message = "Cannot load trajectory with size 0.";
    ROS_WARN("[MpcTracker]: %s", message.c_str());
    return false;
  }

  for (unsigned int i = 0; i < msg.points.size(); i++) {

    // check the point for NaN/inf
    bool no_nans = true;

    if (!std::isfinite(msg.points[i].x)) {
      ROS_ERROR("[MpcTracker]: NaN/inf detected in variable \"msg.points[%d].x\"!!!", i);
      no_nans = false;
    }

    if (!std::isfinite(msg.points[i].y)) {
      ROS_ERROR("[MpcTracker]: NaN/inf detected in variable \"msg.points[%d].y\"!!!", i);
      no_nans = false;
    }

    if (!std::isfinite(msg.points[i].z)) {
      ROS_ERROR("[MpcTracker]: NaN/inf detected in variable \"msg.points[%d].z\"!!!", i);
      no_nans = false;
    }

    if (!std::isfinite(msg.points[i].yaw)) {
      ROS_ERROR("[MpcTracker]: NaN/inf detected in variable \"msg.points[%d].yaw\"!!!", i);
      no_nans = false;
    }

    if (no_nans == false) {

      message = "Trajectory contains NaNs/infs.";
      ROS_WARN("[MpcTracker]: %s", message.c_str());
      return false;
    }
  }

  //}

  int trajectory_size = msg.points.size();

  /* publish the debugging topics of the original trajectory //{ */

  {

    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header = msg.header;

    debug_trajectory_out.header.frame_id = common_handlers->transformer->resolveFrameName(debug_trajectory_out.header.frame_id);

    if (debug_trajectory_out.header.frame_id == "") {
      debug_trajectory_out.header.frame_id = uav_state.header.frame_id;
    }

    if (debug_trajectory_out.header.stamp == ros::Time(0)) {
      debug_trajectory_out.header.stamp = ros::Time::now();
    }

    {
      std::scoped_lock lock(mutex_des_whole_trajectory);

      for (int i = 0; i < trajectory_size; i++) {

        geometry_msgs::Pose newPose;

        newPose.position.x = msg.points[i].x;
        newPose.position.y = msg.points[i].y;
        newPose.position.z = msg.points[i].z;

        tf::Quaternion orientation;
        orientation.setEuler(0, 0, msg.points[i].yaw);
        newPose.orientation.x = orientation.x();
        newPose.orientation.y = orientation.y();
        newPose.orientation.z = orientation.z();
        newPose.orientation.w = orientation.w();

        debug_trajectory_out.poses.push_back(newPose);
      }
    }

    try {
      pub_debug_original_trajectory_poses_.publish(debug_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_debug_original_trajectory_poses_.getTopic().c_str());
    }

    visualization_msgs::MarkerArray msg_out;

    visualization_msgs::Marker marker;

    marker.header = msg.header;

    marker.header.frame_id = common_handlers->transformer->resolveFrameName(marker.header.frame_id);

    if (marker.header.frame_id == "") {
      marker.header.frame_id = uav_state.header.frame_id;
    }

    if (marker.header.stamp == ros::Time(0)) {
      marker.header.stamp = ros::Time::now();
    }

    marker.type               = visualization_msgs::Marker::LINE_LIST;
    marker.color.a            = 1;
    marker.scale.x            = 0.05;
    marker.color.r            = 0;
    marker.color.g            = 1;
    marker.color.b            = 0;
    marker.pose.orientation.w = 1;

    {
      std::scoped_lock lock(mutex_des_whole_trajectory);

      for (int i = 0; i < trajectory_size - 1; i++) {

        geometry_msgs::Point point1;

        point1.x = msg.points[i].x;
        point1.y = msg.points[i].y;
        point1.z = msg.points[i].z;

        marker.points.push_back(point1);

        geometry_msgs::Point point2;

        point2.x = msg.points[i + 1].x;
        point2.y = msg.points[i + 1].y;
        point2.z = msg.points[i + 1].z;

        marker.points.push_back(point2);
      }
    }

    msg_out.markers.push_back(marker);

    try {
      pub_debug_original_trajectory_markers_.publish(msg_out);
    }
    catch (...) {
      ROS_ERROR("Exception caught during publishing topic %s.", pub_debug_original_trajectory_markers_.getTopic().c_str());
    }
  }

  //}

  /* sanitize the time-ness of the trajectory //{ */

  int    trajectory_sample_offset    = 0;  // how many samples in past
  int    trajectory_subsample_offset = 0;  // how many simulation inner loops ahead of the first valid sample
  double trajectory_time_offset      = 0;  // how much time in past in [s]

  // btw, "trajectory_time_offset = 0.2*trajectory_sample_offset + 0.01*trajectory_subsample_offset" should hold
  if (msg.fly_now) {

    ros::Time trajectory_time = msg.header.stamp;

    // the desired time is 0 => the current time
    if (trajectory_time == ros::Time(0)) {

      trajectory_time_offset = 0.0;

      // the desired time is specified
    } else {

      trajectory_time_offset = (ros::Time::now() - trajectory_time).toSec();

      // when the time offset is negative, thus in the future
      // just say it, but use it like its from the current time
      if (trajectory_time_offset < 0.0) {

        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: Received trajectory with timestamp in the future by %.2f s", -trajectory_time_offset);

        trajectory_time_offset = 0.0;
      }
    }

    // if the time offset is set, check if we need to "move the first idx"
    if (trajectory_time_offset > 0) {

      // calculate the offset in samples
      trajectory_sample_offset = int(floor(trajectory_time_offset / 0.2));

      // and get the subsample offset, which will be used to initialize the interpolator
      trajectory_subsample_offset = int(floor(fmod(trajectory_time_offset, 0.2) / (0.01)));

      ROS_DEBUG("[MpcTracker]: sanity check: %.3f", 0.2 * trajectory_sample_offset + 0.01 * trajectory_subsample_offset);

      // if the offset is larger than the number of points in the trajectory
      // the trajectory cannot be used
      if (trajectory_sample_offset >= trajectory_size) {

        message = "Trajectory timestamp is too old!";
        ROS_ERROR_THROTTLE(1.0, "[MpcTracker]: Trajectory timestamp is too old!");

        return false;

      } else {

        // If the offset is larger than one trajectory sample,
        // offset the start
        if (trajectory_time_offset >= 0.2) {

          // decrease the trajectory size
          trajectory_size -= trajectory_sample_offset;

          ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: Got trajectory with timestamp \"" << trajectory_time_offset << " s\" in the past");
        }
      }
    }
  }

  //}

  ROS_DEBUG("[MpcTracker]: trajectory sample offset: %d", trajectory_sample_offset);
  ROS_DEBUG("[MpcTracker]: trajectory subsample offset: %d", trajectory_subsample_offset);

  // after this, we should have the correct value of
  // * trajectory_size
  // * trajectory_sample_offset
  // * trajectory_subsample_offset

  /* copy the trajectory to a local variable //{ */

  // copy only the part from the first valid index

  MatrixXd des_x_whole_trajectory   = VectorXd::Zero(_max_trajectory_size_, 1);
  MatrixXd des_y_whole_trajectory   = VectorXd::Zero(_max_trajectory_size_, 1);
  MatrixXd des_z_whole_trajectory   = VectorXd::Zero(_max_trajectory_size_, 1);
  MatrixXd des_yaw_whole_trajectory = VectorXd::Zero(_max_trajectory_size_, 1);

  for (int i = 0; i < trajectory_size; i++) {

    des_x_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].x;
    des_y_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].y;
    des_z_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].z;
    des_yaw_whole_trajectory(i) = msg.points[trajectory_sample_offset + i].yaw;
  }

  //}

  /* bumper check //{ */

  if (common_handlers->bumper.enabled) {

    for (int i = 0; i < trajectory_size; i++) {

      mrs_msgs::ReferenceStamped des_reference;
      des_reference.header               = msg.header;
      des_reference.reference.position.x = des_x_whole_trajectory(i);
      des_reference.reference.position.y = des_y_whole_trajectory(i);
      des_reference.reference.position.z = des_z_whole_trajectory(i);
      des_reference.reference.yaw        = des_yaw_whole_trajectory(i);

      if (!common_handlers->bumper.bumperValidatePoint(des_reference)) {

        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: trajectory violates bumper and can't be fixed, shortening it!");
        trajectory_size = i;
        break;

      } else {

        des_x_whole_trajectory(i)   = des_reference.reference.position.x;
        des_y_whole_trajectory(i)   = des_reference.reference.position.y;
        des_z_whole_trajectory(i)   = des_reference.reference.position.z;
        des_yaw_whole_trajectory(i) = des_reference.reference.yaw;
      }
    }
  }

  if (trajectory_size == 0) {

    message = "the whole trajectory violates bumper, cannot execute it!";
    ROS_WARN("[MpcTracker]: %s", message.c_str());
    return false;
  }

  //}

  std::string current_frame_id = msg.header.frame_id;

  /* transform the trajectory to the safety area frame //{ */

  if (common_handlers->safety_area.use_safety_area) {

    auto ret = common_handlers->transformer->getTransform(current_frame_id, common_handlers->safety_area.frame_id, uav_state_.header.stamp);

    if (!ret) {

      message = "Coult not create TF transformer for the trajectory.";
      ROS_WARN_THROTTLE(1.0, "[MpcTracker]: Coult not create TF transformer for the trajectory.");
      return false;
    }

    current_frame_id = common_handlers->safety_area.frame_id;

    mrs_lib::TransformStamped tf = ret.value();

    for (int i = 0; i < trajectory_size; i++) {

      mrs_msgs::ReferenceStamped trajectory_point;
      trajectory_point.header = msg.header;

      trajectory_point.reference.position.x = des_x_whole_trajectory(i);
      trajectory_point.reference.position.y = des_y_whole_trajectory(i);
      trajectory_point.reference.position.z = des_z_whole_trajectory(i);
      trajectory_point.reference.yaw        = des_yaw_whole_trajectory(i);

      auto ret = common_handlers->transformer->transform(tf, trajectory_point);

      if (!ret) {

        message = "Trajectory cannnot be transformed to the safety area frame.";
        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: the reference could not be transformed.");
        return false;

      } else {

        // transform the points in the trajectory to the current frame
        des_x_whole_trajectory(i)   = ret.value().reference.position.x;
        des_y_whole_trajectory(i)   = ret.value().reference.position.y;
        des_z_whole_trajectory(i)   = ret.value().reference.position.z;
        des_yaw_whole_trajectory(i) = ret.value().reference.yaw;
      }
    }
  }

  //}

  /* safety area check //{ */

  bool safety_area_pass = true;

  if (common_handlers->safety_area.use_safety_area) {

    // transform the current state to the safety area frame
    mrs_msgs::ReferenceStamped x_current_frame;
    x_current_frame.header               = uav_state.header;
    x_current_frame.reference.position.x = x(0, 0);
    x_current_frame.reference.position.y = x(4, 0);

    auto res = common_handlers->transformer->transformSingle(common_handlers->safety_area.frame_id, x_current_frame);

    mrs_msgs::ReferenceStamped x_area_frame;

    if (res) {
      x_area_frame = res.value();
    } else {

      message = "Could not transform current state to safety area frame!";
      ROS_WARN("[MpcTracker]: %s", message.c_str());
      return false;
    }

    int last_valid_idx    = 0;
    int first_invalid_idx = -1;

    double min_height = common_handlers->safety_area.getMinHeight();
    double max_height = common_handlers->safety_area.getMaxHeight();

    for (int i = 0; i < trajectory_size; i++) {

      // saturate the trajectory to min and max height
      if (des_z_whole_trajectory(i) < min_height) {

        des_z_whole_trajectory(i) = min_height;
        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: The trajectory violates the minimum height!");
        safety_area_pass = false;
      }

      if (des_z_whole_trajectory(i) > max_height) {

        des_z_whole_trajectory(i) = max_height;
        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: The trajectory violates the maximum height!");
        safety_area_pass = false;
      }

      // the point is not feasible
      mrs_msgs::ReferenceStamped des_reference;
      des_reference.header.frame_id      = current_frame_id;
      des_reference.reference.position.x = des_x_whole_trajectory(i);
      des_reference.reference.position.y = des_y_whole_trajectory(i);

      if (!common_handlers->safety_area.isPointInSafetyArea2d(des_reference)) {

        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: The trajectory contains points outside of the safety area!");
        safety_area_pass = false;

        // the first invalid point
        if (first_invalid_idx == -1) {

          first_invalid_idx = i;

          last_valid_idx = i - 1;
        }

        // the point is ok
      } else {

        // we found a point, which is ok, after founding a point which was not ok
        if (first_invalid_idx != -1) {

          // interpolate
          // TODO dont do this when fly_now == true and just start the trajectory in the first valid point
          if (last_valid_idx == -1) {  // special case, we had no valid point so far

            // interpolate between the current position and the valid point
            double angle = atan2(des_y_whole_trajectory(i) - x_area_frame.reference.position.y, des_x_whole_trajectory(i) - x_area_frame.reference.position.x);
            double dist_two_points =
                dist(des_x_whole_trajectory(i), des_y_whole_trajectory(i), x_area_frame.reference.position.x, x_area_frame.reference.position.y);

            if (dist_two_points > 1.0) {
              message = "The trajectory starts outride of the safety area!";
              ROS_WARN("[MpcTracker]: %s", message.c_str());
              return false;
            }

            double step = dist_two_points / i;

            for (int j = 0; j < i; j++) {
              des_x_whole_trajectory(j) = x_area_frame.reference.position.x + j * cos(angle) * step;
              des_y_whole_trajectory(j) = x_area_frame.reference.position.y + j * sin(angle) * step;
            }

            // we have a valid point in the past
          } else {

            bool interpolation_success = true;

            // iterpolate between the last valid point and this new valid point
            double angle = atan2((des_y_whole_trajectory(i) - des_y_whole_trajectory(last_valid_idx)),
                                 (des_x_whole_trajectory(i) - des_x_whole_trajectory(last_valid_idx)));

            double dist_two_points =
                dist(des_x_whole_trajectory(i), des_y_whole_trajectory(i), des_x_whole_trajectory(last_valid_idx), des_y_whole_trajectory(last_valid_idx));
            double step = dist_two_points / (i - last_valid_idx);

            for (int j = last_valid_idx; j < i; j++) {

              mrs_msgs::ReferenceStamped temp_point;
              temp_point.header.frame_id      = current_frame_id;
              temp_point.reference.position.x = des_x_whole_trajectory(last_valid_idx) + (j - last_valid_idx) * cos(angle) * step;
              temp_point.reference.position.y = des_y_whole_trajectory(last_valid_idx) + (j - last_valid_idx) * sin(angle) * step;

              if (!common_handlers->safety_area.isPointInSafetyArea2d(temp_point)) {

                interpolation_success = false;
                break;

              } else {

                des_x_whole_trajectory(j) = temp_point.reference.position.x;
                des_y_whole_trajectory(j) = temp_point.reference.position.y;
              }
            }

            if (!interpolation_success) {
              break;
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

        message = "The whole trajectory is outside of the safety area!";
        ROS_WARN("[MpcTracker]: %s", message.c_str());
        return false;

        // there is a good portion of the trajectory in the beginning
      } else {

        trajectory_size  = last_valid_idx + 1;
        safety_area_pass = false;
      }
    }
  }

  if (trajectory_size == 0) {

    message = "the trajectory somehow happened to be empty after all the checks! This message should not appear!";
    ROS_WARN("[MpcTracker]: %s", message.c_str());
    return false;
  }

  //}

  /* transform the trajectory to the current frame //{ */

  auto ret = common_handlers->transformer->getTransform(current_frame_id, "", uav_state_.header.stamp);

  if (!ret) {

    message = "Coult not create TF transformer for the trajectory.";
    ROS_WARN("[MpcTracker]: Coult not create TF transformer for the trajectory.");
    return false;
  }

  current_frame_id = ret.value().to();

  mrs_lib::TransformStamped tf = ret.value();

  for (int i = 0; i < trajectory_size; i++) {

    mrs_msgs::ReferenceStamped trajectory_point;
    trajectory_point.header = msg.header;

    trajectory_point.reference.position.x = des_x_whole_trajectory(i);
    trajectory_point.reference.position.y = des_y_whole_trajectory(i);
    trajectory_point.reference.position.z = des_z_whole_trajectory(i);
    trajectory_point.reference.yaw        = des_yaw_whole_trajectory(i);

    auto ret = common_handlers->transformer->transform(tf, trajectory_point);

    if (!ret) {

      message = "Trajectory cannnot be transformed.";
      ROS_WARN("[MpcTracker]: the reference could not be transformed.");
      return false;

    } else {

      // transform the points in the trajectory to the current frame
      des_x_whole_trajectory(i)   = ret.value().reference.position.x;
      des_y_whole_trajectory(i)   = ret.value().reference.position.y;
      des_z_whole_trajectory(i)   = ret.value().reference.position.z;
      des_yaw_whole_trajectory(i) = ret.value().reference.yaw;
    }
  }

  //}

  /* set looping //{ */

  bool loop = false;

  if (msg.loop) {

    double first_x = des_x_whole_trajectory(0);
    double first_y = des_y_whole_trajectory(0);
    double first_z = des_z_whole_trajectory(0);

    double last_x = des_x_whole_trajectory(trajectory_size - 1);
    double last_y = des_y_whole_trajectory(trajectory_size - 1);
    double last_z = des_z_whole_trajectory(trajectory_size - 1);

    // check whether the trajectory is loopable
    // TODO should check yaw aswell
    if (dist3d(first_x, first_y, first_z, last_x, last_y, last_z) < 3.141592653) {

      ROS_INFO_THROTTLE(1.0, "[MpcTracker]: looping enabled");
      loop = true;

    } else {

      message = "cannot loop trajectory, the first and last points are too far apart";
      ROS_WARN_STREAM("[MpcTracker]: " << message);
      return false;
    }

  } else {

    loop = false;
  }

  //}

  // by this time, the values of these should be set:
  // * loop

  /* add tail (the last point repeated to fill the prediction horizon) //{ */

  if (!loop) {

    // extend it so it has smooth ending
    for (int i = 0; i < horizon_len_; i++) {

      des_x_whole_trajectory(i + trajectory_size)   = des_x_whole_trajectory(i + trajectory_size - 1);
      des_y_whole_trajectory(i + trajectory_size)   = des_y_whole_trajectory(i + trajectory_size - 1);
      des_z_whole_trajectory(i + trajectory_size)   = des_z_whole_trajectory(i + trajectory_size - 1);
      des_yaw_whole_trajectory(i + trajectory_size) = des_yaw_whole_trajectory(i + trajectory_size - 1);
    }
  }

  //}

  // by this time, the values of these should be set correctly:
  // * trajectory_size
  // * des_x_whole_trajectory
  // * des_y_whole_trajectory
  // * des_z_whole_trajectory
  // * des_yaw_whole_trajectory

  /* update the global variables //{ */

  {
    std::scoped_lock lock(mutex_des_whole_trajectory, mutex_des_trajectory);

    tracking_trajectory_   = msg.fly_now;
    use_yaw_in_trajectory_ = msg.use_yaw;

    for (int i = 0; i < trajectory_size + horizon_len_; i++) {

      des_x_whole_trajectory_(i) = des_x_whole_trajectory(i);
      des_y_whole_trajectory_(i) = des_y_whole_trajectory(i);
      des_z_whole_trajectory_(i) = des_z_whole_trajectory(i);

      if (use_yaw_in_trajectory_) {
        des_yaw_whole_trajectory_(i) = des_yaw_whole_trajectory(i);
      } else {
        des_yaw_whole_trajectory.fill(desired_yaw);
      }
    }

    // if we are tracking trajectory, copy the setpoint
    if (tracking_trajectory_) {

      toggleHover(false);

      for (int i = 0; i < horizon_len_; i++) {

        des_x_trajectory_(i)   = des_x_whole_trajectory(i);
        des_y_trajectory_(i)   = des_y_whole_trajectory(i);
        des_z_trajectory_(i)   = des_z_whole_trajectory(i);
        des_yaw_trajectory_(i) = des_yaw_whole_trajectory(i);
      }

      if (use_yaw_in_trajectory_) {
        desired_yaw = des_yaw_whole_trajectory(0);
      }
    }

    trajectory_size_           = trajectory_size;
    trajectory_idx_            = 0;
    trajectory_tracking_timer_ = trajectory_subsample_offset;
    trajectory_set_            = true;
    loop_                      = loop;
    trajectory_count_++;
  }

  //}

  ROS_INFO_THROTTLE(1, "[MpcTracker]: received trajectory with length %d", trajectory_size);

  /* publish the debugging topics of the post-processed trajectory //{ */

  {

    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = ros::Time::now();
    debug_trajectory_out.header.frame_id = common_handlers->transformer->resolveFrameName(current_frame_id);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory);

      for (int i = 0; i < trajectory_size; i++) {

        geometry_msgs::Pose newPose;

        newPose.position.x = des_x_whole_trajectory_(i);
        newPose.position.y = des_y_whole_trajectory_(i);
        newPose.position.z = des_z_whole_trajectory_(i);

        tf::Quaternion orientation;
        orientation.setEuler(0, 0, des_yaw_whole_trajectory_(i));
        newPose.orientation.x = orientation.x();
        newPose.orientation.y = orientation.y();
        newPose.orientation.z = orientation.z();
        newPose.orientation.w = orientation.w();

        debug_trajectory_out.poses.push_back(newPose);
      }
    }

    try {
      pub_debug_processed_trajectory_poses_.publish(debug_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_debug_processed_trajectory_poses_.getTopic().c_str());
    }

    visualization_msgs::MarkerArray msg_out;

    visualization_msgs::Marker marker;

    marker.header.stamp       = ros::Time::now();
    marker.header.frame_id    = common_handlers->transformer->resolveFrameName(current_frame_id);
    marker.type               = visualization_msgs::Marker::LINE_LIST;
    marker.color.a            = 1;
    marker.scale.x            = 0.05;
    marker.color.r            = 1;
    marker.color.g            = 0;
    marker.color.b            = 0;
    marker.pose.orientation.w = 1;

    {
      std::scoped_lock lock(mutex_des_whole_trajectory);

      for (int i = 0; i < trajectory_size - 1; i++) {

        geometry_msgs::Point point1;

        point1.x = des_x_whole_trajectory(i);
        point1.y = des_y_whole_trajectory(i);
        point1.z = des_z_whole_trajectory(i);

        marker.points.push_back(point1);

        geometry_msgs::Point point2;

        point2.x = des_x_whole_trajectory(i + 1);
        point2.y = des_y_whole_trajectory(i + 1);
        point2.z = des_z_whole_trajectory(i + 1);

        marker.points.push_back(point2);
      }
    }

    msg_out.markers.push_back(marker);

    try {
      pub_debug_processed_trajectory_markers_.publish(msg_out);
    }
    catch (...) {
      ROS_ERROR("Exception caught during publishing topic %s.", pub_debug_processed_trajectory_markers_.getTopic().c_str());
    }
  }

  //}

  publishDiagnostics();

  if (safety_area_pass) {

    message  = "The trajectory successfully loaded.";
    modified = false;

  } else {

    message  = "The trajectory was modified from its original form.";
    modified = true;
  }

  return true;
}

//}

/* //{ setGoal() */

// set absolute goal
bool MpcTracker::setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

  if (set_use_yaw) {

    {
      std::scoped_lock lock(des_yaw_mutex);

      desired_yaw = set_yaw;
    }
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

/* rotateVector() //{ */

Eigen::Vector2d MpcTracker::rotateVector(const Eigen::Vector2d vector_in, double angle) {

  Eigen::Rotation2D<double> rot2(angle);

  return rot2.toRotationMatrix() * vector_in;
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

  mrs_lib::Routine profiler_routine = profiler.createRoutine("diagnosticsTimer", diagnostics_rate, 0.01, event);

  publishDiagnostics();
}

//}

/* //{ mpcTimer() */

void MpcTracker::mpcTimer(const ros::TimerEvent &event) {

  if (resetting_odometry) {
    ROS_ERROR("[MpcTracker]: MPC tried to run while reseting odometry");
    return;
  }

  mrs_lib::ScopeUnset unset_running(running_mpc_timer);

  bool started_with_invalid = mpc_result_invalid;

  if (!is_active) {
    return;
  }

  if (!is_initialized) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler.createRoutine("mpcIteration", int(1.0 / dt), 0.004, event);

  ros::Time     begin = ros::Time::now();
  ros::Time     end;
  ros::Duration interval;

  // if we are tracking trajectory, copy the setpoint
  if (tracking_trajectory_) {

    /* interpolate the trajectory points and fill in the desired_trajectory vector //{ */

    {
      std::scoped_lock lock(mutex_des_trajectory, mutex_des_whole_trajectory);

      double interp_coeff = (trajectory_tracking_timer_ / 20.0);

      int first_idx  = trajectory_idx_;
      int second_idx = trajectory_idx_ + 1;

      if (loop_) {

        if (first_idx >= trajectory_size_) {
          first_idx -= trajectory_size_;
        }

        if (second_idx >= trajectory_size_) {
          second_idx -= trajectory_size_;
        }
      }

      des_x_trajectory_(0, 0) = (1 - interp_coeff) * des_x_whole_trajectory_(first_idx) + interp_coeff * des_x_whole_trajectory_(second_idx);
      des_y_trajectory_(0, 0) = (1 - interp_coeff) * des_y_whole_trajectory_(first_idx) + interp_coeff * des_y_whole_trajectory_(second_idx);
      des_z_trajectory_(0, 0) = (1 - interp_coeff) * des_z_whole_trajectory_(first_idx) + interp_coeff * des_z_whole_trajectory_(second_idx);

      des_yaw_trajectory_(0, 0) = interpolateAngles(des_yaw_whole_trajectory_(first_idx), des_yaw_whole_trajectory_(second_idx), 1 - interp_coeff);

      for (int i = 1; i < horizon_len_; i++) {

        int first_idx  = trajectory_idx_ + i;
        int second_idx = trajectory_idx_ + 1 + i;

        if (loop_) {

          if (second_idx >= trajectory_size_) {
            second_idx -= trajectory_size_;
          }

          if (first_idx >= trajectory_size_) {
            first_idx -= trajectory_size_;
          }

          des_x_trajectory_(i, 0) = (1 - interp_coeff) * des_x_whole_trajectory_(first_idx) + interp_coeff * des_x_whole_trajectory_(second_idx);
          des_y_trajectory_(i, 0) = (1 - interp_coeff) * des_y_whole_trajectory_(first_idx) + interp_coeff * des_y_whole_trajectory_(second_idx);
          des_z_trajectory_(i, 0) = (1 - interp_coeff) * des_z_whole_trajectory_(first_idx) + interp_coeff * des_z_whole_trajectory_(second_idx);

          des_yaw_trajectory_(i, 0) = interpolateAngles(des_yaw_whole_trajectory_(first_idx), des_yaw_whole_trajectory_(second_idx), 1 - interp_coeff);

        } else {

          des_x_trajectory_(i, 0) = (1 - interp_coeff) * des_x_whole_trajectory_(first_idx) + interp_coeff * des_x_whole_trajectory_(second_idx);
          des_y_trajectory_(i, 0) = (1 - interp_coeff) * des_y_whole_trajectory_(first_idx) + interp_coeff * des_y_whole_trajectory_(second_idx);
          des_z_trajectory_(i, 0) = (1 - interp_coeff) * des_z_whole_trajectory_(first_idx) + interp_coeff * des_z_whole_trajectory_(second_idx);

          des_yaw_trajectory_(i, 0) = interpolateAngles(des_yaw_whole_trajectory_(first_idx), des_yaw_whole_trajectory_(second_idx), 1 - interp_coeff);
        }
      }
    }

    //}

    /* do a step of the main tracking idx //{ */

    // every 200 ms, when the subsampling timer hits 20 and we are still tracking
    if (trajectory_tracking_timer_++ == 20 && trajectory_idx_ < (trajectory_size_)) {

      // reset the subsampling timer
      trajectory_tracking_timer_ = 0;

      if (use_yaw_in_trajectory_) {

        std::scoped_lock lock(mutex_des_trajectory, mutex_des_whole_trajectory);

        desired_yaw = des_yaw_whole_trajectory_(trajectory_idx_);
      }

      // INCREMENT THE TRACKING IDX
      trajectory_idx_++;

      // if the tracking idx hits the end of the trajectory
      if (trajectory_idx_ == trajectory_size_) {

        if (loop_) {

          // reset the idx
          trajectory_idx_ = 0;

          ROS_INFO("[MpcTracker]: trajectory looped");

        } else {

          tracking_trajectory_ = false;

          // set the idx to the last idx of the trajectory
          trajectory_idx_ = trajectory_size_ - 1;

          ROS_INFO("[MpcTracker]: Done tracking trajectory.");
          publishDiagnostics();
        }
      }
    }

    //}
  }

  manageConstraints();

  calculateMPC();

  end      = ros::Time::now();
  interval = end - begin;
  if (interval.toSec() > dt) {

    mpc_total_delay += interval.toSec() - dt;
    ROS_WARN_THROTTLE(10.0, "[MpcTracker] MPC is Running %2.2f%% slower than it should.", 100 * mpc_total_delay / (ros::Time::now() - mpc_start_time).toSec());
  }

  mpc_computed_ = true;

  if (publish_debug_trajectory) {

    /* publish mpc reference //{ */

    {
      geometry_msgs::PoseArray debug_trajectory_out;
      debug_trajectory_out.header.stamp    = ros::Time::now();
      debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

      {
        std::scoped_lock lock(mutex_predicted_trajectory);

        for (int i = 0; i < horizon_len_; i++) {

          geometry_msgs::Pose newPose;

          newPose.position.x = des_x_filtered(i, 0);
          newPose.position.y = des_y_filtered(i, 0);
          newPose.position.z = des_z_filtered(i, 0);

          tf::Quaternion orientation;
          orientation.setEuler(0, 0, des_yaw_trajectory_(i));
          newPose.orientation.x = orientation.x();
          newPose.orientation.y = orientation.y();
          newPose.orientation.z = orientation.z();
          newPose.orientation.w = orientation.w();

          debug_trajectory_out.poses.push_back(newPose);
        }
      }

      try {
        debug_mpc_reference_publisher.publish(debug_trajectory_out);
      }
      catch (...) {
        ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", debug_mpc_reference_publisher.getTopic().c_str());
      }
    }

    //}

    /* publish predicted future //{ */

    {
      geometry_msgs::PoseArray debug_trajectory_out;
      debug_trajectory_out.header.stamp    = ros::Time::now();
      debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

      {
        std::scoped_lock lock(mutex_predicted_trajectory);

        for (int i = 0; i < horizon_len_; i++) {

          geometry_msgs::Pose newPose;

          newPose.position.x = predicted_future_trajectory(i * n);
          newPose.position.y = predicted_future_trajectory(i * n + 4);
          newPose.position.z = predicted_future_trajectory(i * n + 8);

          tf::Quaternion orientation;
          orientation.setEuler(0, 0, predicted_future_yaw_trajectory(i * n));
          newPose.orientation.x = orientation.x();
          newPose.orientation.y = orientation.y();
          newPose.orientation.z = orientation.z();
          newPose.orientation.w = orientation.w();

          debug_trajectory_out.poses.push_back(newPose);
        }
      }

      try {
        debug_predicted_trajectory_publisher.publish(debug_trajectory_out);
      }
      catch (...) {
        ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", debug_predicted_trajectory_publisher.getTopic().c_str());
      }
    }

    //}
  }

  if (started_with_invalid) {
    mpc_result_invalid = false;
    ROS_INFO("[MpcTracker]: calculated first MPC result after invalidation, x %f, y %f, hor1x %f, hor1y %f", x_(0, 0), x_(4, 0), des_x_trajectory_(0, 0),
             des_y_trajectory_(0, 0));
  }
}

//}

/* //{ futureTrajectoryTimer() */

void MpcTracker::futureTrajectoryTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  if (!is_initialized)
    return;

  mrs_lib::Routine profiler_routine = profiler.createRoutine("futureTrajectoryTimer", predicted_trajectory_publish_rate, 0.01, event);

  if (future_was_predicted) {

    future_trajectory_out.points.clear();
    future_trajectory_out.stamp               = ros::Time::now();
    future_trajectory_out.uav_name            = uav_name_;
    future_trajectory_out.priority            = my_uav_priority;
    future_trajectory_out.collision_avoidance = collision_avoidance_enabled_;

    // fill the trajectory
    {
      std::scoped_lock lock(mutex_predicted_trajectory);

      for (int i = 0; i < horizon_len_; i++) {

        mrs_msgs::FuturePoint newPoint;

        newPoint.x = predicted_future_trajectory(i * n);
        newPoint.y = predicted_future_trajectory(i * n + 4);
        newPoint.z = predicted_future_trajectory(i * n + 8);

        future_trajectory_out.points.push_back(newPoint);
      }
    }

    try {
      predicted_trajectory_publisher.publish(future_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", predicted_trajectory_publisher.getTopic().c_str());
    }

    future_trajectory_esp_out.points.clear();
    future_trajectory_esp_out.stamp               = ros::Time::now();
    future_trajectory_esp_out.uav_name            = uav_name_;
    future_trajectory_esp_out.priority            = my_uav_priority;
    future_trajectory_esp_out.collision_avoidance = collision_avoidance_enabled_;

    // fill the trajectory
    {
      std::scoped_lock lock(mutex_predicted_trajectory);

      for (int i = 0; i < horizon_len_; i++) {

        mrs_msgs::FuturePointInt8 newPoint;

        newPoint.x = predicted_future_trajectory(i * n);
        newPoint.y = predicted_future_trajectory(i * n + 4);
        newPoint.z = predicted_future_trajectory(i * n + 8);

        future_trajectory_esp_out.points.push_back(newPoint);
      }
    }

    try {
      predicted_trajectory_esp_publisher.publish(future_trajectory_esp_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", predicted_trajectory_esp_publisher.getTopic().c_str());
    }
  }
}

//}

/* hoverTimer() //{ */

void MpcTracker::hoverTimer(const ros::TimerEvent &event) {

  mrs_lib::ScopeUnset unset_running(running_mpc_timer);

  std::scoped_lock lock(mutex_x);

  mrs_lib::Routine profiler_routine = profiler.createRoutine("hoverTimer", 10, 0.01, event);

  setRelativeGoal(0, 0, 0, 0, false);

  if (fabs(x_(1, 0)) < 0.1 && fabs(x_(5, 0)) < 0.1 && fabs(x_(9, 0)) < 0.1) {

    toggleHover(false);

    ROS_INFO("[MpcTracker]: hoverTimer: speed is low, stopping hover timer");
  }
}

//}

// --------------------------------------------------------------
// |                       Other routines                       |
// --------------------------------------------------------------

/* toggleHover() //{ */

void MpcTracker::toggleHover(bool in) {

  if (in == false && hovering_in_progress) {

    ROS_DEBUG("[MpcTracker]: Stoppping hover timer");

    while (running_hover_timer) {

      ROS_DEBUG("[MpcTracker]: the hover is in the middle of an iteration, waiting for it to finish");
      ros::Duration wait(0.01);
      wait.sleep();
    }

    hover_timer.stop();

    hovering_in_progress = false;

  } else if (in == true && !hovering_in_progress) {

    ROS_DEBUG("[MpcTracker]: Starting hover timer");

    hovering_in_progress = true;

    hover_timer.start();
  }
}

//}

/* interpolateAngles() //{ */

double MpcTracker::interpolateAngles(const double a1, const double a2, const double coeff) {

  // interpolate the yaw
  Eigen::Vector3d axis = Eigen::Vector3d(0, 0, 1);

  Eigen::Quaterniond quat1 = Eigen::Quaterniond(Eigen::AngleAxis<double>(a1, axis));
  Eigen::Quaterniond quat2 = Eigen::Quaterniond(Eigen::AngleAxis<double>(a2, axis));

  quat_t new_quat = quat1.slerp(coeff, quat2);

  Eigen::Vector3d vecx = new_quat * Eigen::Vector3d(1, 0, 0);

  return atan2(vecx[1], vecx[0]);
}

//}

}  // namespace mpc_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::mpc_tracker::MpcTracker, mrs_uav_manager::Tracker)
