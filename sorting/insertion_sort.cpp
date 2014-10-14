#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>& A) {
  int N = A.size();
  for (int i = 1; i < N; ++i) {
    int j = i;
    // INVARIANT: A[0..j-1] is sorted
    while (j >= 1 && A[j] < A[j-1]) {
      swap(A[j], A[j-1]);
      --j;
    }
  }
}

int main() {
  while(1) {
    int x;
    vector<int> A;
    while (cin >> x) {
      A.emplace_back(x);
    }
    cin.clear();
    cin.ignore(200, '\n');
    insertion_sort(A);
    for (const int& a : A) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}
