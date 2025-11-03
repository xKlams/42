#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack()
{
	if (this->weapon && this->weapon->getType() != "")
		std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
	else
		std::cout << this->name << " cannot attack without a weapon" << std::endl;
}
