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
    int maxDepth(TreeNode *root, int& result) {
        if (!root) {
            return 0;
        }
        int left  = maxDepth(root->left, result);
        int right = maxDepth(root->right, result);

        result = std::max(result, left + right);

        return 1 + std::max(left, right);
    }
  public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        maxDepth(root, result);
        return result;
    }
};