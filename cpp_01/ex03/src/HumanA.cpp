#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : 
	name_(name), Weapon_(Weapon)
{
}

void HumanA::setWeapon(Weapon& Weapon)
{
	Weapon_ = Weapon;
}

void HumanA::attack() const
{
	std::cout << name_
				<< " attacks with their "
				<< Weapon_.getType()
				<< std::endl;
}
