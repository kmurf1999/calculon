add_subdirectory("${CMAKE_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_executable(calculon_test
  BetSizing.test.cc
  Evaluator.test.cc
  Utils.test.cc
  TreeBuilder.test.cc
  TerminalEquity.test.cc
)
target_compile_features(calculon_test PRIVATE cxx_auto_type)
target_link_libraries(calculon_test calculon gtest gmock gtest_main ${TORCH_LIBARIRES})

gtest_discover_tests(calculon_test)
