
// Lesson 4 - Sorting
// MaxProductOfThree
// Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).

// This one is rated as painless but it is tricky!

#include <algorithm>
int solution(vector<int> &A) {
    unsigned N = A.size() - 1;
    sort(A.begin(), A.end());
    if (A[N] < 0) return A[N] * A[N-1] * A[N-2];
    return A[N] * max(A[0] * A[1], A[N-1] * A[N-2]);
}
