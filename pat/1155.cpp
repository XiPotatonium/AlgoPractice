/// 和1147高度相似

#include <iostream>
#include <vector>

using namespace std;

inline int left_idx(int idx) { return 2 * idx + 1; }
inline int right_idx(int idx) { return 2 * idx + 2; }

bool s_is_min, s_is_max;
vector<int> s_heap;

void bfs(int idx, vector<int> &path) {
    path.push_back(s_heap[idx]);

    int left = left_idx(idx);
    int right = right_idx(idx);

    if (left >= s_heap.size() && right >= s_heap.size()) {
        for (int i = 0; i < path.size(); ++i) {
            if (i != 0) {
                printf(" ");
                if (path[i - 1] < path[i]) {
                    s_is_max = false;
                }
                if (path[i - 1] > path[i]) {
                    s_is_min = false;
                }
            }
            printf("%d", path[i]);
        }
        printf("\n");
    } else {
        if (right < s_heap.size()) {
            bfs(right, path);
        }
        if (left < s_heap.size()) {
            bfs(left, path);
        }
    }

    path.pop_back();
}

int main(void) {
    int n;
    cin >> n;
    s_heap = vector<int>(n);
    s_is_min = s_is_max = true;

    for (int i = 0; i < n; ++i) {
        cin >> s_heap[i];
    }

    vector<int> path;

    bfs(0, path);

    if (s_is_min) {
        printf("Min Heap\n");
    } else if (s_is_max) {
        printf("Max Heap\n");
    } else {
        printf("Not Heap\n");
    }

    return 0;
}