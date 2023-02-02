#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void display_contacts();
	void search_contacts();
};

#endif