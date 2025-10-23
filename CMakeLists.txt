cmake_minimum_required(VERSION 3.5)
project(mrs_uav_trackers)

# set the correct standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1 == use rclcpp::Timer implementation
# 0 == use MRS's thread timer implementation
set(USE_ROS_TIMER 0)

if(${USE_ROS_TIMER})
  MESSAGE(WARNING "[mrs_uav_trackers]: Compiling with ROS Timers. This can cause high CPU load in runtime.")
endif()

# set the compile options to show code warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

if(ENABLE_COVERAGE)
  message(WARNING "building for coverage, the performance might be limited")

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs")

  add_definitions("-O1")
  add_definitions("-g")
endif()

set(DEPENDENCIES
  rclcpp
  rclcpp_components
  mrs_msgs
  mrs_lib
  pluginlib
  geometry_msgs
  sensor_msgs
  mrs_uav_managers
  Eigen3
  mrs_mpc_solvers
)

set(LIBRARIES
  MrsUavTrackers_LandoffTracker
  MrsUavTrackers_LineTracker
  MrsUavTrackers_MpcTracker
  MrsUavTrackers_MidairActivationTracker
  MrsUavTrackers_FlipTracker
  )

foreach(DEP IN LISTS DEPENDENCIES)
  find_package(${DEP} REQUIRED)
endforeach()

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${mrs_lib_INCLUDE_DIRS}
  ${mrs_uav_managers_INCLUDE_DIRS}
  ${mrs_mpc_solvers_INCLUDE_DIRS}
)

# Landoff Tracker

add_library(MrsUavTrackers_LandoffTracker SHARED
  src/landoff_tracker.cpp
  )

ament_target_dependencies(MrsUavTrackers_LandoffTracker
  ${DEPENDENCIES}
  )

target_compile_definitions(MrsUavTrackers_LandoffTracker PRIVATE USE_ROS_TIMER=${USE_ROS_TIMER})

# Line Tracker

add_library(MrsUavTrackers_LineTracker SHARED
  src/line_tracker.cpp
  )

ament_target_dependencies(MrsUavTrackers_LineTracker
  ${DEPENDENCIES}
  )

target_compile_definitions(MrsUavTrackers_LineTracker PRIVATE USE_ROS_TIMER=${USE_ROS_TIMER})

# MPC Tracker

add_library(MrsUavTrackers_MpcTracker SHARED
  src/mpc_tracker.cpp
  )

ament_target_dependencies(MrsUavTrackers_MpcTracker
  ${DEPENDENCIES}
  )

target_link_libraries(MrsUavTrackers_MpcTracker
  ${MPC_CONTROLLER_SOLVER_BIN}
  )

target_compile_definitions(MrsUavTrackers_MpcTracker PRIVATE USE_ROS_TIMER=${USE_ROS_TIMER})

# Midair Activation Tracker

add_library(MrsUavTrackers_MidairActivationTracker SHARED
  src/midair_activation_tracker.cpp
  )

ament_target_dependencies(MrsUavTrackers_MidairActivationTracker
  ${DEPENDENCIES}
  )

target_compile_definitions(MrsUavTrackers_MidairActivationTracker PRIVATE USE_ROS_TIMER=${USE_ROS_TIMER})

# Flip Tracker

add_library(MrsUavTrackers_FlipTracker SHARED
  src/flip_tracker.cpp
  )

ament_target_dependencies(MrsUavTrackers_FlipTracker
  ${DEPENDENCIES}
  )

target_compile_definitions(MrsUavTrackers_FlipTracker PRIVATE USE_ROS_TIMER=${USE_ROS_TIMER})

## --------------------------------------------------------------
## |                       export plugins                       |
## --------------------------------------------------------------

# <package of the base class>, <relative path to the xml>
pluginlib_export_plugin_description_file(mrs_uav_managers plugins.xml)

## --------------------------------------------------------------
## |                           testing                          |
## --------------------------------------------------------------

if(ENABLE_TESTS)

  add_subdirectory(test)

endif()

## --------------------------------------------------------------
## |                           install                          |
## --------------------------------------------------------------

ament_export_libraries(
  ${LIBRARIES}
)

install(
  TARGETS ${LIBRARIES}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY scripts
  USE_SOURCE_PERMISSIONS
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_include_directories(
  include
)

ament_export_targets(
  export_${PROJECT_NAME} HAS_LIBRARY_TARGET
)

ament_export_dependencies(
  ${DEPENDENCIES}
)

ament_package()
