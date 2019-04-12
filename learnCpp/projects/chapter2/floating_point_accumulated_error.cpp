#include <iomanip>
#include <iostream>
#include <limits>

int main() {
  std::cout << "float: " << sizeof(float) << std::endl;
  std::cout << std::numeric_limits<float>::max() << std::endl;
  std::cout << std::numeric_limits<float>::min() << std::endl;
  std::cout << std::numeric_limits<float>::lowest() << std::endl;

  {
    constexpr float begin_value = 1e9f;
    float value = begin_value;
    std::cout << std::setprecision(10'000);
    std::cout << value << std::endl;
    for (size_t idx = 0; idx < 1'000'000; ++idx)
      value += +1e0f; // 10^0 = 1
    std::cout << value << std::endl;
    std::cout << std::boolalpha;
    std::cout << (value == begin_value) << std::endl;

    //constexpr float begin_value = 1e9f;
    //float value = begin_value;
    //std::cout << std::setprecision(10'000);
    //std::cout << value << std::endl;
    //float accumulated_little_value = 0.0f;
    //for (size_t idx = 0; idx < 1'000'000; ++idx)
    //  accumulated_little_value +=
    //      +1e0f;  // calculate values of a little and it can increase
    //value += accumulated_little_value;
    //std::cout << value << std::endl;
    //std::cout << (value == begin_value) << std::endl;
  }

  std::cout << std::setprecision(3);
  std::cout << std::endl;
  std::cout << "double: " << sizeof(double) << std::endl;
  std::cout << std::numeric_limits<double>::max() << std::endl;
  std::cout << std::numeric_limits<double>::min() << std::endl;
  std::cout << std::numeric_limits<double>::lowest() << std::endl;

  {
    constexpr double begin_value = 1e9;
    double value = begin_value;
    std::cout << std::setprecision(10'000);
    std::cout << value << std::endl;
    for (size_t idx = 0; idx < 1'000'000; ++idx)
      value += +1e-1;  // 10^0 = 1
    std::cout << value << std::endl;
    std::cout << (value == begin_value) << std::endl;
  }

  return EXIT_SUCCESS;
}