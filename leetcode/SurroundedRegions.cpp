// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
private:
    typedef vector<vector<char>> Board;
    queue<pair<int, int>> d_q;
    int                   m, n;
    inline void emplaceIfValid(const Board& b, int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n && b[i][j] == 'O') {
            d_q.emplace(i, j);
        }
    }
    void explore(Board& b, int i, int j) {
        emplaceIfValid(b, i, j);
        while (!d_q.empty()) {
            const auto& p = d_q.front();
            int x = p.first;
            int y = p.second;
            b[x][y] = 'V';
            emplaceIfValid(b, x - 1, y);
            emplaceIfValid(b, x + 1, y);
            emplaceIfValid(b, x, y - 1);
            emplaceIfValid(b, x, y + 1);
            d_q.pop();
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            explore(board, i, 0);
            explore(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            explore(board, 0, j);
            explore(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
            }
        }
    }
};
