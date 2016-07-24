// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array
// [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

class Solution {
private:
    void reverse(vector<int> *n, int begin, int end) {
        int size = end - begin;
        for (int i = 0; i < size / 2; ++i) {
            std::swap((*n)[begin + i], (*n)[end - 1 - i]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(&nums, 0, n);
        reverse(&nums, 0, k);
        reverse(&nums, k, n);
    }
};
