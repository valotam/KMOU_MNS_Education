#include <iostream>
#include <sstream>  // std::streamsize
#include <iterator> // std::size
#include <limits>   // std::numeric_limits
#include <iomanip>

int main() {
  //double temps[365] { };

  //std::cout << temps << std::endl;
  //std::cout << &temps[0] << std::endl;

  //enum class Animal { 
  //  chicken, //0
  //  dog,    // 1
  //  cat,    // 2
  //  elephant, //3
  //  duck, // 4
  //  snake, // 5
  //  NUM_ANIMALS, // 6
  //};

  //int legs[static_cast<int>(Animal::NUM_ANIMALS)] =   {2, 4, 4, 4, 2, 0};

  //std::cout << legs[static_cast<int>(Animal::elephant)] << std::endl;



  //float array[]{0.0000001, 0.1, 0.2, 0.0, 0.3, 1.0, 0.5, 0.4, 0.7};
  ////int num_array = sizeof(array) / sizeof(array[0]);  // std::size(array);
  //int num_array = std::size(array);

  //for (size_t idx = 0; idx < num_array; idx++) {
  //std::
  //  cout << array[idx] << std::endl;
  //}

  //// Q4
  ////while (true) {
  ////  int num;
  ////  std::cout << "Enter a number from 1 to 9: ";
  ////  std::cin >> num;

  ////  // if the user entered something invalid
  ////  if ((num < 1 || num > 9) || std::cin.fail()) {
  ////    std::cin.clear(); // unset failbit
  ////    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
  ////    continue;
  ////  }

  ////  for (size_t idx = 0; idx < num_array; idx++) {
  ////    std::cout << array[idx] << std::endl;
  ////  }
  ////  std::cout << array[num] << std::endl;
  ////  break;
  ////}

  //// Q5
  //double min {10};
  //for (size_t idx = 0; idx < num_array; idx++) {
  //  if (min > array[idx]) {
  //    min = array[idx];
  //  }
  //}
  //std::cout << min << std::endl;

  //// Q6
  //for (int i = 0; i < num_array; ++i) {
  //  int min_idx = i;
  //  for (int j = i + 1; j < num_array; ++j) {
  //    if (array[i] > array[j]) {
  //      min_idx = j;
  //    }
  //  }
  //  double temp = array[min_idx];
  //  array[min_idx] = array[i];
  //  array[i] = temp;
  //}

  //for (size_t idx = 0; idx < num_array; idx++) {
  //  std::cout << array[idx] << " ";
  //}
  //std::cout << std::endl;

  //int size = 10;
  //while (true) {
  //  double *p_array = new double[size];
  //  delete[] p_array;
  //}


  // Q9
  //int num_name;
  //std::cin >> num_name;

  //std::string *p_names = new std::string[num_name];

  //for (int i = 0; i < num_name; ++i) {
  //  std::cin >> p_names[i];
  //}

  //delete[] p_names;

  // Q10
  double array[]{0.0000001, 0.1, 0.2, 0.0, 0.3, 1.0, 0.5, 0.4, 0.7};

  for (double element : array) {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}