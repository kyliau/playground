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
    bool isValid(TreeNode *root, long long smallest, long long largest) {
        // val must be in the range [smallest, largest] for
        // valid BST
        if (!root) {
            return true;
        }
        long long val = root->val;
        if (val < smallest || val > largest) {
            return false;
        }
        return isValid(root->left, smallest, val - 1) &&
               isValid(root->right, val + 1, largest);
    }
  public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, std::numeric_limits<int>::lowest(),
                             std::numeric_limits<int>::max());
    }
};