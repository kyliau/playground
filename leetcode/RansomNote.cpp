// Given an arbitrary ransom note string and another string containing letters
// from all the magazines, write a function that will return true if the ransom
// note can be constructed from the magazines ; otherwise, it will return false.
//
// Each letter in the magazine string can only be used once in your ransom note.
//
// Note:
// You may assume that both strings contain only lowercase letters.
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

#include <string>
#include <assert.h>
using namespace std;

class Solution {
  public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        int count[26] = { 0 };
        for (char c : magazine) {
            ++count[c - 'a'];
        }
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    assert(s.canConstruct("aaabbbccc", "abcdabcdabcd"));
    return 0;
}