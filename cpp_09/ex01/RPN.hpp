#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <queue>


class RPN
{
private:
	std::queue<int>	expression_;
public:
	RPN(const std::string& input);
	RPN(const RPN& arg);
	~RPN();

	RPN&	operator=(const RPN& rhs);

	int		calculate();
};

#endif