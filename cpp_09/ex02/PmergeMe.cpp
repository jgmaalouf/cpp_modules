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
}

void PmergeMe::sort()
{
	std::cout << "Before:\t";
	size_t inputSize = vecIntSeq_.size();
	for (size_t i = 0; i < inputSize; i++)
		std::cout << vecIntSeq_[i] << ' ';

	std::cout << std::endl << "After:\t";
	sortVec();
	sortLs();
	for (size_t i = 0; i < inputSize; i++)
		std::cout << vecIntSeq_[i] << ' ';

	std::cout << std::endl << "Time to process a range of "
		<< std::setw(7) << inputSize;
	std::cout << " with std::vector<int> : " << vecSortTime;
	std::cout << std::endl << "Time to process a range of "
		<< std::setw(7) << inputSize;
	std::cout << " with std::list<int> : " << lsSortTime;
	
}

std::vector<int> sortVec()
{
	
}

std::list<int> sortLs()
{
	
}

