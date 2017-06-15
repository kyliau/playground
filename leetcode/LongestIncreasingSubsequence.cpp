// O(n^2) solution here:
// https://www.youtube.com/watch?v=1ivFSH0ijOM

// This solution is O(n log n)
class Solution {
  public:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> v;
        for (int x : nums) {
            auto it = std::lower_bound(v.begin(), v.end(), x);
            if (it == v.end()) {
                v.emplace_back(x);
            }
            else {
                *it = x;
            }
        }
        return v.size();
    }
};