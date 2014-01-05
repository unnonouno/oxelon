#ifndef TRANS_TABLE_CONTROLLER_HPP_97877778_B957_4CF6_BB6A_6D3DA3927E9C_
#define TRANS_TABLE_CONTROLLER_HPP_97877778_B957_4CF6_BB6A_6D3DA3927E9C_

#include "board.hpp"

namespace oxelon {

template <typename T>
class TransTableController {
public:
  typedef T TransTable;

  TransTableController(TransTable& t):
    trans_table_(t) {}

  bool init_alpha_beta(const Board& board, eval_t &alpha, eval_t &beta) {
    typename TransTable::iterator nit = trans_table_.find(board);
    if (nit != trans_table_.end()) {
      //hit_count_++;
      if (nit->second.lowerbound_ >= beta) {
        //cut_count_++;
        return_value_ = nit->second.lowerbound_;
        return false;
      }
      if (nit->second.upperbound_ <= alpha) {
        //cut_count_++;
        return_value_ = nit->second.upperbound_;
        return false;
      }
      alpha = std::max(alpha, nit->second.lowerbound_);
      beta = std::min(beta, nit->second.upperbound_);
      
      //pre_entry = nit->second;
    }
    return true;
  }

  void update_alpha_beta(const Board& board, eval_t g, eval_t alpha, eval_t beta) {
    typename TransTable::iterator nit = trans_table_.find(board);
    if (nit == trans_table_.end()) {
      nit = trans_table_.insert(typename TransTable::value_type(board, typename TransTable::entry_type()));
    }

    typename TransTable::entry_type& new_n = nit->second;
    
    if (g <= alpha) {
      new_n.upperbound_ = g;
    } else if (alpha < g && g < beta) {
      new_n.lowerbound_ = g;
      new_n.upperbound_ = g;
    } else if (g >= beta)
      new_n.lowerbound_ = g;
  }

  eval_t get_return_value() const { return return_value_; }

private:

  TransTable &trans_table_;
  eval_t return_value_;
};

}  // namespace oxelon

#endif // TRANS_TABLE_CONTROLLER_HPP_97877778_B957_4CF6_BB6A_6D3DA3927E9C_
