// Given an array with n objects colored red, white or blue,
// sort them so that objects of the same color are adjacent,
// with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's,
// then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with an one-pass algorithm using only constant space?

// Two-pass algorithm using constant space is easy

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int smaller = 0;
        int equal   = 0;
        int larger  = nums.size() - 1;
        int pivotValue = 1;
        while (equal <= larger) {
            int& n = nums[equal];
            // nums[equal] is the incoming unclassified element.
            if (n < pivotValue) {
                swap(n, nums[smaller]);
                ++smaller;
                ++equal;
            } else if (n == pivotValue) {
                ++equal;
            } else {    // n > pivotValue
                swap(n, nums[larger]);
                --larger;
            }
        }
    }
};
