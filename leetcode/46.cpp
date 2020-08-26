/// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
/// 递归回溯，笨办法，貌似Medium也不会考察高级方法

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        queue<int> remainder;
        vector<int> temp;
        vector<vector<int>> ret;

        if (nums.size() == 0) {
            return ret;
        }

        for (vector<int>::iterator iter = nums.begin(); iter != nums.end();
             ++iter) {
            remainder.push(*iter);
        }

        rec_permute(ret, remainder, temp);

        return ret;
    }

    void rec_permute(vector<vector<int>> &ret, queue<int> &remainder,
                     vector<int> &temp) {
        if (remainder.empty()) {
            ret.emplace_back(temp);
            return;
        }

        int tail = remainder.back();

        while (true) {
            int selected = remainder.front();
            remainder.pop();
            temp.push_back(selected);
            rec_permute(ret, remainder, temp);
            temp.erase(temp.end() - 1);
            remainder.push(selected);
            if (selected == tail) {
                break;
            }
        }
    }
};

int main(void) {
    Solution solution;

    vector<int> arr = {1, 2, 3};

    vector<vector<int>> res = solution.permute(arr);
    for (vector<vector<int>>::iterator row = res.begin(); row != res.end();
         ++row) {
        for (vector<int>::iterator iter = row->begin(); iter != row->end();
             ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }

    return 0;
}