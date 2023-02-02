#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog( const Dog& dog )
	: Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator= (const Dog& dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = dog._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
