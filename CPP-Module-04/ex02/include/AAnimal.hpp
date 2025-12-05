#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal();
	virtual	~AAnimal();
	virtual void		makeSound() const = 0;
	std::string	getType() const;
};

#endif
