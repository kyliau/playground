class Solution {
  public:
    vector<int> majorityElement(const vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 1;
        for (int n : nums) {
            if (n == candidate1) {
                ++count1;
            }
            else if (n == candidate2) {
                ++count2;
            }
            else if (count1 == 0) {
                candidate1 = n;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = n;
                count2 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }
        if (std::count(nums.begin(), nums.end(), candidate1) > n / 3) {
            result.emplace_back(candidate1);
        }
        if (std::count(nums.begin(), nums.end(), candidate2) > n / 3) {
            result.emplace_back(candidate2);
        }
        return result;
    }
};