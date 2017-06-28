#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int result = 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> v(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    v[i][j] = 1 + std::min({
                        v[i][j - 1],
                        v[i - 1][j],
                        v[i - 1][j - 1]
                    });
                    result = std::max(v[i][j], result);
                }
            }
        }
        return result * result;
    }
};

int main() {
    Solution s;
    s.maximalSquare({
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' },
    });
}