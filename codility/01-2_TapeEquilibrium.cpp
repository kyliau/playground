
// Lesson 1 - Time Complexity
// TapeEquilibrium
// Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.


#include <math.h>
int solution(vector<int> &A) {
    
    int left = A[0], right = 0;
    
    for (unsigned i = 1; i < A.size(); i++) {
        right += A[i];
    }
    int min = abs(left - right);
    for (unsigned i = 1; i < A.size() - 1; i++) {
        left += A[i];
        right -= A[i];
        int temp = abs(left - right);
        if (temp < min) {
            min = temp;
        }
    }
    
    return min;
}
