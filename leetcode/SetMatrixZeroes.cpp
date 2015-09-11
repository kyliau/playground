// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.emplace(i);
                    cols.emplace(j);
                }
            }
        }
        for (int r : rows) {
            for (size_t col = 0; col < matrix[r].size(); ++col) {
                matrix[r][col] = 0;
            }
        }
        for (int c : cols) {
            for (size_t row = 0; row < matrix.size(); ++row) {
                matrix[row][c] = 0;
            }
        }
    }
};
