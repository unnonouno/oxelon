#include "quad_parity_evaluator.hpp"

#include <istream>
#include <ostream>

#include "board.hpp"
#include "stream.hpp"

namespace oxelon {

eval_t QuadParityEvaluator::evaluate(const Board& board, Disc disc) const {
  return weights_[board.get_quad_parity()];
}

void QuadParityEvaluator::update(
    const Board& board,
    Disc disc,
    eval_t error,
    int beta,
    int n_sample) {
  int q_par = board.get_quad_parity();
  learning_weights_[q_par] += 2 * beta * error * 128 / n_sample;
  learning_counts_[q_par] += 1;
}

void QuadParityEvaluator::swap() {
  for (int i = 0; i < MAX; i++) {
    eval_t delta = learning_weights_[i] / std::max(2, learning_counts_[i]);
    eval_t max_diff = 1024;
    if (delta > max_diff)
      weights_[i] += max_diff;
    else if (delta < -max_diff)
      weights_[i] += -max_diff;
    else
      weights_[i] += delta;
    learning_weights_[i] = 0;
    learning_counts_[i] = 0;
    //return std::pair<eval_t, eval_t>(learning_weight_, learning_weight_);
  }
}

void QuadParityEvaluator::write(std::ostream &out) const {
  out << weights_ << std::endl;
}

void QuadParityEvaluator::read(std::istream &in) {
  //read_binary(in, weights_);
  read_binary_runlength<short, eval_t>(in, weights_);
  //in >> weights_;
}

}  // namespace oxelon
