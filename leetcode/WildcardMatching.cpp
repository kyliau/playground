// Implement wildcard pattern matching with support for '?' and '*'.
//     '?' Matches any single character.
//     '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
// Some examples:
//     isMatch("aa","a") → false
//     isMatch("aa","aa") → true
//     isMatch("aaa","aa") → false
//     isMatch("aa", "*") → true
//     isMatch("aa", "a*") → true
//     isMatch("ab", "?*") → true
//     isMatch("aab", "c*a*b") → false

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool matchStar(const string& s, const string& p, int si, int pi) {
        //cout << "Match star " << s.substr(si) << " with " << p.substr(pi) << endl;
        int sn = s.length();
        int pn = p.length();
        assert(p[pi] == '*');
        while (pi < pn - 1 && p[pi + 1] == '*') {
            ++pi;
        }
        if (pi == pn - 1) {
            return true;
        }
        do {
            if (matchHere(s, p, si, pi + 1)) {
                return true;
            }
            ++si;
        } while (si < sn);
        return false;
    }

    bool matchHere(const string& s, const string& p, int si, int pi) {
        //cout << "Match here " << s.substr(si) << " with " << p.substr(pi) << endl;
        int sn = s.length();
        int pn = p.length();
        while (pi < pn) {
            char c = p[pi];
            if ('*' == c) {
                return matchStar(s, p, si, pi);
            }
            if (si < sn && ('?' == c || s[si] == c)) {
                ++si;
                ++pi;
            }
            else {
                return false;
            }
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
        // #           string          pattern   match
        // -- -------------------  ------------  -----
        {  1,                "aa",          "a", false },
        {  2,                "aa",         "aa",  true },
        {  3,               "aaa",         "aa", false },
        {  4,                "aa",        "aaa", false },
        {  5,                "aa",          "*",  true },
        {  6,                "aa",         "a*",  true },
        {  7,                "ab",         "?*",  true },
        {  8,               "aab",      "c*a*b", false },
        {  9,                 "a",          "?",  true },
        { 10,                  "",          "*",  true },
        { 11,                  "",         "*b", false },
        { 12,                 "b",         "*b",  true },
        { 13,                 "c",         "*b", false },
        { 14,               "abc",        "*?*",  true },
        { 15,                 "a",         "*?",  true },
        { 16,                 "a",         "?*",  true },
        { 17,                  "",          "?", false },
        { 18,                "ab",        "***",  true },
        { 19,                  "",           "",  true },
        { 20,              "aaab",        "a*b",  true },
        { 21,               "aaa",        "*b*", false },
        { 22, "abefcdgiescdfimde", "ab*cd?i*de",  true },
        { 23,           "abccxxc",         "*c",  true },
        { 24,                "hi",         "*?",  true },
        { 25,               "abc", "a********?",  true },
        { 26,               "abc", "**********",  true },
        { 27, "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb", true },
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