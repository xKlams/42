#include "ClapTrap.hpp"

int main()
{
	ClapTrap	first("Giovanni");

	first.attack("Martino");
	first.takeDamage(4);
	first.beRepaired(5);
	first.takeDamage(12);
	first.takeDamage(1);
	first.attack("Giovannino");
}
