// 中序表达式和中序遍历

#include <iostream>
#include <vector>

using namespace std;

vector<int> s_left;
vector<int> s_right;
vector<string> s_value;

void infix(int root) {
    if (root < 0) {
        return;
    }

    if (s_left[root] < 0 && s_right[root] < 0) {
        // 常值
        cout << s_value[root];
    } else {
        cout << "(";
        infix(s_left[root]);
        cout << s_value[root];
        infix(s_right[root]);
        cout << ")";
    }
}

int main(void) {
    int n;
    cin >> n;

    s_left = vector<int>(n);
    s_right = vector<int>(n);
    s_value = vector<string>(n);

    vector<bool> referenced(n);

    for (int i = 0; i < n; ++i) {
        string s;
        int i_left, i_right;
        cin >> s >> i_left >> i_right;
        s_value[i] = std::move(s);
        --i_left;
        --i_right;
        s_left[i] = i_left;
        s_right[i] = i_right;

        if (i_left >= 0) {
            referenced[i_left] = true;
        }
        if (i_right >= 0) {
            referenced[i_right] = true;
        }
    }

    int root = 0;
    for (; root < n; ++root) {
        if (!referenced[root]) {
            break; // 未被作为孩子的是根节点
        }
    }

    infix(s_left[root]);
    cout << s_value[root];
    infix(s_right[root]);

    return 0;
}