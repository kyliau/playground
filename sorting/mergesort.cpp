#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

using ConstIt = vector<int>::const_iterator;

// invariant: [first, middle) and [middle, last) must be sorted.
// output   : [first, last) is sorted.
void merge(ConstIt first, ConstIt middle, ConstIt last) {

	unsigned N = A.size(), M = B.size();
	unsigned i = 0, j = 0;

	while (i < N || j < M) {
		if (i == N) {
			v[i+j] = B[j];
			j++;
		} else if (j == M) {
			v[i+j] = A[i];
			i++;
		} else if (A[i] <= B[j]) {
			v[i+j] = A[i];
			i++;
		} else {
			v[i+j] = B[j];
			j++;
		}
	}

}

// input    : Two iterators where 'left' points to the first element
//            in the vector, 'right' points to one past the last
//            element in the vector.
// invariant: when the function returns, [left..right) is sorted.
void mergesort(ConstIt first, ConstIt last) {
	size_t N = last - first;
	
	// by definition, an empty array or a single element array is sorted
	if (N <= 1) return;

	size_t mid = N / 2;

	mergesort(first, first + mid);
	mergesort(first + mid, last);
	merge(first, first + mid, last);
}

int main() {
	vector<int> A {5,8,2,8,4,0,7,4,5,1,7,1,6,8,3,6,7,8,9,10,9,-1,-10};
	mergesort(A.begin(), A.end());
	ostream_iterator<int> outIt(cout, " ");
	copy(A.begin(), A.end(), outIt);
	return 0;
}
