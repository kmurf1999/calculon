file(GLOB_RECURSE SRCS LIST_DIRECTORIES true *.cc)
add_executable(${CMAKE_PROJECT_NAME}tst ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME}tst gtest_main supremus ompeval)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}tst)
