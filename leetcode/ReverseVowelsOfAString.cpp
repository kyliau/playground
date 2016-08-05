// Write a function that takes a string as input
// and reverse only the vowels of a string.
// Example 1:
// Given s = "hello", return "holle".
// Example 2:
// Given s = "leetcode", return "leotcede".
// Note:
// The vowels does not include the letter "y".

class Solution {
private:
    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                std::swap(s[left++], s[right--]);
            } else if (isVowel(s[left])) {
                --right;
            } else if (isVowel(s[right])) {
                ++left;
            } else {
                ++left;
                --right;
            }
        }
        return s;
    }
};
