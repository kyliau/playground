#include <iostream>
#include <vector>
using namespace std;


// Given an array of size N that contains [1..N+1], find the missing integer
// runtime: O(n)
unsigned find_one_missing(const vector<int>& A) {
  unsigned sum = 0, N = A.size();
  for (int a : A) {
    sum += a;
  }
  return (1 + N + 1) * (N + 1) / 2 - sum;
}


// Given an array of size N that contains [1..N+2], find the two missing
// integers
// runtime: O(n)

struct missing_t {
  int x;
  int y;
};

missing_t find_two_missing(const vector<int>& A) {
  unsigned sum = 0, N = A.size();
  for (int a : A) {
    sum += a;
  }
  unsigned correct_sum = (1 + N + 2) * (N + 2) / 2;
  unsigned diff = correct_sum - sum;
  unsigned mid = diff / 2;
  sum = 0;
  for (int a : A) {
    if (a <= mid) {
      sum += a;
    }
  }
  missing_t missing;
  missing.x = (1 + mid) * mid / 2 - sum;
  missing.y = diff - missing.x;
  return missing;
}


int main() {
  vector<int> A {6,1,5,10,2,9,3,4,8};
  cout << find_one_missing(A) << endl;
  vector<int> B {6,5,10,2,9,7,3,4,8};
  missing_t b = find_two_missing(B);
  cout << b.x << '\t' << b.y << endl;
  vector<int> C {6,5,1,4,2,3,11,10,12,9};
  missing_t c = find_two_missing(C);
  cout << c.x << '\t' << c.y << endl;
}
