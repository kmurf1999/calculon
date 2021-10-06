#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <cstdint>

namespace constants {

static const uint8_t CARD_COUNT = 52;
static const uint8_t MAX_PLAYERS = 2;
static const uint32_t STACK = 20000;
static const uint32_t BIG_BLIND = 100;
static const uint32_t SMALL_BLIND = 50;
static const uint8_t NUM_STREETS = 4;
static const uint8_t BET_CAP = 3;

// player indexes 1
enum Player { P1 = 0, P2, CHANCE };

enum Street { PREFLOP = 0, FLOP, TURN, RIVER };

} // namespace constants

#endif //__CONSTANTS_H__
