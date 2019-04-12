#include <iostream>

int main() {
  int value = 49;
  // pointer is a variable for store the address of another variable.
  int *p_value = &value; // address-of operator (&)

  std::cout << p_value << " " << *p_value << std::endl; // de-reference operator (*)
  std::cout << &value  << " " << value    << std::endl;

  using PtrInt = int *;

  PtrInt p_value2 = p_value;

  std::cout << p_value2 << " " << *p_value2 << std::endl;  // de-reference operator (*)

  return EXIT_SUCCESS;
}