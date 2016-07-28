// Given a non-empty array of integers, return the k most frequent elements.
// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n),
// where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(k);
        unordered_map<int, int> numMap;
        numMap.reserve(nums.size());
        int maxCount = 0;
        for (int n : nums) {
            maxCount = std::max(maxCount, ++numMap[n]);
        }
        vector<vector<int>> buckets(maxCount);
        for (const auto& p : numMap) {
            buckets[p.second - 1].emplace_back(p.first);
        }
        auto it = buckets.rbegin();
        while (it != buckets.rend() && k > 0) {
            if (it->empty()) {
                ++it;
            } else {
                result.emplace_back(it->back());
                it->pop_back();
                --k;
            }
        }
        return result;
    }
};
