#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <array>

int main()
{
	std::array<int, 3> intArr;

	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	std::cout << "Displaying array before: " << std::endl;
	for (std::array<int, 3>::iterator it = intArr.begin(); it < intArr.end(); it++)
		std::cout << *it << std::endl;
	std::array<int, 3>::iterator iter = easyfind(intArr, 3);
	*iter = 5;
	std::cout << "Displaying array after: " << std::endl;
	for (std::array<int, 3>::iterator it = intArr.begin(); it < intArr.end(); it++)
		std::cout << *it << std::endl;
	

	std::vector<int> intVec;

	intVec.push_back(23);
	intVec.push_back(234);
	std::cout << "Displaying vector before: " << std::endl;
	for (std::vector<int>::iterator it = intVec.begin(); it < intVec.end(); it++)
		std::cout << *it << std::endl;
	std::vector<int>::iterator iter2 = easyfind(intVec, 23);
	*iter2 = 42;
	std::cout << "Displaying vector after: " << std::endl;
	for (std::vector<int>::iterator it = intVec.begin(); it < intVec.end(); it++)
		std::cout << *it << std::endl;
}
