#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _dogBrain;
public:
	Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	virtual ~Dog();

	void makeSound() const;
	void pushIdea(std::string idea);
	void displayIdeas() const;
};

#endif