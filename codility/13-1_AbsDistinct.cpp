
// Lesson 13 - Caterpillar method
// AbsDistinct
// Compute number of distinct absolute values of sorted array elements.

#include <unordered_set>
#include <math.h>
int solution(vector<int> &A) {
    unordered_set<unsigned> set;
    for (int a : A) {
        set.insert(abs(a));
    }
    return set.size();
}
