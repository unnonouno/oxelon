#include "timer.hpp"

namespace oxelon {

Timer::Timer() {
  restart();
}

double Timer::elapsed() const {
  clock_t end = ::clock();
  return static_cast<double>(end - start_) / CLOCKS_PER_SEC;
}

void Timer::restart() {
  start_ = ::clock();
}

}  // namespace oxelon
