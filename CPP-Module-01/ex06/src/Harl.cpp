#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		int_level;

	for (int_level = 0; int_level < 4; int_level++)
	{
		if (level == levels[int_level])
			break;
	}
	switch (int_level)
	{
		case 0:
			std::cout << "\033[32m";
			std::cout << "[DEBUG]" << std::endl;
			this->debug();
		case 1:
			std::cout << "\033[34m";
			std::cout << "[INFO]" << std::endl;
			this->info();
		case 2:
			std::cout << "\033[33m";
			std::cout << "[WARNING]" << std::endl;
			this->warning();
		case 3:
			std::cout << "\033[31m";
			std::cout << "[ERORR]" << std::endl;
			this->error();
			break;
		default:
			std::cout << "\033[0m";
			std::cout << "level not found" << std::endl;
	}
	std::cout << "\033[0m";
}
