// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
// find the one that is missing from the array.
// For example,
// Given nums = [0, 1, 3] return 2.
// Note:
// Your algorithm should run in linear runtime complexity.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint64_t n     = nums.size();
        uint64_t sum   = n * (n + 1) / 2;
        uint64_t total = 0;
        for (int n : nums) {
            total += n;
        }
        return sum - total;
    }
};
