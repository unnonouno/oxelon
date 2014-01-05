#include <gtest/gtest.h>

#include "bit_matrix.hpp"
#include "position.hpp"

namespace oxelon {

TEST(BitMatrix, set) {
  BitMatrix m;
  EXPECT_FALSE(m[0]);
  m.set(0);
  EXPECT_TRUE(m[0]);
  m.set(40);
  EXPECT_TRUE(m[40]);
}

TEST(BitMatrix, size) {
  BitMatrix m;
  EXPECT_EQ(0u, m.size());
  m.set(0);
  EXPECT_EQ(1u, m.size());
  m.set(3);
  EXPECT_EQ(2u, m.size());
  m.set(40);
  EXPECT_EQ(3u, m.size());

  EXPECT_EQ(64u, BitMatrix(0xFFFFFFFFFFFFFFFFULL).size());
}

TEST(BitMatrix, get_next) {
  BitMatrix m;
  //EXPECT_EQ(0u, m.get_next());
  m.set(40);
  EXPECT_EQ(40u, m.get_next());
  m.set(10);
  EXPECT_EQ(10u, m.get_next());
  m.set(0);
  EXPECT_EQ(0u, m.get_next());
  m.set(16);
  EXPECT_EQ(0u, m.get_next());
}

TEST(BitMatrix, parse) {
  BitMatrix m = BitMatrix::parse(
      "X-X-X-X-"
      "-X-X-X-X"
      "X-X-X-X-"
      "-X-X-X-X"
      "X-X-X-X-"
      "-X-X-X-X"
      "X-X-X-X-"
      "-X-X-X-X");
  for (int i = 0; i < 8; i += 2) {
    EXPECT_TRUE(m[Position(i, 0)]);
    EXPECT_FALSE(m[Position(i + 1, 0)]);
  }
}

}  // namespace oxelon

