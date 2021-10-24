cmake_minimum_required(VERSION 3.13...3.19 FATAL_ERROR)
project(calculon VERSION 1.0 LANGUAGES CXX CUDA)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/extern/libtorch)

find_package(Torch CONFIG REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# create main library
file(GLOB_RECURSE LIB_SRCS LIST_DIRECTORIES true src/*.cc)
add_library(calculon ${LIB_SRCS})
target_link_libraries(calculon ${TORCH_LIBRARIES})
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
