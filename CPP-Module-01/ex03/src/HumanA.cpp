#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &starting_weapon)
:weapon(starting_weapon)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
