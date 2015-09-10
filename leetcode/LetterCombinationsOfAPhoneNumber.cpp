// Given a digit string, return all possible letter combinations that the number could represent.
// Example
// Input : Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

const string keypad[] = {
    "0", "1", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};
class Solution {
public:
    void helper(vector<string> *v, string *result, const string& digits, int index) {
        if (index == digits.size()) {
            v->emplace_back(*result);
            return;
        }
        for (char c : keypad[digits[index] - '0']) {
            (*result)[index] = c;
            helper(v, result, digits, index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.empty()) {
            return v;
        }
        string result(digits.size(), 0);
        helper(&v, &result, digits, 0);
        return v;
    }
};
