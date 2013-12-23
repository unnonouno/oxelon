#include <gtest/gtest.h>

#include "bit_board.hpp"

namespace oxelon {

TEST(BitBoard, code_at) {
  BitBoard b;
  Position pos(0, 0);
  EXPECT_EQ(1u, b.code_at(pos));
  b.set_disc(pos, BLACK);
  EXPECT_EQ(0u, b.code_at(pos));
  b.set_disc(pos, WHITE);
  EXPECT_EQ(2u, b.code_at(pos));
}


}  // namespace oxelon
