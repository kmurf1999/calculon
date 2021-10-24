#ifndef __TERMINAL_EQUITY_H__
#define __TERMINAL_EQUITY_H__

#include "calculon/Evaluator.h"
#include "calculon/Utils.h"
#include <assert.h>
#include <torch/torch.h>

class TerminalEquity {
public:
  TerminalEquity();
  void set_board(torch::Tensor board);

  void call_value(torch::Tensor range, torch::Tensor result);
  void fold_value(torch::Tensor range, torch::Tensor result);
  torch::Tensor board;
  torch::Tensor block_matrix;
  torch::Tensor fold_matrix;
  torch::Tensor call_matrix;
  torch::Tensor possible_hand_indexes;

  void get_last_round_call_matrix(torch::Tensor equity_matrix,
                                  torch::Tensor board);
  void set_call_matrix();
  void set_fold_matrix();
  void set_block_matrix();
  void handle_blocking_cards(torch::Tensor equity_matrix);
};

#endif // __TERMINAL_EQUITY_H__
