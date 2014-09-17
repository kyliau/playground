// Lesson 99 - Future Training
// StrSymmetryPoint
// Find a symmetry point of a string, if any.

int solution(string &S) {
    // write your code in C++11
    unsigned N = S.length();
    if (N <= 1) return 0;
    if (N % 2 == 0) return -1;
    unsigned left = 0; 
    unsigned right = N - 1;
    while (left != right) {
        if (S[left++] != S[right--]) {
            return -1;
        }
    }
    return N / 2;
}

