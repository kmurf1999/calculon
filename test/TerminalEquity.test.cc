#include <calculon/TerminalEquity.h>
#include <gtest/gtest.h>

#include <iostream>

using namespace std;

TEST(TerminalEquity, constructor) {
  auto te = new TerminalEquity();
}

TEST(TerminalEquity, set_board) {
  auto board = torch::tensor({ 0, 10, 2, 30, 50 }, { torch::kInt8 });
  auto te = new TerminalEquity();
  te->set_board(board);
}

TEST(TerminalEquity, call_value) {
  auto board = torch::tensor({ 0, 10, 2, 30, 50 }, { torch::kInt8 });
  auto te = new TerminalEquity();
  te->set_board(board);

  auto ranges = torch::ones({ 2, 1326 }, torch::kF32).cuda();
  ranges *= 1.0 / 1326;
  auto value = torch::zeros({ 2, 1326 }).cuda();

  te->call_value(ranges, value);

  cout << value << endl;
}
