#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main ()
{

	DiamondTrap diamond("Jad");

	diamond.whoAmI();
	diamond.highFivesGuys();
	diamond.attack("Karen");
	diamond.takeDamage(32);
	diamond.beRepaired(32);

	ClapTrap clapTrap( "Mr.ClapTrap" );
	clapTrap.setAttackDamage(5);

	FragTrap fragTrap;
	fragTrap.setName( "Mr.FragTrap" );

	clapTrap.attack( "Mr.FragTrap" );

	fragTrap.takeDamage( 5 );
	fragTrap.beRepaired( 2 );
	fragTrap.attack( "Mr.ClapTrap" );
	
	clapTrap.takeDamage( 30 );
	clapTrap.setAttackDamage(7);
	clapTrap.attack( "Mr.FragTrap" );
	fragTrap.highFivesGuys();
}