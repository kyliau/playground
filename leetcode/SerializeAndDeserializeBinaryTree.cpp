// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no
// restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and
// this string can be deserialized to the original tree structure.
//
// For example, you may serialize the following tree
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a
// binary tree. You do not necessarily need to follow this format, so please be
// creative and come up with different approaches yourself.
// Note: Do not use class member/global/static variables to store states.
// Your serialize and deserialize algorithms should be stateless.

#include <iostream>
#include <sstream>
#include <string>
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

class Codec {
    private:
        ostream& serialize(TreeNode *root, ostream& stream) {
            if (!root) {
                stream << " #";
            } else {
                stream << ' ' << root->val;
                serialize(root->left, stream);
                serialize(root->right, stream);
            }
            return stream;
        }

        TreeNode *deserialize(istream& stream, string& s) {
            stream >> s;
            if (!stream || "#" == s) {
                return nullptr;
            }
            TreeNode *node = new TreeNode(std::stoi(s));
            node->left  = deserialize(stream, s);
            node->right = deserialize(stream, s);
            return node;
        }

    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if (!root) {
                return "#";
            }
            ostringstream stream;
            stream << root->val;
            serialize(root->left, stream);
            serialize(root->right, stream);
            return stream.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            string s;
            istringstream stream(data);
            return deserialize(stream, s);
        }
};

TreeNode *make(int val, TreeNode *left = nullptr, TreeNode *right = nullptr) {
    TreeNode *n = new TreeNode(val);
    n->left  = left;
    n->right = right;
    return n;
}

bool isSameTree(const TreeNode *x, const TreeNode *y) {
    if (!x && !y) {
        return true;
    }
    if (!x || !y) {
        return false;
    }
    return x->val == y->val &&
           isSameTree(x->left, y->left) && isSameTree(x->right, y->right);
}

int main() {
    const struct {
        int       n;
        TreeNode *node;
        string    expected;
    } CASES[] = {
        {
            1,
            make(1, make(2), make(3, make(4), make(5))),
            "1 2 # # 3 4 # # 5 # #"
        },
        {
            2,
            make(1, make(2, make(3)), make(4, nullptr, make(5))),
            "1 2 3 # # # 4 # 5 # #"
        },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto  node     = CASES[i].node;
        auto& expected = CASES[i].expected;
        assert(isSameTree(node, node));
        cout << "Test case " << n << " ... ";
        Codec c;
        string result = c.serialize(node);
        if (result != expected) {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        else if (!isSameTree(c.deserialize(result), node)) {
            cout << "FAIL (Not the same tree)";
        }
        else {
            cout << "PASS";
        }
        cout << endl;
    }
}
