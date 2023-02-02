#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", false, 145, 137)
	, _target("Unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", false, 145, 137)
	, _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& srcForm)
	: AForm(srcForm)
	, _target(srcForm._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Form Destructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& srcForm)
{
	AForm::operator=(srcForm);
	_target = srcForm._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	requirementChecker(executor);

	std::ofstream file;
	file.open(_target + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (!file.good())
		throw std::runtime_error("File not good!");
	file << "           _-_"			<< std::endl
         <<"        /~~   ~~\\"		<< std::endl
         <<"     /~~         ~~\\"	<< std::endl
         <<"    {               }"	<< std::endl
         <<"     \\  _-     -_  /"	<< std::endl
         <<"       ~  \\\\ //  ~"		<< std::endl
         <<"    _- -   | | _- _"	<< std::endl
         <<"      _ -  | |   -_"	<< std::endl
         <<"          // \\\\"		<< std::endl;
}
