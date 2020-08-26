#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> s_adj;

int main(void) {
    int m, n, x, y, an;
    cin >> n >> m;

    s_adj = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        s_adj[i][i] = 1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        s_adj[x - 1][y - 1] = s_adj[y - 1][x - 1] = 1;
    }

    cin >> m;

    vector<bool> ok(n);

    for (int i = 0; i < m; ++i) {
        for (int i = 0; i < n; ++i) {
            ok[i] = true;
        }

        cin >> an;
        vector<int> area(an);
        for (int i = 0; i < an; ++i) {
            cin >> area[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < an; ++j) {
                if (s_adj[i][area[j] - 1] == 0) {
                    ok[i] = false;
                    break;
                }
            }
        }

        bool all_ok = true;
        for (int i = 0; i < an; ++i) {
            if (!ok[area[i] - 1]) {
                all_ok = false;
                break;
            } else {
                ok[area[i] - 1] = false;
            }
        }

        if (!all_ok) {
            printf("Area %d needs help.\n", i + 1);
        } else {
            int j;
            for (j = 0; j < n; ++j) {
                if (ok[j]) {
                    break;
                }
            }
            if (j == n) {
                printf("Area %d is OK.\n", i + 1);
            } else {
                printf("Area %d may invite more people, such as %d.\n", i + 1,
                       j + 1);
            }
        }
    }

    return 0;
}