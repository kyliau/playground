#include <iostream>
#include <vector>
using namespace std;

// Lesson 2 - Counting Elements
// MissingInteger
// Find the minimal positive integer not occurring in a given sequence.

int solution(vector<int> &A) {
    int N = A.size();
    vector<bool> B(N);
    fill(B.begin(), B.end(), false);
    for (int a : A) {
        if (a > 0 && a <= N) {
            B[a-1] = true;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!B[i]) {
            return i + 1;
        }
    }
    return N + 1;
}

