// Given an array nums, we call (i, j) an important reverse pair if i < j and
// nums[i] > 2 * nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example 1:
// Input  : [ 1, 3, 2, 3, 1 ]
// Output : 2
//
// Example 2:
// Input  : [ 2, 4, 3, 5, 1 ]
// Output : 3
//
// Note:
// - The length of the given array will not exceed 50,000.
// - All the numbers in the input array are in the range of 32-bit integer.

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
  private:
    int reversePairs(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int m = l + (r - l) / 2;
        int count = reversePairs(nums, l, m) + reversePairs(nums, m + 1, r);

        int i = l;          // index for left subarray
        int j = m + 1;      // index for right subarray
        int k = 0;          // index for insertion position into 'merge'
        int n = r - l + 1;  // size of the merge
        int p = m + 1;      // keep track of important reverse pairs
        vector<int> merge(n);

        while (k < n) {
            if (i == m + 1) {           // reach end of left subarray
                merge[k++] = nums[j++];
            }
            else if (j == r + 1) {      // reach end of right subarray
                while (p <= r && nums[i] > 2L * nums[p]) {
                    ++p;
                }
                count += p - m - 1;
                merge[k++] = nums[i++];
            }
            else if (nums[i] <= nums[j]) {
                while (p <= r && nums[i] > 2L * nums[p]) {
                    ++p;
                }
                count += p - m - 1;
                merge[k++] = nums[i++];
            }
            else {
                merge[k++] = nums[j++];
            }
        }

        std::copy(merge.begin(), merge.end(), nums.begin() + l);
        return count;
    }
  public:
    int reversePairs(vector<int>& nums) {
        return reversePairs(nums, 0, nums.size() - 1);
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v;
        int         e;
    } CASES[] = {
        { 1, { 4, -1, 0, 55, 9, -3, 8, 1, 99, -154, 4, 6, 2, 25, 3 }, 39 },
        { 2, { 7, 8, 9, 1, 2, 3 }, 9 },
        { 3, { 1, 3, 2, 3, 1 }, 2 },
        { 4, { 2, 4, 3, 5, 1 }, 3 },
        { 5, { 1, 2, 3, 4, 5 }, 0 },
        { 6, { 10, 1 }, 1 },
        { 7, { 10, 1, 3, 5 }, 2 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int  n = CASES[i].n;
        auto v = CASES[i].v;
        int  e = CASES[i].e;
        Solution s;
        cout << "Test case " << n << " ... ";
        int result = s.reversePairs(v);
        if (result == e) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << e << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}