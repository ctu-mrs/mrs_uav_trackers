#include <ros/ros.h>

#include <math.h>
#include <cmath>
#include <mutex>
#include <tf/transform_datatypes.h>
#include <eigen3/Eigen/Eigen>

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

using namespace Eigen;

namespace mrs_trackers
{

//{ class MpcTracker

class MpcTracker : public mrs_mav_manager::Tracker {
public:
  MpcTracker(void);

  virtual void initialize(const ros::NodeHandle &parent_nh);
  virtual bool activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  virtual void deactivate(void);

  virtual const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  virtual const mrs_msgs::TrackerStatus::Ptr        getStatus();
  virtual const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr &cmd);

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
  ros::Publisher pub_cmd_pose_;
  ros::Publisher pub_cmd_velocity_;
  ros::Publisher pub_cmd_acceleration_;
  ros::Publisher pub_setpoint_pose_;
  ros::Publisher pub_diagnostics_;
  ros::Publisher pub_debug_trajectory_;  // publishes the trajectory that was just set... because service

  nav_msgs::Odometry odom_;  // odometry

  bool debug_;

  mrs_msgs::PositionCommand position_cmd_;  // message being returned

  bool      odom_set_, is_active, is_initialized;
  double    kx_[3], kv_[3];
  double    new_kx_[3], new_kv_[3];
  double    cur_yaw_;
  ros::Time odomLastTime;

  // variables for yaw tracker
  double max_yaw_rate_old;
  double yaw_gain;

  // safety area
  mrs_lib::ConvexPolygon *safety_area;
  bool                    use_safety_area;

  // variables regarding the MPC controller
  int    n;            // number of states
  int    m;            // number of inputs
  int    n_yaw;        // number of states - yaw
  int    m_yaw;        // number of inputs - yaw
  int    horizon_len;  // lenght of the prediction horizon
  double minimum_collison_free_altitude = 0;
  double last_offset                    = 0;
  double max_horizontal_speed;
  double max_horizontal_acceleration;
  double max_vertical_ascending_acceleration;
  double max_vertical_ascending_speed;
  double max_vertical_ascending_jerk;
  double max_vertical_descending_speed;
  double max_vertical_descending_acceleration;
  double max_vertical_descending_jerk;
  double max_yaw_rate;
  double max_yaw_acceleration;
  double max_yaw_jerk;
  double max_altitude_;
  double min_altitude_;

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
  MatrixXd A;        // system matrix for virtual UAV
  MatrixXd B;        // input matrix for virtual UAV

  MatrixXd A_yaw;  // system matrix for yaw
  MatrixXd B_yaw;  // input matrix for yaw

  // trajectories
  MatrixXd des_x_trajectory;                  // trajectory reference over the prediction horizon
  MatrixXd des_y_trajectory;                  // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory;                  // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory_offset;           // trajectory reference over the prediction horizon
  MatrixXd des_yaw_trajectory;                // trajectory reference over the prediction horizon
  MatrixXd des_x_filtered;                    // filtered trajectory reference over the horizon
  MatrixXd des_y_filtered;                    // filtered trajectory reference over the horizon
  MatrixXd des_z_filtered;                    // filtered trajectory reference over the horizon
  VectorXd cvxgen_horizontal_vel_constraint;  // velocity constraint for the XY cvxgen solver
  VectorXd cvxgen_horizontal_acc_constraint;  // acceleration constraint for the XY cvxgen solver
  VectorXd des_x_whole_trajectory;            // long trajectory reference
  VectorXd des_y_whole_trajectory;            // long trajectory reference
  VectorXd des_z_whole_trajectory;            // long trajectory reference
  VectorXd des_yaw_whole_trajectory;          // long trajectory reference
  bool     use_yaw_in_trajectory;

  bool tracking_trajectory_;  // are we currently tracking a trajectory
  int  trajectory_idx;        // index in the currently tracked trajectory
  int  trajectory_size;       // size of the tracked trajectory
  int  max_trajectory_size;   // maximum length of the trajectory
  bool trajectory_set_;       // true if trajectory was set
  int  trajectory_count;      // counting number of trajectories uploaded to the tracker
  bool loop;                  // whether we are looping the trajectory

  MatrixXd reference;      // XYZ reference for the controller
  MatrixXd reference_yaw;  // yaw reference for the controlle
  MatrixXd x;              // current state of the uav
  MatrixXd x_yaw;          // current yaw of the uav

  // yaw tracker
  double yaw_rate;
  double yaw;
  double desired_yaw;

  // predicting the future
  MatrixXd                 predicted_future_trajectory;
  std::string              uav_name_;
  std::vector<std::string> other_drone_names_;
  std::map<std::string, mrs_msgs::FutureTrajectory> other_drones_trajectories;
  std::vector<ros::Subscriber> other_drones_subscribers;
  ros::Publisher               predicted_trajectory_publisher;
  ros::Publisher               debug_predicted_trajectory_publisher;
  bool                         mrs_collision_avoidance;
  double                       predicted_trajectory_publish_rate;
  double                       mrs_collision_avoidance_radius;
  double                       mrs_collision_avoidance_correction;
  std::mutex                   mutex_predicted_trajectory;
  std::string                  predicted_trajectory_topic;
  void callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg);
  bool   future_was_predicted;
  double mrs_collision_avoidance_altitude_threshold;
  double checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  int       uav_num_name;
  double    collision_free_altitude;
  ros::Time avoiding_collision_time;
  ros::Time being_avoided_time;
  bool callbackToggleCollisionAvoidance(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  double collision_horizontal_acceleration_coef, collision_horizontal_speed_coef;
  int    collision_slow_down_before;
  double collision_slowing_hysteresis;
  int    earliest_collision_idx;
  double collision_trajectory_timeout;

private:
  ros::Timer future_trajectory_timer;
  void futureTrajectoryTimer(const ros::TimerEvent &event);

private:
  ros::Timer diagnostics_timer;
  double     diagnostics_rate;
  void diagnosticsTimer(const ros::TimerEvent &event);

private:
  MatrixXd   outputTrajectory;
  std::mutex x_mutex, trajectory_setpoint_mutex, des_yaw_mutex, des_trajectory_mutex;

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
  void mpcTimer(const ros::TimerEvent &event);
  void pos_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void callbackDesiredPositionRelative(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void callbackDesiredTrajectory(const mrs_msgs::TrackerTrajectory::ConstPtr &msg);
  bool callbackSetTrajectory(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res);
  bool callbackStartTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool callbackStopTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool callbackResumeTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool callbackFlyToTrajectoryStart(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void odom_cb(const nav_msgs::OdometryConstPtr &msg);
  void calculateMPC();
  void setTrajectory(float x, float y, float z, float yaw);
  bool loadTrajectory(const mrs_msgs::TrackerTrajectory &msg, std::string &message);
  double   checkTrajectoryForCollisions();
  void     filterYawReference(void);
  VectorXd integrate(VectorXd &in, double dt, double integrational_const);
  bool setRelativeGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool goTo_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool callbackTriggerFailsafe(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void callbackRadioControl(const mavros_msgs::RCInConstPtr &msg);
  bool   triggerFailsafe();
  void   publishDiagnostics();
  double triangleArea(Eigen::VectorXd a, Eigen::VectorXd b, Eigen::VectorXd c);
  bool pointInBoundary(Eigen::MatrixXd boundary, double px, double py);

  bool callbackSetYaw(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  void desired_yaw_cmd_cb(const mrs_msgs::TrackerPoint::ConstPtr &msg);

private:
  mrs_lib::Profiler *profiler;
  mrs_lib::Routine * routine_mpc_timer;
};

MpcTracker::MpcTracker(void) : odom_set_(false), is_active(false), is_initialized(false), mpc_computed_(false) {
}

//}

// | -------------- tracker's interface routines -------------- |

//{ initialize()

void MpcTracker::initialize(const ros::NodeHandle &parent_nh) {

  ros::NodeHandle nh_(parent_nh, "mpc_tracker");

  ros::Time::waitForValid();

  failsafe_triggered = false;

  std::vector<double> tempList, tempList2, UvaluesList;
  int                 tempIdx;

  nh_.param("debug", debug_, false);

  // safety area
  nh_.param("use_safety_area", use_safety_area, false);
  // load the main system matrix
  nh_.getParam("safety_area", tempList);

  // check if the safety area has odd number of numbers (x, y coordinates)
  if ((tempList.size() % 2) == 1) {

    ROS_ERROR("[MpcTracker]: Safety area is not correctly defined!, Exitting...");
    ros::shutdown();
  }

  // how many points are there in the safety area?
  int safety_area_size = tempList.size() / 2;

  MatrixXd tempMatrix = MatrixXd::Zero(safety_area_size, 2);
  tempIdx             = 0;
  for (int i = 0; i < safety_area_size; i++) {
    for (int j = 0; j < 2; j++) {
      tempMatrix(i, j) = tempList[tempIdx++];
    }
  }

  try {

    safety_area = new mrs_lib::ConvexPolygon(tempMatrix);
  }
  catch (mrs_lib::ConvexPolygon::WrongNumberOfVertices) {

    ROS_ERROR("[MpcTracker]: Exception caught. Wrong number of vertices was supplied to create the safety area.");
    ros::shutdown();
  }
  catch (mrs_lib::ConvexPolygon::PolygonNotConvexException) {

    ROS_ERROR("[MpcTracker]: Exception caught. Polygon supplied to create the safety area is not convex.");
    ros::shutdown();
  }
  catch (mrs_lib::ConvexPolygon::WrongNumberOfColumns) {
    ROS_ERROR("[MpcTracker]: Exception caught. Wrong number of columns was supplied to the safety area.");
  }

  // load parameters for yaw_tracker
  nh_.param("yawTracker/maxYawRate", max_yaw_rate_old, 0.0);
  nh_.param("yawTracker/yawGain", yaw_gain, 0.0);
  desired_yaw = 0;

  // load the dynamicall model parameters
  nh_.param("dynamicalModel/numberOfStates", n, -1);
  nh_.param("dynamicalModel/numberOfInputs", m, -1);

  // load the dynamicall model parameters
  nh_.param("yawModel/numberOfStates", n_yaw, -1);
  nh_.param("yawModel/numberOfInputs", m_yaw, -1);

  // failsafe
  nh_.param("use_rc_failsafe", use_rc_failsafe, false);
  nh_.param("rc_failsafe_threshold", rc_failsafe_threshold, 2000);
  nh_.param("rc_failsafe_channel", rc_failsafe_channel, 9);
  rc_failsafe_time = ros::Time::now();

  if (use_rc_failsafe) {
    ROS_INFO("[MpcTracker]: RC Failsafe ON, channel = %d, threshold = %d", rc_failsafe_channel, rc_failsafe_threshold);
  }

  // load the main system matrix
  nh_.getParam("dynamicalModel/A", tempList);
  A       = MatrixXd::Zero(n, n);
  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A(i, j) = tempList[tempIdx++];
    }
  }

  // load the input matrix
  nh_.getParam("dynamicalModel/B", tempList);
  B       = MatrixXd::Zero(n, m);
  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      B(i, j) = tempList[tempIdx++];
    }
  }

  // load the yaw system matrix
  nh_.getParam("yawModel/A", tempList);
  A_yaw   = MatrixXd::Zero(n_yaw, n_yaw);
  tempIdx = 0;
  for (int i = 0; i < n_yaw; i++) {
    for (int j = 0; j < n_yaw; j++) {
      A_yaw(i, j) = tempList[tempIdx++];
    }
  }

  // load the yaw input matrix
  nh_.getParam("yawModel/B", tempList);
  B_yaw   = MatrixXd::Zero(n_yaw, m_yaw);
  tempIdx = 0;
  for (int i = 0; i < n_yaw; i++) {
    for (int j = 0; j < m_yaw; j++) {
      B_yaw(i, j) = tempList[tempIdx++];
    }
  }

  // load the MPC parameters
  nh_.param("cvxgenMpc/horizon_len", horizon_len, -1);
  nh_.param("cvxgenMpc/maxTrajectorySize", max_trajectory_size, -1);

  nh_.param("cvxgenMpc/dt", dt, -1.0);
  nh_.param("cvxgenMpc/dt2", dt2, -1.0);

  nh_.param("cvxgenMpc/maxHorizontalSpeed", max_horizontal_speed, 0.0);
  nh_.param("cvxgenMpc/maxHorizontalAcceleration", max_horizontal_acceleration, 0.0);
  nh_.param("cvxgenMpc/maxHorizontalJerk", max_horizontal_jerk, 0.0);

  nh_.param("cvxgenMpc/maxVerticalAscendingSpeed", max_vertical_ascending_speed, 0.0);
  nh_.param("cvxgenMpc/maxVerticalAscendingAcceleration", max_vertical_ascending_acceleration, 0.0);
  nh_.param("cvxgenMpc/maxVerticalAscendingJerk", max_vertical_ascending_jerk, 0.0);
  nh_.param("cvxgenMpc/maxVerticalDescendingSpeed", max_vertical_descending_speed, 0.0);
  nh_.param("cvxgenMpc/maxVerticalDescendingAcceleration", max_vertical_descending_acceleration, 0.0);
  nh_.param("cvxgenMpc/maxVerticalDescendingJerk", max_vertical_descending_jerk, 0.0);

  nh_.param("cvxgenMpc/maxYawRate", max_yaw_rate, 0.0);
  nh_.param("cvxgenMpc/maxYawAcceleration", max_yaw_acceleration, 0.0);
  nh_.param("cvxgenMpc/maxYawAcceleration", max_yaw_jerk, 0.0);

  nh_.param("cvxgenMpc/maxAltitude", max_altitude_, 0.0);
  nh_.param("cvxgenMpc/minAltitude", min_altitude_, 1.0);

  nh_.param("diagnostics_rate", diagnostics_rate, 1.0);
  nh_.param("diagnostic_tracking_threshold", diagnostic_tracking_threshold, 1.0);

  ROS_INFO(
      "MPC parameters: horizon_len: %d, max_vertical_ascending_speed: %2.1f, max_horizontal_speed: %2.1f, max_horizontal_acceleration: "
      "%2.1f, max_vertical_ascending_acceleration: %2.1f, max_vertical_descending_speed: %2.1f, max_vertical_descending_acceleration: %2.1f, ",
      horizon_len, max_vertical_ascending_speed, max_horizontal_speed, max_horizontal_acceleration, max_vertical_ascending_acceleration,
      max_vertical_descending_speed, max_vertical_descending_acceleration);

  // CVXGEN wrappers
  bool verbose;

  nh_.param("cvxWrapper/verbose", verbose, false);
  nh_.param("cvxWrapper/maxNumOfIterations", max_iters_XY, 25);
  nh_.getParam("cvxWrapper/Q", tempList);
  nh_.getParam("cvxWrapper/R", tempList2);

  cvx_x = new CvxWrapper(verbose, max_iters_XY, tempList, tempList2, dt, dt2, 0);
  cvx_y = new CvxWrapper(verbose, max_iters_XY, tempList, tempList2, dt, dt2, 1);

  nh_.param("cvxWrapperZ/verbose", verbose, false);
  nh_.param("cvxWrapperZ/maxNumOfIterations", max_iters_Z, 25);
  nh_.getParam("cvxWrapperZ/Q", tempList);
  nh_.getParam("cvxWrapperZ/R", tempList2);

  cvx_z = new CvxWrapper(verbose, max_iters_Z, tempList, tempList2, dt, dt2, 2);

  nh_.param("cvxWrapperYaw/verbose", verbose, false);
  nh_.param("cvxWrapperYaw/maxNumOfIterations", max_iters_YAW, 25);
  nh_.getParam("cvxWrapperYaw/Q", tempList);
  nh_.getParam("cvxWrapperYaw/R", tempList2);

  cvx_yaw = new CvxWrapper(verbose, max_iters_YAW, tempList, tempList2, dt, dt2, 0);

  ROS_INFO("[MpcTracker]: MPC Tracker initiated with system parameters: n: %d, m: %d, dt: %0.3f, dt2: %0.3f", n, m, dt, dt2);
  ROS_INFO_STREAM("\nA:\n" << A << "\nB:\n" << B);

  // initialize other matrices
  x                = MatrixXd::Zero(n, 1);
  x_yaw            = MatrixXd::Zero(3, 1);
  outputTrajectory = MatrixXd::Zero(horizon_len * n, 1);

  // trajectory tracking
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

  des_x_trajectory        = MatrixXd::Zero(horizon_len, 1);
  des_y_trajectory        = MatrixXd::Zero(horizon_len, 1);
  des_z_trajectory        = MatrixXd::Zero(horizon_len, 1);
  des_z_trajectory_offset = MatrixXd::Zero(horizon_len, 1);
  des_yaw_trajectory      = MatrixXd::Zero(horizon_len, 1);

  des_x_filtered = MatrixXd::Zero(horizon_len, 1);
  des_y_filtered = MatrixXd::Zero(horizon_len, 1);
  des_z_filtered = MatrixXd::Zero(horizon_len, 1);

  // subscriber for desired trajectory
  sub_trajectory_ = nh_.subscribe("desired_trajectory", 1, &MpcTracker::callbackDesiredTrajectory, this, ros::TransportHints().tcpNoDelay());

  if (debug_) {
    pub_debug_trajectory_ = nh_.advertise<mrs_msgs::TrackerTrajectory>("debug_set_trajectory", 1);
  }

  // service for desired trajectory
  ser_set_trajectory_ = nh_.advertiseService("set_trajectory", &MpcTracker::callbackSetTrajectory, this);

  // subscriber for rc transmitter
  sub_rc_ = nh_.subscribe("rc_in", 1, &MpcTracker::callbackRadioControl, this, ros::TransportHints().tcpNoDelay());

  // service for starting trajectory following
  ser_start_trajectory_following_ = nh_.advertiseService("start_trajectory_following", &MpcTracker::callbackStartTrajectoryFollowing, this);

  // service for stopping trajectory following
  ser_stop_trajectory_following_ = nh_.advertiseService("stop_trajectory_following", &MpcTracker::callbackStopTrajectoryFollowing, this);

  // service for resuming trajectory following
  ser_resume_trajectory_following_ = nh_.advertiseService("resume_trajectory_following", &MpcTracker::callbackResumeTrajectoryFollowing, this);

  // service for flying to the trajectory start point
  ser_fly_to_trajectory_start_ = nh_.advertiseService("fly_to_trajectory_start", &MpcTracker::callbackFlyToTrajectoryStart, this);

  // service for triggering failsafe
  failsafe_trigger_service_cmd_ = nh_.advertiseService("failsafe", &MpcTracker::callbackTriggerFailsafe, this);

  // publishers for debugging
  pub_cmd_pose_         = nh_.advertise<nav_msgs::Odometry>("cmd_pose", 1);
  pub_cmd_velocity_     = nh_.advertise<geometry_msgs::Vector3>("cmd_velocity", 1);
  pub_cmd_acceleration_ = nh_.advertise<geometry_msgs::Vector3>("md_acceleration", 1);
  pub_diagnostics_      = nh_.advertise<mrs_msgs::TrackerDiagnostics>("diagnostics", 1);

  // publisher for the current setpoint
  pub_setpoint_pose_ = nh_.advertise<nav_msgs::Odometry>("setpoint_pose", 1);

  // collision avoidance
  nh_.param("uav_name", uav_name_, std::string());

  if (uav_name_.empty()) {
    ROS_ERROR("[MpcTracker]: uav_name has not been specified!");
    ros::shutdown();
  }

  // extract the numerical name
  sscanf(uav_name_.c_str(), "uav%d", &uav_num_name);
  ROS_INFO("[MpcTracker]: Numerical ID of this UAV is %d", uav_num_name);

  nh_.getParam("mrs_collision_avoidance/drone_names", other_drone_names_);

  // exclude this drone from the list
  std::vector<std::string>::iterator it = other_drone_names_.begin();
  while (it != other_drone_names_.end()) {

    std::string temp_str = *it;

    int other_drone_id;
    sscanf(temp_str.c_str(), "uav%d", &other_drone_id);

    if (other_drone_id == uav_num_name) {

      other_drone_names_.erase(it);
      continue;
    }

    it++;
  }

  nh_.param("mrs_collision_avoidance/enable", mrs_collision_avoidance, false);

  // create publisher for predicted trajectory
  predicted_trajectory_publisher       = nh_.advertise<mrs_msgs::FutureTrajectory>("predicted_trajectory", 1);
  debug_predicted_trajectory_publisher = nh_.advertise<geometry_msgs::PoseArray>("predicted_trajectory_debugging", 1);

  // preallocate future trajectory
  predicted_future_trajectory = MatrixXd::Zero(horizon_len * n, 1);

  collision_free_altitude = 0;
  avoiding_collision_time = ros::Time::now();
  being_avoided_time      = ros::Time::now();
  future_was_predicted    = false;
  earliest_collision_idx  = INT_MAX;

  nh_.param("predicted_trajectory_topic", predicted_trajectory_topic, std::string());

  nh_.param("mrs_collision_avoidance/predicted_trajectory_publish_rate", predicted_trajectory_publish_rate, 1.0);
  nh_.param("mrs_collision_avoidance/correction", mrs_collision_avoidance_correction, 3.0);
  nh_.param("mrs_collision_avoidance/radius", mrs_collision_avoidance_radius, 3.0);
  nh_.param("mrs_collision_avoidance/altitude_threshold", mrs_collision_avoidance_altitude_threshold, 2.5);
  nh_.param("mrs_collision_avoidance/collision_horizontal_speed_coef", collision_horizontal_speed_coef, 1.0);
  nh_.param("mrs_collision_avoidance/collision_horizontal_acceleration_coef", collision_horizontal_acceleration_coef, 1.0);
  nh_.param("mrs_collision_avoidance/collision_slow_down_before", collision_slow_down_before, 0);
  nh_.param("mrs_collision_avoidance/collision_slowing_hysteresis", collision_slowing_hysteresis, 0.0);
  nh_.param("mrs_collision_avoidance/trajectory_timeout", collision_trajectory_timeout, 1.0);

  // collision avoidance toggle service
  collision_avoidance_service = nh_.advertiseService("collision_avoidance", &MpcTracker::callbackToggleCollisionAvoidance, this);

  if (predicted_trajectory_topic.empty()) {
    ROS_ERROR("[MpcTracker]: You need to define predicted trajectory topic name in the launch file.");
    ros::shutdown();
  }

  // create subscribers on other drones diagnostics
  for (unsigned long i = 0; i < other_drone_names_.size(); i++) {

    std::string topic_name = std::string("/") + other_drone_names_[i] + std::string("/") + predicted_trajectory_topic;

    ROS_INFO("[MpcTracker]: subscribing to %s", topic_name.c_str());

    other_drones_subscribers.push_back(nh_.subscribe(topic_name, 1, &MpcTracker::callbackOtherMavTrajectory, this, ros::TransportHints().tcpNoDelay()));
  }

  is_initialized = true;

  // --------------------------------------------------------------
  // |                          profiler                          |
  // --------------------------------------------------------------

  profiler          = new mrs_lib::Profiler(nh_, "MpcTracker");
  routine_mpc_timer = profiler->registerRoutine("mpc_tracker_loop", int(1.0 / dt), 0.002);

  // --------------------------------------------------------------
  // |                           timers                           |
  // --------------------------------------------------------------

  future_trajectory_timer = nh_.createTimer(ros::Rate(predicted_trajectory_publish_rate), &MpcTracker::futureTrajectoryTimer, this);
  diagnostics_timer       = nh_.createTimer(ros::Rate(diagnostics_rate), &MpcTracker::diagnosticsTimer, this);
  mpc_timer               = nh_.createTimer(ros::Rate(1.0 / dt), &MpcTracker::mpcTimer, this);

  ROS_INFO("[MpcTracker]: MpcTracker initialized");
}

//}

//{ activate()

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
    x(0, 0) = odom_.pose.pose.position.x;
    x(1, 0) = odom_.twist.twist.linear.x;
    x(2, 0) = 0;

    x(3, 0) = odom_.pose.pose.position.y;
    x(4, 0) = odom_.twist.twist.linear.y;
    x(5, 0) = 0;

    x(6, 0) = odom_.pose.pose.position.z;
    x(7, 0) = odom_.twist.twist.linear.z;
    x(8, 0) = 0;

    x_yaw(0, 0) = cur_yaw_;
    x_yaw(1, 0) = 0;
    x_yaw(2, 0) = 0;

    yaw = cur_yaw_;
    x_mutex.unlock();
  }

  failsafe_triggered   = false;
  tracking_trajectory_ = false;

  // if we got a setpoint with the actiovation command
  if (cmd && odom_set_) {

    des_yaw_mutex.lock();
    desired_yaw = cmd->yaw;
    des_yaw_mutex.unlock();

    setTrajectory(cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);

    ROS_INFO("[MpcTracker]: MPC tracker activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z,
             cmd->yaw);
    is_active = true;
  }

  // if we dont, stay where you are
  else if (odom_set_) {

    setTrajectory(odom_.pose.pose.position.x, odom_.pose.pose.position.y, odom_.pose.pose.position.z, tf::getYaw(odom_.pose.pose.orientation));
    position_cmd_.yaw = tf::getYaw(odom_.pose.pose.orientation);

    ROS_INFO("[MpcTracker]: MPC tracker activated with no setpoint, staying where we are.");
    is_active = true;
  }

  mpc_start_time  = ros::Time::now();
  mpc_total_delay = 0;

  publishDiagnostics();

  // can return false
  return is_active;
}

//}

//{ deactivate()

void MpcTracker::deactivate(void) {

  is_active = false;
  odom_set_ = false;

  // turn off trajectory tracking
  des_trajectory_mutex.lock();
  tracking_trajectory_ = false;
  trajectory_idx       = 0;
  des_trajectory_mutex.unlock();

  ROS_INFO("[MpcTracker]: MPC tracker deactivated");

  publishDiagnostics();
}

//}

//{ update()

const mrs_msgs::PositionCommand::ConstPtr MpcTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // copy the odometry from the message
  odom_    = *msg;
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
    if (!std::isfinite(x(i, 0)))
      arefinite = false;
  }

  if (arefinite) {
    x_mutex.lock();
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

  if (std::isfinite(yaw_rate) && std::isfinite(yaw)) {
    // set the yaw output - PD controller
    /* position_cmd_.yaw_dot = yaw_rate; */
    /* position_cmd_.yaw     = yaw; */
  } else {
    ROS_INFO("[MpcTracker]: Output YAW is not finite!");
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
  nav_msgs::Odometry outPose;

  outPose.header.stamp    = ros::Time::now();
  outPose.header.frame_id = "local_origin";

  outPose.pose.pose.position = position_cmd_.position;
  tf::Quaternion orientation;
  orientation.setEuler(0, 0, yaw);
  outPose.pose.pose.orientation.x = orientation.x();
  outPose.pose.pose.orientation.y = orientation.y();
  outPose.pose.pose.orientation.z = orientation.z();
  outPose.pose.pose.orientation.w = orientation.w();

  outPose.twist.twist.linear.x = position_cmd_.velocity.x;
  outPose.twist.twist.linear.y = position_cmd_.velocity.y;
  outPose.twist.twist.linear.z = position_cmd_.velocity.z;

  try {
    pub_cmd_pose_.publish(outPose);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_cmd_pose_.getTopic().c_str());
  }

  // publish velocity for debugging purposes
  geometry_msgs::Vector3 outVelocity;

  outVelocity.x = position_cmd_.velocity.x;
  outVelocity.y = position_cmd_.velocity.y;
  outVelocity.z = position_cmd_.velocity.z;

  try {
    pub_cmd_velocity_.publish(outVelocity);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_cmd_velocity_.getTopic().c_str());
  }

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
  nav_msgs::Odometry outSetpoint;

  outSetpoint.header.stamp    = ros::Time::now();
  outSetpoint.header.frame_id = "local_origin";

  outSetpoint.pose.pose.position.x = des_x_trajectory(0, 0);
  outSetpoint.pose.pose.position.y = des_y_trajectory(0, 0);
  outSetpoint.pose.pose.position.z = des_z_trajectory(0, 0);

  orientation.setEuler(0, 0, desired_yaw);
  outSetpoint.pose.pose.orientation.x = orientation.x();
  outSetpoint.pose.pose.orientation.y = orientation.y();
  outSetpoint.pose.pose.orientation.z = orientation.z();
  outSetpoint.pose.pose.orientation.w = orientation.w();

  try {
    pub_setpoint_pose_.publish(outSetpoint);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_setpoint_pose_.getTopic().c_str());
  }

  // u have to return a position command
  // can set the jerk to 0
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
}

//}

//{ getStatus()

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

//{ enableCallbacks()

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

// | -------------- setpoint topics and services -------------- |

//{ goTo() service

const mrs_msgs::Vec4Response::ConstPtr MpcTracker::goTo(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";

  } else if (!setGoal(cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3], true)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
  } else {

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Going to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3]);
    res.message = tempStr;
  }

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

//{ goTo() topic

bool MpcTracker::goTo(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  if (!failsafe_triggered) {

    setGoal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
  }

  return true;
}

//}

//{ goToRelative() service

const mrs_msgs::Vec4Response::ConstPtr MpcTracker::goToRelative(const mrs_msgs::Vec4Request::ConstPtr &cmd) {

  mrs_msgs::Vec4Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  } else if (!setRelativeGoal(cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3], true)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
  } else {

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Going to relative x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->goal[0], cmd->goal[1], cmd->goal[2], cmd->goal[3]);
    res.message = tempStr;
  }

  return mrs_msgs::Vec4Response::ConstPtr(new mrs_msgs::Vec4Response(res));
}

//}

//{ goToRelative() topic

bool MpcTracker::goToRelative(const mrs_msgs::TrackerPointStampedConstPtr &msg) {

  if (!failsafe_triggered) {

    setRelativeGoal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
  }

  return true;
}

//}

//{ goToAltitude() service

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::goToAltitude(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";

  } else if (!setGoal(x(0, 0), x(3, 0), cmd->goal, x_yaw(0, 0), false)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
  } else {

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Going to altitude %3.2f", cmd->goal);
    res.message = tempStr;
  }

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ goToAltitude() topic

bool MpcTracker::goToAltitude(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    setGoal(x(0, 0), x(3, 0), msg->data, x_yaw(0, 0), false);
  }

  return true;
}

//}

//{ setYaw() service

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::setYaw(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  if (tracking_trajectory_) {

    des_trajectory_mutex.lock();
    {
      for (int i = 0; i < horizon_len; i++) {
        des_yaw_trajectory(i, 0) = mrs_trackers_commons::validateYawSetpoint(cmd->goal);
      }
    }
    des_trajectory_mutex.unlock();

  } else {

    // TODO: should set goal when flying to a setpoint
    if (!setGoal(x(0, 0), x(3, 0), x(6, 0), mrs_trackers_commons::validateYawSetpoint(cmd->goal), true)) {

      res.success = false;
      res.message = "Cannot set the goal. It is probably outside of the safety area.";
    }
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->goal);
  res.message = tempStr;

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ setYaw() topic

bool MpcTracker::setYaw(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    if (tracking_trajectory_) {

      des_trajectory_mutex.lock();
      {
        for (int i = 0; i < horizon_len; i++) {
          des_yaw_trajectory(i, 0) = mrs_trackers_commons::validateYawSetpoint(msg->data);
        }
      }
      des_trajectory_mutex.unlock();

    } else {

      // TODO: should set goal when flying to a setpoint
      setGoal(x(0, 0), x(3, 0), x(6, 0), mrs_trackers_commons::validateYawSetpoint(msg->data), true);
    }
  }

  return true;
}

//}

//{ setYawRelative() service

const mrs_msgs::Vec1Response::ConstPtr MpcTracker::setYawRelative(const mrs_msgs::Vec1Request::ConstPtr &cmd) {

  mrs_msgs::Vec1Response res;

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
  }

  if (tracking_trajectory_) {

    des_trajectory_mutex.lock();
    {
      for (int i = 0; i < horizon_len; i++) {
        des_yaw_trajectory(i, 0) += mrs_trackers_commons::validateYawSetpoint(cmd->goal);
      }
    }
    des_trajectory_mutex.unlock();

  } else {

    if (!setGoal(des_x_trajectory(0, 0), des_y_trajectory(0, 0), des_z_trajectory(0, 0),
                 mrs_trackers_commons::validateYawSetpoint(des_yaw_trajectory(0, 0) + cmd->goal), true)) {

      res.success = false;
      res.message = "Cannot set the goal. It is probably outside of the safety area.";
    }
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Setting yaw to %2.2f", cmd->goal);
  res.message = tempStr;

  return mrs_msgs::Vec1Response::ConstPtr(new mrs_msgs::Vec1Response(res));
}

//}

//{ setYawRelative() topic

bool MpcTracker::setYawRelative(const std_msgs::Float64ConstPtr &msg) {

  if (!failsafe_triggered) {

    if (tracking_trajectory_) {

      des_trajectory_mutex.lock();
      {
        for (int i = 0; i < horizon_len; i++) {
          des_yaw_trajectory(i, 0) += mrs_trackers_commons::validateYawSetpoint(msg->data);
        }
      }
      des_trajectory_mutex.unlock();

    } else {

      setGoal(des_x_trajectory(0, 0), des_y_trajectory(0, 0), des_z_trajectory(0, 0),
              mrs_trackers_commons::validateYawSetpoint(des_yaw_trajectory(0, 0) + msg->data), true);
    }
  }

  return true;
}

//}

//{ hover()

const std_srvs::TriggerResponse::ConstPtr MpcTracker::hover(const std_srvs::TriggerRequest::ConstPtr &cmd) {
  return std_srvs::TriggerResponse::Ptr();
}

//}

// --------------------------------------------------------------
// |                  tracker's custom routines                 |
// --------------------------------------------------------------

// | ------------------------ callbacks ----------------------- |

//{ callbackOtherMavTrajectory()

void MpcTracker::callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr &msg) {

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // update the diagnostics
  other_drones_trajectories[msg->uav_name] = temp_trajectory;
}

//}

//{ callbackToggleCollisionAvoidance()

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

//{ callbackRadioControl()

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

//{ callbackStartTrajectoryFollowing()

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

    des_trajectory_mutex.lock();
    tracking_trajectory_ = true;
    trajectory_idx       = 0;
    des_trajectory_mutex.unlock();

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

//{ callbackStopTrajectoryFollowing()

bool MpcTracker::callbackStopTrajectoryFollowing(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (tracking_trajectory_) {

    des_trajectory_mutex.lock();
    tracking_trajectory_ = false;

    x_mutex.lock();
    setTrajectory(x(0, 0), x(3, 0), x(6, 0), x_yaw(0, 0));
    x_mutex.unlock();

    des_trajectory_mutex.unlock();

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

//{ callbackFlyToTrajectoryStart()

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

    if (!setGoal(des_x_whole_trajectory[0], des_y_whole_trajectory[0], des_z_whole_trajectory[0], des_yaw_whole_trajectory[0], true)) {

      res.success = false;
      res.message = "Cannot set the goal. It is probably outside of the safety area.";
      return true;
    }

    if (use_yaw_in_trajectory)
      desired_yaw = des_yaw_whole_trajectory[0];

    des_trajectory_mutex.lock();
    tracking_trajectory_ = false;
    des_trajectory_mutex.unlock();

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

//{ callbackResumeTrajectoryFollowing()

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

      des_trajectory_mutex.lock();
      tracking_trajectory_ = true;
      des_trajectory_mutex.unlock();

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

//{ callbackTriggerFailsafe()

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

//{ callbackSetTrajectory()

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

//{ callbackDesiredTrajectory()

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

//{ triggerFailsafe()

bool MpcTracker::triggerFailsafe() {

  // turn it off
  if (failsafe_triggered) {

    failsafe_triggered = false;
    ROS_WARN("[MpcTracker]: Failsafe OFF");
    return false;

    // turn it on
  } else {

    // turn off potential trajectory tracking
    des_trajectory_mutex.lock();
    tracking_trajectory_ = false;
    trajectory_idx       = 0;
    des_trajectory_mutex.unlock();

    // calculate time needed to stop
    double time_x = 1.2 * x(1, 0) / max_horizontal_acceleration;
    double time_y = 1.2 * x(4, 0) / max_horizontal_acceleration;

    // calculate how far will it move before it stops
    double move_x = (x(1, 0) >= 0 ? 1 : -1) * 0.5 * max_horizontal_acceleration * time_x * time_x;
    double move_y = (x(4, 0) >= 0 ? 1 : -1) * 0.5 * max_horizontal_acceleration * time_y * time_y;

    // stop
    setRelativeGoal(move_x, move_y, 5, 0, true);

    ROS_WARN("[MpcTracker]: Failsafe ON");

    failsafe_triggered = true;

    publishDiagnostics();

    return true;
  }
}

//}

//{ dist()

double dist(const double ax, const double ay, const double bx, const double by) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

//}

//{ checkCollision()

double MpcTracker::checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (dist(ax, ay, bx, by) < mrs_collision_avoidance_radius && fabs(az - bz) < mrs_collision_avoidance_altitude_threshold) {
    return true;

  } else {

    return false;
  }
}

//}

//{ checkTrajectoryForCollisions()

// Check for potential collisions and return the needed altitude offset to avoid other drones
double MpcTracker::checkTrajectoryForCollisions() {

  trajectory_setpoint_mutex.lock();
  bool avoiding       = false;
  bool being_avoided = false;

  if (mrs_collision_avoidance) {

    std::map<std::string, mrs_msgs::FutureTrajectory>::iterator u = other_drones_trajectories.begin();
    while (u != other_drones_trajectories.end()) {
      // is the other's trajectory fresh enought?
      if ((ros::Time::now() - u->second.stamp).toSec() < collision_trajectory_timeout) {
        for (int v = 0; v < horizon_len; v++) {
          // check all points of the trajectory for possible collisions
          if (checkCollision(predicted_future_trajectory(v * 9, 0), predicted_future_trajectory(v * 9 + 3, 0), predicted_future_trajectory(v * 9 + 6, 0),
                             u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {
            // collision is detected
            int other_drone_id = INT_MAX;
            // get the id of the other uav
            sscanf(u->first.c_str(), "uav%d", &other_drone_id);
            // check if we should be avoiding (out id is higher, or the other uav has collision avoidance turned off)
            if ((u->second.collision_avoidance == false) || (other_drone_id < uav_num_name)) {
              // we should be avoiding
              avoiding                 = true;
              double tmp_safe_altitude = u->second.points[v].z + mrs_collision_avoidance_correction;
              if (tmp_safe_altitude > collision_free_altitude) {
                collision_free_altitude = tmp_safe_altitude;
              }

              ROS_ERROR_STREAM_THROTTLE(1, "[MpcTracker]: Avoiding collision with uav" << other_drone_id);
            } else {
              // the other uav should avoid us
              being_avoided = true;
              ROS_WARN_STREAM_THROTTLE(1, "[MpcTracker]: Detected collision with uav" << other_drone_id << ", not avoiding (My priority is higher)");
            }
          }
        }
      }
      u++;
    }
  }
  trajectory_setpoint_mutex.unlock();
  if (!avoiding) {
    // we are not avoiding any collisions, so reduce the collision avoidance offset
    collision_free_altitude -= 0.02;
    if (collision_free_altitude < 0) {
      collision_free_altitude = 0;
    }
  }
  if (being_avoided) {
    // negative value to signal that other uav is avoiding us
    collision_free_altitude = -0.1;
  }
  return collision_free_altitude;
}

//}

//{ filterYawReference()

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

//{ setTrajectory()

// sets the desired trajectory based on a single setpoint
void MpcTracker::setTrajectory(float x, float y, float z, float yaw) {

  trajectory_setpoint_mutex.lock();
  des_x_trajectory.fill(x);
  des_y_trajectory.fill(y);
  des_z_trajectory.fill(z);
  des_yaw_trajectory.fill(yaw);
  trajectory_setpoint_mutex.unlock();
}

//}

//{ integrate()

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

//{ calculateMPC()

void MpcTracker::calculateMPC() {
  // Check other drone trajectories for collisions
  minimum_collison_free_altitude = checkTrajectoryForCollisions();
  ROS_INFO_STREAM_THROTTLE(1, "OFFSET " << minimum_collison_free_altitude);
  bool slow_down = false;
  if (minimum_collison_free_altitude > 0.001) {
    slow_down = true;
  } else if (minimum_collison_free_altitude < -0.001) {
    minimum_collison_free_altitude = 0;
    slow_down                      = true;
  }

  // filter desired yaw reference to be feasible and remove PI rollovers
  filterYawReference();

  iters_Z   = 0;
  iters_X   = 0;
  iters_Y   = 0;
  iters_YAW = 0;

  if (slow_down) {
    // There is a possibility of a collision, better slow down a bit to give everyone more time
    max_speed_x = max_horizontal_speed * collision_horizontal_speed_coef;
    max_speed_y = max_horizontal_speed * collision_horizontal_speed_coef;
    max_acc_x   = max_horizontal_acceleration * collision_horizontal_acceleration_coef;
    max_acc_y   = max_horizontal_acceleration * collision_horizontal_acceleration_coef;
  } else {
    max_speed_x = max_horizontal_speed;
    max_speed_y = max_horizontal_speed;
    max_acc_x   = max_horizontal_acceleration;
    max_acc_y   = max_horizontal_acceleration;
  }

  if (minimum_collison_free_altitude > 0.001) {
    // we are avoiding someone, better increase the vertical velocity and aceleration limits to avoid in time
    max_speed_z = 5.0;
    max_acc_z   = 3.0;
    max_jerk_z  = 6.0;
    min_speed_z = 5.0;
    min_acc_z   = 3.0;
    min_jerk_z  = 6.0;
  } else {
    max_speed_z = max_vertical_ascending_speed;
    max_acc_z   = max_vertical_ascending_acceleration;
    max_jerk_z  = max_vertical_ascending_jerk;
    min_speed_z = max_vertical_descending_speed;
    min_acc_z   = max_vertical_descending_acceleration;
    min_jerk_z  = max_vertical_descending_jerk;
  }

  max_jerk_x = max_horizontal_jerk;
  max_jerk_y = max_horizontal_jerk;

  /* yaw angle at which my drone "sees the goto reference point" */
  double goto_yaw = atan2(des_y_trajectory(0, 0) - x(3, 0), des_x_trajectory(0, 0) - x(0, 0));
  /* yaw angle of my velocity */
  /* double my_vel_yaw = atan2(x(4, 0), x(1, 0)); */
  /* /1* the difference between the angle of my velocity and the angle at which I am supossed to fly *1/ */
  /* double yaw_diff = fabs(my_vel_yaw - goto_yaw); */
  /* if (yaw_diff > PI) { */
  /*   yaw_diff = fabs(yaw_diff - 2 * PI); */
  /* } */
  /* /1* the angle at which I am allowed to accelerate *1/ */
  /* double goto_vel_yaw = my_vel_yaw + yaw_diff / 2; */
  /* if (yaw_diff > PI / 2) { */
  /*   goto_vel_yaw = goto_yaw - PI + yaw_diff; */
  /* } */

  max_speed_x = fabs(max_speed_x * cos(goto_yaw));
  /* max_acc_x   = fabs(max_acc_x * cos(goto_vel_yaw)); */
  /* max_jerk_x  = fabs(max_jerk_x * cos(goto_vel_yaw)); */

  max_speed_y = fabs(max_speed_y * sin(goto_yaw));
  /* max_acc_y   = fabs(max_acc_y * sin(goto_vel_yaw)); */
  /* max_jerk_y  = fabs(max_jerk_y * sin(goto_vel_yaw)); */

  for (int i = 0; i < horizon_len; i++) {
    if (des_z_trajectory(i, 0) < minimum_collison_free_altitude) {
      des_z_trajectory_offset(i, 0) = minimum_collison_free_altitude;
    } else {
      des_z_trajectory_offset(i, 0) = des_z_trajectory(i, 0);
    }
  }
  // prepare reference vector for XYZ
  /* for (int i = 0; i < horizon_len; i++) { */
  /*   reference(i * n, 0)     = des_x_trajectory(i, 0); */
  /*   reference(i * n + 1, 0) = 0; */
  /*   reference(i * n + 2, 0) = 0; */
  /*   reference(i * n + 3, 0) = des_y_trajectory(i, 0); */
  /*   reference(i * n + 4, 0) = 0; */
  /*   reference(i * n + 5, 0) = 0; */
  /*   reference(i * n + 6, 0) = des_z_trajectory(i, 0) + minimum_collison_free_altitude; */
  /*   reference(i * n + 7, 0) = 0; */
  /*   reference(i * n + 8, 0) = 0; */
  /* } */
  /* // prepare reference vector for Yaw */
  /* for (int i = 0; i < horizon_len; i++) { */
  /*   reference_yaw(i * 3, 0)     = des_yaw_trajectory(i, 0); */
  /*   reference_yaw(i * 3 + 1, 0) = 0; */
  /*   reference_yaw(i * 3 + 2, 0) = 0; */
  /* } */

  // First control input generated by cvxgen
  VectorXd cvx_u     = VectorXd::Zero(m);
  double   cvx_u_yaw = 0;

  ros::Time time_begin = ros::Time::now();

  // | ---------------------- cvxgen X axis --------------------- |
  initial_x(0, 0) = x(0, 0);
  initial_x(1, 0) = x(1, 0);
  initial_x(2, 0) = x(2, 0);

  cvx_x->setInitialState(initial_x);
  cvx_x->setLimits(max_speed_x, max_speed_x, max_acc_x, max_acc_x, max_jerk_x, max_jerk_x);
  cvx_x->loadReference(des_x_trajectory);
  iters_X += cvx_x->solveCvx();
  cvx_x->getStates(predicted_future_trajectory);
  cvx_u(0) = cvx_x->getFirstControlInput();

  // | ---------------------- cvxgen Y axis --------------------- |
  initial_y(0, 0) = x(3, 0);
  initial_y(1, 0) = x(4, 0);
  initial_y(2, 0) = x(5, 0);

  cvx_y->setInitialState(initial_y);
  cvx_y->setLimits(max_speed_y, max_speed_y, max_acc_y, max_acc_y, max_jerk_y, max_jerk_y);
  cvx_y->loadReference(des_y_trajectory);
  iters_Y += cvx_y->solveCvx();
  cvx_y->getStates(predicted_future_trajectory);
  cvx_u(1) = cvx_y->getFirstControlInput();

  // | ---------------------- cvxgen Z axis --------------------- |
  initial_z(0, 0) = x(6, 0);
  initial_z(1, 0) = x(7, 0);
  initial_z(2, 0) = x(8, 0);

  cvx_z->setInitialState(initial_z);
  cvx_z->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_vertical_ascending_jerk, max_vertical_descending_jerk);
  cvx_z->loadReference(des_z_trajectory_offset);
  iters_Z += cvx_z->solveCvx();
  cvx_z->getStates(predicted_future_trajectory);
  cvx_u(2) = cvx_z->getFirstControlInput();


  // | ---------------------- cvxgen YAW axis --------------------- |
  cvx_yaw->setInitialState(x_yaw);
  cvx_yaw->setLimits(max_yaw_rate, max_yaw_rate, max_yaw_acceleration, max_yaw_acceleration, max_yaw_jerk, max_yaw_jerk);
  cvx_yaw->loadReference(des_yaw_trajectory);
  iters_YAW += cvx_yaw->solveCvx();
  cvx_u_yaw = cvx_yaw->getFirstControlInput();

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

//{ publishDiagnostics()

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
    pub_diagnostics_.publish(diagnostics);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_diagnostics_.getTopic().c_str());
  }
}

//}

//{ setRelativeGoal()

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

  if (use_safety_area) {

    if (!safety_area->isPointIn(abs_x, abs_y)) {

      return false;
    }
  }

  des_trajectory_mutex.lock();
  tracking_trajectory_ = false;
  des_trajectory_mutex.unlock();

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

//{ loadTrajectory()

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

    ROS_INFO("[MpcTracker]: MpcTracker: ");

  } else {

    if (debug_) {
      try {
        pub_debug_trajectory_.publish(msg);
      }
      catch (...) {
        ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", pub_debug_trajectory_.getTopic().c_str());
      }
    }

    des_trajectory_mutex.lock();

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
      if (dist(des_x_whole_trajectory(0), des_y_whole_trajectory(0), des_x_whole_trajectory(trajectory_size - 1), des_y_whole_trajectory(trajectory_size - 1)) <
          4) {

        loop = true;

      } else {

        loop = false;
      }
    } else {
      loop = false;
    }

    bool trajectory_is_ok = true;
    // check the safety area
    if (use_safety_area) {

      int last_valid_idx    = 0;
      int first_invalid_idx = -1;
      for (int i = 0; i < trajectory_size; i++) {

        // the point is not feasible
        if (!safety_area->isPointIn(des_x_whole_trajectory(i), des_y_whole_trajectory(i))) {

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

    des_trajectory_mutex.unlock();

    ROS_INFO_THROTTLE(1, "Setting trajectory with length %d", trajectory_size);

    publishDiagnostics();

    if (trajectory_is_ok) {
      message = "The trajectory successfully loaded.";
    } else {
      message = "The trajectory was modified because it contains points outside of the safety area!";
    }
    return true;
  }
}

//}

//{ setGoal()

// set absolute goal
bool MpcTracker::setGoal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

  if (set_use_yaw) {

    des_yaw_mutex.lock();
    desired_yaw = set_yaw;
    des_yaw_mutex.unlock();
  }

  if (use_safety_area) {

    if (!safety_area->isPointIn(set_x, set_y)) {

      return false;
    }
  }

  setTrajectory(set_x, set_y, set_z, set_yaw);

  des_trajectory_mutex.lock();
  tracking_trajectory_ = false;
  des_trajectory_mutex.unlock();

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

//{ diagnosticsTimer()

// published diagnostics in reguar intervals
void MpcTracker::diagnosticsTimer(const ros::TimerEvent &event) {

  publishDiagnostics();
}

//}

//{ mpcTimer()

void MpcTracker::mpcTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  routine_mpc_timer->start(event);

  ros::Time     begin = ros::Time::now();
  ros::Time     end;
  ros::Duration interval;

  int timer = 0;

  des_trajectory_mutex.lock();
  {
    // if we are tracking trajectory, copy the setpoint
    if (tracking_trajectory_ && timer++ == 20 && trajectory_idx < (trajectory_size)) {

      timer = 0;

      // fill the prediction horizon with the desired trajectory
      for (int i = 0; i < horizon_len; i++) {

        int tempIdx = i + trajectory_idx;
        if (loop) {

          if (tempIdx >= trajectory_size) {

            tempIdx = tempIdx % trajectory_size;
          }
        }

        des_x_trajectory(i)   = des_x_whole_trajectory(tempIdx);
        des_y_trajectory(i)   = des_y_whole_trajectory(tempIdx);
        des_z_trajectory(i)   = des_z_whole_trajectory(tempIdx);
        des_yaw_trajectory(i) = des_yaw_whole_trajectory(tempIdx);
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

  des_trajectory_mutex.unlock();

  // run the mpc
  calculateMPC();

  end      = ros::Time::now();
  interval = end - begin;
  if (interval.toSec() > dt) {

    mpc_total_delay += interval.toSec() - dt;
    ROS_WARN_THROTTLE(10.0, "[MpcTracker] MPC is Running %2.2f%% slower than it should.", 100 * mpc_total_delay / (ros::Time::now() - mpc_start_time).toSec());
  }

  mpc_computed_ = true;

  routine_mpc_timer->end();
}

//}

//{ futureTrajectoryTimer()

void MpcTracker::futureTrajectoryTimer(const ros::TimerEvent &event) {

  if (!is_active) {
    return;
  }

  if (future_was_predicted) {

    mrs_msgs::FutureTrajectory newTrajectory;
    newTrajectory.stamp    = ros::Time::now();
    newTrajectory.uav_name = uav_name_;

    newTrajectory.collision_avoidance = mrs_collision_avoidance;

    geometry_msgs::PoseArray debugTrajectory;
    debugTrajectory.header.stamp    = ros::Time::now();
    debugTrajectory.header.frame_id = "local_origin";

    // fill the trajectory
    mutex_predicted_trajectory.lock();
    {
      for (int i = 0; i < horizon_len; i++) {

        mrs_msgs::FuturePoint newPoint;

        newPoint.x = predicted_future_trajectory(i * n);
        newPoint.y = predicted_future_trajectory(i * n + 3);
        newPoint.z = predicted_future_trajectory(i * n + 6);

        newTrajectory.points.push_back(newPoint);

        geometry_msgs::Pose newPose;

        newPose.position.x = newPoint.x;
        newPose.position.y = newPoint.y;
        newPose.position.z = newPoint.z;
        tf::Quaternion orientation;
        orientation.setEuler(0, 0, desired_yaw);
        newPose.orientation.x = orientation.x();
        newPose.orientation.y = orientation.y();
        newPose.orientation.z = orientation.z();
        newPose.orientation.w = orientation.w();

        debugTrajectory.poses.push_back(newPose);
      }
    }
    mutex_predicted_trajectory.unlock();

    try {
      predicted_trajectory_publisher.publish(newTrajectory);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", predicted_trajectory_publisher.getTopic().c_str());
    }
    try {
      debug_predicted_trajectory_publisher.publish(debugTrajectory);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: Exception caught during publishing topic %s.", debug_predicted_trajectory_publisher.getTopic().c_str());
    }
  }
}

//}
}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::MpcTracker, mrs_mav_manager::Tracker)
