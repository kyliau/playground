// Given a matrix of m x n elements (m rows, n columns),
// return all elements of the matrix in spiral order.
// For example,
// Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
private:
    void peelMatrix(vector<int>                *r,
                    const vector<vector<int>>&  m,
                    int                         rStart,
                    int                         rEnd,
                    int                         cStart,
                    int                         cEnd) {
        if (rStart >= rEnd || cStart >= cEnd) {
            return;
        }
        // Print top row
        for (int i = cStart; i < cEnd; ++i) {
            r->emplace_back(m[rStart][i]);
        }
        // Print right column
        for (int i = rStart + 1; i < rEnd; ++i) {
            r->emplace_back(m[i][cEnd-1]);
        }
        if (rEnd - 1 > rStart) {
            // Print bottom row
            for (int i = cEnd - 2; i >= cStart; --i) {
                r->emplace_back(m[rEnd-1][i]);    
            }
        }
        if (cEnd - 1 > cStart) {
            // Print left column
            for (int i = rEnd - 2; i > rStart; --i) {
                r->emplace_back(m[i][cStart]);
            }
        }
        peelMatrix(r, m, ++rStart, --rEnd, ++cStart, --cEnd);
    }
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        result.reserve(m * n);
        peelMatrix(&result, matrix, 0, m, 0, n);
        return result;
    }
};
