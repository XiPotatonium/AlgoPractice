// ǰ��ͺ����ؽ��������
// ע�����ambiguous����Ϊ
// ��ĳ���ڵ�ֻ��һ�����ӵ�����£��޷��ж�����ڵ��prefix����һ���ڵ����������ӻ����Һ���
// ��Ϊprefix��postfix�����ṩ������Ϣ

#include <iostream>
#include <vector>

using namespace std;

class Solution {
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
    Solution(const vector<int> &preorder, const vector<int> &postorder)
        : _preorder(preorder), _postorder(postorder), _left(preorder.size()), _right(preorder.size()) {}

    bool solve(vector<int> &inorder) {
        bool ret = _solve(0, _postorder.size() - 1);
        inorder_traverse(inorder, 0);

        return ret;
    }
};

int main(void) {
    int n;
    cin >> n;

    vector<int> preorder(n);
    vector<int> postorder(n);

    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
    Solution s(preorder, postorder);
    vector<int> inorder;
    if (s.solve(inorder)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", inorder[i]);
    }
    printf("\n");

    return 0;
}