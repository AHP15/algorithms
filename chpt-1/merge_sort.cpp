#include <array>
#include <vector>
#include <iostream>

template <typename T, auto size>
void merge(std::array<T, size>& arr, std::size_t start, std::size_t mid, std::size_t end) {
    using Index = std::array<T, size>::size_type;

    Index leftLength { mid - start + 1 };
    Index rightLength{ end - mid };

    std::vector<T> left{};
    std::vector<T> right{};

    for(Index i { 0 }; i < leftLength; ++i) {
        left.push_back(arr[start + i]);
    }

    for(Index i { 0 }; i < rightLength ; ++i) {
        right.push_back(arr[mid + i + 1]);
    }

    Index k { start };
    Index i { 0 };
    Index j { 0 };

    while(i < leftLength && j < rightLength) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while(i < leftLength) {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while (j < rightLength){
        arr[k] = right[j];
        ++j;
        ++k;
    }
    
}

template <typename T, auto size>
void merge_sort(std::array<T, size>& arr, std::size_t start, std::size_t end) {
    if(start >= end) return;

    std::size_t mid { (start + end) / 2 };

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main() {
    std::array<int , 9> arr {9, 5, 1, 3, 2, 4, 9, 8, 7};

    merge_sort<int, 9>(arr, 0, 9);

    for(auto& ele: arr) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

    return 0;
}