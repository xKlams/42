#include "Zombie.hpp"

int main()
{
	Zombie *test;

	test = newZombie("Aldo");
	randomChump("Giovanni");
	test->announce();
	delete test;
	return (0);
}
