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
    void flatten(TreeNode *root, TreeNode **prev) {
        if (!root) {
            return;
        }
        flatten(root->right, prev);
        flatten(root->left, prev);
        root->left  = nullptr;
        root->right = *prev;
        *prev = root;
    }
  public:
    void flatten(TreeNode* root) {
        TreeNode *prev = nullptr;
        flatten(root, &prev);
    }
};