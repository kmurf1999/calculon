cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(supremus VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


enable_testing()

add_subdirectory(libs/ompeval)
include_directories(libs/ompeval/include)

add_subdirectory(libs/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(src)
include_directories(include)

add_subdirectory(test)
