#include <gtest/gtest.h>

#include "bit_move_iterator.hpp"

namespace oxelon {

TEST(BitMoveIterator, no_move) {
  BitBoard b = BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--OOO---"
      "--OOO---"
      "--OOO---"
      "--------"
      "--------"
      "--------");
  BitMoveIterator it(b);
  ASSERT_FALSE(it.has_next());
}

TEST(BitMoveIterator, last_one) {
  BitBoard b = BitBoard::parse_zebra_board(
      "XOOOOOOO"
      "OOOOOOOO"
      "OOOOOOOO"
      "OOOOOOOO"
      "OOOOOOOO"
      "OOOOOOOO"
      "OOOOOOOO"
      "OOOOOOO-");
  BitMoveIterator it(b);
  ASSERT_TRUE(it.has_next());
}

TEST(BitMoveIterator, trivial) {
  BitBoard b = BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--OOO---"
      "--OXO---"
      "--OOO---"
      "--------"
      "--------"
      "--------");
  BitMoveIterator it(b);
  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "-O------"
      "--OXX---"
      "--XOX---"
      "--XXX---"
      "--------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "---O----"
      "--XOX---"
      "--XOX---"
      "--XXX---"
      "--------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "-----O--"
      "--XXO---"
      "--XOX---"
      "--XXX---"
      "--------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--XXX---"
      "-OOOX---"
      "--XXX---"
      "--------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--XXX---"
      "--XOOO--"
      "--XXX---"
      "--------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--XXX---"
      "--XOX---"
      "--OXX---"
      "-O------"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--XXX---"
      "--XOX---"
      "--XOX---"
      "---O----"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_TRUE(it.has_next());
  EXPECT_EQ(BitBoard::parse_zebra_board(
      "--------"
      "--------"
      "--XXX---"
      "--XOX---"
      "--XXO---"
      "-----O--"
      "--------"
      "--------"), it.get_next());
  it.go_next();

  ASSERT_FALSE(it.has_next());}

}  // namespace oxelon
