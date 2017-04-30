// You are given an integer array nums and you have to return a new counts
// array. The counts array has the property where counts[i] is the number of
// smaller elements to the right of nums[i].
//
// Example:
//
// Given nums = [5, 2, 6, 1]
//
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

ostream& operator<<(ostream& stream, const vector<int>& v) {
    stream << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << (i == 0 ? "" : ", ") << v[i];
    }
    stream << "]";
    return stream;
}

class Solution {
  private:
    void helper(const vector<int>& nums,
                vector<int>&       count,
                vector<int>&       indices,
                int                l,
                int                r) {
        if (l >= r) {
            return;
        }
        int m = l + (r - l) / 2;    // mid index
        helper(nums, count, indices, l, m);
        helper(nums, count, indices, m + 1, r);

        int i = l;              // index into left subarray
        int j = m + 1;          // index into right subarray
        int k = 0;              // index of insertion position into merge
        int n = r - l + 1;      // size of the merge
        int p = m + 1;
        vector<int> merge(n);

        while (k < n) {
            if (i == m + 1) {
                merge[k++] = indices[j++];
            }
            else if (j == r + 1 || nums[indices[i]] < nums[indices[j]]) {
                while (p <= r && nums[indices[i]] > nums[indices[p]]) {
                    ++p;
                }
                count[indices[i]] += p - m - 1;
                merge[k++] = indices[i++];
            }
            else {
                merge[k++] = indices[j++];
            }
        }

        std::copy(merge.begin(), merge.end(), indices.begin() + l);
    }
  public:
    vector<int> countSmaller(const vector<int>& nums) {
        vector<int> count(nums.size());
        vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            indices[i] = i;
        }
        helper(nums, count, indices, 0, nums.size() - 1);
        assert(is_sorted(indices.begin(), indices.end(), [nums](int x, int y) {
            return nums[x] < nums[y];
        }));
        return count;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v;
        vector<int> e;
    } CASES[] = {
        { 1, { 5, 2, 6, 1 }, { 2, 1, 1, 0 } },
        { 2, { 4, -1, 0, 55, 9, -3, 8, 1, 99, -154, 4, 6, 2, 25, 3 }, {7,2,2,10,8,1,6,1,6,0,2,2,0,1,0} },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n = CASES[i].n;
        auto& v = CASES[i].v;
        auto& e = CASES[i].e;
        cout << "Test case " << n << " ... ";
        Solution s;
        vector<int> r = s.countSmaller(v);
        if (r == e) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << e << " but got " << r << ")";
        }
        cout << endl;
    }
    return 0;
}