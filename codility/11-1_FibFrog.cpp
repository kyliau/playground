
// Lesson 11 - Fibonacci Numbers
// FibFrog
// Count the minimum number of jumps required for a frog to get to the 
// other side of a river.

#include <queue>

struct leaf_t {
  int val;  // val is either 0 or 1
  bool visited;
  int hops_away;
};

int helper(int N, vector<leaf_t>& A, const vector<int>& fib) {
  
  // invariant: all leaves in the queue must already be visited
  queue<int> q;
  q.push(-1);
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (int f : fib) {
        int next_index = current + f;
        if (next_index > current && next_index <= N) {
          leaf_t& next_leaf = A[next_index];
          if (next_leaf.val && !next_leaf.visited) {
              next_leaf.visited = true;
              next_leaf.hops_away = (current == -1) ? 1 : A[current].hops_away + 1;
              if (next_index == N) return next_leaf.hops_away;
              q.push(next_index);
          }
        }
    }
  }

  return -1;
}


int solution(vector<int> &A) {
  
  int N = A.size();
  vector<int> fib {0, 1};
  while (fib.back() < N + 2) {
    auto it = fib.end() - 1;
    fib.push_back(*it + *(it - 1));
  }

  vector<leaf_t> leaves(N + 1);
  for (int i = 0; i < N; ++i) {
      leaves[i] = {A[i], false, -1};
  }
  leaves[N] = {1, false, -1};
  
  return helper(N, leaves, fib);

}


int main() {
  vector<int> A {0, 0, 1, 0, 1};
  cout << solution(A) << endl;
  return 0;
}
