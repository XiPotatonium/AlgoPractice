#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> _ans;
    vector<int> _path;

    void _dfs(int k, int start, int remainder) {
        if (_path.size() == k) {
            if (remainder == 0) {
                _ans.push_back(_path);
            }
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > remainder) {
                break;
            }
            _path.emplace_back(i);
            _dfs(k, i + 1, remainder - i);
            _path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        _dfs(k, 1, n);
        return _ans;
    }
};

int main(void) {
    Solution s;
    auto vs = s.combinationSum3(3, 9);
    for (auto &v : vs) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}