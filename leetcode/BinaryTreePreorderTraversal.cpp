// Given a binary tree, return the preorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].
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
    void helper(vector<int> *v, TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        v->emplace_back(node->val);
        helper(v, node->left);
        helper(v, node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(&v, root);
        return v;
    }
};
