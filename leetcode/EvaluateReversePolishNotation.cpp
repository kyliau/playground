// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another
// expression.
// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <assert.h>
using namespace std;

class Solution {
  public:
    int evalRPN(const vector<string>& tokens) {
        std::stack<int> s;
        for (const string& t : tokens) {
            if (t == "+") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x + y);
            }
            else if (t == "-") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y - x);
            }
            else if (t == "*") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x * y);
            }
            else if (t == "/") {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y / x);
            }
            else {
                int x = std::stoi(t);
                s.push(x);
            }
        }
        return s.top();
    }
};

int main() {
    const struct {
        int            n;
        vector<string> tokens;
        int            expected;
    } CASES[] = {
        { 1, { "2", "1", "+", "3", "*" }, 9 },
        { 2, { "4", "13", "5", "/", "+" }, 6 },
        { 3, { "1", "3", "-" }, -2 },
        { 4, { "3", "1", "/" }, 3 },
        { 5, { "2", "1", "+", "4", "-" }, -1 },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int                   n        = CASES[i].n;
        const vector<string>& tokens   = CASES[i].tokens;
        int                   expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution s;
        int result = s.evalRPN(tokens);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}