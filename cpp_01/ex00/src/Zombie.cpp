#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name_(zombieName)
{
}

Zombie::~Zombie()
{
	std::cout << name_ << " deconstructed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
