#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	Weapon		&weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon &starting_weapon);
	void		attack();
};

#endif
