class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int result = n + 1;
        while (j < n) {
            sum += nums[j++];
            while (sum >= s) {
                result = std::min(result, j - i);
                sum -= nums[i++];
            }
        }
        return result == n + 1 ? 0 : result;
    }
};