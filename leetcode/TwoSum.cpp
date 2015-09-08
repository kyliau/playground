// Given an array of integers, find two numbers such that
// they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that
// they add up to the target, where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            auto it = mymap.find(target - n);
            if (it != mymap.end()) {
                v.emplace_back(it->second + 1);
                v.emplace_back(i + 1);
                break;
            }
            mymap[n] = i;
        }
        return v;
    }
};
