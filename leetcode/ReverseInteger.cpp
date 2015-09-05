// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321
// Did you notice that the reversed integer might overflow?
// Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows.
// Assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        int64_t result = 0;
        int y = x < 0 ? -x : x;
        while (y > 0) {
            int64_t prev = result;
            result = result * 10 + (y % 10);
            if (result > INT_MAX || (x < 0 && -result < INT_MIN)) {
                return 0;
            }
            y /= 10;
        }
        return x < 0 ? -result : result;
    }
};
