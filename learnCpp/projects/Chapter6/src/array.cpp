#include <iostream>
#include <iterator>

int PrintArray(double array[], size_t size);

int main() {
  int student_score[5];
  student_score[0] = 100;
  student_score[1] = 80;
  student_score[2] = 60;
  student_score[3] = 40;
  student_score[4] = 20;
  student_score[5] =  0; // extremely critical error!

  // don't use magin number, and be carefule of index out of bounds!
  std::cout << "Students' score " << student_score << std::endl;
  for (size_t idx = 0; idx <= 5; ++idx) {
    std::cout << idx << " " << student_score[idx] << " " << &student_score[idx]
              << std::endl;
  }

  ///////////////////////////////////////////////////////////////////////////////
  ////const size_t num_student = 100'000;
  //double student_height[]{169.3, 171.2, 175.5, 178.8, };
  //size_t num_student = sizeof(student_height) / sizeof(student_height[0]);
  //size_t num_student2 = std::size(student_height);
  //size_t a = sizeof(short);
  //std::cout << "Students' height " << student_height << std::endl;
  //std::cout << "in main func, size of student_height: " << sizeof(student_height) << std::endl;
  //PrintArray(student_height, num_student);

  ///////////////////////////////////////////////////////////////////////////////
  //double max_height = 0;
  //for (size_t idx = 0; idx < num_student; ++idx)
  //  max_height =
  //      (max_height < student_height[idx]) ? student_height[idx] : max_height;
  //// change it to binary search to boost performance

  //std::cout << "Max height: " << max_height << std::endl;

  ///////////////////////////////////////////////////////////////////////////////
  //int muliple_array[3][2] = {
  //    {0, 1},
  //    {2, 3},
  //    {4, 5},
  //};

  return EXIT_SUCCESS;
}

int PrintArray(double array[], size_t size) {
  std::cout << "in PrintArray func, size of array: " << sizeof(array) << std::endl;
  try {
    for (size_t idx = 0; idx < size; ++idx) {
      std::cout << idx << " " << array[idx] << " " << &array[idx] << std::endl;
    }
  } catch (const std::exception& error) {
    throw error.what();
    //return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}