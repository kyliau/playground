
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

// A solution that doesn't make use of any data structures
// OK, but got arithmetic overflow error ...

#include <math.h>
int solution(vector<int>& A) {
  long prev = -1;
  unsigned count = 0;
  auto left = A.begin(), right = A.end() - 1;
  while (left <= right) {
    long leftVal = abs(*left), rightVal = abs(*right);
    if (leftVal > rightVal) {
      if (leftVal != prev) {
        prev = leftVal;
        count++;
      }
      left++;
    } else if (rightVal > leftVal) {
      if (rightVal != prev) {
        prev = rightVal;
        count++;
      }
      right--;
    } else {
      if (leftVal != prev) {
        prev = leftVal;
        count++;
      }
      left++;
      right--;
    } 
  }
  return count;
}

