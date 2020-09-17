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
            // res[i]��ÿ�����ֳ��Խ�����ע�ⲻ���ֵ����
            swap(res[i], res[start]);
            dfs(res, start + 1);
            // ��Ҫ�ָ�ԭ״
            swap(res[i], res[start]);
        }
    }

public:
    /// <summary>
    /// �������е�������ϣ����Ҫ���ֵ����ֶ�sortһ��
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
    /// ���K�����У����Ƶ�˼�룬����Ҫ�г���������
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

        --k; // ��[1, n!]��[0, n! - 1]
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
    /// �����ص�DFS�����Լ�֦������Ϊ��������û����
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

    // lexicographical order �ֵ���
    // ����һ��x�����λΪ1����������£����ĩβ��t��������1������ֱ�ӽ�������tλ��1�͵����� t + 1
    //		λ��0�滻���Ϳ��Եõ�next(x)���� 0011 -> 0101��0101 -> 0110��1001 -> 1010��1001111 -> 1010111��
    // �������x�����λΪ0����������£�ĩβ��t��������0������t��������
    //		0֮ǰ��m��������1�����ǿ��Խ�������t+mλ�õ�1�͵����� t + m + 1λ�� 0�Ի���Ȼ��ѵ����� t + 1λ�������� t + m
    //- 1 		λ�� 1�ƶ������λ���� 0110 -> 1001��1010 -> 1100��1011100 -> 1100011��
    // ö���ֵ��򣬾��൱��ö��ȫ���У��������û�еݹ�
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> p;
        _dfs(p, 1, n, k);
        return _ans;
    }
};