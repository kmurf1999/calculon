cmake_minimum_required(VERSION 3.13...3.19 FATAL_ERROR)
project(calculon VERSION 1.0 LANGUAGES CXX CUDA)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

file(GLOB_RECURSE LIB_SRCS LIST_DIRECTORIES true *.cc)
add_library(calculon ${LIB_SRCS})

target_include_directories(calculon
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(calculon PRIVATE cxx_auto_type)

enable_testing()
add_subdirectory(test)
