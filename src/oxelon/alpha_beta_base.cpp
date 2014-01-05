#include "alpha_beta_base.hpp"

namespace oxelon {

std::pair<Position, eval_t> AlphaBetaBase::search_next(const Board& b, Disc d) {
}

// find score from alpha to beta
AlphaBetaBase::search(
    const Board& board,
    bool passed,
    int depth,
    eval_t alpha,
    eval_t beta) {
  BitMatrix moves = board.get_move_bit();
  if (moves.size() == 0) {
    if (passed) {
      return board.get_score();
    } else {
      return search(board.make_inverse(), true, depth - 1, -beta, -alpha);
    }
  } else {
    for (BitMoveOrderingIterator it(board, *p_evaluator_);
         it.has_next(); it.go_next()) {
      BitBoard next_board = it.get_next();
      eval_t val = evaluate(next_board, false, -beta, -alpha);
      if (alpha < val) {
        alpha = val;
      }
    }
    return alpha;
  }
}

eval_t evaluate(
    const Board& board,
    eval_t alpha,
    eval_t beta) {
  return search(board, false, alpha, beta);
}

}  // namespace oxelon
