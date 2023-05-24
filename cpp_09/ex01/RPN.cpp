#include "RPN.hpp"
#include <cstring>

RPN::RPN(const std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue;
		if (isdigit(input[i]))
			inputNumbers_.push(input[i] - 0);
		else if (std::strchr("+-*/", input[i]) != nullptr)
			inputNumbers_.push(input[i]);
		else
			throw std::runtime_error("Error: bad expression");
	}
}

RPN::RPN(const RPN& arg)
{
	inputNumbers_ = arg.inputNumbers_;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs)
{
	inputNumbers_ = rhs.inputNumbers_;
	return *this;
}

/*  7 7 * 7 - */

int popTop(std::stack<int>& inputNumbers)
{
	int top = inputNumbers.top();
	inputNumbers.pop();
	return top;
}

int RPN::calculate()
{

}
