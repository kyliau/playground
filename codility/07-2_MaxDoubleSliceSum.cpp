#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Lesson 7 - Maximum Slice Problem
// MaxDoubleSliceSum
// Find the maximal sum of any double slice.

// test cases:
// [-3, 6, -1, 4, 5, -1, 2]
// [-3, -2, 100, 12, -6, -150, -1, 4, 5, -6]
// [-3, -2, -6, -1, -4, -5, -1, 20]
// [-3, 2, -6]

// couldn't solve this one :(
// reference: http://rafal.io/posts/codility-max-double-slice-sum.html

#include <algorithm>
int solution(vector<int> &A) {
    unsigned N = A.size();
    int* B = new int[N];
    int* C = new int[N];
    B[0] = B[N-1] = C[0] = C[N-1] = 0;
    
    for (unsigned i = 1; i < N - 1; i++) {
        B[i] = max(0, B[i-1] + A[i]);
    }
    
    for (unsigned i = N - 2; i > 0; i--) {
        C[i] = max(0, C[i+1] + A[i]);
    }
    
    int result = 0;
    for (unsigned i = 1; i < N - 1; i++) {
        result = max(result, B[i-1] + C[i+1]);
    }
    
    return result;
}

