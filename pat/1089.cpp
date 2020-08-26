/// 插入排序和归并排序
/// 判断是否是插入可以看逆序对后面的子数组是否和原数组相同
/// merge sort只能一步一步模拟

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> _buf;

    void insertion_sort_step(vector<int> &arr, int index) {
        int val = arr[index];
        int i = index;
        for (; i > 0; --i) {
            if (arr[i - 1] <= val) {
                break;
            }
            arr[i] = arr[i - 1];
        }
        arr[i] = val;
    }

    void merge_sort_step(vector<int> &arr, int unit) {
        for (int i = 0; i < arr.size(); i += 2 * unit) {
            int j = i, j0 = i, j1 = i + unit;
            for (; j0 < i + unit && j1 < i + 2 * unit && j1 < arr.size(); ++j) {
                _buf[j] = arr[j0] < arr[j1] ? arr[j0++] : arr[j1++];
            }
            while (j0 < i + unit && j0 < arr.size())
                _buf[j++] = arr[j0++];
            while (j1 < i + 2 * unit && j1 < arr.size())
                _buf[j++] = arr[j1++];
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = _buf[i];
        }
    }

public:
    void solve(vector<int> &raw, vector<int> &res) {
        int i, n = raw.size();
        _buf = vector<int>(raw);

        for (i = 1; i < n; ++i) {
            if (res[i] < res[i - 1]) {
                int j = i;
                for (; j < n; ++j) {
                    if (res[j] != raw[j]) {
                        break;
                    }
                }
                if (j == n) {
                    printf("Insertion Sort\n");
                    insertion_sort_step(res, i);
                } else {
                    printf("Merge Sort\n");
                    for (int u = 1; u <= n / 2; u *= 2) {
                        merge_sort_step(raw, u);
                        int j = 0;
                        for (; j < n; ++j) {
                            if (raw[j] != res[j]) {
                                break;
                            }
                        }
                        if (j == n) {
                            merge_sort_step(res, u * 2);
                            break;
                        }
                    }
                }
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", res[i]);
        }
    }
};

int main(void) {
    int n, i;
    scanf("%d", &n);
    vector<int> raw(n);
    vector<int> res(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &raw[i]);
    }
    for (i = 0; i < n; ++i) {
        scanf("%d", &res[i]);
    }

    Solution s;
    s.solve(raw, res);

    return 0;
}