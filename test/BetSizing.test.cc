#include <supremus/BetSizing.h>
#include <gtest/gtest.h>
#include <iostream>

// Demonstrate some basic assertions.
TEST(BetSizing, get_possible_bets) {
  BetSizing *bet_sizing = new BetSizing({{0.5, 1.0}});

  Node *node = new Node;
  node->bets[0] = 100;
  node->bets[1] = 50;
  node->current_player = 1;

  auto bets = bet_sizing->get_possible_bets(node);

  EXPECT_EQ(bets.size(), 3);
  for (auto bet : bets) {
    EXPECT_EQ(bet[1 - node->current_player],
              node->bets[1 - node->current_player]);
  }
  EXPECT_EQ(bets[0][node->current_player], 200);
  EXPECT_EQ(bets[1][node->current_player], 300);
  EXPECT_EQ(bets[2][node->current_player], 20000);
}
