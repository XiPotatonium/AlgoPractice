#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;

bool is_hamilton(vector<int> path) {
    if (path.size() != adj.size() + 1 || path[0] != path[path.size() - 1]) {
        return false;
    }
    vector<bool> visited(adj.size(), false);

    for (int i = 0; i < path.size() - 1; ++i) {
        if (adj[path[i] - 1][path[i + 1] - 1] == 0) {
            return false;
        }
        if (visited[path[i] - 1]) {
            return false;
        }
        visited[path[i] - 1] = true;
    }
    return true;
}

int main(void) {
    int n, m, a, b;
    cin >> n >> m;

    adj = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> n;
        vector<int> path(n);

        for (int i = 0; i < n; ++i) {
            cin >> path[i];
        }

        if (is_hamilton(path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
