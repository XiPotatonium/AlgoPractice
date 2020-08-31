#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(void) {

    int n, m, a, b, qn;
    cin >> n >> m;

    vector<unordered_set<int>> adj(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    cin >> n;

    for (int query = 0; query < n; ++query) {
        unordered_set<int> cover;
        cin >> qn;
        for (int i = 0; i < qn; ++i) {
            cin >> a;
            cover.insert(a);
        }

        bool is_cover = true;
        for (int i = 0; i < adj.size(); ++i) {
            for (auto &j : adj[i]) {
                if (cover.find(i) == cover.end() && cover.find(j) == cover.end()) {
                    is_cover = false;
                    break;
                }
            }
        }

        if (is_cover) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
