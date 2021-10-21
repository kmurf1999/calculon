#include <calculon/Utils.h>
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
  int count[1326] = { 0 };
  for (int c1=0; c1 < 52; ++c1) {
    for (int c2=c1+1; c2 < 52; ++c2) {
      int index = utils::get_hole_index(c1, c2);
      count[index] += 1;
    }
  }
  for (int i=0; i < 1326; ++i)
    EXPECT_EQ(count[i], 1);
}
