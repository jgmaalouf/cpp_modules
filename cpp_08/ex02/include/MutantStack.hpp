#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() {};
	MutantStack(const MutantStack& source) : std::stack<T>(source) {};
	~MutantStack() {};

	MutantStack& operator=(const MutantStack& rhs) { std::stack<T>::operator=(rhs); return *this; };

	iterator begin() { return std::stack<T>::c.begin(); };
	iterator end() { return std::stack<T>::c.end(); };
};

#endif