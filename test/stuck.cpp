#include "../stuck.hpp"

#include <iostream>

int main() {
  using namespace std;
  tiny::stuck<int, 15> container;

  cout << "pushed: ";
  for (int i = 0; i < 10; i++) {
    cout << i << ", ";
    container.push(i);
  }
  cout << endl << "get from container: ";

  while (container.length() > 5) {
    cout << container.edge() << ", ";
    container.pop();
  }

  cout << endl;

  cout << "pushed: ";
  for (int i = 0; i < 10; i++) {
    cout << i << ", ";
    container.push(i);
  }

  cout << endl << "get from container: ";

  while (container.length()) {
    cout << container.edge() << ", ";
    container.pop();
  }

  cout << endl;

  return 0;
}
