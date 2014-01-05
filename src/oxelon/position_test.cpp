#include <gtest/gtest.h>

#include "position.hpp"

namespace oxelon {

TEST(Position, to_str) {
  EXPECT_EQ("B4", Position(1, 3).to_str());
}

}  // namespace oxelon
