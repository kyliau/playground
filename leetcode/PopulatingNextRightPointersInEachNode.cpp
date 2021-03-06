// Given a binary tree
// 
//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
//
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
// 
// Initially, all next pointers are set to NULL.
// 
// Note:
// 
// You may only use constant extra space.
// You may assume that it is a perfect binary tree
// (ie, all leaves are at the same level, and every parent has two children).
// 
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// 
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void helper(vector<TreeLinkNode *> *v, TreeLinkNode *node, int level) {
        if (node == nullptr) {
            return;
        }
        if (v->size() == level) {
            v->emplace_back();
        } else {
            (*v)[level]->next = node;
        }
        (*v)[level] = node;
        helper(v, node->left,  level + 1);
        helper(v, node->right, level + 1);
    }
    void connect(TreeLinkNode *root) {
        // this solution uses O(log h) space
        vector<TreeLinkNode *> v;
        helper(&v, root, 0);
    }
};
