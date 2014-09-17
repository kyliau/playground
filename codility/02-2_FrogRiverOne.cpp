
// Lesson 2 - Counting Elements
// FrogRiverOne
// Find the earliest time when a frog can jump to the other side of a river.

int solution(int X, vector<int> &A) {
    vector<bool> B(X, false);
    long sum = (1 + X) * X / 2;
    long arraySum = 0;
    for (unsigned i = 0; i < A.size(); ++i) {
        if (A[i] > X) continue;
        if (!B[A[i]-1]) {
            B[A[i]-1] = true;
            arraySum += A[i];
            if (arraySum == sum) {
                return i;
            }
        }
    }
    return -1;
}

