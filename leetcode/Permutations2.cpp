class Solution {
  public:
    void permute(vector<int> nums, int i, vector<vector<int>>& res) {
        if (i == nums.size() - 1) {
            res.emplace_back(nums);
            return;
        }
        permute(nums, i + 1, res);
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                swap(nums[i], nums[j]);
                permute(nums, i + 1, res);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        permute(nums, 0, res);
        return res;
    }
};