// Given a sorted integer array without duplicates,
// return the summary of its ranges.
// For example, given [0,1,2,4,5,7],
// return ["0->2","4->5","7"].

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if (nums.empty()) {
            return v;
        }
        int num  = nums[0];
        string s = to_string(num);
        for (size_t i = 1; i < nums.size(); ++i) {
            // need to take care of integer overflow!
            int64_t curr = nums[i];
            int64_t prev = nums[i - 1];
            if (curr - prev > 1) {
                if (prev != num) {
                    s += "->";
                    s += to_string(prev);
                }
                v.emplace_back(s);
                s   = to_string(curr);
                num = curr;
            }
        }
        if (nums.back() != num) {
            s += "->";
            s += to_string(nums.back());
        }
        v.emplace_back(s);
        return v;
    }
};
