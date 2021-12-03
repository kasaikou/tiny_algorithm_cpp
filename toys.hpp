#pragma once

namespace tiny {
template <class Ty>
Ty min(const Ty& l, const Ty& r) {
  return (r < l ? r : l);
}

template <class Ty>
Ty max(const Ty& l, const Ty& r) {
  return (r > l ? r : l);
}

template <class Ty>
Ty abs(const Ty& val) {
  constexpr Ty zero = static_cast<Ty>(0);
  return (val < zero ? -val : val);
}
}  // namespace tiny
