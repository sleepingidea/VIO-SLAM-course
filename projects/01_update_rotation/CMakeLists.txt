
cmake_minimum_required(VERSION 2.8.3)
project(update_rotation)

find_package(Eigen3 REQUIRED)
include_directories(
    ${Eigen3_INCLUDE_DIRS}
)
set(Sophus_DIR  Sophus/build) 
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable(update_rotation_node  update_rotation.cpp)
target_link_libraries(update_rotation_node  ${Sophus_LIBRARIES})
