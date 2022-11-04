cmake_minimum_required(VERSION 3.23)
project(matrix_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix_calculator main.cpp vector.cpp vector.h matrix.cpp matrix.h Google_tests/test.cpp)
add_subdirectory(Google_tests)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(matrix_calculator ${GTEST_LIBRARIES} pthread)