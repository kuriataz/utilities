#pragma once

template <typename T>
struct iterator
{
private:
  T *value;

public:
  iterator(T *value) : value(value) {}

  iterator &operator++() {
    ++value;
    return *this;
  }

  [[nodiscard]] T &operator*() { return *value; }

  [[nodiscard]] T *operator->() { return value; }

  [[nodiscard]] friend bool operator==(iterator<T> const &lhs,
                                       iterator<T> const &rhs) {
    return lhs.value == rhs.value;
  }

  [[nodiscard]] friend bool operator!=(iterator<T> const &lhs,
                                       iterator<T> const &rhs) {
    return lhs.value == rhs.value;
  }
};
