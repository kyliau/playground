#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).
// Example 1:
//  nums1 = [1, 3]
//  nums2 = [2]
//  The median is 2.0
// Example 2:
//  nums1 = [1, 2]
//  nums2 = [3, 4]
//  The median is (2 + 3)/2 = 2.5

class Solution {
private:
    int isMedian(const vector<int>& v,
                 const vector<int>& other,
                 int                index) {
        // Return 0 if v[index] is the median,
        // otherwise return 1 if v[index] is to the right of the median,
        // otherwise return -1 if v[index] is to the left of the median.

        int m = v.size();
        int n = other.size();
        // I have 'index' number elements to my left, I need
        // (n + m - 1) / 2 - index more elements to be a median
        int otherIndex = (m + n - 1) / 2 - index;
        cout << "index = " << index << ", otherIndex = " << otherIndex << endl;
        if (otherIndex < 0) {
            return 1;
        }
        if (otherIndex > n) {
            return -1;
        }
        if (otherIndex > 0 && v[index] < other[otherIndex - 1]) {
            return -1;
        }
        if (otherIndex < n && v[index] > other[otherIndex]) {
            return 1;
        }
        return 0;
    }
    
    int findMedian(const vector<int>& v,
                   const vector<int>& other) {
        // Return the index of the median if median is in 'v',
        // otherwise return -1
        int left = 0;
        int right = v.size();
        while (left < right) {
            int mid = left + 0.5 * (right - left);
            cout << "Test if v[" << mid << "] = " << v[mid] << " is median"
                 << endl;
            int r = isMedian(v, other, mid);
            cout << "Is v[" << mid << "] median? " << r << endl;
            if (r == 0) {
                return mid;
            } else if (r > 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    int findMedianRight(const vector<int>& v,
                        const vector<int>& other,
                        int                index) {
        int m = v.size();
        int n = other.size();
        if ((m + n) % 2 == 1) {
            return v[index];
        }
        int otherIndex = (m + n - 1) / 2 - index;
        if (otherIndex < 0 || otherIndex >= n) {
            return v[index + 1];
        }
        int candidate1 = other[otherIndex];
        if (index == m - 1) {
            return candidate1;
        }
        int candidate2 = v[index + 1];
        return std::min(candidate1, candidate2);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int median, medianRight;
        int index = findMedian(nums1, nums2);
        cout << "index = " << index << endl;
        if (index >= 0) {
            median = nums1[index];
            cout << "Median is in nums1, median = " << median << endl;
            medianRight = findMedianRight(nums1, nums2, index);
        } else {
            index = findMedian(nums2, nums1);
            median = nums2[index];
            cout << "Median is in nums2, median = " << median << endl;
            medianRight = findMedianRight(nums2, nums1, index);
        }
        return median + 0.5 * (medianRight - median);
    }
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <test file>" << endl;
        return 0;
    }
    ifstream inFile(argv[1]);
    int count = 0;
    string s;
    while (std::getline(inFile, s)) {
        istringstream iss(s);
        int x;
        vector<int> v1, v2;
        while (iss >> x) {
            v1.emplace_back(x);
        }
        std::getline(inFile, s);
        iss.ignore(256, '\n');
        iss.clear();
        iss.str(s);
        while (iss >> x) {
            v2.emplace_back(x);
        }
        cout << "Test case " << ++count << endl;
        cout << "v1 = ";
        copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        cout << "v2 = ";
        copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        Solution sol;
        double median = sol.findMedianSortedArrays(v1, v2);
        cout << "Median is " << median << endl;
        double e;
        inFile >> e;
        inFile.ignore(256, '\n');
        if (median != e) {
            cout << "Expected " << e << " but got " << median << endl;
            return 1;
        }
        cout << endl;
    }
    cout << "All test cases passed!" << endl;
    return 0;
}
