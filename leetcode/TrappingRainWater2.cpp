// Given an m x n matrix of positive integers representing the height of each
// unit cell in a 2D elevation map, compute the volume of water it is able to
// trap after raining.
// Note:
// Both m and n are less than 110.
// The height of each unit cell is greater than 0 and is less than 20,000.
// Example:
// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]
// Return 4.

#include <vector>
#include <assert.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int trapRainWater(const vector<vector<int>>& heightMap) {
        return 0;
    }
};

int main() {
    const struct {
        int                 n;
        vector<vector<int>> heights;
        int                 expected;
    } CASES[] = {
        {
            1,
            {
                { 1, 4, 3, 1, 3, 2 },
                { 3, 2, 1, 3, 2, 4 },
                { 2, 3, 3, 2, 3, 1 },
            },
            4
        }
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int   n        = CASES[i].n;
        const auto& heights  = CASES[i].heights;
        const int   expected = CASES[i].expected;
        cout << "Test case " << n << "\t... ";
        Solution s;
        int result = s.trapRainWater(heights);
        if (result == expected) {
            cout << "PASS" << endl;
        }
        else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")"
                 << endl;
        }
    }
    return 0;
}