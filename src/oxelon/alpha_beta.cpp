#include "alpha_beta.hpp"

namespace oxelon {

std::pair<Position, eval_t> AlphaBeta::search_next(const Board& b, Disc d) {
}

eval_t AlphaBeta::evaluate(
    const Board& board,
    bool passed,
    unsigned depth,
    eval_t alpha,
    eval_t beta) {
  if (depth == 0) {
    return p_evaluator_->evaluate(board, BLACK);
  }

  BitBoard::data_type moves = board.get_move_bit();
  unsigned move_size = moves.size();
  if (move_size == 0) {
    if (passed) {
      return board.get_score();
    } else {
      Board next_board = board.make_inverse();
      return -evaluate(next_board, true, depth - 1, -beta, -alpha);
    }
  } else {
    while (moves.any() && alpha < beta) {
      BitBoard::data_type next = moves.get_next_bit();
      moves ^= next;
      BitBoard next_board(board);
      next_board.move(next);

      eval_t val = -evaluate(next_board, false, depth - 1, -beta, -alpha);
      if (val > alpha) {
        alpha = val;
      }
    }
    return alpha;
  }
}

}  // namespace oxelon
