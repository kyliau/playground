// Given an array which consists of non-negative integers and an integer m,
// you can split the array into m non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these m subarrays.
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
// Examples:
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution1 {       // this doesn't work somehow
  private:
    int split(const vector<int>& nums, int l, int r, int m) {
        if (l >= r || m > r - l) {
            return -1;
        }
        assert(l < r);
        assert(0 < m);
        if (m == 1) {
            return nums[r - 1] - (l < 1 ? 0 : nums[l - 1]);
        }
        int val = std::max(split(nums, l, l + 1, m - 1),
                           split(nums, l + 1, r, m - 1));
        for (int i = 2; l + i < r; ++i) {
            int cand = std::max(split(nums, l, l + i, m - 1),
                                split(nums, l + i, r, m - 1));
            val = std::min(val, cand);
        }
        return val;
    }
  public:
    int splitArray(const vector<int>& nums, int m) {
        vector<int> v(nums.size());
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            v[i] = v[i - 1] + nums[i];
        }
        return split(v, 0, v.size(), m);
    }
};

class Solution {
  private:
    bool isPossible(const vector<int>& nums, int m, int target) {
        int sum = 0;
        for (int x : nums) {
            if (sum + x <= target) {
                sum += x;
            }
            else {
                sum = x;
                if (--m == 0) {
                    return false;
                }
            }
        }
        return true;
    }
  public:
    int splitArray(const vector<int>& nums, int m) {
        int lower = 0;  // the lower bound should be the max element in 'nums'
        int upper = 0;  // the upper bound should be the sum of the entire array
        for (int x : nums) {
            lower = std::max(lower, x);
            upper += x;
        }
        while (lower < upper) {
            int mid = lower + (upper - lower) / 2;
            if (isPossible(nums, m, mid)) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }
        return lower;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> nums;
        int         m;
        int         expected;
    } CASES[] = {
        {  1, {               1 }, 1,  1 },
        {  2, {            1, 2 }, 1,  3 },
        {  3, {            1, 2 }, 2,  2 },
        {  4, {         1, 2, 3 }, 1,  6 },
        {  5, {         1, 2, 3 }, 2,  3 },
        {  6, {         1, 2, 3 }, 3,  3 },
        {  7, {      1, 2, 3, 4 }, 1, 10 },
        {  8, {      1, 2, 3, 4 }, 2,  6 },
        {  9, {      1, 2, 3, 4 }, 3,  4 },
        { 10, {      1, 2, 3, 4 }, 4,  4 },
        { 11, { 10, 5, 13, 4, 8 }, 1, 40 },
        { 12, { 10, 5, 13, 4, 8 }, 2, 25 },
        { 13, { 10, 5, 13, 4, 8 }, 3, 15 },
        { 14, { 10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8 }, 8, 25 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto& nums     = CASES[i].nums;
        int   m        = CASES[i].m;
        int   expected = CASES[i].expected;
        cout << "Test case " << (n < 10 ? " " : "") << n << " ... ";
        Solution s;
        int result = s.splitArray(nums, m);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}