int foo(int x) {
  return x;
}


int main() {
  int (*fcnPtr)(int) = foo;
  foo(5);
  fcnPtr(5);

  return 0;
}