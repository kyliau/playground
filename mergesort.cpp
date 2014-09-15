#include <iostream>
#include <vector>
using namespace std;

// invariant: vectors A and B must be sorted
// merge A and B and save the result in v
void merge(vector<int>& v, const vector<int>& A, const vector<int>& B) {

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

// invariant: when the function returns, vector A is sorted
void mergesort(vector<int>& A) {
	unsigned N = A.size();
	
	// by definition, an empty array or a single element array is sorted
	if (N <= 1) return;

	unsigned mid = N / 2;

	vector<int> left(A.begin(), A.begin() + mid);
	vector<int> right(A.begin() + mid, A.end());

	mergesort(left);
	mergesort(right);
	merge(A, left, right);
}

int main() {
	vector<int> A {5,8,2,8,4,0,7,4,5,1,7,1,6,8,3,6,7,8,9,10,9,-1,-10};
	mergesort(A);
	for (int a : A) {
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
