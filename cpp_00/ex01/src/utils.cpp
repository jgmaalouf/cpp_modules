#include "utils.hpp"

bool	isstr_print(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
		if (!std::isprint(input[i]))
			return false;
	return true;
}

bool	isstr_num(std::string input)
{
	size_t i = 0;

	if (input[i] == '+')
		i++;
	for (; i < input.size(); i++)
		if (!std::isdigit(input[i]))
			return false;
	return true;
}
