/// MGJ不知道为什么模拟的方法老是会出问题

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> pre_tra(n);
    unordered_map<int, int> pos; // 结点值 <-> 结点在前序遍历中的位置

    for (int i = 0; i < n; ++i) {
        cin >> pre_tra[i];
        pos[pre_tra[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        auto pa = pos.find(a);
        auto pb = pos.find(b);
        if (pa == pos.end() && pb == pos.end()) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (pa == pos.end() || pb == pos.end()) {
            printf("ERROR: %d is not found.\n", pa == pos.end() ? a : b);
        } else {
            int lca;
            for (int j = 0; j < n; j++) {
                if ((a <= pre_tra[j] && pre_tra[j] <= b) ||
                    (b <= pre_tra[j] && pre_tra[j] <= a)) {
                    // 利用二叉搜索树的性质，a和b的LCA一定大小介于a和b之间
                    // 而前序遍历又是自顶向下的，所以最后不满足的时候lca就是lca
                    lca = pre_tra[j];
                    break;
                }
            }

            if (a == lca || b == lca) {
                printf("%d is an ancestor of %d.\n", lca, lca != a ? a : b);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, lca);
            }
        }
    }
    return 0;
}