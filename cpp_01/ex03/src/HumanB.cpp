#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name_(name)
{
}

void HumanB::setWeapon(Weapon& Weapon)
{
	Weapon_ = &Weapon;
}

void HumanB::attack() const
{
	std::cout << name_
				<< " attacks with their "
				<< Weapon_->getType()
				<< std::endl;
}
