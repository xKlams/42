#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "This is the cat constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "This is the cat deconstructor" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "MEOW!" << std::endl;
}
