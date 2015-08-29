// Given two strings s and t, write a function to determine if t is an anagram of s.
// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.
// Note:
// You may assume the string contains only lowercase alphabets.

// O(n) solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int map[26] = { 0 };
        for (char c : s) {
            ++map[c - 'a'];
        }
        for (char c : t) {
            if (--map[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
