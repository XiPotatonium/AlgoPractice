#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> table;

public:
    int minPathSum(vector<vector<int>> &grid) {
        table = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));

        table[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            table[i][0] = table[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < grid[0].size(); ++i) {
            table[0][i] = table[0][i - 1] + grid[0][i];
        }

        for (int c = 1; c < grid[0].size(); ++c) {
            for (int r = 1; r < grid.size(); ++r) {
                table[r][c] = min(table[r - 1][c], table[r][c - 1]) + grid[r][c];
            }
        }

        return table.back().back();
    }
};

int main(void) {

    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    auto vs = s.minPathSum(v);
    cout << vs << endl;

    return 0;
}