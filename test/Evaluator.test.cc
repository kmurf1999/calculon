#include <calculon/Evaluator.h>
#include <calculon/Utils.h>
#include <gtest/gtest.h>
#include <torch/torch.h>

#include <iostream>

using namespace std;

TEST(Evaluator, batch_eval) {

  auto board = torch::tensor({51, 48, 0, 1, 2}, { torch::kInt8 });
  // AdAs2s2h2c

  torch::Tensor hand_values = batch_eval(board);

  EXPECT_EQ(hand_values[utils::get_hole_index(0, 51)].item<int>(), 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(1, 30)].item<int>(), 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(2, 30)].item<int>(), 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 48)].item<int>(), 0);
  EXPECT_EQ(hand_values[utils::get_hole_index(30, 51)].item<int>(), 0);
}
