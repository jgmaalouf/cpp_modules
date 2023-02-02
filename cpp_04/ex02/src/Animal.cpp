#include "Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& animal)
	: _type(animal._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	_type = animal._type;
	return *this;
}

A_Animal::~A_Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

std::string A_Animal::getType() const
{
	return _type;
}
