include(FetchContent)
include(GoogleTest)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SRCS LIST_DIRECTORIES true *.cc)
add_executable(calculon_test ${SRCS})
target_compile_features(calculon_test PRIVATE cxx_auto_type)
target_link_libraries(calculon_test gtest_main supremus ompeval)

gtest_discover_tests(calculon_test)
