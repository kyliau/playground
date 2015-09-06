// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        auto aIt = a.crbegin();
        auto bIt = b.crbegin();
        int carry = 0;
        string result;
        while (aIt != a.crend() || bIt != b.crend()) {
            int aVal = (aIt == a.crend() ? 0 : *aIt++ - '0');
            int bVal = (bIt == b.crend() ? 0 : *bIt++ - '0');
            int val = aVal + bVal + carry;
            carry = val / 2;
            result = (char)((val % 2) + '0') + result;
        }
        if (carry) {
            result = '1' + result;
        }
        return result;
    }
};
