// Given an integer array nums, return the number of range sums that lie in
// [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between
// indices i and j (i ≤ j), inclusive.
//
// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
// Example:
// Given nums = [-2, 5, -1], lower = -2, upper = 2,
// Return 3.
// The three ranges are : [0, 0], [2, 2], [0, 2] and
// their respective sums are: -2, -1, 2.

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& stream, vector<T>& v) {
    stream << "[";
    for (int i = 0; i < v.size(); ++i) {
        stream << (i == 0 ? "" : ", ") << v[i];
    }
    stream << "]";
    return stream;
}

class Solution {
  private:
    int rangeSum(vector<long long>& sums, int lower, int upper, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return (lower <= sums[l] && sums[l] <= upper) ? 1 : 0;
        }
        int m = l + (r - l) / 2;
        int result = rangeSum(sums, lower, upper, l, m) +
                     rangeSum(sums, lower, upper, m + 1, r);

        int i = l;
        int j = m + 1;
        int k = 0;
        int n = r - l + 1;
        int p = m + 1;
        int q = m + 1;
        vector<long long> merge(n);

        while (k < n) {
            if (i == m + 1) {
                merge[k++] = sums[j++];
            }
            else if (j == r + 1 || sums[i] < sums[j]) {
                while (p < r && sums[p] - sums[i] < lower) {
                    ++p;
                }
                while (q <= r && sums[q] - sums[i] <= upper) {
                    ++q;
                }
                result += q - p;
                merge[k++] = sums[i++];
            }
            else {
                merge[k++] = sums[j++];
            }
        }

        std::copy(merge.begin(), merge.end(), sums.begin() + l);
        return result;
    }
  public:
    int countRangeSum(const vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return 0;
        }
        vector<long long> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        cout << sums << endl;
        int result = rangeSum(sums, lower, upper, 0, nums.size() - 1);
        assert(is_sorted(sums.begin(), sums.end()));
        return result;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> nums;
        int         lower;
        int         upper;
        int         expected;
    } CASES[] = {
        { 1, { -2, 5, -1 }, -2, 2, 3 },
        { 2, { 1, 2, 3 }, 0, 5, 5 },
        { 3, { -1, 1 }, 0, 0, 1 },
        { 4, { 0 }, 0, 0, 1 },
        { 5, { 0, -1, -2, 4, 58, 54, 62, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, -1, 0, 1, 2, 4, 2, 8, 6 }, -2, 2, 18 },
        { 6, { 2147483647, -2147483648, -1, 0 }, -1, 0, 4 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto& nums     = CASES[i].nums;
        int   lower    = CASES[i].lower;
        int   upper    = CASES[i].upper;
        int   expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution s;
        int result = s.countRangeSum(nums, lower, upper);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}