#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal()
{
	std::cout << "This is the dog constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog()
{
	std::cout << "This is the dog deconstructor" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF!" << std::endl;
}
