#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap	scav("Giovanni");
	FragTrap	frag("martino");

	scav.attack("Martino");
	scav.takeDamage(4);
	scav.beRepaired(5);
	scav.takeDamage(12);
	scav.takeDamage(1);
	scav.attack("Giovannino");

	frag.attack("cavallo");
	frag.takeDamage(2);
	frag.highFivesGuys();
}
