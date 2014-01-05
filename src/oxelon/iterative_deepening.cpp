#include "iterative_deepening.hpp"


#include <utility>
#include <memory>

#include "board.hpp"

namespace oxelon {

IterativeDeepening::IterativeDeepening(
    std::auto_ptr<Solver> s,
    double max_time,
    unsigned first_depth,
    unsigned exact_depth)
    : p_solver_(s),
      rest_time_(max_time),
      current_depth_(first_depth),
      exact_depth_(exact_depth) {
}

std::pair<Position, eval_t> IterativeDeepening::search_next(
    const Board& board,
    Disc disc) {
  // 途中まで固定で，後半のみ反復深化
  size_t rest_blank = board.count_disc(BLANK);
  if (rest_blank < Board::COUNT_MAX / 2) {
    double total_time = 0;
    
    std::pair<Position, eval_t> ret;
    // iterative deepening
    while (true) {
      boost::timer  t;
      if (rest_blank - current_depth_ <= 3 || rest_blank <= exact_depth_) {
        p_solver_->set_max_depth(Board::COUNT_MAX);
      }
      ret = p_solver_->search_next(board, disc);
      total_time += t.elapsed();

      // 深化後の探索コストを、トータルで2倍程度あれば大丈夫と予測
      if (total_time * 3 <
          rest_time_  / std::max(1, (static_cast<int>(rest_blank) - 8) / 2)
          && rest_blank > current_depth_) {
        p_solver_->set_max_depth(++current_depth_);
        //std::cerr << "CurDepth: " << current_depth_ << std::endl;
      } else {
        break;
      }
    }
    
    rest_time_ -= total_time;
    //std::cerr << "\tTime: " << total_time << std::endl;
    return ret;
    
  } else {
    boost::timer  t;
    std::pair<Position, eval_t> ret = p_solver_->search_next(board, disc);
    double total_time = t.elapsed();
    rest_time_ -= total_time;
    //std::cerr << "\tTime: " << total_time << std::endl;
    return ret;
  }
}

}
