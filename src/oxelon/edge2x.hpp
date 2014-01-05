#ifndef EDGE2X_HPP_70B08E37_3923_4CE0_81AB_4870C84F8D81_
#define EDGE2X_HPP_70B08E37_3923_4CE0_81AB_4870C84F8D81_

#include "board.hpp"
#include "power.hpp"

namespace oxelon {

template <bool Yinv = false, bool Rot = false>
class Edge2x {
 public:
  size_t pattern_size() const { return pow3<10>::val; }

  unsigned int encode(const Board& b, Disc d) const;

private:
  Position conv_pos(int x, int y) const;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

template <bool Yinv, bool Rot> inline
unsigned int
Edge2x<Yinv, Rot>::encode(const Board& b, Disc d) const {
  unsigned int ret = 0;
  for (int i = 0; i < 8; ++i) {
    ret = ret * 3 + b.code_at(conv_pos(i, 0), d);
  }
  ret = ret * 3 + b.code_at(conv_pos(1, 1), d);
  ret = ret * 3 + b.code_at(conv_pos(6, 1), d);
  return ret;
}

template<> inline
Position
Edge2x<false, false>::conv_pos(int x, int y) const {
  return Position(x, y);
}

template<> inline
Position
Edge2x<true, false>::conv_pos(int x, int y) const {
  return Position(x, Board::SIZE-1 - y);
}

template<> inline
Position
Edge2x<false, true>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - y, x);
}

template<> inline
Position
Edge2x<true, true>::conv_pos(int x, int y) const {
  return Position(y, x);
}

}  // namespace oxelon

#endif // EDGE2X_HPP_70B08E37_3923_4CE0_81AB_4870C84F8D81_
