/// ����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

/// �ٶȰٿ�������������ȵĶ���Ϊ��
/// �������и��� T ���������p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        bool hasp = false, hasq = false;
        return _lowestCommonAncestor(root, p, q, &hasp, &hasq);
    }

    TreeNode *_lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q,
                                    bool *phasp, bool *phasq) {
        bool hasp = root == p, hasq = root == q;
        TreeNode *res = NULL;
        if (root->left) {
            res = _lowestCommonAncestor(root->left, p, q, &hasp, &hasq);
            if (res != NULL) {
                return res;
            }
        }
        if (root->right) {
            res = _lowestCommonAncestor(root->right, p, q, &hasp, &hasq);
            if (res != NULL) {
                return res;
            }
        }
        if (hasp && hasq) {
            return root;
        }
        if (!*phasp) {
            *phasp = hasp;
        }
        if (!*phasq) {
            *phasq = hasq;
        }
        return NULL;
    }
};

int main(void) {
    Solution solution;

    cout << solution.mySqrt(23) << endl;
    cout << solution.mySqrt(2) << endl;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(8) << endl;
    cout << solution.mySqrt(16) << endl;
    cout << solution.mySqrt(0) << endl;
    cout << solution.mySqrt(5) << endl;

    return 0;
}