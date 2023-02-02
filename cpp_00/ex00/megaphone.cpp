#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, EXIT_SUCCESS);

	for (size_t i = 1; argv[i] != NULL ; i++)
		for (size_t j = 0; argv[i][j] != '\0'; j++)
			std::cout << (char)std::toupper(argv[i][j]);

	return (std::cout << std::endl, EXIT_SUCCESS);
}
