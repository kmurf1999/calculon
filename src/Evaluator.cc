#include "calculon/Evaluator.h"

int HR[32487834];

void init_hand_ranks(void) {
  memset(HR, 0, sizeof(HR));
  FILE *fin = fopen("/home/kmurf/Documents/calculon/HandRanks.dat", "r");
  size_t bytesread = fread(HR, sizeof(HR), 1, fin);
  fclose(fin);
}

int *batch_eval(uint8_t board[5]) {
  int *hand_values = new int[1326];
  std::fill(hand_values, hand_values + 1326, 0);
  // create board mask
  uint64_t board_mask = 0;
  for (int i = 0; i < 5; i++) {
    board_mask |= 1ull << board[i];
  }
  // get board value
  int p = HR[54 + board[0]];
  p = HR[p + board[1] + 1];
  p = HR[p + board[2] + 1];
  p = HR[p + board[3] + 1];
  p = HR[p + board[4] + 1];
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
