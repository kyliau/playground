// Given a binary tree containing digits from 0-9 only,
// each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// For example,
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = 12 + 13 = 25.

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
    void helper(TreeNode *root, int sumSoFar, int *result) {
        if (root == nullptr) {
            return;
        }
        int value = sumSoFar * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            *result += value;
        } else {
            helper(root->left,  value, result);
            helper(root->right, value, result);
        }
    }
    int sumNumbers(TreeNode* root) {
        int result = 0;
        helper(root, 0, &result);
        return result;
    }
};
