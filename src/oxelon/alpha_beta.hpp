#ifndef ALPHA_BETA_HPP_EF0F232D_7651_43DE_B45D_50D76D5CDD54_
#define ALPHA_BETA_HPP_EF0F232D_7651_43DE_B45D_50D76D5CDD54_

#include "evaluator.hpp"
#include "solver.hpp"
#include "types.hpp"

namespace oxelon {

class AlphaBeta : public Solver {
 public:
  AlphaBeta(std::auto_ptr<Evaluator<Board> > &eval, unsigned max);
  virtual ~AlphaBeta() {}

  std::pair<Position, eval_t> search_next(const Board& b, Disc d);
  void set_max_depth(unsigned);

  unsigned get_total_node() const;
  void clear_total_node();
  unsigned get_total_leaf();
  void clear_total_leaf();

 private:
  eval_t evaluate(
      const Board& board,
      bool passed,
      unsigned depth,
      eval_t alpha,
      eval_t beta);

  std::auto_ptr<Evaluator<Board> > p_evaluator_;
};

}  // namespace oxelon

#endif // ALPHA_BETA_HPP_EF0F232D_7651_43DE_B45D_50D76D5CDD54_
