#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;
	void				displayConstructionMessage();
public:
	AForm();
	AForm(std::string name, bool isSigned, int signGrade, int execGrade);
	AForm(const AForm& srcForm);
	virtual ~AForm();
	AForm& operator=(const AForm& srcForm);

	void			beSigned(const Bureaucrat& bureaucrat);
	void			requirementChecker(const Bureaucrat& executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& srcForm);

#endif