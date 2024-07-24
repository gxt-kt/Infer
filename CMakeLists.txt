cmake_minimum_required(VERSION 3.16)
project(infer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(benchmark REQUIRED)
find_package(OpenMP REQUIRED)
find_package(Armadillo REQUIRED)
find_package(glog REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)


include_directories(include)


aux_source_directory(./source/data DIR_DATA)
aux_source_directory(./source/runtime DIR_PARSER)
aux_source_directory(./source/layer/abstract DIR_ABSTRACT_LAYER)
aux_source_directory(./source/layer/details DIR_BINOCULAR_LAYER)
aux_source_directory(./source/parser DIR_PARSER)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(link_lib glog pthread gtest)
set(link_math_lib ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
add_library(${PROJECT_NAME} SHARED ${DIR_DATA} ${DIR_PARSER} ${DIR_ABSTRACT_LAYER} ${DIR_BINOCULAR_LAYER} ${DIR_PARSER})

target_include_directories(${PROJECT_NAME} PUBLIC ${benchmark_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GTest_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${Armadillo_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${link_lib} ${link_math_lib})

enable_testing()
add_subdirectory(test)