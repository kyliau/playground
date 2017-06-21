// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
// Each element in the array represents your maximum jump length at that
// position.
// Determine if you are able to reach the last index.
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

// TODO: The solution passed all test cases ...
//       But I believe there are some bugs

class Solution {
    bool canJump(vector<int>& nums, int pos) {
        int n = nums.size();
        if (pos >= n || nums[pos] == -1) {
            return false;
        }
        if (nums[pos] >= n - pos - 1) {
            return true;
        }
        // jump to the farthest location
        int p = pos + nums[pos];
        while (p > pos) {
            if (nums[p] != -1) {
                // visit the farthest position
                if (canJump(nums, p)) {
                    return true;
                } else {
                    // anything before p that is <= nums[p] + distance from p
                    // is also impossible
                    while(p > pos && nums[p - 1] <= nums[p] + 1) {
                        // TODO: need to mark p as -1
                        // and we need to check that p > pos
                        // Although these checks are not done, the program works
                        // why?!
                        --p;
                    }
                }
            }
            --p;
        }

        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
};

class Solution {
  public:
    bool canJump(const vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reach) {
                return false;
            }
            reach = std::max(i + nums[i], reach);
        }
        return true;
    }
};