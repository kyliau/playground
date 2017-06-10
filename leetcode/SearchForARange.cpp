class Solution {
  public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        auto left = std::lower_bound(nums.begin(), nums.end(), target);
        if (left == nums.end() || *left != target) {
            return { -1, -1 };
        }
        auto right = std::upper_bound(left, nums.end(), target);
        return { left - nums.begin(), right - nums.begin() - 1 };
    }
};