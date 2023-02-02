#include "MutantStack.hpp"
#include <list>
int main()
{
	std::cout << "Running the MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\nRunning the same values with list:" << std::endl;
	
	std::list<int> intList;

	intList.push_back(5);
	intList.push_back(17);
	
	std::cout << intList.back() << std::endl;

	intList.pop_back();

	std::cout << intList.size() << std::endl;

	intList.push_back(3);
	intList.push_back(5);
	intList.push_back(737);
	
	intList.push_back(0);
	
	std::list<int>::iterator lit = intList.begin();
	std::list<int>::iterator lite = intList.end();

	++lit;
	--lit;

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}


	// std::cout << "\nTrying out the copy constructor with a std::stack" << std::endl;
	// std::stack<int> s(mstack);
	// s.push(15);
	// s.push(152);
	// s.push(135);
	// std::cout << *s.begin() << std::endl;
	// std::cout << *s.end() << std::endl;
 
	std::cout << "\nTrying out the copy constructor with a MutantStack" << std::endl;

	MutantStack<int> cpyMstack(mstack);
	std::cout << *cpyMstack.begin() << std::endl;
	std::cout << *(cpyMstack.end() - 1) << std::endl;
	cpyMstack.push(15);
	cpyMstack.push(152);
	cpyMstack.push(135);
	std::cout << *cpyMstack.begin() << std::endl;
	std::cout << *(cpyMstack.end() - 1) << std::endl;

	return 0;

}