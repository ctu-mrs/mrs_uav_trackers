#include <rclcpp/rclcpp.hpp>
#include <rclcpp/time.hpp>

#include <mrs_uav_testing/test_generic.h>

using namespace std::chrono_literals;

class Tester : public mrs_uav_testing::TestGeneric {

public:
  Tester() : mrs_uav_testing::TestGeneric() {
  }

  bool test(void);

  std::shared_ptr<mrs_uav_testing::UAVHandler> uh1_;
  std::shared_ptr<mrs_uav_testing::UAVHandler> uh2_;
};

bool Tester::test(void) {

  {
    auto [uhopt, message] = getUAVHandler("uav1");

    if (!uhopt) {
      RCLCPP_ERROR(node_->get_logger(), "Failed obtain handler for '%s': '%s'", "uav1", message.c_str());
      return false;
    }

    uh1_ = uhopt.value();
  }

  {
    auto [uhopt, message] = getUAVHandler("uav2");

    if (!uhopt) {
      RCLCPP_ERROR(node_->get_logger(), "Failed obtain handler for '%s': '%s'", "uav2", message.c_str());
      return false;
    }

    uh2_ = uhopt.value();
  }

  {
    auto [success, message] = uh1_->activateMidAir();

    if (!success) {
      RCLCPP_ERROR(node_->get_logger(), "uav1 midair activation failed with message: '%s'", message.c_str());
      return false;
    }
  }

  {
    auto [success, message] = uh2_->activateMidAir();

    if (!success) {
      RCLCPP_ERROR(node_->get_logger(), "uav2 midair activation failed with message: '%s'", message.c_str());
      return false;
    }
  }

  if (uh1_->getActiveTracker() != "MpcTracker") {
    RCLCPP_ERROR(node_->get_logger(), "uav1: MpcTracker is not active");
    return false;
  }

  if (uh2_->getActiveTracker() != "MpcTracker") {
    RCLCPP_ERROR(node_->get_logger(), "uav2: MpcTracker is not active");
    return false;
  }

  {
    auto [success, message] = uh1_->gotoRel(20, 0, 0, 0);

    if (success) {
      RCLCPP_ERROR(node_->get_logger(), "goto relative succeeded: '%s'", message.c_str());
      return false;
    }
  }

  this->sleep(5.0);

  if (!uh1_->isFlyingNormally() || !uh2_->isFlyingNormally()) {
    return true;
  } else {
    RCLCPP_ERROR(node_->get_logger(), "both UAVs are flying normally, that is wrong");
    return false;
  }
}

int main(int argc, char *argv[]) {

  rclcpp::init(argc, argv);

  bool test_result = true;

  Tester tester;

  test_result &= tester.test();

  tester.sleep(2.0);

  std::cout << "Test: reporting test results" << std::endl;

  tester.reportTestResult(test_result);

  tester.join();
}
