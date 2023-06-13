#include <vector>
#include <list>

class PmergeMe
{
private:
	char** intSeq_;
	PmergeMe();
public:
	PmergeMe(char** intSeq);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();

	PmergeMe operator=(const PmergeMe& rhs);
	
	std::vector<int> sort(std::vec);
};
