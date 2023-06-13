#include <iostream>
#include <vector>

std::vector<int> insertionsort(std::vector<int> arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			std::swap(arr[j], arr[j - 1]);
			j--;
		}
	}
	return arr;
}

int main()
{
	std::vector<int> array = {3, 2, 5, 6, 8, 9, 34, 23};
	std::vector<int> sorted = insertionsort(array);
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << ' ';
	std::cout << std::endl;
}