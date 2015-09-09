// Implement the following operations of a stack using queues.
// push(x) -- Push element x onto stack.
// pop()   -- Removes the element on top of the stack.
// top()   -- Get the top element.
// empty() -- Return whether the stack is empty.

class Stack {
private:
    queue<int> d_queue;
    bool d_lastElementIsFirst;
    void makeLastElementFirst() {
        int size = d_queue.size() - 1;
        for (int i = 0; i < size; ++i) {
            d_queue.push(d_queue.front());
            d_queue.pop();
        }
        d_lastElementIsFirst = true;
    }
public:
    Stack() : d_lastElementIsFirst(false) {}
    
    // Push element x onto stack.
    void push(int x) {
        if (d_lastElementIsFirst) {
            d_queue.push(d_queue.front());
            d_queue.pop();
            d_lastElementIsFirst = false;
        }
        d_queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!d_lastElementIsFirst) {
            makeLastElementFirst();
        }
        d_queue.pop();
        d_lastElementIsFirst = false;
    }

    // Get the top element.
    int top() {
        if (!d_lastElementIsFirst) {
            makeLastElementFirst();
        }
        return d_queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return d_queue.empty();
    }
};
