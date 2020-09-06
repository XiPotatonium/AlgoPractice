#include <iostream>
#include <vector>

using namespace std;

class Solution {
    enum class Stone : char {
        Empty = '.',
        Queen = 'Q',
    };

    vector<string> _board;
    vector<vector<string>> _ans;

    bool _check_valid(int row, int col) {
        // 检查是否是合法落子
        for (int i = 0; i < _board.size(); ++i) {
            // row不需要检查，因为是按row递增递归的
            // 检查同一列
            if (_board[i][col] == static_cast<char>(Stone::Queen)) {
                return false;
            }
        }
        // ↖
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --j, --i) {
            if (_board[i][j] == static_cast<char>(Stone::Queen)) {
                return false;
            }
        }
        // ↘
        for (int i = row, j = col; i < _board.size() && j < _board.size(); ++j, ++i) {
            if (_board[i][j] == static_cast<char>(Stone::Queen)) {
                return false;
            }
        }
        // ↗
        for (int i = row, j = col; i >= 0 && j < _board.size(); ++j, --i) {
            if (_board[i][j] == static_cast<char>(Stone::Queen)) {
                return false;
            }
        }
        // ↙
        for (int i = row + 1, j = col - 1; i < _board.size() && j >= 0; --j, ++i) {
            if (_board[i][j] == static_cast<char>(Stone::Queen)) {
                return false;
            }
        }

        return true;
    }

    void _solveNQueens(int row) {
        // 递归终点
        if (row >= _board.size()) {
            _ans.push_back(_board);
            return;
        }

        for (int col = 0; col < _board.size(); ++col) {
            if (!_check_valid(row, col)) {
                continue;
            }
            _board[row][col] = static_cast<char>(Stone::Queen);
            _solveNQueens(row + 1);
            _board[row][col] = static_cast<char>(Stone::Empty);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string line;
        for (int i = 0; i < n; ++i) {
            line += static_cast<char>(Stone::Empty);
        }

        _board = vector<string>(n, line);
        _solveNQueens(0);

        return _ans;
    }
};

int main(void) {

    Solution s;

    auto res = s.solveNQueens(5);

    for (auto &i : res) {
        for (auto &line : i) {
            cout << line << endl;
        }
        cout << endl;
    }

    return 0;
}