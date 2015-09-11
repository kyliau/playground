// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.
// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

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
    void helper(vector<int> *v, TreeNode *node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level == v->size()) {
            v->emplace_back();
        }
        (*v)[level] = node->val;
        helper(v, node->left,  level + 1);
        helper(v, node->right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        helper(&v, root, 0);
        return v;
    }
};
