// Given a complete binary tree, count the number of nodes.
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last,
// is completely filled, and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.

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
    enum Direction { LEFT, RIGHT };
public:
    int getHeight(TreeNode *root, Direction dir) {
        int height = 0;
        while (root) {
            ++height;
            root = dir == LEFT ? root->left : root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        int leftHeight  = getHeight(root, LEFT);
        int rightHeight = getHeight(root, RIGHT);
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
