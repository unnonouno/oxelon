#include <gtest/gtest.h>

#include "position.hpp"

namespace oxelon {

TEST(Position, to_str) {
  EXPECT_EQ("B4", Position(1, 3).to_str());
}

TEST(Position, pass_to_str) {
  EXPECT_EQ("PS", Position(Position::POS_PASS).to_str());
}

}  // namespace oxelon
