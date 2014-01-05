#ifndef POWER_HPP_CAB6C4C6_9D00_48A2_951C_FA617764750B_
#define POWER_HPP_CAB6C4C6_9D00_48A2_951C_FA617764750B_

namespace oxelon {

template <int N>
struct pow3 {
  static const unsigned val = 3 * pow3<N-1>::val;
};

template <>
struct pow3<0> {
  static const unsigned val = 1;
};

}  // namespace oxelon

#endif // POWER_HPP_CAB6C4C6_9D00_48A2_951C_FA617764750B_
