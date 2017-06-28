class Solution {
  public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (target == matrix[row][col]) {
                return true;
            }
            else if (target < matrix[row][col]) {
                --col;
            }
            else {
                ++row;
            }
        }
        return false;
    }
};