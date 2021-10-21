cmake_minimum_required(VERSION 3.13...3.19 FATAL_ERROR)
project(calculon VERSION 1.0 LANGUAGES CXX CUDA)

# create main library
file(GLOB_RECURSE LIB_SRCS LIST_DIRECTORIES true src/*.cc)
add_library(calculon ${LIB_SRCS})
target_link_libraries(calculon)
target_include_directories(calculon
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_compile_features(calculon PRIVATE cxx_auto_type)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()
