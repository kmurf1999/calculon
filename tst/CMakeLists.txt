file(GLOB_RECURSE SRCS LIST_DIRECTORIES true *.cc)
add_executable(testsupremus ${SRCS})
target_link_libraries(testsupremus gtest_main libsupremus)

include(GoogleTest)
gtest_discover_tests(testsupremus)
