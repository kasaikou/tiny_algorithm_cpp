#pragma once

namespace tiny {
template <class Key, class Val>
struct key_value {
  Key __key;
  Val value;
  key_value() {}
  key_value(const Key& key, const Val& val) : __key(key), value(val) {}
  key_value(const key_value<Key, Val>& kv) : __key(kv.__key), value(kv.value) {}
  Key key() const { return __key; }

  key_value& operator=(const key_value<Key, Val>& kv) {
    __key = kv.__key;
    value = kv.value;
    return *this;
  }
};

// priority_deque:
template <class Key, class Val, unsigned size>
class priority_deque {
  using pair = key_value<Key, Val>;
  pair arr[size];  // array
  pair *arr_first, *arr_last;
  pair *ptr_first, *ptr_last;
  unsigned used;

  // increment pointer
  pair* inc(pair* src) const {
    auto res = (src != arr_last ? (src + 1) : arr_first);
    return res;
  }
  // decrement pointer
  pair* dec(pair* src) const {
    auto res = (src != arr_first ? (src - 1) : arr_last);
    return res;
  }
  // add pointer
  pair* add(pair* src, const unsigned& adding) const {
    auto res = src;
    for (unsigned i = 0; i < adding; i++) {
      res = inc(res);
    }
    return res;
  }

 public:
  // default constractor
  priority_deque() : used(0) {
    arr_first = (pair*)(arr);
    arr_last = (pair*)(arr) + (size - 1);
  }

  pair& first() { return *ptr_first; }
  pair& last() { return *ptr_last; }
  unsigned& length() { return used; }
  pair& at(const unsigned& idx) { return *add(ptr_first, idx); }

  bool push(const pair& kv) {
    if (used < 1) {
      ptr_first = arr_first;
      ptr_last = arr_first;
      *(ptr_first) = kv;
      used = 1;  // reset count
      return true;

    } else if (used == 1) {
      if (kv.__key < ptr_first->__key) {
        ptr_first = dec(ptr_first);
        *(ptr_first) = kv;
      } else {
        ptr_last = inc(ptr_last);
        *(ptr_last) = kv;
      }
      used++;  // increment count
      return true;

    } else if (used < size) {
      auto mid_key = at((used >> 1)).__key;
      if (kv.__key < mid_key) {
        // push from first

        auto from = ptr_first;
        ptr_first = dec(ptr_first);
        auto to = ptr_first;

        for (; from->__key < kv.__key; to = inc(to), from = inc(from)) {
          *to = *from;
        }
        *to = kv;

      } else {
        // push from last
        auto from = ptr_last;
        ptr_last = inc(ptr_last);
        auto to = ptr_last;

        for (; from->__key > kv.__key; to = dec(to), from = dec(from)) {
          *to = *from;
        }
        *to = kv;
      }
      used++;  // increment count
      return true;

    } else {
      return false;
    }
  }

  bool push(const Key& key, const Val& val) {
    return push(key_value<Key, Val>(key, val));
  }

  bool pop_first() {
    if (used > 0) {
      ptr_first = inc(ptr_first);
      used--;
      return true;
    } else
      return false;
  }

  bool pop_last() {
    if (used > 0) {
      ptr_last = dec(ptr_last);
      used--;
      return true;
    } else
      return false;
  }
};
}  // namespace tiny
