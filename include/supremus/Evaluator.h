#ifndef __EVALUATE_H__
#define __EVALUATE_H__

#include <algorithm>
#include <assert.h>
#include <cstdint>
#include <omp/HandEvaluator.h>
#include <cstring>
#include <iostream>

#include "Constants.h"
#include "Utils.h"

static const omp::HandEvaluator EVAL;

// evaluate all hands on board and move output to out
uint16_t* batch_eval(uint64_t board_mask);

#endif // __EVALUATE_H__
