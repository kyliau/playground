// Given a string, find the first non-repeating character in it and return its
// index. If it doesn't exist, return -1.
// Examples:
// s = "leetcode"
// return 0.
// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int firstUniqChar(const string& s) {
        int count[26] = {0};
        for (char c : s) {
            ++count[c - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    const struct {
        int    n;
        string s;
        int    expected;
    } CASES[] = {
        { 1, "leetcode", 0 },
        { 2, "loveleetcode", 2 },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n        = CASES[i].n;
        const string& s        = CASES[i].s;
        int           expected = CASES[i].expected;
        Solution sol;
        cout << "Test case " << n << " ... ";
        int result = sol.firstUniqChar(s);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    }
    return 0;
}