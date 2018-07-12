#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <math.h>
#include <mrs_msgs/Vec4.h>
#include <mavros_msgs/RCIn.h>
#include <mrs_estimation/convex_polygon.h>
#include <mrs_msgs/FuturePoint.h>
#include <mrs_msgs/FutureTrajectory.h>
#include <mrs_msgs/TrackerDiagnostics.h>
#include <mrs_msgs/TrackerPointStamped.h>
#include <mrs_msgs/TrackerTrajectory.h>
#include <mrs_msgs/TrackerTrajectorySrv.h>
#include <mrs_msgs/Vec1.h>
#include <nav_msgs/Odometry.h>
#include <mrs_msgs/TrackerStatus.h>
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <std_srvs/Trigger.h>
#include <tf/transform_datatypes.h>
#include <mrs_mav_manager/Tracker.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <mutex>
#include <thread>

#include "cvx_wrapper.h"
#include "cvx_wrapper_yaw.h"
#include "cvx_wrapper_z.h"

#include "commons.h"

using namespace Eigen;

namespace mrs_trackers
{

class MpcTracker : public mrs_mav_manager::Tracker {
public:
  MpcTracker(void);

  void Initialize(const ros::NodeHandle &parent_nh);
  bool Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd);
  void Deactivate(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const mrs_msgs::TrackerStatus::Ptr status();

private:
  ros::NodeHandle nh_;
  // nodelet variables
  ros::Subscriber    sub_pos_cmd_;                      // desired position command
  ros::Subscriber    sub_pos_rel_cmd_;                  // desired position relative command
  ros::Subscriber    sub_trajectory_;                   // desired trajectory
  ros::Subscriber    sub_rc_;                           // rc transmitter
  ros::ServiceServer ser_start_trajectory_following_;   // start trajectory following
  ros::ServiceServer ser_stop_trajectory_following_;    // stop trajectory following
  ros::ServiceServer ser_resume_trajectory_following_;  // resume trajectory following
  ros::ServiceServer ser_fly_to_trajectory_start_;      // fly to the first point of the trajectory
  ros::ServiceServer ser_set_trajectory_;               // service for setting desired trajectory
  ros::ServiceServer goto_service_cmd_cb_;
  ros::ServiceServer gotorelative_service_cmd_cb_;
  ros::ServiceServer gotoaltitude_service_cmd_cb_;
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
  ConvexPolygon *safety_area;
  bool           use_safety_area;

  // variables regarding the MPC controller
  int    n;            // number of states
  int    m;            // number of inputs
  int    n_yaw;        // number of states - yaw
  int    m_yaw;        // number of inputs - yaw
  int    horizon_len;  // lenght of the prediction horizon
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
  double max_altitude_;
  double min_altitude_;

  bool avoiding_someone;
  bool being_avoided;

  int    max_iters_XY, max_iters_Z, max_iters_yaw;
  int    iters_Z             = 0;
  int    iters_XY            = 0;
  int    iters_yaw           = 0;
  double max_speed_xy        = 0;
  double max_acc_xy          = 0;
  double max_speed_z         = 0;
  double max_acc_z           = 0;
  double min_speed_z         = 0;
  double min_acc_z           = 0;
  double max_horizontal_jerk = 0;

  double diagnostic_tracking_threshold;

  CvxWrapper *   cvx_2d;
  CvxWrapperZ *  cvx_z;
  CvxWrapperYaw *cvx_yaw;

  double   dt, dt2;  // time difference of the dynamical system
  MatrixXd A;        // system matrix for virtual UAV
  MatrixXd B;        // input matrix for virtual UAV

  MatrixXd A_yaw;  // system matrix for yaw
  MatrixXd B_yaw;  // input matrix for yaw

  // trajectories
  MatrixXd des_x_trajectory;                  // trajectory reference over the prediction horizon
  MatrixXd des_y_trajectory;                  // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory;                  // trajectory reference over the prediction horizon
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
  MatrixXd                 predicted_future_yaw;
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
  std::thread                  predicted_trajectory_thread;
  std::mutex                   mutex_predicted_trajectory;
  void                         futureTrajectoryThread(void);
  std::string                  predicted_trajectory_topic;
  void otherDronesTrajectoriesCallback(const mrs_msgs::FutureTrajectoryConstPtr &msg);
  bool   future_was_predicted;
  double mrs_collision_avoidance_altitude_threshold;
  double checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  int       uav_num_name;
  double    collision_altitude_offeset;
  ros::Time avoiding_collision_time;
  ros::Time being_avoided_time;
  bool collision_avoidance_toggle_cb(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  double collision_horizontal_acceleration_coef, collision_horizontal_speed_coef;
  int    collision_slow_down_before;
  double collision_slowing_hysteresis;
  int    earliest_collision_idx;
  double collision_trajectory_timeout;

  MatrixXd   outputTrajectory;
  std::mutex x_mutex, trajectory_setpoint_mutex, des_yaw_mutex, des_trajectory_mutex;

  std::thread mpc_thread, diagnostics_thread;

  bool mpc_computed_;

  double diagnostics_rate;

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
  void mpcThread(void);
  void diagnosticsThread(void);
  void pos_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void pos_rel_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg);
  void trajectory_cmd_cb(const mrs_msgs::TrackerTrajectory::ConstPtr &msg);
  bool trajectory_service_cb(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res);
  bool start_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool stop_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool resume_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  bool fly_to_trajectory_start_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void odom_cb(const nav_msgs::OdometryConstPtr &msg);
  void calculateMPC();
  void setTrajectory(float x, float y, float z, float yaw);
  bool trajectoryLoad(const mrs_msgs::TrackerTrajectory &msg, std::string &message);
  void     filterReference(void);
  void     filterYawReference(void);
  VectorXd integrate(VectorXd &in, double dt, double integrational_const);
  bool set_rel_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool gotorelative_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool gotoaltitude_service_cmd_cb(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool set_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool goto_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res);
  bool failsafe_trigger_service_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void rc_cb(const mavros_msgs::RCInConstPtr &msg);
  bool   trigger_failsafe();
  void   publishDiagnostics();
  double triangleArea(Eigen::VectorXd a, Eigen::VectorXd b, Eigen::VectorXd c);
  bool pointInBoundary(Eigen::MatrixXd boundary, double px, double py);
};

MpcTracker::MpcTracker(void) : odom_set_(false), is_active(false), is_initialized(false), mpc_computed_(false) {
}

void MpcTracker::futureTrajectoryThread(void) {

  ros::Rate r(predicted_trajectory_publish_rate);
  /* ros::Rate r(100); */

  while (ros::ok()) {

    while (!is_active && ros::ok()) {
      r.sleep();
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
        ROS_ERROR("Exception caught during publishing topic %s.", predicted_trajectory_publisher.getTopic().c_str());
      }
      try {
        debug_predicted_trajectory_publisher.publish(debugTrajectory);
      }
      catch (...) {
        ROS_ERROR("Exception caught during publishing topic %s.", debug_predicted_trajectory_publisher.getTopic().c_str());
      }
    }

    r.sleep();
  }
}

// called once at the very beginning
void MpcTracker::Initialize(const ros::NodeHandle &parent_nh) {

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

    ROS_ERROR("Safety area is not correctly defined!, Exitting...");
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

    safety_area = new ConvexPolygon(tempMatrix);
  }
  catch (ConvexPolygon::WrongNumberOfVertices) {

    ROS_ERROR("Exception caught. Wrong number of vertices was supplied to create the safety area.");
    ros::shutdown();
  }
  catch (ConvexPolygon::PolygonNotConvexException) {

    ROS_ERROR("Exception caught. Polygon supplied to create the safety area is not convex.");
    ros::shutdown();
  }
  catch (ConvexPolygon::WrongNumberOfColumns) {
    ROS_ERROR("Exception caught. Wrong number of columns was supplied to the safety area.");
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
    ROS_INFO("RC Failsafe ON, channel = %d, threshold = %d", rc_failsafe_channel, rc_failsafe_threshold);
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


  ROS_INFO("MPC Tracker initiated with system parameters: n: %d, m: %d, dt: %0.3f, dt2: %0.3f", n, m, dt, dt2);
  ROS_INFO_STREAM("\nA:\n" << A << "\nB:\n" << B);

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

  cvx_2d = new CvxWrapper(verbose, max_iters_XY, tempList, tempList2, dt, dt2, max_horizontal_jerk);

  nh_.param("cvxWrapperZ/verbose", verbose, false);
  nh_.param("cvxWrapperZ/maxNumOfIterations", max_iters_Z, 25);
  nh_.getParam("cvxWrapperZ/Q", tempList);
  nh_.getParam("cvxWrapperZ/R", tempList2);

  cvx_z = new CvxWrapperZ(verbose, max_iters_Z, tempList, tempList2, dt, dt2, max_vertical_ascending_jerk, max_vertical_descending_jerk);

  nh_.param("cvxWrapperYaw/verbose", verbose, false);
  nh_.param("cvxWrapperYaw/maxNumOfIterations", max_iters_yaw, 25);
  nh_.getParam("cvxWrapperYaw/Q", tempList);
  nh_.getParam("cvxWrapperYaw/R", tempList2);

  cvx_yaw = new CvxWrapperYaw(verbose, max_iters_yaw, tempList, tempList2, dt, dt2);

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

  des_x_trajectory   = MatrixXd::Zero(horizon_len, 1);
  des_y_trajectory   = MatrixXd::Zero(horizon_len, 1);
  des_z_trajectory   = MatrixXd::Zero(horizon_len, 1);
  des_yaw_trajectory = MatrixXd::Zero(horizon_len, 1);

  des_x_filtered = MatrixXd::Zero(horizon_len, 1);
  des_y_filtered = MatrixXd::Zero(horizon_len, 1);
  des_z_filtered = MatrixXd::Zero(horizon_len, 1);

  // subscriber for setting the position setpoint
  sub_pos_cmd_ = nh_.subscribe("desired_position", 1, &MpcTracker::pos_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  // subscriber for setting the relative setpoint
  sub_pos_rel_cmd_ = nh_.subscribe("desired_relative_position", 1, &MpcTracker::pos_rel_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  // subscriber for desired trajectory
  sub_trajectory_ = nh_.subscribe("desired_trajectory", 1, &MpcTracker::trajectory_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  if (debug_) {
    pub_debug_trajectory_ = nh_.advertise<mrs_msgs::TrackerTrajectory>("debug_set_trajectory", 1);
  }

  // service for desired trajectory
  ser_set_trajectory_ = nh_.advertiseService("set_trajectory", &MpcTracker::trajectory_service_cb, this);

  // subscriber for rc transmitter
  sub_rc_ = nh_.subscribe("rc_in", 1, &MpcTracker::rc_cb, this, ros::TransportHints().tcpNoDelay());

  // service for starting trajectory following
  ser_start_trajectory_following_ = nh_.advertiseService("start_trajectory_following", &MpcTracker::start_trajectory_following_cmd_cb, this);

  // service for stopping trajectory following
  ser_stop_trajectory_following_ = nh_.advertiseService("stop_trajectory_following", &MpcTracker::stop_trajectory_following_cmd_cb, this);

  // service for resuming trajectory following
  ser_resume_trajectory_following_ = nh_.advertiseService("resume_trajectory_following", &MpcTracker::resume_trajectory_following_cmd_cb, this);

  // service for flying to the trajectory start point
  ser_fly_to_trajectory_start_ = nh_.advertiseService("fly_to_trajectory_start", &MpcTracker::fly_to_trajectory_start_cmd_cb, this);

  // service goto service
  goto_service_cmd_cb_ = nh_.advertiseService("goTo", &MpcTracker::goto_service_cmd_cb, this);

  // service goToRelative service
  gotorelative_service_cmd_cb_ = nh_.advertiseService("goToRelative", &MpcTracker::gotorelative_service_cmd_cb, this);

  // service goToAltitude service
  gotoaltitude_service_cmd_cb_ = nh_.advertiseService("goToAltitude", &MpcTracker::gotoaltitude_service_cmd_cb, this);

  // service for triggering failsafe
  failsafe_trigger_service_cmd_ = nh_.advertiseService("failsafe", &MpcTracker::failsafe_trigger_service_cmd_cb, this);

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
    ROS_ERROR("uav_name has not been specified!");
    ros::shutdown();
  }

  // extract the numerical name
  sscanf(uav_name_.c_str(), "uav%d", &uav_num_name);
  ROS_INFO("Numerical ID of this UAV is %d", uav_num_name);

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
  predicted_future_yaw        = MatrixXd::Zero(horizon_len * 3, 1);

  collision_altitude_offeset = 0;
  avoiding_collision_time    = ros::Time::now();
  being_avoided_time         = ros::Time::now();
  future_was_predicted       = false;
  earliest_collision_idx     = INT_MAX;

  nh_.param("predicted_trajectory_topic", predicted_trajectory_topic, std::string());

  nh_.param("mrs_collision_avoidance/predicted_trajectory_publish_rate", predicted_trajectory_publish_rate, 1.0);
  nh_.param("mrs_collision_avoidance/correction", mrs_collision_avoidance_correction, 2.0);
  nh_.param("mrs_collision_avoidance/radius", mrs_collision_avoidance_radius, 1.0);
  nh_.param("mrs_collision_avoidance/altitude_threshold", mrs_collision_avoidance_altitude_threshold, 1.0);
  nh_.param("mrs_collision_avoidance/collision_horizontal_speed_coef", collision_horizontal_speed_coef, 1.0);
  nh_.param("mrs_collision_avoidance/collision_horizontal_acceleration_coef", collision_horizontal_acceleration_coef, 1.0);
  nh_.param("mrs_collision_avoidance/collision_slow_down_before", collision_slow_down_before, 0);
  nh_.param("mrs_collision_avoidance/collision_slowing_hysteresis", collision_slowing_hysteresis, 0.0);
  nh_.param("mrs_collision_avoidance/trajectory_timeout", collision_trajectory_timeout, 1.0);

  // collision avoidance toggle service
  collision_avoidance_service = nh_.advertiseService("collision_avoidance", &MpcTracker::collision_avoidance_toggle_cb, this);

  if (predicted_trajectory_topic.empty()) {
    ROS_ERROR("You need to define predicted trajectory topic name in the launch file.");
    ros::shutdown();
  }

  // create subscribers on other drones diagnostics
  for (unsigned long i = 0; i < other_drone_names_.size(); i++) {

    std::string topic_name = std::string("/") + other_drone_names_[i] + std::string("/") + predicted_trajectory_topic;

    ROS_INFO("subscribing to %s", topic_name.c_str());

    other_drones_subscribers.push_back(nh_.subscribe(topic_name, 1, &MpcTracker::otherDronesTrajectoriesCallback, this, ros::TransportHints().tcpNoDelay()));
  }

  // create threads and mutexes
  mpc_thread                  = std::thread(&MpcTracker::mpcThread, this);
  diagnostics_thread          = std::thread(&MpcTracker::diagnosticsThread, this);
  predicted_trajectory_thread = std::thread(&MpcTracker::futureTrajectoryThread, this);

  is_initialized = true;

  ROS_INFO("MpcTracker initialized");
}

void MpcTracker::otherDronesTrajectoriesCallback(const mrs_msgs::FutureTrajectoryConstPtr &msg) {

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // update the diagnostics
  other_drones_trajectories[msg->uav_name] = temp_trajectory;

  /* ROS_INFO_THROTTLE(1, "Getting trajectory from drone %s", msg->uav_name.c_str()); */
}

bool MpcTracker::collision_avoidance_toggle_cb(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {

  mrs_collision_avoidance = req.data;

  if (!mrs_collision_avoidance) {

    collision_altitude_offeset = 0;
  }

  ROS_INFO("Collision avoidance was switched %s", mrs_collision_avoidance ? "TRUE" : "FALSE");

  res.message = "Collision avoidance set.";
  res.success = true;

  return true;
}

bool MpcTracker::trigger_failsafe() {

  // turn it off
  if (failsafe_triggered) {

    failsafe_triggered = false;
    ROS_WARN("Failsafe OFF");
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
    set_rel_goal(move_x, move_y, 5, 0, true);

    ROS_WARN("Failsafe ON");

    failsafe_triggered = true;

    publishDiagnostics();

    return true;
  }
}

double dist(const double ax, const double ay, const double bx, const double by) {

  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

double MpcTracker::checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (dist(ax, ay, bx, by) < mrs_collision_avoidance_radius && fabs(az - bz) < mrs_collision_avoidance_altitude_threshold) {
    return true;

  } else {

    return false;
  }
}

// callback for rc transmitter
void MpcTracker::rc_cb(const mavros_msgs::RCInConstPtr &msg) {

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

      ROS_WARN("Toggling Failsafe by RC");
      rc_failsafe_time = ros::Time::now();
      trigger_failsafe();
    }
  }
}

// filters the reference trajectory for maximum speed
void MpcTracker::filterReference(void) {

  double difference;
  double maxSpeed;

  trajectory_setpoint_mutex.lock();

  // mrs collision avoidance
  collision_altitude_offeset = 0;

  if (mrs_collision_avoidance) {

    std::map<std::string, mrs_msgs::FutureTrajectory>::iterator u = other_drones_trajectories.begin();
    while (u != other_drones_trajectories.end()) {
      bool collision = false;
      int  v         = 0;

      // is the other's trajectory fresh enought?
      if ((ros::Time::now() - u->second.stamp).toSec() < collision_trajectory_timeout) {
        while (v < horizon_len) {

          if (checkCollision(des_x_filtered(v), des_y_filtered(v), des_z_trajectory(v) + collision_altitude_offeset, u->second.points[v].x,
                             u->second.points[v].y, u->second.points[v].z)) {

            collision = true;

            ROS_ERROR_THROTTLE(1, "Potential collision detected with %s!", u->first.c_str());

            if (v < earliest_collision_idx) {

              earliest_collision_idx = v;
            }
            break;
          }
          // ROS_INFO("%2.2f, %2.2f, %2.2f vs %2.2f, %2.2f, %2.2f", des_x_filtered(v), des_y_filtered(v), des_z_trajectory(v), u->second.points[v].x,
          // u->second.points[v].y, u->second.points[v].z);
          v++;
        }
      }

      if (collision) {
        int other_drone_id = INT_MAX;
        sscanf(u->first.c_str(), "uav%d", &other_drone_id);

        // only do the avoidance manouver when we are higher number than the other drone
        // ! or if the other drones avoidance is turned off
        if ((u->second.collision_avoidance == false) || (other_drone_id < uav_num_name) ||
            (des_z_trajectory(v) > (u->second.points[v].z + mrs_collision_avoidance_correction / 2.0 + collision_altitude_offeset))) {

          ROS_ERROR_THROTTLE(1, "Avoiding collision with %s.", u->first.c_str());

          avoiding_collision_time = ros::Time::now();

          collision_altitude_offeset = u->second.points[v].z + mrs_collision_avoidance_correction - des_z_trajectory(v);
          u                          = other_drones_trajectories.begin();
          continue;

          // when we are of lower id, make it easier for the other drone
        } else {

          ROS_INFO_THROTTLE(1, "Should be avoided by %s.", u->first.c_str());

          being_avoided_time = ros::Time::now();
        }
      }

      u++;
    }
  }

  // we have not detected collision for longer than hysteresis timeout
  // we want to slow down in both cases, when avoiding and when being avoided
  bool avoiding_someone = (ros::Time::now() - avoiding_collision_time).toSec() < collision_slowing_hysteresis ? true : false;
  bool being_avoided    = (ros::Time::now() - being_avoided_time).toSec() < collision_slowing_hysteresis ? true : false;

  // ROS_INFO("Collision altitude offset %2.2f", collision_altitude_offeset);


  if (!avoiding_someone && !being_avoided) {

    earliest_collision_idx = INT_MAX;
  }

  // saturate the x part of the trajectory
  for (int i = 0; i < horizon_len; i++) {

    // limit the velocity for the part of the trajectory where there is a collision
    double temp_horizontal_speed_limit = max_horizontal_speed;
    if ((avoiding_someone || being_avoided) && ((i + collision_slow_down_before) >= earliest_collision_idx)) {
      temp_horizontal_speed_limit *= collision_horizontal_speed_coef;
      ROS_INFO_THROTTLE(1, "Reducing speed in XY in %2.2f s", i * 0.2);
    }

    if (i == 0) {
      maxSpeed   = temp_horizontal_speed_limit * dt;
      difference = des_x_trajectory(i, 0) - x(0, 0);
    } else {
      maxSpeed   = temp_horizontal_speed_limit * dt2;
      difference = des_x_trajectory(i, 0) - des_x_filtered(i - 1, 0);
    }

    // saturate the difference
    if (difference > maxSpeed)
      difference = maxSpeed;
    else if (difference < -maxSpeed)
      difference = -maxSpeed;

    if (i == 0) {
      des_x_filtered(i, 0) = x(0, 0) + difference;
    } else {
      des_x_filtered(i, 0) = des_x_filtered(i - 1, 0) + difference;
    }
  }

  // saturate the y part of the trajectory
  for (int i = 0; i < horizon_len; i++) {

    // limit the velocity for the part of the trajectory where there is a collision
    double temp_horizontal_speed_limit = max_horizontal_speed;
    if ((avoiding_someone || being_avoided) && ((i + collision_slow_down_before) >= earliest_collision_idx)) {
      temp_horizontal_speed_limit *= collision_horizontal_speed_coef;
    }

    if (i == 0) {
      maxSpeed   = temp_horizontal_speed_limit * dt;
      difference = des_y_trajectory(i, 0) - x(3, 0);
    } else {
      maxSpeed   = temp_horizontal_speed_limit * dt2;
      difference = des_y_trajectory(i, 0) - des_y_filtered(i - 1, 0);
    }

    // saturate the difference
    if (difference > maxSpeed)
      difference = maxSpeed;
    else if (difference < -maxSpeed)
      difference = -maxSpeed;

    if (i == 0) {
      des_y_filtered(i, 0) = x(3, 0) + difference;
    } else {
      des_y_filtered(i, 0) = des_y_filtered(i - 1, 0) + difference;
    }
  }

  // saturate the z part of the trajectory
  for (int i = 0; i < horizon_len; i++) {

    double tempDt;

    if (i == 0) {
      difference = des_z_trajectory(i, 0) + collision_altitude_offeset - x(6, 0);
      tempDt     = dt;
    } else {
      difference = des_z_trajectory(i, 0) + collision_altitude_offeset - des_z_filtered(i - 1, 0);
      tempDt     = dt2;
    }

    // saturate the difference
    if (difference > max_vertical_ascending_speed * tempDt) {

      // saturated the upwards velocity only if we are not avoiding collision
      if (!avoiding_someone) {
        difference = max_vertical_ascending_speed * tempDt;

      } else {

        ROS_INFO_THROTTLE(1, "NOT saturation vertical speed.");
      }

    } else if (difference < -max_vertical_descending_speed * tempDt)
      difference = -max_vertical_descending_speed * tempDt;

    if (i == 0) {
      des_z_filtered(i, 0) = x(6, 0) + difference;
    } else {
      des_z_filtered(i, 0) = des_z_filtered(i - 1, 0) + difference;
    }

    // saturate to maxAltitude
    if (des_z_filtered(i, 0) > max_altitude_) {
      des_z_filtered(i, 0) = max_altitude_;
    }

    if (des_z_filtered(i, 0) < min_altitude_) {
      des_z_filtered(i, 0) = min_altitude_;
    }
  }
  trajectory_setpoint_mutex.unlock();
}

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

// sets the desired trajectory based on a single setpoint
void MpcTracker::setTrajectory(float x, float y, float z, float yaw) {

  trajectory_setpoint_mutex.lock();
  des_x_trajectory.fill(x);
  des_y_trajectory.fill(y);
  des_z_trajectory.fill(z);
  des_yaw_trajectory.fill(yaw);
  trajectory_setpoint_mutex.unlock();
}

VectorXd MpcTracker::integrate(VectorXd &in, double dt, double integrational_const) {

  VectorXd out;
  out    = VectorXd::Zero(in.size());
  out(0) = integrational_const;

  for (int i = 1; i < in.size(); i++) {

    out(i) = out(i - 1) + in(i - 1) * dt;
  }

  return out;
}

void MpcTracker::calculateMPC() {

  // filter the desired trajectory to be feasible
  filterReference();
  // filter desired yaw reference to be feasible and remove PI rollarounds
  filterYawReference();

  avoiding_someone = (ros::Time::now() - avoiding_collision_time).toSec() < collision_slowing_hysteresis ? true : false;
  being_avoided    = (ros::Time::now() - being_avoided_time).toSec() < collision_slowing_hysteresis ? true : false;
  iters_Z          = 0;
  iters_XY         = 0;
  iters_yaw        = 0;

  if (being_avoided || avoiding_someone) {
    // There is a possibility of a collision, better slow down a bit to give everyone more time
    max_speed_xy = max_horizontal_speed * collision_horizontal_speed_coef;
    max_acc_xy   = max_horizontal_acceleration * collision_horizontal_acceleration_coef;
  } else {
    max_speed_xy = max_horizontal_speed;
    max_acc_xy   = max_horizontal_acceleration;
  }
  if (avoiding_someone) {
    // we are avoiding someone, better increase the vertical limits to avoid in time
    max_speed_z = 5.0;
    max_acc_z   = 3.0;
    min_speed_z = 5.0;
    min_acc_z   = 3.0;
  } else {
    max_speed_z = max_vertical_ascending_speed;
    max_acc_z   = max_vertical_ascending_acceleration;
    min_speed_z = max_vertical_descending_speed;
    min_acc_z   = max_vertical_descending_acceleration;
  }

  // prepare reference vector for XYZ
  for (int i = 0; i < horizon_len; i++) {
    reference(i * n, 0)     = des_x_filtered(i, 0);
    reference(i * n + 1, 0) = 0;
    reference(i * n + 2, 0) = 0;
    reference(i * n + 3, 0) = des_y_filtered(i, 0);
    reference(i * n + 4, 0) = 0;
    reference(i * n + 5, 0) = 0;
    reference(i * n + 6, 0) = des_z_filtered(i, 0);
    reference(i * n + 7, 0) = 0;
    reference(i * n + 8, 0) = 0;
  }
  // prepare reference vector for Yaw
  for (int i = 0; i < horizon_len; i++) {
    reference_yaw(i * 3, 0)     = des_yaw_trajectory(i, 0);
    reference_yaw(i * 3 + 1, 0) = 0;
    reference_yaw(i * 3 + 2, 0) = 0;
  }

  // First control input generated by cvxgen
  VectorXd cvx_u     = VectorXd::Zero(m);
  double   cvx_u_yaw = 0;

  ros::Time time_begin = ros::Time::now();

  // cvxgen Z axis -------------------------------------------------------------------------------------

  cvx_z->setInitialState(x);
  cvx_z->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z);
  cvx_z->loadReference(reference);
  iters_Z += cvx_z->solveCvx();
  cvx_z->getStates(predicted_future_trajectory);
  cvx_u(2) = cvx_z->getFirstControlInput();

  // cvxgen X and Y axis -------------------------------------------------------------------------------

  // Point of the following for cycle is to reduce maximum speed in XY if the UAV is climbing
  for (int i = 0; i < horizon_len; i++) {
    if (predicted_future_trajectory(7 + (i * n), 0) > 0) {
      double tmpz;
      predicted_future_trajectory(7 + (i * n), 0) > max_speed_z ? tmpz = max_speed_z : tmpz = predicted_future_trajectory(7 + (i * n));
      cvxgen_horizontal_vel_constraint(i) = max_speed_xy * sqrt(1 - (tmpz / max_speed_z) * (tmpz / max_speed_z));
      if (cvxgen_horizontal_vel_constraint(i) < max_speed_xy / 2) {
        cvxgen_horizontal_vel_constraint(i) = max_speed_xy / 2;
      }
      predicted_future_trajectory(8 + (i * n), 0) > (max_acc_z) ? tmpz = max_acc_z : tmpz = predicted_future_trajectory(8 + (i * n));
      tmpz = max_speed_xy * sqrt(1 - (tmpz / max_acc_z) * (tmpz / max_acc_z));
      if (tmpz < cvxgen_horizontal_vel_constraint(i)) {
        cvxgen_horizontal_vel_constraint(i) = tmpz;
        if (cvxgen_horizontal_vel_constraint(i) < max_speed_xy / 2) {
          cvxgen_horizontal_vel_constraint(i) = max_speed_xy / 2;
        }
      }
    } else {
      cvxgen_horizontal_vel_constraint(i) = max_speed_xy;
    }
    cvxgen_horizontal_acc_constraint(i) = max_acc_xy;
  }
  cvx_2d->setInitialState(x);
  cvx_2d->setLimits(cvxgen_horizontal_vel_constraint, cvxgen_horizontal_acc_constraint);
  cvx_2d->loadReference(reference);
  iters_XY += cvx_2d->solveCvx();
  cvx_2d->getStates(predicted_future_trajectory);
  cvx_u(0) = cvx_2d->getFirstControlInputX();
  cvx_u(1) = cvx_2d->getFirstControlInputY();

  // cvxgen yaw ----------------------------------------------------------------------------------------
  cvx_yaw->setInitialState(x_yaw);
  cvx_yaw->setLimits(max_yaw_rate, max_yaw_acceleration);
  cvx_yaw->loadReference(reference_yaw);
  iters_yaw += cvx_yaw->solveCvx();
  cvx_yaw->getStates(predicted_future_yaw);

  if (cvx_u(0) > max_horizontal_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jerk X: " << cvx_u(0));
    cvx_u(0) = max_horizontal_jerk;
  }
  if (cvx_u(0) < -max_horizontal_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jert X: " << cvx_u(0));
    cvx_u(0) = -max_horizontal_jerk;
  }
  if (cvx_u(1) > max_horizontal_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jerk Y: " << cvx_u(1));
    cvx_u(1) = max_horizontal_jerk;
  }
  if (cvx_u(1) < -max_horizontal_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jerk Y: " << cvx_u(1));
    cvx_u(1) = -max_horizontal_jerk;
  }

  if (cvx_u(2) > max_vertical_ascending_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jerk Z: " << cvx_u(2));
    cvx_u(2) = max_vertical_ascending_jerk;
  }

  if (cvx_u(2) < -max_vertical_descending_jerk) {
    ROS_WARN_STREAM_THROTTLE(0.2, "Saturating jerk Z: " << cvx_u(2));
    cvx_u(2) = -max_vertical_descending_jerk;
  }

  cvx_u_yaw = cvx_yaw->getFirstControlInput();

  ROS_INFO_STREAM_THROTTLE(0.5, "Total CVXtime: " << (ros::Time::now() - time_begin).toSec() << " iters XY: " << iters_XY << "/" << max_iters_XY
                                                  << " iters Z: " << iters_Z << "/" << max_iters_Z << " iters yaw: " << iters_yaw << "/" << max_iters_yaw);

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

// the control_manager call this once when it wants to start using this tracker
// the position command in the argument is the last position command used by a previous tracker
bool MpcTracker::Activate(const mrs_msgs::PositionCommand::ConstPtr &cmd) {

  if (odom_set_) {

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
    x_yaw(1, 0) = odom_.twist.twist.angular.z;
    x_yaw(2, 0) = 0;

    yaw = cur_yaw_;
    x_mutex.unlock();

  } else {
    ROS_ERROR("Odometry not set when activating MPC controller!");
  }

  failsafe_triggered   = false;
  tracking_trajectory_ = false;

  // if we got a setpoint with the actiovation command
  if (cmd && odom_set_) {

    des_yaw_mutex.lock();
    desired_yaw = cmd->yaw;
    des_yaw_mutex.unlock();

    setTrajectory(cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);

    ROS_INFO("MPC tracker activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);
    is_active = true;
  }

  // if we dont, stay where you are
  else if (odom_set_) {

    setTrajectory(odom_.pose.pose.position.x, odom_.pose.pose.position.y, odom_.pose.pose.position.z, tf::getYaw(odom_.pose.pose.orientation));
    position_cmd_.yaw = tf::getYaw(odom_.pose.pose.orientation);

    ROS_INFO("MPC tracker activated with no setpoint, staying where we are.");
    is_active = true;
  }

  mpc_start_time  = ros::Time::now();
  mpc_total_delay = 0;

  publishDiagnostics();

  // can return false
  return is_active;
}

// control_manager calls this when it wants to stop using this tracker
void MpcTracker::Deactivate(void) {

  is_active = false;
  odom_set_ = false;

  // turn off trajectory tracking
  des_trajectory_mutex.lock();
  tracking_trajectory_ = false;
  trajectory_idx       = 0;
  des_trajectory_mutex.unlock();

  ROS_INFO("MPC tracker deactivated");

  publishDiagnostics();
}

// if the tracker is active, this mehod is called on every odometry update, even if the tracker is not active
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

    ROS_WARN("MPC not ready, reaturning current odom as the command.");

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

    ROS_ERROR("MPC outputs are not finite!");

    position_cmd_.velocity.x     = 0;
    position_cmd_.acceleration.x = 0;

    position_cmd_.velocity.y     = 0;
    position_cmd_.acceleration.y = 0;

    position_cmd_.velocity.z     = 0;
    position_cmd_.acceleration.z = 0;
  }

  des_yaw_mutex.lock();
  {
    desired_yaw = validateYawSetpoint(desired_yaw);
  }
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
    ROS_INFO("Output YAW is not finite!");
  }

  if (std::isfinite(x_yaw(0, 0)) && std::isfinite(x_yaw(1, 0))) {
    // set the yaw output - cvxgen MPC controller
    position_cmd_.yaw     = x_yaw(0, 0);
    position_cmd_.yaw_dot = x_yaw(1, 0);

  } else {

    ROS_INFO("Output YAW is not finite!");
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
    ROS_ERROR("Exception caught during publishing topic %s.", pub_cmd_pose_.getTopic().c_str());
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
    ROS_ERROR("Exception caught during publishing topic %s.", pub_cmd_velocity_.getTopic().c_str());
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
    ROS_ERROR("Exception caught during publishing topic %s.", pub_cmd_acceleration_.getTopic().c_str());
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
    ROS_ERROR("Exception caught during publishing topic %s.", pub_setpoint_pose_.getTopic().c_str());
  }

  // u have to return a position command
  // can set the jerk to 0
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd_));
}

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
    ROS_ERROR("Exception caught during publishing topic %s.", pub_diagnostics_.getTopic().c_str());
  }
}

// published diagnostics in reguar intervals
void MpcTracker::diagnosticsThread(void) {

  ROS_INFO("Diagnostics thread started.");
  ros::Rate r(diagnostics_rate);

  while (ros::ok()) {

    publishDiagnostics();
    r.sleep();
  }
}

// TODO split mpcThread to simulation thread
void MpcTracker::mpcThread(void) {

  ROS_INFO("Mpc thread started.");
  ros::Time     begin, end;
  ros::Duration interval;

  ros::Rate r(1 / dt);

  int timer = 0;

  while (ros::ok()) {

    while (!is_active && ros::ok()) {
      r.sleep();
    }

    begin = ros::Time::now();

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
            ROS_INFO("Done tracking trajectory.");
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
      ROS_WARN_THROTTLE(10.0, "MPC is Running %2.2f%% slower than it should.", 100 * mpc_total_delay / (ros::Time::now() - mpc_start_time).toSec());
    }

    mpc_computed_ = true;

    r.sleep();
  }
}

bool MpcTracker::set_rel_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

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
    ROS_INFO("Setting Relative Goal to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f which moves it to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f.", set_x, set_y, set_z,
             set_yaw, abs_x, abs_y, abs_z, abs_yaw);
  } else {
    ROS_INFO("Setting Relative Goal to x: %2.2f y: %2.2f z: %2.2f which moves it to x: %2.2f y: %2.2f z: %2.2f.", set_x, set_y, set_z, abs_x, abs_y, abs_z);
  }

  publishDiagnostics();

  return true;
}

// callback for goToRelative service
bool MpcTracker::gotorelative_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!set_rel_goal(req.goal[0], req.goal[1], req.goal[2], req.goal[3], true)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
    return true;
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to relative x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", req.goal[0], req.goal[1], req.goal[2], req.goal[3]);
  res.message = tempStr;

  return true;
}

// callback for goToAltitude service
bool MpcTracker::gotoaltitude_service_cmd_cb(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!set_goal(x(0, 0), x(3, 0), req.goal, x_yaw(0, 0), false)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
    return true;
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to altitude: %2.2f", req.goal);
  res.message = tempStr;

  return true;
}

// callback got goToRelative
void MpcTracker::pos_rel_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {

  if (failsafe_triggered) {

    return;
  }

  set_rel_goal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
}


// method for setting desired trajectory
bool MpcTracker::trajectoryLoad(const mrs_msgs::TrackerTrajectory &msg, std::string &message) {

  if (failsafe_triggered) {

    message = "Failsafe is active!";
    ROS_WARN("%s", message.c_str());
    return false;
  }

  if (int(msg.points.size()) > (max_trajectory_size - horizon_len - 1)) {

    ROS_WARN("Cannot load trajectory, its too large (%d).", (int)msg.points.size());

    char buffer[60];
    sprintf(buffer, "Cannot load trajectory, its too large (%d).", (int)msg.points.size());
    message = buffer;
    return false;

  } else if (msg.points.size() == 0) {

    message = "Cannot load trajectory with size 0.";
    ROS_WARN("%s", message.c_str());
    return false;

    ROS_INFO("MpcTracker: ");

  } else {

    if (debug_) {
      try {
        pub_debug_trajectory_.publish(msg);
      }
      catch (...) {
        ROS_ERROR("Exception caught during publishing topic %s.", pub_debug_trajectory_.getTopic().c_str());
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

// callback for loading desired trajectory
void MpcTracker::trajectory_cmd_cb(const mrs_msgs::TrackerTrajectory::ConstPtr &msg) {

  std::string message;
  trajectoryLoad(*msg, message);
}

// service for setting desired trajectory
bool MpcTracker::trajectory_service_cb(mrs_msgs::TrackerTrajectorySrv::Request &req, mrs_msgs::TrackerTrajectorySrv::Response &res) {

  std::string message;
  res.success = trajectoryLoad(req.trajectory_msg, message);
  res.message = message;
  return true;
}

// set absolute goal
bool MpcTracker::set_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw) {

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
    ROS_INFO("Setting Goal to x: %2.2f y: %2.2f z: %2.2f yaw: %2.2f", set_x, set_y, set_z, set_yaw);
  } else {
    ROS_INFO("Setting Goal to x: %2.2f y: %2.2f z: %2.2f", set_x, set_y, set_z);
  }

  publishDiagnostics();

  return true;
}

// callback for goTo service
bool MpcTracker::goto_service_cmd_cb(mrs_msgs::Vec4::Request &req, mrs_msgs::Vec4::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (!set_goal(req.goal[0], req.goal[1], req.goal[2], req.goal[3], true)) {

    res.success = false;
    res.message = "Cannot set the goal. It is probably outside of the safety area.";
    return true;
  }

  res.success = true;
  char tempStr[100];
  sprintf((char *)&tempStr, "Going to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", req.goal[0], req.goal[1], req.goal[2], req.goal[3]);
  res.message = tempStr;
  return true;
}

// callback for goTo
void MpcTracker::pos_cmd_cb(const mrs_msgs::TrackerPointStamped::ConstPtr &msg) {

  if (failsafe_triggered) {

    return;
  }

  set_goal(msg->position.x, msg->position.y, msg->position.z, msg->position.yaw, msg->use_yaw);
}

bool MpcTracker::start_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (trajectory_set_) {

    des_trajectory_mutex.lock();
    tracking_trajectory_ = true;
    trajectory_idx       = 0;
    des_trajectory_mutex.unlock();

    ROS_INFO("Starting trajectory following.");

    res.success = true;
    res.message = "Starting trajectory following.";

    publishDiagnostics();

  } else {

    ROS_WARN("Cannot start trajectory following, trajectory not set.");
    res.success = false;
    res.message = "Trajectory not set.";
  }

  return true;
}

bool MpcTracker::stop_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

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

    ROS_INFO("Stopping trajectory following, staying at x: %2.2f, y: %2.2f, z: %2.2f.", x(0, 0), x(3, 0), x(6, 0));

    res.success = true;
    char tempStr[100];
    sprintf((char *)&tempStr, "Staying at x: %3.2f, y: %2.2f, z: %2.2f", x(0, 0), x(3, 0), x(6, 0));

    publishDiagnostics();

  } else {

    ROS_WARN("Cannot stop trajectory trakcing, it is already stopped.");
    res.success = false;
    res.message = "Already at stop.";
  }

  return true;
}

bool MpcTracker::fly_to_trajectory_start_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (trajectory_set_) {

    if (!set_goal(des_x_whole_trajectory[0], des_y_whole_trajectory[0], des_z_whole_trajectory[0], des_yaw_whole_trajectory[0], true)) {

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

      ROS_INFO("Flying to trajectory start pooint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
               des_z_whole_trajectory[0], des_yaw_whole_trajectory[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
              des_z_whole_trajectory[0], des_yaw_whole_trajectory[0]);
    } else {
      ROS_INFO("Flying to trajectory start pooint x: %2.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0],
               des_z_whole_trajectory[0]);
      sprintf((char *)&tempStr, "Flying to x: %3.2f, y: %2.2f, z: %2.2f", des_x_whole_trajectory[0], des_y_whole_trajectory[0], des_z_whole_trajectory[0]);
    }
    res.success = true;
    res.message = tempStr;

    publishDiagnostics();

  } else {
    ROS_WARN("Cannot fly to trajectory start point, trajectory not set!");

    res.success = false;
    res.message = "Trajectory not set!";
  }

  return true;
}

bool MpcTracker::resume_trajectory_following_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (failsafe_triggered) {

    res.success = false;
    res.message = "Failsafe is active!";
    return true;
  }

  if (trajectory_set_) {

    if (trajectory_idx < (trajectory_size - 1)) {

      des_trajectory_mutex.lock();
      tracking_trajectory_ = true;
      des_trajectory_mutex.unlock();

      ROS_INFO("Resuming trajectory following.");
      res.success = true;
      res.message = "Resuming trajectory following.";

      publishDiagnostics();

    } else {
      ROS_WARN("Cannot resume trajectory tracking, trajectory is already finished.");
      res.success = false;
      res.message = "Trajectory already finished.";
    }

  } else {
    ROS_WARN("Cannot resume trajectory following, trajectory not set");
    res.success = false;
    res.message = "Trajectory not set!";
  }

  return true;
}

const mrs_msgs::TrackerStatus::Ptr MpcTracker::status() {

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

bool MpcTracker::failsafe_trigger_service_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {

  if (trigger_failsafe()) {

    res.success = true;
    res.message = "Failsafe activated";
  } else {

    res.success = true;
    res.message = "Failsafe deactivated!";
  }

  publishDiagnostics();

  return true;
}
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::MpcTracker, mrs_mav_manager::Tracker)
