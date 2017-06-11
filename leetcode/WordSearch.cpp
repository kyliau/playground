class Solution {
  private:
    using Board = vector<vector<char>>;
    bool isValid(const Board&  board,
                 vector<bool>& visited,
                 int           row,
                 int           col,
                 const string& word,
                 int           i) {
        if (i == word.size()) {
            return true;
        }
        const int rows = board.size();
        const int cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }
        if (board[row][col] != word[i]) {
            return false;
        }
        int position = row * cols + col;
        if (visited[position]) {
            return false;
        }
        visited[position] = true;
        bool flag = isValid(board, visited, row + 1, col, word, i + 1) ||
                    isValid(board, visited, row - 1, col, word, i + 1) ||
                    isValid(board, visited, row, col + 1, word, i + 1) ||
                    isValid(board, visited, row, col - 1, word, i + 1);
        visited[position] = false;
        return flag;
    }
  public:
    bool exist(const Board& board, const string& word) {
        if (board.empty()) {
            return word.empty();
        }
        const int rows = board.size();
        const int cols = board[0].size();
        vector<bool> visited(rows * cols, false);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (isValid(board, visited, row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};