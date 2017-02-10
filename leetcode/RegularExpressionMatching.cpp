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
#include <assert.h>

using namespace std;

class Solution {
public:
    int matchStar(const string& s, const string& p, int si, int pi) {
        int sn = s.length();
        int pn = p.length();
        assert(pi < pn - 1);
        char c = p[pi];
        assert(p[pi + 1] == '*');
        if ('.' != c) {
            while (si != sn && s[si] == c) {
                ++si;
            }
            return si;                                                 // RETURN
        }
        bool endOfP = pi == (pn - 2);
        if (endOfP) {
            return sn;                                                 // RETURN
        }
        char nextC = p[pi + 2];
        while (si != sn && s[si] != nextC) {
            ++si;
        }
        return si;                                                     // RETURN
    }
    bool isMatch(const string& s, const string& p) {
        int si = 0;
        int sn = s.length();
        int pn = p.length();
        for (int pi = 0; pi < pn; ++pi) {
            if (pi != pn - 1 && p[pi + 1] == '*') {
                si = matchStar(s, p, si, pi);
                ++pi;
            } else {
                char c = p[pi];
                if (si == sn) {
                    return false;
                }
                if (c == '.' || c == s[si]) {
                    ++si;
                } else {
                    return false;
                }
            }
        }
        return si == sn;
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
        {  5,   "aa",     "a*",   true },
        {  6,   "aa",     ".*",   true },
        {  7,   "ab",     ".*",   true },
        {  8,  "aab",  "c*a*b",   true },
        {  9,  "abc",    ".*c",   true },
        { 10,  "abd",    ".*c",  false },
        { 11,  "aaa",    "a*a",   true },
        { 12,   "aa",   "ab*a",   true },
        { 13,  "aba",   "ab*a",   true },
        { 14, "abba",   "ab*a",   true },
        { 15,     "",     ".*",   true },
        { 16,     "",       "",   true },
        { 17,     "",      ".",  false },
        { 18,  "aaa",    ".*.",   true },
        { 19,  "aaa",   ".*.*",   true },
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