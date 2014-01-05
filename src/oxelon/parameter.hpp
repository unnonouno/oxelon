#ifndef PARAMETER_HPP_DF7FAF9D_F8A1_4C4D_835F_2C9B128A4F0E_
#define PARAMETER_HPP_DF7FAF9D_F8A1_4C4D_835F_2C9B128A4F0E_

namespace oxelon {

struct Parameter {
  static Parameter create_default();

  /// Don't change search depth when the time remains
  bool fixed_depth_;
  /// Depth of search at middle of a game
  unsigned mid_depth_;
  /// Depth of search when it starts to exact search
  unsigned exact_depth_;
  /// Size of transposition table
  unsigned table_size_;
  /// Time limit
  unsigned time_limit_;
};

}  // namespace oxelon

#endif // PARAMETER_HPP_DF7FAF9D_F8A1_4C4D_835F_2C9B128A4F0E_
