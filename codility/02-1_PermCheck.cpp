
// Lesson 2 - Counting Elements
// PermCheck
// Check whether array A is a permutation.

#include <unordered_map>
int solution(vector<int> &A) {
    unsigned N = A.size();
    unordered_map<int, bool> hash;
    for (int a : A) {
        if (a > N) return 0;
        if (hash.count(a) == 0) {
            hash[a] = true;
        } else {
            return 0;
        }
    }
    return 1;
}
