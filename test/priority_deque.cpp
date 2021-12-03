#include "../priority_deque.hpp"

#include <algorithm>
#include <iostream>

int main() {
  using namespace std;

  cout << "begin" << endl;

  std::srand(unsigned(100));
  array<int, 14> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  tiny::priority_deque<int, int, 15> deque;

  auto random_push = [&]() {
    cout << "shuffle...";
    random_shuffle(arr.begin(), arr.end());
    cout << "end" << endl;

    for (auto itr = arr.begin(); itr != arr.end(); itr++) {
      cout << *itr << ", ";
      deque.push(*itr, 0);
    }
    cout << endl;
  };

  random_push();

  while (deque.length()) {
    cout << deque.first().key() << ", ";
    deque.pop_first();
  }

  cout << endl;

  random_push();

  while (deque.length()) {
    cout << deque.last().key() << ", ";
    deque.pop_last();
  }

  cout << endl;
}
