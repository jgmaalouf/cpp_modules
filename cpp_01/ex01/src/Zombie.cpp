#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name_(zombieName)
{
	std::cout << name_ << " constructed" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Constructor without parameters called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name_ << " destructed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	name_ = name;
}
