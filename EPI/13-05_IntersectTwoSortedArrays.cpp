#include <iostream>
#include <vector>
using namespaces std;

// EPI Solution
vector<int> intersect_arrs3(const vector<int>& A, const vector<int>& B) {
  vector<int> intersect;
  int i = 0, j = 0;
  while (i < A.size() && j < B.size()) {
    if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1])) {
      intersect.emplace_back(A[i]);
      ++i, ++j;
    } else if (A[i] < B[j]) {
      ++i;
    } else {  // A[i] > B[j].
      ++j;
    }
  }
  return intersect;
}

int main() {
  vector<int> A {1, 2, 2};
  vector<int> B {1, 2, 2};
  for (int i : intersect_arrs3(A, B)) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
