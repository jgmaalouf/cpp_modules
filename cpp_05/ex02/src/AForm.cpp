#include "AForm.hpp"

void AForm::displayConstructionMessage()
{
	std::cout << "Created: "
				<< *this << std::endl;
}

AForm::AForm()
	: _name("Unknown")
	, _isSigned(false)
	, _signGrade(150)
	, _execGrade(150)
{
	displayConstructionMessage();
}

AForm::AForm(std::string name, bool isSigned, int signGrade, int execGrade)
	: _name(name)
	, _isSigned(isSigned)
	, _signGrade(signGrade)
	, _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	displayConstructionMessage();
}

AForm::AForm(const AForm& srcAForm)
	: _name(srcAForm._name)
	, _isSigned(srcAForm._isSigned)
	, _signGrade(srcAForm._signGrade)
	, _execGrade(srcAForm._execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	displayConstructionMessage();
}

AForm::~AForm()
{
	std::cout << "AForm " << _name
				<< " is destructed" << std::endl;
}

AForm& AForm::operator=(const AForm& srcAForm)
{
	_isSigned = srcAForm._isSigned;
	return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::requirementChecker(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw std::runtime_error("Form is unsigned!");
	if (_execGrade < executor.getGrade())
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const AForm& srcAForm)
{
	out << "Form: " << srcAForm.getName()
				<< ". It is ";
	if (srcAForm.getIsSigned() == false)
		out << "not ";
	out << "signed. Grade to sign is: "
				<< srcAForm.getSignGrade()
				<< ". Grade to execute is: "
				<< srcAForm.getExecGrade();
	return out;
}
