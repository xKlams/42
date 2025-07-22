#include "../include/phonebook.hpp"

void	phonebook::add()
{
	this->contacts[new_contact_index].set_contact();
	this->size++;
	this->new_contact_index = (this->new_contact_index + 1) % 8;
}

phonebook::phonebook()
{
	this->new_contact_index = 0;
	this->size = 0;
	return;
}

void	phonebook::search() const
{
	std::string contact_fields[4] = {"ID", "first bame", "last name", "nickname"};
	
	for (int i = 0; i <= 44; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10);
	for (int i = 0; i < 4; i++)
		std::cout << std::setw(10) << contact_fields[i] << "|";
	std::cout << std::endl;
	for (size_t i = 0; i < this->size; i++)
		this->contacts[i].get_contact(i);
	for (int i = 0; i <= 44; i++)
		std::cout << "-";
	std::cout << std::endl;
}
