#include <PmergeMe.hpp>
#include <iostream>

int help()
{
	std::cout << "Bad argument" << std::endl;
	std::cout << "usage: ./PmergeMe [positive integer sequence...]" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
	std::vector<int> vecIntSq;
	std::list<int>   lsIntSq;
	long int         val;

	if (argc < 2)
		return help();

	for (size_t i = 1; i < argc; i++)
	{
		
		vecIntSq.push_back(val);
		lsIntSq.push_back(val);
	}
	
}
