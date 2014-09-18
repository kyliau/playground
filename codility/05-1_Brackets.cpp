
// Lesson 5 - Stacks and Queues
// Brackets
// Determine whether a given string of parentheses is properly nested.


#include <stack>
int solution(string &S) {
    stack<char> mystack;
    for (char c : S) {
        if (c == '(' || c == '{' || c == '[') {
            mystack.push(c);
        } else {
            if (mystack.empty()) {
                return 0;
            }
            char b = mystack.top();
            mystack.pop();
            if ((b == '(' && c != ')') || (b == '{' && c != '}') ||
                (b == '[' && c != ']')) {
                return 0;
            }
        }
    }
    if (!mystack.empty()) return 0;
    return 1;
}
