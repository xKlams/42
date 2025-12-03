#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_is_guarding = false;
	std::cout << "ScavTrap " << this->_name << " has been constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destructed" << std::endl;
}

void	ScavTrap::guardGate()
{
	this->_is_guarding = true;
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

