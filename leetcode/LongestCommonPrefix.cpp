// Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        for (size_t i = 1; i < strs.size(); ++i) {
            const string& prev = strs[i - 1];
            string& curr       = strs[i];
            size_t minLength   = min(prev.size(), curr.size());
            for (size_t j = 0; j < minLength; ++j) {
                if (prev[j] != curr[j]) {
                    minLength = j;
                }
            }
            curr.erase(minLength);
        }
        return strs.back();
    }
};
