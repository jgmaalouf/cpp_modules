#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog max;

	max.pushIdea("I'm a dog DAMN!");
	max.pushIdea("I can lick my balls now!");

	max.displayIdeas();

	Dog jack(max);
	jack.displayIdeas();
	std::cout << "Testing for shallow copies" << std::endl;
	{
		Dog tmp = jack;
		tmp.displayIdeas();
	}

	std::cout << "Creating an array of 2 dogs and 2 cats" << std::endl;
	Animal *animals[4] = {
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
	};

	std::cout << "Deleting the array" << std::endl;
	for (size_t i = 0; i < 4; i++)
		delete animals[i];

	return 0;
}