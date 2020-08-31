#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int nv, n, a, b;
    cin >> nv >> n;

    vector<vector<int>> adj(nv, vector<int>(nv));

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
    }

    cin >> n;
    int ni;
    for (int query = 0; query < n; ++query) {
        cin >> ni;
        vector<int> seq(ni);
        vector<int> adj_cnt(nv);

        for (int i = 0; i < ni; ++i) {
            cin >> seq[i];
            --seq[i];

            for (int j = 0; j < nv; ++j) {
                adj_cnt[j] += adj[seq[i]][j];
            }
        }

        bool is_clique = true;
        for (int i : seq) {
            if (adj_cnt[i] != seq.size() - 1) {
                is_clique = false;
                break;
            }
        }

        if (!is_clique) {
            printf("Not a Clique\n");
            continue;
        }

        bool is_max = true;
        for (int i = 0; i < nv; ++i) {
            if (adj_cnt[i] == seq.size()) {
                is_max = false;
                break;
            }
        }

        if (is_max) {
            printf("Yes\n");
        } else {
            printf("Not Maximal\n");
        }
    }

    return 0;
}
