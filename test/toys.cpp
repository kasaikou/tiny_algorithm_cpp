#include "../toys.hpp"

#include <iostream>

int main() {
  using namespace std;

  // min()
  cout << "min(1, 5): " << tiny::min(1, 5) << endl;
  cout << "min(5, 1): " << tiny::min(5, 1) << endl;

  // max()
  cout << "max(1, 5): " << tiny::max(1, 5) << endl;
  cout << "max(5, 1): " << tiny::max(5, 1) << endl;

  // abs()
  cout << "abs(10): " << tiny::abs(10) << endl;
  cout << "abs(0): " << tiny::abs(0) << endl;
  cout << "abs(-10): " << tiny::abs(-10) << endl;
  return 0;
}