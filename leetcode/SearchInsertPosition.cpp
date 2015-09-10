// Given a sorted array and a target value, return the index
// if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = nums.size();
        int left = 0;
        while (count > 0) {
            int step = count / 2;
            int mid = left + step;
            if (nums[mid] < target) {
                left = mid + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return left;
        //auto it = lower_bound(nums.begin(), nums.end(), target);
        //return distance(nums.begin(), it);
    }
};
