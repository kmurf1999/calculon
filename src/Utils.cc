#include "../include/supremus/Utils.h"

namespace utils {

int CHOOSE_TABLE[MAX_CHOOSE * MAX_CHOOSE];

void init_choose_table(void) {
  for (int i = 0; i < MAX_CHOOSE; ++i) {
    for (int j = 0; j < MAX_CHOOSE; ++j) {
      CHOOSE_TABLE[i * MAX_CHOOSE + j] = 0;
    }
  }
  for (int i = 0; i < MAX_CHOOSE; ++i) {
    CHOOSE_TABLE[i * MAX_CHOOSE] = 1;
    CHOOSE_TABLE[i * MAX_CHOOSE + i] = 1;
  }
  for (int i = 1; i < MAX_CHOOSE; ++i) {
    for (int j = 1; j < i; ++j) {
      CHOOSE_TABLE[i * MAX_CHOOSE + j] =
          CHOOSE_TABLE[(i - 1) * MAX_CHOOSE + j - 1] +
          CHOOSE_TABLE[(i - 1) * MAX_CHOOSE + j];
    }
  }
}

int choose(int n, int k) {
  return CHOOSE_TABLE[n * MAX_CHOOSE + k];
}

size_t get_hole_index(int c1, int c2) {
  size_t index = 0;
  index += choose(c1, 1);
  index += choose(c2, 2);
  return index;
}

vector<uint64_t> get_next_boards(uint64_t board) {
  int bit_count = __builtin_popcountl(board);

  assert(bit_count == 0 || bit_count == 3 || bit_count == 4);

  vector<uint64_t> next_boards;

  if (bit_count == 0) {
    for (int i = 0; i < constants::CARD_COUNT; i++) {
      for (int j = i + 1; j < constants::CARD_COUNT; j++) {
        for (int k = j + 1; k < constants::CARD_COUNT; k++) {
          uint64_t next_board = (1ull << i) | (1ull << j) | (1ull << k);
          next_boards.push_back(next_board);
        }
      }
    }
    return next_boards;
  } else {
    for (int i = 0; i < constants::CARD_COUNT; i++) {
      uint64_t next_card = 1ull << i;
      if ((next_card & board) == 0) {
        next_boards.push_back(next_card | board);
      }
    }
  }
  return next_boards;
}
} // namespace utils
