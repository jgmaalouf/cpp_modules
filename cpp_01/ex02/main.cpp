#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The address of str:                "		<< &str << std::endl;
	std::cout << "The address held by stringPTR:     "		<< stringPTR << std::endl;
	std::cout << "The address held by stringREF:     \n"	<< &stringREF << std::endl;

	std::cout << "The value of str:                  "		<< str << std::endl;
	std::cout << "The value pointed to by stringPTR: "		<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: "		<< stringREF << std::endl;
}
