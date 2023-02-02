#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& srcIntern);
	~Intern();
	Intern& operator=(const Intern& srcIntern);

	AForm* makeForm(std::string form, std::string target);

	class WrongFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
