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
    int helper(TreeNode *root, int k, vector<int>& v) {
        if (!root) {
            return v.size();
        }
        if (k == helper(root->left, k, v)) {
            return k;
        }
        v.emplace_back(root->val);
        if (v.size() == k) {
            return k;
        }
        return helper(root->right, k, v);
    }
  public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        v.reserve(k);
        helper(root, k, v);
        return v.back();
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// This solution is much faster!!
class Solution {
  private:
    TreeNode *helper(TreeNode *root, int k, int& x) {
        if (!root) {
            return root;
        }
        TreeNode *left = helper(root->left, k, x);
        if (left) {
            return left;
        }
        if (++x == k) {
            return root;
        }
        TreeNode *right = helper(root->right, k, x);
        return x == k ? right : nullptr;
    }
  public:
    int kthSmallest(TreeNode* root, int k) {
        int x = 0;
        return helper(root, k, x)->val;
    }
};