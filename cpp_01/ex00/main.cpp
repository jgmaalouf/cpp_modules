#include "Zombie.hpp"

int main()
{
	Zombie *zombies[20];

	for (size_t i = 0; i < 20; i++)
	{
		zombies[i] = newZombie("Heap Zombie");
		zombies[i]->announce();
	}
	randomChump("Stack Zombie");

	for (size_t i = 0; i < 20; i++)
	{
		zombies[i]->~Zombie();
		delete zombies[i];
	}

	system("leaks ex00");
}
