#include "Zombie.hpp"

int main()
{
	Zombie *new_zombie = zombieHorde(20, "GUTENTAGJA");
	if (new_zombie == nullptr)
		return (std::cerr << "Allocation failed" << std::endl, 1);

	for (int i = 0; i < 20; i++)
		new_zombie[i].announce();
	delete [] new_zombie;

	system("leaks ex01");
	return 0;
}
