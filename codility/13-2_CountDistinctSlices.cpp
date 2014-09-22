
// Lesson 13 - Caterpillar Method
// CountDistinctSlices
// Count the number of distinct slices (containing only unique numbers).


// Idea: Grow the slice until we encounter a duplicate, then we stop, count
//       the number of possible sub-slices, then apply the same algorithm 
//       starting at the duplicate node

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;

// fail one test ..... large_range

#include <unordered_map>
int solution(int M, vector<int>& A) {
  unordered_map<int, unsigned> map;
  unsigned count = 0;
  unsigned tail = 0;
  for (unsigned i = 0; i < A.size(); ++i) {
    if (map.count(A[i]) > 0 && map[A[i]] >= tail) {
      unsigned last_seen = map[A[i]];
      unsigned N = last_seen - tail + 1;
      count += (1 + N) * N / 2;
      if (count > 1e9) return 1e9;
      count += (i - last_seen - 1) * N;
      if (count > 1e9) return 1e9;
      tail = last_seen + 1;
    }
    map[A[i]] = i;
  }
  unsigned N = A.size() - tail;
  count += (1 + N) * N / 2;
  if (count > 1e9) return 1e9;
  return count;
}


int solution_slow(int M, const vector<int>& A) {
  unsigned N = A.size(), count = 0;
  unordered_set<int> set;
  for (unsigned int i = 0; i < N; i++) {
    set.clear();
    for (unsigned int j = i; j < N; ++j) {
      if (set.count(A[j]) > 0) break;
      set.insert(A[j]);
    }
    count += set.size();
  }
  return count;
}

int main() {
  vector<int> A {3, 4, 5, 5, 2};
  cout << solution_slow(5, A) << '\t' << solution(5, A) << endl;
  vector<int> B {1, 1, 2, 1, 1};
  cout << solution_slow(2, B) << '\t' << solution(2, B) << endl;
  vector<int> C {1, 1, 2, 3, 4, 1, 1};
  cout << solution_slow(4, C) << '\t' << solution(4, C) << endl;
  vector<int> D {1, 4, 3, 4};
  cout << solution_slow(4, D) << '\t' << solution(4, D) << endl;
  while (1) {
    vector<int> X;
    int x;
    cout << "Enter numbers: ";
    while (cin >> x) {
      if (x < 0) break;
      X.push_back(x);
    }
    cout << "Correct: " << solution_slow(100, X) << "\tYour answer: " 
         << solution(100, X) << endl;
  }
  return 0;
}

/*
An integer M and a non-empty zero-indexed array A consisting of 
N non-negative integers are given. All integers in array A are 
less than or equal to M.

A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called 
a slice of array A. 

The slice consists of the elements A[P], A[P + 1], ..., A[Q]. 

A distinct slice is a slice consisting of only unique numbers. 
That is, no individual number occurs more than once in the slice.

For example, consider integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2

    There are exactly nine distinct slices: 
(0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

The goal is to calculate the number of distinct slices.

Write a function:

int solution(int M, vector<int> &A);

that, given an integer M and a non-empty zero-indexed array A 
consisting of N integers, returns the number of distinct slices.

If the number of distinct slices is greater than 1,000,000,000, 
the function should return 1,000,000,000.

For example, given integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2
the function should return 9, as explained above.

Assume that:
N is an integer within the range [1..100,000];
M is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..M].

Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(M), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/
