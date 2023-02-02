#include <iostream>
#include <fstream>
#include <string>

int panic(std::string message)
{
	std::cout << message << std::endl;
	return EXIT_FAILURE;
}

void replace(std::string s1, std::string s2, std::string& line)
{
	size_t pos = 0;
	while (1)
	{
		pos = line.find(s1, pos);
		if (pos == std::string::npos)
			return ;
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos += s2.size();
	}
}

int main(int argc, char *argv[]) // ./ex03 filename replace s1 with s2
{
	if (argc != 4)
		return panic("Usage: ./ex04 <file> <search> <replace>");

	std::string filename = argv[1];
	std::ifstream input(filename);

	if (!input.is_open())
		return panic("Error opening file!");
	std::ofstream output((filename + ".replace"));
	std::string line;
	while (std::getline(input, line) && input.good())
	{
		replace(argv[2], argv[3], line);
		output << line << std::endl;
	}
	return EXIT_SUCCESS;
}
