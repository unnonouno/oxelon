#include "bit_matrix.hpp"

#include <stdexcept>

namespace oxelon {

std::string BitMatrix::to_str() const {
  std::string s;
  for (int i = 0; i < 64; ++i) {
    if (i % 8 == 0) {
      s += ' ';
    }
    if ((*this)[i]) {
      s += '1';
    } else {
      s += '0';
    }
  }
  return s;
}

BitMatrix BitMatrix::parse(const std::string& s) {
  if (s.size() != 64) {
    throw std::runtime_error("Size of string must be 64");
  }

  uint64_t value = 0;
  for (int i = 0; i < 64; i++) {
    switch (s[i]) {
      case '-':
        break;
      case 'X':
        value |= (1ull << i);
        break;
      default:
        throw std::runtime_error("");
        break;
    }
  }
  return BitMatrix(value);
}

}  // namespace oxelon
