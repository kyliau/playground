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
        int width  = 1;
        int height = heights[i];
        for (int j = i + 1; j < heights.size() && heights[j] >= height; ++j) {
            ++width;
        }
        area = std::max(area, width * height);
    }
    for (int i = heights.size() - 1; i >= 0; --i) {
        int width = 1;
        int height = heights[i];
        for (int j = i - 1; j >= 0 && heights[j] >= height; --j) {
            ++width;
        }
        area = std::max(area, width * height);
    }
    return area;
}

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int width  = 0;
        int height = 0;
        int area   = 0;
        std::stack<int> lastWidth;
        for (int i = 0; i < heights.size(); ++i) {
            int h = heights[i];
            if (h == height) {
                ++width;
                //lastWidth.push(i);
            }
            else if (h > height) {
                cout << "h = " << h << ", height * (width + 1) = " << height * (width + 1) << endl;
                if (h > height * (width + 1)) {
                    height = h;
                    width  = 1;
                } else {
                    ++width;
                }
                lastWidth.push(i);
            }
            else {  // h < height
                int someNewWidth = 0;
                while (!lastWidth.empty() && heights[lastWidth.top()] >= h) {
                    someNewWidth = i - lastWidth.top();
                    lastWidth.pop();
                }
                if (width * height > someNewWidth * h) {
                    area = width * height;
                    width  = 0;
                    height = 0;
                }
                else {
                    width  = someNewWidth;
                    height = h;
                }
            }
        }
        area = std::max(area, width * height);
        width  = 0;
        height = 0;
        while(!lastWidth.empty()) {
            lastWidth.pop();
        }
        for (int i = heights.size() - 1; i >= 0; --i) {
            int h = heights[i];
            if (h == height) {
                ++width;
                //lastWidth.push(i);
            }
            else if (h > height) {
                if (h > height * (width + 1)) {
                    height = h;
                    width  = 1;
                } else {
                    ++width;
                }
                lastWidth.push(i);
            }
            else {  // h < height
                int someNewWidth = 0;
                while (!lastWidth.empty() && heights[lastWidth.top()] >= h) {
                    someNewWidth = lastWidth.top() - i;
                    lastWidth.pop();
                }
                if (width * height > someNewWidth * h) {
                    area = std::max(area, width * height);
                    width  = 0;
                    height = 0;
                }
                else {
                    width  = someNewWidth;
                    height = h;
                }
            }
        }
        return std::max(area, width * height);
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
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int n               = CASES[i].i;
        const auto& heights = CASES[i].heights;
        int expected        = CASES[i].area;
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