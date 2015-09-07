// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> v(n + 1, 1);
        for (int k = 0; k < n; ++k) {
            uint64_t nCk= (uint64_t)v[k] * (n - k) / (k + 1);
            v[k + 1] = nCk;
        }
        return v;
    }
};
