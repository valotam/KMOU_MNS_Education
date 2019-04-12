#include <iostream>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v1;
  std::vector<int> v2;

  clock_t begin, end;
  begin = clock();
  for (size_t i = 0; i < 1'000'000; i++) {
    v1.push_back(1);
  }
  end = clock();  // �ð�����
  std::cout << "����ð� : " << ((end - begin)) << std::endl;

  v2.reserve(1'000'000'000);
  begin = clock();
  for (size_t i = 0; i < 1'000'000'000; i++) {
    v2.push_back(1);
  }
  end = clock();  // �ð�����
  std::cout << "����ð� : " << ((end - begin)) << std::endl;

  return 0;
}