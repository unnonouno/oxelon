#ifndef NEGA_SCOUT_HPP_397B969F_D98A_4A62_9BB2_DF6BC611793C_
#define NEGA_SCOUT_HPP_397B969F_D98A_4A62_9BB2_DF6BC611793C_

#include "evaluator.hpp"
#include "solver.hpp"
#include "transposition_table.hpp"
#include "types.hpp"

namespace oxelon {

class NegaScout : public Solver {
 public:
  NegaScout(std::auto_ptr<Evaluator<Board> >, unsigned max);

  std::pair<Position, eval_t> search_next(const Board& b, Disc d);
  void set_max_depth(unsigned d) { max_depth_ = d; }

  unsigned get_total_node() const { return node_count_; }
  void clear_total_node() { node_count_ = 0; }
  unsigned get_total_leaf() const { return leaf_count_; }
  void clear_total_leaf() { leaf_count_ = 0; }

 private:
  eval_t evaluate(
      const Board& board,
      unsigned depth,
      bool passed,
      eval_t alpha,
      eval_t beta);
  
  std::auto_ptr<Evaluator<Board> > p_evaluator_;
  unsigned max_depth_;
  unsigned leaf_count_;
  unsigned node_count_;
  Position next_move_;

  static const eval_t INFINITY_VALUE = 10000000;

  struct Entry {
    Entry() : lowerbound_(-INFINITY_VALUE), upperbound_(INFINITY_VALUE) {}
    eval_t lowerbound_;
    eval_t upperbound_;
  };

  struct Hash {
    unsigned operator()(const Board& key) const {
      return key.hash();
    }
  };

  typedef TranspositionTable<Board, Entry, Hash> TransTable;
  std::auto_ptr<TransTable> p_trans_table_;
};

}  // namespace oxelon

#endif // NEGA_SCOUT_HPP_397B969F_D98A_4A62_9BB2_DF6BC611793C_
