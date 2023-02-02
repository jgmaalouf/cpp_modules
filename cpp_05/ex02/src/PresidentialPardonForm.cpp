#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", false, 25, 5)
	, _target("Unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon Form", false, 25, 5)
	, _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& srcForm)
	: AForm(srcForm)
	, _target(srcForm._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& srcForm)
{
	AForm::operator=(srcForm);
	_target = srcForm._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Form Destructed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	requirementChecker(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
