// Given a binary search tree with non-negative values, find the minimum
// absolute difference between values of any two nodes.
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1
// (or between 2 and 3).
// Note: There are at least two nodes in this BST.

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
  private:
    int helper(TreeNode *root, int result, int **prev) {
        if (!root) {
            return result;
        }
        result = std::min(result, helper(root->left, result, prev));
        if (*prev) {
            result = std::min(result, root->val - **prev);
        }
        *prev = &(root->val);
        result = std::min(result, helper(root->right, result, prev));
        return result;
    }

  public:
    int getMinimumDifference(TreeNode* root) {
        int *prev = nullptr;
        return helper(root, std::numeric_limits<int>::max(), &prev);
    }
};