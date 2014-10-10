
// Lesson 5 - Stacks and Queues
// StoneWall
// Cover "Manhattan skyline" using the minimum number of rectangles.

#include <stack>
int solution(vector<int> &H) {
    int result = 0;
    stack<int> s;
    for (int h : H) {
        while (!s.empty() && s.top() > h) {
            s.pop();
        }
        if (s.empty() || s.top() != h) {
            result++;
            s.push(h);
        }
    }
    return result;
}
