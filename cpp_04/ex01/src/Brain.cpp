#include "Brain.hpp"

Brain::Brain() : _ideaCount(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	operator=(brain);
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	_ideaCount = brain._ideaCount;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

void Brain::pushIdea(std::string idea)
{
	_ideas[_ideaCount] = idea;
	_ideaCount++;
}

void Brain::popIdea()
{
	_ideaCount--;
	_ideas[_ideaCount].clear();
}

void Brain::displayIdeas() const
{
	for (int i = 0; i < _ideaCount; i++)
		std::cout << _ideas[i] << std::endl;
}
