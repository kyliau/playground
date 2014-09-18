
// Lesson 3 - Prefix Sums
// MinAvgTwoSlice
// Find the minimal average of any slice containing at least two elements.

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	double smallest = 0.5 * (A[0] + A[1]);
	unsigned start_pos = 0;
	for (unsigned i = 1; i < A.size() - 1; ++i) {
		double avg = 0.5 * (A[i] + A[i+1]);
		if (avg < smallest) {
			smallest = avg;
			start_pos = i;
		}
	}
	// detect cases like ( 1 + 2 + 0 ) / 3
	for (unsigned i = 0; i < A.size() - 2; ++i) {
		double avg = (A[i] + A[i+1] + A[i+2]) / 3.0;
		if (avg < smallest) {
			smallest = avg;
			start_pos = i;
		}
	}
	return start_pos;
}

int main() {
	vector<int> A {4, 2, 2, 5, 1, 5, 8};
	cout << solution(A) << endl;
	return 0;
}
