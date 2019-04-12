// main.cpp
#include <iostream>
#include "constant.h"

//#define TEST_EXTERN
//#define TEST_STATIC
#define TEST_ENUM
//#define TEST_Q2

#ifdef TEST_EXTERN
int main() {
  std::cout << g_gravity << " " << &g_gravity << " in main.cpp" << std::endl;
  PrintGravity();

  return EXIT_SUCCESS;
}
#endif  // !TEST_EXTERN

#ifdef TEST_STATIC
void incrementAndPrint() {
  static int s_value = 1;  // static duration via static keyword.  This line is
                           // only executed once.
  ++s_value;
  std::cout << s_value << '\n';
}  // s_value is not destroyed here, but becomes inaccessible

int main() {
  incrementAndPrint();
  incrementAndPrint();
  incrementAndPrint();

  return EXIT_SUCCESS;
}
#endif  // !TEST_STATIC

#ifdef TEST_ENUM
namespace JH {
int AA = 47;
}

int main() {
  enum class Color {
    RED = 25,
    BLUE = 36,
    YELLOW,
    GREEN,
  };

  Color background_color;
  JH::AA = 12;
  background_color = Color::GREEN;

  if (background_color == Color::RED) {
  }

  switch (background_color) {
    case Color::RED:
      std::cout << static_cast<int>(background_color) << std::endl;
      break;
    case Color::BLUE:
      std::cout << static_cast<int>(background_color) << std::endl;
      break;
    case Color::YELLOW:
      std::cout << static_cast<int>(background_color) << std::endl;
      break;
    case Color::GREEN:
      std::cout << static_cast<int>(background_color) << std::endl;
      std::cout << "GREEN" << std::endl;
      break;
    default:
      break;
  }

  return EXIT_SUCCESS;
}
#endif  // TEST_ENUM

#ifdef TEST_Q2
enum class MonsterType {
  OGRE,
  SLIME,
};

int main() {
  Monster ogre{"Torg", 145};
  Monster slime{"Blurp", 23};

  PrintMonster(ogre, MonsterType::OGRE);
  PrintMonster(slime, MonsterType::SLIME);

  return EXIT_SUCCESS;
}
#endif  // TEST_Q2
