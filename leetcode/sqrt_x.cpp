// Implement int sqrt(int x).
// Compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
        // invariant: the search range is [left, right]
        int left = 0, right = x;
        while (left <= right) {
            int64_t mid  = left + 0.5 * (right - left);
            int64_t mid2 = mid * mid;
            if (mid2 <= x) {
                left = mid + 1;
            } else {    // mid2 > x
                right = mid - 1;
            }
        }
        return left - 1;
    }
};
