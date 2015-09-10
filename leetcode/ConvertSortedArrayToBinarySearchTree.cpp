// Given an array where elements are sorted in ascending order,
// convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = 0.5 * (right - left) + left;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left  = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return helper(nums, 0, size - 1);
    }
};
