#ifndef ITERATIVE_DEEPENING_HPP_732F77D0_6CEE_469A_A6C7_4CEEF816F012_
#define ITERATIVE_DEEPENING_HPP_732F77D0_6CEE_469A_A6C7_4CEEF816F012_

#include "solver.hpp"

namespace oxelon {

class IterativeDeepening : public Solver {
 public:
  IterativeDeepening(
      std::auto_ptr<Solver> s,
      double max_time,
      unsigned first_depth,
      unsigned exact_depth);
  
  std::pair<Position, eval_t> search_next(const Board& board, Disc disc);

  void set_max_depth(unsigned) {}

  unsigned get_total_node() const { return p_solver_->get_total_node(); }
  void clear_total_node() { p_solver_->clear_total_node(); }
  unsigned get_total_leaf() const { return p_solver_->get_total_leaf(); }
  void clear_total_leaf() { p_solver_->clear_total_leaf(); }

 private:
  std::auto_ptr<Solver> p_solver_;
  mutable double rest_time_;
  mutable unsigned current_depth_;
  const unsigned exact_depth_;
};

}  // namespace oxelon

#endif // ITERATIVE_DEEPENING_HPP_732F77D0_6CEE_469A_A6C7_4CEEF816F012_
