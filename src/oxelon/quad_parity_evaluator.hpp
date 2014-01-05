#ifndef QUAD_PARITY_EVALUATOR_HPP_1277E99B_E377_4E92_A676_463BD4A7B611_
#define QUAD_PARITY_EVALUATOR_HPP_1277E99B_E377_4E92_A676_463BD4A7B611_

#include <vector>

#include "board.hpp"
#include "evaluator.hpp"

namespace oxelon {

class QuadParityEvaluator : public Evaluator<Board> {
 public:
  QuadParityEvaluator()
      : weights_(MAX), learning_weights_(MAX), learning_counts_(MAX) {}
  
  eval_t evaluate(const Board& board, Disc disc) const;

  void update(
      const Board& board,
      Disc disc,
      eval_t error,
      int beta,
      int n_sample);

  void swap();

  void write(std::ostream &out) const;
  
  void read(std::istream &in);

private:
  static const int MAX = 5;
  
  std::vector<eval_t> weights_;
  std::vector<eval_t> learning_weights_;
  std::vector<int> learning_counts_;
};

}  // namespace oxelon

#endif // QUAD_PARITY_EVALUATOR_HPP_1277E99B_E377_4E92_A676_463BD4A7B611_
