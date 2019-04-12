#include <iostream>

int main(int argc, char * argv[]) {
  int x = 5; // this is an initialization
  x = x - 2; // this is an assignment
  std::cout << x << std::endl; // x = 3

  int y = x;
  std::cout << y << std::endl; // y = 3

  // Quiz
  x = x - 1; // x = 2
  std::cout << y << std::endl;  // #1

  {
    //int x = x;
    int x = y;
    std::cout << x << std::endl;  // #2
  }
  std::cout << x << std::endl;  // #3

  //int z;
  //std::cout << z << std::endl; // #4

  return EXIT_SUCCESS;
}