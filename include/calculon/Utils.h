#ifndef __UTILS_H__
#define __UTILS_H__

#include "Constants.h"
#include <bit>
#include <cstdint>
#include <vector>
#include <assert.h>
#include <torch/torch.h>

using namespace std;

#define MAX_CHOOSE 52

namespace utils {

vector<uint64_t> get_next_boards(uint64_t board);

torch::Tensor get_possible_hand_indexes(torch::Tensor board);

extern int CHOOSE_TABLE[];

void init_choose_table (void) __attribute__((constructor));

// get the index 0->1326 of two hole cards
// c1 != c2 and c1 < c2
size_t get_hole_index(int c1, int c2);


} // namespace utils

#endif // __UTILS_H__
