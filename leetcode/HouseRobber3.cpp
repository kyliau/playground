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
    using Pair = std::pair<int, int>;
    // Pair.first  -> max value when root is NOT robbed
    // Pair.second -> max value when root IS robbed
    Pair robb(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }
        Pair left  = robb(root->left);
        Pair right = robb(root->right);
        return {
            std::max(left.first, left.second) + std::max(right.first, right.second),
            root->val + left.first + right.first
        };
    }

  public:
    int rob(TreeNode* root) {
        Pair p = robb(root);
        return std::max(p.first, p.second);
    }
};