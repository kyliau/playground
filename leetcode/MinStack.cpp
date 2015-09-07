// Design a stack that supports push, pop, top, and retrieving the minimum element
// in constant time.
// push(x)  -- Push element x onto stack.
// pop()    -- Removes the element on top of the stack.
// top()    -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class MinStack {
private:
    stack<pair<int, int>> d_stack;
public:
    void push(int x) {
        int minVal = d_stack.empty() ? x : min(x, d_stack.top().second);
        d_stack.emplace(x, minVal);
    }

    void pop() {
        d_stack.pop();
    }

    int top() {
        return d_stack.top().first;
    }

    int getMin() {
        return d_stack.top().second;
    }
};
