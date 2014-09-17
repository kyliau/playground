
// Lesson 4 - Sorting
// Triangle
// Determine whether a triangle can be built from a given set of edges.

#include <algorithm>
int solution(vector<int> &A) {
  if (A.size() < 3) return 0;
  sort(A.begin(), A.end());
  long int last = A.back();
  for (unsigned i = A.size() - 2; i >= 1; i--) {
    long int first = A[i-1];
    long int cur = A[i];
    if (first > last - cur && cur > first - last && 
      first > cur - last) {
      return 1;
    }
    last = cur;
  }
  return 0;
}
