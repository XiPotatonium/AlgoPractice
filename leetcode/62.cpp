/// 简单DP，一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
/// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
/// 问总共有多少条不同的路径？

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(n);
        for (int i = 0; i < n; ++i) {
            table[i] = vector<int>(m);
            table[i][0] = 1;
        }
        for (int i = 0; i < m; ++i) {
            table[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
        return table[n - 1][m - 1];
    }
};

int main(void) {
    Solution solution;

    cout << solution.uniquePaths(3, 2);

    return 0;
}