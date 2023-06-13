#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** intSeq)
: intSeq_(intSeq)
{
}


PmergeMe::PmergeMe(const PmergeMe& obj)
: intSeq_(obj.intSeq_)
{
}

PmergeMe::~PmergeMe(){}

PmergeMe PmergeMe::operator=(const PmergeMe& rhs)
{
	intSeq_ = rhs.intSeq_;
}

std::vector<int> sortVec()
{
	
}

