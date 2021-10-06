cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(calculon VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


enable_testing()

set(CALCULON_LIB calculon)
set(CALCULON_TEST calculon_test)

add_subdirectory(libs/ompeval)
include_directories(libs/ompeval/include)

add_subdirectory(libs/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(src)
include_directories(include)

add_subdirectory(test)
