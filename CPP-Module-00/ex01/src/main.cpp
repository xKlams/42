#include "../include/Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "> "; 
		std::getline(std::cin, command);

		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break; 
	}
	std::cout << "Closing the phonebook" << std::endl;
}
