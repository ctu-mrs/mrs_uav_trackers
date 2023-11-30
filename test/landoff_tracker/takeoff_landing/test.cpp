#include <gtest/gtest.h>
#include <ros/console.h>
#include <log4cxx/logger.h>

#include <mrs_lib/subscribe_handler.h>
#include <mrs_lib/service_client_handler.h>

#include <std_msgs/Bool.h>
#include <mrs_msgs/ControlManagerDiagnostics.h>
#include <mrs_msgs/EstimationDiagnostics.h>
#include <mrs_msgs/Vec4.h>

#include <std_srvs/SetBool.h>
#include <std_srvs/Trigger.h>

/* class Tester //{ */

class Tester {

public:
  Tester();

  bool test();

private:
  ros::NodeHandle                    nh_;
  std::shared_ptr<ros::AsyncSpinner> spinner_;

  mrs_lib::SubscribeHandler<mrs_msgs::ControlManagerDiagnostics> sh_control_manager_diag_;
  mrs_lib::SubscribeHandler<mrs_msgs::EstimationDiagnostics>     sh_estim_manager_diag_;
  mrs_lib::SubscribeHandler<std_msgs::Bool>                      sh_can_takeoff;

  mrs_lib::ServiceClientHandler<std_srvs::SetBool> sch_arming_;
  mrs_lib::ServiceClientHandler<std_srvs::Trigger> sch_offboard_;

  mrs_lib::ServiceClientHandler<mrs_msgs::Vec4>    sch_goto_;
  mrs_lib::ServiceClientHandler<std_srvs::Trigger> sch_land_;
};

//}

/* Tester() //{ */

Tester::Tester() {

  // | ------------------ initialize test node ------------------ |

  nh_ = ros::NodeHandle("~");

  ROS_INFO("[%s]: ROS node initialized", ros::this_node::getName().c_str());

  ros::Time::waitForValid();

  spinner_ = std::make_shared<ros::AsyncSpinner>(4);
  spinner_->start();

  std::string uav_name = "uav1";

  // | ----------------------- subscribers ---------------------- |

  mrs_lib::SubscribeHandlerOptions shopts;
  shopts.nh                 = nh_;
  shopts.node_name          = "Test";
  shopts.no_message_timeout = mrs_lib::no_timeout;
  shopts.threadsafe         = true;
  shopts.autostart          = true;
  shopts.queue_size         = 10;
  shopts.transport_hints    = ros::TransportHints().tcpNoDelay();

  sh_control_manager_diag_ = mrs_lib::SubscribeHandler<mrs_msgs::ControlManagerDiagnostics>(shopts, "/" + uav_name + "/control_manager/diagnostics");
  sh_estim_manager_diag_   = mrs_lib::SubscribeHandler<mrs_msgs::EstimationDiagnostics>(shopts, "/" + uav_name + "/estimation_manager/diagnostics");
  sh_can_takeoff           = mrs_lib::SubscribeHandler<std_msgs::Bool>(shopts, "/" + uav_name + "/automatic_start/can_takeoff");

  ROS_INFO("[%s]: subscribers initialized", ros::this_node::getName().c_str());

  // | --------------------- service clients -------------------- |

  sch_arming_   = mrs_lib::ServiceClientHandler<std_srvs::SetBool>(nh_, "/" + uav_name + "/hw_api/arming");
  sch_offboard_ = mrs_lib::ServiceClientHandler<std_srvs::Trigger>(nh_, "/" + uav_name + "/hw_api/offboard");

  sch_land_ = mrs_lib::ServiceClientHandler<std_srvs::Trigger>(nh_, "/" + uav_name + "/uav_manager/land");
  sch_goto_ = mrs_lib::ServiceClientHandler<mrs_msgs::Vec4>(nh_, "/" + uav_name + "/control_manager/goto");

  ROS_INFO("[%s]: service client initialized", ros::this_node::getName().c_str());
}

//}

/* test() //{ */

bool Tester::test() {

  // | ---------------- wait for ready to takeoff --------------- |

  while (ros::ok()) {

    ROS_INFO_THROTTLE(1.0, "[%s]: waiting for the MRS UAV System", ros::this_node::getName().c_str());

    if (sh_control_manager_diag_.hasMsg() && sh_estim_manager_diag_.hasMsg()) {
      break;
    }

    ros::Duration(0.01).sleep();
  }

  ROS_INFO("[%s]: MRS UAV System is ready", ros::this_node::getName().c_str());

  ros::Duration(1.0).sleep();

  // | ---------------------- arm the drone --------------------- |

  ROS_INFO("[%s]: arming the edrone", ros::this_node::getName().c_str());

  {
    std_srvs::SetBool arming;
    arming.request.data = true;

    {
      bool service_call = sch_arming_.call(arming);

      if (!service_call || !arming.response.success) {
        ROS_ERROR("[%s]: arming service call failed", ros::this_node::getName().c_str());
        return false;
      }
    }
  }

  // | -------------------------- wait -------------------------- |

  ros::Duration(0.2).sleep();

  // | -------------------- trigger offboard -------------------- |

  ROS_INFO("[%s]: triggering offboard", ros::this_node::getName().c_str());

  {
    std_srvs::Trigger trigger;

    {
      bool service_call = sch_offboard_.call(trigger);

      if (!service_call || !trigger.response.success) {
        ROS_ERROR("[%s]: offboard service call failed", ros::this_node::getName().c_str());
        return false;
      }
    }
  }

  // | -------------- wait for the takeoff finished ------------- |

  while (ros::ok()) {

    ROS_INFO_THROTTLE(1.0, "[%s]: waiting for the takeoff to finish", ros::this_node::getName().c_str());

    if (sh_control_manager_diag_.getMsg()->flying_normally) {

      ROS_INFO("[%s]: finished", ros::this_node::getName().c_str());
      break;
    }

    ros::Duration(0.01).sleep();
  }

  ros::Duration(1.0).sleep();

  // | -------------------------- goto -------------------------- |

  mrs_msgs::Vec4 goto_cmd;

  {
    goto_cmd.request.goal[0] = 0;
    goto_cmd.request.goal[1] = 0;
    goto_cmd.request.goal[2] = 5.5;
    goto_cmd.request.goal[3] = 2.2;

    ROS_INFO("[%s]: calling goto", ros::this_node::getName().c_str());

    {
      bool service_call = sch_goto_.call(goto_cmd);

      if (!service_call || !goto_cmd.response.success) {
        ROS_ERROR("[%s]: goto service call failed", ros::this_node::getName().c_str());
        return false;
      }
    }
  }

  // | ------------------- check if we are ok ------------------- |

  while (ros::ok()) {

    ROS_INFO_THROTTLE(1.0, "[%s]: checking if we are still flying", ros::this_node::getName().c_str());

    if (!sh_control_manager_diag_.getMsg()->flying_normally) {
      ROS_ERROR("[%s]: not flying normally", ros::this_node::getName().c_str());
      return false;
    }

    if (!sh_control_manager_diag_.getMsg()->tracker_status.have_goal) {
      ROS_INFO("[%s]: goto finished", ros::this_node::getName().c_str());
      break;
    }
  }

  ros::Duration(1.0).sleep();

  // | ---------------------- call landing ---------------------- |

  {
    std_srvs::Trigger trigger;

    {
      bool service_call = sch_land_.call(trigger);

      if (!service_call || !trigger.response.success) {
        ROS_ERROR("[%s]: land service call failed", ros::this_node::getName().c_str());
        return false;
      }
    }
  }

  // | ----------------- wait for LandoffTracker ---------------- |

  while (ros::ok()) {

    ROS_INFO_THROTTLE(1.0, "[%s]: waiting for LandoffTracker", ros::this_node::getName().c_str());

    if (sh_control_manager_diag_.getMsg()->active_tracker == "LandoffTracker") {
      ROS_INFO("[%s]: LandoffTracker detected", ros::this_node::getName().c_str());
      break;
    }
  }

  // | -------------------- wait for landing -------------------- |

  while (ros::ok()) {

    ROS_INFO_THROTTLE(1.0, "[%s]: waiting for landing", ros::this_node::getName().c_str());

    if (sh_control_manager_diag_.getMsg()->output_enabled == false) {
      ROS_INFO("[%s]: landing detected", ros::this_node::getName().c_str());
      return true;
    }
  }

  return false;
}

//}

std::shared_ptr<Tester> tester_;

TEST(TESTSuite, landing_takeoff) {

  bool result = tester_->test();

  if (result) {
    GTEST_SUCCEED();
  } else {
    GTEST_FAIL();
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {

  ros::init(argc, argv, "landoff_tracker_landing_takeoff");

  tester_ = std::make_shared<Tester>();

  testing::InitGoogleTest(&argc, argv);

  Tester tester;

  return RUN_ALL_TESTS();
}
