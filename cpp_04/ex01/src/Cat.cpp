#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_catBrain = new Brain();
}

Cat::Cat(const Cat& cat)
	: Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_catBrain = new Brain();
	_catBrain->operator=(*(cat._catBrain));
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
	delete _catBrain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::pushIdea(std::string idea)
{
	_catBrain->pushIdea(idea);
}

void Cat::displayIdeas() const
{
	_catBrain->displayIdeas();
}