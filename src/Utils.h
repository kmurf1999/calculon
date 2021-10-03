#ifndef __UTILS_H__
#define __UTILS_H__

#include "Constants.h"
#include <bit>
#include <cstdint>
#include <vector>
#include <assert.h>

using namespace std;

namespace utils {

vector<uint64_t> get_next_boards(uint64_t board);

} // namespace utils

#endif // __UTILS_H__
