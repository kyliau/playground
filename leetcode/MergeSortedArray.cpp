// Given two sorted integer arrays nums1 and nums2,
// merge nums2 into nums1 as one sorted array.
// Note:
// You may assume that nums1 has enough space (size that is
// greater or equal to m + n) to hold additional elements from nums2.
// The number of elements initialized in nums1 and nums2 are m and n respectively.

// Question: I am not sure if an in place merge is viable

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(n + m, 0);
        int i = 0, j = 0, k = 0;
        while (i < m || j < n) {
            if (i == m) {
                v[k++] = nums2[j++];
            } else if (j == n) {
                v[k++] = nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                v[k++] = nums1[i++];
            } else {
                v[k++] = nums2[j++];
            }
        }
        v.swap(nums1);
    }
};
