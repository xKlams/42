#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "This is the dog constructor" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "This is the dog deconstructor" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF!" << std::endl;
}
