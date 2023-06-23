#include "PmergeMe.hpp"

intPairDeque createPairs(std::deque<int>& dequeIntSeq)
{
	// Here, in a loop, I pop out 2 integers from the sequence and
	//  store them into a pair then store the pair into the pairDeque
	intPairDeque pairDeque;

	while (dequeIntSeq.begin() != dequeIntSeq.end() && (dequeIntSeq.begin() + 1) != dequeIntSeq.end())
	{
		std::pair<int, int> pair;
		pair.first = *(dequeIntSeq.begin()); dequeIntSeq.pop_front();
		pair.second = *(dequeIntSeq.begin()); dequeIntSeq.pop_front();
		if (pair.second > pair.first)
			std::swap(pair.first, pair.second);
		g_comparisonCounter++;
		pairDeque.push_back(pair);
	}
	return pairDeque;
}

intPairDeque mergePairs(intPairDeque a, intPairDeque b)
{
	intPairDeque c;

	while(!a.empty() && !b.empty())
	{
		g_comparisonCounter++;
		if (a[0].first > b[0].first)
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

intPairDeque mergesortPairs(intPairDeque& pairDeque, int n)
{
	if (n == 1)
		return pairDeque;
	intPairDeque arr1;
	for (size_t i = 0; i < n / 2; i++)
		arr1.push_back(pairDeque[i]);

	intPairDeque arr2;
	for (size_t i = n / 2; i < n; i++)
		arr2.push_back(pairDeque[i]);

	arr1 = mergesortPairs(arr1, arr1.size());
	arr2 = mergesortPairs(arr2, arr2.size());

	return mergePairs(arr1, arr2);
}

std::deque<int> extractChain(const intPairDeque& pairDeque, int chainType)
{
	std::deque<int> chain;
	intPairDeque::const_iterator it;
	intPairDeque::const_iterator end = pairDeque.end();

	if (chainType == SORTED)
		for (it = pairDeque.begin(); it < end; it++)
			chain.push_back((*it).first);

	else if (chainType == UNSORTED)
		for (it = pairDeque.begin(); it < end; it++)
			chain.push_back((*it).second);

	return chain;
}

void binaryInsert(int pend, std::deque<int>& main, int high)
{
	std::deque<int>::iterator pos = main.begin();

	int low = 0;
	while (low < high)
	{
		int mid = (low + high) / 2;
		g_comparisonCounter++;
		if (main[mid] == pend)
		{
			main.insert(pos + mid, pend);
			return ;
		}
		else if (main[mid] > pend)
			high = mid - 1;
		else
			low = mid + 1;
	}
	// low == high
	g_comparisonCounter++;
	if (pend < main[low])
		main.insert(pos + low, pend);
	else
		main.insert(pos + low + 1, pend);
	return ;
}

void binaryInsertionSort(const std::deque<int>& pend, std::deque<int>& main)
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
			binaryInsert(pend[current - 1], main, high - 1); // -1 because indexing starts at 0
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

