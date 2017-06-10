class Solution {
  public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> v(n, 0);
        v[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    v[j] = 0;
                }
                else if (j > 0) {
                    v[j] += v[j - 1];
                }
            }
        }
        return v.back();
    }
};