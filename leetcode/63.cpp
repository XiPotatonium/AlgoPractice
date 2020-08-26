/// 类似62，但是存在障碍物

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] > 0 || obstacleGrid[n - 1][m - 1] > 0) {
            return 0;
        }
        obstacleGrid[0][0] = -1;
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] > 0) {
                break;
            }
            obstacleGrid[i][0] = -1;
        }
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[0][i] > 0) {
                break;
            }
            obstacleGrid[0][i] = -1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] > 0) {
                    continue;
                }
                int sum = 0;
                if (obstacleGrid[i - 1][j] < 0) {
                    sum += obstacleGrid[i - 1][j];
                }
                if (obstacleGrid[i][j - 1] < 0) {
                    sum += obstacleGrid[i][j - 1];
                }
                obstacleGrid[i][j] = sum;
            }
        }
        return -obstacleGrid[n - 1][m - 1];
    }
};

int main(void) {
    Solution solution;

    cout << solution.uniquePaths(3, 2);

    return 0;
}