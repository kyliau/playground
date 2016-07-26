// Write an efficient algorithm that searches for a value
// in an m x n matrix. This matrix has the following properties:
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer
//    of the previous row.
// For example,
// Consider the following matrix:
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
private:
    bool binarySearch(const vector<int>& v, int target) {
        int l = 0;
        int r = v.size();
        while (l < r) {
            int m = l + 0.5 * (r - l);
            int c = v[m];
            if (c == target) {
                return true;
            }
            if (c > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) {
            return false;
        }
        int l = 0;
        int r = m;
        while (l < r) {
            int m = l + 0.5 * (r - l);
            if (target < matrix[m][0]) {
                r = m;
            } else if (target > matrix[m][n-1]) {
                l = m + 1;
            } else {
                return binarySearch(matrix[m], target);
            }
        }
        return false;
    }
};
