#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    typedef vector<vector<char>> Board;
    typedef pair<int, int>       Cell;
    static const int  SIZE  = 9;
    const char EMPTY = '.';
    
    bool isValidRow(const Board& board, const int row) {
        bool count[SIZE] = { false };
        for (int col = 0; col < SIZE; ++col) {
            char x = board[row][col];
            if (x == EMPTY) continue;
            int y = x - '1';
            if (count[y]) {
                return false;
            }
            count[y] = true;
        }
        return true;
    }
    bool isValidColumn(const Board& board, const int col) {
        bool count[SIZE] = { false };
        for (int row = 0; row < SIZE; ++row) {
            char x = board[row][col];
            if (x == EMPTY) continue;
            int y = x - '1';
            if (count[y]) {
                return false;
            }
            count[y] = true;
        }
        return true;
    }
    bool isValidBox(const Board& board, const int box) {
        int rowStart = (box / 3) * 3;
        int colStart = (box % 3) * 3;
        bool count[SIZE] = { false };
        for (int row = rowStart; row < rowStart + 3; ++row) {
            for (int col = colStart; col < colStart + 3; ++col) {
                char x = board[row][col];
                if (x == EMPTY) continue;
                int y = x - '1';
                if (count[y]) {
                    return false;
                }
                count[y] = true;
            }
        }
        return true;
    }
    
    int findNextEmptyCell(const Board& board, Cell *cell) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++i) {
                if (board[i][j] == EMPTY) {
                    *cell = {i, j};
                    return 0;
                }
            }
        }
        return -1;
    }
    inline int getBoxNumber(const Cell& cell) {
        int row = cell.first / 3;
        int col = cell.second / 3;
        return row * 3 + col;
    }
    bool helper(Board& board) {
        Cell cell;
        if (0 != findNextEmptyCell(board, &cell)) {
            return false;
        }
        for (int i = 1; i <= SIZE; ++i) {
            board[cell.first][cell.second] = (char)('0' + i);
            if(isValidRow(board, cell.first) &&
               isValidColumn(board, cell.second) &&
               isValidBox(board, getBoxNumber(cell))) {
                if (helper(board)) {
                    return true;
                }
            }
        }
        board[cell.first][cell.second] = EMPTY;
        return false;
    }
public:
    void solveSudoku(Board& board) {
        helper(board);
    }
};

int main()
{
    const int SIZE = 9;
    ifstream inFile("sample.txt");
    int count = 0;
    char x;
    vector<vector<char>> board(SIZE, vector<char>(SIZE, '.'));
    while (inFile >> x) {
        board[count / SIZE][count % SIZE] = x;
        ++count;
    }
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    Solution s;
    s.solveSudoku(board);
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
