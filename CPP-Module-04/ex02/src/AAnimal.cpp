#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "This is the AAnimal constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "This is the AAnimal deconstructor" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "What did you expect?" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

