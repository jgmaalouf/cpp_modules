#include <vector>
#include <list>

class PmergeMe
{
private:
	std::vector<int> vecIntSeq_;
	std::list<int>   lsIntSeq_;
	long             vecSortTime; // May change from long
	long             lsSortTime;  // May change from long

	void             sortVec();
	void             sortLs();

	PmergeMe();
public:
	PmergeMe(std::vector<int> vecIntSeq, std::list<int> lsIntSes);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();

	PmergeMe operator=(const PmergeMe& rhs);
	
	void     sort();
};
