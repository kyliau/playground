// Given two integers n and k, return all possible combinations
// of k numbers out of 1 ... n.
// For example,
// If n = 4 and k = 2, a solution is:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
private:
    void fillItWithX(vector<int>&         v,
                     vector<vector<int>>& r,
                     int                  x,
                     int                  n,
                     int                  k) {
        if (x > n || v.size() == k) {
            return;
        }
        v.emplace_back(x);
        if (v.size() == k) {
            r.emplace_back(v);
        } else {
            fillItWithX(v, r, x + 1, n, k);
        }
        v.pop_back();
        fillItWithX(v, r, x + 1, n, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> r;
        vector<int> v;
        v.reserve(k);
        fillItWithX(v, r, 1, n, k);
        return r;
    }
};
