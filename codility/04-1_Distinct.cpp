
// Lesson 4 - Sorting
// Distinct
// Compute number of distinct values in an array.

#include <unordered_set>
int solution(vector<int> &A) {
    unordered_set<int> set;
    for (int a : A) {
        set.insert(a);
    }
    return set.size();
}

// The required runtime in O(n log n)
// So alternatively we could sort the array, and do a pass to check for
// distinct elements
