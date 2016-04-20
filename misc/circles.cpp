#include <iostream>
#include <vector>
using namespace std;

struct node_t {
  int val;
  char type;
  bool operator== (const node_t& b) {
    return val == b.val && type == b.type;
  }
};

struct {
  bool operator() (const node_t& a, const node_t& b) {
    if (a.val == b.val && a.type == 's') {
      return true;
    }
    return a.val < b.val;
  }
} comp;

int solution(vector<int> &A) {
  vector<node_t> B;
  for (int i = 0; i < (int)A.size(); ++i) {
    node_t start = { i - A[i], 's' };
    node_t end = { i + A[i], 'e' };
    B.push_back(start);
    B.push_back(end);
  }
  sort(B.begin(), B.end(), comp);
  int result = 0;
  int start = 0;
  while (i < B.size()) {
    node_t prev = B[i++];
    if (start > 0 && prev.type == 's') {
      result += start;
    }
    start = prev.type == 's' ? start + 1 : start - 1;
  }
  return result;
}

int main() {
  vector<int> A { 1, 5, 2, 1, 4, 0 };
  cout << solution(A) << endl;
  vector<int> B { 1, 1, 1, 1, 1, 1 };
  cout << solution(B) << endl;
  vector<int> C { 0, 0, 0, 0, 0, 0 };
  cout << solution(C) << endl;
  return 0;
}
