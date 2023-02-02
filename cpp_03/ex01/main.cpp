#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	ClapTrap clapTrap("Mr.ClapTrap");
	clapTrap.setAttackDamage(5);

	ScavTrap scavTrap;
	scavTrap.setName("Mr.ScavTrap");

	clapTrap.attack("Mr.ScavTrap");

	scavTrap.takeDamage(5);
	scavTrap.beRepaired (2);
	scavTrap.attack("Mr.ClapTrap");
	scavTrap.guardGate();
	
	clapTrap.takeDamage (20);
	clapTrap.setAttackDamage(7);
	clapTrap.attack("Mr.ScavTrap");
}