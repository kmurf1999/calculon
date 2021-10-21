#include <gtest/gtest.h>
#include <calculon/Evaluator.h>
#include <calculon/Utils.h>

#include <iostream>

using namespace std;

TEST(Evaluator, batch_eval) {

  uint8_t board[5] = { 51, 48, 0, 1, 2 };
  // AdAs2s2h2c

  int* hand_values = batch_eval(board);

  for (int i=0; i < 1000; i++) {
    cout << hand_values[i] << ' ';
  }

  EXPECT_EQ(hand_values[utils::get_hole_index(0, 51)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(1, 30)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(2, 30)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 48)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 51)], 0);
}
