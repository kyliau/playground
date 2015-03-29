// circulardeque.h

#ifndef INCLUDED_CIRCULARDEQUE
#define INCLUDED_CIRCULARDEQUE

#include <algorithm>
#include <memory>

template <class TYPE>
class CircularDeque
{
  public:
    // TYPEDEFS
    typedef TYPE   value_type;
    typedef size_t size_type;

  private:
    typedef std::unique_ptr<TYPE[]> DataPtr;
    // DATA
    size_type d_front;
    size_type d_count;
    size_type d_capacity;
    DataPtr   d_data;

  public:
    // CREATORS
    CircularDeque();
        // Create a 'CircularDeque' object.

    CircularDeque(const CircularDeque& deque);
        // Copy constructor

    CircularDeque& operator=(const CircularDeque& deque);
        // Assignment operator

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
        // Removes the first element in the deque container, effectively
        // reducing its size by one.
        // This destroys the removed element.
        // If the container is not empty, the function never throws exceptions
        // (no-throw guarantee). Otherwise, the behavior is undefined.

    void pop_back();
        // Removes the last element in the deque container, effectively
        // reducing the container size by one.
        // This destroys the removed element.
        // If the container is not empty, the function never throws exceptions
        // (no-throw guarantee).
        // Otherwise, the behavior is undefined.

    void resize(size_type n, value_type value = value_type());
        // Resizes the container so that it contains n elements.
        // If n is smaller than the current container size, the content is
        // reduced to its first n elements, removing those beyond
        // (and destroying them).
        // If n is greater than the current container size, the content is
        // expanded by inserting at the end as many elements as needed to
        // reach a size of n.
        // If 'value' is specified, the new elements are initialized as copies
        // of val, otherwise, they are value-initialized.
        // If n is also greater than the current container capacity, an
        // automatic reallocation of the allocated storage space takes place.
        // Notice that this function changes the actual content of the
        // container by inserting or erasing elements from it.

    void swap(CircularDeque& deque);
        // Exchanges the content of the container by the content of 'deque',
        // which is another vector object of the same type. Sizes may differ.
        // After the call to this member function, the elements in this
        // container are those which were in x before the call, and the
        // elements of 'deque' are those which were in this. All iterators,
        // references and pointers remain valid for the swapped objects.

    void clear() noexcept;
        // Removes all elements from the vector (which are destroyed), leaving
        // the container with a size of 0.
        // A reallocation is not guaranteed to happen, and the vector capacity
        // is not guaranteed to change due to calling this function.

    // ACCESSORS
    bool empty() const;
        // Returns whether the deque container is empty
        // (i.e. whether its size is 0).

    size_type size() const;
        // Returns the number of elements in the deque container.

    size_type capacity() const;
        // Returns the size of the storage space currently allocated for the
        // container, expressed in terms of elements.
        // This capacity is not necessarily equal to the vector size.
        // It can be equal or greater, with the extra space allowing to
        // accommodate for growth without the need to reallocate on each
        // insertion.

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
template <class TYPE>
inline
CircularDeque<TYPE>::CircularDeque()
: d_front(0)
, d_count(0)
, d_capacity(0)
, d_data(nullptr)
{
}

template <class TYPE>
CircularDeque<TYPE>::CircularDeque(const CircularDeque& deque)
{
    DataPtr data(new TYPE[deque.d_capacity]);
    for (size_type i = 0; i < deque.d_capacity; ++i) {
        data[i] = deque.d_data[i];
    }
    d_front    = deque.d_front;
    d_count    = deque.d_count;
    d_capacity = deque.d_capacity;
    d_data     = std::move(data);
}

template <class TYPE>
CircularDeque<TYPE>& CircularDeque<TYPE>::operator=(const CircularDeque& deque)
{
    // note, self assignment not checked
    CircularDeque<TYPE>(deque).swap(*this);
    return *this;
}

// MANIPULATORS
template <class TYPE>
inline
TYPE& CircularDeque<TYPE>::front()
{
    return d_data[d_front];
}

template <class TYPE>
inline
TYPE& CircularDeque<TYPE>::back()
{
    return d_data[(d_front + d_count - 1) % d_capacity];
}

template <class TYPE>
inline
void CircularDeque<TYPE>::push_front(const TYPE& value)
{
    if (d_count == d_capacity) {
        resize(0 == d_capacity ? 1 : d_capacity * 2);
    }
    d_front = (d_front == 0 ? d_capacity - 1 : d_front - 1);
    d_data[d_front] = value;
    ++d_count;
}

template <class TYPE>
inline
void CircularDeque<TYPE>::push_back(const TYPE& value)
{
    if (d_count == d_capacity) {
        resize(0 == d_capacity ? 1 : d_capacity * 2);
    }
    d_data[(d_front + d_count) % d_capacity] = value;
    ++d_count;
}

template <class TYPE>
inline
void CircularDeque<TYPE>::pop_front()
{
    d_front = (d_front + 1 == d_capacity ? 0 : d_front + 1);
    --d_count;
}

template <class TYPE>
inline
void CircularDeque<TYPE>::pop_back()
{
    --d_count;
}

template <class TYPE>
void CircularDeque<TYPE>::resize(size_type n, value_type value)
{
    if (n <= d_count) {
        d_count = n;
        return;                                                       // return
    }

    DataPtr data(new TYPE[n]);
    for (size_type i = 0; i < d_count; ++i) {
        data[i] = d_data[(d_front + i) % d_count];
    }
    for (size_type i = d_count; i < n; ++i) {
        data[i] = value;
    }
    d_front = 0;
    d_capacity = n;
    d_data = std::move(data);
}

template <class TYPE>
inline
void CircularDeque<TYPE>::swap(CircularDeque& deque)
{
    d_data.swap(deque.d_data);
    std::swap(d_front,    deque.d_front);
    std::swap(d_count,    deque.d_count);
    std::swap(d_capacity, deque.d_capacity);
}

template <class TYPE>
inline
void CircularDeque<TYPE>::clear() noexcept
{
    d_count = 0;
}

// ACCESSORS
template <class TYPE>
inline
bool CircularDeque<TYPE>::empty() const
{
    return (0 == d_count);
}

template <class TYPE>
inline
typename CircularDeque<TYPE>::size_type CircularDeque<TYPE>::size() const
{
    return d_count;
}

template <class TYPE>
inline
typename CircularDeque<TYPE>::size_type CircularDeque<TYPE>::capacity() const
{
    return d_capacity;
}

template <class TYPE>
inline
const TYPE& CircularDeque<TYPE>::front() const
{
    return d_data[d_front];
}

template <class TYPE>
inline
const TYPE& CircularDeque<TYPE>::back() const
{
    return d_data[(d_front + d_count - 1) % d_capacity];
}

#endif
