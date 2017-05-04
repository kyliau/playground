// Given an array of size n, find the majority element. The majority element is
// the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always
// exists in the array.

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        size_t n = nums.size();
        int *queue = new int[n];
        size_t size = 0;
        for (size_t i = 0; i < n; ++i) {
            queue[size++] = nums[i];
            if (size > 1 && queue[size - 1] != queue[size - 2]) {
                size -= 2;
            }
        }
        return queue[size - 1];
    }
};