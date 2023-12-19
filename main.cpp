#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T> &arr)
{
	for (std::size_t i{1}; i < arr.size(); i++)
	{
		T key{arr[i]};
		std::size_t j{i - 1};
		while (static_cast<int>(j) >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	std::vector<int> arr{5, 4, 3, 2, 1};
	insertion_sort(arr);

	for (auto number : arr)
	{
		std::cout << number << ' ';
	}
	std::cout << '\n';
	return 0;
}
