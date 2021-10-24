#include "calculon/Evaluator.h"

int HR[32487834];

void init_hand_ranks(void) {
  memset(HR, 0, sizeof(HR));
  FILE *fin = fopen("/home/kmurf/Documents/calculon/HandRanks.dat", "r");
  size_t bytesread = fread(HR, sizeof(HR), 1, fin);
  fclose(fin);
}

torch::Tensor batch_eval(torch::Tensor board) {

  assert(board.size(0) == 5);

  torch::Tensor hand_values = torch::zeros(1326);
  // create board mask
  uint64_t board_mask = 0;
  for (int i = 0; i < 5; i++) {
    board_mask |= 1ull << board[i].item<int>();
  }
  // get board value
  int p = HR[54 + board[0].item<int>()];
  p = HR[p + board[1].item<int>() + 1];
  p = HR[p + board[2].item<int>() + 1];
  p = HR[p + board[3].item<int>() + 1];
  p = HR[p + board[4].item<int>() + 1];
  // iterate over hole cards
  for (uint64_t c1 = 0; c1 < constants::CARD_COUNT; ++c1) {
    if ((1ull << c1) & board_mask)
      continue;
    for (uint64_t c2 = c1 + 1; c2 < constants::CARD_COUNT; ++c2) {
      if ((1ull << c2) & board_mask)
        continue;
      size_t hole_idx = utils::get_hole_index(c1, c2);
      int value = HR[p + c1 + 1];
      value = HR[value + c2 + 1];
      hand_values[hole_idx] = value;
    }
  }
  return hand_values;
}
