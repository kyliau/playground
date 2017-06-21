class Solution {
  private:
    using Board = vector<vector<int>>;
    int liveNeighbours(const Board& board, int x, int y) {
        const int m = board.size();
        const int n = board[0].size();
        int result = 0;
        for (int i = std::max(0, x - 1); i <= std::min(m - 1, x + 1); ++i) {
            for (int j = std::max(0, y - 1); j <= std::min(n - 1, y + 1); ++j) {
                result += board[i][j] & 1;
            }
        }
        result -= board[x][y] & 1;
        return result;
    }
  public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return;
        }
        const int m = board.size();     // rows
        const int n = board[0].size();  // cols
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int lives = liveNeighbours(board, i, j);

                if (board[i][j] == 1 && (lives == 2 || lives == 3)) {
                    board[i][j] = 3;    // 11
                }
                else if (board[i][j] == 0 && lives == 3) {
                    board[i][j] = 2;    // 10
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};