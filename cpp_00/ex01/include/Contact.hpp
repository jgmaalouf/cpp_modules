#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include "utils.hpp"

class Contact
{
private:
	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_num;
	std::string	_darkest_secret;
public:
	Contact();
	~Contact();
	void fill_entry(int);
	void display_trunc();
	void display_full();
};

#endif