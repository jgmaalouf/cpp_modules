#include "RPN.hpp"
#include <cstring>

RPN::RPN(const std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue;
		if (isdigit(input[i]))
		{
			expression_.push(std::strtol(input.c_str() + i, nullptr, 10));
			while (isdigit(input[i]))
				i++;
			i--; // to correct for the extra increment in for loop
		}
		else if (std::strchr("+-*/", input[i]) != nullptr)
			expression_.push(input[i]);
		else
			throw std::runtime_error("Error: bad expression");
	}
}

RPN::RPN(const RPN& arg)
{
	expression_ = arg.expression_;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs)
{
	expression_ = rhs.expression_;
	return *this;
}


int popTop(std::queue<int>& queue)
{
	if (queue.empty())
		throw std::runtime_error("Error: invalid expression");
	int top = queue.front();
	queue.pop();
	return top;
}

int popTop(std::stack<int>& stack)
{
	if (stack.empty())
		throw std::runtime_error("Error: invalid expression");
	int top = stack.top();
	stack.pop();
	return top;
}

bool isOperator(int& input)
{
	if (std::strchr("+-*/", input) != nullptr)
		return true;
	return false;
}

int	operate(int calc, int operand1, int operand2)
{
	if (calc == '+')
		return operand2 + operand1;
	if (calc == '-')
		return operand2 - operand1;
	if (calc == '*')
		return operand2 * operand1;
	if (calc == '/')
		return operand2 / operand1;
	return 0;
}

int RPN::calculate()
{
	std::stack<int>	stack;

	while (!expression_.empty())
	{
		int top = popTop(expression_);
		if (isOperator(top))
		{
			int calc = top;
			int operand1 = popTop(stack);
			int operand2 = popTop(stack);
			int res = operate(calc, operand1, operand2);
			stack.push(res);
		}
		else
			stack.push(top);
	}
	int res = popTop(stack);
	if (!stack.empty())
		throw std::runtime_error("Error: invalid expression");
	return res;
}
