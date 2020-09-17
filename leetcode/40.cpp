#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> _ans;
    vector<int> _path;

    void _dfs(const vector<int> &candidates, int idx, int remainder) {
        if (remainder == 0) {
            _ans.push_back(_path);
            return;
        }
        if (idx >= candidates.size() || remainder < 0) {
            return;
        }

        int tail = idx;
        for (; tail < candidates.size() && candidates[tail] == candidates[idx]; ++tail)
            ;
        _dfs(candidates, tail, remainder); // 不选
        for (int i = idx; i < tail; ++i) {
            // 选若干个
            _path.push_back(candidates[i]);
            remainder -= candidates[idx];
            _dfs(candidates, tail, remainder);
        }
        for (int i = idx; i < tail; ++i) {
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        _dfs(candidates, 0, target);
        return _ans;
    }
};

int main(void) {
    vector<int> candidates = {2, 5, 2, 1, 2};
    Solution s;
    auto vs = s.combinationSum2(candidates, 5);

    for (auto &v : vs) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}