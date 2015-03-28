// queue.h

#ifndef INCLUDED_QUEUE
#define INCLUDED_QUEUE

#include <memory>

template <class TYPE>
class CircularDeque
{
    // DATA
    size_t d_count;
    size_t d_capacity;
    
    
  public:
    // CREATORS
    CircularDeque();
        // Create a 'CircularDeque' object.

    // MANIPULATORS
    TYPE& front();
        // Returns a modifiable reference to the first element in the
        // container.
        // Calling this function on an empty container causes undefined
        // behavior.
    
    TYPE& back();
        // Returns a modifiable reference to the last element in the container.
        // Calling this function on an empty container causes undefined
        // behavior.

    void push_front(const TYPE& value);
        // Inserts a new element at the beginning of the container, right
        // before its current first element. The content of 'value' is copied
        // (or moved) to the inserted element.
        // This effectively increases the container size by one.
    
    void push_back(const TYPE& value);
        // Adds a new element at the end of the container, after its
        // current last element. The content of 'value' is copied (or moved)
        // to the new element.
        // This effectively increases the container size by one.
    
    void pop_front();
    
    void pop_back();
    
    // ACCESSORS
    bool empty() const;
    
    size_t size() const;
    
    const TYPE& front() const;
        // Returns a non-modifiable reference to the first element in the
        // container.
        // Calling this function on an empty container causes undefined
        // behavior.
    
    const TYPE& back() const;
        // Returns a non-modifiable reference to the last element in the
        // container.
        // Calling this function on an empty container causes undefined
        // behavior.
};

// ===========================================================================
//                      INLINE FUNCTION DEFINITIONS
// ===========================================================================

// CREATORS
inline
CircularDeque::CircularDeque()
: d_count(0)
, d_capacity(0)
{
}

// ACCESSORS
inline
bool CircularDeque::empty() const
{
    return (0 == count);
}

inline
size_t CircularDeque::size() const
{
    return count;
}

/*
template <class TYPE>
inline
const TYPE& CircularDeque::front() const
{
    return
}

template <class TYPE>
inline
const TYPE& CircularDeque::back() const
{
    return 
}
*/

#endif
