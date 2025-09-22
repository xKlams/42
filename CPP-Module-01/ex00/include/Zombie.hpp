#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define NAME_LEN

class Zombie
{
private:
	std::string name;
public:
	Zombie(std::string name);
	~Zombie( void );
	void announce( void );
};

void randomChump( std::string name );
Zombie *newZombie( std::string name );

#endif
