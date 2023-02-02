#ifndef Base_HPP
#define Base_HPP

#include <iostream>

class Base
{
public:
	virtual ~Base();
};

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

#endif
