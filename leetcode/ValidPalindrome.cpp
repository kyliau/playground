// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int left  = 0;
        int right = s.size() - 1;
        while (left < right) {
            char l = tolower(s[left]);
            char r = tolower(s[right]);
            while (left < right && !isalnum(l)) {
                ++left;
                l = tolower(s[left]);
            }
            while (left < right && !isalnum(r)) {
                --right;
                r = tolower(s[right]);
            }
            if (l != r) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
