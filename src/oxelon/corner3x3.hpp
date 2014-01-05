#ifndef CORNER3X3_HPP_A2DEE15C_C5F1_41DD_95B0_3DB5B36454BA_
#define CORNER3X3_HPP_A2DEE15C_C5F1_41DD_95B0_3DB5B36454BA_

#include "board.hpp"
#include "power.hpp"

namespace oxelon {

template <bool Xinv = false, bool Yinv = false>
class Corner3x3 {
 public:
  size_t pattern_size() const { return pow3<9>::val; }

  unsigned int encode(const Board& b, Disc d) const;

 private:
  Position conv_pos(int x, int y) const;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

template <bool Xinv, bool Yinv> inline
unsigned int
Corner3x3<Xinv, Yinv>::encode(const Board& b, Disc d) const {
  unsigned int ret = 0;
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      ret = ret * 3 + b.code_at(conv_pos(x, y), d);
    }
  }
  return ret;
}

template<> inline
Position
Corner3x3<false, false>::conv_pos(int x, int y) const {
  return Position(x, y);
}

template<> inline
Position
Corner3x3<true, false>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - x, y);
}

template<> inline
Position
Corner3x3<false, true>::conv_pos(int x, int y) const {
  return Position(x, Board::SIZE-1 - y);
}

template<> inline
Position
Corner3x3<true, true>::conv_pos(int x, int y) const {
  return Position(Board::SIZE-1 - x, Board::SIZE-1 - y);
}

}  // namespace oxelon

#endif // CORNER3X3_HPP_A2DEE15C_C5F1_41DD_95B0_3DB5B36454BA_
