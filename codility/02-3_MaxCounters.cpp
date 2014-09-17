#include <vector>
#include <iostream>
using namespace std;

// Lesson 2 - Counting Elements
// MaxCounters
// Calculate the values of counters after applying all alternating operations: 
// increase counter by 1; set value of all counters to current maximum.


vector<int> solution(int N, vector<int> &A)
{
	vector<int> counter(N, 0);
	int max_counter = 0;
	int minimum = 0;

	for (int i = 0; i < A.size(); ++i) {
		if (A[i] <= N) {
			int& val = counter[A[i] - 1];
			if (val < minimum) {
				val = minimum + 1;
			} else {
				val++;
			}
			if (val > max_counter) {
				max_counter = val;
			}
		} else {
			minimum = max_counter;
		}
	}

	for (int& c : counter) {
		c = c < minimum ? minimum : c;
	}

	return counter;
}

int main()
{
	vector<int> A {3, 4, 4, 6, 1, 4, 4};
	vector<int> B = solution(5, A);
	for (int n : B) {
		cout << n << ", ";
	}
	cout << endl;
	return 0;
}
