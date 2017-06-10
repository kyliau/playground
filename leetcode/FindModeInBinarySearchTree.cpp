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
    void traverse(TreeNode     *root,
                  int&          current,
                  int&          freq,
                  int&          maxFreq,
                  vector<int>&  results) {
        if (!root) {
            return;
        }
        traverse(root->left, current, freq, maxFreq, results);
        if (current != root->val) {
            current = root->val;
            freq = 0;
        }
        ++freq;
        maxFreq = std::max(maxFreq, freq);
        if (freq == maxFreq) {
            results.emplace_back(current);
        }
        traverse(root->right, current, freq, maxFreq, results);
    }
  public:
    vector<int> findMode(TreeNode* root) {
        int current = 0;
        int freq    = 0;
        int maxFreq = 0;
        vector<int> results;
        // in the first pass figure out the highest frequency
        traverse(root, current, freq, maxFreq, results);
        freq = 0;
        results.clear();
        // in the second pass accumulate all values with the highest frequency
        traverse(root, current, freq, maxFreq, results);
        return results;
    }
};