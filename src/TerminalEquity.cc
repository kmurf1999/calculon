#include "calculon/TerminalEquity.h"

#include <iostream>

using namespace std;

TerminalEquity::TerminalEquity() {
  call_matrix = torch::zeros({1326, 1326}, torch::kF32 ).cuda();
  fold_matrix = torch::ones({1326, 1326}, torch::kF32).cuda();
  block_matrix = torch::ones({1326, 1326}, torch::kF32).cuda();
  set_block_matrix();
}

void TerminalEquity::set_board(torch::Tensor board) {
  this->board = board.cuda();
  possible_hand_indexes = utils::get_possible_hand_indexes(board).cuda();
  set_fold_matrix();
  set_call_matrix();
}

void TerminalEquity::set_call_matrix() {
  int board_cnt = board.size(0);
  if (board_cnt == 5) {
    get_last_round_call_matrix(call_matrix, this->board);
  } else if (board_cnt == 4 || board_cnt == 3) {
    // enumerate
  } else if (board_cnt == 0) {
    // use push-fold equity table
  } else {
    assert(false);
  }
}

void TerminalEquity::set_fold_matrix() { handle_blocking_cards(fold_matrix); }

void TerminalEquity::set_block_matrix() {
  for (int i = 0; i < 52; i++) {
    for (int j = i + 1; j < 52; j++) {
      auto idx1 = utils::get_hole_index(i, j);
      for (int k = 0; k < 52; k++) {
        for (int l = k + 1; l < 52; l++) {
          auto idx2 = utils::get_hole_index(k, l);
          if (i == k || i == l || j == k || j == l) {
            block_matrix[idx1][idx2] = 0;
            block_matrix[idx2][idx1] = 0;
          }
        }
      }
    }
  }
}

void TerminalEquity::get_last_round_call_matrix(torch::Tensor equity_matrix,
                                                torch::Tensor board) {
  // get last round call matrix
  auto strength = batch_eval(board).cuda();
  auto strength_view_1 = strength.view({1326, 1}).expand_as(equity_matrix);
  auto strength_view_2 = strength.view({1, 1326}).expand_as(equity_matrix);

  equity_matrix += torch::gt(strength_view_1, strength_view_2).type_as(equity_matrix);
  equity_matrix -= torch::lt(strength_view_1, strength_view_2).type_as(equity_matrix);
  
  handle_blocking_cards(equity_matrix);
}

void TerminalEquity::handle_blocking_cards(torch::Tensor equity_matrix) {
  auto possible_hand_matrix =
      possible_hand_indexes.view({1326, 1}).expand({1326, 1326});
  equity_matrix *= possible_hand_matrix;
  possible_hand_matrix =
      possible_hand_indexes.view({1, 1326}).expand({1326, 1326});
  equity_matrix *= possible_hand_matrix;

  equity_matrix *= block_matrix;
}

void TerminalEquity::call_value(torch::Tensor ranges, torch::Tensor result) {
  torch::matmul_out(result, ranges, call_matrix);
}

void TerminalEquity::fold_value(torch::Tensor ranges, torch::Tensor result) {
  torch::matmul_out(result, ranges, fold_matrix);
}
