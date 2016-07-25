// Given a set of distinct integers, nums, return all possible subsets.
// Note: The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = 1 << nums.size();
        vector<vector<int>> result;
        result.reserve(size);
        if (nums.empty()) {
            return result;
        }
        result.emplace_back();
        result.back().emplace_back(nums[0]);
        result.emplace_back();
        for (int i = 1; i < nums.size(); ++i) {
            int n = result.size();
            for (int j = 0; j < n; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
            }
        }
        return result;
    }
};
