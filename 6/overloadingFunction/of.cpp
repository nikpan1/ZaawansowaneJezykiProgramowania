#include <iostream>

template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x + y) {
  return x + y;
}

int main() {
  int a = 1, b = 2;
  auto c = gt(a, b);
  std::cout << c << std::endl;
}

