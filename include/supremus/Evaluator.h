#ifndef __EVALUATE_H__
#define __EVALUATE_H__

#include <cstdint>

#include <omp/HandEvaluator.h>

// evaluate all hands on board and move output to out
void batch_eval(uint64_t board, uint16_t* hand_values);

#endif // __EVALUATE_H__
