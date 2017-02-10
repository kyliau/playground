// Implement regular expression matching with support for '.' and '*'.
//     '.' Matches any single character.
//     '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// The function prototype should be:
//     bool isMatch(const char *s, const char *p)
// Some examples:
//     isMatch("aa","a") → false
//     isMatch("aa","aa") → true
//     isMatch("aaa","aa") → false
//     isMatch("aa", "a*") → true
//     isMatch("aa", ".*") → true
//     isMatch("ab", ".*") → true
//     isMatch("aab", "c*a*b") → true

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return false;
    }
};

int main() {
    const struct {
        int    n;
        string s;
        string p;
        bool   match;
    } TEST_CASES[] = {
        {  1,  "aa",     "a", false },
        {  2,  "aa",    "aa", true  },
        {  3, "aaa",    "aa", false },
        {  4,  "aa",    "a*", true  },
        {  5,  "aa",    ".*", true  },
        {  6,  "ab",    ".*", true  },
        {  7, "aab", "c*a*b", true  },
    };
    int NUM_CASES = sizeof(TEST_CASES) / sizeof(TEST_CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n         = TEST_CASES[i].n;
        const string& s         = TEST_CASES[i].s;
        const string& p         = TEST_CASES[i].p;
        bool          expected  = TEST_CASES[i].match;
        cout << "Test case " << n << "\t... ";
        Solution sol;
        bool result = sol.isMatch(s, p);
        if (result == expected) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL (Expected " << (expected ? "true" : "false")
                 << " but got " << (result ? "true" : "false" ) << ")"
                 << endl;
        }
    }
    return 0;
}