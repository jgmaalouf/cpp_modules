#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>


class RPN
{
private:
	std::stack<int>	inputNumbers_;
public:
	RPN(const std::string& input);
	RPN(const RPN& arg);
	~RPN();

	RPN&	operator=(const RPN& rhs);

	int		calculate();
};

#endif