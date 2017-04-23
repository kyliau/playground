// Given a binary tree and a sum, find all root-to-leaf paths where each path's
// sum equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
  private:
    void something(vector<vector<int>>& result,
                   vector<int>&         path,
                   int                  sum,
                   int                  target,
                   TreeNode            *node) {
        path.emplace_back(node->val);
        sum += node->val;
        if (!node->left && !node->right) {
            if (sum == target) {
                result.emplace_back(path);
            }
        }
        else {
            if (node->left) {
                something(result, path, sum, target, node->left);
            }
            if (node->right) {
                something(result, path, sum, target, node->right);
            }
        }
        path.pop_back();
    }
  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int>         path;
        if (root) {
            something(result, path, 0, sum, root);
        }
        return result;
    }
};