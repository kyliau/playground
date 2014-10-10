
// Lesson 13 - Caterpillar Method
// MinAbsSumOfTwo
// Find the minimal absolute value of a sum of two elements.

#include <math.h>
#include <algorithm>
int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int left = 0, right = A.size() - 1;
    int sum = abs(A[left] + A[right]);
    while (left < right) {
      int c1 = abs(A[left+1] + A[right]);
      int c2 = abs(A[left] + A[right-1]);
      if (c1 < c2) {
          sum = min(sum, c1);
          left++;
      } else {
          sum = min(sum, c2);
          right--;
      }
    }
    return sum;
}
