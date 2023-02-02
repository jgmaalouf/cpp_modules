#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 0)
		return (std::cout << "Bad input" << std::endl, nullptr);

	Zombie *zombie_horde = new (std::nothrow) Zombie[N];
	if (zombie_horde == nullptr)
		return (nullptr);

	for (int i = 0; i < N; i++)
		zombie_horde[i].setName(name);
	return (zombie_horde);
}
