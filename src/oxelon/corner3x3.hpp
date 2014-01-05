#ifndef CORNER3X3_HPP_A2DEE15C_C5F1_41DD_95B0_3DB5B36454BA_
#define CORNER3X3_HPP_A2DEE15C_C5F1_41DD_95B0_3DB5B36454BA_

#include <boost/preprocessor.hpp>

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

#define PAT_GROUP_3X3 \
  ((0,0)) ((1,0)) ((2,0)) \
  ((0,1)) ((1,1)) ((2,1)) \
  ((0,2)) ((1,2)) ((2,2))

template <bool Xinv, bool Yinv> inline
unsigned int
Corner3x3<Xinv, Yinv>::encode(const Board& b, Disc d) const {
#define COR3X3_PAT_GEN(r,p,elem) ret = (ret << 1) + ret;        \
  ret += b.code_at(conv_pos elem, d);
  
  unsigned int ret = 0;
  BOOST_PP_SEQ_FOR_EACH(COR3X3_PAT_GEN, _, PAT_GROUP_3X3);
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
