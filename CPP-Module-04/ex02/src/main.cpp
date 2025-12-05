#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main()
{
	AAnimal *animal = new Cat();

	delete animal;
}
