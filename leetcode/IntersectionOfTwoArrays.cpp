// Given two arrays, write a function to compute their intersection.
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// Note:
// Each element in the result must be unique.
// The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> result;
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                if (result.empty() || nums1[i] != result.back()) {
                    result.emplace_back(nums1[i]);    
                }
                ++i;
                ++j;
            }
        }
        return result;
    }
};
