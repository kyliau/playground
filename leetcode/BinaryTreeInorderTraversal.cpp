// Given a binary tree, return the inorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
// Note: Recursive solution is trivial, could you do it iteratively?

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
    void helper(vector<int> *v, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        helper(v, root->left);
        v->emplace_back(root->val);
        helper(v, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(&v, root);
        return v;
    }
};
