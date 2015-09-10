// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?
// Note: m and n will be at most 100.

class Solution {
public:
    int nChooseK(int n, int k) {
        int64_t result = 1;
        k = min(k, n - k);
        for (int i = 0; i < k; ++i) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
    int uniquePaths(int m, int n) {
        return nChooseK(m + n - 2, m - 1);
    }
};
