#include "calculon/Node.h"
#include <iostream>

using namespace std;

Node::Node() {
    parent = NULL;
    children = vector<Node*>();
    current_player = 0;
    board = 0;
    street = 0;
    bets[0] = 0;
    bets[1] = 1;
    num_bets = 0;
    terminal = false;
    type = NodeType::CHANCE_NODE;
    depth = 0;
}

Node::~Node() {
    for (int i=0; i < children.size(); i++)
        delete children[0];
    delete this;
}

// bool Node::bets_settled() {
//     uint32_t temp = bets[0];
//     for (int i=1; i < constants::MAX_PLAYERS; i++) {
//         if (bets[i] != temp)
//             return false;
//     }
//     return true;
// }
// 
// // clone everything but parent and children
// Node* Node::clone() {
//     Node* clone = new Node;
//     clone->pot = pot;
//     clone->current_player = current_player;
//     clone->street = street;
//     clone->board = board;
//     clone->depth = depth;
//     clone->terminal = terminal;
//     clone->type = type;
//     clone->num_bets = num_bets;
//     copy(begin(bets), end(bets), begin(clone->bets));
//     return clone;
// }
// 
// uint32_t Node::max_bet() {
//     return *max_element(bets, bets + constants::MAX_PLAYERS);
// }

void print_node(Node* node, int depth) {
    for (int i=0; i < depth; i++)
        cout << "  ";
    cout << '[' << node->bets[0] << ' ' << node->bets[1] << ']';
    cout << " (p" << (node->current_player == 0 ? "1" : "2") << ") ";
    if (node->type == TERMINAL_FOLD_NODE) {
        cout << "Fold";
    }
    if (node->type == CHECK_NODE) {
        cout << "Check/Call";
    }
    if (node->type == BET_NODE) {
        cout << "Bet";
    }
    if (node->type == CHANCE_NODE) {
        cout << "Chance";
    }
    if (node->type == TERMINAL_CALL_NODE) {
        cout << "TCall";
    }
    if (node->type == INNER_NODE) {
        cout << "Inner";
    }
    if (node->terminal) {
        cout << " Terminal";
    }
    cout << endl;
    for (auto child : node->children)
        print_node(child, depth + 1);
}

