// TODO: WIP

// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
// Each element in the array represents your maximum jump length at that
// position.
// Determine if you are able to reach the last index.
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

class Solution {
    bool canJump(vector<int>& nums, int pos) {
        int n = nums.size();
        if (pos >= n || nums[pos] == -1) {
            return false;
        }
        if (nums[pos] >= n - pos - 1) {
            return true;
        }
        int last = -1;
        for (int i = nums[pos]; i > 0; --i) {
            if (nums[pos + i] == last + 1) {
                nums[pos + i] = -1;
            } else if (canJump(nums, pos + i)) {
                return true;
            }
            last = nums[pos + i];
        }
        nums[pos] = -1;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
};
