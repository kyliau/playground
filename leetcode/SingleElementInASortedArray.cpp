// Given a sorted array consisting of only integers where every element appears
// twice except for one element which appears once.
// Find this single element that appears only once.
//
// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10
// Note: Your solution should run in O(log n) time and O(1) space.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int singleNonDuplicate(const vector<int>& nums) {
        int left  = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    left = mid + 2;
                }
                else {
                    right = mid;
                }
            }
            else {
                if (nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v;
        int         expected;
    } CASES[] = {
        { 1, { 1 }, 1 },
        { 2, { 1, 2, 2 }, 1 },
        { 3, { 1, 1, 2 }, 2 },
        { 4, { 1, 2, 2, 3, 3 }, 1 },
        { 5, { 1, 1, 2, 3, 3 }, 2 },
        { 6, { 1, 1, 2, 2, 3 }, 3 },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int n = CASES[i].n;
        auto& v = CASES[i].v;
        int expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution s;
        int result = s.singleNonDuplicate(v);
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