
// Lesson 13 - Caterpillar Method
// CountDistinctSlices
// Count the number of distinct slices (containing only unique numbers).


// Idea: Grow the slice until we encounter a duplicate, then we stop, count
//       the number of possible sub-slices, then apply the same algorithm 
//       starting at the duplicate node

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// role: 
unsigned helper(const vector<int>& A, unsigned& pos) {
  unsigned startPos = pos;
  unordered_map<int, unsigned> map;
  while (pos < A.size()) {
    int a = A[pos];
    if (map.count(a) > 0) {
      break;
    }
    map[a] = pos++;
  }
  unsigned N = pos - startPos;
  unsigned count = (1 + N) * N / 2;
  if (pos < A.size()) {
    count += pos - map[A[pos]] - 1;
    /*
    if (map[A[pos]] + 1 != pos) {
      count += pos - map[A[pos]] - 1;
    }
    */
    //pos = map[A[pos]] + 1;
  }
  return count;
}

int solution(int M, vector<int> &A) {
  unsigned count = 0;
  unsigned pos = 0;
  while (pos < A.size()) {
    count += helper(A, pos);
    if (count > 1e9) return 1e9;
  }
  return count;
}

int main() {
  vector<int> A {3, 4, 5, 5, 2};
  cout << solution(1, A) << endl;
  vector<int> B {1, 1, 2, 1, 1};
  cout << solution(1, B) << endl;
  vector<int> C {1, 1, 2, 3, 4, 1, 1};
  cout << solution(1, C) << endl;
}
