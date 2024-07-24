cmake_minimum_required(VERSION 3.16)
project(infer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

find_package(glog REQUIRED)

include_directories(include)

set(link_lib glog pthread gtest)
set(link_math_lib armadillo blas lapack)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${project_name} main.cpp include/ops/sigmoid_op.hpp include/layer/sigmoid_layer.hpp include/ops/maxpooling_op.hpp include/layer/maxpooling_layer.hpp)

target_include_directories(${project_name} PUBLIC /usr/include/armadillo_bits)
target_include_directories(${project_name} PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(${project_name} ${link_lib} ${link_math_lib})

enable_testing()
# add_subdirectory(test)