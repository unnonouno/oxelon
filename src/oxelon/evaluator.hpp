#ifndef EVALUATOR_HPP_F530D285_4BA6_4E19_B5CC_88FDBCD0F62C_
#define EVALUATOR_HPP_F530D285_4BA6_4E19_B5CC_88FDBCD0F62C_

#include <iostream>
#include <memory>

#include <pficommon/lang/shared_ptr.h>

#include "types.hpp"

namespace oxelon {

template <typename B>
class Evaluator {
 public:
  typedef pfi::lang::shared_ptr<Evaluator> Ptr;

  virtual ~Evaluator() {}

  virtual eval_t evaluate(const B&, Disc) const = 0;
  virtual void update(
      const B& board,
      Disc disc,
      eval_t error,
      int beta,
      int n_sample) = 0;
  virtual void swap() = 0;
  virtual void write(std::ostream &out) const = 0;
  virtual void read(std::istream &in) = 0;
};

}  // namespace oxelon

#endif // EVALUATOR_HPP_F530D285_4BA6_4E19_B5CC_88FDBCD0F62C_
