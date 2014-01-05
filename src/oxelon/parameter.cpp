#include "parameter.hpp"

namespace oxelon {

Parameter Parameter::create_default() {
  Parameter p;

  p.fixed_depth_ = true;
  p.mid_depth_ = 6;
  p.exact_depth_ = 16;
  p.table_size_ = 16;
  p.time_limit_ = 300;

  return p;
}

}  // namespace oxelon
