#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right; // struct����Ϊ��ַ�ṩĬ��ֵ��cdcd��Ĭ��ֵ��?

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    Node *_build(const vector<int> &vpre, const vector<int> &vin, int pre_idx, int in_left, int in_right) {
        if (in_left > in_right || pre_idx >= vpre.size()) {
            return nullptr;
        }

        Node *ret = new Node(vpre[pre_idx]);
        if (in_left == in_right) {
            return ret;
        }

        int in_idx;
        for (in_idx = in_left; in_idx <= in_right; ++in_idx) {
            if (vin[in_idx] == vpre[pre_idx]) {
                break;
            }
        }

        ret->left = _build(vpre, vin, pre_idx + 1, in_left, in_idx - 1);
        ret->right = _build(vpre, vin, pre_idx + in_idx - in_left + 1, in_idx + 1, in_right);
        return ret;
    }

public:
    using NodeAction = void (*)(Node *);

    void pre_order(Node *root, NodeAction action) {
        vector<Node *> stack; // ����δ�����������Ľڵ�
        while (root != nullptr || !stack.empty()) {
            if (root != nullptr) {
                stack.push_back(root);
                action(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                root = root->right;
            }
        }
    }

    void in_order(Node *root, NodeAction action) {
        vector<Node *> stack; // ����δ��action�Ľڵ�
        while (root != nullptr || !stack.empty()) {
            if (root != nullptr) {
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                action(root);
                root = root->right;
            }
        }
    }

    void post_order(Node *root, NodeAction action) {
        vector<Node *> stack; // ����δ�����������Ľڵ�
        vector<Node *> data;

        // ʹ����-��-��ķ�ʽ����
        while (root != nullptr || !stack.empty()) {
            if (root != nullptr) {
                stack.push_back(root);
                data.push_back(root);
                root = root->right;
            } else {
                root = stack.back();
                stack.pop_back();
                root = root->left;
            }
        }

        // ���������������-��-����
        for (auto iter = data.rbegin(); iter != data.rend(); ++iter) {
            action(*iter);
        }
    }

    Node *build(const vector<int> &pre_order, const vector<int> &in_order) {
        return _build(pre_order, in_order, 0, 0, in_order.size() - 1);
    }
};

// ǰ��ͺ����ؽ��������
// ע�����ambiguous����Ϊ
// ��ĳ���ڵ�ֻ��һ�����ӵ�����£��޷��ж�����ڵ��prefix����һ���ڵ����������ӻ����Һ���
// ��Ϊprefix��postfix�����ṩ������Ϣ
class PreAndPostOrder {
    const vector<int> &_preorder;
    const vector<int> &_postorder;
    vector<int> _left;
    vector<int> _right;

    bool _solve(int pre_idx, int post_idx) {
        _left[pre_idx] = _right[pre_idx] = -1;
        bool unique = true;

        if (pre_idx + 1 >= _preorder.size() || post_idx <= 0) {
            // �϶�û�к�����
            return true;
        }

        for (int p = post_idx - 1; p >= 0; --p) {
            if (_postorder[p] == _preorder[pre_idx + 1]) {
                _left[pre_idx] = pre_idx + 1;
                unique = _solve(pre_idx + 1, p);
                if (p == post_idx - 1) {
                    // �޷��������Һ��ӣ�ͳһ��������
                    return false;
                }
                break;
            }
        }

        if (pre_idx + 2 >= _preorder.size()) {
            // û���Һ���
            return unique;
        }

        for (int p = pre_idx + 2; p < _preorder.size(); ++p) {
            if (_preorder[p] == _postorder[post_idx - 1]) {
                _right[pre_idx] = p;
                unique = _solve(p, post_idx - 1) && unique;
                break;
            }
        }

        return unique;
    }

    void inorder_traverse(vector<int> &inorder, int pos) {
        int p = _left[pos];
        if (p >= 0) {
            inorder_traverse(inorder, p);
        }

        inorder.push_back(_preorder[pos]);

        p = _right[pos];
        if (p >= 0) {
            inorder_traverse(inorder, p);
        }
    }

public:
    PreAndPostOrder(const vector<int> &preorder, const vector<int> &postorder)
        : _preorder(preorder), _postorder(postorder), _left(preorder.size()), _right(preorder.size()) {}

    /// <summary>
    /// �ж��Ƿ�ambiguous��������һ������
    /// </summary>
    /// <param name="inorder"></param>
    /// <returns></returns>
    bool solve(vector<int> &inorder) {
        bool ret = _solve(0, _postorder.size() - 1);
        inorder_traverse(inorder, 0);

        return ret;
    }
};

class LCA {
    const vector<int> &s_preorder;
    const vector<int> &s_inorder;
    // �����λ�ã���ϣ����ο�
    unordered_map<int, int> val_idx_map;

    int search(int idx, int a_in_idx, int b_in_idx, int in_left, int in_right) {
        if (in_left > in_right) {
            return -1;
        }
        int inorder_idx = val_idx_map.find(s_preorder[idx])->second;

        if ((inorder_idx <= a_in_idx && inorder_idx >= b_in_idx) ||
            (inorder_idx <= b_in_idx && inorder_idx >= a_in_idx)) {
            // a ... cur ... b || b ... cur ... a
            return s_preorder[idx];
        } else if (inorder_idx > a_in_idx) {
            // a, b ... cur
            // ע��a,b != cur������ڵ�һ��case����
            // ����������
            return search(idx + 1, a_in_idx, b_in_idx, in_left, inorder_idx - 1);
        } else if (inorder_idx < a_in_idx) {
            // cur ... a, b
            // ����������
            if (inorder_idx == in_left) {
                // ������Ϊ��
                return search(idx + 1, a_in_idx, b_in_idx, inorder_idx + 1, in_right);
            } else {
                // inorder_idx - in_left���������Ĵ�С
                return search(idx + 1 + inorder_idx - in_left, a_in_idx, b_in_idx, inorder_idx + 1, in_right);
            }
        } else {
            // �����������
            cout << "FUCK!\n";
        }

        return -1;
    }

public:
    LCA(const vector<int> &pre_order, const vector<int> &in_order) : s_preorder(pre_order), s_inorder(in_order) {
        for (int i = 0; i < s_inorder.size(); ++i) {
            val_idx_map.emplace(s_inorder[i], i);
        }
    }

    /// <summary>
    /// �ҵ�a��b��LCA
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    void solve(int a, int b) {
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
};

int main(void) {
    Solution s;

    vector<int> vpre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};

    Node *root = s.build(vpre, vin);

    s.pre_order(root, [](Node *a) -> void { cout << a->val << ' '; });
    cout << endl;
    s.in_order(root, [](Node *a) -> void { cout << a->val << ' '; });
    cout << endl;
    s.post_order(root, [](Node *a) -> void { cout << a->val << ' '; });
    cout << endl;

    return 0;
}