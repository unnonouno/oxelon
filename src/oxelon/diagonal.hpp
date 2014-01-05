#ifndef DIAGONAL_HPP_9DBEED72_90D3_4939_B3D3_70FCF4D3387C_
#define DIAGONAL_HPP_9DBEED72_90D3_4939_B3D3_70FCF4D3387C_

#include "board.hpp"
#include "power.hpp"

namespace oxelon {

template <int N, bool Xinv = false, bool Yinv = false>
class Diagonal {
 public:
  size_t pattern_size() const { return pow3<N>::val; }

  unsigned int encode(const Board& b, Disc d) const;

private:
  Position conv_pos(int x, int y) const;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

template <int N, bool Xinv, bool Yinv> inline
unsigned int
Diagonal<N, Xinv, Yinv>::encode(const Board& b, Disc d) const {
  unsigned int ret = 0;
  for (int i = 0; i < N; i++) {
    ret = (ret << 1) + ret;
    ret += b.code_at(conv_pos(N-1 - i, i), d);
  }
  return ret;
}

template<int N, bool Xinv, bool Yinv> inline
Position
Diagonal<N, Xinv, Yinv>::conv_pos(int x, int y) const {
  if (!Xinv && !Yinv)
    return Position(x, y);
  else if (Xinv && !Yinv)
    return Position(Board::SIZE-1 - x, y);
  else if (!Xinv && Yinv)
    return Position(x, Board::SIZE-1 - y);
  else
    return Position(Board::SIZE-1 - x, Board::SIZE-1 - y);
}

}  // namespace oxelon

#endif // DIAGONAL_HPP_9DBEED72_90D3_4939_B3D3_70FCF4D3387C_
