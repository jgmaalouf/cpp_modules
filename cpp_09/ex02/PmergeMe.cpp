#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

PmergeMe::PmergeMe(std::vector<int> vecIntSeq, std::list<int> lsIntSeq)
: vecIntSeq_(vecIntSeq)
, lsIntSeq_(lsIntSeq) {}

PmergeMe::PmergeMe(const PmergeMe& obj)
: vecIntSeq_(obj.vecIntSeq_)
, lsIntSeq_(obj.lsIntSeq_) {}

PmergeMe::~PmergeMe(){}

PmergeMe PmergeMe::operator=(const PmergeMe& rhs)
{
	vecIntSeq_ = rhs.vecIntSeq_;
	lsIntSeq_ = rhs.lsIntSeq_;
	return *this;
}

void PmergeMe::sort()
{
	// std::cout << "Before:\t";
	// size_t inputSize = vecIntSeq_.size();
	// for (size_t i = 0; i < inputSize; i++)
	// 	std::cout << vecIntSeq_[i] << ' ';

	// std::cout << std::endl << "After:\t";
	sortVec();
	// sortLs();
	// for (size_t i = 0; i < inputSize; i++)
	// 	std::cout << vecIntSeq_[i] << ' ';

	// std::cout << std::endl << "Time to process a range of "
	// 	<< std::setw(7) << inputSize;
	// std::cout << " with std::vector<int> : " << vecSortTime;
	// std::cout << std::endl << "Time to process a range of "
	// 	<< std::setw(7) << inputSize;
	// std::cout << " with std::list<int> : " << lsSortTime;
	
}

std::vector<struct pairs> createPairs(std::vector<int> vecIntSeq)
{
	// Here, in a loop, I pop out 2 integers from the sequence and
	// store them into a pair then store the pair into the pairVec
	std::vector<struct pairs> pairVec;
	std::vector<int>::iterator it = vecIntSeq.begin();
	while (it != vecIntSeq.end() && (it + 1) != vecIntSeq.end())
	{
		int a = *it; vecIntSeq.erase(it);
		int b = *it; vecIntSeq.erase(it);
		struct pairs pair;
		pair.main = a; pair.pend = b;
		if (a < b) // Comparison made. Should increment a variable
			std::swap(pair.main, pair.pend);
		pairVec.push_back(pair);
	}
	return pairVec;
}

void PmergeMe::sortVec()
{
	// First step in the merge insertion sort is to make pairs of all the numbers
	// So I'm going to use a vector where I store all the pairs
	std::vector<struct pairs> pairVec = createPairs(vecIntSeq_);
	// Now we sort the pairs using mergesort based on the main integer, creating
	// a sorted chain we'll call the main chain
	sortPairs(pairVec);
	// Now we insert the integers in the pend chain into the main chain
	// HERE I NEED TO RETHINK
}

// void PmergeMe::sortLs()
// {
	
// }
