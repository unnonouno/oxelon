#include <gtest/gtest.h>

#include "bit_matrix.hpp"

namespace oxelon {

TEST(BitMatrix, set) {
  BitMatrix m;
  EXPECT_EQ(false, m[0]);
  m.set(0);
  EXPECT_EQ(true, m[0]);
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

}  // namespace oxelon

