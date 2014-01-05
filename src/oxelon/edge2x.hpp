#ifndef EDGE2X_HPP_70B08E37_3923_4CE0_81AB_4870C84F8D81_
#define EDGE2X_HPP_70B08E37_3923_4CE0_81AB_4870C84F8D81_

#include <boost/preprocessor.hpp>

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

#define PAT_GROUP_2X                                              \
  ((0,0)) ((1,0)) ((2,0)) ((3,0)) ((4,0)) ((5,0)) ((6,0)) ((7,0)) \
          ((1,1))                                 ((6,1))

template <bool Yinv, bool Rot> inline
unsigned int
Edge2x<Yinv, Rot>::encode(const Board& b, Disc d) const {
#define EDGE2X_PAT_GEN(r,p,elem) ret = (ret << 1) + ret;        \
  ret += b.code_at(conv_pos elem, d);
  
  unsigned int ret = 0;
  BOOST_PP_SEQ_FOR_EACH(EDGE2X_PAT_GEN, _, PAT_GROUP_2X)
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
