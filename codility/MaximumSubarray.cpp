// Find the contiguous subarray within an array (containing at least one number)
// which has the largest sum.
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

// https://en.wikipedia.org/wiki/Maximum_subarray_problem

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxEndingHere = nums[0], maxSumSoFar = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            maxEndingHere = max(maxEndingHere + n, n);
            maxSumSoFar   = max(maxEndingHere, maxSumSoFar);
        }
        return maxSumSoFar;
    }
};
