#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> done;

bool is_topo() {
    bool ret = true;
    int n = done.size();

    for (int i = 0; i < n; ++i) {
        done[i] = false;
    }

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (ret != false) {
            for (int j = 0; j < n; ++j) {
                if (adj[x - 1][j] != 0 && !done[j]) {
                    ret = false;
                    break;
                }
            }
            done[x - 1] = true;
        }
    }
    return ret;
}

int main(void) {
    int n, m, a, b;
    cin >> n >> m;

    adj = vector<vector<int>>(n, vector<int>(n));
    done = vector<bool>(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[b - 1][a - 1] = 1;
    }

    vector<int> res;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        if (!is_topo()) {
            res.push_back(i);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i];
    }

    return 0;
}