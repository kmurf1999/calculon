#include <gtest/gtest.h>
#include <calculon/Evaluator.h>
#include <calculon/Utils.h>

#include <iostream>

using namespace std;

TEST(Evaluator, batch_eval) {

  uint64_t board_mask = 0;
  board_mask += 1ull << 51;
  board_mask += 1ull << 48;
  board_mask += 1ull << 0;
  board_mask += 1ull << 1;
  board_mask += 1ull << 2;
  // AdAs2s2h2c

  uint16_t* hand_values = batch_eval(board_mask);

  EXPECT_EQ(hand_values[utils::get_hole_index(0, 51)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(1, 30)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(2, 30)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 48)], 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 51)], 0);
}
