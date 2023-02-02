#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int num)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), num);
	if (it == cont.end())
		throw(std::runtime_error("Non existent!"));
	return it;
}

#endif