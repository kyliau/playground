// Implement an iterator over a binary search tree (BST).
// Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// Note: next() and hasNext() should run in average O(1) time and
// uses O(h) memory, where h is the height of the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
    
public:
    BSTIterator(TreeNode *root) {
        while(root) {
            s.push(root);
            root = root->left;
        }    
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top();
        s.pop();
        TreeNode *n = t->right;
        while(n) {
            s.push(n);
            n = n->left;
        }
        return t->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
