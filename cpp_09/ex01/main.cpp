#include "RPN.hpp"
#include <iostream>

int badInput()
{
	std::cout << "Error: bad input" << std::endl;
	std::cout << "Usage: ./RTN <expression>" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return badInput();
	try
	{
		RPN obj(argv[1]);
		std::cout << obj.calculate() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
