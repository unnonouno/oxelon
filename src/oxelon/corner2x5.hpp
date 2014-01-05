#ifndef CORNER2X5_HPP_74A22E1E_BD8C_4E64_87C5_5411633AD0D0_
#define CORNER2X5_HPP_74A22E1E_BD8C_4E64_87C5_5411633AD0D0_

#include "board.hpp"
#include "power.hpp"

namespace oxelon {

template <bool Xinv = false, bool Yinv = false, bool Rot = false>
class Corner2x5 {
 public:
  size_t pattern_size() const { return pow3<10>::val; }

  unsigned int encode(const Board& b, Disc d) const;

 private:
  Position conv_pos(int x, int y) const;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

template <bool Xinv, bool Yinv, bool Rot> inline
unsigned int
Corner2x5<Xinv, Yinv, Rot>::encode(const Board& b, Disc d) const {
  unsigned int ret = 0;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 5; ++x) {
      ret = ret * 3 + b.code_at(conv_pos(x, y), d);
    }
  }
  return ret;
}

template<> inline
Position
Corner2x5<false, false, false>::conv_pos(int x, int y) const {
  return Position(x, y);
}

template<> inline
Position
Corner2x5<true, false, false>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - x, y);
}

template<> inline
Position
Corner2x5<false, true, false>::conv_pos(int x, int y) const {
  return Position(x, Board::SIZE-1 - y);
}

template<> inline
Position
Corner2x5<true, true, false>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - x, Board::SIZE-1 - y);
}

template<> inline
Position
Corner2x5<false, false, true>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - y, x);
}

template<> inline
Position
Corner2x5<true, false, true>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - y, Board::SIZE-1 - x);
}

template<> inline
Position
Corner2x5<false, true, true>::conv_pos(int x, int y) const {
  return Position(y, x);
}

template<> inline
Position
Corner2x5<true, true, true>::conv_pos(int x, int y) const {
  return Position(y, Board::SIZE-1 - x);
}

}  // namespace oxelon

#endif // CORNER2X5_HPP_74A22E1E_BD8C_4E64_87C5_5411633AD0D0_
