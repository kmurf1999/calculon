#ifndef __BET_SIZING_H__
#define __BET_SIZING_H__

#include "Constants.h"
#include "Node.h"
#include <algorithm>
#include <array>
#include <assert.h>
#include <cstdint>
#include <vector>

using namespace std;

class BetSizing {
public:
  BetSizing(vector<vector<double>>);
  vector<array<uint32_t, 2>> get_possible_bets(Node *);

private:
  // an array of bet sizes to use for each action
  // bet_sizes[0] returns the best sizes to use on the first action
  // defaults to the last bet_sizes for any action greater than the last
  vector<vector<double>> pot_fractions;
};

#endif // __BET_SIZING_H__
