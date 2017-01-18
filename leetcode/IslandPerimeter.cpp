// You are given a map in form of a two-dimensional integer grid where
// 1 represents land and 0 represents water. Grid cells are connected
// horizontally/vertically (not diagonally). The grid is completely surrounded
// by water, and there is exactly one island (i.e., one or more connected land
// cells). The island doesn't have "lakes" (water inside that isn't connected to
// the water around the island). One cell is a square with side length 1.
// The grid is rectangular, width and height don't exceed 100.
// Determine the perimeter of the island.

// Example:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Answer: 16

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {

public:
    using Grid = vector<vector<int>>;
    enum {
        WATER = 0,
        LAND  = 1,
    };
    int islandPerimeter(vector<vector<int>>& grid) {
        auto land = findLand(grid);
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int perimeter = 0;
        islandPerimeter(&perimeter, &visited, land.first, land.second, grid);
        return perimeter;
    }

private:
    using Point = pair<int, int>;
    Point findLand(const Grid& g) {
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (LAND == g[i][j]) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    }

    void islandPerimeter(int                  *perimeter,
                         vector<vector<bool>> *visited,
                         int                   i,
                         int                   j,
                         const Grid&           g) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[i].size() ||
            WATER == g[i][j]) {
            ++(*perimeter);
            return;
        }
        if ((*visited)[i][j]) {
            return;
        }
        (*visited)[i][j] = true;
        islandPerimeter(perimeter, visited, i + 1, j, g);
        islandPerimeter(perimeter, visited, i - 1, j, g);
        islandPerimeter(perimeter, visited, i, j + 1, g);
        islandPerimeter(perimeter, visited, i, j - 1, g);
    }
};

int main() {
    {
        Solution s;
        Solution::Grid g = { { 1 } };
        assert(4 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 0, 1, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
        };
        assert(16 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 0, 0, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
        };
        assert(8 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 1, 1 },
            { 1, 1 },
        };
        assert(8 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 1, 1 },
            { 0, 1 },
        };
        assert(8 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 0, 1 },
            { 0, 0 },
        };
        assert(4 == s.islandPerimeter(g));
    }
    {
        Solution s;
        Solution::Grid g = {
            { 0, 0 },
            { 0, 0 },
        };
        assert(0 == s.islandPerimeter(g));
    }
    return 0;
}