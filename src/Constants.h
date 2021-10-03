#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <cstdint>

namespace constants {

inline constexpr uint8_t CARD_COUNT = 52;
inline constexpr uint8_t MAX_PLAYERS = 2;
inline constexpr uint32_t STACK = 20000;
inline constexpr uint32_t BIG_BLIND = 100;
inline constexpr uint32_t SMALL_BLIND = 50;
inline constexpr uint8_t NUM_STREETS = 4;
inline constexpr uint8_t BET_CAP = 3;

// player indexes 1
enum Player { P1 = 0, P2, CHANCE };

enum Street { PREFLOP = 0, FLOP, TURN, RIVER };

} // namespace constants

#endif //__CONSTANTS_H__
