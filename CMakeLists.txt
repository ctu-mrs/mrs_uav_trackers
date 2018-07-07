cmake_minimum_required(VERSION 2.8.3)
project(mrs_trackers)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  geometry_msgs
  tf
  trackers_manager
  std_msgs
  message_generation
  mav_manager
  roscpp
  rospy
  mrs_estimation
  mrs_msgs
  mrs_uav_manager
  quadrotor_msgs
  )

set(CMAKE_CXX_FLAGS "-std=c++11 -Os -fno-diagnostics-color -Wall")
set(CMAKE_C_FLAGS "-Os -fno-diagnostics-color -Wall")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

catkin_package(INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS message_runtime geometry_msgs tf trackers_manager mrs_estimation mrs_uav_manager quadrotor_msgs
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
  src/mpc_tracker/cvxgen_z
  src/mpc_tracker/cvxgen_yaw
  )

# MPC Tracker

add_library(mpc_tracker src/mpc_tracker/mpc_tracker.cpp)

add_library(cvx_wrapper src/mpc_tracker/cvx_wrapper.cpp
  src/mpc_tracker/cvxgen/ldl.c
  src/mpc_tracker/cvxgen/matrix_support.c
  src/mpc_tracker/cvxgen/solver.c
  src/mpc_tracker/cvxgen/util.c
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

add_dependencies(mpc_tracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )

target_link_libraries(mpc_tracker
  ${catkin_LIBRARIES}
  cvx_wrapper
  cvx_wrapper_z
  cvx_wrapper_yaw
  )

# CSV Tracker

add_library(CsvTracker src/csv_tracker/csv_tracker.cpp)
add_dependencies(CsvTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(CsvTracker
  ${catkin_LIBRARIES}
  )

# Linear Tracker

add_library(LinearTracker src/linear_tracker/linear_tracker.cpp)
add_dependencies(LinearTracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(LinearTracker
  ${catkin_LIBRARIES}
  )

#############
## Install ##
#############

install(TARGETS
  mpc_tracker
  CsvTracker
  LinearTracker
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
  linear_tracker.xml
  DESTINATION
  ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
