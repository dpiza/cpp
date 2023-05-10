#ifndef SORT_TPP
#define SORT_TPP

#include <algorithm>

template <typename T> void insertionSort(T &v) {
	for (typename T::iterator it = v.begin(); it != v.end(); it++) {
		typename T::iterator point = std::upper_bound(v.begin(), it, *it);
		std::rotate(point, it, it + 1);
	}
}

template <typename T> void merge(T &v, T left, T right) {
	int lSize = left.size();
	int rSize = right.size();
	int il = 0;
	int ir = 0;
	int iv = 0;

	while (il < lSize && ir < rSize) {
		v[iv++] = (left[il] <= right[ir]) ? left[il++] : right[ir++];
	}
	while (il < lSize) {
		v[iv++] = left[il++];
	}
	while (ir < rSize) {
		v[iv++] = right[ir++];
	}
}

template <typename T> void mergeSort(T &v) {
	if (v.size() > 5) {
		T left;
		T right;

		std::copy(v.begin(), v.begin() + (v.size() / 2),
				  std::back_inserter(left));
		std::copy(v.begin() + (v.size() / 2), v.end(),
				  std::back_inserter(right));

		mergeSort(left);
		mergeSort(right);
		merge(v, left, right);
	} else {
		insertionSort(v);
	}
}

#endif /* ***************************************************** SORT_TPP       \
		*/
