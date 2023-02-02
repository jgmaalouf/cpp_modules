#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Unknown"), _grade(150) 
{
	std::cout << "Bureaucrat " << _name
				<< " created with grade: "
				<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade) 
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << _name
				<< " created with grade: "
				<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& srcBureaucrat)
	: _name(srcBureaucrat._name)
	, _grade(srcBureaucrat._grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << _name
				<< " created with grade: "
				<< _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat "<< _name
				<< " destructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& srcBureaucrat)
{
	_grade = srcBureaucrat._grade;
	return *this;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
					<< " because bureaucrat's grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed "
					<< form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (1 > _grade - 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (150 < _grade + 1)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& srcBureaucrat)
{
	out << srcBureaucrat.getName()
		<< ", bureaucrat grade "
		<< srcBureaucrat.getGrade()
		<< ".";
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
