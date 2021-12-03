#pragma once

namespace tiny {
template <class Ty, unsigned size>
class stuck {
  Ty arr[size];
  Ty* arr_edge;

 public:
  stuck() { arr_edge = (Ty*)(arr); }
  Ty& edge() { return *(arr_edge - 1); }
  Ty& oldedst() { return *arr; }
  unsigned length() { return (arr_edge - arr); }
  bool push(const Ty& val) {
    if (length() < size) {
      *arr_edge = val;
      arr_edge++;
      return true;
    } else {
      return false;
    }
  }

  bool pop() {
    if (length() > 0) {
      arr_edge--;
      return true;
    } else {
      return false;
    }
  }
};
}  // namespace tiny