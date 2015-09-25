// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.
// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

class Solution {
public:
    int partition(vector<int>& v, int l, int r) {
        int pivot = v[l];
        swap(v[l], v[r]);
        int start = l;
        for (int i = l; i < r; ++i) {
            if (v[i] > pivot) {
                swap(v[i], v[start++]);
            }
        }
        swap(v[start], v[r]);
        return start;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int p = partition(nums, left, right);
            if (p == k - 1) {
                return nums[p];
            } else if (p > k - 1) {
                right = p - 1;
            } else {    // p < k - 1
                left = p + 1;
            }
        }
        return nums[left];
    }
};
