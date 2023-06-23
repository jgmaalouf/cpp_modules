#include <vector>
#include <deque>

extern size_t g_comparisonCounter;

class PmergeMe
{
private:
	std::vector<int> vecIntSeq_;
	std::deque<int>  dequeIntSeq_;
	double           vecSortTime_;
	double           dequeSortTime_;

	size_t           vecCompCount_;
	size_t           dequeCompCount_;

	void             vecSortCheck();
	void             dequeSortCheck();

	void             sortVec();
	void             sortDeque();

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
#define SORTED 0
#define UNSORTED 1

intPairVec       createPairs(std::vector<int>& vecIntSeq);
intPairVec       mergePairs(intPairVec a, intPairVec b);
intPairVec       mergesortPairs(intPairVec& pairVec, int n);
std::vector<int> extractChain(const intPairVec& pairVec, int chainType);
void             binaryInsertionSort(const std::vector<int>& pend, std::vector<int>& main);
void             binaryInsert(int pend, std::vector<int>& main, int high);

/* Deque sorting utils */
typedef std::deque<std::pair<int, int> > intPairDeque;
#define SORTED 0
#define UNSORTED 1

intPairDeque     createPairs(std::deque<int>& dequeIntSeq);
intPairDeque     mergePairs(intPairDeque a, intPairDeque b);
intPairDeque     mergesortPairs(intPairDeque& pairVec, int n);
std::deque<int>  extractChain(const intPairDeque& pairVec, int chainType);
void             binaryInsertionSort(const std::deque<int>& pend, std::deque<int>& main);
void             binaryInsert(int pend, std::deque<int>& main, int high);
