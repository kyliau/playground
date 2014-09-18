

// Lesson 5 - Stacks and Queues
// Nesting
// Determine whether given string of parentheses is properly nested.

#include <stack>
int solution(string &S) {
    stack<char> mystack;
    for (char c : S) {
        if (c == '(') {
            mystack.push(c);
        } else {
            if (mystack.empty()) {
                return 0;
            }
            mystack.pop();
        }
    }
    if (!mystack.empty()) return 0;
    return 1;
}

