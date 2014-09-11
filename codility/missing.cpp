#include <iostream>
#include <vector>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

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
