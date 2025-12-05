#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "This is the cat constructor" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "This is the cat deconstructor" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}
