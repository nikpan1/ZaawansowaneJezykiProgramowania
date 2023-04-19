#include <iostream>
using std::ostream;

class Timer {
public:
  Timer();
  ~Timer();
  int hours, minutes, seconds;
  void setTime(int h, int m, int s);

  friend ostream& operator<<(ostream& os, const Timer& time);
};

Timer::Timer() {
  std::cout << "inicjalizuje" << std::endl;
}
Timer::~Timer() {
  std::cout << "usuwam" << std::endl;
}

void Timer::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

ostream& operator<<(ostream& os, const Timer& time) {
    os << "H:" << time.hours << "M:" << time.minutes << "S:" << time.seconds;
    return os;
}

int main() {
  Timer* tmr = new Timer;

  tmr->setTime(6, 30, 15);
  std::cout << *tmr << std::endl;

  delete tmr;
}

