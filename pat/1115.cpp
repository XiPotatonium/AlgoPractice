#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> s_left;
vector<int> s_right;
vector<int> s_value;

void insert(int root, int idx) {
    if (idx == 0) {
        // ¿ÕÊ÷
        return;
    }

    if (s_value[idx] <= s_value[root]) {
        if (s_left[root] < 0) {
            s_left[root] = idx;
        } else {
            insert(s_left[root], idx);
        }
    } else {
        if (s_right[root] < 0) {
            s_right[root] = idx;
        } else {
            insert(s_right[root], idx);
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    s_left = vector<int>(n);
    s_right = vector<int>(n);
    s_value = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        s_left[i] = s_right[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        cin >> s_value[i];
        insert(0, i);
    }

    int level0 = 0, level1 = 0;
    queue<int> q;
    q.push(0);
    int tail = 0;
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (s_left[cur] >= 0) {
            q.push(s_left[cur]);
        }

        if (s_right[cur] >= 0) {
            q.push(s_right[cur]);
        }

        ++cnt;
        if (tail == cur) {
            level0 = level1;
            level1 = cnt;
            if (!q.empty()) {
                tail = q.back();
            }
            cnt = 0;
        }
    }

    printf("%d + %d = %d\n", level1, level0, level0 + level1);

    return 0;
}