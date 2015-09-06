// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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
    void helper(vector<vector<int>> *v, TreeNode *node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level == v->size()) {
            v->emplace_back();
        }
        (*v)[level].emplace_back(node->val);
        helper(v, node->left,  level + 1);
        helper(v, node->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        helper(&v, root, 0);
        return v;
    }
};
