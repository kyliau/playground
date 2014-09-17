#include <iostream>
#include <vector>
using namespace std;

// Lesson 2 - Counting Elements
// MissingInteger
// Find the minimal positive integer not occurring in a given sequence.

int solution(vector<int> &A) {
	int missing = 1;
	int largest = 0;

	for (int a : A) {
		if (a == missing) {
			missing++;
		}
	}
	return missing;
}

int main() {
	vector<int> A {1, 3, 6, 4, 1, 2};
	cout << solution(A) << endl;
}
