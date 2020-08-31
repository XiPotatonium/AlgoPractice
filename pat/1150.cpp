#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> s_adj;

int main(void) {
    int n, m, a, b, dist;
    cin >> n >> m;

    s_adj = vector<vector<int>>(n, vector<int>(n));
    for (auto &i : s_adj) {
        for (auto &j : i) {
            j = -1;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> dist;
        s_adj[a - 1][b - 1] = s_adj[b - 1][a - 1] = dist;
    }

    cin >> n;
    int pn, shortest_idx, shortest_dist = INT32_MAX;
    for (int p = 0; p < n; ++p) {
        cin >> pn;
        vector<int> path(pn);
        set<int> city_set;
        for (int &i : path) {
            cin >> i;
            city_set.insert(i);
        }
        printf("Path %d: ", p + 1);

        dist = 0;
        for (int i = 0; i < pn - 1; ++i) {
            if (s_adj[path[i] - 1][path[i + 1] - 1] < 0) {
                dist = -1;
                break;
            }
            dist += s_adj[path[i] - 1][path[i + 1] - 1];
        }

        if (dist < 0) {
            printf("NA ");
        } else {
            printf("%d ", dist);
        }
        printf("(");
        if (dist < 0 || *path.cbegin() != *path.crbegin() || city_set.size() < s_adj.size()) {
            printf("Not a TS cycle");
        } else {
            if (path.size() > s_adj.size() + 1) {
                printf("TS cycle");
            } else {
                printf("TS simple cycle");
            }
            if (dist < shortest_dist) {
                shortest_dist = dist;
                shortest_idx = p + 1;
            }
        }
        printf(")\n");
    }

    printf("Shortest Dist(%d) = %d\n", shortest_idx, shortest_dist);

    return 0;
}