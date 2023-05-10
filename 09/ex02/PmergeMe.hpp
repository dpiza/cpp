#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Sort.tpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {

  public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	void load(char **);
	void print();
	void execute();

	double getVecSortingTime() const;
	double getDeqSortingTime() const;
	char **getSeed() const;
	int getLoadedSize() const;
	bool isSorted();

  private:
	char **_seed;

	std::vector<int> _vec;
	std::deque<int> _deq;

	double _vecSortingTime;
	double _deqSortingTime;
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif /* ***************************************************** PMERGEME_H */