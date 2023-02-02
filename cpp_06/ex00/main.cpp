#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << "Bad input!" << std::endl, EXIT_FAILURE);
	try
	{
		std::cout.precision(1);
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
