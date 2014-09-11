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
    return a.val < b.val;
  }
} comp;

int solution(vector<int> &A) {
  vector<node_t> B;
  for (int i = 0; i < A.size(); ++i) {
    node_t start = { i - A[i], 's' };
    node_t end = { i + A[i], 'e' };
    B.push_back(start);
    B.push_back(end);
  }
  sort(B.begin(), B.end(), comp);
  for (node_t& n : B) {
    cout << n.val << " " << n.type << endl;
  }
  int count = 0;
  int i = 0;
  int result = 0;
  while (i < B.size()) {
    node_t prev = B[i++];
    int temp = prev.type == 's' ? 1 : -1;
    while (i < B.size() && B[i] == prev) {
      temp = temp > 0 ? temp + 1 : temp - 1;
      i++;
    }
    count += temp;
    result += count;
    cout << "temp = " << temp << ", count = " << count << ", result = " << result << endl;
  }
  return result / 2;
}

int main() {
  vector<int> A { 1, 5, 2, 1, 4, 0 };
  cout << solution(A) << endl;
  vector<int> B { 1, 1, 1, 1, 1, 1 };
  cout << solution(B) << endl;
  return 0;
}
