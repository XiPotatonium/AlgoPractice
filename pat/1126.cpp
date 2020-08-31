#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> s_g;
vector<bool> s_marked;

void dfs(int idx) {
    s_marked[idx] = true;
    for (int i = 0; i < s_g[idx].size(); ++i) {
        if (s_g[idx][i] && !s_marked[i]) {
            dfs(i);
        }
    }
}

int main(void) {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> deg(n);
    s_g = vector<vector<bool>>(n, vector<bool>(n));
    s_marked = vector<bool>(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ++deg[a - 1];
        ++deg[b - 1];
        s_g[a - 1][b - 1] = s_g[b - 1][a - 1] = true;
    }

    int even_cnt = n;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", deg[i]);

        even_cnt -= deg[i] % 2;
    }

    dfs(0);

    bool connected = true;
    for (auto i : s_marked) {
        if (!i) {
            connected = false;
            break;
        }
    }

    if (!connected) {
        printf("\nNon-Eulerian");
    } else if (even_cnt == n) {
        printf("\nEulerian");
    } else if (n - even_cnt == 2) {
        printf("\nSemi-Eulerian");
    } else {
        printf("\nNon-Eulerian");
    }

    return 0;
}