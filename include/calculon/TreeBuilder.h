#ifndef __TREE_BUILDER_H__
#define __TREE_BUILDER_H__

#include "BetSizing.h"
#include "Constants.h"
#include "Node.h"
#include "Utils.h"
#include <algorithm>
#include <vector>

using namespace std;
using namespace constants;

class TreeBuilder {
public:
  void build_tree(Node *, BetSizing *, bool);
private:
  void build_tree_dfs(Node *);
  void get_children(Node *);
  void get_children_chance_node(Node *);
  void get_children_player_node(Node *);

  bool limit_to_street;
  BetSizing *bet_sizes;
};

#endif // __TREE_BUILDER_H__
