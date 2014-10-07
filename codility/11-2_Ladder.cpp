
// Lesson 11 - Fibonacci Numbers
// Ladder
// Count the number of different ways of climbing to the top of a ladder.

#include <algorithm>
vector<int> solution(vector<int> &A, vector<int> &B) {
    int max = *max_element(A.begin(), A.end());
    unsigned long* solution = new unsigned long [max + 1];
    solution[0] = 0;
    solution[1] = 1;
    solution[2] = 2;
    for (int i = 3; i < max + 1; i++) {
        solution[i] = solution[i-1] + solution[i-2];
    }
    vector<int> result(A.size());
    for (unsigned i = 0; i < A.size(); i++) {
        result[i] = solution[A[i]] % (1 << B[i]);
    }
    return result;
}

