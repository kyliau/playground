class Solution {
  public:
    vector<int> grayCode(int n) {
        vector<int> results;
        int count = 1 << n;
        results.reserve(count);
        for (int i = 0; i < count; ++i) {
            results.emplace_back(i ^ (i >> 1));
        }
        return results;
    }
};