// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

#include <algorithm>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left  = height(root->left);
        if (-1 == left) {
            return -1;
        }
        int right = height(root->right);
        if (-1 == right || std::abs(left - right) > 1) {
            return -1;
        }
        return 1 + std::max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return -1 != height(root);
    }
};