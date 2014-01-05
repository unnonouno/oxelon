#include <gtest/gtest.h>

#include "position.hpp"

namespace oxelon {

TEST(Position, to_str) {
  EXPECT_EQ("B4", Position(1, 3).to_str());
}

TEST(Position, pass) {
  Position pass(Position::POS_PASS);
  EXPECT_EQ("PS", pass.to_str());
  EXPECT_TRUE(pass.pass());
}

}  // namespace oxelon
