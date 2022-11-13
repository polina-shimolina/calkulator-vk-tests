cmake_minimum_required(VERSION 3.23)
project(matrix_calculator)

set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(untitled main.cpp Matrix.cpp Matrix.h Vector.cpp Vector.h Google_Tests_run test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
