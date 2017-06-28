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
    TreeNode *build(const vector<int>& preorder,
                    const vector<int>& inorder,
                    int                inLeft,
                    int                inRight,
                    int                preIndex) {
        if (preIndex >= preorder.size() || inLeft >= inRight) {
            return nullptr;
        }
        int val = preorder[preIndex];
        TreeNode *root = new TreeNode(val);
        // Find the location of 'val' in inorder
        auto it = std::find(inorder.begin() + inLeft,
                            inorder.begin() + inRight,
                            val);
        root->left = build(preorder,
                           inorder,
                           inLeft,
                           it - inorder.begin(),
                           preIndex + 1);
        root->right = build(preorder,
                            inorder,
                            it - inorder.begin() + 1,
                            inRight,
                            preIndex + (it - inorder.begin()) - inLeft + 1);
        return root;
    }
  public:
    TreeNode* buildTree(const vector<int>& preorder,
                        const vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size(), 0);
    }
};