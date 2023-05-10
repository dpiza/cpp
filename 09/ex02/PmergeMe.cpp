#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->_vec.clear();
		this->_deq.clear();
		this->load(rhs.getSeed());
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, PmergeMe const &i) {
	int size = i.getLoadedSize();
	o << "PMergeMe Obj ";
	if (size) {
		o << "loaded with " << size << " elements";
	} else {
		o << "empty";
	}
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::load(char **v) {
	this->_seed = v;
	int i = 1;
	while (v[i]) {
		this->_vec.push_back(std::atoi(v[i]));
		this->_deq.push_back(std::atoi(v[i]));
		i++;
	}
}

void PmergeMe::execute() {
	clock_t start;
	clock_t end;

	start = clock();
	mergeSort(this->_vec);
	end = clock();
	this->_vecSortingTime = (end - start) / (double)CLOCKS_PER_SEC;

	start = clock();
	mergeSort(this->_deq);
	end = clock();
	this->_deqSortingTime = (end - start) / (double)CLOCKS_PER_SEC;
}

void PmergeMe::print() {
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = this->_vec.end();
	int i = 0;

	for (it = this->_vec.begin(); it != ite; it++) {
		if (i == 10) {
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		i++;
	}

	std::cout << std::endl;
}

bool PmergeMe::isSorted(void) {
	std::vector<int> sorted;
	sorted.assign(this->_vec.begin(), this->_vec.end());
	std::sort(sorted.begin(), sorted.end());

	for (size_t i = 0; i < this->_vec.size(); i++) {
		if (sorted[i] != this->_vec[i]) {
			return false;
		}
	}
	return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

double PmergeMe::getVecSortingTime() const { return this->_vecSortingTime; }

double PmergeMe::getDeqSortingTime() const { return this->_deqSortingTime; }

char **PmergeMe::getSeed() const { return this->_seed; }

int PmergeMe::getLoadedSize() const { return this->_vec.size(); }

/* ************************************************************************** */