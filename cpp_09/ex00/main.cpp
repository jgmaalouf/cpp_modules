#include "BitcoinExchange.hpp"
#include <iostream>

int main()
{
	BitcoinExchange obj("input.txt");

	std::cout << obj << std::endl;
	// obj.printMap(2);
}
