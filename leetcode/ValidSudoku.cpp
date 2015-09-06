// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are
// filled with the character '.'.
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable.
// Only the filled cells need to be validated.

class Solution {
public:
    const int SIZE = 9;
    typedef vector<vector<char>> Board;
    inline bool isValidRow(const Board& board, const int row) {
        bool count[SIZE] = { false };
        for (int col = 0; col < SIZE; ++col) {
            char x = board[row][col];
            if (x == '.') continue;
            int y = x - '1';
            if (count[y]) {
                return false;
            }
            count[y] = true;
        }
        return true;
    }
    inline bool isValidColumn(const Board& board, const int col) {
        bool count[SIZE] = { false };
        for (int row = 0; row < SIZE; ++row) {
            char x = board[row][col];
            if (x == '.') continue;
            int y = x - '1';
            if (count[y]) {
                return false;
            }
            count[y] = true;
        }
        return true;
    }
    inline bool isValidBox(const Board& board, int box) {
        int rowStart = (box / 3) * 3;
        int colStart = (box % 3) * 3;
        bool count[SIZE] = { false };
        for (int row = rowStart; row < rowStart + 3; ++row) {
            for (int col = colStart; col < colStart + 3; ++col) {
                char x = board[row][col];
                if (x == '.') continue;
                int y = x - '1';
                if (count[y]) {
                    return false;
                }
                count[y] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < SIZE; ++i) {
            if (!isValidRow(board, i) ||
                !isValidColumn(board, i) ||
                !isValidBox(board, i)) {
                return false;
            }
        }
        return true;
    }
};
