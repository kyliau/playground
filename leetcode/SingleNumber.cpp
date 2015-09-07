// Given an array of integers, every element appears twice except for one.
// Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            i ^= n;
        }
        return i;
    }
};
