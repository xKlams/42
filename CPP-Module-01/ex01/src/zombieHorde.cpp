#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "You need at least one Zombie to create an Horde" << std::endl;
		return (NULL);
	}
	Zombie *output = new Zombie[N];
	if (!output)
		std::cout << "Horde allocation failed" << std::endl;
	for (int i = 0; i < N; i++)
		output[i].set_name(name);
	return (output);
}
