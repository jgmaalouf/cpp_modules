#include "BitcoinExchange.hpp"
#include <iostream>

int badInput()
{
	std::cout << "Error: could not open file" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return badInput();

	BitcoinExchange obj(argv[1]);
	std::cout << obj << std::endl;
}
