#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	std::cout << "Creating a legit Bureaucrat:\n";
	Bureaucrat Jimmy("Jimbo", 55);

	std::cout << "\nCreating a form with sign grade == 0 and execution grade == 1\n";
	try
	{
		Form form("Residence Permit", false, 0, 1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nCreating a form with sign grade == 22 and execution grade == 151\n";
	try
	{
		Form form("Residence Permit", false, 22, 151);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nCreating a legit form\n";
	Form form("Residence Permit", false, 14, 150);

	std::cout << "\nLetting Jimmy sign the form\n";
	Jimmy.signForm(form);

	std::cout << "Creating a Bureaucrat with grade higher than 14:\n";
	Bureaucrat Jacuzi("Jacuzo", 10);
	
	std::cout << "\nLetting Jacuzi sign the form\n";
	Jacuzi.signForm(form);

}
