#include "Zombie.hpp"

int main()
{
	Zombie *horde;

	horde = zombieHorde(10, "Pablo");
	for (int i = 0 ; i < 10; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}
