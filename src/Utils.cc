#include "Utils.h"

namespace utils {
vector<uint64_t> get_next_boards(uint64_t board) {
  int bit_count = __popcount(board);

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
