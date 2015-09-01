// Given an array of integers and an integer k,
// find out whether there are two distinct indices
// i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.

// Easy but (relatively) slow solution
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map an integer to its last seen index
        unordered_map<int, size_t> myMap;
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            auto it = myMap.find(n);
            if (it != myMap.end() && i - it->second <= k) {
                return true;
            }
            myMap[n] = i;
        }
        return false;
    }
};

// Slightly faster solution ;)
