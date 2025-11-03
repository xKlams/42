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
	~Zombie( void );
	void set_name(std::string name);
	void announce( void );
};

Zombie *zombieHorde(int N, std::string name);

#endif
