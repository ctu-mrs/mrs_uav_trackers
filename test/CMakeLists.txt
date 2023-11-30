find_package(rostest REQUIRED)

# MPC Tracker basic

add_rostest_gtest(MpcTracker_basic
  mpc_tracker/basic/mpc_tracker_basic.test
  mpc_tracker/basic/test.cpp
  )

target_link_libraries(MpcTracker_basic
  ${catkin_LIBRARIES}
  )

add_dependencies(MpcTracker_basic
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

# LandoffTracker takeoff & landing

add_rostest_gtest(LandoffTracker_takeoff_landing
  landoff_tracker/takeoff_landing/landoff_tracker_takeoff_landing.test
  landoff_tracker/takeoff_landing/test.cpp
  )

target_link_libraries(LandoffTracker_takeoff_landing
  ${catkin_LIBRARIES}
  )

add_dependencies(LandoffTracker_takeoff_landing
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

# LineTracker basic

add_rostest_gtest(LineTracker_basic
  line_tracker/basic/line_tracker_basic.test
  line_tracker/basic/test.cpp
  )

target_link_libraries(LineTracker_basic
  ${catkin_LIBRARIES}
  )

add_dependencies(LineTracker_basic
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )
