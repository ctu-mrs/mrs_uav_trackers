#define VERSION "0.0.5.0"

/* includes //{ */

#include <ros/ros.h>

#include <mrs_uav_manager/Tracker.h>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>

#include <mrs_msgs/FuturePoint.h>
#include <mrs_msgs/FutureTrajectory.h>
#include <mrs_msgs/MpcTrackerDiagnostics.h>
#include <mrs_msgs/OdometryDiag.h>

#include <mrs_lib/Profiler.h>
#include <mrs_lib/Utils.h>
#include <mrs_lib/ParamLoader.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/geometry_utils.h>
#include <mrs_lib/attitude_converter.h>

#include <dynamic_reconfigure/server.h>
#include <mrs_trackers/cvx_wrapper.h>

#include <mrs_trackers/mpc_trackerConfig.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

//}

/* defines //{ */

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
  void initialize(const ros::NodeHandle& parent_nh, const std::string uav_name, std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers);
  bool activate(const mrs_msgs::PositionCommand::ConstPtr& last_position_cmd);
  void deactivate(void);
  bool resetStatic(void);

  const mrs_msgs::PositionCommand::ConstPtr update(const mrs_msgs::UavState::ConstPtr& uav_state, const mrs_msgs::AttitudeCommand::ConstPtr& last_attitude_cmd);
  const std_srvs::SetBoolResponse::ConstPtr enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr& cmd);
  const mrs_msgs::TrackerStatus             getStatus();
  void                                      switchOdometrySource(const mrs_msgs::UavState::ConstPtr& new_uav_state);

  const mrs_msgs::ReferenceSrvResponse::ConstPtr           setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr& cmd);
  const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr setTrajectoryReference(const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr& cmd);

  const std_srvs::TriggerResponse::ConstPtr hover(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr startTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr stopTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr resumeTrajectoryTracking(const std_srvs::TriggerRequest::ConstPtr& cmd);
  const std_srvs::TriggerResponse::ConstPtr gotoTrajectoryStart(const std_srvs::TriggerRequest::ConstPtr& cmd);

  const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr& cmd);

private:
  ros::NodeHandle                                    nh_;
  std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers_;

  bool callbacks_enabled_ = true;

  std::string _version_;
  std::string _uav_name_;

  // debugging publishers
  ros::Publisher pub_diagnostics_;

  ros::Publisher pub_debug_processed_trajectory_poses_;
  ros::Publisher pub_debug_processed_trajectory_markers_;

  mrs_msgs::UavState uav_state_;
  std::mutex         mutex_uav_state_;

  bool is_active_      = false;
  bool is_initialized_ = false;

  // | --------------------- MPC base params -------------------- |

  int _mpc_n_states_;      // number of states
  int _mpc_m_states_;      // number of inputs
  int _mpc_n_states_yaw_;  // number of states - yaw
  int _mpc_n_inputs_yaw_;  // number of inputs - yaw
  int _mpc_horizon_len_;   // lenght of the prediction horizon

  // | ----------------------- constraints ---------------------- |

  mrs_msgs::TrackerConstraints constraints_;
  std::mutex                   mutex_constraints_;

  mrs_msgs::TrackerConstraints constraints_filtered_;
  std::mutex                   mutex_constraints_filtered_;

  bool got_constraints_     = false;
  bool all_constraints_set_ = false;

  double _diag_pos_tracking_thr_;
  double _diag_yaw_tracking_thr_;

  double _dt1_;
  double _dt2_;

  MatrixXd _A_;  // system matrix for virtual UAV
  MatrixXd _B_;  // input matrix for virtual UAV

  MatrixXd _A_yaw_;  // system matrix for yaw
  MatrixXd _B_yaw_;  // input matrix for yaw

  // the reference over the prediction horizon per axis
  MatrixXd   des_x_trajectory_;
  MatrixXd   des_y_trajectory_;
  MatrixXd   des_z_trajectory_;
  MatrixXd   des_yaw_trajectory_;
  std::mutex mutex_des_trajectory_;

  // the reference filtered over the prediction horizon per axis
  MatrixXd des_x_filtered_;
  MatrixXd des_y_filtered_;
  MatrixXd des_z_filtered_;
  MatrixXd des_z_filtered_offset_;

  // the whole trajectory reference split per axis
  std::unique_ptr<VectorXd> des_x_whole_trajectory_;
  std::unique_ptr<VectorXd> des_y_whole_trajectory_;
  std::unique_ptr<VectorXd> des_z_whole_trajectory_;
  std::unique_ptr<VectorXd> des_yaw_whole_trajectory_;
  std::mutex                mutex_des_whole_trajectory_;

  // trajectory tracking
  bool       trajectory_tracking_in_progress_ = false;
  int        trajectory_tracking_sub_idx_     = 0;  // increases with every iteration of the simulated model
  int        trajectory_tracking_idx_         = 0;  // while tracking, this is the current index in the des_*_whole trajectory
  std::mutex mutex_trajectory_tracking_states_;

  // params of the loaded trajectory
  int    trajectory_size_ = 0;
  double trajectory_dt_;
  bool   trajectory_track_yaw_     = false;
  bool   trajectory_tracking_loop_ = false;
  bool   trajectory_set_           = false;
  int    trajectory_count_         = 0;  // counts how many trajectories we have received

  // current state of the dynamical system
  MatrixXd   mpc_x_;      // current state of the uav
  MatrixXd   mpc_x_yaw_;  // current yaw of the uav
  std::mutex mutex_mpc_x_;

  // odometry reset
  bool odometry_reset_in_progress_ = false;
  bool mpc_result_invalid_         = false;

  // predicting the future
  MatrixXd   predicted_trajectory_;
  MatrixXd   predicted_yaw_trajectory_;
  std::mutex mutex_predicted_trajectory_;

  ros::Publisher publisher_predicted_trajectory_debugging_;
  ros::Publisher publisher_mpc_reference_debugging_;

  bool mpc_computed_ = false;

  // | ------------------------- cvxgen ------------------------- |

  std::unique_ptr<mrs_trackers::cvx_wrapper::CvxWrapper> cvx_x_;
  std::unique_ptr<mrs_trackers::cvx_wrapper::CvxWrapper> cvx_y_;
  std::unique_ptr<mrs_trackers::cvx_wrapper::CvxWrapper> cvx_z_;
  std::unique_ptr<mrs_trackers::cvx_wrapper::CvxWrapper> cvx_yaw_;

  int _max_iters_xy_;
  int _max_iters_z_;
  int _max_iters_yaw_;

  // | ------------------ odometry diagnostics ------------------ |

  ros::Subscriber        subscriber_odometry_diagnostics_;
  void                   callbackOdometryDiagnostics(const mrs_msgs::OdometryDiagConstPtr& msg);
  mrs_msgs::OdometryDiag odometry_diagnostics_;
  bool                   got_odometry_diagnostics_ = false;
  std::mutex             mutex_odometry_diagnostics_;

  // | ----------- measuring the "MPC realtime factor" ---------- |

  ros::Time mpc_start_time_;
  double    mpc_total_delay_ = 0;

  // | ------------------- collision avoidance ------------------ |

  // configurable params
  bool collision_avoidance_enabled_ = false;

  // TODO what is this?
  double    coef_scaler = 0;
  ros::Time coef_time;

  double minimum_collison_free_altitude_ = std::numeric_limits<double>::lowest();
  int    active_collision_index_         = INT_MAX;

  // params
  double                   _avoidance_trajectory_rate_;
  double                   _avoidance_radius_threshold_;
  double                   _avoidance_height_correction_;
  std::string              _avoidance_trajectory_topic_name_;
  std::string              _avoidance_diagnostics_topic_name_;
  std::vector<std::string> _avoidance_other_uav_names_;
  double                   _avoidance_height_threshold_;

  // how old can the other UAV trajectory be (since receive time)
  double _collision_trajectory_timeout_;

  // when collision detected, slow down during the manouver
  double _avoidance_collision_horizontal_speed_coef_;

  // when collision detected, slow down fully this number of steps before it
  int _avoidance_collision_slow_down_fully_;

  // when collision detected, start slowing down this number of steps before it
  int _avoidance_collision_slow_down_;

  // when avoiding, start climbing this number of steps before it
  int _avoidance_collision_start_climbing_;

  int avoidance_this_uav_number_;
  int avoidance_this_uav_priority_;

  double collision_free_altitude_;
  bool   avoiding_collision_ = false;

  // avoidance trajectory will not be published unless we computed it at least once
  bool future_was_predicted_ = false;

  // subscribing to the other UAV future trajectories
  void                                              callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr& msg);
  std::vector<ros::Subscriber>                      other_uav_trajectory_subscribers_;
  std::map<std::string, mrs_msgs::FutureTrajectory> other_uav_avoidance_trajectories_;
  std::mutex                                        mutex_other_uav_avoidance_trajectories_;

  // subscribing to the other UAV diagnostics'
  void                                                   callbackOtherMavDiagnostics(const mrs_msgs::MpcTrackerDiagnosticsConstPtr& msg);
  std::vector<ros::Subscriber>                           other_uav_diag_subscribers_;
  std::map<std::string, mrs_msgs::MpcTrackerDiagnostics> other_uav_diagnostics_;
  std::mutex                                             mutex_other_uav_diagnostics_;

  double checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  double checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz);

  ros::Publisher avoidance_trajectory_publisher_;

  ros::ServiceServer service_server_toggle_avoidance_;
  bool               callbackToggleCollisionAvoidance(std_srvs::SetBool::Request& req, std_srvs::SetBool::Response& res);

  // | --------------------- MPC calculation -------------------- |

  ros::Timer timer_model_iteration_;
  bool       model_timer_running_ = false;
  void       timerModelIteration(const ros::TimerEvent& event);

  // | ------------------- trajectory tracking ------------------ |

  ros::Timer timer_trajectory_tracking_;
  void       timerTrajectoryTracking(const ros::TimerEvent& event);

  // | ------------------ avoidance trajectory ------------------ |

  ros::Timer timer_avoidance_trajectory_;
  void       timerAvoidanceTrajectory(const ros::TimerEvent& event);

  // | ----------------------- diagnostics ---------------------- |

  ros::Timer timer_diagnostics_;
  double     _diagnostics_rate_;
  void       timerDiagnostics(const ros::TimerEvent& event);

  // | ------------------------ hovering ------------------------ |

  ros::Timer timer_hover_;
  void       timerHover(const ros::TimerEvent& event);
  bool       hover_timer_runnning_ = false;
  bool       hovering_in_progress_ = false;
  void       toggleHover(bool in);

  // | ------------------- trajectory tracking ------------------ |

  std::tuple<bool, std::string> resumeTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> startTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> stopTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> gotoTrajectoryStartImpl(void);

  // | --------------------- other routines --------------------- |

  void publishDiagnostics();

  void setGoal(const double pos_x, const double pos_y, const double pos_z, const double yaw, const bool use_yaw);
  void setRelativeGoal(const double pos_x, const double pos_y, const double pos_z, const double yaw, const bool use_yaw);
  void setSinglePointReference(const double x, const double y, const double z, const double yaw);

  std::tuple<bool, std::string, bool> loadTrajectory(const mrs_msgs::TrajectoryReference msg);

  void filterReferenceZ(const double max_ascending_speed, const double max_descending_speed);
  void filterReferenceXY(double max_speed_x, double max_speed_y);

  double checkTrajectoryForCollisions(int& first_collision_index);

  void manageConstraints();

  void calculateMPC();

  Eigen::Vector2d rotateVector(const Eigen::Vector2d vector_in, double angle);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler;
  bool              _profiler_enabled_ = false;

  // | ------------------------- wiggle ------------------------- |

  ros::ServiceServer service_client_wiggle_;
  bool               callbackWiggle(std_srvs::SetBool::Request& req, std_srvs::SetBool::Response& res);

  bool       wiggle_enabled_ = false;
  double     wiggle_amplitude_;
  double     wiggle_frequency_;
  double     wiggle_phase_ = 0;
  std::mutex mutex_wiggle_;

  // | --------------- dynamic reconfigure server --------------- |

  void dynamicReconfigureCallback(mrs_trackers::mpc_trackerConfig& config, uint32_t level);

  boost::recursive_mutex                      config_mutex_;
  typedef mrs_trackers::mpc_trackerConfig     Config;
  typedef dynamic_reconfigure::Server<Config> ReconfigureServer;
  boost::shared_ptr<ReconfigureServer>        reconfigure_server_;
  void                                        drs_callback(mrs_trackers::mpc_trackerConfig& config, uint32_t level);
  mrs_trackers::mpc_trackerConfig             drs_params;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

void MpcTracker::initialize(const ros::NodeHandle& parent_nh, [[maybe_unused]] const std::string uav_name,
                            [[maybe_unused]] std::shared_ptr<mrs_uav_manager::CommonHandlers_t> common_handlers) {

  ros::NodeHandle nh_(parent_nh, "mpc_tracker");

  _uav_name_       = uav_name;
  common_handlers_ = common_handlers;

  ros::Time::waitForValid();

  mrs_lib::ParamLoader param_loader(nh_, "MpcTracker");

  param_loader.load_param("version", _version_);

  if (_version_ != VERSION) {

    ROS_ERROR("[MpcTracker]: the version of the binary (%s) does not match the config file (%s), please build me!", VERSION, _version_.c_str());
    ros::shutdown();
  }

  param_loader.load_param("enable_profiler", _profiler_enabled_);

  param_loader.load_param("model/translation/n_states", _mpc_n_states_);
  param_loader.load_param("model/translation/n_inputs", _mpc_m_states_);
  param_loader.load_matrix_static("model/translation/A", _A_, _mpc_n_states_, _mpc_n_states_);
  param_loader.load_matrix_static("model/translation/B", _B_, _mpc_n_states_, _mpc_m_states_);

  param_loader.load_param("model/yaw/n_states", _mpc_n_states_yaw_);
  param_loader.load_param("model/yaw/n_inputs", _mpc_n_inputs_yaw_);
  param_loader.load_matrix_static("model/yaw/A", _A_yaw_, _mpc_n_states_yaw_, _mpc_n_states_yaw_);
  param_loader.load_matrix_static("model/yaw/B", _B_yaw_, _mpc_n_states_yaw_, _mpc_n_inputs_yaw_);

  // load the MPC parameters
  param_loader.load_param("cvxgen/horizon_len", _mpc_horizon_len_);

  param_loader.load_param("cvxgen/dt1", _dt1_);
  param_loader.load_param("cvxgen/dt2", _dt2_);

  param_loader.load_param("diagnostics_rate", _diagnostics_rate_);
  param_loader.load_param("diagnostic_position_tracking_threshold", _diag_pos_tracking_thr_);
  param_loader.load_param("diagnostic_orientation_tracking_threshold", _diag_yaw_tracking_thr_);

  bool verbose_xy  = false;
  bool verbose_z   = false;
  bool verbose_yaw = false;

  std::vector<double> xy_Q;
  std::vector<double> z_Q;
  std::vector<double> yaw_Q;

  param_loader.load_param("cvxgen_xy/verbose", verbose_xy);
  param_loader.load_param("cvxgen_xy/max_n_iterations", _max_iters_xy_);
  param_loader.load_param("cvxgen_xy/Q", xy_Q);

  param_loader.load_param("cvxgen_z/verbose", verbose_z);
  param_loader.load_param("cvxgen_z/max_n_iterations", _max_iters_z_);
  param_loader.load_param("cvxgen_z/Q", z_Q);

  param_loader.load_param("cvxgen_yaw/verbose", verbose_yaw);
  param_loader.load_param("cvxgen_yaw/max_n_iterations", _max_iters_yaw_);
  param_loader.load_param("cvxgen_yaw/Q", yaw_Q);

  param_loader.load_param("wiggle/enabled", wiggle_enabled_);
  param_loader.load_param("wiggle/amplitude", wiggle_amplitude_);
  param_loader.load_param("wiggle/frequency", wiggle_frequency_);

  // collision avoidance
  param_loader.load_param("collision_avoidance/enabled", collision_avoidance_enabled_);
  param_loader.load_param("network/robot_names", _avoidance_other_uav_names_);
  param_loader.load_param("predicted_trajectory_topic", _avoidance_trajectory_topic_name_);
  param_loader.load_param("diagnostics_topic", _avoidance_diagnostics_topic_name_);
  param_loader.load_param("collision_avoidance/predicted_trajectory_publish_rate", _avoidance_trajectory_rate_);
  param_loader.load_param("collision_avoidance/correction", _avoidance_height_correction_);
  param_loader.load_param("collision_avoidance/radius", _avoidance_radius_threshold_);
  param_loader.load_param("collision_avoidance/altitude_threshold", _avoidance_height_threshold_);
  param_loader.load_param("collision_avoidance/collision_horizontal_speed_coef", _avoidance_collision_horizontal_speed_coef_);
  param_loader.load_param("collision_avoidance/collision_slow_down_fully", _avoidance_collision_slow_down_fully_);
  param_loader.load_param("collision_avoidance/collision_slow_down_start", _avoidance_collision_slow_down_);
  param_loader.load_param("collision_avoidance/collision_start_climbing", _avoidance_collision_start_climbing_);
  param_loader.load_param("collision_avoidance/trajectory_timeout", _collision_trajectory_timeout_);

  if (!param_loader.loaded_successfully()) {
    ROS_ERROR("[MpcTracker]: could not load all parameters!");
    ros::shutdown();
  }

  cvx_x_   = std::make_unique<mrs_trackers::cvx_wrapper::CvxWrapper>(verbose_xy, _max_iters_xy_, xy_Q, _dt1_, _dt2_, 0);
  cvx_y_   = std::make_unique<mrs_trackers::cvx_wrapper::CvxWrapper>(verbose_xy, _max_iters_xy_, xy_Q, _dt1_, _dt2_, 1);
  cvx_z_   = std::make_unique<mrs_trackers::cvx_wrapper::CvxWrapper>(verbose_z, _max_iters_z_, z_Q, _dt1_, _dt2_, 2);
  cvx_yaw_ = std::make_unique<mrs_trackers::cvx_wrapper::CvxWrapper>(verbose_yaw, _max_iters_yaw_, yaw_Q, _dt1_, _dt2_, 0);

  mpc_x_     = MatrixXd::Zero(_mpc_n_states_, 1);
  mpc_x_yaw_ = MatrixXd::Zero(_mpc_n_states_yaw_, 1);

  coef_time = ros::Time(0);

  des_x_trajectory_      = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_y_trajectory_      = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_z_trajectory_      = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_z_filtered_offset_ = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_yaw_trajectory_    = MatrixXd::Zero(_mpc_horizon_len_, 1);

  des_x_filtered_ = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_y_filtered_ = MatrixXd::Zero(_mpc_horizon_len_, 1);
  des_z_filtered_ = MatrixXd::Zero(_mpc_horizon_len_, 1);

  subscriber_odometry_diagnostics_ =
      nh_.subscribe("odometry_diagnostics_in", 1, &MpcTracker::callbackOdometryDiagnostics, this, ros::TransportHints().tcpNoDelay());
  service_client_wiggle_ = nh_.advertiseService("wiggle_in", &MpcTracker::callbackWiggle, this);

  pub_diagnostics_ = nh_.advertise<mrs_msgs::MpcTrackerDiagnostics>("diagnostics_out", 1);

  // extract the numerical name
  sscanf(_uav_name_.c_str(), "uav%d", &avoidance_this_uav_number_);
  ROS_INFO("[MpcTracker]: Numerical ID of this UAV is %d", avoidance_this_uav_number_);
  avoidance_this_uav_priority_ = avoidance_this_uav_number_;

  // exclude this drone from the list
  std::vector<std::string>::iterator it = _avoidance_other_uav_names_.begin();
  while (it != _avoidance_other_uav_names_.end()) {

    std::string temp_str = *it;

    int other_uav_priority;
    sscanf(temp_str.c_str(), "uav%d", &other_uav_priority);

    if (other_uav_priority == avoidance_this_uav_number_) {

      _avoidance_other_uav_names_.erase(it);
      continue;
    }

    it++;
  }

  // create publishers for predicted trajectory
  avoidance_trajectory_publisher_           = nh_.advertise<mrs_msgs::FutureTrajectory>("predicted_trajectory", 1);
  publisher_predicted_trajectory_debugging_ = nh_.advertise<geometry_msgs::PoseArray>("predicted_trajectory_debugging", 1);
  publisher_mpc_reference_debugging_        = nh_.advertise<geometry_msgs::PoseArray>("mpc_reference_debugging", 1, true);

  pub_debug_processed_trajectory_poses_   = nh_.advertise<geometry_msgs::PoseArray>("trajectory_processed/poses_out", 1, true);
  pub_debug_processed_trajectory_markers_ = nh_.advertise<visualization_msgs::MarkerArray>("trajectory_processed/markers_out", 1, true);

  // preallocate predicted trajectory
  predicted_trajectory_     = MatrixXd::Zero(_mpc_horizon_len_ * _mpc_n_states_, 1);
  predicted_yaw_trajectory_ = MatrixXd::Zero(_mpc_horizon_len_ * _mpc_n_states_, 1);

  collision_free_altitude_ = common_handlers_->safety_area.getMinHeight();

  // collision avoidance toggle service
  service_server_toggle_avoidance_ = nh_.advertiseService("collision_avoidance_in", &MpcTracker::callbackToggleCollisionAvoidance, this);

  // create subscribers on other drones diagnostics
  for (int i = 0; i < int(_avoidance_other_uav_names_.size()); i++) {

    std::string prediction_topic_name = std::string("/") + _avoidance_other_uav_names_[i] + std::string("/") + _avoidance_trajectory_topic_name_;
    std::string diag_topic_name       = std::string("/") + _avoidance_other_uav_names_[i] + std::string("/") + _avoidance_diagnostics_topic_name_;

    ROS_INFO("[MpcTracker]: subscribing to %s", prediction_topic_name.c_str());

    other_uav_trajectory_subscribers_.push_back(
        nh_.subscribe(prediction_topic_name, 1, &MpcTracker::callbackOtherMavTrajectory, this, ros::TransportHints().tcpNoDelay()));


    ROS_INFO("[MpcTracker]: subscribing to %s", diag_topic_name.c_str());

    other_uav_diag_subscribers_.push_back(
        nh_.subscribe(diag_topic_name, 1, &MpcTracker::callbackOtherMavDiagnostics, this, ros::TransportHints().tcpNoDelay()));
  }

  // | --------------- dynamic reconfigure server --------------- |

  drs_params.wiggle_enabled   = wiggle_enabled_;
  drs_params.wiggle_frequency = wiggle_frequency_;
  drs_params.wiggle_amplitude = wiggle_amplitude_;

  reconfigure_server_.reset(new ReconfigureServer(config_mutex_, nh_));
  reconfigure_server_->updateConfig(drs_params);
  ReconfigureServer::CallbackType f = boost::bind(&MpcTracker::dynamicReconfigureCallback, this, _1, _2);
  reconfigure_server_->setCallback(f);

  // | ------------------------ profiler ------------------------ |

  profiler = mrs_lib::Profiler(nh_, "MpcTracker", _profiler_enabled_);

  // | ------------------------- timers ------------------------- |

  timer_avoidance_trajectory_ = nh_.createTimer(ros::Rate(_avoidance_trajectory_rate_), &MpcTracker::timerAvoidanceTrajectory, this);
  timer_diagnostics_          = nh_.createTimer(ros::Rate(_diagnostics_rate_), &MpcTracker::timerDiagnostics, this);
  timer_model_iteration_      = nh_.createTimer(ros::Rate(1.0 / _dt1_), &MpcTracker::timerModelIteration, this);
  timer_trajectory_tracking_  = nh_.createTimer(ros::Rate(1.0), &MpcTracker::timerTrajectoryTracking, this, false, false);
  timer_hover_                = nh_.createTimer(ros::Rate(10), &MpcTracker::timerHover, this, false, false);

  // | ----------------------- finish init ---------------------- |

  is_initialized_ = true;

  ROS_INFO("[MpcTracker]: initialized, version %s", VERSION);
}

//}

/* //{ activate() */

bool MpcTracker::activate(const mrs_msgs::PositionCommand::ConstPtr& last_position_cmd) {

  if (!got_odometry_diagnostics_) {

    ROS_ERROR("[MpcTracker]: can not activate, missing odometry diagnostics");
    return false;
  }

  if (!got_constraints_) {

    ROS_ERROR("[MpcTracker]: can not activate, missing constraints");
    return false;
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_state_yaw = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getYaw();

  MatrixXd mpc_x     = MatrixXd::Zero(_mpc_n_states_, 1);
  MatrixXd mpc_x_yaw = MatrixXd::Zero(_mpc_n_states_yaw_, 1);

  if (mrs_msgs::PositionCommand::Ptr() != last_position_cmd) {

    // set the initial condition from the last tracker's cmd

    mpc_x(0, 0) = last_position_cmd->position.x;
    mpc_x(1, 0) = last_position_cmd->velocity.x;
    mpc_x(2, 0) = last_position_cmd->acceleration.x;
    mpc_x(3, 0) = 0;

    mpc_x(4, 0) = last_position_cmd->position.y;
    mpc_x(5, 0) = last_position_cmd->velocity.y;
    mpc_x(6, 0) = last_position_cmd->acceleration.y;
    mpc_x(7, 0) = 0;

    mpc_x(8, 0)  = last_position_cmd->position.z;
    mpc_x(9, 0)  = last_position_cmd->velocity.z;
    mpc_x(10, 0) = last_position_cmd->acceleration.z;
    mpc_x(11, 0) = 0;

    mpc_x_yaw(0, 0) = last_position_cmd->yaw;
    mpc_x_yaw(1, 0) = last_position_cmd->yaw_dot;
    mpc_x_yaw(2, 0) = 0;
    mpc_x_yaw(3, 0) = 0;

    ROS_INFO("[MpcTracker]: activated with last tracker's command");

  } else {

    // set the initial condition from the odometry

    mpc_x(0, 0) = uav_state.pose.position.x;
    mpc_x(1, 0) = uav_state.velocity.linear.x;
    mpc_x(2, 0) = 0;
    mpc_x(3, 0) = 0;

    mpc_x(4, 0) = uav_state.pose.position.y;
    mpc_x(5, 0) = uav_state.velocity.linear.y;
    mpc_x(6, 0) = 0;
    mpc_x(7, 0) = 0;

    mpc_x(8, 0)  = uav_state.pose.position.z;
    mpc_x(9, 0)  = uav_state.velocity.linear.z;
    mpc_x(10, 0) = 0;
    mpc_x(11, 0) = 0;

    mpc_x_yaw(0, 0) = uav_state_yaw;
    mpc_x_yaw(1, 0) = uav_state.velocity.angular.z;
    mpc_x_yaw(2, 0) = 0;
    mpc_x_yaw(3, 0) = 0;

    ROS_INFO("[MpcTracker]: activated with uav state");
  }

  {
    std::scoped_lock lock(mutex_mpc_x_);

    mpc_x_     = mpc_x;
    mpc_x_yaw_ = mpc_x_yaw;
  }

  trajectory_tracking_in_progress_ = false;

  timer_trajectory_tracking_.stop();

  mpc_start_time_  = ros::Time::now();
  mpc_total_delay_ = 0;

  ROS_INFO("[MpcTracker]: activated");

  // this is here to initialize the desired_trajectory vector
  // if deleted (and I tried) the UAV will briefly fly to the
  // origin after activation
  setRelativeGoal(0, 0, 0, 0, false);  // do not delete

  toggleHover(true);

  is_active_ = true;

  return true;
}

//}

/* //{ deactivate() */

void MpcTracker::deactivate(void) {

  toggleHover(false);

  is_active_                       = false;
  trajectory_tracking_in_progress_ = false;

  timer_trajectory_tracking_.stop();

  {
    std::scoped_lock lock(mutex_trajectory_tracking_states_);

    trajectory_tracking_idx_     = 0;
    trajectory_tracking_sub_idx_ = 0;
  }

  ROS_INFO("[MpcTracker]: deactivated");

  publishDiagnostics();
}

//}

/* //{ resetStatic() */

bool MpcTracker::resetStatic(void) {

  if (!is_initialized_) {
    ROS_ERROR("[MpcTracker]: can not reset, not initialized");
    return false;
  }

  if (!is_active_) {
    ROS_ERROR("[MpcTracker]: can not reset, not active");
    return false;
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_state_yaw = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getYaw();

  {
    std::scoped_lock lock(mutex_mpc_x_);

    // set the initial condition from the odometry

    ROS_INFO("[MpcTracker]: reseting with uav state with no dynamics");

    mpc_x_(0, 0) = uav_state.pose.position.x;
    mpc_x_(1, 0) = 0;
    mpc_x_(2, 0) = 0;
    mpc_x_(3, 0) = 0;

    mpc_x_(4, 0) = uav_state.pose.position.y;
    mpc_x_(5, 0) = 0;
    mpc_x_(6, 0) = 0;
    mpc_x_(7, 0) = 0;

    mpc_x_(8, 0)  = uav_state.pose.position.z;
    mpc_x_(9, 0)  = 0;
    mpc_x_(10, 0) = 0;
    mpc_x_(11, 0) = 0;

    mpc_x_yaw_(0, 0) = uav_state_yaw;
    mpc_x_yaw_(1, 0) = 0;
    mpc_x_yaw_(2, 0) = 0;
    mpc_x_yaw_(3, 0) = 0;

    trajectory_tracking_in_progress_ = false;

    timer_trajectory_tracking_.stop();

    mpc_start_time_  = ros::Time::now();
    mpc_total_delay_ = 0;

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

const mrs_msgs::PositionCommand::ConstPtr MpcTracker::update(const mrs_msgs::UavState::ConstPtr&                         uav_state,
                                                             [[maybe_unused]] const mrs_msgs::AttitudeCommand::ConstPtr& last_attitude_cmd) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("update");

  mrs_lib::set_mutexed(mutex_uav_state_, *uav_state, uav_state_);

  auto [mpc_x, mpc_x_yaw] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_yaw_);

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return mrs_msgs::PositionCommand::Ptr();
  }

  mrs_msgs::PositionCommand position_cmd;

  if (!mpc_computed_ || mpc_result_invalid_) {

    // if the tracker is not computed yet

    // set the header
    position_cmd.header.stamp    = uav_state->header.stamp;
    position_cmd.header.frame_id = uav_state->header.frame_id;

    // set positions from odom
    position_cmd.position.x = uav_state->pose.position.x;
    position_cmd.position.y = uav_state->pose.position.y;
    position_cmd.position.z = uav_state->pose.position.z;

    // set velocities from odom
    position_cmd.velocity.x = uav_state->velocity.linear.x;
    position_cmd.velocity.y = uav_state->velocity.linear.y;
    position_cmd.velocity.z = uav_state->velocity.linear.z;

    // set zero accelerations
    position_cmd.acceleration.x = 0;
    position_cmd.acceleration.y = 0;
    position_cmd.acceleration.z = 0;

    // set zero jerk
    position_cmd.jerk.x = 0;
    position_cmd.jerk.y = 0;
    position_cmd.jerk.z = 0;


    // set yaw based on current odom
    position_cmd.yaw       = mrs_lib::AttitudeConverter(uav_state->pose.orientation).getYaw();
    position_cmd.yaw_dot   = uav_state->velocity.angular.z;
    position_cmd.yaw_ddot  = 0;
    position_cmd.yaw_dddot = 0;

    ROS_WARN_THROTTLE(1.0, "[MpcTracker]: MPC not ready, reaturning current odom as the command");

    return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd));
  }

  // chech wheather all outputs are finite
  bool arefinite = true;
  for (int i = 0; i < 12; i++) {
    if (!std::isfinite(mpc_x(i, 0))) {
      arefinite = false;
    }
  }

  if (arefinite) {

    // set the desired states base on the result of the mpc
    position_cmd.position.x     = mpc_x(0, 0);
    position_cmd.velocity.x     = mpc_x(1, 0);
    position_cmd.acceleration.x = mpc_x(2, 0);
    position_cmd.jerk.x         = mpc_x(3, 0);

    position_cmd.position.y     = mpc_x(4, 0);
    position_cmd.velocity.y     = mpc_x(5, 0);
    position_cmd.acceleration.y = mpc_x(6, 0);
    position_cmd.jerk.y         = mpc_x(7, 0);

    position_cmd.position.z     = mpc_x(8, 0);
    position_cmd.velocity.z     = mpc_x(9, 0);
    position_cmd.acceleration.z = mpc_x(10, 0);
    position_cmd.jerk.z         = mpc_x(11, 0);

    position_cmd.use_position_vertical   = 1;
    position_cmd.use_position_horizontal = 1;
    position_cmd.use_velocity_vertical   = 1;
    position_cmd.use_velocity_horizontal = 1;
    position_cmd.use_acceleration        = 1;
    position_cmd.use_jerk                = 1;
    position_cmd.use_yaw                 = 1;
    position_cmd.use_yaw_dot             = 1;

  } else {

    ROS_ERROR_THROTTLE(1.0, "[MpcTracker]: MPC outputs are not finite!");

    position_cmd.velocity.x     = 0;
    position_cmd.acceleration.x = 0;
    position_cmd.jerk.x         = 0;

    position_cmd.velocity.y     = 0;
    position_cmd.acceleration.y = 0;
    position_cmd.jerk.y         = 0;

    position_cmd.velocity.z     = 0;
    position_cmd.acceleration.z = 0;
    position_cmd.jerk.z         = 0;
  }

  bool yaw_finite = true;
  for (int i = 0; i < _mpc_n_states_yaw_; i++) {
    if (!std::isfinite(mpc_x_yaw(i, 0))) {
      yaw_finite = false;
    }
  }

  if (yaw_finite) {

    // set the yaw output - cvxgen MPC controller
    position_cmd.yaw       = mpc_x_yaw(0, 0);
    position_cmd.yaw_dot   = mpc_x_yaw(1, 0);
    position_cmd.yaw_ddot  = mpc_x_yaw(2, 0);
    position_cmd.yaw_dddot = mpc_x_yaw(3, 0);

  } else {

    ROS_ERROR_THROTTLE(1.0, "[MpcTracker]: yow output is not finite!");

    position_cmd.yaw_dot   = 0;
    position_cmd.yaw_ddot  = 0;
    position_cmd.yaw_dddot = 0;
  }

  // set the header
  position_cmd.header.stamp    = uav_state->header.stamp;
  position_cmd.header.frame_id = uav_state->header.frame_id;

  // u have to return a position command
  // can set the jerk to 0
  return mrs_msgs::PositionCommand::ConstPtr(new mrs_msgs::PositionCommand(position_cmd));
}

//}

/* //{ getStatus() */

const mrs_msgs::TrackerStatus MpcTracker::getStatus() {

  auto [mpc_x, mpc_x_yaw]      = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_yaw_);
  auto trajectory_size         = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_size_);
  auto trajectory_tracking_idx = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_tracking_idx_);

  double des_x, des_y, des_z, des_yaw;
  {
    std::scoped_lock lock(mutex_des_trajectory_);

    des_x   = des_x_trajectory_(0);
    des_y   = des_y_trajectory_(0);
    des_z   = des_z_trajectory_(0);
    des_yaw = des_yaw_trajectory_(0);
  }

  mrs_msgs::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = is_active_ && callbacks_enabled_ && !hovering_in_progress_;

  tracker_status.tracking_trajectory = trajectory_tracking_in_progress_;

  bool have_position_error   = sqrt(pow(mpc_x(0, 0) - des_x, 2) + pow(mpc_x(4, 0) - des_y, 2) + pow(mpc_x(8, 0) - des_z, 2)) > _diag_pos_tracking_thr_;
  bool have_yaw_error        = mrs_lib::angleBetween(mpc_x_yaw(0), des_yaw) > _diag_yaw_tracking_thr_;
  bool have_nonzero_velocity = abs(mpc_x(1, 0)) > 0.1 || abs(mpc_x(5, 0)) > 0.1 || abs(mpc_x(9, 0)) > 0.1 || abs(mpc_x_yaw(1, 0)) > 0.1;

  tracker_status.have_goal = trajectory_tracking_in_progress_ || hovering_in_progress_ || have_position_error || have_yaw_error || have_nonzero_velocity;

  tracker_status.trajectory_length = trajectory_size;
  tracker_status.trajectory_idx    = trajectory_tracking_idx;

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std_srvs::SetBoolResponse::ConstPtr MpcTracker::enableCallbacks(const std_srvs::SetBoolRequest::ConstPtr& cmd) {

  std::stringstream ss;

  if (cmd->data != callbacks_enabled_) {

    callbacks_enabled_ = cmd->data;
    ss << "callbacks %s" << (callbacks_enabled_ ? "enabled" : "disabled");

  } else {

    ss << "callbacks were already %s" << (callbacks_enabled_ ? "enabled" : "disabled");
  }

  std_srvs::SetBoolResponse res;
  res.message = ss.str();
  res.success = true;

  return std_srvs::SetBoolResponse::ConstPtr(new std_srvs::SetBoolResponse(res));
}

//}

/* switchOdometrySource() //{ */

void MpcTracker::switchOdometrySource(const mrs_msgs::UavState::ConstPtr& new_uav_state) {

  odometry_reset_in_progress_ = true;
  mpc_result_invalid_         = true;

  auto x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  ROS_INFO(
      "[MpcTracker]: start of odmetry reset, curent state [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: %.2f], "
      "new odom [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: %.2f]",
      x(0, 0), x(4, 0), x(8, 0), x(1, 0), x(5, 0), x(9, 0), x(2, 0), x(6, 0), x(10, 0), new_uav_state->pose.position.x, new_uav_state->pose.position.y,
      new_uav_state->pose.position.z, new_uav_state->velocity.linear.x, new_uav_state->velocity.linear.y, new_uav_state->velocity.linear.z,
      new_uav_state->acceleration.linear.x, new_uav_state->acceleration.linear.y, new_uav_state->acceleration.linear.z);

  timer_model_iteration_.stop();
  ROS_INFO("[MpcTracker]: mpc timer stopped");

  while (model_timer_running_) {

    ROS_DEBUG("[MpcTracker]: the MPC is in the middle of an iteration, waiting for it to finish");
    ros::Duration wait(0.01);
    wait.sleep();
  }

  // | --------- recalculate the goal to new coordinates -------- |
  double dx, dy, dz, dyaw;
  double dvz, dvyaw;

  double old_yaw = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getYaw();
  double new_yaw = mrs_lib::AttitudeConverter(new_uav_state->pose.orientation).getYaw();

  // calculate the difference of position
  dx   = new_uav_state->pose.position.x - uav_state_.pose.position.x;
  dy   = new_uav_state->pose.position.y - uav_state_.pose.position.y;
  dz   = new_uav_state->pose.position.z - uav_state_.pose.position.z;
  dyaw = new_yaw - old_yaw;

  // calculate the difference in yaw
  dvyaw = new_uav_state->velocity.angular.z - uav_state_.velocity.angular.z;

  ROS_INFO("[MpcTracker]: dx %f dy %f dz %f dyaw %f", dx, dy, dz, dyaw);

  {
    std::scoped_lock lock(mutex_mpc_x_, mutex_des_trajectory_, mutex_des_whole_trajectory_, mutex_uav_state_);

    for (int i = 0; i < trajectory_size_ + _mpc_horizon_len_; i++) {

      Eigen::Vector2d temp_vec((*des_x_whole_trajectory_)(i)-uav_state_.pose.position.x, (*des_y_whole_trajectory_)(i)-uav_state_.pose.position.y);
      temp_vec = rotateVector(temp_vec, dyaw);

      (*des_x_whole_trajectory_)(i) = new_uav_state->pose.position.x + temp_vec[0];
      (*des_y_whole_trajectory_)(i) = new_uav_state->pose.position.y + temp_vec[1];
      (*des_z_whole_trajectory_)(i) += dz;
      (*des_yaw_whole_trajectory_)(i) += dyaw;
    }

    for (int i = 0; i < _mpc_horizon_len_; i++) {

      Eigen::Vector2d temp_vec(des_x_trajectory_(i) - uav_state_.pose.position.x, des_y_trajectory_(i) - uav_state_.pose.position.y);
      temp_vec = rotateVector(temp_vec, dyaw);

      des_x_trajectory_(i, 0) = new_uav_state->pose.position.x + temp_vec[0];
      des_y_trajectory_(i, 0) = new_uav_state->pose.position.y + temp_vec[1];
      des_z_trajectory_(i, 0) += dz;
      des_yaw_trajectory_(i, 0) += dyaw;
    }

    dvz = new_uav_state->velocity.linear.z - uav_state_.velocity.linear.z;

    // update the position
    {
      Eigen::Vector2d temp_vec(mpc_x_(0, 0) - uav_state_.pose.position.x, mpc_x_(4, 0) - uav_state_.pose.position.y);
      temp_vec     = rotateVector(temp_vec, dyaw);
      mpc_x_(0, 0) = new_uav_state->pose.position.x + temp_vec[0];
      mpc_x_(4, 0) = new_uav_state->pose.position.y + temp_vec[1];
      mpc_x_(8, 0) += dz;
    }

    // update the velocity
    {
      mpc_x_(1, 0) = new_uav_state->velocity.linear.x;
      mpc_x_(5, 0) = new_uav_state->velocity.linear.y;
      // we leave the z velocity as it was in the original frame
    }

    // update the acceleration
    {
      mpc_x_(2, 0)  = 0;
      mpc_x_(6, 0)  = 0;
      mpc_x_(10, 0) = 0;
    }

    // update the heading and its derivative
    mpc_x_yaw_(0, 0) += dyaw;
    mpc_x_yaw_(1, 0) = new_uav_state->velocity.angular.x;
  }

  ROS_INFO(
      "[MpcTracker]: start of odmetry reset, curent state [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: %.2f]",
      x(0, 0), x(4, 0), x(8, 0), x(1, 0), x(5, 0), x(9, 0), x(2, 0), x(6, 0), x(10, 0));

  ROS_INFO("[MpcTracker]: starting the MPC timer");
  timer_model_iteration_.start();

  odometry_reset_in_progress_ = false;
}

//}

/* //{ hover() */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::hover([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {

  toggleHover(true);

  std::stringstream ss;
  ss << "initiating hover";

  std_srvs::TriggerResponse res;
  res.success = true;
  res.message = ss.str();

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ startTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::startTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {
  std::stringstream ss;

  auto [success, message] = startTrajectoryTrackingImpl();

  std_srvs::TriggerResponse res;
  res.success = success;
  res.message = message;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ stopTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::stopTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {

  auto [success, message] = stopTrajectoryTrackingImpl();

  std_srvs::TriggerResponse res;
  res.success = success;
  res.message = message;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ resumeTrajectoryTracking() */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::resumeTrajectoryTracking([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {

  auto [success, message] = resumeTrajectoryTrackingImpl();

  std_srvs::TriggerResponse res;
  res.success = success;
  res.message = message;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ gotoTrajectoryStart() */

const std_srvs::TriggerResponse::ConstPtr MpcTracker::gotoTrajectoryStart([[maybe_unused]] const std_srvs::TriggerRequest::ConstPtr& cmd) {

  auto [success, message] = gotoTrajectoryStartImpl();

  std_srvs::TriggerResponse res;
  res.success = success;
  res.message = message;

  return std_srvs::TriggerResponse::ConstPtr(new std_srvs::TriggerResponse(res));
}

//}

/* //{ setConstraints() */

const mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr MpcTracker::setConstraints(const mrs_msgs::TrackerConstraintsSrvRequest::ConstPtr& constraints) {

  if (!is_initialized_) {
    return mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr(new mrs_msgs::TrackerConstraintsSrvResponse());
  }

  mrs_lib::set_mutexed(mutex_constraints_, constraints->constraints, constraints_);

  got_constraints_ = true;

  // directly updated the speeds in the constraints
  // the reset needs to wait for manageConstraints()
  {
    std::scoped_lock lock(mutex_constraints_filtered_);

    auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

    constraints_filtered_.horizontal_speed          = constraints.horizontal_speed;
    constraints_filtered_.vertical_ascending_speed  = constraints.vertical_ascending_speed;
    constraints_filtered_.vertical_descending_speed = constraints.vertical_descending_speed;
    constraints_filtered_.yaw_speed                 = constraints.yaw_speed;
  }

  all_constraints_set_ = false;

  ROS_INFO("[MpcTracker]: updating constraints");

  mrs_msgs::TrackerConstraintsSrvResponse res;
  res.success = true;
  res.message = "constraints updated";

  return mrs_msgs::TrackerConstraintsSrvResponse::ConstPtr(new mrs_msgs::TrackerConstraintsSrvResponse(res));
}

//}

/* //{ setReference() */

const mrs_msgs::ReferenceSrvResponse::ConstPtr MpcTracker::setReference(const mrs_msgs::ReferenceSrvRequest::ConstPtr& cmd) {

  toggleHover(false);

  setGoal(cmd->reference.position.x, cmd->reference.position.y, cmd->reference.position.z, cmd->reference.yaw, true);

  mrs_msgs::ReferenceSrvResponse res;
  res.success = true;
  res.message = "reference set";

  return mrs_msgs::ReferenceSrvResponse::ConstPtr(new mrs_msgs::ReferenceSrvResponse(res));
}

//}

/* //{ setTrajectoryReference() */

const mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr MpcTracker::setTrajectoryReference([
    [maybe_unused]] const mrs_msgs::TrajectoryReferenceSrvRequest::ConstPtr& cmd) {

  std::stringstream ss;

  auto [success, message, modified] = loadTrajectory(cmd->trajectory);

  mrs_msgs::TrajectoryReferenceSrvResponse response;
  response.success  = success;
  response.message  = message;
  response.modified = modified;

  return mrs_msgs::TrajectoryReferenceSrvResponse::ConstPtr(new mrs_msgs::TrajectoryReferenceSrvResponse(response));
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ callbackOtherMavTrajectory() */

void MpcTracker::callbackOtherMavTrajectory(const mrs_msgs::FutureTrajectoryConstPtr& msg) {

  if (!is_initialized_) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler.createRoutine("callbackOtherMavTrajectory");

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  mrs_msgs::FutureTrajectory temp_trajectory = *msg;

  // the times might not be synchronized, so just remember the time of receiving it
  temp_trajectory.stamp = ros::Time::now();

  // transform it from the utm origin to the currently used frame
  auto res = common_handlers_->transformer->getTransform("utm_origin", uav_state.header.frame_id, ros::Time::now(), true);

  if (!res) {

    std::string message = "[MpcTracker]: can not transform other drone trajectory to the current frame";
    ROS_WARN_STREAM_ONCE(message);
    ROS_DEBUG_STREAM_THROTTLE(1.0, message);

    return;
  }

  mrs_lib::TransformStamped tf = res.value();

  for (int i = 0; i < int(temp_trajectory.points.size()); i++) {

    geometry_msgs::PoseStamped original_pose;

    original_pose.pose.position.x = temp_trajectory.points[i].x;
    original_pose.pose.position.y = temp_trajectory.points[i].y;
    original_pose.pose.position.z = temp_trajectory.points[i].z;

    original_pose.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    auto res = common_handlers_->transformer->transform(tf, original_pose);

    if (res) {
      temp_trajectory.points[i].x = res.value().pose.position.x;
      temp_trajectory.points[i].y = res.value().pose.position.y;
      temp_trajectory.points[i].z = res.value().pose.position.z;
    } else {

      std::string message = "[MpcTracker]: could not transform point of other uav future trajectory!";
      ROS_WARN_STREAM_ONCE(message);
      ROS_DEBUG_STREAM_THROTTLE(1.0, message);

      return;
    }
  }

  {
    std::scoped_lock lock(mutex_other_uav_avoidance_trajectories_);

    // update the diagnostics
    other_uav_avoidance_trajectories_[msg->uav_name] = temp_trajectory;
  }
}

//}

/* //{ callbackOtherMavDiagnostics() */

void MpcTracker::callbackOtherMavDiagnostics(const mrs_msgs::MpcTrackerDiagnosticsConstPtr& msg) {

  mrs_lib::Routine profiler_routine = profiler.createRoutine("callbackOtherMavDiagnostics");

  std::scoped_lock lock(mutex_other_uav_diagnostics_);

  mrs_msgs::MpcTrackerDiagnostics temp_diagnostics = *msg;

  // the times might not be synchronized, so just remember the time of receiving it
  temp_diagnostics.header.stamp = ros::Time::now();

  // update the diagnostics
  other_uav_diagnostics_[msg->uav_name] = temp_diagnostics;
}

//}

/* //{ callbackToggleCollisionAvoidance() */

bool MpcTracker::callbackToggleCollisionAvoidance(std_srvs::SetBool::Request& req, std_srvs::SetBool::Response& res) {

  collision_avoidance_enabled_ = req.data;

  ROS_INFO("[MpcTracker]: Collision avoidance was switched %s", collision_avoidance_enabled_ ? "TRUE" : "FALSE");

  res.message = "Collision avoidance set.";
  res.success = true;

  return true;
}

//}

/* //{ callbackOdometryDiagnostics() */

void MpcTracker::callbackOdometryDiagnostics(const mrs_msgs::OdometryDiagConstPtr& msg) {

  if (!is_initialized_) {
    return;
  }

  ROS_INFO_ONCE("[MpcTracker]: getting odometry diagnostics");

  std::scoped_lock lock(mutex_odometry_diagnostics_);

  odometry_diagnostics_ = *msg;

  got_odometry_diagnostics_ = true;
}

//}

/* callbackWiggle() //{ */

bool MpcTracker::callbackWiggle(std_srvs::SetBool::Request& req, std_srvs::SetBool::Response& res) {

  std::scoped_lock lock(mutex_wiggle_);

  if (!is_initialized_) {

    res.success = false;
    res.message = "tracker not active";
    return true;
  }

  wiggle_enabled_ = req.data;
  res.success     = true;
  res.message     = "wiggle updated";

  return true;
}

//}

/* //{ dynamicReconfigureCallback() */

void MpcTracker::dynamicReconfigureCallback(mrs_trackers::mpc_trackerConfig& config, [[maybe_unused]] uint32_t level) {

  std::scoped_lock lock(mutex_wiggle_);

  drs_params = config;

  wiggle_enabled_   = config.wiggle_enabled;
  wiggle_amplitude_ = config.wiggle_amplitude;
  wiggle_frequency_ = config.wiggle_frequency;

  ROS_INFO("[MpcTracker]: DRS updated");
}

//}

// --------------------------------------------------------------
// |                          routines                          |
// --------------------------------------------------------------

// | --------------- mutual collision avoidance --------------- |

/* //{ checkCollision() */

double MpcTracker::checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (mrs_lib::dist2d(ax, ay, bx, by) < _avoidance_radius_threshold_ && fabs(az - bz) < _avoidance_height_threshold_) {
    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkCollisionInflated() */

double MpcTracker::checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (mrs_lib::dist2d(ax, ay, bx, by) < _avoidance_radius_threshold_ + 1.0 && fabs(az - bz) < _avoidance_height_threshold_ + 1.0) {
    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkTrajectoryForCollisions() */

// Check for potential collisions and return the needed altitude offset to avoid other drones
double MpcTracker::checkTrajectoryForCollisions(int& first_collision_index) {

  std::scoped_lock lock(mutex_predicted_trajectory_, mutex_des_trajectory_, mutex_other_uav_avoidance_trajectories_);

  first_collision_index = INT_MAX;
  avoiding_collision_   = false;

  // This variable is used for collision avoidance priority swapping, only the first detected collision is considered for priority swap, subsequent
  // collisons are irrelevant
  bool first_collision = true;

  std::map<std::string, mrs_msgs::FutureTrajectory>::iterator u = other_uav_avoidance_trajectories_.begin();

  while (u != other_uav_avoidance_trajectories_.end()) {

    first_collision = true;

    // is the other's trajectory fresh enought?
    if ((ros::Time::now() - u->second.stamp).toSec() < _collision_trajectory_timeout_) {

      for (int v = 0; v < _mpc_horizon_len_; v++) {

        // check all points of the trajectory for possible collisions
        if (checkCollision(predicted_trajectory_(v * _mpc_n_states_, 0), predicted_trajectory_(v * _mpc_n_states_ + 4, 0),
                           predicted_trajectory_(v * _mpc_n_states_ + 8, 0), u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {

          // collision is detected
          int other_uav_priority = INT_MAX;
          // get the priority of the other uav
          /* sscanf(u->first.c_str(), "uav%d", &other_uav_priority); */
          other_uav_priority = u->second.priority;
          // check if we should be avoiding (out priority is higher, or the other uav has collision avoidance turned off)
          if ((u->second.collision_avoidance == false) || (other_uav_priority < avoidance_this_uav_priority_)) {
            // we should be avoiding
            avoiding_collision_      = true;
            double tmp_safe_altitude = u->second.points[v].z + _avoidance_height_correction_;
            if (tmp_safe_altitude > collision_free_altitude_ && v <= _avoidance_collision_start_climbing_) {
              collision_free_altitude_ = tmp_safe_altitude;
            }
            ROS_ERROR_STREAM_THROTTLE(1, "[MpcTracker]: avoiding collision with uav" << other_uav_priority);
          } else {
            // the other uav should avoid us
            ROS_WARN_STREAM_THROTTLE(1, "[MpcTracker]: detected collision with uav" << other_uav_priority << ", not avoiding (my priority is higher)");
            first_collision = false;
          }
        }
        if (checkCollisionInflated(predicted_trajectory_(v * _mpc_n_states_, 0), predicted_trajectory_(v * _mpc_n_states_ + 4, 0),
                                   predicted_trajectory_(v * _mpc_n_states_ + 8, 0), u->second.points[v].x, u->second.points[v].y, u->second.points[v].z)) {
          // collision is detected
          if (first_collision_index > v) {
            first_collision_index = v;
          }
        }
      }
    }
    u++;
  }

  if (!avoiding_collision_) {

    // we are not avoiding any collisions, so we slowly reduce the collision avoidance offset to return to normal flight
    collision_free_altitude_ -= 0.02;

    if (collision_free_altitude_ < common_handlers_->safety_area.getMinHeight()) {

      collision_free_altitude_ = common_handlers_->safety_area.getMinHeight();
    }
  }

  return collision_free_altitude_;
}

//}

// | ------------------ trajectory filtering ------------------ |

/* //{ filterReferenceXY() */

void MpcTracker::filterReferenceXY(double max_speed_x_, double max_speed_y_) {

  auto mpc_x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto trajectory_dt = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_dt_);

  double difference_x;
  double difference_y;
  double max_sample_x;
  double max_sample_y;

  for (int i = 0; i < _mpc_horizon_len_; i++) {

    if (i == 0) {
      max_sample_x = max_speed_x_ * _dt1_;
      max_sample_y = max_speed_y_ * _dt1_;
      difference_x = des_x_trajectory_(i, 0) - mpc_x(0, 0);
      difference_y = des_y_trajectory_(i, 0) - mpc_x(4, 0);
    } else {
      max_sample_x = max_speed_x_ * _dt2_;
      max_sample_y = max_speed_y_ * _dt2_;
      difference_x = des_x_trajectory_(i, 0) - des_x_filtered_(i - 1, 0);
      difference_y = des_y_trajectory_(i, 0) - des_y_filtered_(i - 1, 0);
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
      des_x_filtered_(i, 0) = mpc_x(0, 0) + difference_x;
      des_y_filtered_(i, 0) = mpc_x(4, 0) + difference_y;
    } else {
      des_x_filtered_(i, 0) = des_x_filtered_(i - 1, 0) + difference_x;
      des_y_filtered_(i, 0) = des_y_filtered_(i - 1, 0) + difference_y;
    }
  }

  // | ----------------------- add wiggle ----------------------- |
  if (wiggle_enabled_) {

    for (int i = 0; i < _mpc_horizon_len_; i++) {
      des_x_filtered_(i, 0) += wiggle_amplitude_ * cos(wiggle_frequency_ * 2 * M_PI * i * trajectory_dt + wiggle_phase_);
      des_y_filtered_(i, 0) += wiggle_amplitude_ * sin(wiggle_frequency_ * 2 * M_PI * i * trajectory_dt + wiggle_phase_);
    }

    wiggle_phase_ += wiggle_frequency_ * _dt1_ * 2 * M_PI;

    if (wiggle_phase_ > M_PI) {
      wiggle_phase_ -= 2 * M_PI;
    }
  }
}

//}

/* //{ filterReferenceZ() */

void MpcTracker::filterReferenceZ(const double max_ascending_speed, const double max_descending_speed) {

  auto mpc_x = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);

  double difference_z;
  double max_sample_z;

  for (int i = 0; i < _mpc_horizon_len_; i++) {

    if (i == 0) {

      difference_z = des_z_trajectory_(i, 0) - mpc_x(8, 0);

      if (difference_z > 0) {
        max_sample_z = max_ascending_speed * _dt1_;
      } else {
        max_sample_z = max_descending_speed * _dt1_;
      }

    } else {

      difference_z = des_z_trajectory_(i, 0) - des_z_filtered_(i - 1, 0);

      if (difference_z > 0) {
        max_sample_z = max_ascending_speed * _dt2_;
      } else {
        max_sample_z = max_descending_speed * _dt2_;
      }
    }

    // saturate the difference
    if (difference_z > max_sample_z)
      difference_z = max_sample_z;
    else if (difference_z < -max_sample_z)
      difference_z = -max_sample_z;

    if (i == 0) {
      des_z_filtered_(i, 0) = mpc_x(8, 0) + difference_z;
    } else {
      des_z_filtered_(i, 0) = des_z_filtered_(i - 1, 0) + difference_z;
    }
  }
}

//}

/* //{ manageConstraints() */

void MpcTracker::manageConstraints() {

  if (!got_constraints_) {
    return;
  }

  if (all_constraints_set_) {
    return;
  }

  auto constraints        = mrs_lib::get_mutexed(mutex_constraints_, constraints_);
  auto [mpc_x, mpc_x_yaw] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_yaw_);

  bool can_change = (fabs(mpc_x(1, 0)) < constraints.horizontal_speed) && (fabs(mpc_x(2, 0)) < constraints.horizontal_acceleration) &&
                    (fabs(mpc_x(3, 0)) < constraints.horizontal_jerk) && (fabs(mpc_x(5, 0)) < constraints.horizontal_speed) &&
                    (fabs(mpc_x(6, 0)) < constraints.horizontal_acceleration) && (fabs(mpc_x(7, 0)) < constraints.horizontal_jerk) &&
                    (mpc_x(9, 0) < constraints.vertical_ascending_speed) && (mpc_x(9, 0) > -constraints.vertical_descending_speed) &&
                    (mpc_x(10, 0) < constraints.vertical_ascending_acceleration) && (mpc_x(10, 0) > -constraints.vertical_descending_acceleration) &&
                    (mpc_x(11, 0) < constraints.vertical_ascending_jerk) && (mpc_x(11, 0) > -constraints.vertical_descending_jerk) &&
                    (fabs(mpc_x_yaw(1, 0)) < constraints.yaw_speed) && (fabs(mpc_x_yaw(2, 0)) < constraints.yaw_acceleration) &&
                    (fabs(mpc_x_yaw(3, 0)) < constraints.yaw_jerk);

  if (can_change) {

    {
      std::scoped_lock lock(mutex_constraints_filtered_);

      constraints_filtered_.horizontal_acceleration = constraints.horizontal_acceleration;
      constraints_filtered_.horizontal_jerk         = constraints.horizontal_jerk;
      constraints_filtered_.horizontal_snap         = constraints.horizontal_snap;

      constraints_filtered_.vertical_ascending_acceleration = constraints.vertical_ascending_acceleration;
      constraints_filtered_.vertical_ascending_jerk         = constraints.vertical_ascending_jerk;
      constraints_filtered_.vertical_ascending_snap         = constraints.vertical_ascending_snap;

      constraints_filtered_.vertical_descending_acceleration = constraints.vertical_descending_acceleration;
      constraints_filtered_.vertical_descending_jerk         = constraints.vertical_descending_jerk;
      constraints_filtered_.vertical_descending_snap         = constraints.vertical_descending_snap;

      constraints_filtered_.yaw_acceleration = constraints.yaw_acceleration;
      constraints_filtered_.yaw_jerk         = constraints.yaw_jerk;
      constraints_filtered_.yaw_snap         = constraints.yaw_snap;
    }

    ROS_INFO_THROTTLE(1.0, "[MpcTracker]: all constraints succesfully applied");
    all_constraints_set_ = true;

  } else {
    ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: slowing down to apply new constraints");
  }
}

//}

/* //{ calculateMPC() */

void MpcTracker::calculateMPC() {

  auto constraints        = mrs_lib::get_mutexed(mutex_constraints_filtered_, constraints_filtered_);
  auto [mpc_x, mpc_x_yaw] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_yaw_);

  int    first_collision_index = INT_MAX;
  double lowest_z              = std::numeric_limits<double>::max();
  bool   brake;

  if (collision_avoidance_enabled_ && ((odometry_diagnostics_.estimator_type.name == "GPS") || odometry_diagnostics_.estimator_type.name == "RTK")) {

    // determine the lowest point in our trajectory
    for (int i = 0; i < _mpc_horizon_len_; i++) {
      if (des_z_trajectory_(i, 0) < lowest_z) {
        lowest_z = des_z_trajectory_(i, 0);
      }
    }
    // Check other drone trajectories for collisions
    minimum_collison_free_altitude_ = checkTrajectoryForCollisions(first_collision_index);

  } else {

    minimum_collison_free_altitude_ = common_handlers_->safety_area.getMinHeight();
  }

  double max_speed_x = constraints.horizontal_speed;
  double max_speed_y = constraints.horizontal_speed;
  double max_speed_z = constraints.vertical_ascending_speed;
  double min_speed_z = constraints.vertical_descending_speed;

  double max_acc_x = constraints.horizontal_acceleration;
  double max_acc_y = constraints.horizontal_acceleration;
  double max_acc_z = constraints.vertical_ascending_acceleration;
  double min_acc_z = constraints.vertical_descending_acceleration;

  double max_snap_x = constraints.horizontal_snap;
  double max_snap_y = constraints.horizontal_snap;
  double max_snap_z = constraints.vertical_ascending_snap;
  double min_snap_z = constraints.vertical_descending_snap;

  double max_jerk_x = constraints.horizontal_jerk;
  double max_jerk_y = constraints.horizontal_jerk;
  double max_jerk_z = constraints.vertical_ascending_jerk;
  double min_jerk_z = constraints.vertical_descending_jerk;

  if (first_collision_index < _mpc_horizon_len_) {

    // the tmp variable is used to scale the speed of our drone in collision avoidance, depending on how far away the collision is
    double tmp = 0;

    if (first_collision_index <= _avoidance_collision_slow_down_fully_) {
      tmp = 1;
    } else if (first_collision_index <= _avoidance_collision_slow_down_) {
      tmp = 1.0 - ((double)(first_collision_index - _avoidance_collision_slow_down_fully_)) /
                      (double)(_avoidance_collision_slow_down_ - _avoidance_collision_slow_down_fully_);
      tmp = tmp * tmp;
    }

    if (!std::isfinite(tmp)) {
      tmp = 1.0;
      ROS_ERROR("[MpcTracker]: NaN detected in variable 'tmp', setting it to 1.0 and returning!!!");
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
    max_speed_x = constraints.horizontal_speed * ((_avoidance_collision_horizontal_speed_coef_ * coef_scaler) + (1.0 - coef_scaler));
    max_speed_y = constraints.horizontal_speed * ((_avoidance_collision_horizontal_speed_coef_ * coef_scaler) + (1.0 - coef_scaler));
  }

  if (collision_free_altitude_ > lowest_z) {

    // we are avoiding someone, increase Z dynamics limit for faster evasion
    max_speed_z = 2.0;
    max_acc_z   = 2.0;
    max_jerk_z  = 2.0;
    max_snap_z  = 4.0;
    min_speed_z = 2.0;
    min_acc_z   = 2.0;
    min_jerk_z  = 4.0;
    min_snap_z  = 4.0;

    max_speed_x = constraints.horizontal_speed * (_avoidance_collision_horizontal_speed_coef_);
    max_speed_y = constraints.horizontal_speed * (_avoidance_collision_horizontal_speed_coef_);
  }

  // First control input generated by cvxgen
  VectorXd cvx_u     = VectorXd::Zero(_mpc_m_states_);
  double   cvx_u_yaw = 0;

  double iters_z   = 0;
  double iters_x   = 0;
  double iters_y   = 0;
  double iters_yaw = 0;

  ros::Time time_begin = ros::Time::now();

  filterReferenceZ(max_speed_z, min_speed_z);

  for (int i = 0; i < _mpc_horizon_len_; i++) {
    if (des_z_filtered_(i, 0) < minimum_collison_free_altitude_) {
      des_z_filtered_offset_(i, 0) = minimum_collison_free_altitude_;
    } else {
      des_z_filtered_offset_(i, 0) = des_z_filtered_(i, 0);
    }
  }

  // | ---------------------- cvxgen Z axis --------------------- |

  brake = true;
  if (des_z_filtered_(10) != des_z_filtered_(_mpc_horizon_len_ - 1) || des_z_filtered_(30) != des_z_filtered_(_mpc_horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_z_->setVelQ(3000);
  } else {
    cvx_z_->setVelQ(0);
  }

  MatrixXd initial_z = MatrixXd::Zero(_mpc_n_states_, 1);

  initial_z(0, 0) = mpc_x(8, 0);
  initial_z(1, 0) = mpc_x(9, 0);
  initial_z(2, 0) = mpc_x(10, 0);
  initial_z(3, 0) = mpc_x(11, 0);

  cvx_z_->setInitialState(initial_z);
  cvx_z_->loadReference(des_z_filtered_offset_);
  cvx_z_->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_jerk_z, min_jerk_z, max_snap_z, min_snap_z);
  iters_z += cvx_z_->solveCvx();

  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    cvx_z_->getStates(predicted_trajectory_);
  }

  cvx_u(2) = cvx_z_->getFirstControlInput();

  // If we are climbing to avoid a collision, reduce or arrest our horizontal velocity
  double ascend;
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    ascend = (predicted_trajectory_(10, 0) / max_speed_z);
  }

  if (ascend > 0 && collision_free_altitude_ > lowest_z) {
    max_speed_y = max_speed_y * (1.0 - ascend);
    max_speed_x = max_speed_x * (1.0 - ascend);
  }

  filterReferenceXY(max_speed_x, max_speed_y);

  // unwrap the yaw reference

  des_yaw_trajectory_(0, 0) = mrs_lib::unwrapAngle(des_yaw_trajectory_(0, 0), mpc_x_yaw_(0));

  for (int i = 1; i < _mpc_horizon_len_; i++) {
    des_yaw_trajectory_(i, 0) = mrs_lib::unwrapAngle(des_yaw_trajectory_(i, 0), des_yaw_trajectory_(i - 1, 0));
  }

  // | ---------------------- cvxgen X axis --------------------- |

  brake = true;
  if (des_x_filtered_(10) != des_x_filtered_(_mpc_horizon_len_ - 1) || des_x_filtered_(30) != des_x_filtered_(_mpc_horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_x_->setVelQ(3000);
  } else {
    cvx_x_->setVelQ(0);
  }

  MatrixXd initial_x = MatrixXd::Zero(_mpc_n_states_, 1);

  initial_x(0, 0) = mpc_x(0, 0);
  initial_x(1, 0) = mpc_x(1, 0);
  initial_x(2, 0) = mpc_x(2, 0);
  initial_x(3, 0) = mpc_x(3, 0);

  cvx_x_->setInitialState(initial_x);
  cvx_x_->loadReference(des_x_filtered_);
  cvx_x_->setLimits(max_speed_x, max_speed_x, max_acc_x, max_acc_x, max_jerk_x, max_jerk_x, max_snap_x, max_snap_x);
  iters_x += cvx_x_->solveCvx();

  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    cvx_x_->getStates(predicted_trajectory_);
  }

  cvx_u(0) = cvx_x_->getFirstControlInput();

  // | ---------------------- cvxgen Y axis --------------------- |

  brake = true;
  if (des_y_filtered_(10) != des_y_filtered_(_mpc_horizon_len_ - 1) || des_y_filtered_(30) != des_y_filtered_(_mpc_horizon_len_ - 1)) {
    brake = false;
  }
  if (brake) {
    cvx_y_->setVelQ(3000);
  } else {
    cvx_y_->setVelQ(0);
  }

  MatrixXd initial_y = MatrixXd::Zero(_mpc_n_states_, 1);

  initial_y(0, 0) = mpc_x(4, 0);
  initial_y(1, 0) = mpc_x(5, 0);
  initial_y(2, 0) = mpc_x(6, 0);
  initial_y(3, 0) = mpc_x(7, 0);

  cvx_y_->setInitialState(initial_y);
  cvx_y_->loadReference(des_y_filtered_);
  cvx_y_->setLimits(max_speed_y, max_speed_y, max_acc_y, max_acc_y, max_jerk_y, max_jerk_y, max_snap_y, max_snap_y);
  iters_y += cvx_y_->solveCvx();
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    cvx_y_->getStates(predicted_trajectory_);
  }
  cvx_u(1) = cvx_y_->getFirstControlInput();

  // | ---------------------- cvxgen YAW axis --------------------- |

  brake = true;
  if (fabs(mpc_x_yaw(0) - des_yaw_trajectory_(10)) > 1.0 || fabs(mpc_x_yaw(0) - des_yaw_trajectory_(30)) > 1.0) {
    brake = false;
  }

  if (brake) {
    cvx_yaw_->setVelQ(3000);
  } else {
    cvx_yaw_->setVelQ(0);
  }

  cvx_yaw_->setInitialState(mpc_x_yaw);
  cvx_yaw_->loadReference(des_yaw_trajectory_);
  cvx_yaw_->setLimits(constraints.yaw_speed, constraints.yaw_speed, constraints.yaw_acceleration, constraints.yaw_acceleration, constraints.yaw_jerk,
                      constraints.yaw_jerk, constraints.yaw_snap, constraints.yaw_snap);
  iters_yaw += cvx_yaw_->solveCvx();
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    cvx_yaw_->getStates(predicted_yaw_trajectory_);
  }
  cvx_u_yaw = cvx_yaw_->getFirstControlInput();

  {
    std::scoped_lock lock(mutex_constraints_);

    if (cvx_u(0) > max_snap_x * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap X: " << cvx_u(0));
      cvx_u(0) = max_snap_x;
    }
    if (cvx_u(0) < -max_snap_x * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap X: " << cvx_u(0));
      cvx_u(0) = -max_snap_x;
    }
    if (cvx_u(1) > max_snap_y * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap Y: " << cvx_u(1));
      cvx_u(1) = max_snap_y;
    }
    if (cvx_u(1) < -max_snap_y * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap Y: " << cvx_u(1));
      cvx_u(1) = -max_snap_y;
    }
    if (cvx_u(2) > max_snap_z * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap Z: " << cvx_u(2));
      cvx_u(2) = max_snap_z;
    }
    if (cvx_u(2) < -min_snap_z * 1.01) {
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: saturating snap Z: " << cvx_u(2));
      cvx_u(2) = -min_snap_z;
    }
  }

  double cvx_time = (ros::Time::now() - time_begin).toSec();
  if (cvx_time > _dt1_ || iters_x > _max_iters_xy_ || iters_y > _max_iters_xy_ || iters_z > _max_iters_z_ || iters_yaw > _max_iters_yaw_) {
    ROS_DEBUG_STREAM_THROTTLE(1.0, "[MpcTracker]: Total CVXtime: " << cvx_time << " iters X: " << iters_x << "/" << _max_iters_xy_ << " iters Y:  " << iters_y
                                                                   << "/" << _max_iters_xy_ << " iters Z: " << iters_z << "/" << _max_iters_z_
                                                                   << " iters yaw: " << iters_yaw << "/" << _max_iters_yaw_);
  }

  // iterate the models
  {
    std::scoped_lock lock(mutex_mpc_x_);

    mpc_x_     = _A_ * mpc_x_ + _B_ * cvx_u;
    mpc_x_yaw_ = _A_yaw_ * mpc_x_yaw_ + _B_yaw_ * cvx_u_yaw;

    mpc_x_yaw_(0) = mrs_lib::wrapAngle(mpc_x_yaw_(0));
  }

  future_was_predicted_ = true;
}

//}

// | -------------------- referece setting -------------------- |

/* //{ loadTrajectory() */

// method for setting desired trajectory
std::tuple<bool, std::string, bool> MpcTracker::loadTrajectory(const mrs_msgs::TrajectoryReference msg) {

  // copy the member variables
  auto x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  std::stringstream ss;

  /* check the trajectory dt //{ */

  double trajectory_dt;
  if (msg.dt <= 1e-4) {
    trajectory_dt = 0.2;
    ROS_WARN_THROTTLE(10.0, "[MpcTracker]: the trajectory dt was not specified, assuming its the old 0.2 s");
  } else if (msg.dt < _dt1_) {
    trajectory_dt = 0.2;
    ss << std::setprecision(3) << "the trajectory dt (" << msg.dt << " s) is too small (smaller than the tracker's internal step size: " << _dt1_ << " s)";
    ROS_ERROR_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());
    return std::tuple(false, ss.str(), false);
  } else {
    trajectory_dt = msg.dt;
  }

  //}

  int trajectory_size = msg.points.size();

  /* sanitize the time-ness of the trajectory //{ */

  int    trajectory_sample_offset    = 0;  // how many samples in past is the trajectory
  int    trajectory_subsample_offset = 0;  // how many simulation inner loops ahead of the first valid sample
  double trajectory_time_offset      = 0;  // how much time in past in [s]

  // btw, "trajectory_time_offset = trajectory_dt*trajectory_sample_offset + _dt1_*trajectory_subsample_offset" should hold
  if (msg.fly_now) {

    ros::Time trajectory_time = msg.header.stamp;

    // the desired time is 0 => the current time
    // the trajecoty is a single point => the current time
    if (trajectory_time == ros::Time(0) || int(msg.points.size()) == 1) {

      trajectory_time_offset = 0.0;

      // the desired time is specified
    } else {

      trajectory_time_offset = (ros::Time::now() - trajectory_time).toSec();

      // when the time offset is negative, thus in the future
      // just say it, but use it like its from the current time
      if (trajectory_time_offset < 0.0) {

        ROS_WARN_THROTTLE(1.0, "[MpcTracker]: received trajectory with timestamp in the future by %.2f s", -trajectory_time_offset);

        trajectory_time_offset = 0.0;
      }
    }

    // if the time offset is set, check if we need to "move the first idx"
    if (trajectory_time_offset > 0) {

      // calculate the offset in samples
      trajectory_sample_offset = int(floor(trajectory_time_offset / trajectory_dt_));

      // and get the subsample offset, which will be used to initialize the interpolator
      trajectory_subsample_offset = int(floor(fmod(trajectory_time_offset, trajectory_dt) / (_dt1_)));

      ROS_DEBUG_THROTTLE(1.0, "[MpcTracker]: sanity check: %.3f", trajectory_dt * trajectory_sample_offset + _dt1_ * trajectory_subsample_offset);

      // if the offset is larger than the number of points in the trajectory
      // the trajectory can not be used
      if (trajectory_sample_offset >= trajectory_size) {

        ss << "trajectory timestamp is too old (time difference = " << trajectory_time_offset << ")";
        ROS_ERROR_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());
        return std::tuple(false, ss.str(), false);

      } else {

        // If the offset is larger than one trajectory sample,
        // offset the start
        if (trajectory_time_offset >= trajectory_dt) {

          // decrease the trajectory size
          trajectory_size -= trajectory_sample_offset;

          ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: got trajectory with timestamp '" << trajectory_time_offset << " s' in the past");

        } else {

          trajectory_sample_offset = 0;
        }
      }
    }
  }

  //}

  ROS_DEBUG_THROTTLE(1.0, "[MpcTracker]: trajectory sample offset: %d", trajectory_sample_offset);
  ROS_DEBUG_THROTTLE(1.0, "[MpcTracker]: trajectory subsample offset: %d", trajectory_subsample_offset);

  // after this, we should have the correct value of
  // * trajectory_size
  // * trajectory_sample_offset
  // * trajectory_subsample_offset

  /* copy the trajectory to a local variable //{ */

  // copy only the part from the first valid index

  MatrixXd des_x_whole_trajectory   = VectorXd::Zero(trajectory_size + _mpc_horizon_len_, 1);
  MatrixXd des_y_whole_trajectory   = VectorXd::Zero(trajectory_size + _mpc_horizon_len_, 1);
  MatrixXd des_z_whole_trajectory   = VectorXd::Zero(trajectory_size + _mpc_horizon_len_, 1);
  MatrixXd des_yaw_whole_trajectory = VectorXd::Zero(trajectory_size + _mpc_horizon_len_, 1);

  for (int i = 0; i < trajectory_size; i++) {

    des_x_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].position.x;
    des_y_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].position.y;
    des_z_whole_trajectory(i)   = msg.points[trajectory_sample_offset + i].position.z;
    des_yaw_whole_trajectory(i) = msg.points[trajectory_sample_offset + i].yaw;
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
    if (mrs_lib::dist3d(first_x, first_y, first_z, last_x, last_y, last_z) < 3.141592653) {

      ROS_INFO_THROTTLE(1.0, "[MpcTracker]: looping enabled");
      loop = true;

    } else {

      ss << "can not loop trajectory, the first and last points are too far apart";
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());
      return std::tuple(false, ss.str(), false);
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
    for (int i = 0; i < _mpc_horizon_len_; i++) {

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
    std::scoped_lock lock(mutex_des_whole_trajectory_, mutex_des_trajectory_, mutex_trajectory_tracking_states_);

    auto mpc_x_yaw = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_yaw_);

    trajectory_tracking_in_progress_ = msg.fly_now;
    trajectory_track_yaw_            = msg.use_yaw;

    // allocate the vectors
    des_x_whole_trajectory_   = std::make_unique<VectorXd>(trajectory_size + _mpc_horizon_len_, 1);
    des_y_whole_trajectory_   = std::make_unique<VectorXd>(trajectory_size + _mpc_horizon_len_, 1);
    des_z_whole_trajectory_   = std::make_unique<VectorXd>(trajectory_size + _mpc_horizon_len_, 1);
    des_yaw_whole_trajectory_ = std::make_unique<VectorXd>(trajectory_size + _mpc_horizon_len_, 1);

    for (int i = 0; i < trajectory_size + _mpc_horizon_len_; i++) {

      (*des_x_whole_trajectory_)(i) = des_x_whole_trajectory(i);
      (*des_y_whole_trajectory_)(i) = des_y_whole_trajectory(i);
      (*des_z_whole_trajectory_)(i) = des_z_whole_trajectory(i);

      if (trajectory_track_yaw_) {
        (*des_yaw_whole_trajectory_)(i) = des_yaw_whole_trajectory(i);
      } else {
        (*des_yaw_whole_trajectory_).fill(mpc_x_yaw(0, 0));
      }
    }

    // if we are tracking trajectory, copy the setpoint
    if (trajectory_tracking_in_progress_) {

      toggleHover(false);

      for (int i = 0; i < _mpc_horizon_len_; i++) {

        des_x_trajectory_(i)   = des_x_whole_trajectory(i);
        des_y_trajectory_(i)   = des_y_whole_trajectory(i);
        des_z_trajectory_(i)   = des_z_whole_trajectory(i);
        des_yaw_trajectory_(i) = des_yaw_whole_trajectory(i);
      }
    }

    trajectory_size_             = trajectory_size;
    trajectory_tracking_idx_     = 0;
    trajectory_tracking_sub_idx_ = trajectory_subsample_offset;
    trajectory_set_              = true;
    trajectory_tracking_loop_    = loop;
    trajectory_dt_               = trajectory_dt;
    trajectory_count_++;

    timer_trajectory_tracking_.setPeriod(ros::Duration(trajectory_dt));
  }

  //}

  if (trajectory_tracking_in_progress_) {
    timer_trajectory_tracking_.start();
  }

  ROS_INFO_THROTTLE(1, "[MpcTracker]: received trajectory with length %d", trajectory_size);

  /* publish the debugging topics of the post-processed trajectory //{ */

  {

    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = ros::Time::now();
    debug_trajectory_out.header.frame_id = common_handlers_->transformer->resolveFrameName(msg.header.frame_id);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

      for (int i = 0; i < trajectory_size; i++) {

        geometry_msgs::Pose new_pose;

        new_pose.position.x = (*des_x_whole_trajectory_)(i);
        new_pose.position.y = (*des_y_whole_trajectory_)(i);
        new_pose.position.z = (*des_z_whole_trajectory_)(i);

        new_pose.orientation = mrs_lib::AttitudeConverter(0, 0, (*des_yaw_whole_trajectory_)(i));

        debug_trajectory_out.poses.push_back(new_pose);
      }
    }

    try {
      pub_debug_processed_trajectory_poses_.publish(debug_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: exception caught during publishing topic %s", pub_debug_processed_trajectory_poses_.getTopic().c_str());
    }

    visualization_msgs::MarkerArray msg_out;

    visualization_msgs::Marker marker;

    marker.header.stamp     = ros::Time::now();
    marker.header.frame_id  = common_handlers_->transformer->resolveFrameName(msg.header.frame_id);
    marker.type             = visualization_msgs::Marker::LINE_LIST;
    marker.color.a          = 1;
    marker.scale.x          = 0.05;
    marker.color.r          = 1;
    marker.color.g          = 0;
    marker.color.b          = 0;
    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

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
      ROS_ERROR("exception caught during publishing topic %s", pub_debug_processed_trajectory_markers_.getTopic().c_str());
    }
  }

  //}

  publishDiagnostics();

  return std::tuple(true, "trajectory loaded", false);
}

//}

/* //{ setSinglePointReference() */

// fill the des_*_trajectory based on a single point
void MpcTracker::setSinglePointReference(const double x, const double y, const double z, const double yaw) {

  std::scoped_lock lock(mutex_des_trajectory_);

  des_x_trajectory_.fill(x);
  des_y_trajectory_.fill(y);
  des_z_trajectory_.fill(z);
  des_yaw_trajectory_.fill(yaw);
}

//}

/* //{ setGoal() */

// set absolute goal
void MpcTracker::setGoal(const double pos_x, const double pos_y, const double pos_z, const double yaw, const bool use_yaw) {

  double desired_yaw = yaw;

  auto mpc_x_yaw = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_yaw_);

  if (!use_yaw) {
    desired_yaw = mpc_x_yaw(0, 0);
  }

  trajectory_tracking_in_progress_ = false;
  timer_trajectory_tracking_.stop();

  setSinglePointReference(pos_x, pos_y, pos_z, desired_yaw);

  publishDiagnostics();
}

//}

/* //{ setRelativeGoal() */

void MpcTracker::setRelativeGoal(const double pos_x, const double pos_y, const double pos_z, const double yaw, const bool use_yaw) {

  auto [mpc_x, mpc_x_yaw] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_yaw_);

  double abs_x = mpc_x(0, 0) + pos_x;
  double abs_y = mpc_x(4, 0) + pos_y;
  double abs_z = mpc_x(8, 0) + pos_z;

  double abs_yaw = mpc_x_yaw(0, 0);

  if (use_yaw) {
    abs_yaw += yaw;
  }

  trajectory_tracking_in_progress_ = false;
  timer_trajectory_tracking_.stop();

  setSinglePointReference(abs_x, abs_y, abs_z, abs_yaw);

  publishDiagnostics();
}

//}

/* toggleHover() //{ */

void MpcTracker::toggleHover(bool in) {

  if (in == false && hovering_in_progress_) {

    ROS_DEBUG("[MpcTracker]: stoppping the hover timer");

    while (hover_timer_runnning_) {

      ROS_DEBUG("[MpcTracker]: the hover is in the middle of an iteration, waiting for it to finish");
      ros::Duration wait(0.01);
      wait.sleep();
    }

    timer_hover_.stop();

    hovering_in_progress_ = false;

  } else if (in == true && !hovering_in_progress_) {

    ROS_DEBUG("[MpcTracker]: starting the hover timer");

    hovering_in_progress_ = true;

    timer_hover_.start();
  }
}

//}

// | ------------------- trajectory tracking ------------------ |

/* startTrajectoryTrackingImpl() //{ */

std::tuple<bool, std::string> MpcTracker::startTrajectoryTrackingImpl(void) {

  std::stringstream ss;

  if (trajectory_set_) {

    toggleHover(false);

    {
      std::scoped_lock lock(mutex_des_trajectory_);

      trajectory_tracking_in_progress_ = true;
      trajectory_tracking_idx_         = 0;
      trajectory_tracking_sub_idx_     = 0;
    }

    timer_trajectory_tracking_.setPeriod(ros::Duration(trajectory_dt_));
    timer_trajectory_tracking_.start();

    publishDiagnostics();

    ss << "trajectory tracking started";
    ROS_INFO_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    return std::tuple(true, ss.str());

  } else {

    ss << "can not start trajectory tracking, the trajectory is not set";
    ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

/* resumeTrajectoryTrackingImpl() //{ */

std::tuple<bool, std::string> MpcTracker::resumeTrajectoryTrackingImpl(void) {

  std::stringstream ss;

  if (trajectory_set_) {

    toggleHover(false);

    auto trajectory_tracking_idx = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_tracking_idx_);

    if (trajectory_tracking_idx < (trajectory_size_ - 1)) {

      {
        std::scoped_lock lock(mutex_des_trajectory_);

        trajectory_tracking_in_progress_ = true;
      }

      timer_trajectory_tracking_.setPeriod(ros::Duration(trajectory_dt_));
      timer_trajectory_tracking_.start();

      ss << "trajectory tracking resumed";
      ROS_INFO_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

      publishDiagnostics();

      return std::tuple(true, ss.str());

    } else {

      ss << "can not resume trajectory tracking, trajectory is already finished";
      ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

      return std::tuple(false, ss.str());
    }

  } else {

    ss << "can not resume trajectory tracking, ther trajectory is not set";
    ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

/* stopTrajectoryTrackingImpl() //{ */

std::tuple<bool, std::string> MpcTracker::stopTrajectoryTrackingImpl(void) {

  std::stringstream ss;

  if (trajectory_tracking_in_progress_) {

    trajectory_tracking_in_progress_ = false;
    timer_trajectory_tracking_.stop();

    toggleHover(true);

    ss << "stopping trajectory tracking";
    ROS_INFO_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    publishDiagnostics();

  } else {

    ss << "can not stop trajectory tracking, already at stop";
    ROS_INFO_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());
  }

  return std::tuple(true, ss.str());
}

//}

/* gotoTrajectoryStartImpl() //{ */

std::tuple<bool, std::string> MpcTracker::gotoTrajectoryStartImpl(void) {

  std::stringstream ss;

  if (trajectory_set_) {

    toggleHover(false);

    trajectory_tracking_in_progress_ = false;
    timer_trajectory_tracking_.stop();

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

      setGoal((*des_x_whole_trajectory_)[0], (*des_y_whole_trajectory_)[0], (*des_z_whole_trajectory_)[0], (*des_yaw_whole_trajectory_)[0],
              trajectory_track_yaw_);
    }

    publishDiagnostics();

    ss << "flying to the start of the trajectory";
    ROS_INFO_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    return std::tuple(true, ss.str());

  } else {

    ss << "can not fly to the start of the trajectory, the trajectory is not set";
    ROS_WARN_STREAM_THROTTLE(1.0, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

// | ------------------------- support ------------------------ |

/* //{ publishDiagnostics() */

void MpcTracker::publishDiagnostics(void) {

  mrs_msgs::MpcTrackerDiagnostics diagnostics;

  diagnostics.header.stamp    = ros::Time::now();
  diagnostics.header.frame_id = uav_state_.header.frame_id;

  diagnostics.uav_name = _uav_name_;

  diagnostics.collision_avoidance_active = collision_avoidance_enabled_;
  diagnostics.avoiding_collision         = avoiding_collision_;

  diagnostics.setpoint.position.x = des_x_trajectory_(0, 0);
  diagnostics.setpoint.position.y = des_y_trajectory_(0, 0);
  diagnostics.setpoint.position.z = des_z_trajectory_(0, 0);

  diagnostics.setpoint.orientation = mrs_lib::AttitudeConverter(0, 0, des_yaw_trajectory_(0, 0));

  std::stringstream ss;

  {
    std::scoped_lock lock(mutex_other_uav_diagnostics_);

    // fill in if other UAVs are sending their trajectories
    std::map<std::string, mrs_msgs::MpcTrackerDiagnostics>::iterator u = other_uav_diagnostics_.begin();

    while (u != other_uav_diagnostics_.end()) {

      if (u->second.collision_avoidance_active) {

        // is the other's trajectory fresh enought?
        if ((ros::Time::now() - u->second.header.stamp).toSec() < _collision_trajectory_timeout_) {
          diagnostics.avoidance_active_uavs.push_back(u->first);
          ss << u->first.c_str() << ", ";
        }
      }

      u++;
    }
  }

  if (ss.str().length() > 0) {
    ROS_DEBUG_STREAM_THROTTLE(5.0, "[MpcTracker]: getting avoidance trajectories: " << ss.str());
  } else if (got_odometry_diagnostics_ && collision_avoidance_enabled_ &&
             ((odometry_diagnostics_.estimator_type.name == "GPS") || odometry_diagnostics_.estimator_type.name == "RTK")) {
    ROS_DEBUG_THROTTLE(10.0, "[MpcTracker]: missing avoidance trajectories!");
  }

  try {
    pub_diagnostics_.publish(diagnostics);
  }
  catch (...) {
    ROS_ERROR("[MpcTracker]: exception caught during publishing topic %s", pub_diagnostics_.getTopic().c_str());
  }
}

//}

// --------------------------------------------------------------
// |                           timers                           |
// --------------------------------------------------------------

/* //{ timerDiagnostics() */

// published diagnostics in reguar intervals
void MpcTracker::timerDiagnostics(const ros::TimerEvent& event) {

  if (!is_initialized_)
    return;

  mrs_lib::Routine profiler_routine = profiler.createRoutine("timerDiagnostics", _diagnostics_rate_, 0.1, event);

  publishDiagnostics();
}

//}

/* //{ timerModelIteration() */

void MpcTracker::timerModelIteration(const ros::TimerEvent& event) {

  if (odometry_reset_in_progress_) {
    ROS_ERROR("[MpcTracker]: MPC tried to run while reseting odometry");
    return;
  }

  mrs_lib::ScopeUnset unset_running(model_timer_running_);

  bool started_with_invalid = mpc_result_invalid_;

  if (!is_active_) {
    return;
  }

  if (!is_initialized_) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler.createRoutine("mpcIteration", int(1.0 / _dt1_), 0.01, event);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto [trajectory_tracking_sub_idx, trajectory_tracking_idx] =
      mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_tracking_sub_idx_, trajectory_tracking_idx_);
  auto trajectory_dt = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_dt_);

  ros::Time     begin = ros::Time::now();
  ros::Time     end;
  ros::Duration interval;

  // if we are tracking trajectory, copy the setpoint
  if (trajectory_tracking_in_progress_) {

    /* interpolate the trajectory points and fill in the desired_trajectory vector //{ */

    {
      std::scoped_lock lock(mutex_des_trajectory_, mutex_des_whole_trajectory_);

      for (int i = 0; i < _mpc_horizon_len_; i++) {

        double first_time = _dt1_ + i * _dt2_ + trajectory_tracking_sub_idx * _dt1_;

        int first_idx  = trajectory_tracking_idx + floor(first_time / trajectory_dt);
        int second_idx = first_idx + 1;

        double interp_coeff = std::fmod(double(first_time), trajectory_dt) / trajectory_dt;

        if (trajectory_tracking_loop_) {

          if (second_idx >= trajectory_size_) {
            second_idx -= trajectory_size_;
          }

          if (first_idx >= trajectory_size_) {
            first_idx -= trajectory_size_;
          }
        } else {

          if (second_idx >= trajectory_size_) {
            second_idx = trajectory_size_ - 1;
          }

          if (first_idx >= trajectory_size_) {
            first_idx = trajectory_size_ - 1;
          }
        }

        des_x_trajectory_(i, 0) = (1 - interp_coeff) * (*des_x_whole_trajectory_)(first_idx) + interp_coeff * (*des_x_whole_trajectory_)(second_idx);
        des_y_trajectory_(i, 0) = (1 - interp_coeff) * (*des_y_whole_trajectory_)(first_idx) + interp_coeff * (*des_y_whole_trajectory_)(second_idx);
        des_z_trajectory_(i, 0) = (1 - interp_coeff) * (*des_z_whole_trajectory_)(first_idx) + interp_coeff * (*des_z_whole_trajectory_)(second_idx);

        des_yaw_trajectory_(i, 0) =
            mrs_lib::interpolateAngles((*des_yaw_whole_trajectory_)(first_idx), (*des_yaw_whole_trajectory_)(second_idx), 1 - interp_coeff);
      }
    }

    //}

    // increase the trajectory subsampling counter
    {
      std::scoped_lock lock(mutex_trajectory_tracking_states_);

      trajectory_tracking_sub_idx_++;
    }
  }

  manageConstraints();

  calculateMPC();

  end      = ros::Time::now();
  interval = end - begin;

  // | ----------------- acumulate the MPC delay ---------------- |
  if (interval.toSec() > _dt1_) {

    mpc_total_delay_ += interval.toSec() - _dt1_;
    double perc_slower = 100 * mpc_total_delay_ / (ros::Time::now() - mpc_start_time_).toSec();

    if (perc_slower >= 1.0) {
      ROS_WARN_THROTTLE(10.0, "[MpcTracker] MPC is Running %.2f%% slower than it should", perc_slower);
    }
  }

  mpc_computed_ = true;

  /* publish mpc reference //{ */

  {
    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = ros::Time::now();
    debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

    {
      std::scoped_lock lock(mutex_predicted_trajectory_);

      for (int i = 0; i < _mpc_horizon_len_; i++) {

        geometry_msgs::Pose new_pose;

        new_pose.position.x = des_x_filtered_(i, 0);
        new_pose.position.y = des_y_filtered_(i, 0);
        new_pose.position.z = des_z_filtered_(i, 0);

        new_pose.orientation = mrs_lib::AttitudeConverter(0, 0, des_yaw_trajectory_(i));

        debug_trajectory_out.poses.push_back(new_pose);
      }
    }

    try {
      publisher_mpc_reference_debugging_.publish(debug_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: exception caught during publishing topic %s", publisher_mpc_reference_debugging_.getTopic().c_str());
    }
  }

  //}

  /* publish predicted future //{ */

  {
    geometry_msgs::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = ros::Time::now();
    debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

    {
      std::scoped_lock lock(mutex_predicted_trajectory_);

      for (int i = 0; i < _mpc_horizon_len_; i++) {

        geometry_msgs::Pose newPose;

        newPose.position.x = predicted_trajectory_(i * _mpc_n_states_);
        newPose.position.y = predicted_trajectory_(i * _mpc_n_states_ + 4);
        newPose.position.z = predicted_trajectory_(i * _mpc_n_states_ + 8);

        newPose.orientation = mrs_lib::AttitudeConverter(0, 0, predicted_yaw_trajectory_(i * _mpc_n_states_));

        debug_trajectory_out.poses.push_back(newPose);
      }
    }

    try {
      publisher_predicted_trajectory_debugging_.publish(debug_trajectory_out);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: exception caught during publishing topic %s", publisher_predicted_trajectory_debugging_.getTopic().c_str());
    }
  }

  //}

  if (started_with_invalid) {
    mpc_result_invalid_ = false;
    ROS_INFO("[MpcTracker]: calculated first MPC result after invalidation, x %.2f, y %.2f, hor1x %.2f, hor1y %.2f", mpc_x_(0, 0), mpc_x_(4, 0),
             des_x_trajectory_(0, 0), des_y_trajectory_(0, 0));
  }
}

//}

/* timerTrajectoryTracking() //{ */

void MpcTracker::timerTrajectoryTracking(const ros::TimerEvent& event) {

  auto trajectory_size = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_size_);
  auto trajectory_dt   = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_dt_);

  mrs_lib::Routine profiler_routine = profiler.createRoutine("timerTrajectoryTracking", int(1.0 / trajectory_dt), 0.01, event);

  {
    std::scoped_lock lock(mutex_trajectory_tracking_states_);

    // do a step of the main tracking idx

    // reset the subsampling counter
    trajectory_tracking_sub_idx_ = 0;

    // INCREMENT THE TRACKING IDX
    trajectory_tracking_idx_++;

    // if the tracking idx hits the end of the trajectory
    if (trajectory_tracking_idx_ == trajectory_size) {

      if (trajectory_tracking_loop_) {

        // reset the idx
        trajectory_tracking_idx_ = 0;

        ROS_INFO("[MpcTracker]: trajectory looped");

      } else {

        trajectory_tracking_in_progress_ = false;

        // set the idx to the last idx of the trajectory
        trajectory_tracking_idx_ = trajectory_size - 1;

        timer_trajectory_tracking_.stop();

        ROS_INFO("[MpcTracker]: done tracking trajectory");
      }
    }
  }

  publishDiagnostics();
}

//}

/* //{ timerAvoidanceTrajectory() */

void MpcTracker::timerAvoidanceTrajectory(const ros::TimerEvent& event) {

  if (!is_active_) {
    return;
  }

  if (!is_initialized_) {
    return;
  }

  mrs_lib::Routine profiler_routine = profiler.createRoutine("timerAvoidanceTrajectory", _avoidance_trajectory_rate_, 0.1, event);

  auto uav_state            = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto predicted_trajectory = mrs_lib::get_mutexed(mutex_predicted_trajectory_, predicted_trajectory_);

  if (future_was_predicted_) {

    mrs_msgs::FutureTrajectory avoidance_trajectory;

    // fill last trajectory with initial data
    avoidance_trajectory.stamp    = ros::Time::now();
    avoidance_trajectory.uav_name = _uav_name_;
    avoidance_trajectory.priority = avoidance_this_uav_priority_;
    avoidance_trajectory.collision_avoidance =
        collision_avoidance_enabled_ && ((odometry_diagnostics_.estimator_type.name == "GPS") || odometry_diagnostics_.estimator_type.name == "RTK");

    avoidance_trajectory.points.clear();
    avoidance_trajectory.stamp               = ros::Time::now();
    avoidance_trajectory.uav_name            = _uav_name_;
    avoidance_trajectory.priority            = avoidance_this_uav_priority_;
    avoidance_trajectory.collision_avoidance = collision_avoidance_enabled_;

    // transform it from utm_origin to the currently used frame
    auto res = common_handlers_->transformer->getTransform(uav_state.header.frame_id, "utm_origin", ros::Time::now(), true);

    if (!res) {

      std::string message = "[MpcTracker]: can not transform predicted future to utm_origin";
      ROS_WARN_STREAM_ONCE(message);
      ROS_DEBUG_STREAM_THROTTLE(1.0, message);
      return;

    } else {

      mrs_lib::TransformStamped tf = res.value();

      for (int i = 0; i < _mpc_horizon_len_; i++) {

        // original point
        geometry_msgs::PoseStamped original_point;

        original_point.header.stamp    = ros::Time::now();
        original_point.header.frame_id = uav_state.header.frame_id;

        original_point.pose.position.x = predicted_trajectory(i * _mpc_n_states_);
        original_point.pose.position.y = predicted_trajectory(i * _mpc_n_states_ + 4);
        original_point.pose.position.z = predicted_trajectory(i * _mpc_n_states_ + 8);

        original_point.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

        auto res = common_handlers_->transformer->transform(tf, original_point);

        if (res) {

          mrs_msgs::FuturePoint new_point;

          new_point.x = res.value().pose.position.x;
          new_point.y = res.value().pose.position.y;
          new_point.z = res.value().pose.position.z;

          avoidance_trajectory.points.push_back(new_point);

        } else {

          std::string message = "[MpcTracker]: can not transform a point of a future trajectory";
          ROS_WARN_STREAM_ONCE(message);
          ROS_DEBUG_STREAM_THROTTLE(1.0, message);
        }
      }
    }

    try {
      avoidance_trajectory_publisher_.publish(avoidance_trajectory);
    }
    catch (...) {
      ROS_ERROR("[MpcTracker]: exception caught during publishing topic %s", avoidance_trajectory_publisher_.getTopic().c_str());
    }
  }
}

//}

/* timerHover() //{ */

void MpcTracker::timerHover(const ros::TimerEvent& event) {

  mrs_lib::ScopeUnset unset_running(model_timer_running_);

  auto mpc_x = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);

  mrs_lib::Routine profiler_routine = profiler.createRoutine("timerHover", 10, 0.01, event);

  setRelativeGoal(0, 0, 0, 0, false);

  if (fabs(mpc_x(1, 0)) < 0.1 && fabs(mpc_x(5, 0)) < 0.1 && fabs(mpc_x(9, 0)) < 0.1) {

    toggleHover(false);

    ROS_INFO("[MpcTracker]: timerHover: speed is low, stopping hover timer");
  }
}

//}

}  // namespace mpc_tracker

}  // namespace mrs_trackers

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(mrs_trackers::mpc_tracker::MpcTracker, mrs_uav_manager::Tracker)
