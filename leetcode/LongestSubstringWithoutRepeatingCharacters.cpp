// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int i = 0;
        int length = 0;
        int m[128];
        std::fill(m, m + 128, -1);
        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (m[c] >= i) {
                i = m[c] + 1;
            }
            m[c] = j;
            length = std::max(length, j - i + 1);
        }
        return length;
    }
};
