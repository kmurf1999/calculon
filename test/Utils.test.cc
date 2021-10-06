#include <supremus/Utils.h>
#include <gtest/gtest.h>

#include <iostream>

using namespace std;
// Demonstrate some basic assertions.
TEST(Utils, get_next_boards) {

  auto flop_cards = utils::get_next_boards(0);
  EXPECT_EQ(flop_cards.size(), 22100);

  auto turn_cards = utils::get_next_boards(flop_cards[0]);
  EXPECT_EQ(turn_cards.size(), 49);

  auto river_cards = utils::get_next_boards(turn_cards[0]);
  EXPECT_EQ(river_cards.size(), 48);
}

TEST(Utils, get_hole_index) {
  int index = utils::get_hole_index(0, 1);
  cout << index << endl;
  EXPECT_EQ(index, 0);
}
