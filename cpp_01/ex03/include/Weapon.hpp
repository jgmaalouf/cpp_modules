#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type_;
public:
	std::string getType() const;
	void setType(std::string type);
	Weapon(std::string type);
};

#endif
