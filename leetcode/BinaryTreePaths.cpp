// Given a binary tree, return all root-to-leaf paths.
// For example, given the following binary tree:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]

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
    void helper(vector<string> *v, string s, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        if (!s.empty()) {
            s += "->";
        }
        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            v->emplace_back(s);
        } else {
            helper(v, s, root->left);
            helper(v, s, root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        helper(&v, "", root);
        return v;
    }
};
