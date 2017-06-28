class Solution {
  public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> v(s.size() + 1, false);
        v[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v.back();
    }
};