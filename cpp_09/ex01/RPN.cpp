#include "RPN.hpp"
#include <cstring>

bool isOperator(const int& input);

RPN::RPN(const std::string& input)
: expression_(input)
{
	expression_.erase(std::remove_if(expression_.begin(), expression_.end(), isspace), expression_.end()); // Removes all spaces from arg
	for (size_t i = 0; i < expression_.size(); i++)
	{
		if (isdigit(expression_[i]) || isOperator(expression_[i]))
			continue;
		throw std::runtime_error("Error: bad expression");
	}
}

RPN::RPN(const RPN& arg)
: expression_(arg.expression_)
{
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs)
{
	expression_ = rhs.expression_;
	return *this;
}


int popTop(std::string& expression)
{
	if (expression.empty())
		throw std::runtime_error("Error: invalid expression");
	int top = expression.front();
	if (!isOperator(top))
		top -= '0';
	expression.erase(0, 1);
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

bool isOperator(const int& input)
{
	if (std::strchr("+-*/", input) != nullptr)
		return true;
	return false;
}

int	operate(const int& calc, const int& operand1, const int& operand2)
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
	std::stack<int> stack;

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
