#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "This is the WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "This is the WrongAnimal deconstructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "What did you expect?" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}


