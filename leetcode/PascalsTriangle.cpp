// Given numRows, generate the first numRows of Pascal's triangle.
// For example, given numRows = 5,
// Return
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for (int row = 0; row < numRows; ++row) {
            v.emplace_back();
            for (int i = 0; i < row + 1; ++i) {
                int val = (i == 0 || i == row ? 1 : v[row - 1][i - 1] + v[row - 1][i]); 
                v.back().emplace_back(val);
            }
        }
        return v;
    }
};
