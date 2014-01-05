#ifndef BIT_MOVE_ORDERING_ITERATOR_HPP_3D35D617_62F0_45DB_BF0A_4497DD42F29B_
#define BIT_MOVE_ORDERING_ITERATOR_HPP_3D35D617_62F0_45DB_BF0A_4497DD42F29B_

#include <vector>

#include "board.hpp"
#include "evaluator.hpp"
#include "sorted_list.hpp"

namespace oxelon {

class BitMoveOrderingIterator {
 public:
  BitMoveOrderingIterator(const Board& board, Evaluator<Board>& eval);
  bool has_next() const;
  void go_next();
  Board get_next() const;

private:
  typedef std::vector<unsigned> ValBitMap;

  const BitBoard& board_;
  ValBitMap sorted_next_;
  ValBitMap::iterator current_;
};

BitMoveOrderingIterator::BitMoveOrderingIterator(
    const Board& board,
    Evaluator<Board>& eval)
    : board_(board), sorted_next_() {
  std::vector<eval_t> sort_key;

  BitBoard::data_type moves = board.get_move_bit();
  while (moves.any()) {
    BitBoard::data_type next = moves.get_next_bit();
    unsigned pos = next.get_next();
    BitBoard next_board(board);
    next_board.try_move(pos);
    eval_t v = eval.evaluate(next_board, BLACK);
    sort_insert(sort_key,
                sorted_next_,
                v,
                pos);
    moves ^= next;
  }
  current_ = sorted_next_.begin();
}

inline
bool BitMoveOrderingIterator::has_next() const {
  return current_ != sorted_next_.end();
}

inline
void BitMoveOrderingIterator::go_next() {
  ++current_;
}

inline
BitBoard BitMoveOrderingIterator::get_next() const {
  BitBoard next_board(board_);
  next_board.try_move(*current_);
  return next_board.make_inverse();
}

}  // namespace oxelon

#endif // BIT_MOVE_ORDERING_ITERATOR_HPP_3D35D617_62F0_45DB_BF0A_4497DD42F29B_
