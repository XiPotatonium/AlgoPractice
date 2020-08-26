/// HashSet，Open Address， Quadratic probing

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> _table;
    int _size;

    bool is_prime(int x) {
        if (x == 1) { // mgj不加这个第二个点不会过
            return false;
        }

        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int next_prime(int x) {
        while (!is_prime(x)) {
            ++x;
        }
        return x;
    }

public:
    Solution(int size) {
        _size = next_prime(size);
        _table = vector<int>(_size);
    }

    int insert(int x) {
        for (int i = 0; i < _size; ++i) {
            int pos = (x + i * i) % _size;
            if (_table[pos] == 0) {
                _table[pos] = 1;
                return pos;
            }
        }
        return -1;
    }
};

int main(void) {
    int size, n;
    scanf("%d %d", &size, &n);

    Solution s(size);

    int x;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        int idx = s.insert(x);
        if (i != 0) {
            printf(" ");
        }
        if (idx < 0) {
            printf("-");
        } else {
            printf("%d", idx);
        }
    }

    return 0;
}
