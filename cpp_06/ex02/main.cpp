#include "Base.hpp"
#include <time.h>
#include <cstdlib>
#include <exception>

Base *generate()
{
	std::srand(time(NULL));

	int chance = std::rand() % 3;
	switch (chance)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		break;
	}
	return NULL;
}

void identify(Base* p)
{
	if ((dynamic_cast<A*>(p) != nullptr))
		std::cout << "A" << std::endl;
	if ((dynamic_cast<B*>(p) != nullptr))
		std::cout << "B" << std::endl;
	if ((dynamic_cast<C*>(p) != nullptr))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	Base *base = generate();
	identify(*base);
	B b;
	Base& baseRef(b);
	identify(baseRef);
	delete base;
}
