// Given a string and an integer k, you need to reverse the first k characters
// for every 2k characters counting from the start of the string.
// If there are less than k characters left, reverse all of them.
// If there are less than 2k but greater than or equal to k characters, then
// reverse the first k characters and left the other as original.
//
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
//
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string reverseStr(string s, int k) {
        int i = 0;
        int n = s.length();
        while (i < n) {
            int start = i;
            for (int j = 0; j < k && i < n; ++j) {
                ++i;
            }
            int end = i - 1;
            while (start < end) {
                std::swap(s[start++], s[end--]);
            }
            for (int j = 0; j < k && i < n; ++j) {
                ++i;
            }
        }
        return s;
    }
};

int main() {
    const struct {
        int    n;
        string s;
        int    k;
        string expected;
    } CASES[] = {
        { 1, "abcdefg", 2, "bacdfeg" },
        { 2, "abcdefg", 1, "abcdefg" },
        { 3, "abcdefg", 3, "cbadefg" },
        { 4, "abcdefg", 4, "dcbaefg"}
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int           n        = CASES[i].n;
        string        s        = CASES[i].s;
        int           k        = CASES[i].k;
        const string& expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution sol;
        string result = sol.reverseStr(s, k);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect '" << expected << "' but got '" << s << "')";
        }
        cout << endl;
    }
    return 0;
}