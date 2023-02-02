#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

/*
	Here, I have a static int that references the contacts array
	to set the values of the contact. If I reach the end of the
	array, i is set back to 0. This is for changing the oldest contact
	if there is no more space left.
*/
void	PhoneBook::add_contact(void)
{
	static int	i;
	
	if (i == MAX_CONTACTS)
		i = 0;
	_contacts[i].fill_entry(i);
	i++;
}

void	PhoneBook::display_contacts(void)
{
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|index     |first_name|last_name |nickname  |\n";
	std::cout << "|-------------------------------------------|\n";
	for (size_t i = 0; i < MAX_CONTACTS; i++)
		_contacts[i].display_trunc();
	std::cout << "|-------------------------------------------|\n\n";
	
}

void	PhoneBook::search_contacts(void)
{
	std::string input;
	int	index;

	display_contacts();
	std::cout << "Insert the index of the entry to display: ";
	while (std::getline(std::cin, input))
	{
		if (isstr_num(input))
		{
			index = std::atoi(input.c_str());
			if (index > 0 && index <= MAX_CONTACTS)
			{
				_contacts[index - 1].display_full();
				return ;
			}
		}
		std::cout << "Wrong input! Request an index from the list. Input must be numerical\n";
		std::cout << "Please try again: ";
	}
}
