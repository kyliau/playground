// Given an integer, write a function to determine if it is a power of three.

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n == 1 || (n > 0 && n % 3 == 0 && isPowerOfThree(n / 3));
    }
};