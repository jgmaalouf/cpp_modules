#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> c;

	while (!a.empty() && !b.empty())
	{
		if (a[0] > b[0])
		{
			c.push_back(b[0]);
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin());
		}
	}
	// at this point either a or b are empty
	while (!a.empty())
	{
		c.push_back(a[0]);
		a.erase(a.begin());
	}
	
	while (!b.empty())
	{
		c.push_back(b[0]);
		b.erase(b.begin());
	}
	return c;
}

std::vector<int> mergesort(std::vector<int> array, int n)
{
	if (n == 1)
		return array;

	std::vector<int> arrayOne;
	for (size_t i = 0; i < n / 2; i++)
		arrayOne.push_back(array[i]);
	
	std::vector<int> arrayTwo;
	for (size_t i = n / 2; i < n; i++)
		arrayTwo.push_back(array[i]);
	
	arrayOne = mergesort(arrayOne, arrayOne.size());
	arrayTwo = mergesort(arrayTwo, arrayTwo.size());

	return merge(arrayOne, arrayTwo);
}

int main()
{
	std::vector<int> array = {3, 2, 5, 6, 8, 9, 34, 23};
	std::vector<int> sorted = mergesort(array, array.size());
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << ' ';
	std::cout << std::endl;
}