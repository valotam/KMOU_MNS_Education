#include <iostream>
#include <cmath>

int main() {
  double zero = 0.0;
  double pos_inf =  1.0 / zero;
  double neg_inf = -1.0 / zero;
  double nan     =  0.0 / zero;

  std::cout << std::boolalpha;
  std::cout << pos_inf <<" " << std::isinf(pos_inf) << std::endl;
  std::cout << neg_inf << " " << std::isinf(neg_inf) << std::endl;
  std::cout << nan << " " << std::isnan(nan) << std::endl;

  return EXIT_FAILURE;
}