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
    vector<TreeNode*> generate(int start, int end) {
        // Generate all binary search trees in the range [start, end]
        vector<TreeNode *> results;
        if (start > end) {
            results.emplace_back(nullptr);
            return results;
        }
        if (start == end) {
            results.emplace_back(new TreeNode(start));
            return results;
        }
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        for (int i = start; i <= end; ++i) {
            left  = generate(start, i - 1);
            right = generate(i + 1, end);
            for (TreeNode *n : left) {
                for (TreeNode *m : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left  = n;
                    root->right = m;
                    results.emplace_back(root);
                }
            }
        }
        return results;
    }
  public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return {};
        }
        return generate(1, n);
    }
};