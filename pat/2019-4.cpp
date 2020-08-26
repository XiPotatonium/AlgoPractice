#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        value = val;
        left = right = NULL;
    }
};

TreeNode *construct_tree(vector<int> &in_order, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int min_v = INT32_MAX, min_i = -1;
    for (int i = left; i <= right; ++i) {
        if (in_order[i] < min_v) {
            min_v = in_order[i];
            min_i = i;
        }
    }

    TreeNode *node = new TreeNode(min_v);
    node->left = construct_tree(in_order, left, min_i - 1);
    node->right = construct_tree(in_order, min_i + 1, right);
    return node;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> in_order(n);
    for (int i = 0; i < n; ++i) {
        cin >> in_order[i];
    }

    TreeNode *root = construct_tree(in_order, 0, in_order.size() - 1);

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur != root) {
            cout << " ";
        }
        cout << cur->value;
        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
    }

    return 0;
}