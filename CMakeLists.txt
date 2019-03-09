cmake_minimum_required(VERSION 2.8.3)
project(mrs_trackers)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  geometry_msgs
  tf
  std_msgs
  message_generation
  roscpp
  rospy
  mrs_lib
  mrs_msgs
  mrs_uav_manager
  )

# -march=native flag must be set either in all or none nodes that are linked together, otherwise segfaults due to mismatched vectorization of Eigen occur
set(CMAKE_CXX_FLAGS "-std=c++17 -Os -fno-diagnostics-color -Wall -march=native")
set(CMAKE_C_FLAGS "-Os -fno-diagnostics-color -Wall -march=native")
# set(CMAKE_CXX_FLAGS "-std=c++17 -Os -fno-diagnostics-color -Wall")
# set(CMAKE_C_FLAGS "-Os -fno-diagnostics-color -Wall")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
  CATKIN_DEPENDS message_runtime geometry_msgs tf mrs_lib mrs_uav_manager mrs_msgs
  DEPENDS Eigen
  )

###########
## Build ##
###########

include_directories(
  include
  ${EIGEN_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
  src/mpc_tracker/cvxgen
  )

# MPC Tracker

add_library(MpcTracker src/mpc_tracker/mpc_tracker.cpp)

add_library(cvx_wrapper src/mpc_tracker/cvx_wrapper.cpp
  src/mpc_tracker/cvxgen/ldl.c
  src/mpc_tracker/cvxgen/matrix_support.c
  src/mpc_tracker/cvxgen/solver.c
  src/mpc_tracker/cvxgen/util.c
  )

add_dependencies(MpcTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MpcTracker
  ${catkin_LIBRARIES}
  cvx_wrapper
  )

# CSV Tracker

add_library(CsvTracker
  src/csv_tracker/csv_tracker.cpp
  )
add_dependencies(CsvTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(CsvTracker
  ${catkin_LIBRARIES}
  )

# Line Tracker

add_library(LineTracker
  src/line_tracker/line_tracker.cpp
  )
add_dependencies(LineTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(LineTracker
  ${catkin_LIBRARIES}
  )

# Landoff Tracker

add_library(LandoffTracker
  src/landoff_tracker/landoff_tracker.cpp
  )
add_dependencies(LandoffTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(LandoffTracker
  ${catkin_LIBRARIES}
  )

# Joy Tracker

add_library(JoyTracker
  src/joy_tracker/joy_tracker.cpp
  )
add_dependencies(JoyTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(JoyTracker
  ${catkin_LIBRARIES}
  )

#############
## Install ##
#############

install(TARGETS
  MpcTracker
  CsvTracker
  LineTracker
  LandoffTracker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
  )

install(FILES
  mrs_trackers.xml
  csv_tracker.xml
  line_tracker.xml
  landoff_tracker.xml
  DESTINATION
  ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
