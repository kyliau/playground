class Solution {
  public:
    vector<string> findWords(const vector<string>& words) {
        vector<string> results;
        vector<int> v = {
            2, 3, 3, 2, 1,
            2, 2, 2, 1, 2,
            2, 2, 3, 3, 1,
            1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3
        };
        for (const string& w : words) {
            int row = v[std::tolower(w[0]) - 'a'];
            int flag = true;
            for (int i = 1; i < w.length() && flag; ++i) {
                if (v[std::tolower(w[i]) - 'a'] != row) {
                    flag = false;
                }
            }
            if (flag) {
                results.emplace_back(w);
            }
        }
        return results;
    }
};