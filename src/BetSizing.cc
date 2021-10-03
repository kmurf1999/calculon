#include "BetSizing.h"

BetSizing::BetSizing(vector<vector<double>> pot_fractions) {
  // assert(pot_fractions.size() >= 1);
  // for (auto fractions : pot_fractions) {
  //   assert(fractions.size() >= 1);
  // }
  this->pot_fractions = pot_fractions;
}

vector<array<uint32_t, 2>> BetSizing::get_possible_bets(Node *node) {
  vector<array<uint32_t, 2>> possible_bets;
  uint8_t current_player = node->current_player;
  uint8_t opponent = 1 - current_player;
  uint32_t current_bet = node->bets[current_player];
  uint32_t opponent_bet = node->bets[opponent];

  uint32_t max_raise_size = constants::STACK - opponent_bet;
  uint32_t min_raise_size = opponent_bet - current_bet;
  min_raise_size = max(min_raise_size, constants::BIG_BLIND);
  min_raise_size = min(max_raise_size, min_raise_size);

  if (min_raise_size == 0)
    return possible_bets;

  if (min_raise_size == max_raise_size) {
    array<uint32_t, 2> size = {node->bets[0], node->bets[1]};
    size[current_player] = opponent_bet + min_raise_size;
    possible_bets.push_back(size);
    return possible_bets;
  }

  if (node->num_bets < constants::BET_CAP) {
    vector<double> fractions;
    if (node->num_bets < pot_fractions.size()) {
      fractions = pot_fractions[node->num_bets];
    } else {
      fractions = pot_fractions[pot_fractions.size() - 1];
    }

    auto pot = opponent_bet * 2;
    for (int i = 0; i < fractions.size(); i++) {
      auto raise_size = pot * fractions[i];
      if (raise_size >= min_raise_size && raise_size < max_raise_size) {
        array<uint32_t, 2> size = {node->bets[0], node->bets[1]};
        size[current_player] = opponent_bet + raise_size;
        possible_bets.push_back(size);
      }
    }
  }

  array<uint32_t, 2> size = {node->bets[0], node->bets[1]};
  size[current_player] = opponent_bet + max_raise_size;
  possible_bets.push_back(size);

  return possible_bets;
}
