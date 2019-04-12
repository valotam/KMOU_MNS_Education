#include <iostream>

//#define OCCUR_ERROR

int main() {
  const size_t num_value = 5;
  double double_array[num_value]{ 1.5, 3.2, 0, };
  double *p_double = nullptr;

#ifdef OCCUR_ERROR
  for (size_t idx = 0; idx < 5; idx++) {
    std::cout << p_double[idx] << std::endl;
  }
#else
  if (p_double == nullptr) {
    std::cerr << "Nullptr!" << std::endl;
  } else {
    p_double = double_array;
    for (size_t idx = 0; idx < num_value; idx++) {
      std::cout << p_double[idx] << std::endl;
    }
  }
#endif  // !OCCUR_ERROR

  return EXIT_SUCCESS;
}