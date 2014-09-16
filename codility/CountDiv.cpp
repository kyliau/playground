#include <iostream>
#include <math.h>
using namespace std;

// Lesson 3 - Prefix Sums
// CountDiv
// Compute number of integers divisible by k in range [a..b].

int solution(int A, int B, int K) {
	int sol = ceil((double)(B - A) / K);
	if (A % K == 0 && B % K == 0) sol++;
	return sol;
}

int main() {
	while(1) {
		int A, B, C;
		cin >> A >> B >> C;
		cout << "Number of integers in [" << A << ", " << B << "] divisible by "
			   << C << " = " << solution(A, B, C) << endl;
	}
	return 0;
}
