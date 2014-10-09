
// Lesson 12 - Binary Search Algorithm
// NailingPlanks
// Count the minimum number of nails that allow a series of planks to be nailed.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <algorithm>

struct plank_t {
    int start;
    int end;
    bool operator< (const plank_t& other) const {
        return start < other.start;
    }
};

// answer the question:
// can I nail all planks using the given nails?
bool check2(const vector<plank_t>& A, const vector<int>& nails) {
    int N = A.size();
    auto it = nails.begin();
    for (int i = 0; i < N; i++) {
        if (*it >= A[i].start && *it <= A[i].end) continue;
        while (it != nails.end() && *it < A[i].start) {
            it++;
        }
        if (it == nails.end() || *it > A[i].end) return false;
    }
    return true;
}

// answer the question: 
// can I nail all planks using exactly X (sequential) nails?
bool check(const vector<plank_t>& A, const vector<int>& C, int X) {
    //cout << "X = " << X;
    vector<int> nails(C.begin(), C.begin() + X);
    sort(nails.begin(), nails.end());
    if (check2(A, nails)) return true;
    return false;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N = A.size();
    vector<plank_t> plank(N);
    for (int i = 0; i < N; i++) {
        plank[i] = {A[i], B[i]};
    }
    sort(plank.begin(), plank.end());
    int M = C.size();
    int lbound = 1;
    int ubound = M;
    while (lbound <= ubound) {
        int mid = 0.5 * (lbound + ubound);
        if (check(plank, C, mid)) {
            //cout << " OK" << endl;
            ubound = mid - 1;
        } else {
            //cout << " NOT OK" << endl;
            lbound = mid + 1;
        }
    }
    return (lbound >= 1 && lbound <= M) ? lbound : -1;
}

int main() {
  vector<int> A {1, 1, 1};
  vector<int> B {1, 2, 3};
  vector<int> C {1, 1, 1};
  cout << solution(A, B, C) << endl;
}
