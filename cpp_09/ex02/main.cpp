#include "PmergeMe.hpp"
#include <iostream>
#include <climits>

int help()
{
	std::cout << "Bad argument" << std::endl;
	std::cout << "usage: ./PmergeMe [positive integer sequence...]" << std::endl;
	return EXIT_FAILURE;
}

void parseInt(long int val, std::vector<int>& vecIntSq, std::deque<int>& dequeIntSq)
{
	if (   errno == ERANGE
		|| val < 0
		|| val > INT_MAX)
		throw std::runtime_error("Error");
	vecIntSq.push_back(val);
	dequeIntSq.push_back(val);
}

void parseArg(char* arg, std::vector<int>& vecIntSq, std::deque<int>& dequeIntSq)
{
	long int val;
	char*    endptr;

	for (size_t i = 0; arg[i] != '\0'; i++)
	{
		if (isdigit(arg[i]) || isspace(arg[i]))
			continue;
		throw std::runtime_error("Error");
	}
	
	val = std::strtol(arg, &endptr, 10);
	parseInt(val, vecIntSq, dequeIntSq);
	while (*endptr != '\0')
	{
		val = std::strtol(endptr, &endptr, 10);
		parseInt(val, vecIntSq, dequeIntSq);
	}
}

int main(int argc, char* argv[])
{
	std::vector<int> vecIntSq;
	std::deque<int> dequeIntSq;

	if (argc < 2)
		return help();
	try
	{
		for (size_t i = 1; i < argc; i++)
			parseArg(argv[i], vecIntSq, dequeIntSq);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	PmergeMe sorter3000(vecIntSq, dequeIntSq);
	sorter3000.sort();
	return EXIT_SUCCESS;
}
