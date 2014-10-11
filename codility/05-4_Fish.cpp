
// Lesson 5 - Stacks and Queues
// Fish
// N voracious fish are moving along a river. 
// Calculate how many fish are alive.

#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    enum direction { UPSTREAM, DOWNSTREAM };
    struct fish_t { int size; int dir; };
    stack<fish_t> s;
    s.push({A[0], B[0]});
    int N = A.size();
    for (int i = 1; i < N; ++i) {
        fish_t& fish = s.top();
        if (fish.dir == DOWNSTREAM && B[i] == UPSTREAM) {
            if (fish.size > A[i]) continue;
            while (!s.empty() && s.top().dir == DOWNSTREAM && s.top().size < A[i]) {
                s.pop();
            }
            if (s.empty() || s.top().dir == UPSTREAM || A[i] > s.top().size) {
                s.push({A[i], B[i]});
            }
        } else {
            s.push({A[i], B[i]});
        }
    }
    return s.size();
}
