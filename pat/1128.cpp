#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// 只要检查半边就好了，因为是从左到右落子的
/// </summary>
/// <param name="board"></param>
/// <param name="row"></param>
/// <param name="col"></param>
/// <returns></returns>
bool check_valid(vector<vector<bool>> &board, int row, int col) {
    for (int j = 0; j < col; ++j) {
        if (board[row][j]) {
            return false;
        }
    }

    // 左上
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // 左下
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int nquery, n, row;
    cin >> nquery;

    for (int iquery = 0; iquery < nquery; ++iquery) {
        cin >> n;

        vector<vector<bool>> board(n, vector<bool>(n));
        bool valid = true;
        for (int col = 0; col < n; ++col) {
            cin >> row;
            --row;
            if (!valid) {
                continue;
            }

            valid = check_valid(board, row, col);
            board[row][col] = true;
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return 0;
}