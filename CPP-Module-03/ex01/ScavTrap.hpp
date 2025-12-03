#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class	ScavTrap : public ClapTrap
{
private:
	bool	_is_guarding;
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void	guardGate();
};

#endif
