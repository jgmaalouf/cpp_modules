#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", false, 72, 45)
	, _target("Unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", false, 72, 45)
	, _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& srcForm)
	: AForm(srcForm)
	, _target(srcForm._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& srcForm)
{
	AForm::operator=(srcForm);
	_target = srcForm._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Form Destructed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	requirementChecker(executor);
	std::srand((unsigned)std::time(NULL));
	int chance = std::rand() % 2;
	if (chance == 1)
	{
		std::cout << "...DrDrDrDrDrDrDr...\n"
					<< _target << " has been robotomized"
					<< std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
}
