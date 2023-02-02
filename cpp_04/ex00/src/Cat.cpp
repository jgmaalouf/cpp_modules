#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat& cat )
	: Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator= (const Cat& cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	_type = cat._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}