#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	Karen;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter \"LEVEL\"" << std::endl;
		return (1);
	}
	Karen.complain(argv[1]);
}

