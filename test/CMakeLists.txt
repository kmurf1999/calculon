file(GLOB_RECURSE SRCS LIST_DIRECTORIES true *.cc)
add_executable(${CALCULON_TEST} ${SRCS})
target_link_libraries(${CALCULON_TEST} gtest_main ${CALCULON_LIB} ompeval)

include(GoogleTest)
gtest_discover_tests(${CALCULON_TEST})
