#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
	int			_ideaCount;
public:
	Brain();
	Brain(const Brain& brain);
	Brain& operator=(const Brain& brain);
	~Brain();

	void pushIdea(std::string idea);
	void popIdea();
	void displayIdeas() const;
};

#endif