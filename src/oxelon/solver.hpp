#ifndef SOLVER_HPP_67821E5C_C74E_41CE_A17B_CBA409CFC45F_
#define SOLVER_HPP_67821E5C_C74E_41CE_A17B_CBA409CFC45F_

#include <utility>

#include "board.hpp"
#include "position.hpp"
#include "types.hpp"

namespace oxelon {

class Position;

class Solver {
 public:
  virtual ~Solver() {}

  virtual std::pair<Position, eval_t> search_next(const Board& b, Disc d) = 0;
  virtual void set_max_depth(unsigned) = 0;

  virtual unsigned get_total_node() const = 0;
  virtual void clear_total_node() = 0;
  virtual unsigned get_total_leaf() const = 0;
  virtual void clear_total_leaf() = 0;
};

}  // namespace oxelon

#endif // SOLVER_HPP_67821E5C_C74E_41CE_A17B_CBA409CFC45F_
