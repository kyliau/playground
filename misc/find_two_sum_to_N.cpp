#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

// Given an array of ints and an integer N, return 1 if there exists 
// two numbers in the array that sum to N.
// return 0 if no such numbers exist
// runtime: O(n)


int find_two_sum_to_N(const vector<int>& A, int M) {
  cout << "\nFind two numbers that sum to " << M << endl;
  unordered_set<int> set;
  for (int a : A) {
    if (set.count(M-a) > 0) {
      cout << "The two numbers are " << a << " and " << M - a << endl;
      return 1;
    }
    set.insert(a);
  }
  cout << "No such numbers exist" << endl;
  return 0;
}

int main() {
  vector<int> A {1,2,3,4,5,6,7,8,9,10,-1};
  find_two_sum_to_N(A, 12);
  find_two_sum_to_N(A, 20);
  find_two_sum_to_N(A, 9);
  find_two_sum_to_N(A, -1);
  find_two_sum_to_N(A, 19);
  find_two_sum_to_N(A, 2);
  find_two_sum_to_N(A, 0);
  return 0;
}
