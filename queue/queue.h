// queue.h

#ifndef INCLUDED_QUEUE
#define INCLUDED_QUEUE

#include <unique_ptr>

template <class TYPE>
class Queue
{
    // DATA
    size_t count, capacity;
    
    
  public:
    // CREATORS
    
    // MANIPULATORS
    TYPE& front();
    
    TYPE& back();
    
    void push_front(const TYPE& value);
    
    void push_back(const TYPE& value);
        // Adds a new element at the end of the deque container,
        // after its current last element.
        // The content of val is copied (or moved) to the new element.

This effectively increases the container size by one.
    
    void pop_front();
    
    void pop_back();
    
    // ACCESSORS
    bool empty() const;
    
    size_t size() const;
    
    const TYPE& front() const;
    
    const TYPE& back() const;
    
    
  
};

#endif
