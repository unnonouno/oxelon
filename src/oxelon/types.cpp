#include "types.hpp"

namespace oxelon {

std::string disc_to_str(Disc disc) {
  switch (disc) {
    case BLACK:
      return "black";
    case WHITE:
      return "white";
    case BLANK:
      return "blank";
  }
  return "";
}

}  // namespace oxelon

