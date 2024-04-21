#include <gtest/gtest.h>

#include <mrs_uav_testing/test_generic.h>

class Tester : public mrs_uav_testing::TestGeneric {

public:
  bool test();
};

bool Tester::test() {

  std::shared_ptr<mrs_uav_testing::UAVHandler> uh1;
  std::shared_ptr<mrs_uav_testing::UAVHandler> uh2;

  {
    auto [uhopt, message] = getUAVHandler("uav1");

    if (!uhopt) {
      ROS_ERROR("[%s]: Failed obtain handler for uav1: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }

    uh1 = uhopt.value();
  }

  {
    auto [uhopt, message] = getUAVHandler("uav2");

    if (!uhopt) {
      ROS_ERROR("[%s]: Failed obtain handler for uav2: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }

    uh2 = uhopt.value();
  }

  {
    auto [success, message] = uh1->activateMidAir();

    if (!success) {
      ROS_ERROR("[%s]: uav1 midair activation failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  {
    auto [success, message] = uh2->activateMidAir();

    if (!success) {
      ROS_ERROR("[%s]: uav2 midair activation failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  if (uh1->getActiveTracker() != "MpcTracker") {
    ROS_ERROR("[%s]: uav1: MpcTracker is not active", ros::this_node::getName().c_str());
    return false;
  }

  if (uh2->getActiveTracker() != "MpcTracker") {
    ROS_ERROR("[%s]: uav2: MpcTracker is not active", ros::this_node::getName().c_str());
    return false;
  }

  {
    auto [success, message] = uh1->gotoRel(20, 0, 0, 0);

    if (!success) {
      ROS_ERROR("[%s]: goto failed with message: '%s'", ros::this_node::getName().c_str(), message.c_str());
      return false;
    }
  }

  this->sleep(5.0);

  if (uh1->isFlyingNormally() && uh2->isFlyingNormally()) {
    return true;
  } else {
    ROS_ERROR("[%s]: not flying normally", ros::this_node::getName().c_str());
    return false;
  }
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
