class Solution {
  private:
    void canConstruct(const vector<int>&   c,
                      vector<int>&         partial,
                      vector<vector<int>>& results,
                      int                  target,
                      int                  i) {
        // Can I construct a combination sum using c[i] ... c[end]?
        if (i >= c.size() || target < c[i]) {
            return;
        }
        for (int j = i; j < c.size() && target >= c[j]; ++j) {
            if (j > i && c[j] == c[j - 1]) {
                continue;
            }
            partial.emplace_back(c[j]);
            if (target == c[j]) {
                results.emplace_back(partial);
            }
            else {
                canConstruct(c, partial, results, target - c[j], j + 1);
            }
            partial.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> partial;
        canConstruct(candidates, partial, results, target, 0);
        return results;
    }
};