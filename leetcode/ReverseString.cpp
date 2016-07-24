// Write a function that takes a string as input and
// returns the string reversed.
// Example:
// Given s = "hello", return "olleh".

class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            std::swap(s[i], s[n - 1 - i]);
        }
        return s;
    }
};
