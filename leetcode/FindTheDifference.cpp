class Solution {
  public:
    char findTheDifference(const string& s, const string& t) {
        int count[26] = { 0 };
        for (char c : s) {
            ++count[c - 'a'];
        }
        for (char c : t) {
            --count[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                return i + 'a';
            }
        }
        return 0;
    }
};