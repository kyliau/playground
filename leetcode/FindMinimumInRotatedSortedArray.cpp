// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// You may assume no duplicate exists in the array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int last = nums.back();
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + 0.5 * (right - left);
            if (nums[mid] <= last) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
