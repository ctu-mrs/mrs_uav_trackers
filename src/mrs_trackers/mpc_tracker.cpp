#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <math.h>
#include <mav_manager/Vec4.h>
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
#include <quadrotor_msgs/TrackerStatus.h>
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <std_srvs/Trigger.h>
#include <tf/transform_datatypes.h>
#include <trackers_manager/Tracker.h>
#include <cmath>
#include <eigen3/Eigen/Eigen>
#include <mutex>
#include <thread>
extern "C" {
#include <solver.h>
}

Vars      vars;
Params    params;
Workspace work;
Settings  settings;

using namespace Eigen;

class MpcTracker : public trackers_manager::Tracker {
public:
  MpcTracker(void);

  void Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh);
  bool Activate(const quadrotor_msgs::PositionCommand::ConstPtr &cmd);
  void Deactivate(void);

  const quadrotor_msgs::PositionCommand::ConstPtr update(const nav_msgs::Odometry::ConstPtr &msg);
  const quadrotor_msgs::TrackerStatus::Ptr status();

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

  // Cvxgen
  bool debug_;

  quadrotor_msgs::PositionCommand position_cmd_;  // message being returned

  bool      odom_set_, active_;
  double    kx_[3], kv_[3];
  double    new_kx_[3], new_kv_[3];
  double    cur_yaw_;
  ros::Time odomLastTime;

  // variables for yaw tracker
  double max_yaw_rate;
  double yaw_gain;

  // safety area
  ConvexPolygon *safety_area;
  bool           use_safety_area;

  // variables regarding the MPC controller
  int    n;                                    // number of states
  int    m;                                    // number of inputs
  int    horizon_len;                          // lenght of the prediction horizon
  int    n_variables;                          // number of variables in the optimization
  double max_vertical_ascending_speed;         // maximum allowed horizontal speed for the mpc controller
  double max_horizontal_speed;                 // maximum allowed vertical speed for the mpc controller
  double max_vertical_ascending_acceleration;  // maximum allowed horizontal acceleration
  double max_horizontal_acceleration;          // maximum allowed vertical acceleration
  double max_vertical_descending_acceleration;
  double max_vertical_descending_speed;
  double max_altitude;

  double tracking_error_threshold;  // for switching large error and small error tracking
  double diagnostic_tracking_threshold;

  double   dt, dt2;         // time difference of the dynamical system
  MatrixXd A;               // system matrix
  MatrixXd A2;              // system matrix 2
  MatrixXd B;               // input matrix
  MatrixXd B2;              // input matrix
  MatrixXd U;               // matrix for reshaping inputs
  MatrixXd A_roof;          // BIG main matrix
  MatrixXd B_roof;          // BIG input matrix
  MatrixXd B_roof_reduced;  // BIG input matrix reduced by U
  MatrixXd Q;               // small penalization matrix for large error
  MatrixXd Q2;              // small penalization matrix for small error
  MatrixXd P;               // small penalization of input actions
  MatrixXd Q_roof;          // BIG matrix of coeficients of quadratic penalization for large error
  MatrixXd Q_roof_2;        // BIG matrix of coeficients of quadratic penalization for small error
  MatrixXd P_roof;          // BIG matrix of coeficients of penalization of inputs
  MatrixXd H_inv;           // inversion of the main matrix of the quadratic form
  MatrixXd H;               // inversion of the main matrix of the quadratic form

  MatrixXd X_0;
  MatrixXd c;
  MatrixXd u_cf;
  MatrixXd u;
  MatrixXd states;

  // trajectories
  MatrixXd des_x_trajectory;  // trajectory reference over the prediction horizon
  MatrixXd des_y_trajectory;  // trajectory reference over the prediction horizon
  MatrixXd des_z_trajectory;  // trajectory reference over the prediction horizon
  MatrixXd des_x_filtered;    // filtered trajectory reference over the horizon
  MatrixXd des_y_filtered;    // filtered trajectory reference over the horizon
  MatrixXd des_z_filtered;    // filtered trajectory reference over the horizon

  VectorXd des_x_whole_trajectory;    // long trajectory reference
  VectorXd des_y_whole_trajectory;    // long trajectory reference
  VectorXd des_z_whole_trajectory;    // long trajectory reference
  VectorXd des_yaw_whole_trajectory;  // long trajectory reference
  bool     use_yaw_in_trajectory;

  bool tracking_trajectory_;  // are we currently tracking a trajectory
  int  trajectory_idx;        // index in the currently tracked trajectory
  int  trajectory_size;       // size of the tracked trajectory
  int  max_trajectory_size;   // maximum length of the trajectory
  bool trajectory_set_;       // true if trajectory was set
  int  trajectory_count;      // counting number of trajectories uploaded to the tracker
  bool loop;                  // whether we are looping the trajectory

  MatrixXd reference;  // reference for the controller
  MatrixXd x;          // current state of the uav

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
  void loadReferenceForCvxgen(int k);
  void getStatesFromCvxgen(int k);
  void setTrajectory(float x, float y, float z);
  bool trajectoryLoad(const mrs_msgs::TrackerTrajectory &msg, std::string &message);
  void     filterReference(void);
  VectorXd integrate(VectorXd &in, double dt, double integrational_const);
  void validateYawSetpoint();
  bool set_rel_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool gotorelative_service_cmd_cb(mav_manager::Vec4::Request &req, mav_manager::Vec4::Response &res);
  bool gotoaltitude_service_cmd_cb(mrs_msgs::Vec1::Request &req, mrs_msgs::Vec1::Response &res);
  bool set_goal(double set_x, double set_y, double set_z, double set_yaw, bool set_use_yaw);
  bool goto_service_cmd_cb(mav_manager::Vec4::Request &req, mav_manager::Vec4::Response &res);
  bool failsafe_trigger_service_cmd_cb(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
  void rc_cb(const mavros_msgs::RCInConstPtr &msg);
  bool   trigger_failsafe();
  void   publishDiagnostics();
  double triangleArea(Eigen::VectorXd a, Eigen::VectorXd b, Eigen::VectorXd c);
  bool pointInBoundary(Eigen::MatrixXd boundary, double px, double py);

  const double pi = 3.1415926535897;
};

MpcTracker::MpcTracker(void) : odom_set_(false), active_(false), mpc_computed_(false) {
}

void MpcTracker::futureTrajectoryThread(void) {

  ros::Rate r(predicted_trajectory_publish_rate);

  while (ros::ok()) {

    while (!active_ && ros::ok()) {
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
void MpcTracker::Initialize(const ros::NodeHandle &nh, const ros::NodeHandle &parent_nh) {

  // Some cvxgen stuff
  set_defaults();
  setup_indexing();
  settings.verbose   = 0;
  settings.max_iters = 25;

  params.Q[0]  = 5000;
  params.Q[1]  = 0;
  params.Q[2]  = 0;
  params.R[0]  = 500;
  params.S[0] = 500;
  params.A[0]  = 1;
  params.A[1]  = 1;
  params.A[2]  = 1;
  params.A[3]  = 0.2;
  params.A[4]  = 0.2;
  params.Af[0] = 1;
  params.Af[1] = 1;
  params.Af[2] = 1;
  params.Af[3] = 0.01;
  params.Af[4] = 0.01;
  params.B[0]  = 0.2;
  params.Bf[0] = 0.01;

  params.x_ss_1[1]  = 0;
  params.x_ss_2[1]  = 0;
  params.x_ss_3[1]  = 0;
  params.x_ss_4[1]  = 0;
  params.x_ss_5[1]  = 0;
  params.x_ss_6[1]  = 0;
  params.x_ss_7[1]  = 0;
  params.x_ss_8[1]  = 0;
  params.x_ss_9[1]  = 0;
  params.x_ss_10[1] = 0;
  params.x_ss_11[1] = 0;
  params.x_ss_12[1] = 0;
  params.x_ss_13[1] = 0;
  params.x_ss_14[1] = 0;
  params.x_ss_15[1] = 0;
  params.x_ss_16[1] = 0;
  params.x_ss_17[1] = 0;
  params.x_ss_18[1] = 0;
  params.x_ss_19[1] = 0;
  params.x_ss_20[1] = 0;
  params.x_ss_21[1] = 0;
  params.x_ss_22[1] = 0;
  params.x_ss_23[1] = 0;
  params.x_ss_24[1] = 0;
  params.x_ss_25[1] = 0;
  params.x_ss_26[1] = 0;
  params.x_ss_27[1] = 0;
  params.x_ss_28[1] = 0;
  params.x_ss_29[1] = 0;
  params.x_ss_30[1] = 0;
  params.x_ss_31[1] = 0;
  params.x_ss_32[1] = 0;
  params.x_ss_33[1] = 0;
  params.x_ss_34[1] = 0;
  params.x_ss_35[1] = 0;
  params.x_ss_36[1] = 0;
  params.x_ss_37[1] = 0;
  params.x_ss_38[1] = 0;
  params.x_ss_39[1] = 0;
  params.x_ss_40[1] = 0;


  params.x_ss_1[2]  = 0;
  params.x_ss_2[2]  = 0;
  params.x_ss_3[2]  = 0;
  params.x_ss_4[2]  = 0;
  params.x_ss_5[2]  = 0;
  params.x_ss_6[2]  = 0;
  params.x_ss_7[2]  = 0;
  params.x_ss_8[2]  = 0;
  params.x_ss_9[2]  = 0;
  params.x_ss_10[2] = 0;
  params.x_ss_11[2] = 0;
  params.x_ss_12[2] = 0;
  params.x_ss_13[2] = 0;
  params.x_ss_14[2] = 0;
  params.x_ss_15[2] = 0;
  params.x_ss_16[2] = 0;
  params.x_ss_17[2] = 0;
  params.x_ss_18[2] = 0;
  params.x_ss_19[2] = 0;
  params.x_ss_20[2] = 0;
  params.x_ss_21[2] = 0;
  params.x_ss_22[2] = 0;
  params.x_ss_23[2] = 0;
  params.x_ss_24[2] = 0;
  params.x_ss_25[2] = 0;
  params.x_ss_26[2] = 0;
  params.x_ss_27[2] = 0;
  params.x_ss_28[2] = 0;
  params.x_ss_29[2] = 0;
  params.x_ss_30[2] = 0;
  params.x_ss_31[2] = 0;
  params.x_ss_32[2] = 0;
  params.x_ss_33[2] = 0;
  params.x_ss_34[2] = 0;
  params.x_ss_35[2] = 0;
  params.x_ss_36[2] = 0;
  params.x_ss_37[2] = 0;
  params.x_ss_38[2] = 0;
  params.x_ss_39[2] = 0;
  params.x_ss_40[2] = 0;


  ros::NodeHandle priv_nh(nh, "mpc_tracker");

  failsafe_triggered = false;

  std::vector<double> tempList, UvaluesList;
  int                 tempIdx;

  nh.param("debug", debug_, false);

  // safety area
  nh.param("use_safety_area", use_safety_area, false);
  // load the main system matrix
  nh.getParam("safety_area", tempList);

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

  // pload parameters for yaw_tracker
  nh.param("yawTracker/maxYawRate", max_yaw_rate, 0.0);
  nh.param("yawTracker/yawGain", yaw_gain, 0.0);
  desired_yaw = 0;

  // load the dynamicall model parameters
  nh.param("dynamicalModel/numberOfStates", n, -1);
  nh.param("dynamicalModel/numberOfInputs", m, -1);
  nh.param("dynamicalModel/dt", dt, 0.0);
  nh.param("dynamicalModel/dt2", dt2, 0.0);

  // failsafe
  nh.param("use_rc_failsafe", use_rc_failsafe, false);
  nh.param("rc_failsafe_threshold", rc_failsafe_threshold, 2000);
  nh.param("rc_failsafe_channel", rc_failsafe_channel, 9);
  rc_failsafe_time = ros::Time::now();

  if (use_rc_failsafe) {
    ROS_INFO("RC Failsafe ON, channel = %d, threshold = %d", rc_failsafe_channel, rc_failsafe_threshold);
  }

  // load the main system matrix
  nh.getParam("dynamicalModel/A", tempList);
  A = MatrixXd::Zero(n, n);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      A(i, j) = tempList[tempIdx++];
    }
  }

  // load the second main system matrix
  nh.getParam("dynamicalModel/A2", tempList);
  A2 = MatrixXd::Zero(n, n);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      A2(i, j) = tempList[tempIdx++];
    }
  }

  // load the input matrix
  nh.getParam("dynamicalModel/B", tempList);
  B = MatrixXd::Zero(n, m);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      B(i, j) = tempList[tempIdx++];
    }
  }

  // load the input matrix
  nh.getParam("dynamicalModel/B2", tempList);
  B2 = MatrixXd::Zero(n, m);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      B2(i, j) = tempList[tempIdx++];
    }
  }

  ROS_INFO("MPC Tracker initiated with system parameters: n: %d, m: %d, dt: %0.3f, dt2: %0.3f", n, m, dt, dt2);
  ROS_INFO_STREAM("\nA:\n" << A << "\nA2:\n" << A2 << "\nB:\n" << B << "\nB2:\n" << B2);

  // load the MPC parameters
  nh.param("mpc/horizon_len", horizon_len, -1);
  nh.param("mpc/numberOfVariables", n_variables, -1);
  nh.param("mpc/maxHorizontalSpeed", max_horizontal_speed, 0.0);
  nh.param("mpc/maxHorizontalAcceleration", max_horizontal_acceleration, 0.0);
  nh.param("mpc/maxTrajectorySize", max_trajectory_size, 0);

  nh.param("mpc/maxVerticalAscendingSpeed", max_vertical_ascending_speed, 0.0);
  nh.param("mpc/maxVerticalAscendingAcceleration", max_vertical_ascending_acceleration, 0.0);

  nh.param("mpc/maxVerticalDescendingSpeed", max_vertical_descending_speed, 0.0);
  nh.param("mpc/maxVerticalDescendingAcceleration", max_vertical_descending_acceleration, 0.0);
  nh.param("mpc/maxAltitude", max_altitude, 10.0);

  nh.param("mpc/trackingErrorThr", tracking_error_threshold, 1.0);
  nh.param("diagnostics_rate", diagnostics_rate, 1.0);
  nh.param("diagnostic_tracking_threshold", diagnostic_tracking_threshold, 1.0);

  // load penalization matrix
  nh.getParam("mpc/Q", tempList);
  Q = MatrixXd::Zero(n, n);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      Q(i, j) = tempList[tempIdx++];
    }
  }

  // load end-state penalization matrix
  nh.getParam("mpc/Q2", tempList);
  Q2 = MatrixXd::Zero(n, n);

  tempIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      Q2(i, j) = tempList[tempIdx++];
    }
  }

  // load input penalization matrix
  nh.getParam("mpc/P", tempList);
  P = MatrixXd::Zero(m, m);

  tempIdx = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {

      P(i, j) = tempList[tempIdx++];
    }
  }

  // load the U matrix
  nh.getParam("mpc/U", UvaluesList);
  U = MatrixXd::Zero(horizon_len * m, n_variables);

  tempIdx      = 0;
  int tempIdx2 = 0;

  for (unsigned long i = 0; i < UvaluesList.size(); i++) {
    for (int j = 0; j < UvaluesList[i]; j++) {

      U.block(tempIdx, tempIdx2, m, m) = MatrixXd::Identity(m, m);
      tempIdx += m;
    }
    tempIdx2 += m;
  }

  ROS_INFO(
      "MPC parameters: horizon_len: %d, numberOfVariables: %d, max_vertical_ascending_speed: %2.1f, max_horizontal_speed: %2.1f, max_horizontal_acceleration: "
      "%2.1f, max_vertical_ascending_acceleration: %2.1f, max_vertical_descending_speed: %2.1f, max_vertical_descending_acceleration: %2.1f, "
      "tracking_error_threshold: %2.1f",
      horizon_len, n_variables, max_vertical_ascending_speed, max_horizontal_speed, max_horizontal_acceleration, max_vertical_ascending_acceleration,
      max_vertical_descending_speed, max_vertical_descending_acceleration, tracking_error_threshold);
  ROS_INFO_STREAM("\nQ:\n" << Q << "\nP:\n" << P << "\nQ2:\n" << Q2);

  // prepare the MPC matrice

  // prepare A_roof matrix
  // A_roof = [A;
  //           A^2;
  //           A^4;
  //           ...;
  //           A^n];

  A_roof = MatrixXd::Zero(horizon_len * n, n);

  tempMatrix = MatrixXd(n, n);  // for acumulating the powers of A
  tempMatrix = A;

  for (int i = 0; i < horizon_len; i++) {

    A_roof.middleRows(i * n, n) = tempMatrix;
    tempMatrix = tempMatrix * A2;  // compute next power of A
  }

  // B_roof matrix
  //			% n = prediction horizon length
  //			% B_roof = [B1,        0,        0,   0;
  //         				  AB1,       B2,       0,   0;
  //         				  A^2B1,     AB2,      B2,  0;
  //         				  ...;
  //         				  A^(n-2)B1, A^(n-1)B2, ..., 0;
  //         				  A^(n-1)B1, A^(n-2)B2, ..., B2;

  B_roof = MatrixXd::Zero(horizon_len * n, horizon_len * m);

  B_roof.block(0, 0, n, m)         = B;
  B_roof.block(1 * n, 0 * m, n, m) = A * B;
  B_roof.block(1 * n, 1 * m, n, m) = B2;

  for (int i = 2; i < horizon_len; i++) {    // over rows of submatrices
    for (int j = 2; j < horizon_len; j++) {  // over cols of submatrices

      // replicate the previous line but shift it one block right
      B_roof.block(i * n, j * m, n, m) = B_roof.block((i - 1) * n, (j - 1) * m, n, m);
    }

    // create the first block of the new line
    B_roof.block(i * n, 0, n, m) = A2 * B_roof.block((i - 1) * n, 0, n, m);

    // create the second block of the new line
    B_roof.block(i * n, m, n, m) = A2 * B_roof.block((i - 1) * n, m, n, m);
  }

  // create the reduced version of B_roof
  B_roof_reduced = MatrixXd::Zero(horizon_len * n, n_variables);
  B_roof_reduced = B_roof * U;

  // Q_roof matrix
  // n = number of system states
  // Q = n*n
  //     diagonal, penalizing control errors
  // Q_roof = [Q,   0,   ...,  0;
  //           0,   Q,   ...,  0;
  //           ..., ..., Q,    0;
  //           0,   ..., ...,  S];

  Q_roof = MatrixXd::Zero(horizon_len * n, horizon_len * n);

  for (int i = 0; i < horizon_len; i++) {

    Q_roof.block(i * n, i * n, n, n) = Q;
  }

  // Q_roof_2 matrix
  // n = number of system states
  // Q2 = n*n
  //      diagonal, penalizing control errors
  // Q_roof_2 = [Q,   0,   ...,  0;
  //             0,   Q,   ...,  0;
  //             ..., ..., Q,    0;
  //             0,   ..., ...,  S];

  Q_roof_2 = MatrixXd::Zero(horizon_len * n, horizon_len * n);

  for (int i = 0; i < horizon_len; i++) {

    Q_roof_2.block(i * n, i * n, n, n) = Q2;
  }

  // P_roof matrix
  // penalizing control actions
  // P_roof = [P,   0,   ...,  0;
  //           0,   P,   ...,  0;
  //           ..., ..., P,    0;
  //           0,   ..., ...,  P];

  P_roof = MatrixXd::Zero(n_variables, n_variables);

  tempIdx = 0;
  for (unsigned long i = 0; i < UvaluesList.size(); i++) {

    P_roof.block(i * m, i * m, m, m) = P * UvaluesList[i];
  }

  P_roof.block(0, 0, m, m) = P_roof.block(0, 0, m, m) / (dt2 / dt);

  // initialize other matrices
  x                = MatrixXd::Zero(n, 1);
  X_0              = MatrixXd::Zero(horizon_len * n, 1);
  c                = MatrixXd::Zero(n_variables * m, 1);
  u_cf             = MatrixXd::Zero(n_variables * m, 1);
  u                = MatrixXd::Zero(horizon_len * m, 1);
  states           = MatrixXd::Zero(horizon_len * n, 1);
  H_inv            = MatrixXd::Zero(n_variables, n_variables);
  H                = MatrixXd::Zero(n_variables, n_variables);
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
  reference = MatrixXd::Zero(n * horizon_len, 1);

  des_x_trajectory = MatrixXd::Zero(horizon_len, 1);
  des_y_trajectory = MatrixXd::Zero(horizon_len, 1);
  des_z_trajectory = MatrixXd::Zero(horizon_len, 1);

  des_x_filtered = MatrixXd::Zero(horizon_len, 1);
  des_y_filtered = MatrixXd::Zero(horizon_len, 1);
  des_z_filtered = MatrixXd::Zero(horizon_len, 1);

  H = B_roof_reduced.transpose() * Q_roof * B_roof_reduced + P_roof;

  // create the inversion of H matrix - the main matrix of the qudratic form
  H_inv = (0.5 * H).inverse();

  // subscriber for setting the position setpoint
  sub_pos_cmd_ = priv_nh.subscribe("desired_position", 1, &MpcTracker::pos_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  // subscriber for setting the relative setpoint
  sub_pos_rel_cmd_ = priv_nh.subscribe("desired_relative_position", 1, &MpcTracker::pos_rel_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  // subscriber for desired trajectory
  sub_trajectory_ = priv_nh.subscribe("desired_trajectory", 1, &MpcTracker::trajectory_cmd_cb, this, ros::TransportHints().tcpNoDelay());

  if (debug_) {
    pub_debug_trajectory_ = priv_nh.advertise<mrs_msgs::TrackerTrajectory>("debug_set_trajectory", 1);
  }

  // service for desired trajectory
  ser_set_trajectory_ = priv_nh.advertiseService("set_trajectory", &MpcTracker::trajectory_service_cb, this);

  // subscriber for rc transmitter
  sub_rc_ = priv_nh.subscribe("rc_in", 1, &MpcTracker::rc_cb, this, ros::TransportHints().tcpNoDelay());

  // service for starting trajectory following
  ser_start_trajectory_following_ = priv_nh.advertiseService("start_trajectory_following", &MpcTracker::start_trajectory_following_cmd_cb, this);

  // service for stopping trajectory following
  ser_stop_trajectory_following_ = priv_nh.advertiseService("stop_trajectory_following", &MpcTracker::stop_trajectory_following_cmd_cb, this);

  // service for resuming trajectory following
  ser_resume_trajectory_following_ = priv_nh.advertiseService("resume_trajectory_following", &MpcTracker::resume_trajectory_following_cmd_cb, this);

  // service for flying to the trajectory start point
  ser_fly_to_trajectory_start_ = priv_nh.advertiseService("fly_to_trajectory_start", &MpcTracker::fly_to_trajectory_start_cmd_cb, this);

  // service goto service
  goto_service_cmd_cb_ = priv_nh.advertiseService("goTo", &MpcTracker::goto_service_cmd_cb, this);

  // service goToRelative service
  gotorelative_service_cmd_cb_ = priv_nh.advertiseService("goToRelative", &MpcTracker::gotorelative_service_cmd_cb, this);

  // service goToAltitude service
  gotoaltitude_service_cmd_cb_ = priv_nh.advertiseService("goToAltitude", &MpcTracker::gotoaltitude_service_cmd_cb, this);

  // service for triggering failsafe
  failsafe_trigger_service_cmd_ = priv_nh.advertiseService("failsafe", &MpcTracker::failsafe_trigger_service_cmd_cb, this);

  // publishers for debugging
  pub_cmd_pose_         = priv_nh.advertise<nav_msgs::Odometry>("cmd_pose", 1);
  pub_cmd_velocity_     = priv_nh.advertise<geometry_msgs::Vector3>("cmd_velocity", 1);
  pub_cmd_acceleration_ = priv_nh.advertise<geometry_msgs::Vector3>("md_acceleration", 1);
  pub_diagnostics_      = priv_nh.advertise<mrs_msgs::TrackerDiagnostics>("diagnostics", 1);

  // publisher for the current setpoint
  pub_setpoint_pose_ = priv_nh.advertise<nav_msgs::Odometry>("setpoint_pose", 1);

  // collision avoidance
  nh.param("uav_name", uav_name_, std::string());

  if (uav_name_.empty()) {
    ROS_ERROR("uav_name has not been specified!");
    ros::shutdown();
  }

  // extract the numerical name
  sscanf(uav_name_.c_str(), "uav%d", &uav_num_name);
  ROS_INFO("Numerical ID of this UAV is %d", uav_num_name);

  nh.getParam("mrs_collision_avoidance/drone_names", other_drone_names_);

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

  nh.param("mrs_collision_avoidance/enable", mrs_collision_avoidance, false);

  // create publisher for predicted trajectory
  predicted_trajectory_publisher       = priv_nh.advertise<mrs_msgs::FutureTrajectory>("predicted_trajectory", 1);
  debug_predicted_trajectory_publisher = priv_nh.advertise<geometry_msgs::PoseArray>("predicted_trajectory_debugging", 1);

  // preallocate future trajectory
  predicted_future_trajectory = MatrixXd::Zero(horizon_len * n, 1);

  collision_altitude_offeset = 0;
  avoiding_collision_time    = ros::Time::now();
  being_avoided_time         = ros::Time::now();
  future_was_predicted       = false;
  earliest_collision_idx     = INT_MAX;

  nh.param("predicted_trajectory_topic", predicted_trajectory_topic, std::string());

  nh.param("mrs_collision_avoidance/predicted_trajectory_publish_rate", predicted_trajectory_publish_rate, 1.0);
  nh.param("mrs_collision_avoidance/correction", mrs_collision_avoidance_correction, 2.0);
  nh.param("mrs_collision_avoidance/radius", mrs_collision_avoidance_radius, 1.0);
  nh.param("mrs_collision_avoidance/altitude_threshold", mrs_collision_avoidance_altitude_threshold, 1.0);
  nh.param("mrs_collision_avoidance/collision_horizontal_speed_coef", collision_horizontal_speed_coef, 1.0);
  nh.param("mrs_collision_avoidance/collision_horizontal_acceleration_coef", collision_horizontal_acceleration_coef, 1.0);
  nh.param("mrs_collision_avoidance/collision_slow_down_before", collision_slow_down_before, 0);
  nh.param("mrs_collision_avoidance/collision_slowing_hysteresis", collision_slowing_hysteresis, 0.0);
  nh.param("mrs_collision_avoidance/trajectory_timeout", collision_trajectory_timeout, 1.0);

  // collision avoidance toggle service
  collision_avoidance_service = priv_nh.advertiseService("collision_avoidance", &MpcTracker::collision_avoidance_toggle_cb, this);

  if (predicted_trajectory_topic.empty()) {
    ROS_ERROR("You need to define predicted trajectory topic name in the launch file.");
    ros::shutdown();
  }

  // create subscribers on other drones diagnostics
  for (unsigned long i = 0; i < other_drone_names_.size(); i++) {

    std::string topic_name = std::string("/") + other_drone_names_[i] + std::string("/") + predicted_trajectory_topic;

    ROS_INFO("subscribing to %s", topic_name.c_str());

    other_drones_subscribers.push_back(
        priv_nh.subscribe(topic_name, 1, &MpcTracker::otherDronesTrajectoriesCallback, this, ros::TransportHints().tcpNoDelay()));
  }

  // create threads and mutexes
  mpc_thread                  = std::thread(&MpcTracker::mpcThread, this);
  diagnostics_thread          = std::thread(&MpcTracker::diagnosticsThread, this);
  predicted_trajectory_thread = std::thread(&MpcTracker::futureTrajectoryThread, this);
}

void MpcTracker::otherDronesTrajectoriesCallback(const mrs_msgs::FutureTrajectoryConstPtr &msg) {

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // update the diagnostics
  other_drones_trajectories[msg->uav_name] = temp_trajectory;

  // ROS_INFO_THROTTLE(1, "Getting trajectory from drone %s", msg->uav_name.c_str());
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

  double difference_x, difference_y, difference;
  double maxSpeed;
  double totalSpeed;

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

            ROS_WARN_THROTTLE(1, "Potential collision detected with %s!", u->first.c_str());

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

        // only do the avoidance manouver when we are higher number the the other one
        // ! or if the other drones avoidance is turned off
        if ((u->second.collision_avoidance == false) || (other_drone_id < uav_num_name) ||
            (des_z_trajectory(v) > (u->second.points[v].z + mrs_collision_avoidance_correction / 2.0 + collision_altitude_offeset))) {

          ROS_INFO_THROTTLE(1, "Avoiding collision with %s.", u->first.c_str());

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
  // saturate the x and y part of the trajectory
  for (int i = 0; i < horizon_len; i++) {

    if (i == 0) {
      /* maxSpeed     = temp_horizontal_speed_limit * dt; */
      difference_x = des_x_trajectory(i, 0) - x(0, 0);
      difference_y = des_y_trajectory(i, 0) - x(3, 0);
    } else {
      /* maxSpeed     = temp_horizontal_speed_limit * dt2; */
      difference_x = des_x_trajectory(i, 0) - des_x_filtered(i - 1, 0);
      difference_y = des_y_trajectory(i, 0) - des_y_filtered(i - 1, 0);
    }

    // limit the velocity for the part of the trajectory where there is a collision
    double temp_horizontal_speed_limit = max_horizontal_speed;
    if ((avoiding_someone || being_avoided) && ((i + collision_slow_down_before) >= earliest_collision_idx)) {
      temp_horizontal_speed_limit *= collision_horizontal_speed_coef;
      ROS_INFO_THROTTLE(1, "Reducing speed in XY in %2.2f s", i * 0.2);
      if (i == 0) {
        maxSpeed = temp_horizontal_speed_limit * dt;
      } else {
        maxSpeed = temp_horizontal_speed_limit * dt2;
      }
      if (difference_x > maxSpeed)
        difference_x = maxSpeed;
      else if (difference_x < -maxSpeed)
        difference_x = -maxSpeed;
      if (difference_y > maxSpeed)
        difference_y = maxSpeed;
      else if (difference_y < -maxSpeed)
        difference_y = -maxSpeed;
    }


    // saturate the difference
    /* if (difference_x > maxSpeed) */
    /*   difference_x = maxSpeed; */
    /* else if (difference_x < -maxSpeed) */
    /*   difference_x = -maxSpeed; */
    /* if (difference_y > maxSpeed) */
    /*   difference_y = maxSpeed; */
    /* else if (difference_y < -maxSpeed) */
    /*   difference_y = -maxSpeed; */
    /* } */


    // saturate over both x and y - circle saturation
    /* if (i == 0) { */
    /*   totalSpeed = sqrt(pow(difference_x, 2) + pow(difference_y, 2)) / dt; */
    /* } else { */
    /*   totalSpeed = sqrt(pow(difference_x, 2) + pow(difference_y, 2)) / dt2; */
    /* } */
    /* if (totalSpeed > max_horizontal_speed) { */
    /*   difference_x = difference_x * (max_horizontal_speed / totalSpeed); */
    /*   difference_y = difference_y * (max_horizontal_speed / totalSpeed); */
    /* } */

    if (i == 0) {
      des_x_filtered(i, 0) = x(0, 0) + difference_x;
      des_y_filtered(i, 0) = x(3, 0) + difference_y;
    } else {
      des_x_filtered(i, 0) = des_x_filtered(i - 1, 0) + difference_x;
      des_y_filtered(i, 0) = des_y_filtered(i - 1, 0) + difference_y;
    }
  }

  /* // saturate the y part of the trajectory */
  /* for (int i = 0; i < horizon_len; i++) { */

  /*   // limit the velocity for the part of the trajectory where there is a collision */
  /*   double temp_horizontal_speed_limit = max_horizontal_speed; */
  /*   if ((avoiding_someone || being_avoided) && ((i + collision_slow_down_before) >= earliest_collision_idx)) { */
  /*     temp_horizontal_speed_limit *= collision_horizontal_speed_coef; */
  /*   } */

  /*   if (i == 0) { */
  /*     maxSpeed   = temp_horizontal_speed_limit * dt; */
  /*     difference = des_y_trajectory(i, 0) - x(3, 0); */
  /*   } else { */
  /*     maxSpeed   = temp_horizontal_speed_limit * dt2; */
  /*     difference = des_y_trajectory(i, 0) - des_y_filtered(i - 1, 0); */
  /*   } */

  /*   // saturate the difference */
  /*   if (difference > maxSpeed) */
  /*     difference = maxSpeed; */
  /*   else if (difference < -maxSpeed) */
  /*     difference = -maxSpeed; */

  /*   if (i == 0) { */
  /*     des_y_filtered(i, 0) = x(3, 0) + difference; */
  /*   } else { */
  /*     des_y_filtered(i, 0) = des_y_filtered(i - 1, 0) + difference; */
  /*   } */
  /* } */


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
    // No saturation, Cvxgen will handle this
    /*   // saturate the difference */
    /*   if (difference > max_vertical_ascending_speed * tempDt) { */

    /*     // saturated the upwards velocity only if we are not avoiding collision */
    /*     if (!avoiding_someone) { */
    /*       difference = max_vertical_ascending_speed * tempDt; */

    /*     } else { */

    /*       ROS_INFO_THROTTLE(1, "NOT saturation vertical speed."); */
    /*     } */

    /*   } else if (difference < -max_vertical_descending_speed * tempDt) */
    /*     difference = -max_vertical_descending_speed * tempDt; */

    if (i == 0) {
      des_z_filtered(i, 0) = x(6, 0) + difference;
    } else {
      des_z_filtered(i, 0) = des_z_filtered(i - 1, 0) + difference;
    }

    // saturate to maxAltitude
    if (des_z_filtered(i, 0) > max_altitude) {
      des_z_filtered(i, 0) = max_altitude;
    }
  }

  trajectory_setpoint_mutex.unlock();
}

// sets the desire trajectory based on a single setpoint
void MpcTracker::setTrajectory(float x, float y, float z) {

  trajectory_setpoint_mutex.lock();
  des_x_trajectory.fill(x);
  des_y_trajectory.fill(y);
  des_z_trajectory.fill(z);
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
void MpcTracker::loadReferenceForCvxgen(int k) {
  params.x_ss_1[0]  = reference(0 * n + (k * 3), 0);
  params.x_ss_2[0]  = reference(1 * n + (k * 3), 0);
  params.x_ss_3[0]  = reference(2 * n + (k * 3), 0);
  params.x_ss_4[0]  = reference(3 * n + (k * 3), 0);
  params.x_ss_5[0]  = reference(4 * n + (k * 3), 0);
  params.x_ss_6[0]  = reference(5 * n + (k * 3), 0);
  params.x_ss_7[0]  = reference(6 * n + (k * 3), 0);
  params.x_ss_8[0]  = reference(7 * n + (k * 3), 0);
  params.x_ss_9[0]  = reference(8 * n + (k * 3), 0);
  params.x_ss_10[0] = reference(9 * n + (k * 3), 0);
  params.x_ss_11[0] = reference(10 * n + (k * 3), 0);
  params.x_ss_12[0] = reference(11 * n + (k * 3), 0);
  params.x_ss_13[0] = reference(12 * n + (k * 3), 0);
  params.x_ss_14[0] = reference(13 * n + (k * 3), 0);
  params.x_ss_15[0] = reference(14 * n + (k * 3), 0);
  params.x_ss_16[0] = reference(15 * n + (k * 3), 0);
  params.x_ss_17[0] = reference(16 * n + (k * 3), 0);
  params.x_ss_18[0] = reference(17 * n + (k * 3), 0);
  params.x_ss_19[0] = reference(18 * n + (k * 3), 0);
  params.x_ss_20[0] = reference(19 * n + (k * 3), 0);
  params.x_ss_21[0] = reference(20 * n + (k * 3), 0);
  params.x_ss_22[0] = reference(21 * n + (k * 3), 0);
  params.x_ss_23[0] = reference(22 * n + (k * 3), 0);
  params.x_ss_24[0] = reference(23 * n + (k * 3), 0);
  params.x_ss_25[0] = reference(24 * n + (k * 3), 0);
  params.x_ss_26[0] = reference(25 * n + (k * 3), 0);
  params.x_ss_27[0] = reference(26 * n + (k * 3), 0);
  params.x_ss_28[0] = reference(27 * n + (k * 3), 0);
  params.x_ss_29[0] = reference(28 * n + (k * 3), 0);
  params.x_ss_30[0] = reference(29 * n + (k * 3), 0);
  params.x_ss_31[0] = reference(30 * n + (k * 3), 0);
  params.x_ss_32[0] = reference(31 * n + (k * 3), 0);
  params.x_ss_33[0] = reference(32 * n + (k * 3), 0);
  params.x_ss_34[0] = reference(33 * n + (k * 3), 0);
  params.x_ss_35[0] = reference(34 * n + (k * 3), 0);
  params.x_ss_36[0] = reference(35 * n + (k * 3), 0);
  params.x_ss_37[0] = reference(36 * n + (k * 3), 0);
  params.x_ss_38[0] = reference(37 * n + (k * 3), 0);
  params.x_ss_39[0] = reference(38 * n + (k * 3), 0);
  params.x_ss_40[0] = reference(39 * n + (k * 3), 0);
}
void MpcTracker::getStatesFromCvxgen(int k) {

  predicted_future_trajectory(0 + k * 3 + (0 * 9))  = *(vars.x_1);
  predicted_future_trajectory(1 + k * 3 + (0 * 9))  = *(vars.x_1 + 1);
  predicted_future_trajectory(2 + k * 3 + (0 * 9))  = *(vars.x_1 + 2);
  predicted_future_trajectory(0 + k * 3 + (1 * 9))  = *(vars.x_2);
  predicted_future_trajectory(1 + k * 3 + (1 * 9))  = *(vars.x_2 + 1);
  predicted_future_trajectory(2 + k * 3 + (1 * 9))  = *(vars.x_2 + 2);
  predicted_future_trajectory(0 + k * 3 + (2 * 9))  = *(vars.x_3);
  predicted_future_trajectory(1 + k * 3 + (2 * 9))  = *(vars.x_3 + 1);
  predicted_future_trajectory(2 + k * 3 + (2 * 9))  = *(vars.x_3 + 2);
  predicted_future_trajectory(0 + k * 3 + (3 * 9))  = *(vars.x_4);
  predicted_future_trajectory(1 + k * 3 + (3 * 9))  = *(vars.x_4 + 1);
  predicted_future_trajectory(2 + k * 3 + (3 * 9))  = *(vars.x_4 + 2);
  predicted_future_trajectory(0 + k * 3 + (4 * 9))  = *(vars.x_5);
  predicted_future_trajectory(1 + k * 3 + (4 * 9))  = *(vars.x_5 + 1);
  predicted_future_trajectory(2 + k * 3 + (4 * 9))  = *(vars.x_5 + 2);
  predicted_future_trajectory(0 + k * 3 + (5 * 9))  = *(vars.x_6);
  predicted_future_trajectory(1 + k * 3 + (5 * 9))  = *(vars.x_6 + 1);
  predicted_future_trajectory(2 + k * 3 + (5 * 9))  = *(vars.x_6 + 2);
  predicted_future_trajectory(0 + k * 3 + (6 * 9))  = *(vars.x_7);
  predicted_future_trajectory(1 + k * 3 + (6 * 9))  = *(vars.x_7 + 1);
  predicted_future_trajectory(2 + k * 3 + (6 * 9))  = *(vars.x_7 + 2);
  predicted_future_trajectory(0 + k * 3 + (7 * 9))  = *(vars.x_8);
  predicted_future_trajectory(1 + k * 3 + (7 * 9))  = *(vars.x_8 + 1);
  predicted_future_trajectory(2 + k * 3 + (7 * 9))  = *(vars.x_8 + 2);
  predicted_future_trajectory(0 + k * 3 + (8 * 9))  = *(vars.x_9);
  predicted_future_trajectory(1 + k * 3 + (8 * 9))  = *(vars.x_9 + 1);
  predicted_future_trajectory(2 + k * 3 + (8 * 9))  = *(vars.x_9 + 2);
  predicted_future_trajectory(0 + k * 3 + (9 * 9))  = *(vars.x_10);
  predicted_future_trajectory(1 + k * 3 + (9 * 9))  = *(vars.x_10 + 1);
  predicted_future_trajectory(2 + k * 3 + (9 * 9))  = *(vars.x_10 + 2);
  predicted_future_trajectory(0 + k * 3 + (10 * 9)) = *(vars.x_11);
  predicted_future_trajectory(1 + k * 3 + (10 * 9)) = *(vars.x_11 + 1);
  predicted_future_trajectory(2 + k * 3 + (10 * 9)) = *(vars.x_11 + 2);
  predicted_future_trajectory(0 + k * 3 + (11 * 9)) = *(vars.x_12);
  predicted_future_trajectory(1 + k * 3 + (11 * 9)) = *(vars.x_12 + 1);
  predicted_future_trajectory(2 + k * 3 + (11 * 9)) = *(vars.x_12 + 2);
  predicted_future_trajectory(0 + k * 3 + (12 * 9)) = *(vars.x_13);
  predicted_future_trajectory(1 + k * 3 + (12 * 9)) = *(vars.x_13 + 1);
  predicted_future_trajectory(2 + k * 3 + (12 * 9)) = *(vars.x_13 + 2);
  predicted_future_trajectory(0 + k * 3 + (13 * 9)) = *(vars.x_14);
  predicted_future_trajectory(1 + k * 3 + (13 * 9)) = *(vars.x_14 + 1);
  predicted_future_trajectory(2 + k * 3 + (13 * 9)) = *(vars.x_14 + 2);
  predicted_future_trajectory(0 + k * 3 + (14 * 9)) = *(vars.x_15);
  predicted_future_trajectory(1 + k * 3 + (14 * 9)) = *(vars.x_15 + 1);
  predicted_future_trajectory(2 + k * 3 + (14 * 9)) = *(vars.x_15 + 2);
  predicted_future_trajectory(0 + k * 3 + (15 * 9)) = *(vars.x_16);
  predicted_future_trajectory(1 + k * 3 + (15 * 9)) = *(vars.x_16 + 1);
  predicted_future_trajectory(2 + k * 3 + (15 * 9)) = *(vars.x_16 + 2);
  predicted_future_trajectory(0 + k * 3 + (16 * 9)) = *(vars.x_17);
  predicted_future_trajectory(1 + k * 3 + (16 * 9)) = *(vars.x_17 + 1);
  predicted_future_trajectory(2 + k * 3 + (16 * 9)) = *(vars.x_17 + 2);
  predicted_future_trajectory(0 + k * 3 + (17 * 9)) = *(vars.x_18);
  predicted_future_trajectory(1 + k * 3 + (17 * 9)) = *(vars.x_18 + 1);
  predicted_future_trajectory(2 + k * 3 + (17 * 9)) = *(vars.x_18 + 2);
  predicted_future_trajectory(0 + k * 3 + (18 * 9)) = *(vars.x_19);
  predicted_future_trajectory(1 + k * 3 + (18 * 9)) = *(vars.x_19 + 1);
  predicted_future_trajectory(2 + k * 3 + (18 * 9)) = *(vars.x_19 + 2);
  predicted_future_trajectory(0 + k * 3 + (19 * 9)) = *(vars.x_20);
  predicted_future_trajectory(1 + k * 3 + (19 * 9)) = *(vars.x_20 + 1);
  predicted_future_trajectory(2 + k * 3 + (19 * 9)) = *(vars.x_20 + 2);
  predicted_future_trajectory(0 + k * 3 + (20 * 9)) = *(vars.x_21);
  predicted_future_trajectory(1 + k * 3 + (20 * 9)) = *(vars.x_21 + 1);
  predicted_future_trajectory(2 + k * 3 + (20 * 9)) = *(vars.x_21 + 2);
  predicted_future_trajectory(0 + k * 3 + (21 * 9)) = *(vars.x_22);
  predicted_future_trajectory(1 + k * 3 + (21 * 9)) = *(vars.x_22 + 1);
  predicted_future_trajectory(2 + k * 3 + (21 * 9)) = *(vars.x_22 + 2);
  predicted_future_trajectory(0 + k * 3 + (22 * 9)) = *(vars.x_23);
  predicted_future_trajectory(1 + k * 3 + (22 * 9)) = *(vars.x_23 + 1);
  predicted_future_trajectory(2 + k * 3 + (22 * 9)) = *(vars.x_23 + 2);
  predicted_future_trajectory(0 + k * 3 + (23 * 9)) = *(vars.x_24);
  predicted_future_trajectory(1 + k * 3 + (23 * 9)) = *(vars.x_24 + 1);
  predicted_future_trajectory(2 + k * 3 + (23 * 9)) = *(vars.x_24 + 2);
  predicted_future_trajectory(0 + k * 3 + (24 * 9)) = *(vars.x_25);
  predicted_future_trajectory(1 + k * 3 + (24 * 9)) = *(vars.x_25 + 1);
  predicted_future_trajectory(2 + k * 3 + (24 * 9)) = *(vars.x_25 + 2);
  predicted_future_trajectory(0 + k * 3 + (25 * 9)) = *(vars.x_26);
  predicted_future_trajectory(1 + k * 3 + (25 * 9)) = *(vars.x_26 + 1);
  predicted_future_trajectory(2 + k * 3 + (25 * 9)) = *(vars.x_26 + 2);
  predicted_future_trajectory(0 + k * 3 + (26 * 9)) = *(vars.x_27);
  predicted_future_trajectory(1 + k * 3 + (26 * 9)) = *(vars.x_27 + 1);
  predicted_future_trajectory(2 + k * 3 + (26 * 9)) = *(vars.x_27 + 2);
  predicted_future_trajectory(0 + k * 3 + (27 * 9)) = *(vars.x_28);
  predicted_future_trajectory(1 + k * 3 + (27 * 9)) = *(vars.x_28 + 1);
  predicted_future_trajectory(2 + k * 3 + (27 * 9)) = *(vars.x_28 + 2);
  predicted_future_trajectory(0 + k * 3 + (28 * 9)) = *(vars.x_29);
  predicted_future_trajectory(1 + k * 3 + (28 * 9)) = *(vars.x_29 + 1);
  predicted_future_trajectory(2 + k * 3 + (28 * 9)) = *(vars.x_29 + 2);
  predicted_future_trajectory(0 + k * 3 + (29 * 9)) = *(vars.x_30);
  predicted_future_trajectory(1 + k * 3 + (29 * 9)) = *(vars.x_30 + 1);
  predicted_future_trajectory(2 + k * 3 + (29 * 9)) = *(vars.x_30 + 2);
  predicted_future_trajectory(0 + k * 3 + (30 * 9)) = *(vars.x_31);
  predicted_future_trajectory(1 + k * 3 + (30 * 9)) = *(vars.x_31 + 1);
  predicted_future_trajectory(2 + k * 3 + (30 * 9)) = *(vars.x_31 + 2);
  predicted_future_trajectory(0 + k * 3 + (31 * 9)) = *(vars.x_32);
  predicted_future_trajectory(1 + k * 3 + (31 * 9)) = *(vars.x_32 + 1);
  predicted_future_trajectory(2 + k * 3 + (31 * 9)) = *(vars.x_32 + 2);
  predicted_future_trajectory(0 + k * 3 + (32 * 9)) = *(vars.x_33);
  predicted_future_trajectory(1 + k * 3 + (32 * 9)) = *(vars.x_33 + 1);
  predicted_future_trajectory(2 + k * 3 + (32 * 9)) = *(vars.x_33 + 2);
  predicted_future_trajectory(0 + k * 3 + (33 * 9)) = *(vars.x_34);
  predicted_future_trajectory(1 + k * 3 + (33 * 9)) = *(vars.x_34 + 1);
  predicted_future_trajectory(2 + k * 3 + (33 * 9)) = *(vars.x_34 + 2);
  predicted_future_trajectory(0 + k * 3 + (34 * 9)) = *(vars.x_35);
  predicted_future_trajectory(1 + k * 3 + (34 * 9)) = *(vars.x_35 + 1);
  predicted_future_trajectory(2 + k * 3 + (34 * 9)) = *(vars.x_35 + 2);
  predicted_future_trajectory(0 + k * 3 + (35 * 9)) = *(vars.x_36);
  predicted_future_trajectory(1 + k * 3 + (35 * 9)) = *(vars.x_36 + 1);
  predicted_future_trajectory(2 + k * 3 + (35 * 9)) = *(vars.x_36 + 2);
  predicted_future_trajectory(0 + k * 3 + (36 * 9)) = *(vars.x_37);
  predicted_future_trajectory(1 + k * 3 + (36 * 9)) = *(vars.x_37 + 1);
  predicted_future_trajectory(2 + k * 3 + (36 * 9)) = *(vars.x_37 + 2);
  predicted_future_trajectory(0 + k * 3 + (37 * 9)) = *(vars.x_38);
  predicted_future_trajectory(1 + k * 3 + (37 * 9)) = *(vars.x_38 + 1);
  predicted_future_trajectory(2 + k * 3 + (37 * 9)) = *(vars.x_38 + 2);
  predicted_future_trajectory(0 + k * 3 + (38 * 9)) = *(vars.x_39);
  predicted_future_trajectory(1 + k * 3 + (38 * 9)) = *(vars.x_39 + 1);
  predicted_future_trajectory(2 + k * 3 + (38 * 9)) = *(vars.x_39 + 2);
  predicted_future_trajectory(0 + k * 3 + (39 * 9)) = *(vars.x_40);
  predicted_future_trajectory(1 + k * 3 + (39 * 9)) = *(vars.x_40 + 1);
  predicted_future_trajectory(2 + k * 3 + (39 * 9)) = *(vars.x_40 + 2);
}


void MpcTracker::calculateMPC() {
  tic();
  // filter the desired trajectory to be feasibl
  filterReference();

  bool avoiding_someone = (ros::Time::now() - avoiding_collision_time).toSec() < collision_slowing_hysteresis ? true : false;
  bool being_avoided    = (ros::Time::now() - being_avoided_time).toSec() < collision_slowing_hysteresis ? true : false;
  int  iters            = 0;

  // max speed and acceleration for X and Y axis
  if (being_avoided) {
    // somebody is trying to avoid me, better slow down a bit to give them more time
    params.x_max_2[0] = max_horizontal_speed * collision_horizontal_speed_coef;
    params.x_max_3[0] = max_horizontal_acceleration * collision_horizontal_acceleration_coef;
    params.x_min_2[0] = -max_horizontal_speed * collision_horizontal_speed_coef;
    params.x_min_3[0] = -max_horizontal_acceleration * collision_horizontal_acceleration_coef;
  } else {
    params.x_max_2[0] = max_horizontal_speed;
    params.x_max_3[0] = max_horizontal_acceleration;
    params.x_min_2[0] = -max_horizontal_speed;
    params.x_min_3[0] = -max_horizontal_acceleration;
  }
  params.u_max[0] = max_horizontal_acceleration;
  params.u_min[0] = -max_horizontal_acceleration;


  // prepare the full reference vector
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

  // First control input generated by cvxgen
  VectorXd cvx_u = VectorXd::Zero(m);

  // cvxgen X axis-------------------------------------------------------------------------------

  // initial position
  params.x_0[0] = x(0, 0);
  params.x_0[1] = x(1, 0);
  params.x_0[2] = x(2, 0);

  // reference
  loadReferenceForCvxgen(0);


  iters += solve();
  getStatesFromCvxgen(0);
  cvx_u(0) = *(vars.u_0);

  // cvxgen Y axis-------------------------------------------------------------------------------
  // initial position
  params.x_0[0] = x(3, 0);
  params.x_0[1] = x(4, 0);
  params.x_0[2] = x(5, 0);
  // reference

  loadReferenceForCvxgen(1);

  iters += solve();
  getStatesFromCvxgen(1);
  cvx_u(1) = *(vars.u_0);

  // cvxgen Z axis------------------------------------------------------------------------------
  // initial position
  params.x_0[0] = x(6, 0);
  params.x_0[1] = x(7, 0);
  params.x_0[2] = x(8, 0);
  // max speed and acceleration for Z axis
  if (avoiding_someone) {
    // I am avoiding someone, better push vertical speed and acc up to avoid in time
    params.x_max_2[0] = 5.0;
    params.x_max_3[0] = 2.0;
  } else {
    params.x_max_2[0] = max_vertical_ascending_speed;
    params.x_max_3[0] = max_vertical_ascending_acceleration;
  }
  params.x_min_2[0] = -max_vertical_descending_speed;
  params.x_min_3[0] = -max_vertical_descending_acceleration;
  // reference
  params.u_max[0] = max_vertical_ascending_acceleration;
  params.u_min[0] = -max_vertical_descending_acceleration;


  loadReferenceForCvxgen(2);


  iters += solve();

  getStatesFromCvxgen(2);
  cvx_u(2) = *(vars.u_0);

  double tmptime = tocq();
  ROS_INFO_STREAM_THROTTLE(1, "CVXGEN stats; total time taken: " << tmptime << "total number of iterations: " << iters);


  future_was_predicted = true;

  x_mutex.lock();
  { x = A * x + B * cvx_u; }

  x_mutex.unlock();
}

// the trackers_manager call this once when it wants to start using this tracker
// the position command in the argument is the last position command used by a previous tracker
bool MpcTracker::Activate(const quadrotor_msgs::PositionCommand::ConstPtr &cmd) {

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

    setTrajectory(cmd->position.x, cmd->position.y, cmd->position.z);

    ROS_INFO("MPC tracker activated with setpoint x: %2.2f, y: %2.2f, z: %2.2f, yaw: %2.2f", cmd->position.x, cmd->position.y, cmd->position.z, cmd->yaw);
    active_ = true;
  }

  // if we dont, stay where you are
  else if (odom_set_) {

    setTrajectory(odom_.pose.pose.position.x, odom_.pose.pose.position.y, odom_.pose.pose.position.z);
    position_cmd_.yaw = tf::getYaw(odom_.pose.pose.orientation);

    ROS_INFO("MPC tracker activated with no setpoint, staying where we are.");
    active_ = true;
  }

  mpc_start_time  = ros::Time::now();
  mpc_total_delay = 0;

  publishDiagnostics();

  // can return false
  return active_;
}

// trackers_manager calls this when it wants to stop using this tracker
void MpcTracker::Deactivate(void) {

  active_   = false;
  odom_set_ = false;

  // turn off trajectory tracking
  des_trajectory_mutex.lock();
  tracking_trajectory_ = false;
  trajectory_idx       = 0;
  des_trajectory_mutex.unlock();

  ROS_INFO("MPC tracker deactivated");

  publishDiagnostics();
}

// check the yaw setpoint
void MpcTracker::validateYawSetpoint() {

  des_yaw_mutex.lock();

  if (!std::isfinite(desired_yaw)) {

    desired_yaw = 0;
    ROS_ERROR("Desired YAW is not finite number!");
  }

  if (fabs(desired_yaw) > 1000) {

    ROS_WARN("Desired YAW is > 1000");
  }
  // if desired yaw is grater then 2*pi mod it
  if (fabs(desired_yaw) > 2 * pi) {
    desired_yaw = fmod(desired_yaw, 2 * pi);
  }

  // move it to its place
  if (desired_yaw > pi) {
    desired_yaw -= 2 * pi;
  } else if (desired_yaw < -pi) {
    desired_yaw += 2 * pi;
  }

  des_yaw_mutex.unlock();
}

// if the tracker is active, this mehod is called on every odometry update, even if the tracker is not active
const quadrotor_msgs::PositionCommand::ConstPtr MpcTracker::update(const nav_msgs::Odometry::ConstPtr &msg) {

  // copy the odometry from the message
  odom_     = *msg;
  cur_yaw_  = tf::getYaw(msg->pose.pose.orientation);
  odom_set_ = true;

  // very important, return null pointer when the tracker is not active, but we can still do some stuff
  if (!active_)
    return quadrotor_msgs::PositionCommand::Ptr();

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

    return quadrotor_msgs::PositionCommand::ConstPtr(new quadrotor_msgs::PositionCommand(position_cmd_));
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

  validateYawSetpoint();

  // compute the desired yaw rate
  des_yaw_mutex.lock();
  if (fabs(desired_yaw - yaw) > pi) {
    yaw_rate = -yaw_gain * (desired_yaw - yaw);
  } else {
    yaw_rate = yaw_gain * (desired_yaw - yaw);
  }
  des_yaw_mutex.unlock();

  if (yaw_rate > max_yaw_rate) {
    yaw_rate = max_yaw_rate;
  } else if (yaw_rate < -max_yaw_rate) {
    yaw_rate = -max_yaw_rate;
  }

  // flap the resulted yaw aroud pi
  yaw = yaw + dt * yaw_rate;
  if (yaw > pi) {
    yaw -= 2 * pi;
  } else if (yaw < -pi) {
    yaw += 2 * pi;
  }

  if (std::isfinite(yaw_rate) && std::isfinite(yaw)) {

    // set the yaw output
    position_cmd_.yaw_dot = yaw_rate;
    position_cmd_.yaw     = yaw;

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
  return quadrotor_msgs::PositionCommand::ConstPtr(new quadrotor_msgs::PositionCommand(position_cmd_));
}

void MpcTracker::publishDiagnostics(void) {

  mrs_msgs::TrackerDiagnostics diagnostics;

  diagnostics.header.stamp    = ros::Time::now();
  diagnostics.header.frame_id = "local_origin";

  diagnostics.tracker_active = active_;

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

    while (!active_ && ros::ok()) {
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

          des_x_trajectory(i) = des_x_whole_trajectory(tempIdx);
          des_y_trajectory(i) = des_y_whole_trajectory(tempIdx);
          des_z_trajectory(i) = des_z_whole_trajectory(tempIdx);
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
  double abs_yaw = desired_yaw + set_yaw;

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

  setTrajectory(abs_x, abs_y, abs_z);

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
bool MpcTracker::gotorelative_service_cmd_cb(mav_manager::Vec4::Request &req, mav_manager::Vec4::Response &res) {

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

  if (!set_goal(x(0, 0), x(3, 0), req.goal, 0, false)) {

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
    return false;
  }

  if (int(msg.points.size()) > (max_trajectory_size - horizon_len - 1)) {

    ROS_WARN("Cannot load trajectory, its too large (%d).", (int)msg.points.size());

    char buffer[60];
    sprintf(buffer, "Cannot load trajectory, its too large (%d).", (int)msg.points.size());
    message = buffer;
    return false;

  } else if (msg.points.size() == 0) {

    ROS_WARN("Cannot load trajectory with size 0.");

    char buffer[60];
    sprintf(buffer, "Cannot load trajectory with size 0.");
    message = buffer;
    return false;

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

    // check the safety area
    if (use_safety_area) {

      int last_valid_idx    = 0;
      int first_invalid_idx = -1;
      for (int i = 0; i < trajectory_size; i++) {

        // the point is not feasible
        if (!safety_area->isPointIn(des_x_whole_trajectory(i), des_y_whole_trajectory(i))) {

          ROS_WARN_THROTTLE(1.0, "The trajectory contains points outside of the safety area!");

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

        des_x_trajectory(i) = des_x_whole_trajectory(i);
        des_y_trajectory(i) = des_y_whole_trajectory(i);
        des_z_trajectory(i) = des_z_whole_trajectory(i);
      }

      if (use_yaw_in_trajectory) {
        desired_yaw = des_yaw_whole_trajectory(trajectory_idx);
      }
    }

    des_trajectory_mutex.unlock();

    ROS_INFO_THROTTLE(1, "Setting trajectory with length %d", trajectory_size);

    publishDiagnostics();

    message = "Trajectory loaded.";
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

  setTrajectory(set_x, set_y, set_z);

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

// callback for goToe service
bool MpcTracker::goto_service_cmd_cb(mav_manager::Vec4::Request &req, mav_manager::Vec4::Response &res) {

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
    setTrajectory(x(0, 0), x(3, 0), x(6, 0));
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

const quadrotor_msgs::TrackerStatus::Ptr MpcTracker::status() {

  if (!active_)
    return quadrotor_msgs::TrackerStatus::Ptr();

  quadrotor_msgs::TrackerStatus::Ptr msg(new quadrotor_msgs::TrackerStatus);
  msg->status = quadrotor_msgs::TrackerStatus::SUCCEEDED;
  return msg;
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

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(MpcTracker, trackers_manager::Tracker)
