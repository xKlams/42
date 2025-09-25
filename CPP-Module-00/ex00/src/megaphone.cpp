#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
	}
	for (size_t j = 0; j < (size_t)argc - 1; j++)
	{
		if (j > 0)
			std::cout << " ";
		for (size_t i = 0; argv[j+1][i]; i++)
			std::cout << (char)std::toupper(argv[j + 1][i]);
	}
	std::cout << std::endl;
}
