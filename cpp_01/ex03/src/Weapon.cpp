#include "Weapon.hpp"

std::string Weapon::getType() const
{
	return type_;
}

void Weapon::setType(std::string type)
{
	type_ = type;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}
