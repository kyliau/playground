// Given n, how many structurally unique BST's (binary search trees) that store
// values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        vector<int> v(n + 1, 0);
        v[0] = 1;   // empty tree
        v[1] = 1;   // tree with only one node
        for (int i = 2; i <= n; ++i) {  // loop through the entire sequence
            for (int j = 1; j <= i; ++j) {  // with 'j' as the root
                v[i] += v[j - 1] * v[i - j];
            }
        }
        return v[n];
    }
};

int main() {
    Solution s;
    int result = s.numTrees(10);
    cout << result << endl;
}