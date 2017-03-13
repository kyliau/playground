// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
// Design an algorithm to serialize and deserialize a binary search tree. There
// is no restriction on how your serialization/deserialization algorithm should
// work. You just need to ensure that a binary search tree can be serialized to
// a string and this string can be deserialized to the original tree structure.
// The encoded string should be as compact as possible.
// Note: Do not use class member/global/static variables to store states. Your
// serialize and deserialize algorithms should be stateless.
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#include <sstream>
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

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

TreeNode *buildTree(int       val,
                    TreeNode *left = nullptr,
                    TreeNode *right = nullptr) {
    TreeNode *node = new TreeNode(val);
    node->left  = left;
    node->right = right;
    return node;
}

class Codec {
private:
    ostream& serialize(TreeNode *root, ostream& stream) {
        if (!root) {
            return stream;
        }
        stream << root->val << " ";
        serialize(root->left, stream);
        serialize(root->right, stream);
        return stream;
    }

    void deserialize(istream& stream, TreeNode *root) {
        if (!root) {
            return;
        }
        int val;
        stream >> val;
        if (!stream) {
            return;
        }
        TreeNode *node = new TreeNode(val);
        if (val < root->val) {
            root->left = node;
        } else {
            root->right = node;
        }
        deserialize(stream, node);
    }

    TreeNode *reconstruct(const vector<int>& v, int& i, TreeNode *p) {
        if (i >= v.size()) {
            return nullptr;
        }
        TreeNode *n = new TreeNode(v[i++]);
        if (i < v.size() && v[i] < n->val) {
            n->left = reconstruct(v, i);
        }
        if (i < v.size() && v[i] >= n->val) {
            n->right = reconstruct(v, i);
        }
        return n;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream stream;
        serialize(root, stream);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        vector<int> v;
        int x;
        istringstream stream(data);
        while (stream >> x) {
            v.emplace_back(x);
        }
        int i = 0;
        return reconstruct(v, i, nullptr);
        //int val;
        //istringstream stream(data);
        //stream >> val;
        //if (!stream) {
        //    return nullptr;
        //}
        //TreeNode *root = new TreeNode(val);
        //deserialize(stream, root);
        //return root;
    }
};

bool isSameTree(TreeNode *x, TreeNode *y) {
    if (!x && !y) {
        return true;
    }
    if (!x || !y) {
        return false;
    }
    return x->val == y->val &&
           isSameTree(x->left, y->left) &&
           isSameTree(x->right, y->right);
}

int main() {
    {
        TreeNode *root = buildTree(10, buildTree(5), buildTree(11, buildTree(10), buildTree(12)));
        assert(isSameTree(root, root));
        Codec codec;
        string data = codec.serialize(root);
        cout << data << endl;
        TreeNode *newRoot = codec.deserialize(data);
        assert(isSameTree(root, newRoot));
    }
    {
        TreeNode *root = buildTree(1, nullptr, buildTree(2, nullptr, buildTree(3, nullptr, buildTree(4))));
        assert(isSameTree(root, root));
        Codec codec;
        cout << codec.serialize(root) << endl;
    }
    {
        TreeNode *root = buildTree(4, buildTree(3, buildTree(2, buildTree(1), nullptr), nullptr), nullptr);
        assert(isSameTree(root, root));
        Codec codec;
        cout << codec.serialize(root) << endl;
    }
    {
        TreeNode *root = buildTree(20, buildTree(15, buildTree(10, buildTree(2), buildTree(14)), buildTree(18, buildTree(16), buildTree(19))), buildTree(30, buildTree(24, buildTree(20)), buildTree(31, nullptr, buildTree(32))));
        assert(isSameTree(root, root));
        Codec codec;
        cout << codec.serialize(root) << endl;
    }
}