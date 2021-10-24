#ifndef __LOOK_AHEAD_H__
#define __LOOK_AHEAD_H__

#include "Node.h"
#include "torch/torch.h"
#include <vector>

struct LookAhead {
  Node* root;
  int depth;

  vector<int> bets_count;
  vector<int> nonallinbets_count;
  vector<int> terminal_actions_count;
  vector<int> actions_count;

  bool first_call_terminal;
  bool first_call_transition;
  bool first_call_check;
};

void compute_tree_structures(LookAhead* lookahead, vector<Node*> current_layer, int current_depth);

LookAhead* build_from_tree(Node* root);

#endif// __LOOK_AHEAD_H__
