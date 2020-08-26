/// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
/// 火车票有三种不同的销售方式：
/// 一张为期一天的通行证售价为 costs[0] 美元；
/// 一张为期七天的通行证售价为 costs[1] 美元；
/// 一张为期三十天的通行证售价为 costs [2] 美元。 通行证允许数天无限制的旅行。
/// 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7
/// 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
/// 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

/// 动规，注意票价不一定是递增的，在选票的时候选择最便宜的那个而不是日期最短的那个

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> table(days.size());
        for (vector<int>::iterator iter = table.begin(); iter != table.end();
             ++iter) {
            *iter = 0;
        }
        for (int i = 0; i < days.size(); ++i) {
            table[i] = INT32_MAX;
            int cur = 0;
            int diff = 0;
            for (int j = 0; j <= i; ++j) {
                cur = 0;
                diff = days[i] - days[j];
                if (diff >= 30) {
                    continue;
                } else if (diff >= 7) {
                    cur = costs[2];
                } else if (diff >= 1) {
                    cur = costs[1] < costs[2] ? costs[1] : costs[2];
                } else {
                    cur = costs[1] < costs[2] ? costs[1] : costs[2];
                    cur = costs[0] < cur ? costs[0] : cur;
                }
                if (j != 0) {
                    cur += table[j - 1];
                }
                if (cur < table[i]) {
                    table[i] = cur;
                }
            }
        }
        return table[days.size() - 1];
    }
};

int main(void) {
    Solution solution;

    vector<int> days({1, 4, 6, 7, 8, 20});
    vector<int> costs({7, 2, 15});

    cout << solution.mincostTickets(days, costs) << endl;

    return 0;
}