#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name_;
	Weapon		&Weapon_;
public:
	HumanA(std::string name, Weapon& weapon);
	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif