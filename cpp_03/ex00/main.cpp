#include "ClapTrap.hpp"

int main ()
{
	ClapTrap fighter1("Mr.ClapTrap");
	fighter1.setAttackDamage(5);

	ClapTrap fighter2 (fighter1);
	fighter2 = fighter1;
	fighter2.setName("Mr.AntiClapTrap");

	fighter1.attack("Mr.AntiClapTrap");

	fighter2.takeDamage(5);
	fighter2.beRepaired(2);
	fighter2.attack("Mr.ClapTrap");
	
	fighter1.takeDamage(5);
	fighter1.setAttackDamage(7);
	fighter1.attack("Mr.AntiClapTrap");

	fighter2.takeDamage(7);
	fighter2.attack("Mr.ClapTrap");
	fighter2.beRepaired(2);
}