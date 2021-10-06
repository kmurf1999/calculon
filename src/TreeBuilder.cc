#include "../include/supremus/TreeBuilder.h"

void TreeBuilder::build_tree(Node *root, BetSizing *bet_sizes,
                             bool limit_to_street) {
  this->limit_to_street = limit_to_street;
  this->bet_sizes = bet_sizes;
  build_tree_dfs(root);
}

void TreeBuilder::build_tree_dfs(Node *node) {
  get_children(node);
  uint32_t depth = 0;
  for (auto child : node->children) {
    child->parent = node;
    build_tree_dfs(child);
    depth = max(depth, child->depth);
  }
  node->depth = depth + 1;
}

void TreeBuilder::get_children(Node *node) {
  if (node->terminal) {
    return;
  } else if (node->current_player == CHANCE) {
    get_children_chance_node(node);
  } else {
    get_children_player_node(node);
  }
}

void TreeBuilder::get_children_chance_node(Node *parent) {
  if (limit_to_street) {
    return;
  }

  auto next_boards = utils::get_next_boards(parent->board);
  for (auto board : next_boards) {
    Node *child = new Node;
    child->parent = parent;
    child->type = INNER_NODE;
    child->board = board;
    child->street = parent->street + 1;
    child->bets[0] = parent->bets[0];
    child->bets[1] = parent->bets[1];
    child->current_player = P2;
    parent->children.push_back(child);
  }
}

void TreeBuilder::get_children_player_node(Node *parent) {
  // 1. fold action
  Node *fold_node = new Node;
  fold_node->type = TERMINAL_FOLD_NODE;
  fold_node->terminal = true;
  fold_node->current_player = 1 - parent->current_player;
  fold_node->street = parent->street;
  fold_node->board = parent->board;
  fold_node->bets[0] = parent->bets[0];
  fold_node->bets[1] = parent->bets[1];
  parent->children.push_back(fold_node);

  // During preflop, on the first action we can call and its not a transition
  // postflop, the first player to act can check
  if ((parent->street == PREFLOP && parent->current_player == P1 &&
       parent->num_bets == 0) ||
      (parent->street != PREFLOP && parent->current_player == P2 &&
       parent->bets[0] == parent->bets[1])) {
    Node *check_node = new Node;
    check_node->type = CHECK_NODE;
    check_node->terminal = false;
    check_node->current_player = 1 - parent->current_player;
    check_node->street = parent->street;
    check_node->board = parent->board;
    check_node->bets[0] = max(parent->bets[0], parent->bets[1]);
    check_node->bets[1] = max(parent->bets[0], parent->bets[1]);
    check_node->num_bets = parent->num_bets;
    parent->children.push_back(check_node);
  } else if (parent->street != RIVER &&
             ((parent->bets[0] == parent->bets[1] &&
               ((parent->street == PREFLOP && parent->current_player == P2) ||
                (parent->street != PREFLOP && parent->current_player == P1))) ||
              (parent->bets[0] != parent->bets[1] &&
               max(parent->bets[0], parent->bets[1]) < STACK))) {
    Node *chance_node = new Node;
    chance_node->type = CHANCE_NODE;
    chance_node->terminal = false;
    chance_node->board = parent->board;
    chance_node->street = parent->street;
    chance_node->current_player = CHANCE;
    chance_node->bets[0] = max(parent->bets[0], parent->bets[1]);
    chance_node->bets[1] = max(parent->bets[0], parent->bets[1]);
    chance_node->num_bets = 0;
    parent->children.push_back(chance_node);
  } else {
    Node *call_node = new Node;
    call_node->type = TERMINAL_CALL_NODE;
    call_node->terminal = true;
    call_node->current_player = 1 - parent->current_player;
    call_node->street = parent->street;
    call_node->board = parent->board;
    call_node->bets[0] = max(parent->bets[0], parent->bets[1]);
    call_node->bets[1] = max(parent->bets[0], parent->bets[1]);
    call_node->num_bets = parent->num_bets;
    parent->children.push_back(call_node);
  }

    auto possible_bets = this->bet_sizes->get_possible_bets(parent);
    for (auto bet : possible_bets) {
      Node *child = new Node;
      child->type = BET_NODE;
      child->current_player = 1 - parent->current_player;
      child->street = parent->street;
      child->board = parent->board;
      child->bets[0] = bet[0];
      child->bets[1] = bet[1];
      child->num_bets = parent->num_bets + 1;
      parent->children.push_back(child);
    }
}
