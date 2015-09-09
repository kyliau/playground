// Given a 2d grid map of '1's (land) and '0's (water),
// count the number of islands.
// An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
// Example 1:
// 11110
// 11010
// 11000
// 00000
// Answer: 1
// Example 2:
// 11000
// 11000
// 00100
// 00011
// Answer: 3

class Solution {
public:
    enum {
        WATER   = '0',
        LAND    = '1',
        VISITED = 'V'
    };
    void exploreIsland(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size()      ||
            col < 0 || col >= grid[row].size() ||
            grid[row][col] != LAND) {
            return;
        }
        grid[row][col] = VISITED;
        exploreIsland(grid, row, col - 1);
        exploreIsland(grid, row, col + 1);
        exploreIsland(grid, row - 1, col);
        exploreIsland(grid, row + 1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == LAND) {
                    exploreIsland(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
