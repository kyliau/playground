#include <iostream>
#include <vector>
using namespace std;

// Lesson 99 - Future Training
// ArrayInversionCount
// Compute number of inversion in an array.


// An inversion is a pair of elements in an array such that
// i < j but A[i] > A[j]. 
// Count the total number of inversions in a given array.

// invariant: vectors A and B must be sorted
// merge A and B and save the result in v
unsigned merge(vector<int>& v, const vector<int>& A, const vector<int>& B) {

	const unsigned N = A.size(), M = B.size();
	unsigned i = 0, j = 0, count = 0;

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
			count += N - i;
		}
	}

	return count;

}

// invariant: when the function returns, vector A becomes sorted
// this is basically just mergesort with a (clever) twist
// O( nlog(n) )
unsigned countInversion(vector<int>& A) {
	unsigned N = A.size();
	
	// by definition, an empty array or a single element array is sorted
	if (N <= 1) return 0;

	unsigned mid = N / 2;

	vector<int> left(A.begin(), A.begin() + mid);
	vector<int> right(A.begin() + mid, A.end());

	return countInversion(left) + countInversion(right) + merge(A, left, right);
}

// this version is O(n^2) but it is guaranteed to work.
unsigned countInversionSlow(const vector<int>& A) {
	unsigned N = A.size(), count = 0;
	for (unsigned i = 0; i < N; ++i) {
		for (unsigned j = i + 1; j < N; ++j) {
			if (A[i] > A[j]) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector<int> A {5,8,2,8,4,0,7,4,5,1,7,1,6,8,3,6,7,8,9,10,9,-1,-10};
	unsigned count1 = countInversionSlow(A);
	unsigned count2 = countInversion(A);
	// at this point A is sorted, so the inversion count should be 0
	unsigned count3 = countInversionSlow(A);
	unsigned count4 = countInversion(A);
	/*
	for (int a : A) {
		cout << a << " ";
	}
	*/
	cout << count1 << " " << count2 << " " << count3 << " " << count4 << endl;
	return 0;
}
