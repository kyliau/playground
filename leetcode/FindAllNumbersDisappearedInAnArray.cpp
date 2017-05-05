// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
// elements appear twice and others appear once.
//
// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime?
// You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]

class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        for (int x : nums) {
            ++results[x - 1];
        }
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (results[j] == 0) {
                results[i++] = j + 1;
            }
        }
        results.resize(i);
        return results;
    }
};