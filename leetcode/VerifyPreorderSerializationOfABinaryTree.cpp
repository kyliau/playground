// One way to serialize a binary tree is to use pre-order traversal.
// When we encounter a non-null node, we record the node's value.
// If it is a null node, we record using a sentinel value such as #.
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string
// "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
// Given a string of comma separated values, verify whether it is a correct
// preorder traversal serialization of a binary tree.
// Find an algorithm without reconstructing the tree.
// Each comma separated value in the string must be either an integer or a
// character '#' representing null pointer.
// You may assume that the input format is always valid, for example it could
// never contain two consecutive commas such as "1,,3".
// Example 1:
//  "9,3,4,#,#,1,#,#,2,#,6,#,#"
//  Return true
// Example 2:
//  "1,#"
//  Return false
// Example 3:
//  "9,#,#,1"
//  Return false

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    private:
        bool isValid(istream& stream, string& s) {
            std::getline(stream, s, ',');
            if (!stream) {
                return false;
            }
            return "#" == s || (isValid(stream, s) && isValid(stream, s));
        }

    public:
        bool isValidSerialization(const string& preorder) {
            string s;
            istringstream stream(preorder);
            return isValid(stream, s) && stream.eof();
        }
};

int main() {
    const struct {
        int    n;
        string s;
        bool   expected;
    } CASES[] = {
        { 1, "9,3,4,#,#,1,#,#,2,#,6,#,#",  true },
        { 2,                       "1,#", false },
        { 3,                   "9,#,#,1", false },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto& s        = CASES[i].s;
        bool  expected = CASES[i].expected;
        Solution sol;
        bool result = sol.isValidSerialization(s);
        cout << "Test case " << n << " ... ";
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL";
        }
        cout << endl;
    }
    return 0;
}