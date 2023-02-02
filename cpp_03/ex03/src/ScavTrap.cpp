#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap " << name_ << " constructor called" << std::endl;
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap " << name_ << " name constructor called" << std::endl;
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap " << name_ << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& scavTrap)
{
	std::cout << "ScavTrap assigment operator called" << std::endl;
	ClapTrap::operator=(scavTrap);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name_ << " default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		std::cout << "ScavTrap " << name_
					<< " attacks " << target
					<< " causing " << attackDamage_
					<< " points of damage!"
					<< std::endl;
		energyPoints_--;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm already dead." << std::endl;
	hitPoints_ -= amount;
	std::cout << "ScavTrap " << name_
				<< " took " << amount
				<< " points of damage!"
				<< std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		hitPoints_ += amount;
		energyPoints_--;
		std::cout << "ScavTrap " << name_
				<< " repaired itself by: " << amount
				<< " hit points!"
				<< std::endl;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_
				<< " is now in Gate keeper mode!"
				<< std::endl;
}
