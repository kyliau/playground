// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
private:
    bool findMedian(double             *median,
                    const vector<int>&  v1,
                    const vector<int>&  v2) {
        // Find the median in 'v1', and return true if found. Otherwise return
        // false.
        // For now, this only works if v1.size + v2.size is odd
        int n1 = v1.size();
        int n2 = v2.size();
        //bool even = (n1 + n2) % 2 == 0;
        int target  = n1 + 0.5 * (n2 - n1);
        int l  = 0;
        int r  = n1;
        while (l < r) { // search range is [l, r) in v1
            int mid = l + 0.5 * (r - l);
            int more = target - mid;
            if (more > n2 || (n2 > 0 && v2[more - 1] > v1[mid])) {
                l = mid + 1;
            }
            else if (more < 0 || (more < n2 && v2[more] < v1[mid])) {
                r = mid;
            }
            else {
                *median = v1[mid];
                return true;
            }
        }
        return false;
    }

public:
    double findMedianSortedArrays(const vector<int>& nums1,
                                  const vector<int>& nums2) {
        double median = 0;
        //if ((nums1.size() + nums2.size()) % 2 == 0) { return 99; }
        if (!findMedian(&median, nums1, nums2)) {
            bool result = findMedian(&median, nums2, nums1);
            assert(result);
        }
        return median;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v1;
        vector<int> v2;
        double      median;
    } CASES[] = {
        {  1, {    1, 3, 5, 7 }, {            2, 4, 6 },   4 },
        {  2, {       2, 4, 6 }, {         1, 3, 5, 7 },   4 },
        {  3, {          0, 1 }, {               2, 2 }, 1.5 },
        {  4, {          1, 2 }, {               0, 2 }, 1.5 },
        {  5, {          1, 2 }, {               3, 4 }, 2.5 },
        {  6, { 1, 2, 3, 4, 5 }, {                    },   3 },
        {  7, {               }, {      1, 2, 3, 4, 5 },   3 },
        {  8, {    1, 2, 3, 4 }, {                    }, 2.5 },
        {  9, {               }, {         1, 2, 3, 4 }, 2.5 },
        { 10, {             1 }, {         2, 3, 4, 5 },   3 },
        { 11, {       1, 3, 4 }, {                  2 }, 2.5 },
        { 12, {             2 }, {            1, 3, 4 }, 2.5 },
        { 13, {      -1, 2, 5 }, { -3, 1, 4, 7, 9, 10 },   4 },
        { 14, {             2 }, {         0, 1, 3, 4 },   2 },
        { 15, {    0, 1, 3, 4 }, {                  2 },   2 },
        { 16, {             1 }, {            2, 3, 4 }, 2.5 },
        { 17, {       2, 3, 4 }, {                  1 }, 2.5 },
        { 18, {             1 }, {   2, 3, 4, 5, 6, 7 },   4 },
        { 19, {    1, 2, 4, 5 }, {                  3 },   3 },
        { 20, {       1, 1, 1 }, {         2, 2, 2, 2 },   2 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int    n        = CASES[i].n;
        auto&  v1       = CASES[i].v1;
        auto&  v2       = CASES[i].v2;
        double expected = CASES[i].median;
        Solution s;
        double result = s.findMedianSortedArrays(v1, v2);
        cout << "Test case " << (n < 10 ? " " : "" ) << n << " ... ";
        if (result == expected) {
            cout << "PASS";
        } else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    }
    return 0;
}