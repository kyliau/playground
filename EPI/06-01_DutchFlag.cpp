#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// EPI Problem 6.1 pg 52
// Partition the array into [< pivot .. == pivot .. > pivot] 

void rearrange(vector<int>& A, int i) {
  int pivot = A[i];
  int left = 0, right = A.size() - 1;
  int current = 0;
  while (current <= right) {
    int& a = A[current];
    if (a < pivot) {
      swap(a, A[left++]);
      current++;
    } else if (a > pivot) {
      swap(a, A[right--]);
    } else {
      current++;
    }
  }
}

// EPI solution
void dutch_flag_partition(vector<int>& A, int pivot_index) {
  int pivot = A[pivot_index];
  int smaller = 0, equal = 0, larger = A.size() - 1;
  while (equal <= larger) {
    if (A[equal] < pivot) {
      swap(A[smaller++], A[equal++]);
    } else if (A[equal] == pivot) {
      ++equal;
    } else {
      swap(A[equal], A[larger--]);
    }
  }
}

int main() {
  while (1) {
    cout << "Enter numbers: ";
    vector<int> A;
    int x;
    while (cin >> x) {
      A.push_back(x);
    }
    cin.clear();
    cin.ignore(200, '\n');
    cout << "Enter index: ";
    int index;
    cin >> index;
    cout << "Pivot is " << A[index] << endl;
    rearrange(A, index);
    for (int a : A) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}

        

