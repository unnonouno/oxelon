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

TEST(BitBoard, get_move_bit) {
  BitBoard b = BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--OOO---"
      "--OXO---"
      "--OOO---"
      "--------"
      "--------"
      "--------");

  BitBoard::data_type move = b.get_move_bit();
  BitMatrix expect = BitMatrix::parse(
      "--------"
      "-X-X-X--"
      "--------"
      "-X---X--"
      "--------"
      "-X-X-X--"
      "--------"
      "--------");
  EXPECT_TRUE(expect == move);
}

TEST(BitBoard, get_score) {
  BitBoard b;
  EXPECT_EQ(0, b.get_score());
  b.set_disc(Position(0), BLACK);
  // TODO
  EXPECT_EQ(1024, b.get_score());
  b.set_disc(Position(1), WHITE);
  b.set_disc(Position(2), WHITE);
  EXPECT_EQ(-1024, b.get_score());
}


}  // namespace oxelon
