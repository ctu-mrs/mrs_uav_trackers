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
  mrs_mav_manager
  )

set(CMAKE_CXX_FLAGS "-std=c++11 -Os -fno-diagnostics-color -Wall")
set(CMAKE_C_FLAGS "-Os -fno-diagnostics-color -Wall")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
  CATKIN_DEPENDS message_runtime geometry_msgs tf mrs_lib mrs_mav_manager mrs_msgs
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
  src/mpc_tracker/cvxgen_xy
  src/mpc_tracker/cvxgen_z
  src/mpc_tracker/cvxgen_yaw
  )

# MPC Tracker

add_library(MpcTracker src/mpc_tracker/mpc_tracker.cpp)

add_library(cvx_wrapper src/mpc_tracker/cvx_wrapper.cpp
  src/mpc_tracker/cvxgen/ldl.c
  src/mpc_tracker/cvxgen/matrix_support.c
  src/mpc_tracker/cvxgen/solver.c
  src/mpc_tracker/cvxgen/util.c
  )

add_library(cvx_wrapper_xy src/mpc_tracker/cvx_wrapper_xy.cpp
  src/mpc_tracker/cvxgen_xy/ldl.c
  src/mpc_tracker/cvxgen_xy/matrix_support.c
  src/mpc_tracker/cvxgen_xy/solver.c
  src/mpc_tracker/cvxgen_xy/util.c
  )

add_library(cvx_wrapper_z src/mpc_tracker/cvx_wrapper_z.cpp
  src/mpc_tracker/cvxgen_z/ldl.c
  src/mpc_tracker/cvxgen_z/matrix_support.c
  src/mpc_tracker/cvxgen_z/solver.c
  src/mpc_tracker/cvxgen_z/util.c
  )

add_library(cvx_wrapper_yaw src/mpc_tracker/cvx_wrapper_yaw.cpp
  src/mpc_tracker/cvxgen_yaw/ldl.c
  src/mpc_tracker/cvxgen_yaw/matrix_support.c
  src/mpc_tracker/cvxgen_yaw/solver.c
  src/mpc_tracker/cvxgen_yaw/util.c
  )

add_dependencies(MpcTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(MpcTracker
  ${catkin_LIBRARIES}
  cvx_wrapper
  cvx_wrapper_xy
  cvx_wrapper_z
  cvx_wrapper_yaw
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
