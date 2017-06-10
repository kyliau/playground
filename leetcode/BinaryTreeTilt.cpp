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
    int sum(TreeNode *root, int &tilt) {
        if (!root) {
            return 0;
        }
        int left  = sum(root->left, tilt);
        int right = sum(root->right, tilt);
        tilt += std::abs(left - right);
        return root->val + left + right;
    }
  public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        sum(root, tilt);
        return tilt;
    }
};