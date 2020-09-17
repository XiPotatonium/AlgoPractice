#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool _solve(vector<vector<char>> &board, int row, int col) {
        array<bool, 9> appeared;
        for (auto &i : appeared) {
            i = false;
        }

        for (int i = 0; i < board.size(); ++i) {
            if (board[row][i] != '.') {
                appeared[board[row][i] - '1'] = true;
            }
            if (board[i][col] != '.') {
                appeared[board[i][col] - '1'] = true;
            }
        }

        for (int i = row - row % 3, j = col - col % 3, idx = 0; idx < 9;
             i = row - row % 3 + idx / 3, j = col - col % 3 + idx % 3, ++idx) {
            if (board[i][j] != '.') {
                appeared[board[i][j] - '1'] = true;
            }
        }

        int next_row = row + (col + 1) / 9, next_col = (col + 1) % 9;
        while (next_row < board.size() && board[next_row][next_col] != '.') {
            next_row += (next_col + 1) / 9;
            next_col = (next_col + 1) % 9;
        }

        for (int i = 0; i < appeared.size(); ++i) {
            if (!appeared[i]) {
                board[row][col] = i + '1';
                if (next_row < board.size() && next_col < board.size()) {
                    if (_solve(board, next_row, next_col)) {
                        return true;
                    }
                } else {
                    return true;
                }
            }
        }
        board[row][col] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        int next_row = 0, next_col = 0;
        while (board[next_row][next_col] != '.') {
            next_row += (next_col + 1) / 9;
            next_col = (next_col + 1) % 9;
        }
        _solve(board, next_row, next_col);
    }
};

int main(void) {

    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.solveSudoku(sudoku);

    for (auto &r : sudoku) {
        for (auto &c : r) {
            putchar(c + '0');
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}