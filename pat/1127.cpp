/// 不知道为什么，用stack实现倒序输出第四个点不过
/// 理论上deque=queue+stack

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> in_order;
vector<int> post_order;

class Node {
public:
    Node *left = NULL;
    Node *right = NULL;
    int value;

    Node(int v) { value = v; }
};

Node *construct_tree(int in_left, int in_right, int post_idx) {
    Node *ret = new Node(post_order[post_idx]);

    int pivot;
    for (pivot = in_left; pivot <= in_right; ++pivot) {
        if (in_order[pivot] == post_order[post_idx]) {
            break;
        }
    }
    if (pivot != in_right) {
        ret->right = construct_tree(pivot + 1, in_right, post_idx - 1);
    }
    if (pivot != in_left) {
        ret->left = construct_tree(in_left, pivot - 1, post_idx - (in_right - pivot) - 1);
    }
    return ret;
}

int main(void) {
    int n;
    cin >> n;

    in_order = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> in_order[i];
    }

    post_order = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> post_order[i];
    }

    Node *tree = construct_tree(0, n - 1, n - 1);

    deque<Node *> q;
    bool from_left = false;
    Node *cur, *tail = tree;
    q.push_back(tree);

    while (!q.empty()) {
        if (from_left) {
            cur = q.front();
            q.pop_front();

            if (cur->left) {
                q.push_back(cur->left);
            }
            if (cur->right) {
                q.push_back(cur->right);
            }
        } else {
            cur = q.back();
            q.pop_back();

            if (cur->right) {
                q.push_front(cur->right);
            }
            if (cur->left) {
                q.push_front(cur->left);
            }
        }
        if (cur == tail) {
            from_left = !from_left;
            if (!q.empty()) {
                tail = from_left ? q.back() : q.front();
            }
        }
        if (cur != tree) {
            cout << " ";
        }
        cout << cur->value;
    }

    return 0;
}
