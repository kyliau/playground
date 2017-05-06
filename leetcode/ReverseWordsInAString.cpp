// Given an input string, reverse the string word by word.
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Clarification:
// What constitutes a word?
// - A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// - Yes. However, your reversed string should not contain leading or trailing
//   spaces.
// How about multiple spaces between two words?
// - Reduce them to a single space in the reversed string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    void reverseWords(string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            std::swap(s[i], s[n - i - 1]);
        }
        int i = 0;  // index to write the character
        int j = 0;
        while (j < n) {
            // Find the first non-space character
            while (j < n && s[j] == ' ') {
                ++j;
            }
            int start = j;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            int end = j - 1;
            if (start <= end && i > 0) {
                s[i++] = ' ';
            }
            while (i < start) {
                s[i++] = s[end--];
            }
            i = end + 1;
            while (start < end) {
                std::swap(s[start++], s[end--]);
            }
        }
        s.resize(i);
    }
};

int main() {
    const struct {
        int    n;
        string s;
        string expected;
    } CASES[] = {
        { 1, "foobar", "foobar" },
        { 2, " foobar", "foobar" },
        { 3, "foobar ", "foobar" },
        { 4, "foo bar", "bar foo" },
        { 5, "the sky is blue", "blue is sky the" },
        { 6, " foo   bar ", "bar foo" },
        { 7, "   ", "" },
        { 8, "  the    sky is     blue   ", "blue is sky the" },
        { 9, "a b", "b a" },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n        = CASES[i].n;
        string        s        = CASES[i].s;
        const string& expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution sol;
        sol.reverseWords(s);
        if (s == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect '" << expected << "' but got '" << s << "')";
        }
        cout << endl;
    }
    return 0;
}