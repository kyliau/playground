
// Lesson 1 - Time Complexity
// PermMissingElem
// Find the missing element in a given permutation.

int solution(vector<int> &A) {
    unsigned N = A.size() + 1;
    unsigned sum = (1 + N) * N / 2;
    unsigned arraySum = 0;
    for (int a : A) {
        arraySum += a;
    }
    return sum - arraySum;
}
