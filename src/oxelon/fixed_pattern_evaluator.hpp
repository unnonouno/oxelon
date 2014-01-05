#ifndef FIXED_PATTERN_EVALUATOR_HPP_84CDAEDB_8126_4181_B856_409C4B96FB60_
#define FIXED_PATTERN_EVALUATOR_HPP_84CDAEDB_8126_4181_B856_409C4B96FB60_

#include "board.hpp"
#include "evaluator.hpp"

namespace oxelon {

class FixedPatternEvaluator : public Evaluator<Board> {
 public:
  FixedPatternEvaluator();
  
  eval_t evaluate(const Board& board, Disc) const;

  void update(const Board& board, Disc, eval_t error, int beta, int n_sample);

  void swap();

  void write(std::ostream &out) const;
  
  void read(std::istream &in);

 private:
  std::vector<eval_t> horver_2_weights_;
  std::vector<eval_t> horver_3_weights_;
  std::vector<eval_t> horver_4_weights_;

  std::vector<eval_t> diagonal_4_weights_;
  std::vector<eval_t> diagonal_5_weights_;
  std::vector<eval_t> diagonal_6_weights_;
  std::vector<eval_t> diagonal_7_weights_;
  std::vector<eval_t> diagonal_8_weights_;

  std::vector<eval_t> corner3x3_weights_;
  std::vector<eval_t> corner2x5_weights_;
  std::vector<eval_t> edge2x_weights_;
};

}  // namespace oxelon

#endif // FIXED_PATTERN_EVALUATOR_HPP_84CDAEDB_8126_4181_B856_409C4B96FB60_
