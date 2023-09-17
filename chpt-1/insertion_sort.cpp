#include <array>
#include <iostream>
#include <span>

template <typename T, auto size>
std::array<T, size> insertion_sort(std::array<T, size>& arr) {
  using Index = std::array<T, size>::size_type;
  for(Index i {1}; i < size; ++i) {
    T key{ arr[i] };

    Index j { i - 1 };
    while(static_cast<int>(j) >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }

  return arr;
};

template <typename T, auto size>
void print_array(const std::array<T, size>& arr) {
  for (auto& element: arr) {
    std::cout << element << '\n';
  }
}

int main() {
  std::array<int, 6> arr{5, 2, 4, 6, 1, 3};

  insertion_sort<int, 6>(arr);

  print_array<int, 6>(arr);

  return 0;
}