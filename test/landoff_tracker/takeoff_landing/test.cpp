#include <rclcpp/rclcpp.hpp>
#include <rclcpp/time.hpp>

#include <mrs_uav_testing/test_generic.h>

using namespace std::chrono_literals;

class Tester : public mrs_uav_testing::TestGeneric {

public:
  Tester() : mrs_uav_testing::TestGeneric() {
  }

  bool test(void);
};

bool Tester::test(void) {

  const std::string uav_name = "uav1";

  std::shared_ptr<mrs_uav_testing::UAVHandler> uh;

  {
    auto [uhopt, message] = getUAVHandler(uav_name);

    if (!uhopt) {
      RCLCPP_ERROR(node_->get_logger(), "Failed obtain handler for '%s': '%s'", uav_name.c_str(), message.c_str());
      return false;
    }

    uh = uhopt.value();
  }

  // | ------------------------- takeoff ------------------------ |

  {
    auto [success, message] = uh->takeoff();

    if (!success) {
      RCLCPP_ERROR(node_->get_logger(), "takeoff failed with message: '%s'", message.c_str());
      return false;
    }
  }

  this->sleep(1.0);

  if (!uh->isFlyingNormally()) {
    RCLCPP_ERROR(node_->get_logger(), "not flying normally");
    return false;
  }

  // | --------------------- goto somewhere --------------------- |

  {
    auto [success, message] = uh->gotoRel(10, 1, 2, 1.5);

    if (!success) {
      RCLCPP_ERROR(node_->get_logger(), "goto failed with message: '%s'", message.c_str());
      return false;
    }
  }

  this->sleep(1.0);

  if (!uh->isFlyingNormally()) {
    RCLCPP_ERROR(node_->get_logger(), "not flying normally");
    return false;
  }

  // | -------------------------- land -------------------------- |

  {
    auto [success, message] = uh->land();

    if (!success) {
      RCLCPP_ERROR(node_->get_logger(), "landing failed with message: '%s'", message.c_str());
      return false;
    }
  }

  return true;
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
