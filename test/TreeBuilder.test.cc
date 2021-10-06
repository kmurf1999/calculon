#include <supremus/TreeBuilder.h>
#include <gtest/gtest.h>

TEST(TreeBuilder, build_game_tree_river) {
  vector<vector<double>> sizes = {{ 1.0 }};
  BetSizing *bet_sizes = new BetSizing(sizes);

  Node *root = new Node;
  root->board = 0b11111;
  root->street = RIVER;
  root->current_player = P2;
  root->bets[0] = 100;
  root->bets[1] = 100;
  root->num_bets = 0;

  TreeBuilder *builder = new TreeBuilder;
  builder->build_tree(root, bet_sizes, true);

  EXPECT_EQ(root->depth, 7);
}

TEST(TreeBuilder, build_game_tree_turn) {
  vector<vector<double>> sizes = {{ 1.0 }};
  BetSizing *bet_sizes = new BetSizing(sizes);

  Node *root = new Node;
  root->board = 0b1111;
  root->street = TURN;
  root->current_player = P2;
  root->bets[0] = 100;
  root->bets[1] = 100;
  root->num_bets = 0;
  root->type = INNER_NODE;

  TreeBuilder *builder = new TreeBuilder;
  builder->build_tree(root, bet_sizes, false);

  EXPECT_EQ(root->depth, 11);
}

TEST(TreeBuilder, build_game_tree_preflop) {
  vector<vector<double>> sizes = {{ 1.0 }};
  BetSizing *bet_sizes = new BetSizing(sizes);

  Node *root = new Node;
  root->board = 0;
  root->street = PREFLOP;
  root->current_player = P1;
  root->bets[0] = SMALL_BLIND;
  root->bets[1] = BIG_BLIND;
  root->num_bets = 0;
  root->type = INNER_NODE;

  TreeBuilder *builder = new TreeBuilder;
  builder->build_tree(root, bet_sizes, true);

  // print_node(root, 0);

  EXPECT_EQ(root->depth, 7);
}
