#ifndef MOVE_ORDERING_ITERATOR_HPP_348A3FAB_4209_4713_A8B1_AB803EB8C242_
#define MOVE_ORDERING_ITERATOR_HPP_348A3FAB_4209_4713_A8B1_AB803EB8C242_

#include "board.hpp"
#include "evaluator.hpp"
#include "sorted_list.hpp"

namespace oxelon {

template <typename T>
class MoveOrderingIterator {
 public:
  typedef T TransTable;

  MoveOrderingIterator(
      const Board& board,
      BitBoard::data_type moves,
      Evaluator<Board> &evaluator,
      int delta,
      T& trans_table,
      T& pre_trans_table)
      : sorted_next_(sorted_nexts_[delta]) {
    std::vector<eval_t>& sort_key = sort_keys_[delta];
    
    sorted_next_.clear();
    sort_key.clear();

    size_t n_blank = board.get_blank_bit().size();
    
    while (moves.any()) {
      BitBoard::data_type next = moves.get_next_bit();
      //std::cerr << "*" << next.to_str() << std::endl;
      moves ^= next;
      BitBoard next_board(board);
      next_board.try_move(next.get_next());
      std::pair<BitBoard, BitBoard::data_type>
        next_ent(next_board.make_inverse(), next);
      typename TransTable::iterator trans_it = trans_table.find(next_ent.first);
      eval_t v;
      if (trans_it != trans_table.end()) {
        // 見つからない
        if (trans_it->second.upperbound_ == trans_it->second.lowerbound_)
          // 最優先
          v = -INFINITY_VALUE;
        else
          v = trans_it->second.upperbound_;
      } else {
        typename TransTable::iterator pre_it;
        if ((pre_it = pre_trans_table.find(next_ent.first))
            != pre_trans_table.end()) {
          //              if (false) {
          // 前回の探索結果を使う
          // TODO: lowerbound or upperbound?
          if (pre_it->second.upperbound_ == pre_it->second.lowerbound_)
            v = -INFINITY_VALUE;
          else
            v = pre_it->second.upperbound_;
        } else {
          if (n_blank > 20)
            v = evaluator.evaluate(next_ent.first, BLACK);
          else
            //v = next_ent.first.get_mobility();
            v = next_ent.first.get_weighted_mobility();
          v += INFINITY_VALUE;
        }
      }
      sort_insert(sort_key, sorted_next_, v, next_ent);
    }

    iterator_ = sorted_next_.begin();
  }

  bool has_next() const {
    return iterator_ != sorted_next_.end();
  }

  Board get_next() const {
    return iterator_->first;
  }
  void go_next() {
    ++iterator_;
  }

  static const eval_t INFINITY_VALUE = 10000000;

  typedef std::vector<std::pair<BitBoard, BitBoard::data_type> > ValBoardMap;
private:
  ValBoardMap& sorted_next_;
  typename ValBoardMap::iterator iterator_;

  static std::vector<ValBoardMap> sorted_nexts_;
  static std::vector<std::vector<eval_t> > sort_keys_;
};

template<typename T>
std::vector<typename MoveOrderingIterator<T>::ValBoardMap> MoveOrderingIterator<T>::sorted_nexts_(32);

template<typename T>
std::vector<std::vector<eval_t> > MoveOrderingIterator<T>::sort_keys_(32);

}  // namespace oxelon

#endif // MOVE_ORDERING_ITERATOR_HPP_348A3FAB_4209_4713_A8B1_AB803EB8C242_
