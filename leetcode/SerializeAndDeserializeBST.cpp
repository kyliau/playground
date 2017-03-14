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
#include <limits>

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

    TreeNode *reconstruct(const vector<int>& v, int& i, int min, int max) {
        if (i >= v.size() || v[i] < min || v[i] > max) {
            return nullptr;
        }
        TreeNode *n = new TreeNode(v[i++]);
        n->left  = reconstruct(v, i, min, n->val);
        n->right = reconstruct(v, i, n->val, max);
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
        return reconstruct(v,
                           i,
                           std::numeric_limits<int>::min(),
                           std::numeric_limits<int>::max());
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
        TreeNode *newRoot = codec.deserialize(data);
        assert(isSameTree(root, newRoot));
    }
    {
        TreeNode *root = buildTree(1, nullptr, buildTree(2, nullptr, buildTree(3, nullptr, buildTree(4))));
        assert(isSameTree(root, root));
        Codec codec;
        string data = codec.serialize(root);
        TreeNode *newRoot = codec.deserialize(data);
        assert(isSameTree(root, newRoot));
    }
    {
        TreeNode *root = buildTree(4, buildTree(3, buildTree(2, buildTree(1), nullptr), nullptr), nullptr);
        assert(isSameTree(root, root));
        Codec codec;
        string data = codec.serialize(root);
        TreeNode *newRoot = codec.deserialize(data);
        assert(isSameTree(root, newRoot));
    }
    {
        TreeNode *root = buildTree(20, buildTree(15, buildTree(10, buildTree(2), buildTree(14)), buildTree(18, buildTree(16), buildTree(19))), buildTree(30, buildTree(24, buildTree(20)), buildTree(31, nullptr, buildTree(32))));
        assert(isSameTree(root, root));
        Codec codec;
        string data = codec.serialize(root);
        TreeNode *newRoot = codec.deserialize(data);
        assert(isSameTree(root, newRoot));
    }
}