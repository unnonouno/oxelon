#ifndef TIMER_HPP_6CFAF0F7_AA95_46A9_B14F_852867E88B8C_
#define TIMER_HPP_6CFAF0F7_AA95_46A9_B14F_852867E88B8C_

#include <time.h>

namespace oxelon {

class Timer {
 public:
  Timer();

  double elapsed() const;

  void restart();

 private:
  clock_t start_;
};

}  // namespace oxelon

#endif // TIMER_HPP_6CFAF0F7_AA95_46A9_B14F_852867E88B8C_
