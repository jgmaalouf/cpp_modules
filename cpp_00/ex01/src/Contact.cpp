#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
	static int i;

	_index = ++i;
}

Contact::~Contact() {}

std::string	store_string(void)
{
	std::string input;

	while (std::getline(std::cin, input))
	{
		if (!isstr_print(input))
		{
			std::cout << "Wrong input! Only printable characters accepted.\nTry again: ";
			continue;
		}
		if (input == "")
		{
			std::cout << "You didn't input anything!\nTry again: ";
			continue;
		}
		return input;
	}
	return input;
}

std::string	store_num(void)
{
	std::string input;

	while (std::getline(std::cin, input))
	{
		if (!isstr_num(input))
		{
			std::cout << "Wrong input! Only numerical characters accepted.\nTry again: ";
			continue;
		}
		if (input == "")
		{
			std::cout << "You didn't input anything!\nTry again: ";
			continue;
		}
		return input;
	}
	return input;
}

void Contact::fill_entry(int i)
{
	_index = i + 1;

	std::cout << "Enter first name: ";
	_first_name = store_string();
	
	std::cout << "\nEnter last name: ";
	_last_name = store_string();
	
	std::cout << "\nEnter nickname: ";
	_nickname = store_string();
	
	std::cout << "\nEnter phone_num: ";
	_phone_num = store_num();
	
	std::cout << "\nEnter darkest secret: ";
	_darkest_secret = store_string();
	std::cout << "\033[1;32m" << "\nContact has been successfully added\n";
}

std::string	trunc_str(std::string field)
{
	if (field.size() > 10)
	{
		field = field.substr(0, 9);
		field += ".";
	}
	while (field.size() < 10)
		field += " ";
	return (field);
}

void Contact::display_trunc(void)
{
	std::cout << "|"
				<< trunc_str(std::to_string(_index))
				<< "|"
				<< trunc_str(_first_name)
				<< "|"
				<< trunc_str(_last_name)
				<< "|"
				<< trunc_str(_nickname)
				<< "|\n";
}

void Contact::display_full(void)
{
	std::cout << "\nFirst Name: " << _first_name
				<< "\nLast Name: " << _last_name
				<< "\nNickname: " << _nickname
				<< "\nPhone Number: " << _phone_num
				<< "\nDarkest Secret: " << _darkest_secret
				<< "\n"
				<< std::endl;
}
