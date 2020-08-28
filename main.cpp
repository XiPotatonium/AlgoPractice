#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> s_parent;

int find_root(int x) {
    int tail = x;
    while (s_parent[x] != x) {
        x = s_parent[x];
    }
    int root = x;
    x = tail;
    while (x != root) {
        int f = s_parent[x];
        s_parent[x] = root;
        x = f;
    }
    return root;
}

void do_union(int a, int b) {
    int ra = find_root(a);
    int rb = find_root(b);

    if (ra != rb) {
        s_parent[ra] = rb;
    }
}

int main(void) {
    s_parent = vector<int>(10000);
    for (int i = 0; i < s_parent.size(); ++i) {
        s_parent[i] = i;
    }

    int cnt = INT32_MIN;
    int n, ni;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> ni;
        if (ni == 0) {
            continue;
        }
        int bro, x;
        cin >> bro;
        if (bro > cnt) {
            cnt = bro;
        }
        --bro;
        for (int j = 1; j < ni; ++j) {
            cin >> x;
            if (x > cnt) {
                cnt = x;
            }
            --x;
            do_union(bro, x);
        }
    }

    set<int> roots;

    for (int i = 0; i < cnt; ++i) {
        roots.insert(find_root(i));
    }

    printf("%d %d\n", roots.size(), cnt);

    int a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (find_root(a - 1) == find_root(b - 1)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}