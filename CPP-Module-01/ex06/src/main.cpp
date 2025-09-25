#include "Harl.hpp"

int main()
{
	Harl	Karen;
	std::string	complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Testcase with level = " << complains[i] << std::endl;
		Karen.complain(complains[i]);
	}
}

