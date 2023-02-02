#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_dogBrain = new Brain();
}

Dog::Dog(const Dog& dog)
	: Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_dogBrain = new Brain();
	_dogBrain->operator=(*(dog._dogBrain));
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
	delete _dogBrain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void Dog::pushIdea(std::string idea)
{
	_dogBrain->pushIdea(idea);
}

void Dog::displayIdeas() const
{
	_dogBrain->displayIdeas();
}
