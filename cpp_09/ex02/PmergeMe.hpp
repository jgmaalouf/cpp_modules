#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> vecIntSeq_;
	std::deque<int>   dequeIntSeq_;
	long             vecSortTime; // May change from long
	long             dequeSortTime;  // May change from long

	void             sortVec();
	// void             sortDeque();

	PmergeMe();
public:
	PmergeMe(std::vector<int> vecIntSeq, std::deque<int> dequeIntSeq);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();

	PmergeMe operator=(const PmergeMe& rhs);
	
	void     sort();
};

// Generates either the next or previous Jacobsthal number relative to the current number given
// Note: Assumes current is also in the Jacobsthal series
#define NEXT 0
#define PREV 1
size_t jacobsthalIndexGen(size_t current, int iteration);

/* Vector sorting utils */
typedef std::vector<std::pair<int, int> > intPairVec;
typedef std::vector<std::vector<int>::iterator> intVecIterator;
#define SORTED 0
#define UNSORTED 1

intPairVec       createPairs(std::vector<int> vecIntSeq);
intPairVec       mergePairs(intPairVec a, intPairVec b);
intPairVec       mergesortPairs(intPairVec& pairVec, int n);
std::vector<int> extractChain(intPairVec pairVec, int chainType);
intVecIterator   createIters(std::vector<int>& intVec);
void             binaryInsertionSort(std::vector<int>& pend, std::vector<int>& main, intVecIterator& mainIters);

/* Deque sorting utils */
