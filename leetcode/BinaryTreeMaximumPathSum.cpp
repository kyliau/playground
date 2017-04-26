// Given a binary tree, find the maximum path sum.
// For this problem, a path is defined as any sequence of nodes from some
// starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the
// root.
// For example:
// Given the below binary tree,
//        1
//       / \
//      2   3
// Return 6.

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <assert.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *makeTree(int x, int y, int z) {
    TreeNode *node = new TreeNode(x);
    node->left     = new TreeNode(y);
    node->right    = new TreeNode(z);
    return node;
}

TreeNode *makeTree(int x, int y, TreeNode *z = nullptr) {
    TreeNode *node = new TreeNode(x);
    node->left     = new TreeNode(y);
    node->right    = z;
    return node;
}

TreeNode *makeTree(int x, TreeNode *y, int z) {
    TreeNode *node = new TreeNode(x);
    node->left     = y;
    node->right    = new TreeNode(z);
    return node;
}

TreeNode *makeTree(int x, TreeNode *y = nullptr, TreeNode *z = nullptr) {
    TreeNode *node = new TreeNode(x);
    node->left     = y;
    node->right    = z;
    return node;
}

class Solution {
  private:
    int maxPathSum(TreeNode *root, int& sum) {
        if (!root) {
            return 0;
        }
        int left  = std::max(0, maxPathSum(root->left, sum));
        int right = std::max(0, maxPathSum(root->right, sum));
        sum = std::max(sum, root->val + left + right);
        return std::max(left, right) + root->val;
    }
  public:
    int maxPathSum(TreeNode* root) {
        int sum = std::numeric_limits<int>::lowest();
        maxPathSum(root, sum);
        return sum;
    }
};

int main() {
    const struct {
        int       n;
        TreeNode *root;
        int       expected;
    } CASES[] = {
        { 1, makeTree(1, 2, 3), 6 },
        { 2, makeTree(-3), -3 },
        { 3, makeTree(-1, makeTree(-2, makeTree(1, -1), 3), makeTree(-3, -2)), 3 },
        { 4, makeTree(1, makeTree(2, 4, 5), makeTree(3, 6, 7)), 18 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int       n        = CASES[i].n;
        TreeNode *root     = CASES[i].root;
        int       expected = CASES[i].expected;
        Solution s;
        cout << "Test case " << n << " ... ";
        int result = s.maxPathSum(root);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    };
    return 0;
}