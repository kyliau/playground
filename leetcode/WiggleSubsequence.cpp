// A sequence of numbers is called a wiggle sequence if the differences between
// successive numbers strictly alternate between positive and negative.
// The first difference (if one exists) may be either positive or negative.
// A sequence with fewer than two elements is trivially a wiggle sequence.
// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
// (6,-3,5,-7,3) are alternately positive and negative.
// In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first
// because its first two differences are positive and the second because its
// last difference is zero.
// Given a sequence of integers, return the length of the longest subsequence
// that is a wiggle sequence. A subsequence is obtained by deleting some number
// of elements (eventually, also zero) from the original sequence, leaving the
// remaining elements in their original order.
// Examples:
//  Input: [1,7,4,9,2,5]
//  Output: 6
//  The entire sequence is a wiggle sequence.
//  Input: [1,17,5,10,13,15,10,5,16,8]
//  Output: 7
//  There are several subsequences that achieve this length.
//  One is [1,17,10,13,10,16,8].
//  Input: [1,2,3,4,5,6,7,8,9]
//  Output: 2
//  Follow up:
//  Can you do it in O(n) time?

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(const vector<int>& nums) {
        enum DIRECTION { UNDEFINED, UP, DOWN };
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int prev = nums[i];
            int length = 1;
            DIRECTION d = UNDEFINED;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (UP == d && nums[j] < prev) {
                    d = DOWN;
                    prev = nums[j];
                    ++length;
                }
                else if (DOWN == d && nums[j] > prev) {
                    d = UP;
                    prev = nums[j];
                    ++length;
                }
                else if (UNDEFINED == d && nums[j] != prev) {
                    d = nums[j] > prev ? UP : DOWN;
                    prev = nums[j];
                    ++length;
                }
            }
            maxLength = std::max(maxLength, length);
        }
        return maxLength;
    }
};

int main() {
    const struct {
        int         n;
        vector<int> v;
        int         expected;
    } CASES[] = {
        {  1, {                   1, 7, 4, 9, 2, 5 }, 6 },
        {  2, { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }, 7 },
        {  3, {          1, 2, 3, 4, 5, 6, 7, 8, 9 }, 2 },
        {  4, {                   1, 2, 3, 2, 3, 2 }, 5 },
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        auto& v        = CASES[i].v;
        int   expected = CASES[i].expected;
        Solution s;
        int result = s.wiggleMaxLength(v);
        cout << "Test case " << (n < 10 ? " " : "") << n << " ... ";
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