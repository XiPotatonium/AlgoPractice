/// ��DP��һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
/// ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
/// ���ܹ��ж�������ͬ��·����

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