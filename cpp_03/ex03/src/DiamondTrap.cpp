#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap ("Unknown_clap_name")
	, name_ ("Unknown")
{
	std::cout << "DiamondTrap " << name_ << " default constructor called" << std::endl;
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap (name + "_clap_name")
	, name_(name)
{
	std::cout << "DiamondTrap " << name_ << " name constructor called" << std::endl;
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
	: ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
{
	std::cout << "DiamondTrap " << name_ << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap assigment operator called" << std::endl;
	ClapTrap::operator=(diamondTrap);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name_ << " default destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() const
{
	std::cout << name_ << std::endl;
	std::cout << ClapTrap::name_ << std::endl;
}
