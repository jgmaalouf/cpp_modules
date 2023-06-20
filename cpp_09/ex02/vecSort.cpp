#include "PmergeMe.hpp"

intPairVec createPairs(std::vector<int> vecIntSeq)
{
	// Here, in a loop, I pop out 2 integers from the sequence and
	//  store them into a pair then store the pair into the pairVec
	intPairVec pairVec;
	std::vector<int>::iterator it = vecIntSeq.begin();
	while (it != vecIntSeq.end() && (it + 1) != vecIntSeq.end())
	{
		std::pair<int, int> pair;
		pair.first = *it; vecIntSeq.erase(it);
		pair.second = *it; vecIntSeq.erase(it);
		if (pair.second > pair.first) // Comparison made. Should increment a comparison count variable
			std::swap(pair.first, pair.second);
		pairVec.push_back(pair);
	}
	return pairVec;
}

intPairVec mergePairs(intPairVec a, intPairVec b)
{
	intPairVec c;

	while(!a.empty() && !b.empty())
	{
		if (a[0].first > b[0].first) // Comparison. Should increment
		{
			c.push_back(b[0]);
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin());
		}
	}
	// At this point either a or b are empty
	while (!a.empty())
	{
		c.push_back(a[0]);
		a.erase(a.begin());
	}
	
	while (!b.empty())
	{
		c.push_back(b[0]);
		b.erase(b.begin());
	}
	return c;
}

intPairVec mergesortPairs(intPairVec& pairVec, int n)
{
	if (n == 1)
		return pairVec;
	intPairVec arr1;
	for (size_t i = 0; i < n / 2; i++)
		arr1.push_back(pairVec[i]);

	intPairVec arr2;
	for (size_t i = n / 2; i < n; i++)
		arr2.push_back(pairVec[i]);

	arr1 = mergesortPairs(arr1, arr1.size());
	arr2 = mergesortPairs(arr2, arr2.size());

	return mergePairs(arr1, arr2);
}

std::vector<int> extractChain(intPairVec pairVec, int chainType)
{
	std::vector<int> chain;
	intPairVec::iterator it;
	intPairVec::iterator end = pairVec.end();

	if (chainType == SORTED)
		for (it = pairVec.begin(); it < end; it++)
			chain.push_back((*it).first);

	else if (chainType == UNSORTED)
		for (it = pairVec.begin(); it < end; it++)
			chain.push_back((*it).second);

	return chain;
}

intVecIterator createIters(std::vector<int>& intVec)
{
	intVecIterator intVecIters;

	std::vector<int>::iterator it;
	std::vector<int>::iterator end = intVec.end();
	for (it = intVec.begin(); it < end; it++)
		intVecIters.push_back(it);

	return intVecIters;
}

#include <iostream>
std::vector<int>::iterator binarySearch(int pend, std::vector<int>& main, std::vector<int>::iterator& upperBound)
{
	std::vector<int>::iterator pos = main.begin();

	size_t size = std::distance(main.begin(), upperBound);
	size_t low = 0;
	size_t high = size;



	// I have a problem understanding iterators
	while (pos < upperBound)
	{
		std::cout << *pos << std::endl;
		pos++;
	}
	exit(0);

	while (low < high)
	{
		size_t mid = (low + high) / 2;
		if (main[mid] == pend)
			return pos + mid;
		else if (main[mid] > pend)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return pos + low;
}

void binaryInsertionSort(std::vector<int>& pend, std::vector<int>& main, intVecIterator& mainIters)
{
	size_t current = 3; // Starting at the third Jacobsthal index
	size_t next = jacobsthalIndexGen(current, NEXT);
	size_t prev = jacobsthalIndexGen(current, PREV);

	size_t pendSize = pend.size();

	while (current < pendSize)
	{
		while (current > prev)
		{
			std::vector<int>::iterator pos = binarySearch(pend[current - 1], main, mainIters[current - 2]);
			main.insert(pos, pend[current - 1]);
			current--;
		}
		current = next;
		next = jacobsthalIndexGen(current, NEXT);
		prev = jacobsthalIndexGen(current, PREV);
	}

	// When we exit, we still have one round of insertions to do
	current = pendSize;
	while (current > prev)
	{
		std::vector<int>::iterator pos = binarySearch(pend[current - 1], main, mainIters[current - 2]);
		main.insert(pos, pend[current - 1]);
		current--;
	}
}

