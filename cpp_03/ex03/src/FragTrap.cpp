#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap " << name_ << " constructor called" << std::endl;
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap (name)
{
	std::cout << "FragTrap " << name_ << " name constructor called" << std::endl;
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
	: ClapTrap (fragTrap)
{
	std::cout << "FragTrap " << name_ << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << "FragTrap assigment operator called" << std::endl;
	ClapTrap::operator=(fragTrap);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name_ << " default destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		std::cout << "FragTrap " << name_
					<< " attacks " << target
					<< " causing " << attackDamage_
					<< " points of damage!"
					<< std::endl;
		energyPoints_--;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm already dead." << std::endl;
	hitPoints_ -= amount;
	std::cout << "FragTrap " << name_
				<< " took " << amount
				<< " points of damage!"
				<< std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		hitPoints_ += amount;
		energyPoints_--;
		std::cout << "FragTrap " << name_
				<< " repaired itself by: " << amount
				<< " hit points!"
				<< std::endl;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name_
				<< " is requesting a high five baby!"
				<< std::endl;
}
