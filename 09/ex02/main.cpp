#include "PmergeMe.hpp"

int main(int c, char **v) {
	if (c < 2) {
		std::cout << "Usage:\t./PMergeMe N N1 N2 N3 N4\n";
		return 1;
	}
	PmergeMe PMe;

	PMe.load(v);

	std::cout << "Before:\t";
	PMe.print();
	PMe.execute();
	std::cout << "After:\t";
	PMe.print();
	if (!PMe.isSorted()) {
		std::cout << "Sorting failed\n";
		return 1;
	}
	std::cout << "Time to process a range of " << std::setw(4) << c - 1;
	std::cout << " elements with std::vector : " << std::fixed
			  << PMe.getVecSortingTime() << " us"
			  << "\n";
	std::cout << "Time to process a range of " << std::setw(4) << c - 1;
	std::cout << " elements with std::deque  : " << std::fixed
			  << PMe.getDeqSortingTime() << " us"
			  << "\n";
	return 0;
}