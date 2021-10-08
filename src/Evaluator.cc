#include "calculon/Evaluator.h"

uint16_t* batch_eval(uint64_t board_mask) {
  assert(__builtin_popcountl(board_mask) == 5);

  uint16_t* hand_values = new uint16_t[1326];
  std::fill(hand_values, hand_values + 1326, 0);

  omp::Hand board = omp::Hand::empty();
  for (int i = 0; i < constants::CARD_COUNT; ++i) {
    if ((1ull << i) & board_mask) {
      board += omp::Hand(i);
    }
  }

  for (uint64_t c1 = 0; c1 < constants::CARD_COUNT; ++c1) {
    if ((1ull << c1) & board_mask)
      continue;
    for (uint64_t c2 = c1 + 1; c2 < constants::CARD_COUNT; ++c2) {
      if ((1ull << c2) & board_mask)
        continue;
      size_t hole_idx = utils::get_hole_index(c1, c2);
      hand_values[hole_idx] =
          EVAL.evaluate(board + omp::Hand(c1) + omp::Hand(c2));
    }
  }

  return hand_values;
}
