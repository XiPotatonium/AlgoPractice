/// 完全二叉树，层序遍历，遇到非中间节点（右孩子是空）之后，所有的节点都是叶子节点
/// 百科上有更官方的定义，但是那个定义似乎在前序遍历上比较好用。

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> left(n);
    vector<int> right(n);
    vector<bool> mentioned(n);

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "-") {
            left[i] = -1;
        } else {
            left[i] = atoi(s.c_str());
            mentioned[left[i]] = true;
        }

        cin >> s;
        if (s == "-") {
            right[i] = -1;
        } else {
            right[i] = atoi(s.c_str());
            mentioned[right[i]] = true;
        }
    }

    int root = 0;
    for (; root < n; ++root) {
        if (!mentioned[root]) {
            break;
        }
    }

    queue<int> q;
    q.push(root);
    int last_node = -1;

    while (!q.empty()) {
        int cur = q.front();

        if (left[cur] == -1) {
            if (right[cur] == -1) {
                last_node = q.back();
            } else {
                // 有右孩子没有左孩子不是Complete
                last_node = -1;
                break;
            }
        } else if (right[cur] == -1) {
            if (last_node >= 0) {
                // 已经遇到叶子节点再遇见有左孩子的节点，不是complete
                last_node = -1;
                break;
            } else {
                last_node = left[cur];
            }
        } else if (last_node >= 0) {
            // 已经遇到叶子节点再遇见有左右孩子的节点，不是complete
            last_node = -1;
            break;
        }

        if (left[cur] != -1) {
            q.push(left[cur]);
        }
        if (right[cur] != -1) {
            q.push(right[cur]);
        }

        // 放到后面pop，输入可能只有一个节点
        q.pop();
    }

    if (last_node >= 0) {
        printf("YES %d\n", last_node);
    } else {
        printf("NO %d\n", root);
    }

    return 0;
}