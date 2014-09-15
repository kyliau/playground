#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

// generates a number that is in [min, max]
unsigned pick_index(unsigned min, unsigned max) {
	// simple implementation:
	return min + (max - min) / 2;
}

void partition(vector<int>& A, unsigned left, unsigned right, unsigned index) {
	assert(index >= left && index <= right);

	int target = A[index];
	cout << "index = " << index << ", target = " << target << endl;

	swap(A[index],A[right]);
	unsigned j = left;
	for (unsigned i = left; i < right; i++) {
		if (A[i] < target) {
			swap(A[i], A[j]);
			j++;
		}
	}
	swap(A[j],A[right]);
	/*
	for (unsigned i = left; i <= right; i++) {
		if (A[i] > target) {
			swap(A[i], A[index]);
			index = i;
			break;
		}
	}
	*/
	for (int a : A) {
		cout << a << " ";
	}
	cout << endl;
	for (unsigned i = left; i <= right; i++) {
		if (i <= j) {
			assert(A[i] <= A[j]);
		} else {
			assert(A[i] > A[j]);
		}
	}

}

// sort the vector v from v[left] to v[right] (inclusive)
void quicksort(vector<int>& A, unsigned left, unsigned right) {

	if (left >= right) return;

	// randomly pick an element within [left, right]
	unsigned index = pick_index(left, right);
	partition(A, left, right, index);
	// at this point v[index] is at the correct location in the sorted array
	// all elements to the left of A[index] are <= A[index], all elements to the
	// right are > A[index]
	quicksort(A, left, index-1);
	quicksort(A, index+1, right);
}

void quicksort(vector<int>& A) {
	quicksort(A, 0, A.size() - 1);
}

int main() {
	vector<int> A {5,2,6,3,7,8,9,3,29,0,-5,47,92,-33,0,1,50,16,-3,4,0};
	quicksort(A);
	cout << "sorted array: " << endl;
	for (int a : A) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
