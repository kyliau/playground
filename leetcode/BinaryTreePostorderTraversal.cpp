// Given a binary tree, return the postorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].
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
        helper(v, root->right);
        v->emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(&v, root);
        return v;
    }
};
