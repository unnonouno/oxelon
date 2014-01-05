#ifndef TYPES_HPP_C7A89BFD_4BF8_4D27_96FC_45F38CACD4D4_
#define TYPES_HPP_C7A89BFD_4BF8_4D27_96FC_45F38CACD4D4_

#include <string>

namespace oxelon {

typedef unsigned char pos_t;
typedef long eval_t;

enum Disc {
  BLACK = -1,
  WHITE = 1,
  BLANK = 0
};

std::string disc_to_str(Disc disc);
  
}  // namespace oxelon

#endif // TYPES_HPP_C7A89BFD_4BF8_4D27_96FC_45F38CACD4D4_
