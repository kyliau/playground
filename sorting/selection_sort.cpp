#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// iteratively
void selection_sort_iterative(vector<int>& A) {
  int N = A.size();
  for (int i = 0; i < N; ++i) {
    int min_index = i;
    for (int j = i + 1; j < N; ++j) {
      if (A[j] < A[min_index]) {
        min_index = j;
      }
    }
    swap(A[i], A[min_index]);
  }
}

// recursively - just for fun
void selection_sort_recursive(vector<int>& A, int left) {
  int min_index = left, N = A.size();
  if (left >= N) return;
  for (int i = left + 1; i < N; ++i) {
    if (A[i] < A[min_index]) {
      min_index = i;
    }
  }
  swap(A[left], A[min_index]);
  selection_sort_recursive(A, left + 1);
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
    vector<int> B(A);
    
    cout << "Iterative result: ";
    selection_sort_iterative(A);
    for (const int& a : A) {
      cout << a << " ";
    }
    cout << endl;
    
    cout << "Recursive result: ";
    selection_sort_recursive(B, 0);
    for (const int& b : B) {
      cout << b << " ";
    }
    cout << endl;
  }
  return 0;
}
