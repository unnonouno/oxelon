#ifndef POSITION_HPP_EFB4C42D_BA64_4C68_A93A_8BBDD83003FA_
#define POSITION_HPP_EFB4C42D_BA64_4C68_A93A_8BBDD83003FA_

#include <string>
#include <vector>

#include "types.hpp"

namespace oxelon {

class Position {
 public:
  static const pos_t POS_WIDTH = 8;
  static const pos_t POS_MAX = POS_WIDTH * POS_WIDTH;
  static const pos_t POS_END = POS_WIDTH * POS_WIDTH;
  static const pos_t POS_PASS = POS_WIDTH * POS_WIDTH;
  
  Position() : pos_(0) {}
  explicit Position(const Position& p) : pos_(p.pos_) {}
  Position(pos_t x, pos_t y) : pos_(y * POS_WIDTH + x) {}
  Position(pos_t p) : pos_(p) {}

  Position& operator = (const Position& rhs) {
    pos_ = rhs.pos_;
    return *this;
  }
  
  bool operator == (const Position& p) const {
    return pos_ == p.pos_;
  }

  bool operator == (pos_t p) const {
    return pos_ == p;
  }

  operator pos_t() const { return pos_; }
  bool pass() const { return pos_ == POS_PASS; }
  bool end() const { return pos_ == POS_END; }
  
  Position& operator++() { ++pos_; return *this; }
  pos_t get_x() const { return pos_ % POS_WIDTH; }
  pos_t get_y() const { return pos_ / POS_WIDTH; }
  Position rotate() const { return Position(inverse(get_y()), get_x() ); }
  Position x_inverse() const { return Position(inverse(get_x()), get_y()); }
  Position y_inverse() const { return Position(get_x(), inverse(get_y())); }
  bool in() const { return pos_ != POS_PASS; }
  
  std::string to_str() const;

  struct left {
    Position operator()(const Position& p) {
      return Position(Position::LEFT_TABLE[p.pos_]);
    }
  };
  struct right {
    Position operator()(const Position& p) {
      return Position(Position::RIGHT_TABLE[p.pos_]);
    }
  };
  struct up {
    Position operator()(const Position& p) {
      return Position(Position::UP_TABLE[p.pos_]);
    }
  };
  struct down {
    Position operator()(const Position& p) {
      return Position(Position::DOWN_TABLE[p.pos_]);
    }
  };
  struct up_left {
    Position operator()(const Position& p) {
      return left()(up()(p));
    }
  };
  struct up_right {
    Position operator()(const Position p) {
      return right()(up()(p));
    }
  };
  struct down_left {
    Position operator()(const Position p) {
      return left()(down()(p));
    }
  };
  struct down_right {
    Position operator()(const Position p) {
      return right()(down()(p));
    }
  };
  
 private:
  static std::vector<pos_t> LEFT_TABLE;
  static std::vector<pos_t> RIGHT_TABLE;
  static std::vector<pos_t> UP_TABLE;
  static std::vector<pos_t> DOWN_TABLE;
  
  static pos_t inverse(pos_t p) {
    return POS_WIDTH-1 - p;
  }
  
  friend struct left;
  friend struct right;
  friend struct up;
  friend struct down;
  friend struct up_left;
  friend struct up_right;
  friend struct down_left;
  friend struct down_riht;

  static void init_table();
  
  struct Static {
   private:
    Static() { Position::init_table(); }
    static Static inst_;
  };
  
  pos_t pos_;
};

}  // namespace oxelon

#endif // POSITION_HPP_EFB4C42D_BA64_4C68_A93A_8BBDD83003FA_
