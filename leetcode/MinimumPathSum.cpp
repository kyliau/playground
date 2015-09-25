// Given a m x n grid filled with non-negative numbers, find a path
// from top left to bottom right which minimizes the sum of all numbers
// along its path.
// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        
        for (int row = 1; row < m; ++row) {
            grid[row][0] += grid[row - 1][0];
        }
        
        for (int col = 1; col < n; ++col) {
            grid[0][col] += grid[0][col - 1];
            for (int row = 1; row < m; ++row) {
                grid[row][col] += min(grid[row - 1][col],
                                      grid[row][col -1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
