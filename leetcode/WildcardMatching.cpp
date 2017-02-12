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
#include <vector>

using namespace std;

ostream& operator<<(ostream& stream, const vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << "\n[ ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << (j == 0 ? "" : ", ") << (v[i][j] < 0 ? "" : " ") << v[i][j];
        }
        cout << " ]";
    }
    return stream;
}

class RecursiveSolution {
    public:
    bool matchStar(const string& s, const string& p, int si, int pi) {
        // Recursion method. It is exponentially slow!
        int sn = s.length();
        int pn = p.length();
        assert(p[pi] == '*');
        while (pi < pn && p[pi] == '*') {
            ++pi;
        }
        if (pi == pn) {
            return true;
        }
        do {
            if (matchHere(s, p, si, pi)) {
                return true;
            }
            ++si;
        } while (si < sn);
        return false;
    }

    bool matchHere(const string& s, const string& p, int si, int pi) {
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

class GreedySolution {
    public:
    bool isMatch(const string& s, const string& p) {
        int si = 0;
        int pi = 0;
        int sn = s.length();
        int pn = p.length();
        int last_si = -1;
        int lastStar = -1;
        while (si < sn) {
            if (pi < pn && (p[pi] == '?' || p[pi] == s[si])) {
                ++pi;
                ++si;
            }
            else if (pi < pn && p[pi] == '*') {
                last_si = si + 1;
                lastStar = pi++;
            }
            else if (lastStar != -1) {
                pi = lastStar;
                si = last_si;
            }
            else {
                return false;
            }
        }
        while (pi < pn && p[pi] == '*') {
            ++pi;
        }
        return pi == pn;
    }
};

class DpSolution {
    private:
        vector<vector<int>> d_memo;
    public:
    bool matchHere(const string& s, const string& p, int si, int pi) {
        int sn = s.length();
        int pn = p.length();
        if (pi == pn) {
            return si == sn;
        }
        if (si == sn) {
            while (pi < pn) {
                if (p[pi++] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (-1 != d_memo[si][pi]) {
            return d_memo[si][pi];                                    // RETURN
        }
        int result = 0;
        if (p[pi] == '?' || p[pi] == s[si]) {
            result = matchHere(s, p, si + 1, pi + 1);
        }
        else if (p[pi] == '*') {
            result = matchHere(s, p, si, pi + 1) ||
                     matchHere(s, p, si + 1, pi);
        }
        d_memo[si][pi] = result;
        return result;
    }
    bool isMatch(const string& s, const string& p) {
        int sn = s.length();
        int pn = p.length();
        d_memo.resize(sn);
        for (int i = 0; i < sn; ++i) {
            d_memo[i].resize(pn, -1);
        }
        bool result = matchHere(s, p, 0, 0);
        //cout << d_memo << endl;
        return result;
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
        { 27,               "abc",       "a*bc",  true },
        { 28,            "abcabc",        "c?*", false },
        { 29,            "abcabc",       "a?*c",  true },
        { 30,           "abcdabc",     "a*d?*c",  true },
        { 31, "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*", true },
        { 32, "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "*aa*ba*a*bb*aa*ab*a*aaaaaa*a*aaaa*bbabb*b*b*aaaaaaaaa*a*ba*bbb*a*ba*bb*bb*a*b*bb", false },
    };
    int NUM_CASES = sizeof(TEST_CASES) / sizeof(TEST_CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n         = TEST_CASES[i].n;
        const string& s         = TEST_CASES[i].s;
        const string& p         = TEST_CASES[i].p;
        bool          expected  = TEST_CASES[i].match;
        cout << "Test case " << n << "\t... ";
        //RecursiveSolution sol;
        GreedySolution    sol;
        //DpSolution        sol;
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