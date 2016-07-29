// Given a positive integer num, write a function which
// returns True if num is a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.
// Example 1:
// Input: 16
// Returns: True
// Example 2:
// Input: 14
// Returns: False

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = 0.5 * num + 1;
        while (left <= right) {
            long long mid = left + (right - left) * 0.5;
            long long square = mid * mid;
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
