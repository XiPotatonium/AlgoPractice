#include <iostream>
#include <vector>

using namespace std;

vector<int> s_inorder;
vector<int> s_preorder;

void traverse(int pre_idx, int in_left, int in_right) {
    if (in_left == in_right) {
        // 叶子节点
        cout << s_preorder[pre_idx];
        return;
    }

    int i;
    for (i = in_left; i <= in_right; ++i) {
        if (s_inorder[i] == s_preorder[pre_idx]) {
            break;
        }
    }

    if (i == in_left) {
        // 没有左孩子
        traverse(pre_idx + 1, i + 1, in_right);
    } else {
        traverse(pre_idx + 1, in_left, i - 1);
    }
}

int main(void) {
    int n;
    cin >> n;

    s_inorder = vector<int>(n);
    s_preorder = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> s_preorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s_inorder[i];
    }

    traverse(0, 0, s_inorder.size() - 1);

    return 0;
}