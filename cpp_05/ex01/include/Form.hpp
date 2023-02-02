#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;
	void				displayConstructionMessage();
public:
	Form();
	Form(std::string name, bool isSigned, int signGrade, int execGrade);
	Form(const Form& srcForm);
	~Form();
	Form& operator=(const Form& srcForm);

	void	beSigned(const Bureaucrat& bureaucrat);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& srcForm);

#endif