#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int>& A) {
  int N = A.size();
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < i ; ++j) {
      if (A[j] > A[j+1]) {
        swap(A[j], A[j+1]);
        j++;
      }
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
