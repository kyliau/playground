class Solution {
  public:
    bool detectCapitalUse(const string& word) {
        if (word.empty() || 1 == word.length()) {
            return true;
        }
        bool firstCharUpper  = std::tolower(word[0]) != word[0];
        bool secondCharUpper = std::tolower(word[1]) != word[1];
        bool upperOnly = firstCharUpper && secondCharUpper;
        bool lowerOnly = !firstCharUpper;
        for (int i = 1; i < word.length(); ++i) {
            char c = word[i];
            bool isLower = std::tolower(c) == c;
            if (isLower && upperOnly || lowerOnly && !isLower || !secondCharUpper && !isLower) {
                return false;
            }
        }
        return true;
    }
};