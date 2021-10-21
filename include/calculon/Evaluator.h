#ifndef __EVALUATE_H__
#define __EVALUATE_H__

#include <algorithm>
#include <assert.h>
#include <cstdint>
#include <cstring>
#include <iostream>

#include "Constants.h"
#include "Utils.h"

// The handranks lookup table- loaded from HANDRANKS.DAT.
extern int HR[];
void init_hand_ranks (void) __attribute__((constructor));

// evaluate all hands on board and move output to out
int* batch_eval(uint8_t board[5]);

#endif // __EVALUATE_H__
