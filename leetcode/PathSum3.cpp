// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go
// downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range
// -1,000,000 to 1,000,000.
// Example:
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
// Return 3. The paths that sum to 8 are:
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *makeTree(int x, int y, int z) {
    TreeNode *node = new TreeNode(x);
    node->left     = new TreeNode(y);
    node->right    = new TreeNode(z);
    return node;
}

//TreeNode *makeTree(int x, int y) {
//    TreeNode *node = new TreeNode(x);
//    node->left     = new TreeNode(y);
//    return node;
//}

TreeNode *makeTree(int x, TreeNode *y, int z) {
    TreeNode *node = new TreeNode(x);
    node->left     = y;
    node->right    = new TreeNode(z);
    return node;
}

TreeNode *makeTree(int x, TreeNode *y, TreeNode *z) {
    TreeNode *node = new TreeNode(x);
    node->left     = y;
    node->right    = z;
    return node;
}

class Solution {
  private:
    int pathSum(unordered_map<int, int>&  h,
                TreeNode                 *root,
                int                       sum,
                int                       target) {
        if (!root) {
            return 0;
        }
        sum += root->val;
        int count = h[sum - target];
        ++h[sum];
        count += pathSum(h, root->left, sum, target) +
                 pathSum(h, root->right, sum, target);
        --h[sum];
        return count;
    }

  public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> h;
        h[0] = 1;
        return pathSum(h, root, 0, sum);
    }
};

class Solution2 {
  private:
    int findPath(TreeNode *root, int sum) {
        int count = 0;
        if (!root) {
            return count;
        }
        if (sum == root->val) {
            ++count;
        }
        return count + findPath(root->left, sum - root->val) +
                       findPath(root->right, sum - root->val);
    }

  public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) {
            return 0;
        }
        return findPath(root, sum) + pathSum(root->left, sum) +
                                     pathSum(root->right, sum);
    }
};

int main() {
    const struct {
        int       n;
        TreeNode *root;
        int       sum;
        int       expected;
    } CASES[] = {
        { 1, makeTree(10, makeTree(5, makeTree(3, 3, -2), makeTree(2, nullptr, 1)), makeTree(-3, nullptr, 11)), 8, 3 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int       n        = CASES[i].n;
        TreeNode *root     = CASES[i].root;
        int       sum      = CASES[i].sum;
        int       expected = CASES[i].expected;
        Solution s;
        cout << "Test case " << n << " ... ";
        int result = s.pathSum(root, sum);
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