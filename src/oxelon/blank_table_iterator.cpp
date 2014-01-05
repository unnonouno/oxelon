#include "blank_table_iterator.hpp"

namespace oxelon {

void BlankTableIterator::forward() {
  while (index_ < blanks_.size()) {
    unsigned delta = blanks_[index_].first;
    unsigned next = blanks_[index_].second;
    BitBoard next_board(board_);
    if (next_board.try_move(next)) {
      next_board.inverse();
      next_board_ = next_board;
      // delete blank
      blanks_[pre_].first += delta;
      last_delta_ = delta;
      return;
    }

    pre_ = index_;
    index_ += delta;
  }
  valid_ = false;
}

void BlankTableIterator::go_next() {
  blanks_[pre_].first -= last_delta_;
  pre_ = index_;
  index_ += last_delta_;
  forward();
}

}  // namespace oxelon
