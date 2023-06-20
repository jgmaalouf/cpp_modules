#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <utility>

PmergeMe::PmergeMe(std::vector<int> vecIntSeq, std::deque<int> dequeIntSeq)
: vecIntSeq_(vecIntSeq)
, dequeIntSeq_(dequeIntSeq) {}

PmergeMe::PmergeMe(const PmergeMe& obj)
: vecIntSeq_(obj.vecIntSeq_)
, dequeIntSeq_(obj.dequeIntSeq_) {}

PmergeMe::~PmergeMe(){}

PmergeMe PmergeMe::operator=(const PmergeMe& rhs)
{
	vecIntSeq_ = rhs.vecIntSeq_;
	dequeIntSeq_ = rhs.dequeIntSeq_;
	return *this;
}

void PmergeMe::sort()
{
	// std::cout << "Before:\t";
	size_t inputSize = vecIntSeq_.size();
	// for (size_t i = 0; i < inputSize; i++)
	// 	std::cout << vecIntSeq_[i] << ' ';

	// std::cout << std::endl << "After:\t";
	sortVec();
	// sortLs();
	for (size_t i = 0; i < inputSize; i++)
		std::cout << vecIntSeq_[i] << ' ';

	// std::cout << std::endl << "Time to process a range of "
	// 	<< std::setw(7) << inputSize;
	// std::cout << " with std::vector<int> : " << vecSortTime;
	// std::cout << std::endl << "Time to process a range of "
	// 	<< std::setw(7) << inputSize;
	// std::cout << " with std::deque<int> : " << dequeSortTime;
	
}

void PmergeMe::sortVec()
{
	// First step in the merge insertion sort is to make pairs of all the numbers,
	//  so I'm going to use a vector where I store all the pairs
	intPairVec pairVec = createPairs(vecIntSeq_);

	// Now we sort the pairs using merge sort based on the largest int from the two pairs
	pairVec = mergesortPairs(pairVec, pairVec.size());

	// main: Contains all the largest ints from the pairs and these form a sorted chain
	// pend (pending): Contains all the smallest ints from the pairs and these form an unsorted chain
	//  that we need to insert into the main chain.
	std::vector<int> main = extractChain(pairVec, SORTED);
	std::vector<int> pend = extractChain(pairVec, UNSORTED);

	// We make a vector of iterators which point to the integers in the main chain
	std::vector<std::vector<int>::iterator> mainIters = createIters(main);

	// Since the first int in the pend chain is always less than the first int in the main
	//  we add it to the main chain
	main.insert(main.begin(), pend[0]);

	// Insert the pend integers into main using the Jacobsthal indexing and binary search.
	//  The mainIters are for not losing track of the linked indexing between main and pend when main grows in size
	binaryInsertionSort(pend, main, mainIters);

	// Still have to check if the vecIntSeq_ is not empty. If not there is one element left in it to insert
	vecIntSeq_ = main;
}

// void PmergeMe::sortDeque()
// {
	
// }

size_t jacobsthalIndexGen(size_t current, int iteration)
{
	size_t n_2 = 0; // n-2
	size_t n_1 = 1; // n-1
	size_t n = 1;

	while (n < current)
	{
		n = 2 * n_2 + n_1;
		n_2 = n_1;
		n_1 = n;
	}

	if (iteration == NEXT)
		return (2 * n_2 + n_1);
	// Otherwise it's PREV
	return n_2;
}
