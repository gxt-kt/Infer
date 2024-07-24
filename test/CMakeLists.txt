find_package(GTest REQUIRED)

set(link_lib glog gtest pthread)
set(link_math_lib armadillo blas lapack)

set(link_lib glog gtest)
set(link_math_lib ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

set(TEST_SRC 
  test_main.cpp
  test_tensor.cpp
  test_load_data.cpp
)
add_executable(test_infer ${TEST_SRC})

link_directories(/usr/local/lib/)
# target_link_libraries(test_infer ${OpenCV_LIBS})
target_link_directories(test_infer PUBLIC ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(test_infer infer)
target_link_libraries(test_infer ${link_lib} ${link_math_lib})

target_include_directories(test_infer PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(test_infer PUBLIC ${GTest_INCLUDE_DIR})
target_include_directories(test_infer PUBLIC ${Armadillo_INCLUDE_DIR})
