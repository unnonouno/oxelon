#include "position.hpp"

#include <iostream>

namespace oxelon {

Position::Static Position::Static::inst_;

std::vector<pos_t> Position::LEFT_TABLE;
std::vector<pos_t> Position::RIGHT_TABLE;
std::vector<pos_t> Position::UP_TABLE;
std::vector<pos_t> Position::DOWN_TABLE;

void Position::init_table() {
  std::cerr << "init table" << std::endl;

  LEFT_TABLE.resize(Position::POS_MAX + 1);
  RIGHT_TABLE.resize(Position::POS_MAX + 1);
  UP_TABLE.resize(Position::POS_MAX + 1);
  DOWN_TABLE.resize(Position::POS_MAX + 1);

  for (pos_t y = 0; y < POS_WIDTH; ++y) {
    LEFT_TABLE[Position(0, y)] = POS_PASS;
    RIGHT_TABLE[Position(POS_WIDTH-1, y)] = POS_PASS;
    for (pos_t x = 1; x < POS_WIDTH; ++x) {
      LEFT_TABLE[Position(x, y)] = Position(x-1, y);
      RIGHT_TABLE[Position(x-1, y)] = Position(x, y);
    }
  }

  for (pos_t x = 0; x < POS_WIDTH; ++x) {
    UP_TABLE[Position(x, 0)] = POS_PASS;
    DOWN_TABLE[Position(x, POS_WIDTH-1)] = POS_PASS;
  }

  for (pos_t y = 1; y < POS_WIDTH; ++y) {
    for (pos_t x = 0; x < POS_WIDTH; ++x) {
      UP_TABLE[Position(x, y)] = Position(x, y-1);
      DOWN_TABLE[Position(x, y-1)] = Position(x, y);
    }
  }

  LEFT_TABLE[POS_PASS]
      = RIGHT_TABLE[POS_PASS]
      = UP_TABLE[POS_PASS]
      = DOWN_TABLE[POS_PASS]
      = POS_PASS;
}

std::string Position::to_str() const {
  if (pass()) {
    return "PS";
  } else {
    return std::string()
        + static_cast<char>('A' + get_x())
        + static_cast<char>('1' + get_y());
  }
}

}  // namespace oxelon
