

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(void) {
    int n, m, a, b;
    cin >> n >> m;
    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int nquery;
    cin >> nquery;
    for (int iquery = 0; iquery < nquery; ++iquery) {
        vector<int> coloring(n);
        unordered_set<int> color_set;
        for (int i = 0; i < n; ++i) {
            cin >> coloring[i];
            color_set.insert(coloring[i]);
        }

        bool is_coloring = true;
        for (int i = 0; i < adj.size(); ++i) {
            for (auto j : adj[i]) {
                if (coloring[i] == coloring[j]) {
                    is_coloring = false;
                    break;
                }
            }
            if (!is_coloring) {
                break;
            }
        }

        if (!is_coloring) {
            printf("No\n");
        } else {
            printf("%d-coloring\n", color_set.size());
        }
    }

    return 0;
}