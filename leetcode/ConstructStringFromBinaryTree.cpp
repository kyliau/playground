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
    void serialize(TreeNode *t, ostream &stream) {
        if (!t) {
            stream << "()";
            return;
        }
        stream << '(' << t->val;
        if (t->right) {
            serialize(t->left, stream);
            serialize(t->right, stream);
        }
        else if (t->left) {
            serialize(t->left, stream);
        }
        stream << ')';
    }
  public:
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        }
        ostringstream stream;
        stream << t->val;
        if (t->right) {
            serialize(t->left, stream);
            serialize(t->right, stream);
        }
        else if (t->left) {
            serialize(t->left, stream);
        }
        return stream.str();
    }
};