#include "PhoneBook.hpp"
#include "Contact.hpp"

int	wrong_input(void)
{
	std::cout << "\033[1;31m" << "Wrong input!\n"
				<< "\033[1;33m" << "The program only accepts ADD, SEARCH and EXIT\n"
				<< std::endl;
	return (EXIT_SUCCESS);
}

int main(void)
{
	PhoneBook	phonebook;

	std::string input;
	std::cout << "\033[1;37m" << "Input the command you want:\n" << "\033[0m";
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contacts();
		else if (input == "EXIT")
			break ;
		else
			wrong_input();
		std::cout << "\033[1;37m" << "Input the command you want:\n" << "\033[0m";
	}
	return EXIT_SUCCESS;
}
