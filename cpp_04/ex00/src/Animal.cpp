#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
	: _type(animal._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "No Sound" << std::endl;
}