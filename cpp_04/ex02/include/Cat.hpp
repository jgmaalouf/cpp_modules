#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
private:
	Brain* _catBrain;
public:
	Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);
	virtual ~Cat();

	void makeSound() const;
	void pushIdea(std::string idea);
	void displayIdeas() const;
};

#endif