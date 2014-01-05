#ifndef BIT_MOVE_HPP_81183565_D78A_43EB_934F_F4FC2E646A86_
#define BIT_MOVE_HPP_81183565_D78A_43EB_934F_F4FC2E646A86_

#include "bit_matrix.hpp"
#include "position.hpp"

namespace oxelon {

class BitMove {
 public:
  BitMove(const Position& pos, Disc disc, const BitMatrix& move)
      : flip_mask_(move), position_(pos), disc_(disc) {
  }

  int get_mobility_diff(const BitMatrix& blank) const;
  
  const BitMatrix& get_bits() const { return flip_mask_; }
  Disc get_disc() const { return disc_; }
  Position get_position() const { return position_; }

 private:
  BitMatrix flip_mask_;
  Position position_;
  Disc disc_;
};

inline int BitMove::get_mobility_diff(const BitMatrix& blank) const {
  BitMatrix tmp = flip_mask_.make_round();
  //    tmp.set(position_);
  return (tmp & blank).size();
}

}  // namespace oxelon

#endif // BIT_MOVE_HPP_81183565_D78A_43EB_934F_F4FC2E646A86_
