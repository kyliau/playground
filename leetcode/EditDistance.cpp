// Given two words word1 and word2, find the minimum number of steps required
// to convert word1 to word2. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minDistance(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; ++i) {
            d[i][0] = i;    // deletion
        }
        for (int j = 0; j < n + 1; ++j) {
            d[0][j] = j;    // insertion
        }
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1];
                }
                else {
                    int insertion    = 1 + d[i - 1][j];
                    int deletion     = 1 + d[i][j - 1];
                    int substitution = 1 + d[i - 1][j - 1];
                    d[i][j] = std::min(std::min(insertion, deletion),
                                       substitution);
                }
            }
        }
        return d[m][n];
    }
};

int main() {
    const struct {
        int    n;
        string word1;
        string word2;
        int    expected;
    } CASES[] = {
        {  1,   "foo",   "bar", 3 },
        {  2,      "",   "abc", 3 },
        {  3,   "abc",   "abc", 0 },
        {  4, "aaabb",   "aaa", 2 },
        {  5,   "aaa", "aaabb", 2 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        const int n        = CASES[i].n;
        auto&     word1    = CASES[i].word1;
        auto&     word2    = CASES[i].word2;
        const int expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution s;
        int result = s.minDistance(word1, word2);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    }
    return 0;
}
