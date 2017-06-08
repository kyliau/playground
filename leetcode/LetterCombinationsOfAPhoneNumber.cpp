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

class Solution {
  public:
    vector<string> letterCombinations(const string& digits) {
        static const vector<string> digitMap = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
        };
        vector<string> results;
        for (char d : digits) {
            const string& word = digitMap[d - '0'];
            if (results.empty()) {
                for (char c : word) {
                    results.emplace_back(1, c);
                }
            }
            else if (!word.empty()) {
                int count = results.size();
                for (int i = 0; i < count; ++i) {
                    results[i].push_back(word[0]);
                }
                for (int i = 1; i < word.size(); ++i) {
                    for (int j = 0; j < count; ++j) {
                        results.emplace_back(results[j]);
                        results.back().back() = word[i];
                    }
                }
            }            
        }
        return results;
    }
};
