// Given an array and a value, remove all instances of that value in place and
// return the new length.
// Do not allocate extra space for another array, you must do this in place with
// constant memory.
// The order of elements can be changed. It doesn't matter what you leave beyond
// the new length.
// Example:
// Given input array nums = [3,2,2,3], val = 3
// Your function should return length = 2, with the first two elements of nums
// being 2.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int x : nums) {
            if (x != val) {
                std::swap(x, nums[i++]);
            }
        }
        return i;
    }
};

int main() {
    struct {
        int         n;
        vector<int> nums;
        int         remove;
        vector<int> expected;
    } CASES[] = {
        { 1, { 2, 3, 2, 3, 2, 2, 3, 4, 5, 2 }, 2, { 3, 3, 3, 4, 5 } },
        { 2, {                1, 2, 3, 4, 5 }, 0, { 1, 2, 3, 4, 5 } },
        { 3, {                      1, 2, 3 }, 2, {          1, 3 } },
        { 4, {                   1, 1, 1, 1 }, 1, {               } },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int         n        = CASES[i].n;
        auto&       nums     = CASES[i].nums;
        int         remove   = CASES[i].remove;
        const auto& expected = CASES[i].expected;
        Solution s;
        cout << "Test case " << n << " ... ";
        int length = s.removeElement(nums, remove);
        vector<int> result(nums.begin(), nums.begin() + length);
        if (result != expected) {
            cout << "FAIL";
        }
        else {
            cout << "PASS";
        }
        cout << endl;
    }
    return 0;
}