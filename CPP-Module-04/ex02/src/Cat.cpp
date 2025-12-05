#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal()
{
	std::cout << "This is the cat constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat()
{
	std::cout << "This is the cat deconstructor" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}
