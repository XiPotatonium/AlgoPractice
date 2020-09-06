#include <iostream>
#include <vector>

using namespace std;

class Permutation {
    vector<string> _ans;

    void dfs(string &res, int start) {
        if (start == res.size()) {
            _ans.push_back(res);
            return;
        }

        for (int i = start; i < res.size(); ++i) {
            // res[i]和每个数字尝试交换，注意不是字典序的
            swap(res[i], res[start]);
            dfs(res, start + 1);
            // 需要恢复原状
            swap(res[i], res[start]);
        }
    }

public:
    /// <summary>
    /// 生成所有的排列组合，如果要求字典序，手动sort一下
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    vector<string> permute(int n) {
        string s;
        for (int i = 0; i < n; ++i) {
            s += '0' + i + 1;
        }

        dfs(s, 0);

        return _ans;
    }
};

class Solution {

public:
    string getPermutation(int n, int k) {
        vector<char> src;
        for (int i = 0; i < n; ++i) {
            src.push_back('0' + i + 1);
        }

        int base = 1;

        for (int i = 1; i < n; ++i) {
            base *= i;
        }

        --k; // 从[1, n!]到[0, n! - 1]
        string s;
        for (int i = n - 1; i >= 1; --i) {
            s += src[k / base];
            src.erase(src.begin() + k / base);
            k = k % base;
            base = base / i;
        }
        s += src[0];

        return s;
    }
};

int main(void) {

    Solution s;

    auto res = s.getPermutation(3, 3);

    cout << res << endl;

    return 0;
}