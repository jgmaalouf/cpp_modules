#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("Unknown")
	, hitPoints_(10)
	, energyPoints_(10)
	, attackDamage_(10)
{
	std::cout << "Default ClapTrap " << name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name_ (name)
	, hitPoints_ (10)
	, energyPoints_ (10)
	, attackDamage_ (10)
{
	std::cout << "ClapTrap " << name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
	: name_ (clapTrap.name_) 
	, hitPoints_ (clapTrap.hitPoints_)
	, energyPoints_ (clapTrap.energyPoints_)
	, attackDamage_ (clapTrap.attackDamage_)
{
	std::cout << "ClapTrap " << name_ << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	name_ = clapTrap.name_;
	hitPoints_ = clapTrap.hitPoints_;
	energyPoints_ = clapTrap.energyPoints_;
	attackDamage_ = clapTrap.attackDamage_;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name_ << " default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		std::cout << "ClapTrap " << name_
					<< " attacks " << target
					<< " causing " << attackDamage_
					<< " points of damage!"
					<< std::endl;
		energyPoints_--;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm already dead." << std::endl;
	else
	{
		hitPoints_ -= amount;
		std::cout << "ClapTrap " << name_
					<< " took " << amount
					<< " points of damage!"
					<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ <= 0)
		std::cout << "Sorry dude, I'm dead." << std::endl;
	else if (energyPoints_ > 0)
	{
		hitPoints_ += amount;
		energyPoints_--;
	std::cout << "ClapTrap " << name_
				<< " repaired itself by: " << amount
				<< " hit points!"
				<< std::endl;
	}
	else
		std::cout << "Sorry dude, can't do shit without hit and energy points ¯\\_(ツ)_/¯" << std::endl;
}

void ClapTrap::setName( std::string name )
{
	name_ = name;
}

void ClapTrap::setAttackDamage( unsigned int amount )
{
	attackDamage_ = amount;
}
