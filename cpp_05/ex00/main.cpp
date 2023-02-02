#include "Bureaucrat.hpp"

int main ()
{
	std::cout << "Creating a legit Bureaucrat:\n";
	Bureaucrat Jimmy("Jimbo", 55);

	std::cout << "\nCreating an Bureaucrat with a grade higher than 1 (In normal language grade is less than 1):\n";
	try
	{
		Bureaucrat Jacuzi("Jacuzo", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nCreating an Bureaucrat with a grade less than 150 (In normal language grade is greater than 150):\n";
	try
	{
		Bureaucrat Rambo("Ramboo", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nCreating an Bureaucrat with the highest grade (1):\n";
	Bureaucrat someDude("Some dude", 1);

	std::cout << "\nDecrementing the Bureaucrat with the highest grade (1):\n";
	try
	{
		someDude.decrementGrade();
		std::cout << someDude << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nIncrementing this bureaucrat:\n";
	try
	{
		someDude.incrementGrade();
		std::cout << someDude << std::endl;
		std::cout << "\nIncrementing this bureaucrat again:\n";
		someDude.incrementGrade();
		std::cout << someDude << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nIncrementing this bureaucrat again:\n";
	try
	{
		someDude.incrementGrade();
		std::cout << someDude << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
