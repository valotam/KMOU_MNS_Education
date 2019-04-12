#include <iostream>

class A {
 public:
  virtual void Print() { std::cout << "A" << std::endl; }
};

class B : public A {
 public:
  virtual void Print() override { std::cout << "B" << std::endl; }
};

class C : public B {
 public:
  void Print() { std::cout << "C" << std::endl; }
};

int main() {
  A a;
  B b;
  C c;

  A *p_a = &b;
  p_a->Print();

  return 0;
}