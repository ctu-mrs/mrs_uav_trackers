/* includes //{ */

#include <rclcpp/rclcpp.hpp>

#include <mrs_uav_managers/tracker.h>
#include <mrs_uav_managers/controller.h>

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>

#include <mrs_msgs/msg/future_point.hpp>
#include <mrs_msgs/msg/future_trajectory.hpp>
#include <mrs_msgs/msg/mpc_tracker_diagnostics.hpp>
#include <mrs_msgs/msg/mpc_prediction_full_state.hpp>
#include <mrs_msgs/msg/estimation_diagnostics.hpp>
#include <mrs_msgs/msg/velocity_reference.hpp>
#include <mrs_msgs/msg/velocity_reference_stamped.hpp>

#include <std_msgs/msg/string.hpp>

#include <mrs_lib/profiler.h>
#include <mrs_lib/utils.h>
#include <mrs_lib/mutex.h>
#include <mrs_lib/attitude_converter.h>
#include <mrs_lib/subscriber_handler.h>
#include <mrs_lib/publisher_handler.h>
#include <mrs_lib/service_server_handler.h>
#include <mrs_lib/geometry/cyclic.h>
#include <mrs_lib/geometry/misc.h>
#include <mrs_lib/scope_timer.h>
#include <mrs_lib/dynparam_mgr.h>

#include <mrs_mpc_solvers/mpc_tracker.h>

#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>

//}

/* defines //{ */

#define MPC_N_STATES 12
#define MPC_N_INPUTS 3

#define MPC_HEADING_N_STATES 4
#define MPC_HEADING_N_INPUTS 1

#define MPC_HORIZON_LENGTH 40

//}

/* using //{ */

using namespace Eigen;

using vec2_t = mrs_lib::geometry::vec_t<2>;
using vec3_t = mrs_lib::geometry::vec_t<3>;

using radians  = mrs_lib::geometry::radians;
using sradians = mrs_lib::geometry::sradians;

using quat_t = Eigen::Quaterniond;

using namespace std::chrono_literals;

//}

/* typedefs //{ */

#if USE_ROS_TIMER == 1
typedef mrs_lib::ROSTimer TimerType;
#else
typedef mrs_lib::ThreadTimer TimerType;
#endif

//}

namespace mrs_uav_trackers
{

namespace mpc_tracker
{

/* //{ class MpcTracker */

class MpcTracker : public mrs_uav_managers::Tracker {
public:
  bool initialize(const rclcpp::Node::SharedPtr &node, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers);

  void destroy(void);

  std::tuple<bool, std::string> activate(const std::optional<mrs_msgs::msg::TrackerCommand> &last_tracker_cmd);
  void                          deactivate(void);
  bool                          resetStatic(void);

  std::optional<mrs_msgs::msg::TrackerCommand>            update(const mrs_msgs::msg::UavState                     &uav_state,
                                                                 const mrs_uav_managers::Controller::ControlOutput &last_control_output);
  const mrs_msgs::msg::TrackerStatus                      getStatus();
  const std::shared_ptr<std_srvs::srv::SetBool::Response> enableCallbacks(const std::shared_ptr<std_srvs::srv::SetBool::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> switchOdometrySource(const mrs_msgs::msg::UavState &new_uav_state);

  const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response> setReference(const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Request> &request);
  const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response>
  setVelocityReference(const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Request> &request);
  const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response>
  setTrajectoryReference(const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Request> &request);

  const std::shared_ptr<std_srvs::srv::Trigger::Response> hover(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> startTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> stopTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> resumeTrajectoryTracking(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);
  const std::shared_ptr<std_srvs::srv::Trigger::Response> gotoTrajectoryStart(const std::shared_ptr<std_srvs::srv::Trigger::Request> &request);

  const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response>
  setConstraints(const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Request> &request);

private:
  rclcpp::Node::SharedPtr  node_;
  rclcpp::Clock::SharedPtr clock_;

  rclcpp::CallbackGroup::SharedPtr cbkgrp_subs_;
  rclcpp::CallbackGroup::SharedPtr cbkgrp_timers_;
  rclcpp::CallbackGroup::SharedPtr cbkgrp_ss_;

  std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t>  common_handlers_;
  std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers_;

  std::atomic<bool> callbacks_enabled_ = true;

  std::string _uav_name_;

  // debugging publishers
  mrs_lib::PublisherHandler<mrs_msgs::msg::MpcTrackerDiagnostics> pub_diagnostics_;
  mrs_lib::PublisherHandler<std_msgs::msg::String>                pub_status_string_;

  mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>        pub_debug_processed_trajectory_poses_;
  mrs_lib::PublisherHandler<visualization_msgs::msg::MarkerArray> pub_debug_processed_trajectory_markers_;

  mrs_msgs::msg::UavState uav_state_;
  std::mutex              mutex_uav_state_;

  rclcpp::Time time_last_update_;

  bool is_active_      = false;
  bool is_initialized_ = false;

  // | ----------------------- constraints ---------------------- |

  mrs_msgs::msg::DynamicsConstraints constraints_;
  std::mutex                         mutex_constraints_;

  mrs_msgs::msg::DynamicsConstraints constraints_filtered_;
  std::mutex                         mutex_constraints_filtered_;

  std::atomic<bool> got_constraints_     = false;
  std::atomic<bool> all_constraints_set_ = false;

  double _diag_pos_tracking_thr_;
  double _diag_heading_tracking_thr_;

  double _mpc_synchronous_rate_limit_;
  double _mpc_asynchronous_rate_;

  double update_rate_ = 100.0;

  double     dt1_;
  std::mutex mutex_dt1_;

  double _dt2_;

  MatrixXd          _mat_A_; // system matrix for virtual UAV
  MatrixXd          _mat_B_; // input matrix for virtual UAV
  MatrixXd          A_;      // system matrix for virtual UAV
  MatrixXd          B_;      // input matrix for virtual UAV
  std::atomic<bool> model_first_iteration_ = true;
  rclcpp::Time      model_iteration_last_time_;

  MatrixXd _mat_A_heading_; // system matrix for heading
  MatrixXd _mat_B_heading_; // input matrix for heading
  MatrixXd A_heading_;      // system matrix for heading
  MatrixXd B_heading_;      // input matrix for heading

  // the reference over the prediction horizon per axis
  MatrixXd   des_x_trajectory_;
  MatrixXd   des_y_trajectory_;
  MatrixXd   des_z_trajectory_;
  MatrixXd   des_heading_trajectory_;
  std::mutex mutex_des_trajectory_;

  // the reference filtered over the prediction horizon per axis
  MatrixXd des_z_filtered_offset_;

  // the whole trajectory reference split per axis
  std::shared_ptr<VectorXd> des_x_whole_trajectory_;
  std::shared_ptr<VectorXd> des_y_whole_trajectory_;
  std::shared_ptr<VectorXd> des_z_whole_trajectory_;
  std::shared_ptr<VectorXd> des_heading_whole_trajectory_;
  int                       des_whole_trajectory_id_ = 0;
  std::mutex                mutex_des_whole_trajectory_;

  int  getCurrentTrajectoryIdx();
  void increaseCurrentTrajectoryTime(const double dt);

  // trajectory tracking
  std::atomic<bool> trajectory_tracking_in_progress_ = false;
  double            trajectory_current_time_;
  std::mutex        mutex_trajectory_tracking_states_;

  // params of the loaded trajectory
  int    trajectory_size_          = 0;
  double trajectory_dt_            = 0.2;
  bool   trajectory_track_heading_ = false;
  bool   trajectory_tracking_loop_ = false;
  bool   trajectory_set_           = false;
  int    trajectory_count_         = 0; // counts how many trajectories we have received

  // mpc output
  VectorXd   mpc_u_;
  double     mpc_u_heading_;
  std::mutex mutex_mpc_u_;

  // current state of the dynamical system
  MatrixXd   mpc_x_;         // translation state
  MatrixXd   mpc_x_heading_; // heading state
  std::mutex mutex_mpc_x_;

  // odometry reset
  std::atomic<bool> odometry_reset_in_progress_ = false;
  std::atomic<bool> mpc_result_invalid_         = false;

  // predicting the future
  MatrixXd   predicted_trajectory_;
  MatrixXd   predicted_heading_trajectory_;
  std::mutex mutex_predicted_trajectory_;

  mrs_msgs::msg::MpcPredictionFullState prediction_full_state_;
  std::mutex                            mutex_prediction_full_state_;

  mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>   ph_predicted_trajectory_debugging_;
  mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>   ph_mpc_reference_debugging_;
  mrs_lib::PublisherHandler<geometry_msgs::msg::PoseStamped> ph_current_trajectory_point_;
  mrs_lib::PublisherHandler<geometry_msgs::msg::PoseStamped> ph_first_reference_point_;

  std::atomic<bool> mpc_computed_ = false;

  bool brake_ = false;

  // | ----------------------- MPC solver ----------------------- |

  std::shared_ptr<mrs_mpc_solvers::mpc_tracker::Solver> mpc_solver_y_;
  std::shared_ptr<mrs_mpc_solvers::mpc_tracker::Solver> mpc_solver_x_;
  std::shared_ptr<mrs_mpc_solvers::mpc_tracker::Solver> mpc_solver_z_;
  std::shared_ptr<mrs_mpc_solvers::mpc_tracker::Solver> mpc_solver_heading_;

  std::mutex mutex_mpc_calculation_;

  int _max_iters_xy_;
  int _max_iters_z_;
  int _max_iters_heading_;

  // | ----------- measuring the "MPC realtime factor" ---------- |

  double mpc_rtf_ = 0.0;

  // | ------------------- collision avoidance ------------------ |

  // configurable params
  bool collision_avoidance_enabled_           = false;
  bool collision_avoidance_enabled_passively_ = true;

  // TODO what is this?
  double       coef_scaler = 0;
  rclcpp::Time coef_time;

  double minimum_collison_free_altitude_ = std::numeric_limits<double>::lowest();

  // params
  double                   _avoidance_trajectory_rate_;
  double                   _avoidance_radius_threshold_;
  double                   _avoidance_z_correction_;
  std::string              _avoidance_diagnostics_topic_name_;
  std::vector<std::string> _avoidance_other_uav_names_;
  double                   _avoidance_z_threshold_;

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

  double            collision_free_altitude_;
  std::atomic<bool> avoiding_collision_               = false;
  bool              collision_avoidance_affecting_me_ = false;

  // avoidance trajectory will not be published unless we computed it at least once
  std::atomic<bool> future_was_predicted_ = false;

  // subscribing to the other UAV future trajectories
  void callbackOtherMavTrajectory(const mrs_msgs::msg::FutureTrajectory::ConstSharedPtr msg);

  std::vector<std::shared_ptr<mrs_lib::SubscriberHandler<mrs_msgs::msg::FutureTrajectory>>> other_uav_trajectory_subscribers_;
  std::map<std::string, mrs_msgs::msg::FutureTrajectory>                                    other_uav_avoidance_trajectories_;
  std::mutex                                                                                mutex_other_uav_avoidance_trajectories_;

  // subscribing to the other UAV diagnostics'
  void callbackOtherMavDiagnostics(const mrs_msgs::msg::MpcTrackerDiagnostics::ConstSharedPtr msg);

  std::vector<std::shared_ptr<mrs_lib::SubscriberHandler<mrs_msgs::msg::MpcTrackerDiagnostics>>> other_uav_diag_subscribers_;
  std::map<std::string, mrs_msgs::msg::MpcTrackerDiagnostics>                                    other_uav_diagnostics_;
  std::mutex                                                                                     mutex_other_uav_diagnostics_;

  bool checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz);
  bool checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz);

  mrs_lib::PublisherHandler<mrs_msgs::msg::FutureTrajectory> ph_avoidance_trajectory_;

  mrs_lib::ServiceServerHandler<std_srvs::srv::SetBool> ss_toggle_avoidance_;
  bool                                                  callbackToggleCollisionAvoidance(const std::shared_ptr<std_srvs::srv::SetBool::Request>  request,
                                                                                         const std::shared_ptr<std_srvs::srv::SetBool::Response> response);

  mrs_lib::SubscriberHandler<mrs_msgs::msg::EstimationDiagnostics> sh_estimation_diag_;

  // | --------------------- MPC calculation -------------------- |

  std::shared_ptr<TimerType> timer_mpc_iteration_;
  std::atomic<bool>          mpc_synchronous_ = false;

  std::atomic<bool> mpc_timer_running_ = false;
  void              timerMPC();

  rclcpp::Time time_last_mpc_calculation_;

  // | -------------------- velocity tracking ------------------- |

  std::shared_ptr<TimerType>       timer_velocity_tracking_;
  void                             timerVelocityTracking();
  rclcpp::Time                     velocity_reference_time_;
  mrs_msgs::msg::VelocityReference velocity_reference_;
  std::mutex                       mutex_velocity_reference_;
  std::atomic<bool>                velocity_tracking_active_ = false;

  // | ------------------ avoidance trajectory ------------------ |

  std::shared_ptr<TimerType> timer_avoidance_trajectory_;
  void                       timerAvoidanceTrajectory();

  // | ----------------------- diagnostics ---------------------- |

  std::shared_ptr<TimerType> timer_diagnostics_;
  double                     _diagnostics_rate_;
  void                       timerDiagnostics();

  // | ------------------------ hovering ------------------------ |

  std::shared_ptr<TimerType> timer_hover_;
  void                       timerHover();
  std::atomic<bool>          hovering_in_progress_ = false;
  void                       toggleHover(bool in);

  // | ------------------- trajectory tracking ------------------ |

  std::tuple<bool, std::string> resumeTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> startTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> stopTrajectoryTrackingImpl(void);
  std::tuple<bool, std::string> gotoTrajectoryStartImpl(void);

  // | --------------------- other routines --------------------- |

  void publishDiagnostics();

  void debugPrintState(const double throttle);
  void debugPrintMPCResult(const double throttle);

  void setGoal(const double pos_x, const double pos_y, const double pos_z, const double heading, const bool use_heading);
  void setRelativeGoal(const double pos_x, const double pos_y, const double pos_z, const double heading, const bool use_heading);
  void setSinglePointReference(const double x, const double y, const double z, const double heading);

  std::tuple<bool, std::string, bool> loadTrajectory(const mrs_msgs::msg::TrajectoryReference msg);

  MatrixXd                       filterReferenceZ(const VectorXd &des_z_trajectory, const double max_ascending_speed, const double max_descending_speed);
  std::tuple<MatrixXd, MatrixXd> filterReferenceXY(const VectorXd &des_x_trajectory, const VectorXd &des_y_trajectory, double max_speed_x, double max_speed_y);

  double checkTrajectoryForCollisions(int &first_collision_index);

  void manageConstraints(void);
  void calculateMPC(void);
  void iterateModel(const double &dt);

  // | ------------------------ profiler ------------------------ |

  mrs_lib::Profiler profiler;
  bool              _profiler_enabled_ = false;

  // | ------------------------- wiggle ------------------------- |

  mrs_lib::ServiceServerHandler<std_srvs::srv::SetBool> ss_wiggle_;
  bool callbackWiggle(const std::shared_ptr<std_srvs::srv::SetBool::Request> request, const std::shared_ptr<std_srvs::srv::SetBool::Response> response);

  double wiggle_phase_ = 0;

  // | --------------- dynamic reconfigure server --------------- |

  std::shared_ptr<mrs_lib::DynparamMgr> dynparam_mgr_;

  struct drs_params
  {
    bool   wiggle_enabled   = false;
    double wiggle_amplitude = 0.0;
    double wiggle_frequency = 0.0;
    bool   braking_enabled  = false;
    double q_vel_braking    = 0.0;
    double q_vel_no_braking = 0.0;
  };

  drs_params drs_params_;
  std::mutex mutex_drs_params_;
};

//}

// | -------------- tracker's interface routines -------------- |

/* //{ initialize() */

bool MpcTracker::initialize(const rclcpp::Node::SharedPtr &node, std::shared_ptr<mrs_uav_managers::control_manager::CommonHandlers_t> common_handlers,
                            std::shared_ptr<mrs_uav_managers::control_manager::PrivateHandlers_t> private_handlers) {

  this->common_handlers_  = common_handlers;
  this->private_handlers_ = private_handlers;

  _uav_name_ = common_handlers->uav_name;

  node_  = node;
  clock_ = node->get_clock();

  cbkgrp_subs_   = node_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  cbkgrp_timers_ = node_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  cbkgrp_ss_     = node_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  time_last_update_          = rclcpp::Time(0, 0, clock_->get_clock_type());
  time_last_mpc_calculation_ = rclcpp::Time(0, 0, clock_->get_clock_type());

  // --------------------------------------------------------------
  // |                     loading parameters                     |
  // --------------------------------------------------------------

  dynparam_mgr_ = std::make_shared<mrs_lib::DynparamMgr>(node_, mutex_drs_params_);

  // | ---------- loading params using the parent's nh ---------- |

  private_handlers->parent_param_loader->loadParamReusable("enable_profiler", _profiler_enabled_);

  private_handlers->parent_param_loader->loadParamReusable("network/robot_names", _avoidance_other_uav_names_);

  if (!private_handlers->parent_param_loader->loadedSuccessfully()) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: Could not load all parameters!");
    return false;
  }

  // | --------------- loading plugin's parameters -------------- |

  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") + "/config/private/mpc_tracker.yaml");
  private_handlers->param_loader->addYamlFile(ament_index_cpp::get_package_share_directory("mrs_uav_trackers") + "/config/public/mpc_tracker.yaml");

  dynparam_mgr_->get_param_provider().copyYamls(private_handlers->param_loader->getParamProvider());

  private_handlers->param_loader->loadParam("mpc_loop/synchronous_rate_limit", _mpc_synchronous_rate_limit_);
  private_handlers->param_loader->loadParam("mpc_loop/asynchronous_loop_rate", _mpc_asynchronous_rate_);

  if (_mpc_asynchronous_rate_ < 15) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: the asynchronous_loop_rate must be > 15 Hz");
    return false;
  }

  dt1_ = 1.0 / _mpc_asynchronous_rate_;

  dynparam_mgr_->register_param("dynamic/braking/enabled", &drs_params_.braking_enabled, false);

  dynparam_mgr_->register_param("dynamic/braking/q_vel_braking", &drs_params_.q_vel_braking, mrs_lib::DynparamMgr::range_t<double>(0.0, 10000.0));

  dynparam_mgr_->register_param("dynamic/braking/q_vel_no_braking", &drs_params_.q_vel_no_braking, mrs_lib::DynparamMgr::range_t<double>(0.0, 10000.0));

  private_handlers->param_loader->loadMatrixKnown("model/translation/A", _mat_A_, MPC_N_STATES, MPC_N_STATES);
  private_handlers->param_loader->loadMatrixKnown("model/translation/B", _mat_B_, MPC_N_STATES, MPC_N_INPUTS);

  A_ = _mat_A_;
  B_ = _mat_B_;

  private_handlers->param_loader->loadMatrixKnown("model/heading/A", _mat_A_heading_, MPC_HEADING_N_STATES, MPC_HEADING_N_STATES);
  private_handlers->param_loader->loadMatrixKnown("model/heading/B", _mat_B_heading_, MPC_HEADING_N_STATES, MPC_HEADING_N_INPUTS);

  A_heading_ = _mat_A_heading_;
  B_heading_ = _mat_B_heading_;

  // load the MPC parameters
  private_handlers->param_loader->loadParam("mpc_solver/dt2", _dt2_);

  private_handlers->param_loader->loadParam("diagnostics/rate", _diagnostics_rate_);
  private_handlers->param_loader->loadParam("diagnostics/position_tracking_threshold", _diag_pos_tracking_thr_);
  private_handlers->param_loader->loadParam("diagnostics/orientation_tracking_threshold", _diag_heading_tracking_thr_);

  bool verbose_xy      = false;
  bool verbose_z       = false;
  bool verbose_heading = false;

  std::vector<double> xy_Q;
  std::vector<double> z_Q;
  std::vector<double> heading_Q;

  private_handlers->param_loader->loadParam("mpc_solver/xy/verbose", verbose_xy);
  private_handlers->param_loader->loadParam("mpc_solver/xy/max_n_iterations", _max_iters_xy_);
  private_handlers->param_loader->loadParam("mpc_solver/xy/Q", xy_Q);

  private_handlers->param_loader->loadParam("mpc_solver/z/verbose", verbose_z);
  private_handlers->param_loader->loadParam("mpc_solver/z/max_n_iterations", _max_iters_z_);
  private_handlers->param_loader->loadParam("mpc_solver/z/Q", z_Q);

  private_handlers->param_loader->loadParam("mpc_solver/heading/verbose", verbose_heading);
  private_handlers->param_loader->loadParam("mpc_solver/heading/max_n_iterations", _max_iters_heading_);
  private_handlers->param_loader->loadParam("mpc_solver/heading/Q", heading_Q);

  RCLCPP_INFO(node_->get_logger(), "subnamespace: %s", node_->get_sub_namespace().c_str());

  dynparam_mgr_->register_param("dynamic/wiggle/enabled", &drs_params_.wiggle_enabled);
  dynparam_mgr_->register_param("dynamic/wiggle/amplitude", &drs_params_.wiggle_amplitude, mrs_lib::DynparamMgr::range_t<double>(0.0, 2.0));
  dynparam_mgr_->register_param("dynamic/wiggle/frequency", &drs_params_.wiggle_frequency, mrs_lib::DynparamMgr::range_t<double>(0.0, 2.0));

  private_handlers->param_loader->loadParam("collision_avoidance/enabled", collision_avoidance_enabled_);
  private_handlers->param_loader->loadParam("collision_avoidance/enabled_passively", collision_avoidance_enabled_passively_);
  private_handlers->param_loader->loadParam("collision_avoidance/predicted_trajectory_publish_rate", _avoidance_trajectory_rate_);
  private_handlers->param_loader->loadParam("collision_avoidance/correction", _avoidance_z_correction_);
  private_handlers->param_loader->loadParam("collision_avoidance/radius", _avoidance_radius_threshold_);
  private_handlers->param_loader->loadParam("collision_avoidance/altitude_threshold", _avoidance_z_threshold_);
  private_handlers->param_loader->loadParam("collision_avoidance/collision_horizontal_speed_coef", _avoidance_collision_horizontal_speed_coef_);
  private_handlers->param_loader->loadParam("collision_avoidance/collision_slow_down_fully", _avoidance_collision_slow_down_fully_);
  private_handlers->param_loader->loadParam("collision_avoidance/collision_slow_down_start", _avoidance_collision_slow_down_);
  private_handlers->param_loader->loadParam("collision_avoidance/collision_start_climbing", _avoidance_collision_start_climbing_);
  private_handlers->param_loader->loadParam("collision_avoidance/trajectory_timeout", _collision_trajectory_timeout_);

  if (!private_handlers->param_loader->loadedSuccessfully() || !dynparam_mgr_->loaded_successfully()) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: could not load all parameters!");
    return false;
  }

  RCLCPP_INFO_STREAM(node_->get_logger(), "[MpcTracker]: initializing solvers with dt1 = " << dt1_);

  mpc_solver_y_ = std::make_shared<mrs_mpc_solvers::mpc_tracker::Solver>("MpcTracker_y", verbose_xy, _max_iters_xy_, xy_Q, dt1_, _dt2_, 1);
  mpc_solver_x_ = std::make_shared<mrs_mpc_solvers::mpc_tracker::Solver>("MpcTracker_x", verbose_xy, _max_iters_xy_, xy_Q, dt1_, _dt2_, 0);
  mpc_solver_z_ = std::make_shared<mrs_mpc_solvers::mpc_tracker::Solver>("MpcTracker_z", verbose_z, _max_iters_z_, z_Q, dt1_, _dt2_, 2);
  mpc_solver_heading_ =
      std::make_shared<mrs_mpc_solvers::mpc_tracker::Solver>("MpcTracker_hdg", verbose_heading, _max_iters_heading_, heading_Q, dt1_, _dt2_, 0);

  mpc_x_         = MatrixXd::Zero(MPC_N_STATES, 1);
  mpc_x_heading_ = MatrixXd::Zero(MPC_HEADING_N_STATES, 1);

  mpc_u_ = VectorXd::Zero(MPC_N_INPUTS);

  coef_time = rclcpp::Time(0, 0, clock_->get_clock_type());

  des_x_trajectory_       = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);
  des_y_trajectory_       = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);
  des_z_trajectory_       = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);
  des_z_filtered_offset_  = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);
  des_heading_trajectory_ = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);

  ss_wiggle_ = mrs_lib::ServiceServerHandler<std_srvs::srv::SetBool>(node_, "~/" + private_handlers_->name_space + "/wiggle",
                                                                     std::bind(&MpcTracker::callbackWiggle, this, std::placeholders::_1, std::placeholders::_2),
                                                                     rclcpp::SystemDefaultsQoS(), cbkgrp_ss_);

  pub_diagnostics_   = mrs_lib::PublisherHandler<mrs_msgs::msg::MpcTrackerDiagnostics>(node_, "~/" + private_handlers_->name_space + "/diagnostics");
  pub_status_string_ = mrs_lib::PublisherHandler<std_msgs::msg::String>(node_, "/" + common_handlers_->uav_name + "/uav_status_acquisition/display_string");

  // extract the numerical name
  sscanf(_uav_name_.c_str(), "uav%d", &avoidance_this_uav_number_);
  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: Numerical ID of this UAV is %d", avoidance_this_uav_number_);
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

  // initialize velocity tracker

  velocity_reference_time_ = rclcpp::Time(0, 0, clock_->get_clock_type());

  // create publishers for predicted trajectory

  ph_avoidance_trajectory_ = mrs_lib::PublisherHandler<mrs_msgs::msg::FutureTrajectory>(node_, "~/" + private_handlers_->name_space + "/predicted_trajectory");
  ph_predicted_trajectory_debugging_ =
      mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>(node_, "~/" + private_handlers_->name_space + "/predicted_trajectory_debugging");

  // TODO make these topics latching
  ph_mpc_reference_debugging_ =
      mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>(node_, "~/" + private_handlers_->name_space + "/mpc_reference_debugging");
  ph_current_trajectory_point_ =
      mrs_lib::PublisherHandler<geometry_msgs::msg::PoseStamped>(node_, "~/" + private_handlers_->name_space + "/current_trajectory_point");
  ph_first_reference_point_ =
      mrs_lib::PublisherHandler<geometry_msgs::msg::PoseStamped>(node_, "~/" + private_handlers_->name_space + "/first_reference_point");
  pub_debug_processed_trajectory_poses_ =
      mrs_lib::PublisherHandler<geometry_msgs::msg::PoseArray>(node_, "~/" + private_handlers_->name_space + "/trajectory_processed/poses");
  pub_debug_processed_trajectory_markers_ =
      mrs_lib::PublisherHandler<visualization_msgs::msg::MarkerArray>(node_, "~/" + private_handlers_->name_space + "/trajectory_processed/markers");

  // preallocate predicted trajectory
  predicted_trajectory_         = MatrixXd::Zero(MPC_HORIZON_LENGTH * MPC_N_STATES, 1);
  predicted_heading_trajectory_ = MatrixXd::Zero(MPC_HORIZON_LENGTH * MPC_N_STATES, 1);

  collision_free_altitude_ = std::numeric_limits<float>::lowest();

  // collision avoidance toggle service
  ss_toggle_avoidance_ = mrs_lib::ServiceServerHandler<std_srvs::srv::SetBool>(
      node_, "~/" + private_handlers_->name_space + "/collision_avoidance",
      std::bind(&MpcTracker::callbackToggleCollisionAvoidance, this, std::placeholders::_1, std::placeholders::_2), rclcpp::SystemDefaultsQoS(), cbkgrp_ss_);

  mrs_lib::SubscriberHandlerOptions shopts;
  shopts.node                                = node_;
  shopts.no_message_timeout                  = mrs_lib::no_timeout;
  shopts.threadsafe                          = true;
  shopts.autostart                           = true;
  shopts.subscription_options.callback_group = cbkgrp_subs_;

  // create subscribers on other drones diagnostics
  if (collision_avoidance_enabled_ || collision_avoidance_enabled_passively_) {

    for (int i = 0; i < int(_avoidance_other_uav_names_.size()); i++) {

      std::string prediction_topic_name = std::string("/") + _avoidance_other_uav_names_.at(i) + "/control_manager/mpc_tracker/predicted_trajectory";
      std::string diag_topic_name       = std::string("/") + _avoidance_other_uav_names_.at(i) + "/control_manager/mpc_tracker/diagnostics";

      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: subscribing to %s", prediction_topic_name.c_str());

      other_uav_trajectory_subscribers_.push_back(std::make_shared<mrs_lib::SubscriberHandler<mrs_msgs::msg::FutureTrajectory>>(
          shopts, prediction_topic_name, &MpcTracker::callbackOtherMavTrajectory, this));

      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: subscribing to %s", diag_topic_name.c_str());

      other_uav_diag_subscribers_.push_back(std::make_shared<mrs_lib::SubscriberHandler<mrs_msgs::msg::MpcTrackerDiagnostics>>(
          shopts, diag_topic_name, &MpcTracker::callbackOtherMavDiagnostics, this));
    }
  }

  sh_estimation_diag_ =
      mrs_lib::SubscriberHandler<mrs_msgs::msg::EstimationDiagnostics>(shopts, std::string("/") + _uav_name_ + "/estimation_manager/diagnostics");

  profiler = mrs_lib::Profiler(common_handlers->parent_node, "MpcTracker", _profiler_enabled_);

  // | ------------------------- timers ------------------------- |

  mrs_lib::TimerHandlerOptions timer_opts_start;

  timer_opts_start.node           = node_;
  timer_opts_start.autostart      = true;
  timer_opts_start.callback_group = cbkgrp_timers_;

  mrs_lib::TimerHandlerOptions timer_opts_no_start;

  timer_opts_no_start.node           = node_;
  timer_opts_no_start.autostart      = false;
  timer_opts_no_start.callback_group = cbkgrp_timers_;

  {
    std::function<void()> callback_fcn = std::bind(&MpcTracker::timerAvoidanceTrajectory, this);

    mrs_lib::TimerHandlerOptions opts;

    opts.node           = node_;
    opts.autostart      = collision_avoidance_enabled_ || collision_avoidance_enabled_passively_;
    opts.callback_group = cbkgrp_timers_;

    timer_avoidance_trajectory_ = std::make_shared<TimerType>(opts, rclcpp::Rate(_avoidance_trajectory_rate_, clock_), callback_fcn);
  }

  {
    std::function<void()> callback_fcn = std::bind(&MpcTracker::timerDiagnostics, this);

    timer_diagnostics_ = std::make_shared<TimerType>(timer_opts_start, rclcpp::Rate(_diagnostics_rate_, clock_), callback_fcn);
  }

  {
    std::function<void()> callback_fcn = std::bind(&MpcTracker::timerMPC, this);

    timer_mpc_iteration_ = std::make_shared<TimerType>(timer_opts_no_start, rclcpp::Rate(_mpc_asynchronous_rate_, clock_), callback_fcn);
  }

  {
    std::function<void()> callback_fcn = std::bind(&MpcTracker::timerVelocityTracking, this);

    // TODO parametrize timer rate
    timer_velocity_tracking_ = std::make_shared<TimerType>(timer_opts_no_start, rclcpp::Rate(30.0, clock_), callback_fcn);
  }

  {
    std::function<void()> callback_fcn = std::bind(&MpcTracker::timerHover, this);

    // TODO parametrize timer rate
    timer_hover_ = std::make_shared<TimerType>(timer_opts_no_start, rclcpp::Rate(10.0, clock_), callback_fcn);
  }

  // | ----------------------- finish init ---------------------- |

  is_initialized_ = true;

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: initialized");

  return true;
}

//}

/* destroy() //{ */

void MpcTracker::destroy(void) {

  timer_avoidance_trajectory_->stop();
  timer_diagnostics_->stop();
  timer_mpc_iteration_->stop();
  timer_velocity_tracking_->stop();
  timer_hover_->stop();
}

//}

/* //{ activate() */

std::tuple<bool, std::string> MpcTracker::activate(const std::optional<mrs_msgs::msg::TrackerCommand> &last_tracker_cmd) {

  std::stringstream ss;

  if (!got_constraints_) {

    ss << "can not activate, missing constraints";
    RCLCPP_ERROR_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_state_heading;

  try {
    uav_state_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    ss << "could not calculate the UAV heading";
    RCLCPP_ERROR_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
    return std::tuple(false, ss.str());
  }

  MatrixXd mpc_x         = MatrixXd::Zero(MPC_N_STATES, 1);
  MatrixXd mpc_x_heading = MatrixXd::Zero(MPC_HEADING_N_STATES, 1);

  if (last_tracker_cmd) {

    // set the initial condition from the last tracker's cmd

    if (last_tracker_cmd->use_position_horizontal) {
      mpc_x(0, 0) = last_tracker_cmd->position.x;
      mpc_x(4, 0) = last_tracker_cmd->position.y;
    } else {
      mpc_x(0, 0) = uav_state.pose.position.x;
      mpc_x(4, 0) = uav_state.pose.position.y;
    }

    if (last_tracker_cmd->use_position_vertical) {
      mpc_x(8, 0) = last_tracker_cmd->position.z;
    } else {
      mpc_x(8, 0) = uav_state.pose.position.z;
    }

    if (last_tracker_cmd->use_velocity_horizontal) {
      mpc_x(1, 0) = last_tracker_cmd->velocity.x;
      mpc_x(5, 0) = last_tracker_cmd->velocity.y;
    } else {
      mpc_x(1, 0) = uav_state.velocity.linear.x;
      mpc_x(5, 0) = uav_state.velocity.linear.y;
    }

    if (last_tracker_cmd->use_velocity_vertical) {
      mpc_x(9, 0) = last_tracker_cmd->velocity.z;
    } else {
      mpc_x(9, 0) = uav_state.velocity.linear.z;
    }

    if (last_tracker_cmd->use_acceleration) {
      mpc_x(2, 0)  = last_tracker_cmd->acceleration.x;
      mpc_x(6, 0)  = last_tracker_cmd->acceleration.y;
      mpc_x(10, 0) = last_tracker_cmd->acceleration.z;
    } else {
      mpc_x(2, 0)  = 0;
      mpc_x(6, 0)  = 0;
      mpc_x(10, 0) = 0;
    }

    // the jerks
    mpc_x(3, 0)  = 0;
    mpc_x(7, 0)  = 0;
    mpc_x(11, 0) = 0;

    if (last_tracker_cmd->use_heading) {
      mpc_x_heading(0, 0) = last_tracker_cmd->heading;
    } else if (last_tracker_cmd->use_orientation) {
      try {
        mpc_x_heading(0, 0) = mrs_lib::AttitudeConverter(last_tracker_cmd->orientation).getHeading();
      }
      catch (...) {
        mpc_x_heading(0, 0) = uav_state_heading;
      }
    } else {
      mpc_x_heading(0, 0) = uav_state_heading;
    }

    if (last_tracker_cmd->use_heading_rate) {
      mpc_x_heading(1, 0) = last_tracker_cmd->heading_rate;
    } else {
      mpc_x_heading(1, 0) = uav_state.velocity.angular.z;
    }

    mpc_x_heading(2, 0) = 0;
    mpc_x_heading(3, 0) = 0;

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: activated with last tracker's command");

  } else {

    // set the initial condition completely from the uav_state

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

    mpc_x_heading(0, 0) = uav_state_heading;
    mpc_x_heading(1, 0) = uav_state.velocity.angular.z;
    mpc_x_heading(2, 0) = 0;
    mpc_x_heading(3, 0) = 0;

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: activated with uav state");
  }

  {
    std::scoped_lock lock(mutex_mpc_x_);

    mpc_x_         = mpc_x;
    mpc_x_heading_ = mpc_x_heading;
  }

  trajectory_tracking_in_progress_ = false;

  ss << "activated";
  RCLCPP_INFO_STREAM(node_->get_logger(), "[MpcTracker]: " << ss.str());

  // this is here to initialize the desired_trajectory vector
  // if deleted (and I tried) the UAV will briefly fly to the
  // origin after activation
  setRelativeGoal(0, 0, 0, 0, false); // do not delete

  toggleHover(true);

  model_first_iteration_ = true;

  A_ = _mat_A_;
  B_ = _mat_B_;

  A_heading_ = _mat_A_heading_;
  B_heading_ = _mat_B_heading_;

  is_active_ = true;

  if (!mpc_synchronous_) {
    timer_mpc_iteration_->start();
  }

  return std::tuple(true, ss.str());
}

//}

/* //{ deactivate() */

void MpcTracker::deactivate(void) {

  toggleHover(false);

  is_active_                       = false;
  trajectory_tracking_in_progress_ = false;
  model_first_iteration_           = true;

  time_last_update_ = rclcpp::Time(0, 0, clock_->get_clock_type());

  {
    std::scoped_lock lock(mutex_trajectory_tracking_states_);

    trajectory_current_time_ = 0;
  }

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: deactivated");

  timer_mpc_iteration_->stop();

  publishDiagnostics();
}

//}

/* //{ resetStatic() */

bool MpcTracker::resetStatic(void) {

  if (!is_initialized_) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: can not reset, not initialized");
    return false;
  }

  if (!is_active_) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: can not reset, not active");
    return false;
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  double uav_state_heading;

  try {
    uav_state_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: could not calculate the UAV heading");
    return false;
  }

  {
    std::scoped_lock lock(mutex_mpc_x_);

    // set the initial condition from the odometry

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: reseting with uav state with no dynamics");

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

    mpc_x_heading_(0, 0) = uav_state_heading;
    mpc_x_heading_(1, 0) = 0;
    mpc_x_heading_(2, 0) = 0;
    mpc_x_heading_(3, 0) = 0;

    trajectory_tracking_in_progress_ = false;

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: reseted");
  }

  // this is here to initialize the desired_trajectory vector
  // if deleted (and I tried) the UAV will briefly fly to the
  // origin after activation
  setRelativeGoal(0, 0, 0, 0, false); // do not delete

  return true;
}

//}

/* //{ update() */

std::optional<mrs_msgs::msg::TrackerCommand> MpcTracker::update(const mrs_msgs::msg::UavState                                      &uav_state,
                                                                [[maybe_unused]] const mrs_uav_managers::Controller::ControlOutput &last_control_output) {

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("update");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer(node_, "MpcTracker::update", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  auto old_uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  // save the uav state
  mrs_lib::set_mutexed(mutex_uav_state_, uav_state, uav_state_);

  // the time from the last update call
  double dt = 0.01;

  if (time_last_update_.seconds() > 0) {
    dt = (clock_->now() - time_last_update_).seconds();
  }

  time_last_update_ = clock_->now();

  if (dt > 0) {

    double rate = 1.0 / dt;

    update_rate_ = 0.9 * update_rate_ + 0.1 * rate;

    if (mpc_synchronous_ && (update_rate_ > _mpc_synchronous_rate_limit_)) {
      mpc_synchronous_ = false;
      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: detecting high update date (%.1f Hz > %.1f Hz), switching to asynchronous mode.", rate,
                  _mpc_synchronous_rate_limit_);
      if (is_active_) {
        timer_mpc_iteration_->start();
      }
    } else if (!mpc_synchronous_ && (update_rate_ <= _mpc_synchronous_rate_limit_)) {
      mpc_synchronous_ = true;
      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: detecting low update rate (%.1f Hz < %.1f Hz), switching to synchronous mode.", rate,
                  _mpc_synchronous_rate_limit_);
      timer_mpc_iteration_->stop();
    }
  }

  // up to this part the update() method is evaluated even when the tracker is not active
  if (!is_active_) {
    return {};
  }

  mrs_msgs::msg::TrackerCommand tracker_cmd;

  if (!mpc_synchronous_ && (!mpc_computed_ || mpc_result_invalid_)) {

    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: MPC not ready, returning current odom as the command");

    // set the header
    tracker_cmd.header.stamp    = uav_state.header.stamp;
    tracker_cmd.header.frame_id = uav_state.header.frame_id;

    // set positions from odom
    tracker_cmd.position.x              = uav_state.pose.position.x;
    tracker_cmd.position.y              = uav_state.pose.position.y;
    tracker_cmd.position.z              = uav_state.pose.position.z;
    tracker_cmd.use_position_vertical   = 1;
    tracker_cmd.use_position_horizontal = 1;

    // set velocities from odom
    tracker_cmd.velocity.x              = uav_state.velocity.linear.x;
    tracker_cmd.velocity.y              = uav_state.velocity.linear.y;
    tracker_cmd.velocity.z              = uav_state.velocity.linear.z;
    tracker_cmd.use_velocity_vertical   = 1;
    tracker_cmd.use_velocity_horizontal = 1;

    // set zero accelerations
    tracker_cmd.acceleration.x   = 0;
    tracker_cmd.acceleration.y   = 0;
    tracker_cmd.acceleration.z   = 0;
    tracker_cmd.use_acceleration = 1;

    try {
      tracker_cmd.heading     = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
      tracker_cmd.use_heading = 1;
    }
    catch (...) {
      tracker_cmd.use_heading = 0;
      RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: could not calculate the current UAV heading");
    }

    // set zero jerk
    tracker_cmd.jerk.x = 0;
    tracker_cmd.jerk.y = 0;
    tracker_cmd.jerk.z = 0;

    try {
      tracker_cmd.heading_rate     = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeadingRate(uav_state.velocity.angular);
      tracker_cmd.use_heading_rate = 1;
    }
    catch (...) {
      tracker_cmd.use_heading_rate = 0;
      RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: could not calculate the current UAV heading rate");
    }

    return {tracker_cmd};
  }

  if (mpc_synchronous_) {

    RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: running in SYNCHRONOUS mode");

    timerMPC();

  } else {
    RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: running in ASYNCHRONOUS mode");
  }

  if (dt > 0) {
    iterateModel(dt);
  } else {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: dt !> 0, not iterating the model");
  }

  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);
  auto prediction_full_state  = mrs_lib::get_mutexed(mutex_prediction_full_state_, prediction_full_state_);

  // check whether all outputs are finite
  bool arefinite = true;
  for (int i = 0; i < 12; i++) {
    if (!std::isfinite(mpc_x(i, 0))) {
      arefinite = false;
    }
  }

  if (arefinite) {

    // set the desired states base on the result of the mpc
    tracker_cmd.position.x     = mpc_x(0, 0);
    tracker_cmd.velocity.x     = mpc_x(1, 0);
    tracker_cmd.acceleration.x = mpc_x(2, 0);
    tracker_cmd.jerk.x         = mpc_x(3, 0);

    tracker_cmd.position.y     = mpc_x(4, 0);
    tracker_cmd.velocity.y     = mpc_x(5, 0);
    tracker_cmd.acceleration.y = mpc_x(6, 0);
    tracker_cmd.jerk.y         = mpc_x(7, 0);

    tracker_cmd.position.z     = mpc_x(8, 0);
    tracker_cmd.velocity.z     = mpc_x(9, 0);
    tracker_cmd.acceleration.z = mpc_x(10, 0);
    tracker_cmd.jerk.z         = mpc_x(11, 0);

    tracker_cmd.full_state_prediction = prediction_full_state;

    tracker_cmd.use_position_vertical     = 1;
    tracker_cmd.use_position_horizontal   = 1;
    tracker_cmd.use_velocity_vertical     = 1;
    tracker_cmd.use_velocity_horizontal   = 1;
    tracker_cmd.use_acceleration          = 1;
    tracker_cmd.use_jerk                  = 1;
    tracker_cmd.use_full_state_prediction = 1;

  } else {

    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: MPC translation outputs are not finite!");

    return {};
  }

  bool heading_finite = true;
  for (int i = 0; i < MPC_HEADING_N_STATES; i++) {
    if (!std::isfinite(mpc_x_heading(i, 0))) {
      heading_finite = false;
    }
  }

  if (heading_finite) {

    tracker_cmd.heading              = mpc_x_heading(0, 0);
    tracker_cmd.heading_rate         = mpc_x_heading(1, 0);
    tracker_cmd.heading_acceleration = mpc_x_heading(2, 0);
    tracker_cmd.heading_jerk         = mpc_x_heading(3, 0);

    tracker_cmd.use_heading              = 1;
    tracker_cmd.use_heading_rate         = 1;
    tracker_cmd.use_heading_acceleration = 1;
    tracker_cmd.use_heading_jerk         = 1;

  } else {

    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: MPC heading output is not finite!");

    return {};
  }

  // set the header
  tracker_cmd.header.stamp    = uav_state.header.stamp;
  tracker_cmd.header.frame_id = uav_state.header.frame_id;

  // u have to return a position command
  // can set the jerk to 0
  return {tracker_cmd};
} // namespace mpc_tracker

//}

/* //{ getStatus() */

const mrs_msgs::msg::TrackerStatus MpcTracker::getStatus() {

  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);
  auto trajectory_size        = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_size_);

  double des_x, des_y, des_z, des_heading;
  {
    std::scoped_lock lock(mutex_des_trajectory_);

    des_x       = des_x_trajectory_(0);
    des_y       = des_y_trajectory_(0);
    des_z       = des_z_trajectory_(0);
    des_heading = des_heading_trajectory_(0);
  }

  mrs_msgs::msg::TrackerStatus tracker_status;

  tracker_status.active            = is_active_;
  tracker_status.callbacks_enabled = is_active_ && callbacks_enabled_ && !hovering_in_progress_;

  tracker_status.tracking_trajectory = trajectory_tracking_in_progress_;

  bool have_position_error   = sqrt(pow(mpc_x(0, 0) - des_x, 2) + pow(mpc_x(4, 0) - des_y, 2) + pow(mpc_x(8, 0) - des_z, 2)) > _diag_pos_tracking_thr_;
  bool have_heading_error    = fabs(radians::diff(mpc_x_heading(0), des_heading)) > _diag_heading_tracking_thr_;
  bool have_nonzero_velocity = fabs(mpc_x(1, 0)) > 0.1 || fabs(mpc_x(5, 0)) > 0.1 || fabs(mpc_x(9, 0)) > 0.1 || fabs(mpc_x_heading(1, 0)) > 0.1;

  tracker_status.have_goal = trajectory_tracking_in_progress_ || hovering_in_progress_ || have_position_error || have_heading_error || have_nonzero_velocity;

  if (!is_active_)
    tracker_status.state = mrs_msgs::msg::TrackerStatus::STATE_IDLE;
  else if (tracker_status.tracking_trajectory)
    tracker_status.state = mrs_msgs::msg::TrackerStatus::STATE_TRAJECTORY;
  else if (tracker_status.have_goal)
    tracker_status.state = mrs_msgs::msg::TrackerStatus::STATE_REFERENCE;
  else
    tracker_status.state = mrs_msgs::msg::TrackerStatus::STATE_HOVER;


  int trajectory_tracking_idx = getCurrentTrajectoryIdx();

  tracker_status.trajectory_length = trajectory_size;
  tracker_status.trajectory_idx    = trajectory_tracking_idx;

  if (trajectory_tracking_in_progress_) {

    auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

    std::scoped_lock lock(mutex_des_whole_trajectory_);

    tracker_status.trajectory_reference.header.stamp    = clock_->now();
    tracker_status.trajectory_reference.header.frame_id = uav_state.header.frame_id;

    tracker_status.trajectory_reference.reference.position.x = (*des_x_whole_trajectory_)(trajectory_tracking_idx);
    tracker_status.trajectory_reference.reference.position.y = (*des_y_whole_trajectory_)(trajectory_tracking_idx);
    tracker_status.trajectory_reference.reference.position.z = (*des_z_whole_trajectory_)(trajectory_tracking_idx);
    tracker_status.trajectory_reference.reference.heading    = (*des_heading_whole_trajectory_)(trajectory_tracking_idx);
  }

  return tracker_status;
}

//}

/* //{ enableCallbacks() */

const std::shared_ptr<std_srvs::srv::SetBool::Response> MpcTracker::enableCallbacks(const std::shared_ptr<std_srvs::srv::SetBool::Request> &request) {

  std::shared_ptr<std_srvs::srv::SetBool::Response> response = std::make_shared<std_srvs::srv::SetBool::Response>();

  std::stringstream ss;

  if (request->data != callbacks_enabled_) {

    callbacks_enabled_ = request->data;

    ss << "callbacks " << (callbacks_enabled_ ? "enabled" : "disabled");
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

  } else {

    ss << "callbacks were already " << (callbacks_enabled_ ? "enabled" : "disabled");
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
  }

  response->message = ss.str();
  response->success = true;

  return response;
}

//}

/* switchOdometrySource() //{ */

const std::shared_ptr<std_srvs::srv::Trigger::Response> MpcTracker::switchOdometrySource([[maybe_unused]] const mrs_msgs::msg::UavState &new_uav_state) {

  odometry_reset_in_progress_ = true;
  mpc_result_invalid_         = true;

  auto x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  RCLCPP_INFO(
      node_->get_logger(),
      "[MpcTracker]: start of odometry reset, curent state [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: "
      "%.2f], "
      "new odom [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: %.2f]",
      x(0, 0), x(4, 0), x(8, 0), x(1, 0), x(5, 0), x(9, 0), x(2, 0), x(6, 0), x(10, 0), new_uav_state.pose.position.x, new_uav_state.pose.position.y,
      new_uav_state.pose.position.z, new_uav_state.velocity.linear.x, new_uav_state.velocity.linear.y, new_uav_state.velocity.linear.z,
      new_uav_state.acceleration.linear.x, new_uav_state.acceleration.linear.y, new_uav_state.acceleration.linear.z);

  timer_mpc_iteration_->stop();
  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: mpc timer stopped");

  while (mpc_timer_running_) {

    RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: the mpc is in the middle of an iteration, waiting for it to finish");

    clock_->sleep_for(1ms);

    if (!mpc_timer_running_) {
      RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: mpc timer finished");
      break;
    }
  }

  // | --------- recalculate the goal to new coordinates -------- |

  double old_heading  = 0;
  double new_heading  = 0;
  bool   got_headings = true;

  try {
    old_heading = mrs_lib::AttitudeConverter(uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: could not calculate the old UAV heading");
    got_headings = false;
  }

  try {
    new_heading = mrs_lib::AttitudeConverter(new_uav_state.pose.orientation).getHeading();
  }
  catch (...) {
    RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: could not calculate the new UAV heading");
    got_headings = false;
  }

  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  if (!got_headings) {
    response->message = "could not calculate the heading difference";
    response->success = false;

    return response;
  }

  // calculate the difference of position
  double dx       = new_uav_state.pose.position.x - uav_state_.pose.position.x;
  double dy       = new_uav_state.pose.position.y - uav_state_.pose.position.y;
  double dz       = new_uav_state.pose.position.z - uav_state_.pose.position.z;
  double dheading = new_heading - old_heading;

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: dx %f dy %f dz %f dheading %f", dx, dy, dz, dheading);

  {
    std::scoped_lock lock(mutex_mpc_x_, mutex_des_trajectory_, mutex_des_whole_trajectory_, mutex_uav_state_);

    if (trajectory_set_) {

      for (int i = 0; i < trajectory_size_ + MPC_HORIZON_LENGTH; i++) {

        Eigen::Vector2d temp_vec((*des_x_whole_trajectory_)(i)-uav_state_.pose.position.x, (*des_y_whole_trajectory_)(i)-uav_state_.pose.position.y);
        temp_vec = Eigen::Rotation2D<double>(dheading).toRotationMatrix() * temp_vec;

        (*des_x_whole_trajectory_)(i) = new_uav_state.pose.position.x + temp_vec(0);
        (*des_y_whole_trajectory_)(i) = new_uav_state.pose.position.y + temp_vec(1);
        (*des_z_whole_trajectory_)(i) += dz;
        (*des_heading_whole_trajectory_)(i) += dheading;
      }
    }

    for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

      Eigen::Vector2d temp_vec(des_x_trajectory_(i) - uav_state_.pose.position.x, des_y_trajectory_(i) - uav_state_.pose.position.y);
      temp_vec = Eigen::Rotation2D<double>(dheading).toRotationMatrix() * temp_vec;

      des_x_trajectory_(i, 0) = new_uav_state.pose.position.x + temp_vec(0);
      des_y_trajectory_(i, 0) = new_uav_state.pose.position.y + temp_vec(1);
      des_z_trajectory_(i, 0) += dz;
      des_heading_trajectory_(i, 0) += dheading;
    }

    // update the position
    {
      Eigen::Vector2d temp_vec(mpc_x_(0, 0) - uav_state_.pose.position.x, mpc_x_(4, 0) - uav_state_.pose.position.y);
      temp_vec     = Eigen::Rotation2D<double>(dheading).toRotationMatrix() * temp_vec;
      mpc_x_(0, 0) = new_uav_state.pose.position.x + temp_vec(0);
      mpc_x_(4, 0) = new_uav_state.pose.position.y + temp_vec(1);
      mpc_x_(8, 0) += dz;
    }

    // update the velocity
    {
      mpc_x_(1, 0) = new_uav_state.velocity.linear.x;
      mpc_x_(5, 0) = new_uav_state.velocity.linear.y;
      // we leave the z velocity as it was in the original frame
    }

    // update the acceleration
    {
      mpc_x_(2, 0)  = 0;
      mpc_x_(6, 0)  = 0;
      mpc_x_(10, 0) = 0;
    }

    // update the heading and its derivative
    mpc_x_heading_(0, 0) += dheading;
    mpc_x_heading_(1, 0) = new_uav_state.velocity.angular.x;
  }

  RCLCPP_INFO(
      node_->get_logger(),
      "[MpcTracker]: start of odometry reset, curent state [x: %.2f, y: %.2f, z: %.2f] [x_d: %.2f, y_d: %.2f, z_d: %.2f] [x_dd: %.2f, y_dd: %.2f, z_dd: "
      "%.2f]",
      x(0, 0), x(4, 0), x(8, 0), x(1, 0), x(5, 0), x(9, 0), x(2, 0), x(6, 0), x(10, 0));

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: starting the MPC timer");

  if (!mpc_synchronous_) {
    timer_mpc_iteration_->start();
  }

  odometry_reset_in_progress_ = false;

  return response;
}

//}

/* //{ hover() */

const std::shared_ptr<std_srvs::srv::Trigger::Response> MpcTracker::hover([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  toggleHover(true);

  std::stringstream ss;
  ss << "initiating hover";

  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  response->success = true;
  response->message = ss.str();

  return response;
}

//}

/* //{ startTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MpcTracker::startTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  std::stringstream ss;

  auto [success, message] = startTrajectoryTrackingImpl();

  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  response->success = success;
  response->message = message;

  return response;
}

//}

/* //{ stopTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MpcTracker::stopTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  auto [success, message] = stopTrajectoryTrackingImpl();

  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  response->success = success;
  response->message = message;

  return response;
}

//}

/* //{ resumeTrajectoryTracking() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MpcTracker::resumeTrajectoryTracking([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  auto [success, message] = resumeTrajectoryTrackingImpl();


  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  response->success = success;
  response->message = message;

  return response;
}

//}

/* //{ gotoTrajectoryStart() */

const std::shared_ptr<std_srvs::srv::Trigger::Response>
MpcTracker::gotoTrajectoryStart([[maybe_unused]] const std::shared_ptr<std_srvs::srv::Trigger::Request> &request) {

  auto [success, message] = gotoTrajectoryStartImpl();

  std::shared_ptr<std_srvs::srv::Trigger::Response> response = std::make_shared<std_srvs::srv::Trigger::Response>();

  response->success = success;
  response->message = message;

  return response;
}

//}

/* //{ setConstraints() */

const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response>
MpcTracker::setConstraints([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Request> &request) {

  if (!is_initialized_) {
    return nullptr;
  }

  mrs_lib::set_mutexed(mutex_constraints_, request->constraints, constraints_);

  // directly updated the speeds in the constraints
  // the reset needs to wait for manageConstraints()
  {
    std::scoped_lock lock(mutex_constraints_filtered_);

    // important! this needs to be done to initialize the full struct
    if (!got_constraints_) {

      constraints_filtered_ = request->constraints;

    } else {

      constraints_filtered_.horizontal_speed          = request->constraints.horizontal_speed;
      constraints_filtered_.vertical_ascending_speed  = request->constraints.vertical_ascending_speed;
      constraints_filtered_.vertical_descending_speed = request->constraints.vertical_descending_speed;
      constraints_filtered_.heading_speed             = request->constraints.heading_speed;
    }
  }

  got_constraints_ = true;

  all_constraints_set_ = false;

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: updating constraints");

  std::shared_ptr<mrs_msgs::srv::DynamicsConstraintsSrv::Response> response = std::make_shared<mrs_msgs::srv::DynamicsConstraintsSrv::Response>();

  response->success = true;
  response->message = "constraints updated";

  return response;
}

//}

/* //{ setReference() */

const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response>
MpcTracker::setReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Request> &request) {

  toggleHover(false);

  setGoal(request->reference.position.x, request->reference.position.y, request->reference.position.z, request->reference.heading, true);

  std::shared_ptr<mrs_msgs::srv::ReferenceSrv::Response> response = std::make_shared<mrs_msgs::srv::ReferenceSrv::Response>();

  response->success = true;
  response->message = "reference set";

  return response;
}

//}

/* //{ setVelocityReference() */

const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response>
MpcTracker::setVelocityReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Request> &request) {

  if (!is_initialized_) {
    return nullptr;
  }

  {
    std::scoped_lock lock(mutex_velocity_reference_);

    velocity_reference_time_ = clock_->now();

    velocity_reference_ = request->reference;
  }

  if (!velocity_tracking_active_) {

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: starting velocity tracking timer");

    timer_velocity_tracking_->stop();
    timer_velocity_tracking_->start();

    velocity_tracking_active_ = true;
  }

  std::shared_ptr<mrs_msgs::srv::VelocityReferenceSrv::Response> response = std::make_shared<mrs_msgs::srv::VelocityReferenceSrv::Response>();

  response->success = true;
  response->message = "reference set";

  return response;
}

//}

/* //{ setTrajectoryReference() */

const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response>
MpcTracker::setTrajectoryReference([[maybe_unused]] const std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Request> &request) {

  std::stringstream ss;

  auto [success, message, modified] = loadTrajectory(request->trajectory);

  std::shared_ptr<mrs_msgs::srv::TrajectoryReferenceSrv::Response> response = std::make_shared<mrs_msgs::srv::TrajectoryReferenceSrv::Response>();

  response->success  = success;
  response->message  = message;
  response->modified = modified;

  return response;
}

//}

// | ------------------------ callbacks ----------------------- |

/* //{ callbackOtherMavTrajectory() */

void MpcTracker::callbackOtherMavTrajectory(const mrs_msgs::msg::FutureTrajectory::ConstSharedPtr msg) {

  if (!is_initialized_) {
    return;
  }

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("callbackOtherMavTrajectory");
  mrs_lib::ScopeTimer timer =
      mrs_lib::ScopeTimer(node_, "MpcTracker::callbackOtherMavTrajectory", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  mrs_msgs::msg::FutureTrajectory trajectory = *msg;

  // the times might not be synchronized, so just remember the time of receiving it
  trajectory.stamp = clock_->now();

  // transform it from the utm origin to the currently used frame
  auto res = common_handlers_->transformer->getTransform("utm_origin", uav_state.header.frame_id, clock_->now());

  if (!res) {

    std::string message = "[MpcTracker]: can not transform other drone trajectory to the current frame";
    RCLCPP_WARN_STREAM_ONCE(node_->get_logger(), message);
    RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, message);

    return;
  }

  geometry_msgs::msg::TransformStamped tf = res.value();

  for (int i = 0; i < int(trajectory.points.size()); i++) {

    geometry_msgs::msg::PoseStamped original_pose;

    original_pose.pose.position.x = trajectory.points.at(i).x;
    original_pose.pose.position.y = trajectory.points.at(i).y;
    original_pose.pose.position.z = trajectory.points.at(i).z;

    original_pose.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    auto res = common_handlers_->transformer->transform(original_pose, tf);

    if (res) {
      trajectory.points.at(i).x = res.value().pose.position.x;
      trajectory.points.at(i).y = res.value().pose.position.y;
      trajectory.points.at(i).z = res.value().pose.position.z;
    } else {

      std::string message = "[MpcTracker]: could not transform point of other uav future trajectory!";
      RCLCPP_WARN_STREAM_ONCE(node_->get_logger(), message);
      RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, message);

      return;
    }
  }

  {
    std::scoped_lock lock(mutex_other_uav_avoidance_trajectories_);

    // update the diagnostics
    other_uav_avoidance_trajectories_[trajectory.uav_name] = trajectory;
  }
}

//}

/* //{ callbackOtherMavDiagnostics() */

void MpcTracker::callbackOtherMavDiagnostics(const mrs_msgs::msg::MpcTrackerDiagnostics::ConstSharedPtr msg) {

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("callbackOtherMavDiagnostics");
  mrs_lib::ScopeTimer timer =
      mrs_lib::ScopeTimer(node_, "MpcTracker::callbackOtherMavDiagnostics", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  mrs_msgs::msg::MpcTrackerDiagnostics diagnostics = *msg;

  // fill in the current time
  // the other uav's time might not be synchronized with ours
  diagnostics.header.stamp = clock_->now();

  {
    std::scoped_lock lock(mutex_other_uav_diagnostics_);

    other_uav_diagnostics_[diagnostics.uav_name] = diagnostics;
  }
}

//}

/* //{ callbackToggleCollisionAvoidance() */

bool MpcTracker::callbackToggleCollisionAvoidance(const std::shared_ptr<std_srvs::srv::SetBool::Request>  request,
                                                  const std::shared_ptr<std_srvs::srv::SetBool::Response> response) {

  collision_avoidance_enabled_ = request->data;

  RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: Collision avoidance was switched %s", collision_avoidance_enabled_ ? "TRUE" : "FALSE");

  response->message = "Collision avoidance set.";
  response->success = true;

  return true;
}

//}

/* callbackWiggle() //{ */

bool MpcTracker::callbackWiggle(const std::shared_ptr<std_srvs::srv::SetBool::Request>  request,
                                const std::shared_ptr<std_srvs::srv::SetBool::Response> response) {

  if (!is_initialized_) {

    response->success = false;
    response->message = "tracker not active";
    return true;
  }

  mrs_lib::set_mutexed(mutex_drs_params_, drs_params_.wiggle_enabled, request->data);

  dynparam_mgr_->update_to_ros();

  response->success = true;
  response->message = "wiggle updated";

  return true;
}

//}

// --------------------------------------------------------------
// |                          routines                          |
// --------------------------------------------------------------

// | --------------- mutual collision avoidance --------------- |

/* //{ checkCollision() */

bool MpcTracker::checkCollision(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (mrs_lib::geometry::dist(vec2_t(ax, ay), vec2_t(bx, by)) < _avoidance_radius_threshold_ && fabs(az - bz) < _avoidance_z_threshold_) {

    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkCollisionInflated() */

bool MpcTracker::checkCollisionInflated(const double ax, const double ay, const double az, const double bx, const double by, const double bz) {

  if (mrs_lib::geometry::dist(vec2_t(ax, ay), vec2_t(bx, by)) < _avoidance_radius_threshold_ + 1.0 && fabs(az - bz) < _avoidance_z_threshold_ + 1.0) {

    return true;

  } else {

    return false;
  }
}

//}

/* //{ checkTrajectoryForCollisions() */

// Check for potential collisions and return the needed altitude offset to avoid other drones
double MpcTracker::checkTrajectoryForCollisions(int &first_collision_index) {

  std::scoped_lock lock(mutex_predicted_trajectory_, mutex_des_trajectory_, mutex_other_uav_avoidance_trajectories_);

  first_collision_index = INT_MAX;
  avoiding_collision_   = false;

  std::map<std::string, mrs_msgs::msg::FutureTrajectory>::iterator u = other_uav_avoidance_trajectories_.begin();

  while (u != other_uav_avoidance_trajectories_.end()) {

    // is the other's trajectory fresh enought?
    if ((clock_->now() - u->second.stamp).seconds() < _collision_trajectory_timeout_) {

      for (int v = 0; v < MPC_HORIZON_LENGTH; v++) {

        // check all points of the trajectory for possible collisions
        if (checkCollision(predicted_trajectory_(v * MPC_N_STATES, 0), predicted_trajectory_(v * MPC_N_STATES + 4, 0),
                           predicted_trajectory_(v * MPC_N_STATES + 8, 0), u->second.points.at(v).x, u->second.points.at(v).y, u->second.points.at(v).z)) {

          // collision is detected
          int other_uav_priority = INT_MAX;
          // get the priority of the other uav
          /* sscanf(u->first.c_str(), "uav%d", &other_uav_priority); */
          other_uav_priority = u->second.priority;

          // check if we should be avoiding (out priority is higher, or the other uav has collision avoidance turned off)
          if ((u->second.collision_avoidance == false) || (other_uav_priority < avoidance_this_uav_priority_)) {

            // we should be avoiding
            avoiding_collision_      = true;
            double tmp_safe_altitude = u->second.points.at(v).z + _avoidance_z_correction_;

            if (tmp_safe_altitude > collision_free_altitude_ && v <= _avoidance_collision_start_climbing_) {
              collision_free_altitude_ = tmp_safe_altitude;
            }

            RCLCPP_ERROR_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: avoiding collision with uav" << other_uav_priority);

          } else {
            // the other uav should avoid us
            RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000,
                                        "[MpcTracker]: detected collision with uav" << other_uav_priority << ", not avoiding (my priority is higher)");
          }
        }

        if (checkCollisionInflated(predicted_trajectory_(v * MPC_N_STATES, 0), predicted_trajectory_(v * MPC_N_STATES + 4, 0),
                                   predicted_trajectory_(v * MPC_N_STATES + 8, 0), u->second.points.at(v).x, u->second.points.at(v).y,
                                   u->second.points.at(v).z)) {

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

    auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

    // we are not avoiding any collisions, so we slowly reduce the collision avoidance offset to return to normal flight
    collision_free_altitude_ -= 2.0 / (1.0 / dt1);

    double safety_area_min_z = std::numeric_limits<double>::lowest();

    if (collision_free_altitude_ < safety_area_min_z) {

      collision_free_altitude_ = safety_area_min_z;
    }
  }

  return collision_free_altitude_;
}

//}

// | ------------------ trajectory filtering ------------------ |

/* //{ filterReferenceXY() */

std::tuple<MatrixXd, MatrixXd> MpcTracker::filterReferenceXY(const VectorXd &des_x_trajectory, const VectorXd &des_y_trajectory, double max_speed_x,
                                                             double max_speed_y) {

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  auto [wiggle_enabled, wiggle_amplitude, wiggle_frequency_] =
      mrs_lib::get_mutexed(mutex_drs_params_, drs_params_.wiggle_enabled, drs_params_.wiggle_amplitude, drs_params_.wiggle_frequency);

  auto mpc_x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto trajectory_dt = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_dt_);

  MatrixXd filtered_x_trajectory = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);
  MatrixXd filtered_y_trajectory = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);

  double difference_x;
  double difference_y;
  double max_sample_x;
  double max_sample_y;

  if (!wiggle_enabled && std::hypot(mpc_x(0, 0) - des_x_trajectory(0, 0), mpc_x(4, 0) - des_y_trajectory(0, 0)) < 2.0) {
    return {des_x_trajectory, des_y_trajectory};
  }

  for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

    if (i == 0) {
      max_sample_x = max_speed_x * dt1;
      max_sample_y = max_speed_y * dt1;
      difference_x = des_x_trajectory(i, 0) - mpc_x(0, 0);
      difference_y = des_y_trajectory(i, 0) - mpc_x(4, 0);
    } else {
      max_sample_x = max_speed_x * _dt2_;
      max_sample_y = max_speed_y * _dt2_;
      difference_x = des_x_trajectory(i, 0) - filtered_x_trajectory(i - 1, 0);
      difference_y = des_y_trajectory(i, 0) - filtered_y_trajectory(i - 1, 0);
    }

    if (!trajectory_tracking_in_progress_) {

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
    }

    if (i == 0) {
      filtered_x_trajectory(i, 0) = mpc_x(0, 0) + difference_x;
      filtered_y_trajectory(i, 0) = mpc_x(4, 0) + difference_y;
    } else {
      filtered_x_trajectory(i, 0) = filtered_x_trajectory(i - 1, 0) + difference_x;
      filtered_y_trajectory(i, 0) = filtered_y_trajectory(i - 1, 0) + difference_y;
    }
  }

  // | ----------------------- add wiggle ----------------------- |

  if (wiggle_enabled) {

    RCLCPP_INFO_THROTTLE(node_->get_logger(), *clock_, 1000, "wiggle enabled");

    for (int i = 1; i < MPC_HORIZON_LENGTH; i++) {
      filtered_x_trajectory(i, 0) += wiggle_amplitude * cos(wiggle_frequency_ * 2 * M_PI * i * trajectory_dt + wiggle_phase_);
      filtered_y_trajectory(i, 0) += wiggle_amplitude * sin(wiggle_frequency_ * 2 * M_PI * i * trajectory_dt + wiggle_phase_);
    }

    wiggle_phase_ += wiggle_frequency_ * dt1 * 2 * M_PI;

    if (wiggle_phase_ > M_PI) {
      wiggle_phase_ -= 2 * M_PI;
    }
  }

  return std::make_tuple(filtered_x_trajectory, filtered_y_trajectory);
}

//}

/* //{ filterReferenceZ() */

MatrixXd MpcTracker::filterReferenceZ(const VectorXd &des_z_trajectory, const double max_ascending_speed, const double max_descending_speed) {

  auto mpc_x = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  double difference_z;
  double max_sample_z;

  MatrixXd filtered_trajectory = MatrixXd::Zero(MPC_HORIZON_LENGTH, 1);

  double current_z = mpc_x(8, 0);

  for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

    if (i == 0) {

      difference_z = des_z_trajectory(i, 0) - current_z;

      if (difference_z > 0) {
        max_sample_z = max_ascending_speed * dt1;
      } else {
        max_sample_z = max_descending_speed * dt1;
      }

    } else {

      difference_z = des_z_trajectory(i, 0) - filtered_trajectory(i - 1, 0);

      if (difference_z > 0) {
        max_sample_z = max_ascending_speed * _dt2_;
      } else {
        max_sample_z = max_descending_speed * _dt2_;
      }
    }

    if (!trajectory_tracking_in_progress_) {

      // saturate the difference
      if (difference_z > max_sample_z)
        difference_z = max_sample_z;
      else if (difference_z < -max_sample_z)
        difference_z = -max_sample_z;
    }

    if (i == 0) {
      filtered_trajectory(i, 0) = current_z + difference_z;
    } else {
      filtered_trajectory(i, 0) = filtered_trajectory(i - 1, 0) + difference_z;
    }
  }

  return filtered_trajectory;
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

  auto constraints            = mrs_lib::get_mutexed(mutex_constraints_, constraints_);
  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);

  bool can_change = (fabs(mpc_x(1, 0)) < constraints.horizontal_speed) && (fabs(mpc_x(2, 0)) < constraints.horizontal_acceleration) &&
                    (fabs(mpc_x(3, 0)) < constraints.horizontal_jerk) && (fabs(mpc_x(5, 0)) < constraints.horizontal_speed) &&
                    (fabs(mpc_x(6, 0)) < constraints.horizontal_acceleration) && (fabs(mpc_x(7, 0)) < constraints.horizontal_jerk) &&
                    (mpc_x(9, 0) < constraints.vertical_ascending_speed) && (mpc_x(9, 0) > -constraints.vertical_descending_speed) &&
                    (mpc_x(10, 0) < constraints.vertical_ascending_acceleration) && (mpc_x(10, 0) > -constraints.vertical_descending_acceleration) &&
                    (mpc_x(11, 0) < constraints.vertical_ascending_jerk) && (mpc_x(11, 0) > -constraints.vertical_descending_jerk) &&
                    (fabs(mpc_x_heading(1, 0)) < constraints.heading_speed) && (fabs(mpc_x_heading(2, 0)) < constraints.heading_acceleration) &&
                    (fabs(mpc_x_heading(3, 0)) < constraints.heading_jerk);

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

      constraints_filtered_.heading_acceleration = constraints.heading_acceleration;
      constraints_filtered_.heading_jerk         = constraints.heading_jerk;
      constraints_filtered_.heading_snap         = constraints.heading_snap;
    }

    RCLCPP_INFO_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: all constraints succesfully applied");
    all_constraints_set_ = true;

  } else {
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: slowing down to apply new constraints");
  }
}

//}

/* //{ calculateMPC() */

void MpcTracker::calculateMPC() {

  std::scoped_lock lock(mutex_mpc_calculation_);

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: MPC calculation dt = " << dt1);

  auto constraints            = mrs_lib::get_mutexed(mutex_constraints_filtered_, constraints_filtered_);
  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);
  auto uav_state              = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto drs_params             = mrs_lib::get_mutexed(mutex_drs_params_, drs_params_);

  MatrixXd des_x_trajectory, des_y_trajectory, des_z_trajectory, des_heading_trajectory;
  {
    std::scoped_lock lock(mutex_des_trajectory_);

    des_x_trajectory       = des_x_trajectory_;
    des_y_trajectory       = des_y_trajectory_;
    des_z_trajectory       = des_z_trajectory_;
    des_heading_trajectory = des_heading_trajectory_;
  }

  int    first_collision_index = INT_MAX;
  double lowest_z              = std::numeric_limits<double>::max();

  if (collision_avoidance_enabled_ && (uav_state.estimator_horizontal == "lat_gps" || uav_state.estimator_horizontal == "lat_rtk")) {

    // determine the lowest point in our trajectory
    for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {
      if (des_z_trajectory_(i, 0) < lowest_z) {
        lowest_z = des_z_trajectory_(i, 0);
      }
    }

    // check other drone trajectories for collisions
    minimum_collison_free_altitude_ = checkTrajectoryForCollisions(first_collision_index);

  } else {

    minimum_collison_free_altitude_ = std::numeric_limits<double>::lowest();
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

  collision_avoidance_affecting_me_ = false;

  if (first_collision_index < MPC_HORIZON_LENGTH) {

    collision_avoidance_affecting_me_ = true;
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
      RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: NaN detected in variable 'tmp', setting it to 1.0 and returning!!!");
      return;
    } else if (tmp > 1.0) {
      tmp = 1.0;
    } else if (tmp < 0.0) {
      tmp = 0.0;
    }

    if (tmp > coef_scaler) {
      coef_scaler = tmp;
      coef_time   = clock_->now();
    }
    if ((clock_->now() - coef_time).seconds() > 2.0) {
      coef_scaler = tmp;
    }

    // we are close to a possible collision, better slow down a bit to give everyone more time
    max_speed_x = constraints.horizontal_speed * ((_avoidance_collision_horizontal_speed_coef_ * coef_scaler) + (1.0 - coef_scaler));
    max_speed_y = constraints.horizontal_speed * ((_avoidance_collision_horizontal_speed_coef_ * coef_scaler) + (1.0 - coef_scaler));
  }

  if (collision_free_altitude_ > lowest_z) {

    collision_avoidance_affecting_me_ = true;
    max_speed_x                       = constraints.horizontal_speed * (_avoidance_collision_horizontal_speed_coef_);
    max_speed_y                       = constraints.horizontal_speed * (_avoidance_collision_horizontal_speed_coef_);
  }

  // first control input generated by MPC
  VectorXd mpc_u         = VectorXd::Zero(MPC_N_INPUTS);
  double   mpc_u_heading = 0;

  double iters_z       = 0;
  double iters_x       = 0;
  double iters_y       = 0;
  double iters_heading = 0;

  rclcpp::Time time_begin = clock_->now();

  MatrixXd des_z_filtered = filterReferenceZ(des_z_trajectory, max_speed_z, min_speed_z);

  for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {
    if (des_z_filtered(i, 0) < minimum_collison_free_altitude_) {
      des_z_filtered_offset_(i, 0) = minimum_collison_free_altitude_;
    } else {
      des_z_filtered_offset_(i, 0) = des_z_filtered(i, 0);
    }
  }

  // | ----------------- prepare the references ----------------- |

  // | -------------------- MPC solver z-axis ------------------- |

  if (brake_ && !trajectory_tracking_in_progress_) {
    mpc_solver_z_->setVelQ(drs_params.q_vel_braking);
  } else {
    mpc_solver_z_->setVelQ(drs_params.q_vel_no_braking);
  }

  MatrixXd initial_z = MatrixXd::Zero(4, 1);

  initial_z(0, 0) = mpc_x(8, 0);
  initial_z(1, 0) = mpc_x(9, 0);
  initial_z(2, 0) = mpc_x(10, 0);
  initial_z(3, 0) = mpc_x(11, 0);

  mpc_solver_z_->setDt(dt1);
  mpc_solver_z_->setInitialState(initial_z);
  mpc_solver_z_->loadReference(des_z_filtered_offset_);
  mpc_solver_z_->setLimits(max_speed_z, min_speed_z, max_acc_z, min_acc_z, max_jerk_z, min_jerk_z, max_snap_z, min_snap_z);
  iters_z += mpc_solver_z_->solveMPC();

  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    mpc_solver_z_->getStates(predicted_trajectory_);
  }

  mpc_u(2) = mpc_solver_z_->getFirstControlInput();

  // if we are climbing to avoid a collision, reduce or arrest our horizontal velocity
  double ascend;
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    ascend = (predicted_trajectory_(10, 0) / max_speed_z);
  }

  if (ascend > 0 && collision_free_altitude_ > lowest_z) {
    max_speed_y = max_speed_y * (1.0 - ascend);
    max_speed_x = max_speed_x * (1.0 - ascend);
  }

  auto [des_x_filtered, des_y_filtered] = filterReferenceXY(des_x_trajectory, des_y_trajectory, max_speed_x, max_speed_y);

  // | -------------------- MPC solver x-axis ------------------- |

  if (brake_ && !trajectory_tracking_in_progress_) {
    mpc_solver_x_->setVelQ(drs_params.q_vel_braking);
  } else {
    mpc_solver_x_->setVelQ(drs_params.q_vel_no_braking);
  }

  MatrixXd initial_x = MatrixXd::Zero(4, 1);

  initial_x(0, 0) = mpc_x(0, 0);
  initial_x(1, 0) = mpc_x(1, 0);
  initial_x(2, 0) = mpc_x(2, 0);
  initial_x(3, 0) = mpc_x(3, 0);

  mpc_solver_x_->setDt(dt1);
  mpc_solver_x_->setInitialState(initial_x);
  mpc_solver_x_->loadReference(des_x_filtered);

  mpc_solver_x_->setLimits(max_speed_x, max_speed_x, max_acc_x, max_acc_x, max_jerk_x, max_jerk_x, max_snap_x, max_snap_x);
  iters_x += mpc_solver_x_->solveMPC();

  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    mpc_solver_x_->getStates(predicted_trajectory_);
  }

  mpc_u(0) = mpc_solver_x_->getFirstControlInput();

  // | -------------------- MPC solver y-axis ------------------- |

  if (brake_ && !trajectory_tracking_in_progress_) {
    mpc_solver_y_->setVelQ(drs_params.q_vel_braking);
  } else {
    mpc_solver_y_->setVelQ(drs_params.q_vel_no_braking);
  }

  MatrixXd initial_y = MatrixXd::Zero(4, 1);

  initial_y(0, 0) = mpc_x(4, 0);
  initial_y(1, 0) = mpc_x(5, 0);
  initial_y(2, 0) = mpc_x(6, 0);
  initial_y(3, 0) = mpc_x(7, 0);

  mpc_solver_y_->setDt(dt1);
  mpc_solver_y_->setInitialState(initial_y);
  mpc_solver_y_->loadReference(des_y_filtered);
  mpc_solver_y_->setLimits(max_speed_y, max_speed_y, max_acc_y, max_acc_y, max_jerk_y, max_jerk_y, max_snap_y, max_snap_y);
  iters_y += mpc_solver_y_->solveMPC();
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    mpc_solver_y_->getStates(predicted_trajectory_);
  }
  mpc_u(1) = mpc_solver_y_->getFirstControlInput();

  // | ------------------- MPC solver heading ------------------- |

  // unwrap the heading reference

  des_heading_trajectory(0, 0) = sradians::unwrap(des_heading_trajectory(0, 0), mpc_x_heading(0));

  for (int i = 1; i < MPC_HORIZON_LENGTH; i++) {
    des_heading_trajectory(i, 0) = sradians::unwrap(des_heading_trajectory(i, 0), des_heading_trajectory(i - 1, 0));
  }

  if (brake_ && !trajectory_tracking_in_progress_) {
    mpc_solver_heading_->setVelQ(drs_params.q_vel_braking);
  } else {
    mpc_solver_heading_->setVelQ(drs_params.q_vel_no_braking);
  }

  mpc_solver_heading_->setDt(dt1);
  mpc_solver_heading_->setInitialState(mpc_x_heading);
  mpc_solver_heading_->loadReference(des_heading_trajectory);
  mpc_solver_heading_->setLimits(constraints.heading_speed, constraints.heading_speed, constraints.heading_acceleration, constraints.heading_acceleration,
                                 constraints.heading_jerk, constraints.heading_jerk, constraints.heading_snap, constraints.heading_snap);
  iters_heading += mpc_solver_heading_->solveMPC();
  {
    std::scoped_lock lock(mutex_predicted_trajectory_);

    mpc_solver_heading_->getStates(predicted_heading_trajectory_);
  }
  mpc_u_heading = mpc_solver_heading_->getFirstControlInput();

  {
    geometry_msgs::msg::PoseStamped point;
    point.header.stamp    = clock_->now();
    point.header.frame_id = uav_state_.header.frame_id;

    point.pose.position.x = des_x_filtered(0, 0);
    point.pose.position.y = des_y_filtered(0, 0);
    point.pose.position.z = des_z_filtered(0, 0);

    point.pose.orientation = mrs_lib::AttitudeConverter(0, 0, des_heading_trajectory(0, 0));

    ph_first_reference_point_.publish(point);
  }

  {
    bool saturating = false;

    if (mpc_u(0) > max_snap_x * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap X: " << mpc_u(0));
      mpc_u(0)   = max_snap_x;
      saturating = true;
    }
    if (mpc_u(0) < -max_snap_x * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap X: " << mpc_u(0));
      mpc_u(0)   = -max_snap_x;
      saturating = true;
    }
    if (mpc_u(1) > max_snap_y * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap Y: " << mpc_u(1));
      mpc_u(1)   = max_snap_y;
      saturating = true;
    }
    if (mpc_u(1) < -max_snap_y * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap Y: " << mpc_u(1));
      mpc_u(1)   = -max_snap_y;
      saturating = true;
    }
    if (mpc_u(2) > max_snap_z * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap Z: " << mpc_u(2));
      mpc_u(2)   = max_snap_z;
      saturating = true;
    }
    if (mpc_u(2) < -min_snap_z * 1.01) {
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: saturating snap Z: " << mpc_u(2));
      mpc_u(2)   = -min_snap_z;
      saturating = true;
    }

    if (saturating) {
      debugPrintState(0.1);
      debugPrintMPCResult(0.1);
    }
  }

  {
    std::scoped_lock lock(mutex_mpc_u_);

    mpc_u_         = mpc_u;
    mpc_u_heading_ = mpc_u_heading;
  }

  double mpc_solver_time = (clock_->now() - time_begin).seconds();
  if (mpc_solver_time > dt1 || iters_x > _max_iters_xy_ || iters_y > _max_iters_xy_ || iters_z > _max_iters_z_ || iters_heading > _max_iters_heading_) {
    RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000,
                                 "[MpcTracker]: Total MPC solver time: " << mpc_solver_time << " iters X: " << iters_x << "/" << _max_iters_xy_
                                                                         << " iters Y:  " << iters_y << "/" << _max_iters_xy_ << " iters Z: " << iters_z << "/"
                                                                         << _max_iters_z_ << " iters heading: " << iters_heading << "/" << _max_iters_heading_);
  }

  future_was_predicted_ = true;

  // | ------------- breaking for the next iteration ------------ |

  if (drs_params.braking_enabled && (std::abs(des_x_filtered(MPC_HORIZON_LENGTH - 6) - des_x_filtered(MPC_HORIZON_LENGTH - 1)) <= 0.1) &&
      (std::abs(des_y_filtered(MPC_HORIZON_LENGTH - 6) - des_y_filtered(MPC_HORIZON_LENGTH - 1)) <= 0.1) &&
      (std::abs(des_z_filtered(MPC_HORIZON_LENGTH - 6) - des_z_filtered(MPC_HORIZON_LENGTH - 1)) <= 0.1) &&
      (std::abs(radians::diff(des_heading_trajectory(MPC_HORIZON_LENGTH - 6), des_heading_trajectory(MPC_HORIZON_LENGTH - 1))) <= 0.1)) {

    brake_ = true;
    RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: braking");

  } else {
    brake_ = false;
  }

  /* publish mpc reference //{ */

  {
    geometry_msgs::msg::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = clock_->now();
    debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

    {
      std::scoped_lock lock(mutex_predicted_trajectory_);

      for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

        geometry_msgs::msg::Pose new_pose;

        new_pose.position.x = des_x_filtered(i, 0);
        new_pose.position.y = des_y_filtered(i, 0);
        new_pose.position.z = des_z_filtered(i, 0);

        new_pose.orientation = mrs_lib::AttitudeConverter(0, 0, des_heading_trajectory(i));

        debug_trajectory_out.poses.push_back(new_pose);
      }
    }

    ph_mpc_reference_debugging_.publish(debug_trajectory_out);
  }

  //}
}

//}

/* iterateModel() //{ */

void MpcTracker::iterateModel(const double &dt) {

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  if (model_first_iteration_) {

    model_iteration_last_time_ = clock_->now();
    model_first_iteration_     = false;

  } else {

    dt1 = 0.9 * dt1 + 0.1 * dt;

    mrs_lib::set_mutexed(mutex_dt1_, dt1, dt1_);
    timer_mpc_iteration_->setPeriod(rclcpp::Duration(std::chrono::duration<double>(dt1)));

    // clang-format off
    A_ << 1, dt1, 0.5*dt1*dt1, 0,           0, 0,   0,           0,           0, 0,   0,           0,
          0, 1,   dt1,         0.5*dt1*dt1, 0, 0,   0,           0,           0, 0,   0,           0,
          0, 0,   1,           dt1,         0, 0,   0,           0,           0, 0,   0,           0,
          0, 0,   0,           1,           0, 0,   0,           0,           0, 0,   0,           0,
          0, 0,   0,           0,           1, dt1, 0.5*dt1*dt1, 0,           0, 0,   0,           0,
          0, 0,   0,           0,           0, 1,   dt1,         0.5*dt1*dt1, 0, 0,   0,           0,
          0, 0,   0,           0,           0, 0,   1,           dt1,         0, 0,   0,           0,
          0, 0,   0,           0,           0, 0,   0,           1,           0, 0,   0,           0,
          0, 0,   0,           0,           0, 0,   0,           0,           1, dt1, 0.5*dt1*dt1, 0,
          0, 0,   0,           0,           0, 0,   0,           0,           0, 1,   dt1,         0.5*dt1*dt1,
          0, 0,   0,           0,           0, 0,   0,           0,           0, 0,   1,           dt1,
          0, 0,   0,           0,           0, 0,   0,           0,           0, 0,   0,           1;

      B_ << 0,   0,   0,
            0,   0,   0,
            0,   0,   0,
            dt1, 0,   0,
            0,   0,   0,
            0,   0,   0,
            0,   0,   0,
            0,   dt1, 0,
            0,   0,   0,
            0,   0,   0,
            0,   0,   0,
            0,   0,   dt1;

      A_heading_ << 1, dt1, 0.5*dt1*dt1, 0,
                    0, 1,   dt1,         0.5*dt1*dt1,
                    0, 0,   1,           dt1,
                    0, 0,   0,           1;

      B_heading_ << 0,
                    0,
                    0,
                    dt1;

    model_iteration_last_time_ = clock_->now();
  }

  {
    auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);
    auto [mpc_u, mpc_u_heading] = mrs_lib::get_mutexed(mutex_mpc_u_, mpc_u_, mpc_u_heading_);

    MatrixXd new_mpc_x         = A_ * mpc_x + B_ * mpc_u;
    MatrixXd new_mpc_x_heading = A_heading_ * mpc_x_heading + B_heading_ * mpc_u_heading;

    // | --------------- check the state difference --------------- |
    {
      auto constraints = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

      bool problem = false;

      // position

      if (fabs((new_mpc_x(0) - mpc_x(0)) / dt1) > 1.05 * constraints.horizontal_speed) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal pos x update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(0), new_mpc_x(0),
                  fabs((new_mpc_x(0) - mpc_x(0)) / dt1), constraints.horizontal_speed);
        problem = true;
      }

      if (fabs((new_mpc_x(4) - mpc_x(4)) / dt1) > 1.05 * constraints.horizontal_speed) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal pos y update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(4), new_mpc_x(4),
                  fabs((new_mpc_x(4) - mpc_x(4)) / dt1), constraints.horizontal_speed);
        problem = true;
    }

      if (((new_mpc_x(8) - mpc_x(8)) / dt1) > 1.05 * constraints.vertical_ascending_speed) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical pos z update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(8), new_mpc_x(8),
                  ((new_mpc_x(8) - mpc_x(8)) / dt1), constraints.vertical_ascending_speed);
        problem = true;
      }

      if (((new_mpc_x(8) - mpc_x(8)) / dt1) < 1.05 * -constraints.vertical_descending_speed) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical pos z update violates constraints: %.2f -> %.2f = %.2f, < %.2f", mpc_x(8), new_mpc_x(8),
                  ((new_mpc_x(8) - mpc_x(8)) / dt1), -constraints.vertical_descending_speed);
        problem = true;
      }

      /* if (fabs(radians::diff(new_mpc_x_heading(0), mpc_x_heading(0)) / dt1) > 1.2 * constraints.heading_speed) { */
      /*   ROS_DEBUG("[MpcTracker]: heading update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x_heading(0), new_mpc_x_heading(0), */
      /*             fabs(radians::diff(new_mpc_x_heading(0), mpc_x_heading(0)) / dt1), constraints.heading_speed); */
      /*   problem = true; */
      /* } */

      // velocity

      if (fabs((new_mpc_x(1) - mpc_x(1)) / dt1) > 1.05 * constraints.horizontal_acceleration) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal vel x update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(1), new_mpc_x(1),
                  fabs((new_mpc_x(1) - mpc_x(1)) / dt1), constraints.horizontal_acceleration);
        problem = true;
      }

      if (fabs((new_mpc_x(5) - mpc_x(5)) / dt1) > 1.05 * constraints.horizontal_acceleration) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal vel y update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(5), new_mpc_x(5),
                  fabs((new_mpc_x(5) - mpc_x(5)) / dt1), constraints.horizontal_acceleration);
        problem = true;
      }

      if (((new_mpc_x(9) - mpc_x(9)) / dt1) > 1.05 * constraints.vertical_ascending_acceleration) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical vel z update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(9), new_mpc_x(9),
                  ((new_mpc_x(9) - mpc_x(9)) / dt1), constraints.vertical_ascending_acceleration);
        problem = true;
      }

      if (((new_mpc_x(9) - mpc_x(9)) / dt1) < 1.05 * -constraints.vertical_descending_acceleration) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical vel z update violates constraints: %.2f -> %.2f = %.2f, < %.2f", mpc_x(9), new_mpc_x(9),
                  ((new_mpc_x(9) - mpc_x(9)) / dt1), -constraints.vertical_descending_acceleration);
        problem = true;
      }

      // acceleration

      if (fabs((new_mpc_x(2) - mpc_x(2)) / dt1) > 1.05 * constraints.horizontal_jerk) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal acc x update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(2), new_mpc_x(2),
                  fabs((new_mpc_x(2) - mpc_x(2)) / dt1), constraints.horizontal_jerk);
        problem = true;
      }

      if (fabs((new_mpc_x(6) - mpc_x(6)) / dt1) > 1.05 * constraints.horizontal_jerk) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal acc y update violates constraints: %.2f -> %.2f, = %.2f > %.2f", mpc_x(6), new_mpc_x(6),
                  fabs((new_mpc_x(6) - mpc_x(6)) / dt1), constraints.horizontal_jerk);
        problem = true;
      }

      if (((new_mpc_x(10) - mpc_x(10)) / dt1) > 1.05 * constraints.vertical_ascending_jerk) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical acc z update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(10), new_mpc_x(10),
                  ((new_mpc_x(10) - mpc_x(10)) / dt1), constraints.vertical_ascending_jerk);
        problem = true;
      }

      if (((new_mpc_x(10) - mpc_x(10)) / dt1) < 1.05 * -constraints.vertical_descending_jerk) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical acc z update violates constraints: %.2f -> %.2f = %.2f, < %.2f", mpc_x(10), new_mpc_x(10),
                  ((new_mpc_x(10) - mpc_x(10)) / dt1), -constraints.vertical_descending_jerk);
        problem = true;
      }

      // jerk

      if (fabs((new_mpc_x(3) - mpc_x(3)) / dt1) > 1.05 * constraints.horizontal_snap) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal jerk x update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(3), new_mpc_x(3),
                  fabs((new_mpc_x(3) - mpc_x(3)) / dt1), constraints.horizontal_snap);
        problem = true;
      }

      if (fabs((new_mpc_x(7) - mpc_x(7)) / dt1) > 1.05 * constraints.horizontal_snap) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: horizontal jerk y update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(7), new_mpc_x(7),
                  fabs((new_mpc_x(7) - mpc_x(7)) / dt1), constraints.horizontal_snap);
        problem = true;
      }

      if (((new_mpc_x(11) - mpc_x(11)) / dt1) > 1.05 * constraints.vertical_ascending_snap) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical jerk z update violates constraints: %.2f -> %.2f = %.2f, > %.2f", mpc_x(11), new_mpc_x(11),
                  ((new_mpc_x(11) - mpc_x(11)) / dt1), constraints.vertical_ascending_snap);
        problem = true;
      }

      if (((new_mpc_x(11) - mpc_x(11)) / dt1) < 1.05 * -constraints.vertical_descending_snap) {
        RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: vertical jerk z update violates constraints: %.2f -> %.2f = %.2f, < %.2f", mpc_x(11), new_mpc_x(11),
                  ((new_mpc_x(11) - mpc_x(11)) / dt1), -constraints.vertical_descending_snap);
        problem = true;
      }

      if (problem) {
        debugPrintState(0.001);
        debugPrintMPCResult(0.001);
      }
    }

    {
      std::scoped_lock lock(mutex_mpc_x_);

      mpc_x_         = new_mpc_x;
      mpc_x_heading_ = new_mpc_x_heading;

      mpc_x_heading_(0) = sradians::wrap(mpc_x_heading_(0));
    }
  }
}

//}

// | -------------------- referece setting -------------------- |

/* //{ loadTrajectory() */

// method for setting desired trajectory
std::tuple<bool, std::string, bool> MpcTracker::loadTrajectory(const mrs_msgs::msg::TrajectoryReference msg) {

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  // copy the member variables
  auto x         = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);
  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  std::stringstream ss;

  /* check the trajectory dt //{ */

  double trajectory_dt;
  if (msg.dt <= 1e-4) {
    trajectory_dt = 0.2;
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 10000, "[MpcTracker]: the trajectory dt was not specified, assuming its the old 0.2 s");
  } else if (msg.dt < dt1) {
    trajectory_dt = 0.2;
    ss << std::setprecision(3) << "the trajectory dt (" << msg.dt << " s) is too small (smaller than the tracker's internal step size: " << dt1 << " s)";
    RCLCPP_ERROR_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
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

    rclcpp::Time trajectory_time = msg.header.stamp;

    // the desired time is 0 => the current time
    // the trajecoty is a single point => the current time
    if (trajectory_time.seconds() == 0 || int(msg.points.size()) == 1) {

      trajectory_time_offset = 0.0;

      // the desired time is specified
    } else {

      trajectory_time_offset = (clock_->now() - trajectory_time).seconds();

      // when the time offset is negative, thus in the future
      // just say it, but use it like its from the current time
      if (trajectory_time_offset < 0.0) {

        RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: received trajectory with timestamp in the future by %.3f s", -trajectory_time_offset);

        trajectory_time_offset = 0.0;
      }
    }

    // if the time offset is set, check if we need to "move the first idx"
    if (trajectory_time_offset > 0.0) {

      // calculate the offset in samples
      trajectory_sample_offset = int(floor(trajectory_time_offset / trajectory_dt));

      // and get the subsample offset, which will be used to initialize the interpolator
      trajectory_subsample_offset = int(floor(fmod(trajectory_time_offset, trajectory_dt) / dt1));

      RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: received trajectory with timestamp in the past by %.3f s",
                         trajectory_dt * trajectory_sample_offset + dt1 * trajectory_subsample_offset);

      // if the offset is larger than the number of points in the trajectory
      // the trajectory can not be used
      if (trajectory_sample_offset >= trajectory_size) {

        ss << "trajectory timestamp is too old (time difference = " << trajectory_time_offset << ")";
        RCLCPP_ERROR_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
        return std::tuple(false, ss.str(), false);

      } else {

        // if the offset is larger than one trajectory sample,
        // offset the start
        if (trajectory_time_offset >= trajectory_dt) {

          // decrease the trajectory size
          trajectory_size -= trajectory_sample_offset;

          RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: offsetting trajectory by %d samples", trajectory_sample_offset);

        } else {

          trajectory_sample_offset = 0;
        }
      }
    }

  } else { // not fly_now

      trajectory_tracking_in_progress_ = false;
  }

  //}

  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: trajectory sample offset: %d", trajectory_sample_offset);
  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: trajectory subsample offset: %d", trajectory_subsample_offset);

  // after this, we should have the correct value of
  // * trajectory_size
  // * trajectory_sample_offset
  // * trajectory_subsample_offset

  /* copy the trajectory to a local variable //{ */

  // copy only the part from the first valid index

  MatrixXd des_x_whole_trajectory       = VectorXd::Zero(trajectory_size + MPC_HORIZON_LENGTH, 1);
  MatrixXd des_y_whole_trajectory       = VectorXd::Zero(trajectory_size + MPC_HORIZON_LENGTH, 1);
  MatrixXd des_z_whole_trajectory       = VectorXd::Zero(trajectory_size + MPC_HORIZON_LENGTH, 1);
  MatrixXd des_heading_whole_trajectory = VectorXd::Zero(trajectory_size + MPC_HORIZON_LENGTH, 1);

  for (int i = 0; i < trajectory_size; i++) {

    des_x_whole_trajectory(i)       = msg.points.at(trajectory_sample_offset + i).position.x;
    des_y_whole_trajectory(i)       = msg.points.at(trajectory_sample_offset + i).position.y;
    des_z_whole_trajectory(i)       = msg.points.at(trajectory_sample_offset + i).position.z;
    des_heading_whole_trajectory(i) = msg.points.at(trajectory_sample_offset + i).heading;
  }

  //}

  /* set looping //{ */

  bool loop = false;

  if (msg.loop) {

    double first_x = des_x_whole_trajectory(0);
    double first_y = des_y_whole_trajectory(0);
    double first_z = des_z_whole_trajectory(0);
    double first_hdg = des_heading_whole_trajectory(0);

    double last_x = des_x_whole_trajectory(trajectory_size - 1);
    double last_y = des_y_whole_trajectory(trajectory_size - 1);
    double last_z = des_z_whole_trajectory(trajectory_size - 1);
    double last_hdg = des_heading_whole_trajectory(trajectory_size - 1);

    // check whether the trajectory is loopable
    if (mrs_lib::geometry::dist(vec3_t(first_x, first_y, first_z), vec3_t(last_x, last_y, last_z)) < 1.0 && abs(sradians::diff(first_hdg, last_hdg)) < 0.2) {

      RCLCPP_INFO_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: looping enabled");
      loop = true;

    } else {

      ss << "can not loop trajectory, the first and last points are too far apart";
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
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
    for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

      des_x_whole_trajectory(i + trajectory_size)       = des_x_whole_trajectory(i + trajectory_size - 1);
      des_y_whole_trajectory(i + trajectory_size)       = des_y_whole_trajectory(i + trajectory_size - 1);
      des_z_whole_trajectory(i + trajectory_size)       = des_z_whole_trajectory(i + trajectory_size - 1);
      des_heading_whole_trajectory(i + trajectory_size) = des_heading_whole_trajectory(i + trajectory_size - 1);
    }
  }

  //}

  // by this time, the values of these should be set correctly:
  // * trajectory_size
  // * des_x_whole_trajectory
  // * des_y_whole_trajectory
  // * des_z_whole_trajectory
  // * des_heading_whole_trajectory

  /* update the global variables //{ */

  {
    std::scoped_lock lock(mutex_des_whole_trajectory_, mutex_des_trajectory_, mutex_trajectory_tracking_states_);

    des_whole_trajectory_id_ = msg.input_id;

    auto mpc_x_heading = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_heading_);

    trajectory_tracking_in_progress_ = msg.fly_now;
    trajectory_track_heading_        = msg.use_heading;

    // allocate the vectors
    des_x_whole_trajectory_       = std::make_shared<VectorXd>(trajectory_size + MPC_HORIZON_LENGTH, 1);
    des_y_whole_trajectory_       = std::make_shared<VectorXd>(trajectory_size + MPC_HORIZON_LENGTH, 1);
    des_z_whole_trajectory_       = std::make_shared<VectorXd>(trajectory_size + MPC_HORIZON_LENGTH, 1);
    des_heading_whole_trajectory_ = std::make_shared<VectorXd>(trajectory_size + MPC_HORIZON_LENGTH, 1);

    for (int i = 0; i < trajectory_size + MPC_HORIZON_LENGTH; i++) {

      (*des_x_whole_trajectory_)(i) = des_x_whole_trajectory(i);
      (*des_y_whole_trajectory_)(i) = des_y_whole_trajectory(i);
      (*des_z_whole_trajectory_)(i) = des_z_whole_trajectory(i);

      if (trajectory_track_heading_) {
        (*des_heading_whole_trajectory_)(i) = des_heading_whole_trajectory(i);
      } else {
        (*des_heading_whole_trajectory_).fill(mpc_x_heading(0, 0));
      }
    }

    // if we are tracking trajectory, copy the setpoint
    if (trajectory_tracking_in_progress_) {

      toggleHover(false);

      /* interpolate the trajectory points and fill in the desired_trajectory vector //{ */

      for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

        double first_time = dt1 + i * _dt2_ + trajectory_subsample_offset * dt1;

        int first_idx  = floor(first_time / trajectory_dt);
        int second_idx = first_idx + 1;

        double interp_coeff = std::fmod(first_time / trajectory_dt, 1.0);

        if (trajectory_tracking_loop_) {

          if (second_idx >= trajectory_size) {
            second_idx -= trajectory_size;
          }

          if (first_idx >= trajectory_size) {
            first_idx -= trajectory_size;
          }
        } else {

          if (second_idx >= trajectory_size) {
            second_idx = trajectory_size - 1;
          }

          if (first_idx >= trajectory_size) {
            first_idx = trajectory_size - 1;
          }
        }

        des_x_trajectory_(i, 0) = (1.0 - interp_coeff) * des_x_whole_trajectory(first_idx) + interp_coeff * des_x_whole_trajectory(second_idx);
        des_y_trajectory_(i, 0) = (1.0 - interp_coeff) * des_y_whole_trajectory(first_idx) + interp_coeff * des_y_whole_trajectory(second_idx);
        des_z_trajectory_(i, 0) = (1.0 - interp_coeff) * des_z_whole_trajectory(first_idx) + interp_coeff * des_z_whole_trajectory(second_idx);

        des_heading_trajectory_(i, 0) = sradians::interp(des_heading_whole_trajectory(first_idx), des_heading_whole_trajectory(second_idx), interp_coeff);
      }

      //}
    }

    trajectory_size_             = trajectory_size;
    trajectory_current_time_     = 0;
    trajectory_set_              = true;
    trajectory_tracking_loop_    = loop;
    trajectory_dt_               = trajectory_dt;
    trajectory_count_++;
  }

  //}

  RCLCPP_INFO_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: finished setting trajectory with length %d", trajectory_size);

  /* publish the debugging topics of the post-processed trajectory //{ */

  {

    geometry_msgs::msg::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = clock_->now();
    debug_trajectory_out.header.frame_id = common_handlers_->transformer->resolveFrame(msg.header.frame_id);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

      for (int i = 0; i < trajectory_size; i++) {

        geometry_msgs::msg::Pose new_pose;

        new_pose.position.x = (*des_x_whole_trajectory_)(i);
        new_pose.position.y = (*des_y_whole_trajectory_)(i);
        new_pose.position.z = (*des_z_whole_trajectory_)(i);

        new_pose.orientation = mrs_lib::AttitudeConverter(0, 0, (*des_heading_whole_trajectory_)(i));

        debug_trajectory_out.poses.push_back(new_pose);
      }
    }

    pub_debug_processed_trajectory_poses_.publish(debug_trajectory_out);

    visualization_msgs::msg::MarkerArray msg_out;

    visualization_msgs::msg::Marker marker;

    marker.header.stamp     = clock_->now();
    marker.header.frame_id  = common_handlers_->transformer->resolveFrame(msg.header.frame_id);
    marker.type             = visualization_msgs::msg::Marker::LINE_LIST;
    marker.color.a          = 1;
    marker.scale.x          = 0.05;
    marker.color.r          = 1;
    marker.color.g          = 0;
    marker.color.b          = 0;
    marker.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

      for (int i = 0; i < trajectory_size - 1; i++) {

        geometry_msgs::msg::Point point1;

        point1.x = des_x_whole_trajectory(i);
        point1.y = des_y_whole_trajectory(i);
        point1.z = des_z_whole_trajectory(i);

        marker.points.push_back(point1);

        geometry_msgs::msg::Point point2;

        point2.x = des_x_whole_trajectory(i + 1);
        point2.y = des_y_whole_trajectory(i + 1);
        point2.z = des_z_whole_trajectory(i + 1);

        marker.points.push_back(point2);
      }
    }

    msg_out.markers.push_back(marker);

    pub_debug_processed_trajectory_markers_.publish(msg_out);
  }

  //}

  publishDiagnostics();

  return std::tuple(true, "trajectory loaded", false);
}

//}

/* //{ setSinglePointReference() */

// fill the des_*_trajectory based on a single point
void MpcTracker::setSinglePointReference(const double x, const double y, const double z, const double heading) {

  std::scoped_lock lock(mutex_des_trajectory_);

  des_x_trajectory_.fill(x);
  des_y_trajectory_.fill(y);
  des_z_trajectory_.fill(z);
  des_heading_trajectory_.fill(heading);
}

//}

/* //{ setGoal() */

// set absolute goal
void MpcTracker::setGoal(const double pos_x, const double pos_y, const double pos_z, const double heading, const bool use_heading) {

  double desired_heading = sradians::wrap(heading);

  auto mpc_x_heading = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_heading_);

  if (!use_heading) {
    desired_heading = mpc_x_heading(0, 0);
  }

  trajectory_tracking_in_progress_ = false;

  setSinglePointReference(pos_x, pos_y, pos_z, desired_heading);

  publishDiagnostics();
}

//}

/* //{ setRelativeGoal() */

void MpcTracker::setRelativeGoal(const double pos_x, const double pos_y, const double pos_z, const double heading, const bool use_heading) {

  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);

  double abs_x = mpc_x(0, 0) + pos_x;
  double abs_y = mpc_x(4, 0) + pos_y;
  double abs_z = mpc_x(8, 0) + pos_z;

  double abs_heading = mpc_x_heading(0, 0);

  if (use_heading) {
    abs_heading += heading;
  }

  trajectory_tracking_in_progress_ = false;

  setSinglePointReference(abs_x, abs_y, abs_z, abs_heading);

  publishDiagnostics();
}

//}

/* toggleHover() //{ */

void MpcTracker::toggleHover(bool in) {

  if (in == false && hovering_in_progress_) {

    RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: stoppping the hover timer");

    timer_hover_->stop();

    hovering_in_progress_ = false;

  } else if (in == true && !hovering_in_progress_) {

    RCLCPP_DEBUG(node_->get_logger(), "[MpcTracker]: starting the hover timer");

    hovering_in_progress_ = true;

    timer_hover_->start();
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
      trajectory_current_time_ = 0;
    }

    publishDiagnostics();

    ss << "trajectory tracking started";
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(true, ss.str());

  } else {

    ss << "can not start trajectory tracking, the trajectory is not set";
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

/* resumeTrajectoryTrackingImpl() //{ */

std::tuple<bool, std::string> MpcTracker::resumeTrajectoryTrackingImpl(void) {

  std::stringstream ss;

  if (trajectory_set_) {

    toggleHover(false);

    int trajectory_tracking_idx = getCurrentTrajectoryIdx();

    if (trajectory_tracking_idx < (trajectory_size_ - 1)) {

      {
        std::scoped_lock lock(mutex_des_trajectory_);

        trajectory_tracking_in_progress_ = true;
      }

      ss << "trajectory tracking resumed";
      RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

      publishDiagnostics();

      return std::tuple(true, ss.str());

    } else {

      ss << "can not resume trajectory tracking, trajectory is already finished";
      RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

      return std::tuple(false, ss.str());
    }

  } else {

    ss << "can not resume trajectory tracking, ther trajectory is not set";
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

/* stopTrajectoryTrackingImpl() //{ */

std::tuple<bool, std::string> MpcTracker::stopTrajectoryTrackingImpl(void) {

  std::stringstream ss;

  if (trajectory_tracking_in_progress_) {

    trajectory_tracking_in_progress_ = false;

    toggleHover(true);

    ss << "stopping trajectory tracking";
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    publishDiagnostics();

  } else {

    ss << "can not stop trajectory tracking, already at stop";
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());
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

    {
      std::scoped_lock lock(mutex_des_whole_trajectory_);

      setGoal((*des_x_whole_trajectory_)(0), (*des_y_whole_trajectory_)(0), (*des_z_whole_trajectory_)(0), (*des_heading_whole_trajectory_)(0),
              trajectory_track_heading_);
    }

    publishDiagnostics();

    ss << "flying to the start of the trajectory";
    RCLCPP_INFO_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(true, ss.str());

  } else {

    ss << "can not fly to the start of the trajectory, the trajectory is not set";
    RCLCPP_WARN_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: " << ss.str());

    return std::tuple(false, ss.str());
  }
}

//}

// | ------------------------- support ------------------------ |

/* //{ publishDiagnostics() */

void MpcTracker::publishDiagnostics(void) {

  auto des_x_trajectory       = mrs_lib::get_mutexed(mutex_des_trajectory_, des_x_trajectory_);
  auto des_y_trajectory       = mrs_lib::get_mutexed(mutex_des_trajectory_, des_y_trajectory_);
  auto des_z_trajectory       = mrs_lib::get_mutexed(mutex_des_trajectory_, des_z_trajectory_);
  auto des_heading_trajectory = mrs_lib::get_mutexed(mutex_des_trajectory_, des_heading_trajectory_);

  mrs_msgs::msg::MpcTrackerDiagnostics diagnostics;

  diagnostics.header.stamp    = clock_->now();
  diagnostics.header.frame_id = uav_state_.header.frame_id;

  diagnostics.active = is_active_;

  diagnostics.uav_name = _uav_name_;

  diagnostics.collision_avoidance_active = collision_avoidance_enabled_;
  diagnostics.avoiding_collision         = collision_avoidance_affecting_me_;

  diagnostics.setpoint.position.x = des_x_trajectory(0, 0);
  diagnostics.setpoint.position.y = des_y_trajectory(0, 0);
  diagnostics.setpoint.position.z = des_z_trajectory(0, 0);

  diagnostics.setpoint.orientation = mrs_lib::AttitudeConverter(0, 0, des_heading_trajectory(0, 0));

  std::stringstream ss;

  {
    std::scoped_lock lock(mutex_other_uav_diagnostics_);

    // fill in if other UAVs are sending their trajectories
    std::map<std::string, mrs_msgs::msg::MpcTrackerDiagnostics>::iterator u = other_uav_diagnostics_.begin();

    while (u != other_uav_diagnostics_.end()) {

      if (u->second.collision_avoidance_active) {

        // is the other's trajectory fresh enought?
        if ((clock_->now() - u->second.header.stamp).seconds() < _collision_trajectory_timeout_) {
          diagnostics.avoidance_active_uavs.push_back(u->first);
          ss << u->first.c_str() << ", ";
        }
      }

      u++;
    }
  }

  auto uav_state = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);

  if (ss.str().length() > 0) {
    RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 5000, "[MpcTracker]: getting avoidance trajectories: " << ss.str());
  } else if (collision_avoidance_enabled_ &&
      (uav_state.estimator_horizontal == "lat_gps" || uav_state.estimator_horizontal == "lat_rtk")) {
    RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 10000, "[MpcTracker]: missing avoidance trajectories!");
  }

  pub_diagnostics_.publish(diagnostics);

  std_msgs::msg::String string_msg;

  if (diagnostics.avoidance_active_uavs.empty()) {

    string_msg.data = "-id col_avoid I see: NOTHING";

  } else {

    string_msg.data = "-id col_avoid I see: ";
  }

  if (diagnostics.avoidance_active_uavs.size() <= 3) {

    for (size_t i = 0; i < diagnostics.avoidance_active_uavs.size(); i++) {
      if (i == 0) {
        string_msg.data += diagnostics.avoidance_active_uavs.at(i);
      } else {
        string_msg.data += ", " + diagnostics.avoidance_active_uavs.at(i);
      }
    }

  } else {

    std::stringstream ss;
    ss << diagnostics.avoidance_active_uavs.size();

    string_msg.data += ss.str() + " UAVs";
  }

  pub_status_string_.publish(string_msg);
}

//}

/* debugPrintState() //{ */

void MpcTracker::debugPrintState(const double throttle) {

  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);

  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: MPC internal state: pos [%.2f, %.2f, %.2f, %.2f]", mpc_x(0), mpc_x(4), mpc_x(8), mpc_x_heading(0));
  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: MPC internal state: vel [%.2f, %.2f, %.2f, %.2f]", mpc_x(1), mpc_x(5), mpc_x(9), mpc_x_heading(1));
  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: MPC internal state: acc [%.2f, %.2f, %.2f, %.2f]", mpc_x(2), mpc_x(6), mpc_x(10), mpc_x_heading(2));
  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: MPC internal state: jerk [%.2f, %.2f, %.2f, %.2f]", mpc_x(3), mpc_x(7), mpc_x(11), mpc_x_heading(3));
}

//}

/* debugPrintMPCu() //{ */

void MpcTracker::debugPrintMPCResult(const double throttle) {

  auto [mpc_u, mpc_u_heading] = mrs_lib::get_mutexed(mutex_mpc_u_, mpc_u_, mpc_u_heading_);
  auto constraints            = mrs_lib::get_mutexed(mutex_constraints_, constraints_);

  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: MPC result: [%.2f, %.2f, %.2f, %.2f]", mpc_u(0), mpc_u(1), mpc_u(2), mpc_u_heading);
  RCLCPP_DEBUG_THROTTLE(node_->get_logger(), *clock_, 1000*throttle, "[MpcTracker]: snap constraint: hor: %.2f, ver asc: %.2f, vert desc: %.2f, heading: %.2f]", constraints.horizontal_snap, constraints.vertical_ascending_snap, constraints.vertical_descending_snap, constraints.heading_snap);
}

//}

/* getCurrentTrajectoryIdx() //{ */

int MpcTracker::getCurrentTrajectoryIdx() {

  auto trajectory_current_time = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_current_time_);
  auto trajectory_dt   = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_dt_);

  return floor(trajectory_current_time / trajectory_dt);
}

//}

/* increaseCurrentTrajectoryTime() //{ */

void MpcTracker::increaseCurrentTrajectoryTime(const double dt) {

  auto trajectory_current_time = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_current_time_);
  auto [trajectory_size, trajectory_dt] = mrs_lib::get_mutexed(mutex_des_trajectory_, trajectory_size_, trajectory_dt_);

  trajectory_current_time += dt;

  const double trajectory_duration = trajectory_size * trajectory_dt;

  // if the tracking idx hits the end of the trajectory
  if (trajectory_current_time >= trajectory_duration) {

    if (trajectory_tracking_loop_) {

      // reset the idx
      trajectory_current_time -= trajectory_duration;

      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: trajectory looped");

    } else {

      trajectory_tracking_in_progress_ = false;

      RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: done tracking trajectory, current time in trajectory=%f, trajectory_duration=%f", trajectory_current_time, trajectory_duration);
    }
  }

  if (trajectory_tracking_in_progress_) {
    mrs_lib::set_mutexed(mutex_trajectory_tracking_states_, trajectory_current_time, trajectory_current_time_);
  }
}

//}

// --------------------------------------------------------------
// |                           timers                           |
// --------------------------------------------------------------

/* //{ timerDiagnostics() */

// published diagnostics in reguar intervals
void MpcTracker::timerDiagnostics() {

  if (!is_initialized_)
    return;

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("timerDiagnostics");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer(node_, "MpcTracker::timerDiagnostics", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  publishDiagnostics();
}

//}

/* //{ timerMPC() */

void MpcTracker::timerMPC() {

  if (odometry_reset_in_progress_) {
    RCLCPP_ERROR(node_->get_logger(), "[MpcTracker]: mpc iteration tried run while reseting odometry");
    return;
  }

  auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

  mrs_lib::AtomicScopeFlag unset_running(mpc_timer_running_);

  bool started_with_invalid = mpc_result_invalid_;

  if (!is_active_) {
    return;
  }

  if (!is_initialized_) {
    return;
  }

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("timerMPC");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer(node_, "MpcTracker::timerMPC", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  rclcpp::Time     begin = clock_->now();
  rclcpp::Time     end;

  double interval;

  int           trajectory_id;

  // if we are tracking trajectory, copy the setpoint
  if (trajectory_tracking_in_progress_) {

    MatrixXd des_x_trajectory, des_y_trajectory, des_z_trajectory, des_heading_trajectory;
    VectorXd des_x_whole_trajectory, des_y_whole_trajectory, des_z_whole_trajectory, des_heading_whole_trajectory;
    double   trajectory_dt;
    int      trajectory_size;
    {
      std::scoped_lock lock(mutex_des_trajectory_, mutex_des_whole_trajectory_);

      des_x_trajectory       = des_x_trajectory_;
      des_y_trajectory       = des_y_trajectory_;
      des_z_trajectory       = des_z_trajectory_;
      des_heading_trajectory = des_heading_trajectory_;

      des_x_whole_trajectory       = *des_x_whole_trajectory_;
      des_y_whole_trajectory       = *des_y_whole_trajectory_;
      des_z_whole_trajectory       = *des_z_whole_trajectory_;
      des_heading_whole_trajectory = *des_heading_whole_trajectory_;

      trajectory_size = trajectory_size_;
      trajectory_dt   = trajectory_dt_;

      trajectory_id = des_whole_trajectory_id_;
    }

    /* interpolate the trajectory points and fill in the desired_trajectory vector //{ */

    double dt_from_last_update = 0.0;

    if (time_last_mpc_calculation_.seconds() == 0) {

      dt_from_last_update = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

    } else {

      dt_from_last_update = (clock_->now() - time_last_mpc_calculation_).seconds();
    }

    time_last_mpc_calculation_ = clock_->now();

    if (dt_from_last_update > 0.0 && dt_from_last_update < 1.0) {
      increaseCurrentTrajectoryTime(dt_from_last_update);
    } else {
      RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: timerMpc(): dt from the last update is not normal, not iterating trajectory, dt=%.4f", dt_from_last_update);
    }

    auto trajectory_current_time = mrs_lib::get_mutexed(mutex_trajectory_tracking_states_, trajectory_current_time_);

    for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

      auto dt1 = mrs_lib::get_mutexed(mutex_dt1_, dt1_);

      double first_time = trajectory_current_time + dt1 + i * _dt2_;

      int first_idx  = int(floor(first_time / trajectory_dt));

      int second_idx = first_idx + 1;

      double interp_coeff = std::fmod(first_time / trajectory_dt, 1.0);

      if (trajectory_tracking_loop_) {

        if (second_idx >= trajectory_size) {
          second_idx = second_idx % trajectory_size;
        }

        if (first_idx >= trajectory_size) {
          first_idx = first_idx % trajectory_size;
        }

      } else {

        if (second_idx >= trajectory_size) {
          second_idx = trajectory_size - 1;
        }

        if (first_idx >= trajectory_size) {
          first_idx = trajectory_size - 1;
        }
      }

      if (first_idx < 0 || first_idx > (trajectory_size-1) || second_idx < 0 || second_idx > (trajectory_size-1)) {
        RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 100, "[MpcTracker]: trying to index out range when interpolating the trajectory! first_idx=%d, second_idx=%d, trajectory_size=%d", first_idx, second_idx, trajectory_size);
        continue;
      }

      des_x_trajectory(i, 0) = (1.0 - interp_coeff) * des_x_whole_trajectory(first_idx) + interp_coeff * des_x_whole_trajectory(second_idx);
      des_y_trajectory(i, 0) = (1.0 - interp_coeff) * des_y_whole_trajectory(first_idx) + interp_coeff * des_y_whole_trajectory(second_idx);
      des_z_trajectory(i, 0) = (1.0 - interp_coeff) * des_z_whole_trajectory(first_idx) + interp_coeff * des_z_whole_trajectory(second_idx);

      des_heading_trajectory(i, 0) = sradians::interp(des_heading_whole_trajectory(first_idx), des_heading_whole_trajectory(second_idx), interp_coeff);
    }

    {
      std::scoped_lock lock(mutex_des_trajectory_);

      des_x_trajectory_       = des_x_trajectory;
      des_y_trajectory_       = des_y_trajectory;
      des_z_trajectory_       = des_z_trajectory;
      des_heading_trajectory_ = des_heading_trajectory;
    }

    //}

    // | ---------- publish the current trajectory point ---------- |

    int trajectory_tracking_idx = getCurrentTrajectoryIdx();

    geometry_msgs::msg::PoseStamped debug_trajectory_point;
    debug_trajectory_point.header.stamp    = clock_->now();
    debug_trajectory_point.header.frame_id = uav_state_.header.frame_id;

    debug_trajectory_point.pose.position.x = (*des_x_whole_trajectory_)(trajectory_tracking_idx);
    debug_trajectory_point.pose.position.y = (*des_y_whole_trajectory_)(trajectory_tracking_idx);
    debug_trajectory_point.pose.position.z = (*des_z_whole_trajectory_)(trajectory_tracking_idx);

    debug_trajectory_point.pose.orientation = mrs_lib::AttitudeConverter(0, 0, (*des_heading_whole_trajectory_)(trajectory_tracking_idx));

    ph_current_trajectory_point_.publish(debug_trajectory_point);

  } else {

    std::scoped_lock lock(mutex_des_whole_trajectory_);

    trajectory_id = des_whole_trajectory_id_;
  }

  manageConstraints();

  calculateMPC();

  end      = clock_->now();
  interval = (end - begin).seconds();

  // | ------------------ calculate the MPC RTF ----------------- |

  mpc_rtf_ = 0.99 * mpc_rtf_ + 0.01 * (interval/dt1);

  if (mpc_rtf_ >= 1.0) {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 5000, "[MpcTracker] MPC Real Time Factor (%.3f) is slow", mpc_rtf_);
  }

  /* publish predicted future //{ */

  {
    geometry_msgs::msg::PoseArray debug_trajectory_out;
    debug_trajectory_out.header.stamp    = clock_->now();
    debug_trajectory_out.header.frame_id = uav_state_.header.frame_id;

    {
      std::scoped_lock lock(mutex_predicted_trajectory_);

      for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

        geometry_msgs::msg::Pose newPose;

        newPose.position.x = predicted_trajectory_(i * MPC_N_STATES);
        newPose.position.y = predicted_trajectory_(i * MPC_N_STATES + 4);
        newPose.position.z = predicted_trajectory_(i * MPC_N_STATES + 8);

        try {
          newPose.orientation = mrs_lib::AttitudeConverter(0, 0, predicted_heading_trajectory_(i * MPC_N_STATES));
        } catch (...) {
          RCLCPP_ERROR_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: failed to fill orientation into debug print trajectory");
        }

        debug_trajectory_out.poses.push_back(newPose);
      }
    }

    ph_predicted_trajectory_debugging_.publish(debug_trajectory_out);
  }

  //}

  /* publish full state prediction //{ */

  {
    mrs_msgs::msg::MpcPredictionFullState prediction_fs_out;
    prediction_fs_out.header.stamp    = clock_->now();
    prediction_fs_out.header.frame_id = uav_state_.header.frame_id;

    rclcpp::Time stamp = prediction_fs_out.header.stamp;

    prediction_fs_out.input_id = trajectory_id;

    {
      std::scoped_lock lock(mutex_predicted_trajectory_);

      for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

        if (i == 0) {
          stamp += rclcpp::Duration(std::chrono::duration<double>(0.01));
        } else {
          stamp += rclcpp::Duration(std::chrono::duration<double>(0.2));
        }

        prediction_fs_out.stamps.push_back(stamp);

        {  // position
          geometry_msgs::msg::Point point;

          point.x = predicted_trajectory_(i * MPC_N_STATES);
          point.y = predicted_trajectory_(i * MPC_N_STATES + 4);
          point.z = predicted_trajectory_(i * MPC_N_STATES + 8);

          prediction_fs_out.position.push_back(point);
        }

        {  // velocity
          geometry_msgs::msg::Vector3 vector;

          vector.x = predicted_trajectory_(i * MPC_N_STATES + 1);
          vector.y = predicted_trajectory_(i * MPC_N_STATES + 5);
          vector.z = predicted_trajectory_(i * MPC_N_STATES + 9);

          prediction_fs_out.velocity.push_back(vector);
        }

        {  // acceleration
          geometry_msgs::msg::Vector3 vector3;

          vector3.x = predicted_trajectory_(i * MPC_N_STATES + 2);
          vector3.y = predicted_trajectory_(i * MPC_N_STATES + 6);
          vector3.z = predicted_trajectory_(i * MPC_N_STATES + 10);

          prediction_fs_out.acceleration.push_back(vector3);
        }

        {  // jerk
          geometry_msgs::msg::Vector3 vector3;

          vector3.x = predicted_trajectory_(i * MPC_N_STATES + 3);
          vector3.y = predicted_trajectory_(i * MPC_N_STATES + 7);
          vector3.z = predicted_trajectory_(i * MPC_N_STATES + 11);

          prediction_fs_out.jerk.push_back(vector3);
        }

        {
          // heading

          prediction_fs_out.heading.push_back(predicted_heading_trajectory_(i * MPC_N_STATES));
          prediction_fs_out.heading_rate.push_back(predicted_heading_trajectory_(i * MPC_N_STATES + 1));
          prediction_fs_out.heading_acceleration.push_back(predicted_heading_trajectory_(i * MPC_N_STATES + 2));
          prediction_fs_out.heading_jerk.push_back(predicted_heading_trajectory_(i * MPC_N_STATES + 3));
        }
      }
    }

    {
      std::scoped_lock lock(mutex_prediction_full_state_);
      prediction_full_state_ = prediction_fs_out;
    }
  }

  //}

  mpc_computed_ = true;

  if (started_with_invalid) {

    mpc_result_invalid_ = false;

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: calculated the first MPC result after invalidation");
  }
}

//}

/* timerVelocityTracking() //{ */

void MpcTracker::timerVelocityTracking() {

  if (!is_initialized_) {
    return;
  }

  if (!velocity_tracking_active_) {
    return;
  }

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("timerVelocityTracking");
  mrs_lib::ScopeTimer timer =
      mrs_lib::ScopeTimer(node_, "MpcTracker::timerVelocityTracking", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  // stop the timer when timeout
  if ((clock_->now() - velocity_reference_time_).seconds() > 0.5) {

    RCLCPP_WARN_THROTTLE(node_->get_logger(), *clock_, 1000, "[MpcTracker]: velocity reference timeouted, hovering");
    timer_velocity_tracking_->stop();

    toggleHover(true);

    velocity_tracking_active_ = false;

    return;
  }

  auto [mpc_x, mpc_x_heading] = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_, mpc_x_heading_);
  auto velocity_reference     = mrs_lib::get_mutexed(mutex_velocity_reference_, velocity_reference_);

  mrs_msgs::msg::TrajectoryReference trajectory;

  trajectory.fly_now         = true;
  trajectory.use_heading     = true;
  trajectory.dt              = 0.2;
  trajectory.header.stamp    = clock_->now();
  trajectory.header.frame_id = "";

  double x       = mpc_x(0, 0);
  double y       = mpc_x(4, 0);
  double z       = mpc_x(8, 0);
  double heading = mpc_x_heading(0, 0);

  for (int i = 0; i < 50; i++) {

    mrs_msgs::msg::Reference reference;
    reference.position.x = x;
    reference.position.y = y;
    reference.position.z = z;
    reference.heading    = heading;

    trajectory.points.push_back(reference);

    x += velocity_reference.velocity.x * trajectory.dt;
    y += velocity_reference.velocity.y * trajectory.dt;
    z += velocity_reference.velocity.z * trajectory.dt;

    if (velocity_reference.use_altitude) {
      z = velocity_reference.altitude;
    }

    if (velocity_reference.use_heading_rate) {
      heading += velocity_reference.heading_rate * trajectory.dt;
    } else if (velocity_reference.use_heading) {
      heading = velocity_reference.heading;
    }
  }

  auto [success, message, modified] = loadTrajectory(trajectory);
}

//}

/* //{ timerAvoidanceTrajectory() */

void MpcTracker::timerAvoidanceTrajectory() {

  if (!is_active_) {
    return;
  }

  if (!is_initialized_) {
    return;
  }

  if (!sh_estimation_diag_.hasMsg()) {
    return;
  } else {
    // we won't try to transform and publish the avoidance prediction if we cannot transform it

    auto                     estimation_diag      = sh_estimation_diag_.getMsg();
    std::vector<std::string> state_estimators = estimation_diag.get()->switchable_state_estimators;

    bool got_gps_est = std::find(state_estimators.begin(), state_estimators.end(), "gps_garmin") != state_estimators.end() || std::find(state_estimators.begin(), state_estimators.end(), "gps_baro") != state_estimators.end();
    bool got_rtk_est = std::find(state_estimators.begin(), state_estimators.end(), "rtk") != state_estimators.end();

    if (!got_gps_est && !got_rtk_est) {
      return;
    }
  }

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("timerAvoidanceTrajectory");
  mrs_lib::ScopeTimer timer =
      mrs_lib::ScopeTimer(node_, "MpcTracker::timerAvoidanceTrajectory", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  auto uav_state            = mrs_lib::get_mutexed(mutex_uav_state_, uav_state_);
  auto predicted_trajectory = mrs_lib::get_mutexed(mutex_predicted_trajectory_, predicted_trajectory_);

  if (future_was_predicted_) {

    mrs_msgs::msg::FutureTrajectory avoidance_trajectory;

    // fill last trajectory with initial data
    avoidance_trajectory.stamp               = clock_->now();
    avoidance_trajectory.uav_name            = _uav_name_;
    avoidance_trajectory.priority            = avoidance_this_uav_priority_;
    avoidance_trajectory.collision_avoidance = collision_avoidance_enabled_ && (uav_state.estimator_horizontal == "lat_gps" || uav_state.estimator_horizontal == "lat_rtk");
    avoidance_trajectory.points.clear();
    avoidance_trajectory.stamp               = clock_->now();
    avoidance_trajectory.uav_name            = _uav_name_;
    avoidance_trajectory.priority            = avoidance_this_uav_priority_;
    avoidance_trajectory.collision_avoidance = collision_avoidance_enabled_;

    auto res = common_handlers_->transformer->getTransform(uav_state.header.frame_id, "utm_origin", clock_->now());

    if (!res) {

      std::string message = "[MpcTracker]: can not transform predicted future to utm_origin";
      RCLCPP_WARN_STREAM_ONCE(node_->get_logger(), message);
      RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, message);
      return;

    } else {

      geometry_msgs::msg::TransformStamped tf = res.value();

      for (int i = 0; i < MPC_HORIZON_LENGTH; i++) {

        // original point
        geometry_msgs::msg::PoseStamped original_point;

        original_point.header.stamp    = clock_->now();
        original_point.header.frame_id = uav_state.header.frame_id;

        original_point.pose.position.x = predicted_trajectory(i * MPC_N_STATES);
        original_point.pose.position.y = predicted_trajectory(i * MPC_N_STATES + 4);
        original_point.pose.position.z = predicted_trajectory(i * MPC_N_STATES + 8);

        original_point.pose.orientation = mrs_lib::AttitudeConverter(0, 0, 0);

        auto res = common_handlers_->transformer->transform(original_point, tf);

        if (res) {

          mrs_msgs::msg::FuturePoint new_point;

          new_point.x = res.value().pose.position.x;
          new_point.y = res.value().pose.position.y;
          new_point.z = res.value().pose.position.z;

          avoidance_trajectory.points.push_back(new_point);

        } else {

          std::string message = "[MpcTracker]: can not transform a point of a future trajectory";
          RCLCPP_WARN_STREAM_ONCE(node_->get_logger(), message);
          RCLCPP_DEBUG_STREAM_THROTTLE(node_->get_logger(), *clock_, 1000, message);
        }
      }
    }

    ph_avoidance_trajectory_.publish(avoidance_trajectory);
  }
}

//}

/* timerHover() //{ */

void MpcTracker::timerHover() {

  MatrixXd mpc_x = mrs_lib::get_mutexed(mutex_mpc_x_, mpc_x_);

  mrs_lib::Routine    profiler_routine = profiler.createRoutine("timerHover");
  mrs_lib::ScopeTimer timer = mrs_lib::ScopeTimer(node_, "MpcTracker::timerHover", common_handlers_->scope_timer.logger, common_handlers_->scope_timer.enabled);

  setRelativeGoal(0, 0, 0, 0, false);

  if (fabs(mpc_x(1, 0)) < 0.1 && fabs(mpc_x(5, 0)) < 0.1 && fabs(mpc_x(9, 0)) < 0.1) {

    toggleHover(false);

    RCLCPP_INFO(node_->get_logger(), "[MpcTracker]: timerHover: speed is low, stopping hover timer");
  }
}

//}

}  // namespace mpc_tracker

}  // namespace mrs_uav_trackers

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(mrs_uav_trackers::mpc_tracker::MpcTracker, mrs_uav_managers::Tracker)
