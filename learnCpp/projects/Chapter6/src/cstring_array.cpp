#include <iostream>

int main() { 
  char hello_string[] = "Hello I am string.";
  std::cout << hello_string << std::endl;
  hello_string[4] = '\0';
  std::cout << hello_string << std::endl;

  return EXIT_SUCCESS;
}