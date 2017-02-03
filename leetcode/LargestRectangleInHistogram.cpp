// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include <algorithm>

using namespace std;

int oracle(const vector<int>& heights) {
    int area = 0;
    for (int i = 0; i < heights.size(); ++i) {
        int height = heights[i];
        for (int j = i; j < heights.size(); ++j) {
            height = std::min(height, heights[j]);
            area = std::max(area, height * (j - i + 1));
        }
    }
    return area;
}

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int area = 0;
        std::stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            int h = heights[i];
            while (!s.empty() && h < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                area = std::max(area, height * width);
            }
            s.push(i);
        }
        while (!s.empty()) {
            int index = s.top();
            int h     = heights[index];
            s.pop();
            while (!s.empty() && h >= heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width  = s.empty() ? index + 1 : index - s.top();
                area = std::max(area, height * width);
            }
            int width = s.empty() ? 1 : index - s.top();
            area = std::max(area, h * width);
        }
        return area;
    }
};

int main() {
    const struct {
        int         i;
        vector<int> heights;
        int         area;
    } CASES[] = {
        {  1, {  2,  1,  5,  6,  2,  3 }, 10 },
        {  2, {  1,  2,  3,  4,  5,  6 }, 12 },
        {  3, {  6,  5,  4,  3,  2,  1 }, 12 },
        {  4, {  1,  1,  1,  1,  1,  1 },  6 },
        {  5, {  1,  1,  1,  0,  1,  1 },  3 },
        {  6, {  1,  2, 10, 12,  2,  1 }, 20 },
        {  7, {  2,  8,  7,  6,  5,  4 }, 20 },
        {  8, {  4,  9,  8,  1         }, 16 },
        {  9, {  5,  5,  9,  8,  1     }, 20 },
        { 10, {  1,  5,  5,  9,  8,  1 }, 20 },
        { 11, {  1,  1,  4             },  4 },
        { 12, {  2,  4,  4             },  8 },
        { 13, {  1,  2,  1             },  3 },
        { 14, {  1,  2,  3             },  4 },
        { 15, {  1,  0,  1             },  1 },
        { 16, {  1,  4,  3             },  6 },
        { 17, {  1,  4,  3, 1, 1, 1, 1 },  7 },
        { 18, {  5                     },  5 },
        { 19, {  1,  1,  2, 1          },  4 },
        { 20, {  1,  1                 },  2 },
        { 21, {  1,  1,  1             },  3 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int n         = CASES[i].i;
        const auto& heights = CASES[i].heights;
        const int expected  = CASES[i].area;
        assert(expected == oracle(heights));
        Solution s;
        int area = s.largestRectangleArea(heights);
        cout << "Test case " << n << "\t... ";
        if (area == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (expected " << expected << " but got " << area << ")";
        }
        cout << endl;
    }
    return 0;
}