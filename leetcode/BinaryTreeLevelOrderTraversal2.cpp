// Given a binary tree, return the bottom-up level order traversal of its nodes' values.
// (ie, from left to right, level by level from leaf to root).
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// This works but there might be a better solution.
// This is exactly the same solution as BinaryTreeLevelOrderTraversal.cpp
// but with the reverse operation.

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        helper(&v, root, 0);
        reverse(v.begin(), v.end());
        return v;
    }
};
