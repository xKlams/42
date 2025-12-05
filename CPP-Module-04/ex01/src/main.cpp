#include "Dog.hpp"
#include "Cat.hpp"

#define	N_ANIMALS 100

int main()
{
	Animal *animals[N_ANIMALS];

	for (int i = 0 ; i < N_ANIMALS/2; i++)
		animals[i] = new Dog();
	for (int i = N_ANIMALS/2; i < N_ANIMALS; i++)
		animals[i] = new Cat();
	for (int i = 0; i < N_ANIMALS; i++)
		delete animals[i];
	return 0;
}
