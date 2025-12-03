#include "ClapTrap.hpp"
#include <iostream>
#include <algorithm>

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap " << this->_name << " has been constructed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tries to attack but it's dead!" << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tries to attack but it's too tired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	(this->_energy_points)--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= std::min(amount, this->_hit_points);
	std::cout << "Claptrap " << this->_name << " takes " << amount << " of damage" << std::endl;
	if (this->_hit_points <= 0)
		std::cout << "Claptrap "<< this->_name << " is dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tries to repair but it's dead!" << std::endl;
		return ;
	}
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tries to repair but it's too tired!" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << this->_name << " is repaired for " << amount << " hit points" << std::endl;
	this->_hit_points += amount;
	(this->_energy_points)--;
}

