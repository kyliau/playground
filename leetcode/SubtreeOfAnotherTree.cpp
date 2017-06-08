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
    string serialize(TreeNode *root) {
        ostringstream oss;
        std::stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *n = s.top();
            s.pop();
            oss << ',' << (n ? n->val : '#');
            if (n) {
                s.push(n->left);
                s.push(n->right);
            }
        }
        return oss.str();
    }
  public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ss = serialize(s);
        string ts = serialize(t);
        return std::string::npos != ss.find(ts);
    }
};

// This is surprisingly faster
class Solution {
  private:
    bool isSame(TreeNode *s, TreeNode *t) {
        if (!s) {
            return t == nullptr;
        }
        if (!t) {
            return s == nullptr;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
  public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSame(s, t) || (s && isSubtree(s->left, t)) ||
                               (s && isSubtree(s->right, t));
    }
};