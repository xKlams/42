#include "replacer.hpp"

void	process_file(char *filename, std::string s1, std::string s2)
{
	std::string	line;
	std::ifstream	start_file (filename);
	std::string	new_filename = filename;

	new_filename += ".replaced";
	std::ofstream new_file (new_filename.c_str());

	size_t		substr_position;

	if (start_file.is_open())
	{
		while (getline(start_file, line))
		{
			substr_position = line.find(s1);
			while (substr_position != std::string::npos)
			{
				line.erase(substr_position, s1.length());
				line.insert(substr_position, s2);
				substr_position = line.find(s1, substr_position + s2.length());
			}
			new_file << line << std::endl;
		}
	}
}


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./repalcer <filename> s1 s2" << std::endl;
		return (EXIT_FAILURE);
	}
	process_file(argv[1], argv[2], argv[3]);
}
