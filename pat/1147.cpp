#include <iostream>
#include <vector>

using namespace std;

inline int left_child_idx(int root) { return 2 * root + 1; }

inline int right_child_idx(int root) { return 2 * root + 2; }

bool check_heap(vector<int> &h, int idx, bool check_min) {
    int left = left_child_idx(idx);
    int right = right_child_idx(idx);
    bool is_heap = true;

    if (left < h.size()) {
        if ((check_min && h[left] < h[idx]) || (!check_min && h[left] > h[idx])) {
            return false;
        }
        is_heap = check_heap(h, left, check_min);
    }
    if (right < h.size()) {
        if ((check_min && h[right] < h[idx]) || (!check_min && h[right] > h[idx])) {
            return false;
        }
        is_heap = is_heap && check_heap(h, right, check_min);
    }
    return is_heap;
}

void postoreder(vector<int> &v, int idx) {
    if (idx >= v.size()) {
        return;
    }

    postoreder(v, left_child_idx(idx));
    postoreder(v, right_child_idx(idx));

    if (idx == 0) {
        printf("%d\n", v[idx]);
    } else {
        printf("%d ", v[idx]);
    }
}

int main(void) {
    int m, n;

    cin >> m >> n;

    vector<int> input(n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> input[j];
        }

        if (input[0] < input[1]) {
            // min heap
            if (check_heap(input, 0, true)) {
                printf("Min Heap\n");
            } else {
                printf("Not Heap\n");
            }
        } else {
            // max heap
            if (check_heap(input, 0, false)) {
                printf("Max Heap\n");
            } else {
                printf("Not Heap\n");
            }
        }
        postoreder(input, 0);
    }

    return 0;
}