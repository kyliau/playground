// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(const vector<int>& heights) {
        if (3 > heights.size()) {
            return 0;
        }
        int area = 0;
        auto it = std::max_element(heights.begin(), heights.end());
        int tallest = it - heights.begin();
        int level = heights[0];
        for (int i = 1; i < tallest; ++i) {
            if (heights[i] < level) {
                area += level - heights[i];
            } else {
                level = heights[i];
            }
        }
        level = heights.back();
        for (int i = heights.size() - 2; i > tallest; --i) {
            if (heights[i] < level) {
                area += level - heights[i];
            } else {
                level = heights[i];
            }
        }
        return area;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> heights;
        int         expected;
    } CASES[] = {
        {  1, { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 },  6 },
        {  2, { 1, 1, 1                            },  0 },
        {  3, { 1, 2, 1                            },  0 },
        {  4, { 2, 1, 2                            },  1 },
        {  5, { 1                                  },  0 },
        {  6, { 1, 2, 3, 2, 1                      },  0 },
        {  7, { 3, 2, 1, 2, 3                      },  4 },
        {  8, { 5, 3, 2, 6, 1, 4                   },  8 },
        {  9, { 5, 4, 6, 2, 8, 1, 7                }, 11 },
        { 10, { 6, 2, 4, 3, 5                      },  6 },
        { 11, { 6, 2, 6, 3, 5                      },  6 },
        { 12, { 3, 2, 5, 3, 4, 2, 6                },  7 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int   n        = CASES[i].n;
        const auto& heights  = CASES[i].heights;
        const int   expected = CASES[i].expected;
        cout << "Test case " << n << "\t... ";
        Solution s;
        int result = s.trap(heights);
        if (result == expected) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")"
                 << endl;
        }
    }
    return 0;
}
