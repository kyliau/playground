// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
// Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return addDigits(result);
    }
};

// O(1) solution
// https://en.wikipedia.org/wiki/Digital_root
// return 1 + ((n - 1) % 9)
