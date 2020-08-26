/// 硬币排列组合，经典动规
/// 有1, 5, 10, 25四种硬币，因为存在大测试点，可能数据过大int32表示不下，所以规定模1000000007
/// 时间优化：
/// 写下递归式之后可以发现f(i,v)=f(i−1,v)+f(i,v−ci)，时间优化的一个技巧就是写递归式看看能不能约简，遇到超时可以试试。
/// 空间优化：
/// 好像knapsack里面也有类似的优化，因为实际上只用到了最近的一列，所以可以覆盖，只需要一列就好，但是要注意迭代方向

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        vector<int> arr(n + 1);

        for (int i = 0; i <= n; ++i) {
            arr[i] = 1;
        }

        vector<int> coins = {1, 5, 10, 25};

        for (int i = 1; i < 4; ++i) {
            for (int j = 0; j <= n; ++j) {
                long long sum = arr[j];
                if (j >= coins[i]) {
                    sum += arr[j - coins[i]];
                }
                arr[j] = sum % 1000000007;
            }
        }

        return arr[n];
    }
};

int main(void) {
    Solution solution;

    cout << solution.waysToChange(10);

    return 0;
}