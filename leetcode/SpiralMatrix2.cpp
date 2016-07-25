// Given an integer n, generate a square matrix filled with
// elements from 1 to n^2 in spiral order.
// For example,
// Given n = 3,
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
private:
    void writeMatrix(int&                 x,
                     vector<vector<int>>& v,
                     int                  rBegin,
                     int                  rEnd,
                     int                  cBegin,
                     int                  cEnd) {
        if (rBegin >= rEnd || cBegin >= cEnd) {
            return;
        }
        for (int i = cBegin; i < cEnd; ++i) {
            v[rBegin][i] = x++;
        }
        for (int i = rBegin + 1; i < rEnd; ++i) {
            v[i][cEnd-1] = x++;
        }
        for (int i = cEnd - 2; i >= cBegin; --i) {
            v[rEnd-1][i] = x++;
        }
        for (int i = rEnd - 2; i > rBegin; --i) {
            v[i][cBegin] = x++;
        }
        writeMatrix(x, v, ++rBegin, --rEnd, ++cBegin, --cEnd);
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i].resize(n);
        }
        int count = 1;
        writeMatrix(count, v, 0, n, 0, n);
        return v;
    }
};
