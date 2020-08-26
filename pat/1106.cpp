// 记tail的层序遍历，没什么好说的

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n, ni;
    double p, r;
    cin >> n >> p >> r;
    r = r / 100 + 1;

    vector<vector<int>> members(n);

    for (int i = 0; i < n; ++i) {
        cin >> ni;
        members[i] = vector<int>(ni);
        for (int j = 0; j < ni; ++j) {
            cin >> members[i][j];
        }
    }

    int tail = 0;
    int cnt = 0, level = 0;
    queue<int> s;
    s.push(0);
    while (!s.empty()) {
        int cur = s.front();
        s.pop();

        if (members[cur].size() == 0) {
            ++cnt;
        }

        for (int child : members[cur]) {
            s.push(child);
        }

        if (cur == tail) {
            if (cnt != 0) {
                break;
            }
            tail = *members[cur].rbegin();
            ++level;
        }
    }

    double price = p;
    for (int i = 0; i < level; ++i) {
        price *= r;
    }

    printf("%.4lf %d", price, cnt);

    return 0;
}