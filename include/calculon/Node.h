#ifndef __NODE_H__
#define __NODE_H__

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

enum NodeType {
  TERMINAL_FOLD_NODE = 0,
  TERMINAL_CALL_NODE,
  INNER_NODE,
  CHECK_NODE,
  CHANCE_NODE,
  BET_NODE
};


struct Node {
  Node *parent;
  std::vector<Node *> children;
  // pot size
  uint32_t pot;
  // current player index
  uint8_t current_player;
  // current betting round
  uint8_t street;
  // 64bit representation of board cards
  uint64_t board;
  // depth shouldnt take more than 8bits
  uint32_t depth;
  // current number of bets, resets every round
  uint32_t num_bets;
  // is this a terminal node
  bool terminal;
  // bets
  uint32_t bets[2];
  // node type
  NodeType type;

  Node();
  ~Node();
};

void print_node(Node*, int);

#endif // __NODE_H__
