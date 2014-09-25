
// Lesson 7 - Maximum Slice Problem
// MaxProfit
// Given a log of stock prices compute the maximum possible earning.

// O(n) solution
#include <algorithm>
int solution(vector<int> &A) {
    if (A.empty()) return 0;
    int min = A[0], profit = 0;
    for (int a : A) {
        if (a < min) {
            min = a;
        }
        profit = max(profit, a - min);
    }
    return profit;
}

// O(n log n) solution
int helper(const vector<int>& A, unsigned left, unsigned right) {
	if (right <= left) return 0;
	int mid = (right - left + 1) / 2;
	vector<int> v;
	v.push_back(helper(A, left, mid));
	v.push_back(helper(A, mid+1, right));
	auto it = A.begin();
	v.push_back(max_element(it + mid, A.end()) - min_element(it, it + mid));
	return max_element(v.begin(), v.end());
	/*
	 * in pseudo code:
	 * return max(helper(A, left, mid), 
	 *            helper(A, mid+1, right), 
	 *            max_element(right half) - min(left half))
	 */
}

int solution(vector<int> &A) {
	helper(A, 0, A.size() - 1);
}
