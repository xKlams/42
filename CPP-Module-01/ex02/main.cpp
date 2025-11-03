#include <string>
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF= s;

	std::cout << "Memory address of string variable: " << &s << std::endl;
	std::cout << "Memory address held by: " << stringPTR << std::endl;
	std::cout << "Memory address held by reference: " << &stringREF << std::endl;

	std::cout << "Value of string variable: " << s << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
