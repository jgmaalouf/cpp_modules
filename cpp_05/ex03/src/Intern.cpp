#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& srcIntern)
{
	(void) srcIntern;
	std::cout << "Copy Intern created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructed" << std::endl;
}

Intern& Intern::operator=(const Intern& srcIntern)
{
	(void) srcIntern;
	return *this;
}

void strToLower(std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
		input[i] = std::tolower(input[i]);
}

void strNoSpaces(std::string& input)
{
	size_t i = 0;
	while (i < input.size())
	{
		if (input[i] == ' ')
			{
				input.erase(i, 1);
				continue;
			}
		i++;
	}
}

const char* Intern::WrongFormException::what() const throw()
{
	return "Form doesn't exist!";
}

AForm* newSCF(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* newRRF(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* newPPF(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string formCpy = form;
	strNoSpaces(form);
	strToLower(form);
	std::string forms[3] = {
		"shrubberycreation",
		"robotomyrequest",
		"presidentialpardon"
	};

	AForm* (*formArr[3])(std::string) = {
		&newSCF,
		&newRRF,
		&newPPF
	};

	for (size_t i = 0; i < 3; i++)
		if (form == forms[i] || form == forms[i] + "form")
		{
			std::cout << "Intern creates " << formCpy;
			return formArr[i](target);
		}
	throw Intern::WrongFormException();
}
