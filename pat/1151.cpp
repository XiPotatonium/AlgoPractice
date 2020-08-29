// 用中序遍历的哈希啊笨蛋，一直在遍历中序找root
// 跳出人类算法的圈圈
// 哈希真的太快了

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> s_preorder;
vector<int> s_inorder;
// 中序的位置
unordered_map<int, int> val_idx_map;

int search(int idx, int a_in_idx, int b_in_idx, int in_left, int in_right) {
    if (in_left > in_right) {
        return -1;
    }
    int inorder_idx = val_idx_map.find(s_preorder[idx])->second;

    if ((inorder_idx <= a_in_idx && inorder_idx >= b_in_idx) || (inorder_idx <= b_in_idx && inorder_idx >= a_in_idx)) {
        // a ... cur ... b || b ... cur ... a
        return s_preorder[idx];
    } else if (inorder_idx > a_in_idx) {
        // a, b ... cur
        // 注意a,b != cur，这个在第一个case里面
        // 搜索左子树
        return search(idx + 1, a_in_idx, b_in_idx, in_left, inorder_idx - 1);
    } else if (inorder_idx < a_in_idx) {
        // cur ... a, b
        // 搜索右子树
        if (inorder_idx == in_left) {
            // 左子树为空
            return search(idx + 1, a_in_idx, b_in_idx, inorder_idx + 1, in_right);
        } else {
            // inorder_idx - in_left是左子树的大小
            return search(idx + 1 + inorder_idx - in_left, a_in_idx, b_in_idx, inorder_idx + 1, in_right);
        }
    } else {
        // 不会进入这里
        cout << "FUCK!\n";
    }

    return -1;
}

int main(void) {
    int m, n;
    cin >> m >> n;
    s_preorder = vector<int>(n);
    s_inorder = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> s_inorder[i];
        val_idx_map.emplace(s_inorder[i], i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s_preorder[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        auto iter_a = val_idx_map.find(a);
        auto iter_b = val_idx_map.find(b);

        if (iter_a == val_idx_map.end() && iter_b == val_idx_map.end()) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (iter_a == val_idx_map.end() || iter_b == val_idx_map.end()) {
            printf("ERROR: %d is not found.\n", iter_a == val_idx_map.end() ? a : b);
        } else {
            int lca = search(0, val_idx_map[a], val_idx_map[b], 0, s_inorder.size() - 1);
            if (lca == a) {
                printf("%d is an ancestor of %d.\n", a, b);
            } else if (lca == b) {
                printf("%d is an ancestor of %d.\n", b, a);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, lca);
            }
        }
    }

    return 0;
}
