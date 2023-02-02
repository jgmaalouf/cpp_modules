#include "Form.hpp"

void Form::displayConstructionMessage()
{
	std::cout << "Created: "
				<< *this << std::endl;
}

Form::Form()
	: _name("Unknown")
	, _isSigned(false)
	, _signGrade(150)
	, _execGrade(150)
{
	displayConstructionMessage();
}

Form::Form(std::string name, bool isSigned, int signGrade, int execGrade)
	: _name(name)
	, _isSigned(isSigned)
	, _signGrade(signGrade)
	, _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	displayConstructionMessage();
}

Form::Form(const Form& srcForm)
	: _name(srcForm._name)
	, _isSigned(srcForm._isSigned)
	, _signGrade(srcForm._signGrade)
	, _execGrade(srcForm._execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	displayConstructionMessage();
}

Form::~Form()
{
	std::cout << "Form " << _name
				<< " is destructed" << std::endl;
}

Form& Form::operator=(const Form& srcForm)
{
	_isSigned = srcForm._isSigned;
	return *this;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& srcForm)
{
	out << "Form " << srcForm.getName()
				<< ". It is ";
	if (srcForm.getIsSigned() == false)
		out << "not ";
	out << "signed. Grade to sign is: "
				<< srcForm.getSignGrade()
				<< ". Grade to execute is: "
				<< srcForm.getExecGrade();
	return out;
}
