/// MGJ��֪��Ϊʲôģ��ķ������ǻ������

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> pre_tra(n);
    unordered_map<int, int> pos; // ���ֵ <-> �����ǰ������е�λ��

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
                    // ���ö��������������ʣ�a��b��LCAһ����С����a��b֮��
                    // ��ǰ����������Զ����µģ�������������ʱ��lca����lca
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