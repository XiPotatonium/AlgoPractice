#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<bool>> visited;

    bool _exists(vector<vector<char>> &board, string &word, int row, int col, int idx) {
        if (board[row][col] != word[idx]) {
            return false;
        }

        if (idx == word.size() - 1) {
            return true;
        }

        visited[row][col] = true;
        if (col + 1 < board[row].size() && !visited[row][col + 1] && _exists(board, word, row, col + 1, idx + 1)) {
            visited[row][col] = false;
            return true;
        }
        if (row + 1 < board.size() && !visited[row + 1][col] && _exists(board, word, row + 1, col, idx + 1)) {
            visited[row][col] = false;
            return true;
        }
        if (row > 0 && !visited[row - 1][col] && _exists(board, word, row - 1, col, idx + 1)) {
            visited[row][col] = false;
            return true;
        }
        if (col > 0 && !visited[row][col - 1] && _exists(board, word, row, col - 1, idx + 1)) {
            visited[row][col] = false;
            return true;
        }

        visited[row][col] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        this->visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (_exists(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(void) {

    vector<vector<char>> b = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    bool ans = s.exist(b, "ABCESEEEFS");

    cout << (ans ? "true" : "false") << endl;

    return 0;
}