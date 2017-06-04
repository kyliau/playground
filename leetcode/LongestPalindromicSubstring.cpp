// Given a string s, find the longest palindromic substring in s. You may
// assume that the maximum length of s is 1000.
//
// Example:
// Input  : "babad"
// Output : "bab"
// Note   : "aba" is also a valid answer.
//
// Example:
// Input  : "cbbd"
// Output : "bb"

#include <iostream>
#include <string>
using namespace std;

class Solution {
  private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
  public:
    string longestPalindrome(const string& s) {
        int start  = 0;
        int length = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if (isPalindrome(s, i, j) && j - i + 1 > length) {
                    length = j - i + 1;
                    start  = i;
                }
            }
        }
        return s.substr(start, length);
    }
};

int main() {
    const struct {
        int    n;
        string s;
        string e;   // expected
    } CASES[] = {
        { 1, "babad", "bab" },
        { 2, "cbbd", "bb" },
        { 3, "a", "a" },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n = CASES[i].n;
        const string& s = CASES[i].s;
        const string& e = CASES[i].e;
        Solution sol;
        cout << "Test case " << n << " ... ";
        string result = sol.longestPalindrome(s);
        if (result == e) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << e << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}