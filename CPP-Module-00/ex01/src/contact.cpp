#include "../include/contact.hpp"
#include <string>

void contact::set_contact()
{
	std::string contact_fields[5] = {"first bame", "last name", "nickname", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Please enter the "<< contact_fields[i] << " of your contact" << std::endl;
		std::getline(std::cin, this->contact_info[i]);
		if (contact_info[i].length() == 0)
		{
			std::cout << "Empty string provided, please enter a non-empty string" << std::endl;
			i--;
		}
	}
	std::cout << "Contatto aggiunto correttamente" << std::endl;
}

void contact::get_contact(int ID) const
{
	std::cout << "|" << std::setfill(' ') << std::setw(10) << ID << "|";
	for (int i = 0; i < 3; i++)
	{
		if (this->contact_info[i].length() < 10)
			std::cout << std::setw(10) << contact_info[i] << "|";
		else
			std::cout << std::setw(10) << contact_info[i].substr(0,9) + "." << "|";
	}
	std::cout << std::endl;
}

std::string contact::get_info(int index) const
{
	return (this->contact_info[index]);
}
