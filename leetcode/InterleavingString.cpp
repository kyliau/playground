// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool isInterleave(const string& s1,
                      const string& s2,
                      const string& s3) {
        const int l1 = s1.length();
        const int l2 = s2.length();
        const int l3 = s3.length();
        if (l1 + l2 != l3) {
            return false;
        }
        vector<vector<bool>> v(l1 + 1, vector<bool>(l2 + 1));

        v[0][0] = true;

        for (int i = 1; i < l1 + 1; ++i) {
            v[i][0] = v[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for (int j = 1; j < l2 + 1; ++j) {
            v[0][j] = v[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i < l1 + 1; ++i) {
            for (int j = 1; j < l2 + 1; ++j) {
                v[i][j] = (v[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                          (v[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return v[l1][l2];
    }
};

int main() {
    const struct {
        int    n;
        string s1;
        string s2;
        string s3;
        bool   expected;
    } CASES[] = {
        { 1, "see", "saw", "seesaw",  true },
        { 2, "saw", "see", "seesaw",  true },
        { 3, "see", "saw", "sseaew",  true },
        { 4, "see", "saw", "sesawe",  true },
        { 5, "see", "saw", "sseewa", false },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int     n        = CASES[i].n;
        const string& s1       = CASES[i].s1;
        const string& s2       = CASES[i].s2;
        const string& s3       = CASES[i].s3;
        const bool    expected = CASES[i].expected;
        Solution s;
        cout << "Test case " << n << " ... ";
        bool result = s.isInterleave(s1, s2, s3);
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