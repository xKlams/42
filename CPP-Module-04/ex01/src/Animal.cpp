#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "This is the Animal constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "This is the Animal deconstructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "What did you expect?" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

