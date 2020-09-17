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

    /// <summary>
    /// 求第K个排列，进制的思想，不需要列出所有排列
    /// </summary>
    /// <param name="n"></param>
    /// <param name="k"></param>
    /// <returns></returns>
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

class Combination {

    vector<vector<int>> _ans;

    /// <summary>
    /// 最朴素的DFS，可以剪枝，但是为了最朴素没有做
    /// </summary>
    /// <param name="path"></param>
    /// <param name="i"></param>
    /// <param name="n"></param>
    /// <param name="k"></param>
    void _dfs(vector<int> &path, int i, int n, int k) {
        if (path.size() == k) {
            _ans.push_back(path);
            return;
        }

        if (i >= n + 1) {
            return;
        }

        for (int j = i; j <= n; ++j) {
            path.push_back(j);
            _dfs(path, j + 1, n, k);
            path.pop_back();
        }
    }

    // lexicographical order 字典序
    // 规则一：x的最低位为1，这种情况下，如果末尾由t个连续的1，我们直接将倒数第t位的1和倒数第 t + 1
    //		位的0替换，就可以得到next(x)。如 0011 -> 0101，0101 -> 0110，1001 -> 1010，1001111 -> 1010111。
    // 规则二：x的最低位为0，这种情况下，末尾有t个连续的0，而这t个连续的
    //		0之前有m个连续的1，我们可以将倒数第t+m位置的1和倒数第 t + m + 1位的 0对换，然后把倒数第 t + 1位到倒数第 t + m
    //- 1 		位的 1移动到最低位。如 0110 -> 1001，1010 -> 1100，1011100 -> 1100011。
    // 枚举字典序，就相当于枚举全排列，这个方法没有递归
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> p;
        _dfs(p, 1, n, k);
        return _ans;
    }
};