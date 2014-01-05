#ifndef BIT_MOVE_ITERATOR_HPP_B29BC124_9366_4914_847C_0707A3C9293E_
#define BIT_MOVE_ITERATOR_HPP_B29BC124_9366_4914_847C_0707A3C9293E_

#include "bit_board.hpp"
#include "bit_matrix.hpp"

namespace oxelon {

class BitMoveIterator {
 public:
  BitMoveIterator(const BitBoard& board);
  bool has_next() const;
  void go_next();
  BitBoard get_next() const;
  size_t get_rest_size() const;

 private:
  const BitBoard& board_;
  BitBoard::data_type moves_;
  BitBoard next_board_;
};

////////////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////////////

inline
BitMoveIterator::BitMoveIterator(const BitBoard& board)
    : board_(board),
      moves_(board.get_blank_bit()) {
  go_next();
}

inline
size_t BitMoveIterator::get_rest_size() const {
  return moves_.size();
}

inline
bool BitMoveIterator::has_next() const {
  return !(next_board_ == board_);
}

inline
BitBoard BitMoveIterator::get_next() const {
  return next_board_;
}

inline
void BitMoveIterator::go_next() {
  while (moves_.any()) {
    BitBoard::data_type next = moves_.get_next_bit();
    uint32_t pos = next.get_next();
    moves_ ^= next;
    BitBoard next_board(board_);
    if (next_board.try_move(pos)) {
      next_board.inverse();
      next_board_ = next_board;
      return;
    }
  }
  next_board_ = board_;
}

}  // namespace oxelon

#endif // BIT_MOVE_ITERATOR_HPP_B29BC124_9366_4914_847C_0707A3C9293E_
