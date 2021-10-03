
#include <gtest/gtest.h>
#include "../src/Utils.h"

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
