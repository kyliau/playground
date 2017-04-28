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
  private:
    void reverse(string& s, int start, int end) {
        int n = end - start;
        for (int i = 0; i < n / 2; ++i) {
            std::swap(s[start++], s[--end]);
        }
    }

  public:
    void reverseWords(string& s) {
        int n = s.length();
        reverse(s, 0, n);
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                reverse(s, start, i);
                start = i + 1;
            }
        }
        reverse(s, start, n);
    }
};

int main() {
    const struct {
        int    n;
        string s;
        string expected;
    } CASES[] = {
        { 1, "foobar", "foobar" },
        { 2, "foo bar", "bar foo" },
        { 3, "the sky is blue", "blue is sky the" },
        { 4, " foo   bar ", "bar foo" },
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