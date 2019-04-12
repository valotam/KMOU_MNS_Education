#include <iostream>
#include <string>
#include <random>

class Creature {
 public:
  Creature() {}
  Creature(std::string name, char symbol, int health,int damage, int gold)
  : name_(name), symbol_(symbol), health_(health), damage_(damage), gold_(gold) {}

  ~Creature() {}

  auto Name() const -> const std::string & { return name_; }
  auto Symbol() const -> char { return symbol_; }
  auto Health() const -> int { return health_; }
  auto Damage() const -> int { return damage_; }
  auto Gold() const -> int { return gold_; }

 protected:
  std::string name_;
  char symbol_;
  int health_;
  int damage_;
  int gold_;

 public:

  void ReduceHealth(int damage) {
    health_ -= damage;
    if (health_ < 0) health_ = 0;
  }
  bool IsDead() {
    if (health_ <= 0) return true;
    else return false;
  }
  void AddGold(int gold) {
    gold_ += gold;
  }
};

class Player : public Creature {
 public:
  Player() : level_(1) {
    symbol_ = '@';
    health_ = 10;
    damage_ = 1;
    gold_ = 0;
  }

  ~Player() {}

  void SetName(std::string name) {
    name_ = name;
  }

  void LevelUp() {
    level_ += 1;
    damage_ += 1;
  }

  int Level() const { return level_; }

 private:
   int level_;

   bool HasWon() {
     if (level_ >= 20) return true;
     else return false;
   }

};

class Monster : public Creature {
 public:
  enum class Type {
    DRAGON,
    ORC,
    SLIME,
    MAX_TYPES,
  };

  Monster(std::string name, char symbol, int health, int damage, int gold)
      : Creature(name, symbol, health, damage, gold) {}

  Monster(Type type) {
    //*this = monster_data[static_cast<int>(type)];
    switch (type) {
      case Monster::Type::DRAGON:
        *this = { "dragon", 'D', 20, 4, 100 };
        break;
      case Monster::Type::ORC:
        *this = {"orc", 'O', 4, 2, 25};
        break;
      case Monster::Type::SLIME:
        *this = {"slime", 'S', 1, 1, 10};
        break;
      default:
        break;
    }
  }

  ~Monster() {}

  static Monster GetRandomMonster() {
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dis(
        0, static_cast<int>(Type::MAX_TYPES) - 1);

    int random_number = dis(gen);

    return Monster(static_cast<Type>(random_number));
  }

 private:
};



int main() {
  Monster mon1 = Monster::GetRandomMonster();
  Monster mon2 = Monster::GetRandomMonster();
  Monster mon3 = Monster::GetRandomMonster();
  Monster mon4 = Monster::GetRandomMonster();

   return 0;
}