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
  mrs_cvxy
  )

set(CMAKE_CXX_FLAGS "-std=c++11 -Os -fno-diagnostics-color -Wall")

# include Eigen3
find_package(Eigen3 REQUIRED)
set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIRS})
set(Eigen_LIBRARIES ${EIGEN3_LIBRARIES})

catkin_package(INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS message_runtime geometry_msgs tf trackers_manager mrs_estimation
  DEPENDS Eigen
  )

###########
## Build ##
###########

include_directories(
  include
  ${EIGEN_INCLUDE_DIR} 
  ${catkin_INCLUDE_DIRS}
  src/${PROJECT_NAME}/cvxgen
  src/${PROJECT_NAME}/cvxgen_xy
  )


add_library(mpc_tracker src/${PROJECT_NAME}/mpc_tracker.cpp
  src/${PROJECT_NAME}/cvxgen/ldl.c
  src/${PROJECT_NAME}/cvxgen/matrix_support.c
  src/${PROJECT_NAME}/cvxgen/solver.c
  src/${PROJECT_NAME}/cvxgen/util.c
  )

add_library(cvx_wrapper src/${PROJECT_NAME}/cvx_wrapper.cpp
  src/${PROJECT_NAME}/cvxgen/ldl.c
  src/${PROJECT_NAME}/cvxgen/matrix_support.c
  src/${PROJECT_NAME}/cvxgen/solver.c
  src/${PROJECT_NAME}/cvxgen/util.c
  )

add_dependencies(mpc_tracker
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  )
target_link_libraries(mpc_tracker ${catkin_LIBRARIES} cvx_wrapper
  )
#############
## Install ##
#############

install(TARGETS
  mpc_tracker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
  )

install(FILES mrs_trackers.xml DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
