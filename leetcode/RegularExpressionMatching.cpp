// Implement regular expression matching with support for '.' and '*'.
//     '.' Matches any single character.
//     '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// The function prototype should be:
//     bool isMatch(const char *s, const char *p)
// Some examples:
//     isMatch("aa","a") -> false
//     isMatch("aa","aa") -> true
//     isMatch("aaa","aa") -> false
//     isMatch("aa", "a*") -> true
//     isMatch("aa", ".*") -> true
//     isMatch("ab", ".*") -> true
//     isMatch("aab", "c*a*b") -> true

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool matchStar(const string& s, const string& p, int si, int pi) {
        int sn = s.length();
        int pn = p.length();
        assert(pi < pn - 1);
        assert(p[pi + 1] == '*');
        char c = p[pi];
        do {
            if (matchHere(s, p, si, pi + 2)) {
                return true;
            }
        } while (si < sn && (c == s[si++] || c == '.'));
        return false;
    }

    bool matchHere(const string& s, const string& p, int si, int pi) {
        int sn = s.length();
        int pn = p.length();
        while (pi < pn) {
            char c = p[pi];
            if (pi != pn - 1 && p[pi + 1] == '*') {
                return matchStar(s, p, si, pi);
            }
            else if (si < sn && (c == '.' || c == s[si])) {
                ++si;
            }
            else {
                return false;
            }
            ++pi;
        }
        return si == sn;
    }

    bool isMatch(const string& s, const string& p) {
        return matchHere(s, p, 0, 0);
    }
};

int main() {
    const struct {
        int    n;
        string s;
        string p;
        bool   match;
    } TEST_CASES[] = {
        // #  string   pattern   match
        {  1,   "aa",      "a",  false },
        {  2,   "aa",     "aa",   true },
        {  3,  "aaa",     "aa",  false },
        {  4,   "aa",    "aaa",  false },
        {  5,    "a",      ".",   true },
        {  6,   "aa",     "a*",   true },
        {  7,   "aa",     ".*",   true },
        {  8,   "ab",     ".*",   true },
        {  9,  "aab",  "c*a*b",   true },
        { 10,  "abc",    ".*c",   true },
        { 11,  "abd",    ".*c",  false },
        { 12,  "aaa",    "a*a",   true },
        { 13,   "aa",   "ab*a",   true },
        { 14,  "aba",   "ab*a",   true },
        { 15, "abba",   "ab*a",   true },
        { 16,     "",     ".*",   true },
        { 17,     "",       "",   true },
        { 18,     "",      ".",  false },
        { 19,  "aaa",    ".*.",   true },
        { 20,  "aaa",   ".*.*",   true },
        { 21,  "aaa",  "a*aaa",   true },
        { 22,     "",    ".*.",  false },
        { 23,    "x",       "",  false },
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