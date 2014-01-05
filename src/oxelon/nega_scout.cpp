#include "nega_scout.hpp"

#include "bit_board.hpp"
#include "bit_move_ordering_iterator.hpp"
#include "board.hpp"
#include "trans_table_controller.hpp"
#include "transposition_table.hpp"

namespace oxelon {

NegaScout::NegaScout(std::auto_ptr<Evaluator<Board> > e, unsigned max)
    : p_evaluator_(e), max_depth_(max) {
}

std::pair<Position, eval_t> NegaScout::search_next(
    const Board& board,
    Disc disc) {
  leaf_count_ = node_count_ = 0;

  BitBoard b(board);
  if (disc == WHITE) {
    b.inverse();
  }

  p_trans_table_ = std::auto_ptr<TransTable>(new TransTable(10));

  eval_t value = evaluate(b, max_depth_, false, -10000000, 10000001);
  std::cerr << value << "(" << node_count_ << ", " << leaf_count_ << ")" << std::endl;

  return std::make_pair(next_move_, value);
}

eval_t NegaScout::evaluate(
    const Board& board,
    unsigned depth,
    bool passed,
    eval_t alpha,
    eval_t beta) {
  //std::cerr << board.to_zebra_str() << std::endl;

  TransTableController<TransTable> ttc(*p_trans_table_);
  if (!ttc.init_alpha_beta(board, alpha, beta)) {
    return ttc.get_return_value();
  }

  eval_t g = alpha;
  if (depth == 0) {
    leaf_count_++;
    g = p_evaluator_->evaluate(board, BLACK);

  } else {
    node_count_++;
    
    eval_t a = alpha;
    eval_t b = beta;

    bool first = true;

    BitBoard::data_type moves = board.get_move_bit();
    //std::cerr << moves.to_str() << std::endl;
    unsigned moves_size = moves.size();

    if (moves_size == 0) {
      if (passed) {
        g = board.get_score() / 1024;
      } else {
        Board next_board = board.make_inverse();
        g = -evaluate(next_board, depth - 1, true, -beta, -alpha);
      }
    } else {
      if (depth >= max_depth_) {
        std::cerr << moves.to_str() << std::endl;
      }
      BitMoveOrderingIterator it(board, *p_evaluator_);
      while (it.has_next()) {
/*      while (moves.any()) {
        BitBoard::data_type next = moves.get_next_bit();
        moves ^= next;
        BitBoard next_board(board);
        next_board.move(next);
        next_board.inverse();
  */
        BitBoard next_board = it.get_next();

        if (depth >= max_depth_ - 2) {
          BitMatrix move = board.get_blank_bit() ^ next_board.get_blank_bit();
          std::cerr << "move: " << Position(move.get_next()).to_str()
                    << " " << move.to_str() << std::endl;
        }

        /*
        // scout
        eval_t val = -evaluate(next_board, depth - 1, false, -b, -a);

        if (a < val && val < beta && !first)
          val = -evaluate(next_board, depth - 1, false, -beta, -val);
        */
        eval_t val = -evaluate(next_board, depth - 1, false, -b, -a);
        
        //a = std::max(a, val);
        if (a < val) {
          if (depth == max_depth_)
            next_move_ = (board.get_blank_bit() ^ next_board.get_blank_bit()).get_next();
          a = val;
        }

        g = std::max(g, val);
        if (depth == max_depth_) {
          std::cerr << "a: " << a << ", g: " << g << std::endl;
        }
        
        if (a >= beta) {
          if (depth == max_depth_) {
            next_move_ = (board.get_blank_bit() ^ next_board.get_blank_bit()).get_next();
            //next_move_ = next.get_next();
            std::cerr << "next: " << next_move_ << std::endl;
          }
          return a;
        }

        //b = a + 1;
        first = false;

        it.go_next();
      }
    }
  }

  ttc.update_alpha_beta(board, g, alpha, beta);
  return g;
}

}  // namespace oxelon
