#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

// Given a sorted array in which all elements appear twice except one, find the
// element that appears only once.

int findSingleElement(const vector<int>& v, int left, int right) {
    // invariant: search v from [left, right] for the single element
    assert((right - left) % 2 == 0);    // must be odd number of elements
    int mid = 0.5 * (left + right); // mid is the median index
    if (mid == left || (v[mid - 1] != v[mid] && v[mid] != v[mid + 1])) {
        return v[mid];  // found the single element
    }
    if (v[mid - 1] == v[mid]) {
        if (mid % 2 == 0) {
            // search left
            return findSingleElement(v, left, mid - 2);
        } else {
            // search right
            return findSingleElement(v, mid + 1, right);
        }
    }
    // Invariant: v[mid] == v[mid + 1]
    if (mid % 2 == 0) {
        // search right
        return findSingleElement(v, mid + 2, right);
    } else {
        // search left
        return findSingleElement(v, left, mid - 1);
    }
}

int findSingleElement(const vector<int>& v) {
    assert(!v.empty());
    return findSingleElement(v, 0, v.size() - 1);
}

int main() {
    // test cases
    using V = vector<int>;
    V v0 = {1, 1, 2};
    V v1 = {1, 2, 2};
    V v2 = {1};
    V v3 = {1, 1, 2, 2, 3};
    V v4 = {1, 2, 2, 3, 3};
    V v5 = {1, 1, 2, 3, 3};
    V v6 = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    V v7 = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    V v8 = {99, -1, -1, 3, 3, 10, 10, -5, -5, 7, 7, 0, 0, 10, 10};
    V v9 = {-1, -1, 3, 3, 10, 10, -5, -5, 7, 7, 0, 0, 8, 10, 10};
    vector<V> tests = {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9};
    for (const V& v : tests) {
        cout << "Vector = ";
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl
             << "Single element = " << findSingleElement(v)
             << endl << endl;
    }
    return 0;
}
