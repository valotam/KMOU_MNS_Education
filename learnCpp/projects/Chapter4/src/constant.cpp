// constant.cpp
#include <iostream>
#include "constant.h"

extern const double g_gravity{9.8};

auto PrintGravity() -> void {
  std::cout << g_gravity << " " << &g_gravity << " in constant.cpp" << std::endl;
}