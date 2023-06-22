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

void binaryInsert(int pend, std::vector<int>& main, size_t high)
{
	std::vector<int>::iterator pos = main.begin();

	int low = 0;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (main[mid] == pend) // Comparison
		{
			main.insert(pos + mid, pend);
			return ;
		}
		else if (main[mid] > pend) // Comparison
			high = mid - 1;
		else
			low = mid + 1;
	}
	// low == high
	if (pend < main[low]) // Comparison
		main.insert(pos + low, pend);
	else
		main.insert(pos + low + 1, pend);
	return ;
}


#include <iostream>
void binaryInsertionSort(std::vector<int>& pend, std::vector<int>& main)
{
	size_t current = 3; // Starting at the third Jacobsthal index
	size_t high = 3;    // Limit of binary search in main
	size_t next = jacobsthalIndexGen(current, NEXT);
	size_t prev = jacobsthalIndexGen(current, PREV);

	size_t pendSize = pend.size();

	while (current < pendSize)
	{
		while (current > prev)
		{
			binaryInsert(pend[current - 1], main, high - 1);
			current--;
		}
		current = next;
		next = jacobsthalIndexGen(current, NEXT);
		prev = jacobsthalIndexGen(current, PREV);
		high = high * 2 + 1;
	}

	// When we exit, we still have one round of insertions to do
	current = pendSize;
	high = main.size();
	while (current > prev)
	{
		binaryInsert(pend[current - 1], main, high - 1);
		current--;
	}
}

