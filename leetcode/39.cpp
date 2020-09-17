#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> _ans;
    vector<int> _path;

    void _dfs(vector<int>::const_reverse_iterator tail, vector<int>::const_reverse_iterator end, int remainder) {
        if (remainder == 0) {
            _ans.push_back(_path);
            return;
        }
        if (tail == end) {
            return;
        }

        _dfs(tail + 1, end, remainder);
        while (remainder >= *tail) {
            remainder -= *tail;
            _path.push_back(*tail);
            _dfs(tail + 1, end, remainder);
        }

        // »Ö¸´
        while (!_path.empty() && _path.back() == *tail) {
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (auto iter = candidates.crbegin(); iter != candidates.crend(); ++iter) {
            if (*iter <= target) {
                _dfs(iter, candidates.crend(), target);
                break;
            }
        }

        return _ans;
    }
};

int main(void) {
    vector<int> vs = {2, 3, 6, 7};
    Solution s;
    auto res = s.combinationSum(vs, 7);
    for (auto &i : res) {
        for (auto j : i) {
            cout << j << ' ';
        }
    }

    return 0;
}