#ifndef BLANK_TABLE_ITERATOR_HPP_315DE7B0_124F_40E8_9CB2_DF4BA7B98EF8_
#define BLANK_TABLE_ITERATOR_HPP_315DE7B0_124F_40E8_9CB2_DF4BA7B98EF8_

#include <vector>

#include "bit_board.hpp"

namespace oxelon {

class BlankTableIterator {
 public:
  typedef std::vector<std::pair<unsigned, unsigned> > blank_table;

  BlankTableIterator(blank_table&, const BitBoard&);
  bool has_next() const;
  void go_next();
  BitBoard get_next() const;

private:
  void forward();

  blank_table& blanks_;
  const BitBoard& board_;
  unsigned pre_;
  unsigned index_;
  unsigned last_delta_;
  BitBoard next_board_;
  bool valid_;
};

inline
BlankTableIterator::BlankTableIterator(
    BlankTableIterator::blank_table& blanks,
    const BitBoard& board)
    : blanks_(blanks),
      board_(board), 
      pre_(0),
      index_(blanks[0].first),
      last_delta_(0),
      valid_(true) {
  forward();
}

inline
bool BlankTableIterator::has_next() const {
  return valid_;
}

inline
BitBoard BlankTableIterator::get_next() const {
  return next_board_;
}

}  // namespace oxelon

#endif // BLANK_TABLE_ITERATOR_HPP_315DE7B0_124F_40E8_9CB2_DF4BA7B98EF8_
