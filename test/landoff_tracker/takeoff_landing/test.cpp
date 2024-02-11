#include <gtest/gtest.h>

#include <mrs_uav_testing/test_generic.h>

class Tester : public mrs_uav_testing::TestGeneric {

public:
  bool test();
};

bool Tester::test() {

  std::shared_ptr<mrs_uav_testing::UAVHandler> uh;

  {
    auto [uhopt, message] = getUAVHandler(_uav_name_);

    if (!uhopt) {
      ROS_ERROR("[%s]: Failed obtain handler for '%s': '%s'", ros::this_node::getName().c_str(), _uav_name_.c_str(), message.c_str());
      return false;
    }

    uh = uhopt.value();
  }

  // | ------------------------- takeoff ------------------------ |

  {
    auto [success, message] = uh->takeoff();

    if (!success) {
      ROS_ERROR("[%s]: takeoff failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  this->sleep(1.0);

  if (!uh->isFlyingNormally()) {
    ROS_ERROR("[%s]: not flying normally", ros::this_node::getName().c_str());
    return false;
  }

  // | --------------------- goto somewhere --------------------- |

  {
    auto [success, message] = uh->gotoRel(10, 1, 2, 1.5);

    if (!success) {
      ROS_ERROR("[%s]: goto failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  this->sleep(1.0);

  if (!uh->isFlyingNormally()) {
    ROS_ERROR("[%s]: not flying normally", ros::this_node::getName().c_str());
    return false;
  }

  // | -------------------------- land -------------------------- |

  {
    auto [success, message] = uh->land();

    if (!success) {
      ROS_ERROR("[%s]: landing failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  return true;
}


TEST(TESTSuite, test) {

  Tester tester;

  bool result = tester.test();

  if (result) {
    GTEST_SUCCEED();
  } else {
    GTEST_FAIL();
  }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {

  ros::init(argc, argv, "test");

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
