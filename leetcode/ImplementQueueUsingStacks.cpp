// Implement the following operations of a queue using stacks.
// push(x) -- Push element x to the back of queue.
// pop()   -- Removes the element from in front of queue.
// peek()  -- Get the front element.
// empty() -- Return whether the queue is empty.

class Queue {
private:
    stack<int> d_in;
    stack<int> d_out;
    void transferElementsFromInToOut() {
        assert(d_out.empty());
        while(!d_in.empty()) {
            d_out.push(d_in.top());
            d_in.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        d_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (d_out.empty()) {
            transferElementsFromInToOut();
        }
        d_out.pop();
    }

    // Get the front element.
    int peek(void) {
        if (d_out.empty()) {
            transferElementsFromInToOut();
        }
        return d_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return d_in.empty() && d_out.empty();
    }
};
