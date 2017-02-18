// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

ostream& operator<<(ostream& stream, const vector<string>& v) {
    stream << "[ ";
    for (int i = 0; i < v.size(); ++i) {
        stream << (i == 0 ? "" : ", ") << v[i];
    }
    cout << " ]";
    return stream;
}

class Solution {
public:
    void generate(vector<string>& r,
                  string&         s,
                  int             p,
                  int             numOpen,
                  int             numCompleted) {
        int n = s.length();
        if (p == n) {
            r.emplace_back(s);
            return;
        }
        if (numOpen > 0) {
            s[p] = ')';
            generate(r, s, p + 1, numOpen - 1, numCompleted + 1);
        }
        if (numOpen + numCompleted < n / 2) {
            s[p] = '(';
            generate(r, s, p + 1, numOpen + 1, numCompleted);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) {
            return result;
        }
        string s(n * 2, ' ');
        generate(result, s, 0, 0, 0);
        return result;
    }
};

int main() {
    struct {
        int            n;
        vector<string> expected;
    } CASES[] = {
        { 1, {"()"          } },
        { 2, {"()()", "(())" } },
        { 3, {"((()))", "(()())", "()(())", "()()()", "(())()"} },
        { 4, {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"} },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto& expected = CASES[i].expected;
        Solution s;
        auto result = s.generateParenthesis(n);
        std::sort(result.begin(), result.end());
        std::sort(expected.begin(), expected.end());
        cout << "Test case " << n << "\t... ";
        if (result == expected) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl
                 << "Expected\n" << expected << "\nbut got\n" << result << endl;
        }
    }
    return 0;
}