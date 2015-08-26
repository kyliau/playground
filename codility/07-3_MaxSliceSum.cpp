
// Lesson 7 - Maximum Slice Problem
// MaxSliceSum
// Find a maximum sum of a compact subsequence of array elements.

#include <algorithm>
int solution(vector<int> &A) {
    
    // check the case when all numbers are negative
    int max_elem = *max_element(A.begin(), A.end());
    if (max_elem < 0) return max_elem;
    
    int sum = 0, max_sum = 0;
    for (int a : A) {
        sum = max(0, sum + a);
        max_sum = max(max_sum, sum);
    }
    return max_sum;

}

// Variant of this problem:
// Show the left and right index of the subsequence (subarray)
