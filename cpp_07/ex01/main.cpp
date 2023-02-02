#include "iter.hpp"

template<typename T>
void increment(T& element)
{
	element++;
}

int main ()
{
	// Allocated int array
	int *array = new int[5];
	std::cout << "Before applying iter to allocated int array" << std::endl;
	for(int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;
	iter(array, 5, &increment);
	std::cout << "After applying iter to allocated int array" << std::endl;
	for(int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;
	delete[] array;

	// Char array
	char arr[3] = {'a', 'b', 'c'};
	std::cout << "Before applying iter to char array" << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << arr[i] << std::endl;
	iter(arr, 3, &increment);
	std::cout << "After applying iter to char array" << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << arr[i] << std::endl;

	return 0;
}