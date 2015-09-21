// Given a positive integer n, find the least number of perfect square numbers
// (for example, 1, 4, 9, 16, ...) which sum to n.
// For example,
// given n = 12, return 3 because 12 = 4 + 4 + 4;
// given n = 13, return 2 because 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        int *x = new int[n + 1];
        x[0] = 0;
        for (int i = 1; i <= n; ++i) {
            x[i] = 1 + x[i - 1];
            for (int j = 2; j * j <= i; ++j) {
                x[i] = min(x[i], 1 + x[i - j * j]);
            }
        }
        return x[n];
    }
};
