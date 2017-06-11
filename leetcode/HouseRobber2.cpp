class Solution {
  private:
    int rob(const vector<int>& nums, int left, int right) {
        int include = 0;
        int exclude = 0;
        while (left < right) {
            int temp = exclude;
            exclude = std::max(exclude, include);
            include = temp + nums[left];
            ++left;
        }
        return std::max(include, exclude);
    }
  public:
    int rob(const vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return std::max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
};