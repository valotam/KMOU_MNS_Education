#include <iostream>
#include <cassert>
// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// BinarySearch() should return the index of the target element
//                if the target is found, -1 otherwise.
int BinarySearch(const int *array, int target, int min_idx, int max_idx);

int main() {
  const int ARRAY_MAX_SIZE = 15;
  const int array[ARRAY_MAX_SIZE] = {
     3,  6,  8, 12, 14,
    17, 20, 21, 26, 32,
    36, 37, 42, 44, 48
  };

  // We will test a bunch of values to see if they produce the expected results
  const int TEST_SIZE = 9;
  // Here are the test target values
  const int target_values[TEST_SIZE] = {0, 3, 12, 13, 22, 26, 43, 44, 49};
  // And here are the expected results for each value
  const int expected_values[TEST_SIZE] = {-1, 0, 3, -1, -1, 8, -1, 13, -1};

  // Loop through all of the test values
  for (int count = 0; count < TEST_SIZE; ++count) {
    // See if our test value is in the array
    int min_idx = 0;
    int max_idx = ARRAY_MAX_SIZE - 1;
    int index = BinarySearch(array, target_values[count], min_idx, max_idx);
    // If it matches our expected value, then great!
    if (index == expected_values[count]) {
      std::cout << "test value "     << target_values[count]   << " passed!\n";
      std::cout << "expected value " << expected_values[count] << "\n";
      std::cout << "index "          << index                  << "\n";
    }
    else  // otherwise, our BinarySearch() function must be broken
      std::cout << "test value " << target_values[count]
                << " failed.  There's something wrong with your code!\n";
  }

  return EXIT_SUCCESS;
}

int BinarySearch(const int *array, int target, int min, int max) {
  assert(array);  // make sure array exists

  while (min <= max) {
    // implement this iteratively
    int mid =
        min +
        ((max - min) / 2);  // this way of calculating mid avoids overflow

    if (array[mid] > target) {
      // if array[mid] > target, then we know the number must be in the
      // lower half of the array we can use mid - 1 as the upper index,
      // since we don't need to retest the mid next iteration
      max = mid - 1;
    } else if (array[mid] < target) {
      // if array[mid] < target, then we know the number must be in the
      // upper half of the array we can use mid + 1 as the lower index,
      // since we don't need to retest the mid next iteration
      min = mid + 1;
    } else
      return mid;
  }

  return -1;
}