class Solution {
  public:
    int numDecodings(const string& s) {
        if (s.empty()) {
            return 0;
        }
        const int n = s.length();
        vector<int> v(n + 1, 0);
        v[n]     = 1;
        v[n - 1] = s.back() == '0' ? 0 : 1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }
            v[i] = v[i + 1];
            if (std::stoi(s.substr(i, 2)) <= 26) {
                v[i] += v[i + 2];
            }
        }
        return v[0];
    }
};