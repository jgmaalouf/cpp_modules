#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <utility>
#include <sys/time.h>

#define CHECKER
#define COMPARISON_COUNT

size_t g_comparisonCounter = 0;

PmergeMe::PmergeMe(std::vector<int> vecIntSeq, std::deque<int> dequeIntSeq)
: vecIntSeq_(vecIntSeq)
, vecCompCount_(0)
, dequeCompCount_(0)
, dequeIntSeq_(dequeIntSeq) {}

PmergeMe::PmergeMe(const PmergeMe& obj)
: vecIntSeq_(obj.vecIntSeq_)
, vecCompCount_(obj.vecCompCount_)
, dequeCompCount_(obj.dequeCompCount_)
, dequeIntSeq_(obj.dequeIntSeq_) {}

PmergeMe::~PmergeMe(){}

PmergeMe PmergeMe::operator=(const PmergeMe& rhs)
{
	vecIntSeq_ = rhs.vecIntSeq_;
	vecCompCount_ = rhs.vecCompCount_;
	dequeCompCount_ = rhs.dequeCompCount_;
	dequeIntSeq_ = rhs.dequeIntSeq_;
	return *this;
}

void PmergeMe::sort()
{
	std::cout << "Before:\t";
	size_t inputSize = vecIntSeq_.size();
	for (size_t i = 0; i < inputSize; i++)
		std::cout << vecIntSeq_[i] << ' ';
	std::cout << std::endl;

#ifdef CHECKER
	vecSortCheck();
	dequeSortCheck();
#endif

	if (inputSize > 1)
	{
		sortVec();
		vecCompCount_ = g_comparisonCounter;
		g_comparisonCounter = 0;
		sortDeque();
		dequeCompCount_ = g_comparisonCounter;
		g_comparisonCounter = 0;
	}

	std::cout << "After:\t";
	for (size_t i = 0; i < inputSize; i++)
		std::cout << vecIntSeq_[i] << ' ';
	std::cout << std::endl;

#ifdef CHECKER
	vecSortCheck();
	dequeSortCheck();
#endif

	std::cout << "Time to process a range of "
		<< std::setw(7) << inputSize << " elements with std::vector<int> : ";
	std::cout << std::fixed << std::setprecision(6) << vecSortTime_ << " seconds";

	std::cout << std::endl << "Time to process a range of "
		<< std::setw(7) << inputSize << " elements with std::deque<int>  : ";
	std::cout << std::fixed << std::setprecision(6) << dequeSortTime_ << " seconds";

#ifdef COMPARISON_COUNT
	std::cout << "\n\033[1;34mComparison counter for std::vector<int>: \033[0m" << vecCompCount_ << std::endl;
	std::cout << "\033[1;34mComparison counter for std::deque<int>: \033[0m" << dequeCompCount_ << std::endl;
#endif
}

void PmergeMe::sortVec()
{
	struct timeval begin, end;

	// Start timing
	gettimeofday(&begin, 0);
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

	// Since the first int in the pend chain is always less than the first int in the main
	//  we add it to the main chain
	main.insert(main.begin(), pend[0]);

	// Insert the pend integers into main using the Jacobsthal indexing and binary search.
	binaryInsertionSort(pend, main);

	// Still have to check if the vecIntSeq_ is not empty. If not there is one element left in it to insert
	if (!vecIntSeq_.empty())
		binaryInsert(vecIntSeq_[0], main, main.size() - 1);

	// End timing
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	vecSortTime_ = seconds + microseconds * 1e-6;

	// Set the result of the sorting to vecIntSeq_
	vecIntSeq_ = main;
}

void PmergeMe::sortDeque()
{
	struct timeval begin, end;

	// Start timing
	gettimeofday(&begin, 0);

	// First step in the merge insertion sort is to make pairs of all the numbers,
	//  so I'm going to use a deque where I store all the pairs
	intPairDeque pairDeque = createPairs(dequeIntSeq_);

	// Now we sort the pairs using merge sort based on the largest int from the two pairs
	pairDeque = mergesortPairs(pairDeque, pairDeque.size());

	// main: Contains all the largest ints from the pairs and these form a sorted chain
	// pend (pending): Contains all the smallest ints from the pairs and these form an unsorted chain
	//  that we need to insert into the main chain.
	std::deque<int> main = extractChain(pairDeque, SORTED);
	std::deque<int> pend = extractChain(pairDeque, UNSORTED);

	// Since the first int in the pend chain is always less than the first int in the main
	//  we add it to the main chain
	main.insert(main.begin(), pend[0]);

	// Insert the pend integers into main using the Jacobsthal indexing and binary search.
	binaryInsertionSort(pend, main);

	// Still have to check if the dequeIntSeq_ is not empty. If not there is one element left in it to insert
	if (!dequeIntSeq_.empty())
		binaryInsert(dequeIntSeq_[0], main, main.size() - 1);

	// End timing
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	dequeSortTime_ = seconds + microseconds * 1e-6;

	// Set the result of the sorting to dequeIntSeq_
	dequeIntSeq_ = main;
}

void PmergeMe::vecSortCheck()
{
	std::cout << "\033[1;34mChecking sorting for std::vector<int>: \033[0m";
	for (size_t i = 0; i < vecIntSeq_.size() - 1; i++)
	{
		if (vecIntSeq_[i] > vecIntSeq_[i + 1])
		{
			std::cout << "\033[1;31mUNSORTED\033[0m" << std::endl;
			return ;
		}
	}
	std::cout << "\033[1;32mSORTED SUCCESSFULLY\033[0m" << std::endl;
}

void PmergeMe::dequeSortCheck()
{
	std::cout << "\033[1;34mChecking sorting for std::deque<int>: \033[0m";
	for (size_t i = 0; i < dequeIntSeq_.size() - 1; i++)
	{
		if (dequeIntSeq_[i] > dequeIntSeq_[i + 1])
		{
			std::cout << "\033[1;31mUNSORTED\033[0m" << std::endl;
			return ;
		}
	}
	std::cout << "\033[1;32mSORTED SUCCESSFULLY\033[0m" << std::endl;
}

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
