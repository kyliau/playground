#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// copied from http://en.cppreference.com/w/cpp/algorithm/lower_bound
template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
        if (*it < value) {
            first = ++it; 
            count -= step + 1; 
        }
        else {
            count = step;
        }
    }
    return first;
}

// my simple and naive implementation
typedef vector<int>::const_iterator ConstIt;
ConstIt lower_bound(ConstIt first, ConstIt last, int value)
{
    while (first < last) {
        mid = first + std::distance(first, last) / 2;
        if (*mid >= value) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return first;
}

int main()
{
    std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
 
    auto lower = std::lower_bound(data.begin(), data.end(), 4);
    auto upper = std::upper_bound(data.begin(), data.end(), 4);
 
    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));
}
