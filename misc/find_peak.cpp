#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int findPeak(const vector<int>& v) {
    // Given an ascending then descending sequence 'v', return the index of the
    // maximum element.

    if (v.empty()) {
        return -1;
    }
    int left  = 0;
    int right = v.size() - 1;

    while (left < right) {
        // Invariant: Search space is always in the range [left, right] where
        // both left and right endpoints are included
        int mid = left + (right - left) * 0.5;
        if (v[mid] < v[mid + 1]) {
            // discard the 'mid' element and everything to the left of 'mid'
            left = mid + 1;
        } else {
            // v[mid] > v[mid + 1]
            // Keep 'mid' element but discard everything to the right of 'mid'
            right = mid;
        }
    }

    return left;
}

int main() {

    vector<vector<int>> cases = {
        {},
        {1},
        {1,2},
        {2,1},
        {1,2,3},
        {3,2,1},
        {1,2,3,1},
        {1,2,3,2,1}
    };
    for (const auto& v : cases) {
        int index = findPeak(v);
        cout << "The peak element of [";
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        cout << "] is ";
        if (index == -1) {
            cout << "not found.";
        } else {
            cout << v[index];
        }
        cout << endl;
    }
    return 0;
}
