#ifndef HORVER_HPP_3B0CBA17_9F52_461D_B9D6_D8E86A0FB150_
#define HORVER_HPP_3B0CBA17_9F52_461D_B9D6_D8E86A0FB150_

#include <utility>
#include <boost/preprocessor.hpp>

#include "board.hpp"
#include "position.hpp"
#include "power.hpp"

namespace oxelon {

template <int N, bool Yinv = false, bool Rot = false>
class HorVer {
 public:
  size_t pattern_size() const { return pow3<8>::val; }

  unsigned int encode(const Board& b, Disc d) const;

 private:
  Position conv_pos(int x, int y) const;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

template <int N, bool Yinv, bool Rot> inline
unsigned int HorVer<N, Yinv, Rot>::encode(const Board& b, Disc d) const {
  unsigned int ret = 0;
#define GEN_HOR_VER_CODE(z, i, data)                                    \
  ret = (ret << 1) + ret;                                               \
  ret += b.code_at(conv_pos(i, N-1), d);

  BOOST_PP_REPEAT(8, GEN_HOR_VER_CODE, _)
  return ret;
}

template<int N, bool Yinv, bool Rot> inline
Position
HorVer<N, Yinv, Rot>::conv_pos(int x, int y) const {
  if (!Yinv && !Rot)
    return Position(x, y);
  else if (Yinv && !Rot)
    return Position(x, Board::SIZE-1 - y);
  else if (!Yinv && Rot)
    return Position(Board::SIZE-1 - y, x);
  else
    return Position(y, x);
}

/*
template<int N>
inline Position
HorVer<N, false, false>::conv_pos(int x, int y) const
{ return Position(x, y); }

template<int N>
inline Position
HorVer<N, true, false>::conv_pos(int x, int y) const
{ return Position(x, Board::SIZE-1 - y); }

template<int N>
inline Position
HorVer<N, false, true>::conv_pos(int x, int y) const
{ return Position(Board::SIZE-1 - y, x); }

template<int N>
inline Position
HorVer<N, true, true>::conv_pos(int x, int y) const
{ return Position(y, x); }
*/

}  // namespace oxelon

#endif // HORVER_HPP_3B0CBA17_9F52_461D_B9D6_D8E86A0FB150_
