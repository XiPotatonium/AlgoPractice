// 非递减子序列
// 数组最长只有15
// 这道题主要不是遍历，而是去重
// 官方题解在解决去重(用类似字符串hash的方式去重)，
// 这里给了一个动态规划的做法，不用考虑去重

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        // 以key结尾的所有非递增子串
        unordered_map<int, vector<vector<int>>> table;
        for (int num : nums) {
            vector<vector<int>> vs;
            vs.push_back({num}); // 单个数字的一定在第一个

            // 寻找所有结尾<=num的子串，append
            for (auto &kv : table) {
                if (kv.first <= num) {
                    for (auto &v : kv.second) {
                        vector<int> newv = v;
                        newv.push_back(num); // 必然append，不会出现只选择一个的情况，所以不发生重复
                        vs.push_back(std::move(newv));
                    }
                }
            }

            table.insert_or_assign(num, std::move(vs));
        }

        vector<vector<int>> ret;
        for (auto &kv : table) {
            for (int i = 1; i < kv.second.size(); ++i) {
                ret.push_back(std::move(kv.second[i]));
            }
        }
        return ret;
    }
};

int main() {
    vector<int> input = {4, 6, 7, 7};
    Solution s;
    auto vs = s.findSubsequences(input);

    for (auto &v : vs) {
        for (auto item : v) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}