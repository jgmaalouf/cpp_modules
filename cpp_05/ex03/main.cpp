#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main ()
{
	std::cout << "Creating two bureaucrats Jimbo and Jacuzo" << std::endl;
	Bureaucrat Jimmy("Jimbo", 55);
	Bureaucrat Jacuzi("Jacuzo", 146);

	std::cout << "\nCreating an intern to create ShrubberyCreationForm" << std::endl;
	Intern jack;
	AForm* scf;
	try
	{
		scf = jack.makeForm("shrubbery creation", "42");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(0);
	}
	std::cout << "\nLetting Jacuzo execute the form unsigned" << std::endl;
	Jacuzi.executeForm(*scf);

	std::cout << "\nLetting Jacuzo sign the form" << std::endl;
	Jacuzi.signForm(*scf);

	std::cout << "\nLetting Jimbo sign the form" << std::endl;
	Jimmy.signForm(*scf);

	std::cout << "\nLetting Jacuzo execute the form now" << std::endl;
	Jacuzi.executeForm(*scf);

	std::cout << "\nCreating a new bureaucrat with grade 137 to execute the form" << std::endl;
	Bureaucrat Hitchcock("Alfred Hitchcock", 137);
	Hitchcock.executeForm(*scf);

	// std::cout << "\nCreating Robotomy request form" << std::endl;
	// RobotomyRequestForm rrf("Schweinshaxe");

	// std::cout << "\nAsking Hitchcock to execute it" << std::endl;
	// Hitchcock.executeForm(rrf);

	// std::cout << "Letting Jimbo sign it" << std::endl;
	// Jimmy.signForm(rrf);

	// std::cout << "\nAsking Hitchcock to execute it" << std::endl;
	// Hitchcock.executeForm(rrf);

	// std::cout << "\nAsking Jimbo to execute it" << std::endl;
	// Jimmy.executeForm(rrf);

	// std::cout << "\nCreating a new bureaucrat with grade 45 to execute the form" << std::endl;
	// Bureaucrat Kubrick("Stanley Kubrick", 45);
	// Kubrick.executeForm(rrf);

	// std::cout << "\nCreating Presidential pardon form" << std::endl;
	// PresidentialPardonForm ppf("George Washington");

	// std::cout << "\nAsking Stanley to sign it" << std::endl;
	// Kubrick.signForm(ppf);

	// std::cout << "\nCreating a new bureaucrat with grade 25 to sign the form" << std::endl;
	// Bureaucrat Scorcese("Martin Scorcese", 25);
	// Scorcese.signForm(ppf);

	// std::cout << "\nAsking Martin to execute it" << std::endl;
	// Scorcese.executeForm(ppf);

	// std::cout << "\nCreating a new bureaucrat with grade 5 to execute the form" << std::endl;
	// Bureaucrat poop("Poop", 5);
	// poop.executeForm(ppf);
}
