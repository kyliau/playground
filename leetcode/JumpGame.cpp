// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
// Each element in the array represents your maximum jump length at that
// position.
// Determine if you are able to reach the last index.
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

class Solution {
    bool canJump(vector<bool> *e, const vector<int>& nums, int pos) {
        int n = nums.size();
        if (pos >= n) {
            return false;
        }
        if (e->at(pos)) {
            return false;
        }
        int numspos = nums[pos];
        if (numspos >= n - pos - 1) {
            return true;
        }
        int d = min(numspos, n - pos -1);
        for (int i = d; i > 0; --i) {
            if (canJump(e, nums, pos + i)) {
                return true;
            }
        }
        (*e)[pos] = true;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<bool> explored(nums.size(), false);
        return canJump(&explored, nums, 0);
    }
};
