/// 我觉得这道题的有点NT，find函数为什么偏偏要写到<=

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> _data;

public:
    Solution(int nslots) : _data(nslots) {}

    void insert(int value) {
        int i;
        for (i = 0; i < _data.size(); ++i) {
            if (_data[(value + i * i) % _data.size()] == 0) {
                _data[(value + i * i) % _data.size()] = value;
                break;
            }
        }

        if (i == _data.size()) {
            printf("%d cannot be inserted.\n", value);
        }
    }

    void find(int value, int &cnt) {
        cnt = 0;
        int hashv;

        for (int i = 0; i <= _data.size(); ++i) { // ??
            hashv = (value + i * i) % _data.size();
            // 注意如果是0也要提前退出
            ++cnt;
            if (_data[hashv] == value || _data[hashv] == 0) {
                break;
            }
        }
    }
};

bool is_prime(int num) {
    if (num == 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int nslots, n, m;
    int x;
    cin >> nslots >> n >> m;

    for (; !is_prime(nslots); ++nslots)
        ;

    Solution s(nslots);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }

    int cnt = 0;
    int total_cnt = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        s.find(x, cnt);
        total_cnt += cnt;
    }

    printf("%.1lf\n", (double)total_cnt / m);

    return 0;
}