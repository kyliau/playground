// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path
// from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        root->val = 1;
        queue<TreeNode *> q;
        q.push(root);
        int result = 0;
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result = node->val;
                break;
            }
            if (node->left) {
                node->left->val = node->val + 1;
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = node->val + 1;
                q.push(node->right);
            }
        }
        return result;
    }
};
